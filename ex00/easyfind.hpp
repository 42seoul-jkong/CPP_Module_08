/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#pragma once

#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& cont, const int& val)
{
    return std::find(cont.begin(), cont.end(), val);
}

template <typename T>
typename T::const_iterator easyfind(const T& cont, const int& val)
{
    return std::find(cont.begin(), cont.end(), val);
}
