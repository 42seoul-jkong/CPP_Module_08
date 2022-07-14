/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include "Span.hpp"
#include <iostream>

Span::Span(Span::size_type n)
    : capacity(n)
{
    // No-OP
}

Span::Span(const Span& that)
{
    *this = that;
}

Span& Span::operator=(const Span& that)
{
    if (this != &that)
    {
        this->c = that.c;
        this->capacity = that.capacity;
    }
    return *this;
}

Span::~Span()
{
    // No-OP
}

void Span::addNumber(Span::value_type n)
{
    if (this->c.size() >= this->capacity)
    {
        throw InvalidSizeException();
    }
    this->c.insert(n);
}

Span::size_type Span::shortestSpan() const
{
    if (this->c.size() < 2)
    {
        throw InvalidSizeException();
    }
    bool first = true;
    Span::size_type r;
    Span::container_type::iterator it = this->c.begin();
    while (it != this->c.end())
    {
        Span::size_type a = *it;
        if (++it == this->c.end())
        {
            break;
        }
        Span::size_type b = *it;
        Span::size_type distance = b - a;
        if (first || distance < r)
        {
            r = distance;
            first = false;
        }
    }
    return r;
}

Span::size_type Span::longestSpan() const
{
    if (this->c.size() < 2)
    {
        throw InvalidSizeException();
    }
    Span::size_type max = *this->c.rbegin();
    Span::size_type min = *this->c.begin();
    return max - min;
}

InvalidSizeException::~InvalidSizeException() throw() {} // = default

const char* InvalidSizeException::what() const throw()
{
    return "invalid size";
}
