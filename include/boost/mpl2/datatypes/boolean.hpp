/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef _BOOST_MPL2_DATATYPES_BOOLEAN_HPP_
#define _BOOST_MPL2_DATATYPES_BOOLEAN_HPP_

#include <boost/mpl2/datatypes/integral_concept.hpp>

namespace boost
{
    namespace mpl2
    {
        template<bool constant>
        struct bool_ :
                integral_concept<bool_<constant>, bool, constant>
        {};

        typedef bool_<true> true_;
        typedef bool_<false> false_;
    }
}

#endif