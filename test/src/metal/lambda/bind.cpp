// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/bind.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define _boilerplate(M, N) \
    using _cat(opt, M) = _expr(M)<_vals(M)>; \
    using _cat(rec, M) = _expr(M)<_enum(M, rec)>; \
    _assert((metal::is_just_t<metal::bind<_val(M) _comma(N) _vals(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::bind<_num(M) _comma(N) _vals(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::bind<_pair(M) _comma(N) _vals(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::bind<_list(M) _comma(N) _vals(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::bind<_map(M) _comma(N) _vals(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::bind<_arg(M) _comma(N) _vals(N)>>), (_bool(M < N))); \
    _assert((metal::is_just_t<metal::bind<_cat(opt, M) _comma(N) _vals(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::bind<_cat(rec, M) _comma(N) _vals(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::bind<_lbd() _comma(N) _vals(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::bind<_lambda() _comma(N) _vals(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::bind<_lbd(M) _comma(N) _vals(N)>>), (_bool(M <= N))); \
    _assert((metal::is_just_t<metal::bind<_lambda(M) _comma(N) _vals(N)>>), (_bool(M == N))); \
    _assert((metal::is_just_t<metal::bind<_expr(_inc(M))<_lbds(M) _comma(M) _lambda(M)> _comma(N) _vals(N)>>), (_bool(M == N))); \
    _assert((metal::is_just_t<metal::bind<metal::bind<_args(_inc(M))>, _lbd(M) _comma(N) _vals(N)>>), (_bool(M <= N))); \
    _assert((metal::is_just_t<metal::bind<metal::lambda<metal::bind>, _lambda(M) _comma(N) _vals(N)>>), (_true)); \
    _assert((metal::bind_t<_val(M) _comma(N) _vals(N)>), (_val(M))); \
    _assert((metal::bind_t<_num(M) _comma(N) _vals(N)>), (_num(M))); \
    _assert((metal::bind_t<_pair(M) _comma(N) _vals(N)>), (_pair(M))); \
    _assert((metal::bind_t<_list(M) _comma(N) _vals(N)>), (_list(M))); \
    _assert((metal::bind_t<_map(M) _comma(N) _vals(N)>), (_map(M))); \
    _assert((metal::bind_t<_arg(M), _vals(_inc(M))>), (_val(M))); \
    _assert((metal::bind_t<_cat(opt, M) _comma(N) _vals(N)>), (_cat(opt, M))); \
    _assert((metal::bind_t<_cat(rec, M) _comma(N) _vals(N)>), (_cat(rec, M))); \
    _assert((metal::bind_t<_lbd() _comma(M) _vals(M)>), (_expr()<_vals(M)>)); \
    _assert((metal::bind_t<_lambda() _comma(M) _vals(M)>), (_expr()<_vals(M)>)); \
    _assert((metal::bind_t<_lbd(M) _comma(M) _vals(M)>), (_cat(opt, M))); \
    _assert((metal::bind_t<_lambda(M) _comma(M) _vals(M)>), (_cat(opt, M))); \
    _assert((metal::bind_t<_expr(_inc(M))<_lbds(M) _comma(M) _lambda(M)> _comma(M) _vals(M)>), (_expr(_inc(M))<_enum(_inc(M), opt)>)); \
    _assert((metal::bind_t<metal::bind<_args(_inc(M))>, _lbd(M) _comma(M) _vals(M)>), (metal::bind<_lbd(M) _comma(M) _vals(M)>)); \
    _assert((metal::bind_t<metal::lambda<metal::bind>, _lambda(M) _comma(M) _vals(M)>), (metal::bind<_lambda(M) _comma(M) _vals(M)>)); \
/**/

_gen(_boilerplate)