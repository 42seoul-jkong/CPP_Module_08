/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

template <typename T>
MutantStack<T>::MutantStack()
    : std::stack<T>()
{
    // No-OP
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& that)
    : std::stack<T>(that)
{
    // No-OP
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& that)
{
    if (this != &that)
    {
        this->std::stack<T>::operator=(that);
    }
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {} // = default

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() throw()
{
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const throw()
{
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() throw()
{
    return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const throw()
{
    return this->c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() throw()
{
    return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const throw()
{
    return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() throw()
{
    return this->c.rend();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const throw()
{
    return this->c.rend();
}
