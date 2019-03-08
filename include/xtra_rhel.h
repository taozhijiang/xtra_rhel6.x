/*-
 * Copyright (c) 2018 TAO Zhijiang<taozhijiang@gmail.com>
 *
 * Licensed under the BSD-3-Clause license, see LICENSE for full information.
 *
 */


#ifndef __XTRA_RHEL6x_H__
#define __XTRA_RHEL6x_H__

// General GNU
#ifdef __GNUC__
#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)
#else
#define likely(x)       (x)
#define unlikely(x)     (x)
#endif

#if __cplusplus >= 201103L
// language _built_in_ support
#else
#define override
#define nullptr (void*)0
#define noexcept
#endif


// USING NP_DEBUG to control SAFE_ASSERT expand
#include <boost/assert.hpp>
#undef NDEBUG  // needed by handler
#ifndef NP_DEBUG
// default, expand to ::assert, will abort
#else
// custom assert print but not abort, define your own assertion_failed
#define BOOST_ENABLE_ASSERT_HANDLER
#endif
#define SAFE_ASSERT(expr) BOOST_ASSERT(expr)



#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <string>
using std::string;

#include <cstdint>         // int64_t ...
#include <linux/limits.h>  // PATH_MAX


#include <vector>
#include <memory> 
#include <mutex>
#include <boost/thread/shared_mutex.hpp>

#include <functional>      // bind


#if __cplusplus >= 201103L
#include <chrono>
using std::chrono::milliseconds;
using std::chrono::seconds;
#else
#include <boost/chrono.hpp>
using boost::chrono::milliseconds;
using boost::chrono::seconds;
#endif

#ifndef _XTRA_DEFINE_GET_POINTER_MARKER_
#define _XTRA_DEFINE_GET_POINTER_MARKER_
template<class T>
T * get_pointer(std::shared_ptr<T> const& p) {
    return p.get();
}
#endif // _XTRA_DEFINE_GET_POINTER_MARKER_

#endif //__XTRA_RHTL6x_H__
