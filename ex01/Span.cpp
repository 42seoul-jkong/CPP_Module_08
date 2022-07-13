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

Span::value_type Span::shortestSpan() const
{
    if (this->c.size() < 2)
    {
        throw InvalidSizeException();
    }
    bool first = true;
    Span::value_type r = Span::value_type();
    for (Span::container_type::iterator it = this->c.begin(); it != this->c.end(); it++)
    {
        Span::value_type a = *it;
        if (++it == this->c.end())
        {
            break;
        }
        Span::value_type b = *it;
        Span::value_type d;
        if (a < b)
        {
            d = b - a;
        }
        else
        {
            d = a - b;
        }
        if (first || d < r)
        {
            r = d;
        }
    }
    return r;
}

Span::value_type Span::longestSpan() const
{
    if (this->c.size() < 2)
    {
        throw InvalidSizeException();
    }
    return *this->c.rbegin() - *this->c.begin();
}

InvalidSizeException::~InvalidSizeException() throw() {} // = default

const char* InvalidSizeException::what() const throw()
{
    return "invalid size";
}