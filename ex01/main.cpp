/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int main()
{
    std::srand(time(NULL));

    std::vector<Span::value_type> vec;
    for (Span::size_type i = 0; i < 1000; i++)
    {
        Span::value_type x = static_cast<Span::value_type>(static_cast<unsigned int>(std::rand()) + std::rand());
        vec.push_back(x);
    }
    std::cout << std::endl;

    Span sp = Span(vec.size() + 1);
    sp.addNumber(0);
    sp.addNumber(vec.begin(), vec.end());

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    return 0;
}
