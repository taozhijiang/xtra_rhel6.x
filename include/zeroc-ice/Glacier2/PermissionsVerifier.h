// **********************************************************************
//
// Copyright (c) 2003-2017 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.6.4
//
// <auto-generated>
//
// Generated from file `PermissionsVerifier.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __Glacier2_PermissionsVerifier_h__
#define __Glacier2_PermissionsVerifier_h__

#include <IceUtil/PushDisableWarnings.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/StreamHelpers.h>
#include <Ice/Proxy.h>
#include <Ice/GCObject.h>
#include <Ice/AsyncResult.h>
#include <Ice/Incoming.h>
#include <Ice/FactoryTableInit.h>
#include <IceUtil/ScopedArray.h>
#include <IceUtil/Optional.h>
#include <Ice/StreamF.h>
#include <Ice/SlicedDataF.h>
#include <Glacier2/SSLInfo.h>
#include <IceUtil/UndefSysMacros.h>
#include <Glacier2/Config.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 306
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 4
#       error Ice patch level mismatch!
#   endif
#endif

#ifndef GLACIER2_API
#   ifdef GLACIER2_API_EXPORTS
#       define GLACIER2_API ICE_DECLSPEC_EXPORT
#   elif defined(ICE_STATIC_LIBS)
#       define GLACIER2_API /**/
#   else
#       define GLACIER2_API ICE_DECLSPEC_IMPORT
#   endif
#endif

namespace IceProxy
{

namespace Glacier2
{

class PermissionsVerifier;
GLACIER2_API void __read(::IceInternal::BasicStream*, ::IceInternal::ProxyHandle< ::IceProxy::Glacier2::PermissionsVerifier>&);
GLACIER2_API ::IceProxy::Ice::Object* upCast(::IceProxy::Glacier2::PermissionsVerifier*);

class SSLPermissionsVerifier;
GLACIER2_API void __read(::IceInternal::BasicStream*, ::IceInternal::ProxyHandle< ::IceProxy::Glacier2::SSLPermissionsVerifier>&);
GLACIER2_API ::IceProxy::Ice::Object* upCast(::IceProxy::Glacier2::SSLPermissionsVerifier*);

}

}

namespace Glacier2
{

class PermissionsVerifier;
GLACIER2_API ::Ice::Object* upCast(::Glacier2::PermissionsVerifier*);
typedef ::IceInternal::Handle< ::Glacier2::PermissionsVerifier> PermissionsVerifierPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Glacier2::PermissionsVerifier> PermissionsVerifierPrx;
GLACIER2_API void __patch(PermissionsVerifierPtr&, const ::Ice::ObjectPtr&);

class SSLPermissionsVerifier;
GLACIER2_API ::Ice::Object* upCast(::Glacier2::SSLPermissionsVerifier*);
typedef ::IceInternal::Handle< ::Glacier2::SSLPermissionsVerifier> SSLPermissionsVerifierPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Glacier2::SSLPermissionsVerifier> SSLPermissionsVerifierPrx;
GLACIER2_API void __patch(SSLPermissionsVerifierPtr&, const ::Ice::ObjectPtr&);

}

namespace Glacier2
{

class GLACIER2_API PermissionDeniedException : public ::Ice::UserException
{
public:

    PermissionDeniedException() {}
    explicit PermissionDeniedException(const ::std::string&);
    virtual ~PermissionDeniedException() throw();

    virtual ::std::string ice_name() const;
    virtual PermissionDeniedException* ice_clone() const;
    virtual void ice_throw() const;

    ::std::string reason;

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*);
    using ::Ice::UserException::__write;
    using ::Ice::UserException::__read;

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    using ::Ice::UserException::__writeImpl;
    using ::Ice::UserException::__readImpl;

    ::Ice::SlicedDataPtr __slicedData;
};

static PermissionDeniedException __PermissionDeniedException_init;

}

namespace Ice
{
template<>
struct StreamableTraits< ::Glacier2::PermissionDeniedException>
{
    static const StreamHelperCategory helper = StreamHelperCategoryUserException;
};

}

