#include <thread>
#include <future>
#include <condition_variable>
#include <functional>
#include <queue>

#ifndef POOL_H
#define POOL_H

class ThreadPool
{
    size_t size;
    bool active;

    std::queue<std::function<void()>>
        queue_; //очередь функциональных объектов, тут будем хранить процессы на выполнение
    std::vector<std::thread> pool_; //наш pool

    std::mutex mut;
    std::condition_variable cv;

public:
    ThreadPool(size_t poolSize)
        : size(poolSize)
        , active(true)
    {
        for (size_t i = 0; i < size; i++)
        {
            pool_.emplace_back([this]() //пушим в наш pool потоки, в которых выполняются наши функции
                { 
                    while (true) //будет выполняться до тех пор, пока не опустеет очередь и не запустится деструктор
                    {
                        std::unique_lock<std::mutex> lock(
                            mut); //замок для того, чтобы безопасно вытащить функцию из очереди
                        if (!queue_.empty())
                        {
                            auto func = std::move(queue_.front());
                            queue_.pop(); //забираем функцию из очереди
                            lock.unlock(); //разрешаем работать другим потокам
                            func(); //выполняем функцию из потока
                        }
                        else
                        {
                            if (active)
                                cv.wait(lock); //Ложимся спать, ждём задач
                            else
                                break; //Выходим, если pool был убит и список задач пуст
                        }
                    }
                });
        }
    }

    ~ThreadPool()
    {
        active = false;
        cv.notify_all(); // Wake up!
        for (auto & t: pool_) // And die
        {
            t.join();
        }
    }
	
	
    template <class Func, class... Args>
    auto exec(Func func, Args... args) -> std::future<decltype(func(args...))>
    {
        auto p = std::make_shared<std::packaged_task<decltype(func(args...))()> >
            (std::bind(std::forward<Func>(func), std::forward<Args>(args)...)); //делаем для функции тот интерфейс, который требуется
		{
			std::lock_guard<std::mutex> lock(mut);
			if (!active)
			{
				throw std::runtime_error("The pool has stopped"); //Для безопасности
			}
			queue_.emplace([p]{(*p)();}); //добавляем в очередь. Нельзя ли никак это более адекватно реализовать??? Я не знаю, правильно ли это работает...
		}
        cv.notify_one(); //будим любой поток, пусть выполняет нашу задачу
        return p->get_future(); //-> так как у нас p - ссылка
    }
};

#endif