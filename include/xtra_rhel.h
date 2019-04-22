/*-
 * Copyright (c) 2018-2019 TAO Zhijiang<taozhijiang@gmail.com>
 *
 * Licensed under the BSD-3-Clause license, see LICENSE for full information.
 *
 */


#ifndef __XTRA_RHEL6x_H__
#define __XTRA_RHEL6x_H__


//
// the version of the standard supported by the compiler
// 
// 199711L: ISO C++ 1998/2003
// 201103L: ISO C++ 2011
//


#if __cplusplus >= 201103L
// language standard _built_in_ support
#else
#define override
#define nullptr (void*)0
#define noexcept throw()
#endif


// General GNU features
#ifdef __GNUC__
#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)
#else
#define likely(x)       (x)
#define unlikely(x)     (x)
#endif


#include <cstdint>         // int64_t ...
#include <linux/limits.h>  // PATH_MAX
#include <limits>          // std::numeric_limits<T>::max()

#if __cplusplus >= 201103L
#include <chrono>
using std::chrono::milliseconds;
using std::chrono::seconds;
#else
#include <boost/chrono.hpp>
using boost::chrono::milliseconds;
using boost::chrono::seconds;
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


// if no define will get unique_future
#define BOOST_THREAD_PROVIDES_FUTURE
#define BOOST_THREAD_PROVIDES_FUTURE_CONTINUATION
#define BOOST_THREAD_PROVIDES_FUTURE_WHEN_ALL_WHEN_ANY

#include <boost/thread.hpp>
#include <boost/thread/shared_mutex.hpp>


// make_unqiue patch ...
#include <memory> 
template<typename T, typename... Ts>
std::unique_ptr<T> make_unique(Ts&&... params){
    return std::unique_ptr<T>(new T(std::forward<Ts>(params)...));
}


// some compiler compains these for smart_ptr
#ifndef _XTRA_DEFINE_GET_POINTER_MARKER_
#define _XTRA_DEFINE_GET_POINTER_MARKER_
template<class T>
T * get_pointer(std::shared_ptr<T> const& p) {
    return p.get();
}
#endif // _XTRA_DEFINE_GET_POINTER_MARKER_


// 简易的辅助代码
template <typename T>
inline void ignore_unused(T const&) {}

#define __noncopyable__(class_name) \
    private:\
    class_name(const class_name&) = delete;\
    class_name& operator=(const class_name&) = delete;

#define __auto_lock__(lock_name) \
    std::lock_guard<std::mutex> __lock_##__FILE__##__LINE__ (lock_name);

#endif //__XTRA_RHTL6x_H__
