// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_ADD_HPP
#define METAL_NUMBER_ADD_HPP

namespace metal
{
    namespace detail
    {
        template<typename head, typename... tail>
        struct _add;
    }

    /// \ingroup number
    /// Computes the arithmetic addition of \numbers.
    ///
    /// Usage
    /// -----
    /// For any \numbers `num_1, ..., num_n`
    /// \code
    ///     using result = metal::add<num_1, ..., num_n>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     \code
    ///         using result = metal::number<
    ///             decltype(num_1{} + ... + num_n{}),
    ///             num_1{} + ... + num_n{}
    ///         >;
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet number.cpp add
    ///
    /// See Also
    /// --------
    /// \see number, inc, dec, neg, sub, mul, div, mod, pow
    template<typename head, typename... tail>
    using add = typename detail::_add<head, tail...>::type;
}

#include <metal/number/number.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/list/list.hpp>
#include <metal/list/fold.hpp>

namespace metal
{
    namespace detail
    {
        template<typename head, typename... tail>
        struct _add
        {};

        template<typename tx, tx vx>
        struct _add<number<tx, vx>> :
            number<tx, vx>
        {};

        template<typename tx, tx vx, typename ty, ty vy>
        struct _add<number<tx, vx>, number<ty, vy>> :
            number<decltype(vx + vy), vx + vy>
        {};

        template<typename tx, tx vx, typename ty, ty vy, typename... nums>
        struct _add<number<tx, vx>, number<ty, vy>, nums...> :
            _fold<
                list<number<ty, vy>, nums...>,
                number<tx, vx>, lambda<add>,
                size_t<0>, size_t<sizeof...(nums) + 1>
            >
        {};
    }
}

#endif
