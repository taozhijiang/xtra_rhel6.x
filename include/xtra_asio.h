/*-
 * Copyright (c) 2018 TAO Zhijiang<taozhijiang@gmail.com>
 *
 * Licensed under the BSD-3-Clause license, see LICENSE for full information.
 *
 */


#ifndef __TZ_XTRA_ASIO_H__
#define __TZ_XTRA_ASIO_H__

#include <boost/asio.hpp>
using namespace boost::asio;

typedef std::shared_ptr<ip::tcp::socket>    SocketPtr;
typedef std::weak_ptr<ip::tcp::socket>      SocketWeakPtr;

typedef boost::asio::posix::stream_descriptor asio_fd;
typedef std::shared_ptr<boost::asio::posix::stream_descriptor> asio_fd_shared_ptr;

#include <boost/chrono.hpp>
#include <boost/asio/steady_timer.hpp>

#endif  //__TZ_XTRA_ASIO_H__
