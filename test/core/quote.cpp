// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/quote.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

using boost::mpl2::quote;

template<typename x>
using f = std::add_pointer<x>;

template<typename x>
using g = quote<f>::type<x>;

template<typename x>
using h = quote<g>::type<x>;

BOOST_MPL2_ASSERT((std::is_same<f<void>::type, g<void>::type>));
BOOST_MPL2_ASSERT((std::is_same<g<void>::type, h<void>::type>));

template<typename x>
struct capture_void
{
    using type = x;
};

template<>
struct capture_void<void>;

template<typename x>
using i = quote<capture_void>::type<x>;

template<typename x>
using j = quote<i>::type<x>;

BOOST_MPL2_ASSERT((std::is_same<i<char>::type, char>));
BOOST_MPL2_ASSERT((std::is_same<i<void>::type, capture_void<void> >));
BOOST_MPL2_ASSERT((std::is_same<i<char>::type, j<char>::type>));
BOOST_MPL2_ASSERT((std::is_same<i<void>::type, j<void>::type>));

int main()
{
    return 0;
}