namespace Glacier2
{

class Callback_PermissionsVerifier_checkPermissions_Base : virtual public ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_PermissionsVerifier_checkPermissions_Base> Callback_PermissionsVerifier_checkPermissionsPtr;

class Callback_SSLPermissionsVerifier_authorize_Base : virtual public ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_SSLPermissionsVerifier_authorize_Base> Callback_SSLPermissionsVerifier_authorizePtr;

}

namespace IceProxy
{

namespace Glacier2
{

class GLACIER2_API PermissionsVerifier : virtual public ::IceProxy::Ice::Object
{
public:

    bool checkPermissions(const ::std::string& __p_userId, const ::std::string& __p_password, ::std::string& __p_reason)
    {
        return checkPermissions(__p_userId, __p_password, __p_reason, 0);
    }
    bool checkPermissions(const ::std::string& __p_userId, const ::std::string& __p_password, ::std::string& __p_reason, const ::Ice::Context& __ctx)
    {
        return checkPermissions(__p_userId, __p_password, __p_reason, &__ctx);
    }
#ifdef ICE_CPP11
    ::Ice::AsyncResultPtr
    begin_checkPermissions(const ::std::string& __p_userId, const ::std::string& __p_password, const ::IceInternal::Function<void (bool, const ::std::string&)>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& __sent = ::IceInternal::Function<void (bool)>())
    {
        return __begin_checkPermissions(__p_userId, __p_password, 0, __response, __exception, __sent);
    }
    ::Ice::AsyncResultPtr
    begin_checkPermissions(const ::std::string& __p_userId, const ::std::string& __p_password, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_checkPermissions(__p_userId, __p_password, 0, ::Ice::newCallback(__completed, __sent), 0);
    }
    ::Ice::AsyncResultPtr
    begin_checkPermissions(const ::std::string& __p_userId, const ::std::string& __p_password, const ::Ice::Context& __ctx, const ::IceInternal::Function<void (bool, const ::std::string&)>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& __sent = ::IceInternal::Function<void (bool)>())
    {
        return __begin_checkPermissions(__p_userId, __p_password, &__ctx, __response, __exception, __sent);
    }
    ::Ice::AsyncResultPtr
    begin_checkPermissions(const ::std::string& __p_userId, const ::std::string& __p_password, const ::Ice::Context& __ctx, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_checkPermissions(__p_userId, __p_password, &__ctx, ::Ice::newCallback(__completed, __sent));
    }
    
private:

    ::Ice::AsyncResultPtr __begin_checkPermissions(const ::std::string& __p_userId, const ::std::string& __p_password, const ::Ice::Context* __ctx, const ::IceInternal::Function<void (bool, const ::std::string&)>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception, const ::IceInternal::Function<void (bool)>& __sent);
    
public:
#endif

