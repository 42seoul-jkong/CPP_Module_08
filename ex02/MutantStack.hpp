/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#pragma once

#include <deque>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

public:
    MutantStack();
    MutantStack(const MutantStack& that);
    MutantStack& operator=(const MutantStack& that);
    virtual ~MutantStack();
    iterator begin() throw();
    const_iterator begin() const throw();
    iterator end() throw();
    const_iterator end() const throw();
    reverse_iterator rbegin() throw();
    const_reverse_iterator rbegin() const throw();
    reverse_iterator rend() throw();
    const_reverse_iterator rend() const throw();
};

#include "MutantStack.tpp"
