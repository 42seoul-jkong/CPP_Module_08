/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <set>
#include <vector>

template <typename T>
void testInternal(T& cont, const int& val)
{
    typename T::iterator it = easyfind(cont, val);
    if (it != cont.end())
    {
        std::cout << *it << std::endl;
    }
    else
    {
        std::cout << "Not Found: " << val << std::endl;
    }
}

template <typename T>
void testConstInternal(const T& cont, const int& val)
{
    typename T::const_iterator it = easyfind(cont, val);
    std::cout << "[const] ";
    if (it != cont.end())
    {
        std::cout << *it << std::endl;
    }
    else
    {
        std::cout << "Not Found: " << val << std::endl;
    }
}

template <typename T>
void test()
{
    T cont;
    for (int i = 0; i < 10; i++)
    {
        cont.insert(cont.end(), i * 100);
    }

    testInternal(cont, 0);
    testInternal(cont, 500);
    testInternal(cont, 900);
    testInternal(cont, 512);
    testConstInternal(cont, 0);
    testConstInternal(cont, 500);
    testConstInternal(cont, 900);
    testConstInternal(cont, 512);
}

int main(void)
{
    std::cout << "std::deque<int>" << std::endl;
    test<std::deque<int> >();
    std::cout << std::endl;

    std::cout << "std::list<int>" << std::endl;
    test<std::list<int> >();
    std::cout << std::endl;

    std::cout << "std::set<int>" << std::endl;
    test<std::set<int> >();
    std::cout << std::endl;

    std::cout << "std::vector<int>" << std::endl;
    test<std::vector<int> >();
    std::cout << std::endl;

    return 0;
}
