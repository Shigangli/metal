// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/quote.hpp>

#include "test/expressions.hpp"
#include "test/main.hpp"

using namespace boost::mpl2;

BOOST_MPL2_ASSERT((std::is_same<quote_t<test::nullexpr>, test::nullexpr<>>));
BOOST_MPL2_ASSERT((std::is_same<quote_t<test::unexpr, void>, test::unexpr<void>>));
BOOST_MPL2_ASSERT((std::is_same<quote_t<test::binexpr, void, void*>, test::binexpr<void, void*>>));

BOOST_MPL2_ASSERT((std::is_same<quote_t<test::n_expr>, test::n_expr<>>));
BOOST_MPL2_ASSERT((std::is_same<quote_t<test::n_expr, short>, test::n_expr<short>>));
BOOST_MPL2_ASSERT((std::is_same<quote_t<test::n_expr, short, int>, test::n_expr<short, int>>));
BOOST_MPL2_ASSERT((std::is_same<quote_t<test::n_expr, short, int, long>, test::n_expr<short, int, long>>));
BOOST_MPL2_ASSERT((std::is_same<quote_t<test::n_expr, short, int, long, long long>, test::n_expr<short, int, long, long long>>));
