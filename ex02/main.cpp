/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include "MutantStack.hpp"
#include <iostream>

int ft_main(MutantStack<int> mstack)
{
    std::cout << "[Test]" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;

    std::cout << "[Test Reverse]" << std::endl;
    for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;

    const MutantStack<int>& cmstack = mstack;

    std::cout << "[Test Const]" << std::endl;
    for (MutantStack<int>::const_iterator it = cmstack.begin(); it != cmstack.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;

    std::cout << "[Test Const Reverse]" << std::endl;
    for (MutantStack<int>::const_reverse_iterator it = cmstack.rbegin(); it != cmstack.rend(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;

    return 0;
}

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return ft_main(mstack);
}