    ::Ice::AsyncResultPtr begin_checkPermissions(const ::std::string& __p_userId, const ::std::string& __p_password)
    {
        return begin_checkPermissions(__p_userId, __p_password, 0, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_checkPermissions(const ::std::string& __p_userId, const ::std::string& __p_password, const ::Ice::Context& __ctx)
    {
        return begin_checkPermissions(__p_userId, __p_password, &__ctx, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_checkPermissions(const ::std::string& __p_userId, const ::std::string& __p_password, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_checkPermissions(__p_userId, __p_password, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_checkPermissions(const ::std::string& __p_userId, const ::std::string& __p_password, const ::Ice::Context& __ctx, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_checkPermissions(__p_userId, __p_password, &__ctx, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_checkPermissions(const ::std::string& __p_userId, const ::std::string& __p_password, const ::Glacier2::Callback_PermissionsVerifier_checkPermissionsPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_checkPermissions(__p_userId, __p_password, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_checkPermissions(const ::std::string& __p_userId, const ::std::string& __p_password, const ::Ice::Context& __ctx, const ::Glacier2::Callback_PermissionsVerifier_checkPermissionsPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_checkPermissions(__p_userId, __p_password, &__ctx, __del, __cookie);
    }

    bool end_checkPermissions(::std::string& __p_reason, const ::Ice::AsyncResultPtr&);
    
private:

    bool checkPermissions(const ::std::string&, const ::std::string&, ::std::string&, const ::Ice::Context*);
    ::Ice::AsyncResultPtr begin_checkPermissions(const ::std::string&, const ::std::string&, const ::Ice::Context*, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& __cookie = 0);
    
public:
    
    ::IceInternal::ProxyHandle<PermissionsVerifier> ice_context(const ::Ice::Context& __context) const
    {
        return dynamic_cast<PermissionsVerifier*>(::IceProxy::Ice::Object::ice_context(__context).get());
    }
    
    ::IceInternal::ProxyHandle<PermissionsVerifier> ice_adapterId(const ::std::string& __id) const
    {
        return dynamic_cast<PermissionsVerifier*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<PermissionsVerifier> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
        return dynamic_cast<PermissionsVerifier*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    }
    
    ::IceInternal::ProxyHandle<PermissionsVerifier> ice_locatorCacheTimeout(int __timeout) const
    {
        return dynamic_cast<PermissionsVerifier*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<PermissionsVerifier> ice_connectionCached(bool __cached) const
    {
        return dynamic_cast<PermissionsVerifier*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    }
    
    ::IceInternal::ProxyHandle<PermissionsVerifier> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
        return dynamic_cast<PermissionsVerifier*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    }
    
    ::IceInternal::ProxyHandle<PermissionsVerifier> ice_secure(bool __secure) const
    {
        return dynamic_cast<PermissionsVerifier*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    }
    
    ::IceInternal::ProxyHandle<PermissionsVerifier> ice_preferSecure(bool __preferSecure) const
    {
        return dynamic_cast<PermissionsVerifier*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    }
    
    ::IceInternal::ProxyHandle<PermissionsVerifier> ice_router(const ::Ice::RouterPrx& __router) const
    {
        return dynamic_cast<PermissionsVerifier*>(::IceProxy::Ice::Object::ice_router(__router).get());
    }
    
    ::IceInternal::ProxyHandle<PermissionsVerifier> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
        return dynamic_cast<PermissionsVerifier*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    }
    
    ::IceInternal::ProxyHandle<PermissionsVerifier> ice_collocationOptimized(bool __co) const
    {
        return dynamic_cast<PermissionsVerifier*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    }
    
    ::IceInternal::ProxyHandle<PermissionsVerifier> ice_invocationTimeout(int __timeout) const
    {
        return dynamic_cast<PermissionsVerifier*>(::IceProxy::Ice::Object::ice_invocationTimeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<PermissionsVerifier> ice_twoway() const
    {
        return dynamic_cast<PermissionsVerifier*>(::IceProxy::Ice::Object::ice_twoway().get());
    }
    
    ::IceInternal::ProxyHandle<PermissionsVerifier> ice_oneway() const
    {
        return dynamic_cast<PermissionsVerifier*>(::IceProxy::Ice::Object::ice_oneway().get());
    }
    
    ::IceInternal::ProxyHandle<PermissionsVerifier> ice_batchOneway() const
    {
        return dynamic_cast<PermissionsVerifier*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    }
    
    ::IceInternal::ProxyHandle<PermissionsVerifier> ice_datagram() const
    {
        return dynamic_cast<PermissionsVerifier*>(::IceProxy::Ice::Object::ice_datagram().get());
    }
    
    ::IceInternal::ProxyHandle<PermissionsVerifier> ice_batchDatagram() const
    {
        return dynamic_cast<PermissionsVerifier*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    }
    
    ::IceInternal::ProxyHandle<PermissionsVerifier> ice_compress(bool __compress) const
    {
        return dynamic_cast<PermissionsVerifier*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    }
    
    ::IceInternal::ProxyHandle<PermissionsVerifier> ice_timeout(int __timeout) const
    {
        return dynamic_cast<PermissionsVerifier*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<PermissionsVerifier> ice_connectionId(const ::std::string& __id) const
    {
        return dynamic_cast<PermissionsVerifier*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<PermissionsVerifier> ice_encodingVersion(const ::Ice::EncodingVersion& __v) const
    {
        return dynamic_cast<PermissionsVerifier*>(::IceProxy::Ice::Object::ice_encodingVersion(__v).get());
    }
    
    static const ::std::string& ice_staticId();

private: 
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

class GLACIER2_API SSLPermissionsVerifier : virtual public ::IceProxy::Ice::Object
{
public:

    bool authorize(const ::Glacier2::SSLInfo& __p_info, ::std::string& __p_reason)
    {
        return authorize(__p_info, __p_reason, 0);
    }
    bool authorize(const ::Glacier2::SSLInfo& __p_info, ::std::string& __p_reason, const ::Ice::Context& __ctx)
    {
        return authorize(__p_info, __p_reason, &__ctx);
    }
#ifdef ICE_CPP11
    ::Ice::AsyncResultPtr
    begin_authorize(const ::Glacier2::SSLInfo& __p_info, const ::IceInternal::Function<void (bool, const ::std::string&)>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& __sent = ::IceInternal::Function<void (bool)>())
    {
        return __begin_authorize(__p_info, 0, __response, __exception, __sent);
    }
    ::Ice::AsyncResultPtr
    begin_authorize(const ::Glacier2::SSLInfo& __p_info, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_authorize(__p_info, 0, ::Ice::newCallback(__completed, __sent), 0);
    }
    ::Ice::AsyncResultPtr
    begin_authorize(const ::Glacier2::SSLInfo& __p_info, const ::Ice::Context& __ctx, const ::IceInternal::Function<void (bool, const ::std::string&)>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception = ::IceInternal::Function<void (const ::Ice::Exception&)>(), const ::IceInternal::Function<void (bool)>& __sent = ::IceInternal::Function<void (bool)>())
    {
        return __begin_authorize(__p_info, &__ctx, __response, __exception, __sent);
    }
    ::Ice::AsyncResultPtr
    begin_authorize(const ::Glacier2::SSLInfo& __p_info, const ::Ice::Context& __ctx, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __completed, const ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>& __sent = ::IceInternal::Function<void (const ::Ice::AsyncResultPtr&)>())
    {
        return begin_authorize(__p_info, &__ctx, ::Ice::newCallback(__completed, __sent));
    }
    
private:

    ::Ice::AsyncResultPtr __begin_authorize(const ::Glacier2::SSLInfo& __p_info, const ::Ice::Context* __ctx, const ::IceInternal::Function<void (bool, const ::std::string&)>& __response, const ::IceInternal::Function<void (const ::Ice::Exception&)>& __exception, const ::IceInternal::Function<void (bool)>& __sent);
    
public:
#endif

    ::Ice::AsyncResultPtr begin_authorize(const ::Glacier2::SSLInfo& __p_info)
    {
        return begin_authorize(__p_info, 0, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_authorize(const ::Glacier2::SSLInfo& __p_info, const ::Ice::Context& __ctx)
    {
        return begin_authorize(__p_info, &__ctx, ::IceInternal::__dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_authorize(const ::Glacier2::SSLInfo& __p_info, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_authorize(__p_info, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_authorize(const ::Glacier2::SSLInfo& __p_info, const ::Ice::Context& __ctx, const ::Ice::CallbackPtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_authorize(__p_info, &__ctx, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_authorize(const ::Glacier2::SSLInfo& __p_info, const ::Glacier2::Callback_SSLPermissionsVerifier_authorizePtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_authorize(__p_info, 0, __del, __cookie);
    }

    ::Ice::AsyncResultPtr begin_authorize(const ::Glacier2::SSLInfo& __p_info, const ::Ice::Context& __ctx, const ::Glacier2::Callback_SSLPermissionsVerifier_authorizePtr& __del, const ::Ice::LocalObjectPtr& __cookie = 0)
    {
        return begin_authorize(__p_info, &__ctx, __del, __cookie);
    }

    bool end_authorize(::std::string& __p_reason, const ::Ice::AsyncResultPtr&);
    
private:

    bool authorize(const ::Glacier2::SSLInfo&, ::std::string&, const ::Ice::Context*);
    ::Ice::AsyncResultPtr begin_authorize(const ::Glacier2::SSLInfo&, const ::Ice::Context*, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& __cookie = 0);
    
public:
    
    ::IceInternal::ProxyHandle<SSLPermissionsVerifier> ice_context(const ::Ice::Context& __context) const
    {
        return dynamic_cast<SSLPermissionsVerifier*>(::IceProxy::Ice::Object::ice_context(__context).get());
    }
    
    ::IceInternal::ProxyHandle<SSLPermissionsVerifier> ice_adapterId(const ::std::string& __id) const
    {
        return dynamic_cast<SSLPermissionsVerifier*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<SSLPermissionsVerifier> ice_endpoints(const ::Ice::EndpointSeq& __endpoints) const
    {
        return dynamic_cast<SSLPermissionsVerifier*>(::IceProxy::Ice::Object::ice_endpoints(__endpoints).get());
    }
    
    ::IceInternal::ProxyHandle<SSLPermissionsVerifier> ice_locatorCacheTimeout(int __timeout) const
    {
        return dynamic_cast<SSLPermissionsVerifier*>(::IceProxy::Ice::Object::ice_locatorCacheTimeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<SSLPermissionsVerifier> ice_connectionCached(bool __cached) const
    {
        return dynamic_cast<SSLPermissionsVerifier*>(::IceProxy::Ice::Object::ice_connectionCached(__cached).get());
    }
    
    ::IceInternal::ProxyHandle<SSLPermissionsVerifier> ice_endpointSelection(::Ice::EndpointSelectionType __est) const
    {
        return dynamic_cast<SSLPermissionsVerifier*>(::IceProxy::Ice::Object::ice_endpointSelection(__est).get());
    }
    
    ::IceInternal::ProxyHandle<SSLPermissionsVerifier> ice_secure(bool __secure) const
    {
        return dynamic_cast<SSLPermissionsVerifier*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    }
    
    ::IceInternal::ProxyHandle<SSLPermissionsVerifier> ice_preferSecure(bool __preferSecure) const
    {
        return dynamic_cast<SSLPermissionsVerifier*>(::IceProxy::Ice::Object::ice_preferSecure(__preferSecure).get());
    }
    
    ::IceInternal::ProxyHandle<SSLPermissionsVerifier> ice_router(const ::Ice::RouterPrx& __router) const
    {
        return dynamic_cast<SSLPermissionsVerifier*>(::IceProxy::Ice::Object::ice_router(__router).get());
    }
    
    ::IceInternal::ProxyHandle<SSLPermissionsVerifier> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
        return dynamic_cast<SSLPermissionsVerifier*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    }
    
    ::IceInternal::ProxyHandle<SSLPermissionsVerifier> ice_collocationOptimized(bool __co) const
    {
        return dynamic_cast<SSLPermissionsVerifier*>(::IceProxy::Ice::Object::ice_collocationOptimized(__co).get());
    }
    
    ::IceInternal::ProxyHandle<SSLPermissionsVerifier> ice_invocationTimeout(int __timeout) const
    {
        return dynamic_cast<SSLPermissionsVerifier*>(::IceProxy::Ice::Object::ice_invocationTimeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<SSLPermissionsVerifier> ice_twoway() const
    {
        return dynamic_cast<SSLPermissionsVerifier*>(::IceProxy::Ice::Object::ice_twoway().get());
    }
    
    ::IceInternal::ProxyHandle<SSLPermissionsVerifier> ice_oneway() const
    {
        return dynamic_cast<SSLPermissionsVerifier*>(::IceProxy::Ice::Object::ice_oneway().get());
    }
    
    ::IceInternal::ProxyHandle<SSLPermissionsVerifier> ice_batchOneway() const
    {
        return dynamic_cast<SSLPermissionsVerifier*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    }
    
    ::IceInternal::ProxyHandle<SSLPermissionsVerifier> ice_datagram() const
    {
        return dynamic_cast<SSLPermissionsVerifier*>(::IceProxy::Ice::Object::ice_datagram().get());
    }
    
    ::IceInternal::ProxyHandle<SSLPermissionsVerifier> ice_batchDatagram() const
    {
        return dynamic_cast<SSLPermissionsVerifier*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    }
    
    ::IceInternal::ProxyHandle<SSLPermissionsVerifier> ice_compress(bool __compress) const
    {
        return dynamic_cast<SSLPermissionsVerifier*>(::IceProxy::Ice::Object::ice_compress(__compress).get());
    }
    
    ::IceInternal::ProxyHandle<SSLPermissionsVerifier> ice_timeout(int __timeout) const
    {
        return dynamic_cast<SSLPermissionsVerifier*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    }
    
    ::IceInternal::ProxyHandle<SSLPermissionsVerifier> ice_connectionId(const ::std::string& __id) const
    {
        return dynamic_cast<SSLPermissionsVerifier*>(::IceProxy::Ice::Object::ice_connectionId(__id).get());
    }
    
    ::IceInternal::ProxyHandle<SSLPermissionsVerifier> ice_encodingVersion(const ::Ice::EncodingVersion& __v) const
    {
        return dynamic_cast<SSLPermissionsVerifier*>(::IceProxy::Ice::Object::ice_encodingVersion(__v).get());
    }
    
    static const ::std::string& ice_staticId();

private: 
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

}

}

namespace Glacier2
{

class GLACIER2_API PermissionsVerifier : virtual public ::Ice::Object
{
public:

    typedef PermissionsVerifierPrx ProxyType;
    typedef PermissionsVerifierPtr PointerType;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual bool checkPermissions(const ::std::string&, const ::std::string&, ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___checkPermissions(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    using ::Ice::Object::__writeImpl;
    using ::Ice::Object::__readImpl;
};

inline bool operator==(const PermissionsVerifier& l, const PermissionsVerifier& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

inline bool operator<(const PermissionsVerifier& l, const PermissionsVerifier& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

class GLACIER2_API SSLPermissionsVerifier : virtual public ::Ice::Object
{
public:

    typedef SSLPermissionsVerifierPrx ProxyType;
    typedef SSLPermissionsVerifierPtr PointerType;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual bool authorize(const ::Glacier2::SSLInfo&, ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::Ice::DispatchStatus ___authorize(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    using ::Ice::Object::__writeImpl;
    using ::Ice::Object::__readImpl;
};

inline bool operator==(const SSLPermissionsVerifier& l, const SSLPermissionsVerifier& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

inline bool operator<(const SSLPermissionsVerifier& l, const SSLPermissionsVerifier& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

}

namespace Glacier2
{

template<class T>
class CallbackNC_PermissionsVerifier_checkPermissions : public Callback_PermissionsVerifier_checkPermissions_Base, public ::IceInternal::TwowayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)(bool, const ::std::string&);

    CallbackNC_PermissionsVerifier_checkPermissions(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallbackNC<T>(obj, cb != 0, excb, sentcb), _response(cb)
    {
    }

    virtual void completed(const ::Ice::AsyncResultPtr& __result) const
    {
        ::Glacier2::PermissionsVerifierPrx __proxy = ::Glacier2::PermissionsVerifierPrx::uncheckedCast(__result->getProxy());
        ::std::string reason;
        bool __ret;
        try
        {
            __ret = __proxy->end_checkPermissions(reason, __result);
        }
        catch(const ::Ice::Exception& ex)
        {
            ::IceInternal::CallbackNC<T>::exception(__result, ex);
            return;
        }
        if(_response)
        {
            (::IceInternal::CallbackNC<T>::_callback.get()->*_response)(__ret, reason);
        }
    }

    private:

    Response _response;
};

template<class T> Callback_PermissionsVerifier_checkPermissionsPtr
newCallback_PermissionsVerifier_checkPermissions(const IceUtil::Handle<T>& instance, void (T::*cb)(bool, const ::std::string&), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_PermissionsVerifier_checkPermissions<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_PermissionsVerifier_checkPermissionsPtr
newCallback_PermissionsVerifier_checkPermissions(T* instance, void (T::*cb)(bool, const ::std::string&), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_PermissionsVerifier_checkPermissions<T>(instance, cb, excb, sentcb);
}

template<class T, typename CT>
class Callback_PermissionsVerifier_checkPermissions : public Callback_PermissionsVerifier_checkPermissions_Base, public ::IceInternal::TwowayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(bool, const ::std::string&, const CT&);

    Callback_PermissionsVerifier_checkPermissions(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallback<T, CT>(obj, cb != 0, excb, sentcb), _response(cb)
    {
    }

    virtual void completed(const ::Ice::AsyncResultPtr& __result) const
    {
        ::Glacier2::PermissionsVerifierPrx __proxy = ::Glacier2::PermissionsVerifierPrx::uncheckedCast(__result->getProxy());
        ::std::string reason;
        bool __ret;
        try
        {
            __ret = __proxy->end_checkPermissions(reason, __result);
        }
        catch(const ::Ice::Exception& ex)
        {
            ::IceInternal::Callback<T, CT>::exception(__result, ex);
            return;
        }
        if(_response)
        {
            (::IceInternal::Callback<T, CT>::_callback.get()->*_response)(__ret, reason, CT::dynamicCast(__result->getCookie()));
        }
    }

    private:

    Response _response;
};

template<class T, typename CT> Callback_PermissionsVerifier_checkPermissionsPtr
newCallback_PermissionsVerifier_checkPermissions(const IceUtil::Handle<T>& instance, void (T::*cb)(bool, const ::std::string&, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_PermissionsVerifier_checkPermissions<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_PermissionsVerifier_checkPermissionsPtr
newCallback_PermissionsVerifier_checkPermissions(T* instance, void (T::*cb)(bool, const ::std::string&, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_PermissionsVerifier_checkPermissions<T, CT>(instance, cb, excb, sentcb);
}

template<class T>
class CallbackNC_SSLPermissionsVerifier_authorize : public Callback_SSLPermissionsVerifier_authorize_Base, public ::IceInternal::TwowayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)(bool, const ::std::string&);

    CallbackNC_SSLPermissionsVerifier_authorize(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallbackNC<T>(obj, cb != 0, excb, sentcb), _response(cb)
    {
    }

    virtual void completed(const ::Ice::AsyncResultPtr& __result) const
    {
        ::Glacier2::SSLPermissionsVerifierPrx __proxy = ::Glacier2::SSLPermissionsVerifierPrx::uncheckedCast(__result->getProxy());
        ::std::string reason;
        bool __ret;
        try
        {
            __ret = __proxy->end_authorize(reason, __result);
        }
        catch(const ::Ice::Exception& ex)
        {
            ::IceInternal::CallbackNC<T>::exception(__result, ex);
            return;
        }
        if(_response)
        {
            (::IceInternal::CallbackNC<T>::_callback.get()->*_response)(__ret, reason);
        }
    }

    private:

    Response _response;
};

template<class T> Callback_SSLPermissionsVerifier_authorizePtr
newCallback_SSLPermissionsVerifier_authorize(const IceUtil::Handle<T>& instance, void (T::*cb)(bool, const ::std::string&), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_SSLPermissionsVerifier_authorize<T>(instance, cb, excb, sentcb);
}

template<class T> Callback_SSLPermissionsVerifier_authorizePtr
newCallback_SSLPermissionsVerifier_authorize(T* instance, void (T::*cb)(bool, const ::std::string&), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_SSLPermissionsVerifier_authorize<T>(instance, cb, excb, sentcb);
}

template<class T, typename CT>
class Callback_SSLPermissionsVerifier_authorize : public Callback_SSLPermissionsVerifier_authorize_Base, public ::IceInternal::TwowayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(bool, const ::std::string&, const CT&);

    Callback_SSLPermissionsVerifier_authorize(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallback<T, CT>(obj, cb != 0, excb, sentcb), _response(cb)
    {
    }

    virtual void completed(const ::Ice::AsyncResultPtr& __result) const
    {
        ::Glacier2::SSLPermissionsVerifierPrx __proxy = ::Glacier2::SSLPermissionsVerifierPrx::uncheckedCast(__result->getProxy());
        ::std::string reason;
        bool __ret;
        try
        {
            __ret = __proxy->end_authorize(reason, __result);
        }
        catch(const ::Ice::Exception& ex)
        {
            ::IceInternal::Callback<T, CT>::exception(__result, ex);
            return;
        }
        if(_response)
        {
            (::IceInternal::Callback<T, CT>::_callback.get()->*_response)(__ret, reason, CT::dynamicCast(__result->getCookie()));
        }
    }

    private:

    Response _response;
};

template<class T, typename CT> Callback_SSLPermissionsVerifier_authorizePtr
newCallback_SSLPermissionsVerifier_authorize(const IceUtil::Handle<T>& instance, void (T::*cb)(bool, const ::std::string&, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_SSLPermissionsVerifier_authorize<T, CT>(instance, cb, excb, sentcb);
}

template<class T, typename CT> Callback_SSLPermissionsVerifier_authorizePtr
newCallback_SSLPermissionsVerifier_authorize(T* instance, void (T::*cb)(bool, const ::std::string&, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_SSLPermissionsVerifier_authorize<T, CT>(instance, cb, excb, sentcb);
}

}

#include <IceUtil/PopDisableWarnings.h>
#endif
