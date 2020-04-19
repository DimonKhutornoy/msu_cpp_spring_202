#ifndef _ALLOCATOR_H_
#define _ALLOCATOR_H_

template <class T>
struct Allocator
{
    using pointer = T*;

    pointer allocate(size_t count)
    {
        pointer new_data = static_cast<pointer>(malloc(sizeof(T) * count));
        if (new_data == nullptr)
        {
            throw std::bad_alloc();
        }
        return new_data;
    }

    void deallocate(pointer p, size_t count) noexcept
    {
        free(p);
    }

    template <typename... Args>
    void construct(pointer np, Args&&... args)
    {
        new (np) T(std::forward<Args>(args)...);
    }

    void destroy(pointer np) noexcept
    {
        np->~T();
    }
};

#endif