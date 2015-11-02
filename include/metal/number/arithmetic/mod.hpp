// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_MOD_HPP
#define METAL_NUMBER_ARITHMETIC_MOD_HPP

namespace metal
{
    /// \ingroup arithmetic
    /// \brief ...
    template<typename... nums>
    struct mod
    {};

    /// \ingroup arithmetic
    /// \brief Eager adaptor for \ref mod.
    template<typename... nums>
    using mod_t = typename mod<nums...>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    template<typename tx, tx vx>
    struct mod<number<tx, vx>> :
        number<tx, vx>
    {};

    template<typename tx, tx vx, typename ty, ty vy, typename... nums>
    struct mod<number<tx, vx>, number<ty, vy>, nums...> :
        mod<number<decltype(vx % vy), vx % vy>, nums...>
    {};

    template<typename tx, tx vx, typename ty, typename... nums>
    struct mod<number<tx, vx>, number<ty, ty(0)>, nums...>
    {};
}

#endif