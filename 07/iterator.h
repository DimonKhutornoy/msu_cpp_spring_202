#include <iterator>

#ifndef _ITERATOR_H_
#define _ITERATOR_H_

template <class T>
class Iterator : public std::iterator<std::random_access_iterator_tag, T>
{
public:
    using pointer = T*;
    using reference = T&;
    using iterator = Iterator<T>;
    using diff = std::ptrdiff_t;

private:
    pointer ptr_;

public:
    Iterator(pointer ptr)
        : ptr_(ptr)
    {
    }

    operator pointer()
    {
        return ptr_;
    }

    reference operator*()
    {
        return *ptr_;
    }

    reference operator[](diff n)
    {
        return *(ptr_ + n);
    }

    iterator& operator++()
    {
        ptr_++;
        return *this;
    }

    iterator& operator--()
    {
        ptr_--;
        return *this;
    }

    iterator& operator+=(diff n)
    {
        ptr_ += n;
        return *this;
    }

    iterator& operator-=(diff n)
    {
        ptr_ -= n;
        return *this;
    }

    iterator operator+(diff n) const
    {
        return iterator(ptr_ + n);
    }

    iterator operator-(diff n) const
    {
        return iterator(ptr_ - n);
    }

    iterator::diff operator-(const iterator& it) const
    {
        return ptr_ - it.ptr_;
    }

    bool operator==(const iterator& it) const
    {
        return ptr_ == it.ptr_;
    }
    bool operator!=(const iterator& it) const
    {
        return ptr_ != it.ptr_;
    }
};

#endif