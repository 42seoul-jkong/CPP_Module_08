/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#pragma once

#include <exception>
#include <set>

class Span
{
public:
    typedef unsigned int size_type;
    typedef unsigned int value_type;
    typedef std::multiset<value_type> container_type;

private:
    container_type c;
    size_type capacity;

public:
    Span(size_type n = 0);
    Span(const Span& that);
    Span& operator=(const Span& that);
    ~Span();
    void addNumber(value_type n);
    template <typename InputIterator>
    void addNumber(InputIterator first, InputIterator last);
    value_type shortestSpan() const;
    value_type longestSpan() const;
};

class InvalidSizeException : public std::exception
{
public:
    InvalidSizeException() throw() {}
    virtual ~InvalidSizeException() throw();
    virtual const char* what() const throw();
};

template <typename InputIterator>
void Span::addNumber(InputIterator first, InputIterator last)
{
    for (InputIterator it = first; it != last; it++)
    {
        this->addNumber(*it);
    }
}
