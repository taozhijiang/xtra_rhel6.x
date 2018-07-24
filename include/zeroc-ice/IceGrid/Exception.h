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
// Generated from file `Exception.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __IceGrid_Exception_h__
#define __IceGrid_Exception_h__

#include <IceUtil/PushDisableWarnings.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/StreamHelpers.h>
#include <Ice/FactoryTableInit.h>
#include <IceUtil/ScopedArray.h>
#include <IceUtil/Optional.h>
#include <Ice/StreamF.h>
#include <Ice/Identity.h>
#include <Ice/BuiltinSequences.h>
#include <IceUtil/UndefSysMacros.h>
#include <IceGrid/Config.h>

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

#ifndef ICE_GRID_API
#   ifdef ICE_GRID_API_EXPORTS
#       define ICE_GRID_API ICE_DECLSPEC_EXPORT
#   elif defined(ICE_STATIC_LIBS)
#       define ICE_GRID_API /**/
#   else
#       define ICE_GRID_API ICE_DECLSPEC_IMPORT
#   endif
#endif

namespace IceGrid
{

class ICE_GRID_API ApplicationNotExistException : public ::Ice::UserException
{
public:

    ApplicationNotExistException() {}
    explicit ApplicationNotExistException(const ::std::string&);
    virtual ~ApplicationNotExistException() throw();

    virtual ::std::string ice_name() const;
    virtual ApplicationNotExistException* ice_clone() const;
    virtual void ice_throw() const;

    ::std::string name;

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    using ::Ice::UserException::__writeImpl;
    using ::Ice::UserException::__readImpl;
};

static ApplicationNotExistException __ApplicationNotExistException_init;

class ICE_GRID_API ServerNotExistException : public ::Ice::UserException
{
public:

    ServerNotExistException() {}
    explicit ServerNotExistException(const ::std::string&);
    virtual ~ServerNotExistException() throw();

    virtual ::std::string ice_name() const;
    virtual ServerNotExistException* ice_clone() const;
    virtual void ice_throw() const;

    ::std::string id;

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    using ::Ice::UserException::__writeImpl;
    using ::Ice::UserException::__readImpl;
};

class ICE_GRID_API ServerStartException : public ::Ice::UserException
{
public:

    ServerStartException() {}
    ServerStartException(const ::std::string&, const ::std::string&);
    virtual ~ServerStartException() throw();

    virtual ::std::string ice_name() const;
    virtual ServerStartException* ice_clone() const;
    virtual void ice_throw() const;

    ::std::string id;
    ::std::string reason;

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    using ::Ice::UserException::__writeImpl;
    using ::Ice::UserException::__readImpl;
};

class ICE_GRID_API ServerStopException : public ::Ice::UserException
{
public:

    ServerStopException() {}
    ServerStopException(const ::std::string&, const ::std::string&);
    virtual ~ServerStopException() throw();

    virtual ::std::string ice_name() const;
    virtual ServerStopException* ice_clone() const;
    virtual void ice_throw() const;

    ::std::string id;
    ::std::string reason;

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    using ::Ice::UserException::__writeImpl;
    using ::Ice::UserException::__readImpl;
};

class ICE_GRID_API AdapterNotExistException : public ::Ice::UserException
{
public:

    AdapterNotExistException() {}
    explicit AdapterNotExistException(const ::std::string&);
    virtual ~AdapterNotExistException() throw();

    virtual ::std::string ice_name() const;
    virtual AdapterNotExistException* ice_clone() const;
    virtual void ice_throw() const;

    ::std::string id;

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    using ::Ice::UserException::__writeImpl;
    using ::Ice::UserException::__readImpl;
};

class ICE_GRID_API ObjectExistsException : public ::Ice::UserException
{
public:

    ObjectExistsException() {}
    explicit ObjectExistsException(const ::Ice::Identity&);
    virtual ~ObjectExistsException() throw();

    virtual ::std::string ice_name() const;
    virtual ObjectExistsException* ice_clone() const;
    virtual void ice_throw() const;

    ::Ice::Identity id;

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    using ::Ice::UserException::__writeImpl;
    using ::Ice::UserException::__readImpl;
};

class ICE_GRID_API ObjectNotRegisteredException : public ::Ice::UserException
{
public:

    ObjectNotRegisteredException() {}
    explicit ObjectNotRegisteredException(const ::Ice::Identity&);
    virtual ~ObjectNotRegisteredException() throw();

    virtual ::std::string ice_name() const;
    virtual ObjectNotRegisteredException* ice_clone() const;
    virtual void ice_throw() const;

    ::Ice::Identity id;

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    using ::Ice::UserException::__writeImpl;
    using ::Ice::UserException::__readImpl;
};

class ICE_GRID_API NodeNotExistException : public ::Ice::UserException
{
public:

    NodeNotExistException() {}
    explicit NodeNotExistException(const ::std::string&);
    virtual ~NodeNotExistException() throw();

    virtual ::std::string ice_name() const;
    virtual NodeNotExistException* ice_clone() const;
    virtual void ice_throw() const;

    ::std::string name;

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    using ::Ice::UserException::__writeImpl;
    using ::Ice::UserException::__readImpl;
};

class ICE_GRID_API RegistryNotExistException : public ::Ice::UserException
{
public:

    RegistryNotExistException() {}
    explicit RegistryNotExistException(const ::std::string&);
    virtual ~RegistryNotExistException() throw();

    virtual ::std::string ice_name() const;
    virtual RegistryNotExistException* ice_clone() const;
    virtual void ice_throw() const;

    ::std::string name;

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    using ::Ice::UserException::__writeImpl;
    using ::Ice::UserException::__readImpl;
};

class ICE_GRID_API DeploymentException : public ::Ice::UserException
{
public:

    DeploymentException() {}
    explicit DeploymentException(const ::std::string&);
    virtual ~DeploymentException() throw();

    virtual ::std::string ice_name() const;
    virtual DeploymentException* ice_clone() const;
    virtual void ice_throw() const;

    ::std::string reason;

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    using ::Ice::UserException::__writeImpl;
    using ::Ice::UserException::__readImpl;
};

class ICE_GRID_API NodeUnreachableException : public ::Ice::UserException
{
public:

    NodeUnreachableException() {}
    NodeUnreachableException(const ::std::string&, const ::std::string&);
    virtual ~NodeUnreachableException() throw();

    virtual ::std::string ice_name() const;
    virtual NodeUnreachableException* ice_clone() const;
    virtual void ice_throw() const;

    ::std::string name;
    ::std::string reason;

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    using ::Ice::UserException::__writeImpl;
    using ::Ice::UserException::__readImpl;
};

class ICE_GRID_API ServerUnreachableException : public ::Ice::UserException
{
public:

    ServerUnreachableException() {}
    ServerUnreachableException(const ::std::string&, const ::std::string&);
    virtual ~ServerUnreachableException() throw();

    virtual ::std::string ice_name() const;
    virtual ServerUnreachableException* ice_clone() const;
    virtual void ice_throw() const;

    ::std::string name;
    ::std::string reason;

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    using ::Ice::UserException::__writeImpl;
    using ::Ice::UserException::__readImpl;
};

class ICE_GRID_API RegistryUnreachableException : public ::Ice::UserException
{
public:

    RegistryUnreachableException() {}
    RegistryUnreachableException(const ::std::string&, const ::std::string&);
    virtual ~RegistryUnreachableException() throw();

    virtual ::std::string ice_name() const;
    virtual RegistryUnreachableException* ice_clone() const;
    virtual void ice_throw() const;

    ::std::string name;
    ::std::string reason;

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    using ::Ice::UserException::__writeImpl;
    using ::Ice::UserException::__readImpl;
};

class ICE_GRID_API BadSignalException : public ::Ice::UserException
{
public:

    BadSignalException() {}
    explicit BadSignalException(const ::std::string&);
    virtual ~BadSignalException() throw();

    virtual ::std::string ice_name() const;
    virtual BadSignalException* ice_clone() const;
    virtual void ice_throw() const;

    ::std::string reason;

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    using ::Ice::UserException::__writeImpl;
    using ::Ice::UserException::__readImpl;
};

class ICE_GRID_API PatchException : public ::Ice::UserException
{
public:

    PatchException() {}
    explicit PatchException(const ::Ice::StringSeq&);
    virtual ~PatchException() throw();

    virtual ::std::string ice_name() const;
    virtual PatchException* ice_clone() const;
    virtual void ice_throw() const;

    ::Ice::StringSeq reasons;

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    using ::Ice::UserException::__writeImpl;
    using ::Ice::UserException::__readImpl;
};

class ICE_GRID_API AccessDeniedException : public ::Ice::UserException
{
public:

    AccessDeniedException() {}
    explicit AccessDeniedException(const ::std::string&);
    virtual ~AccessDeniedException() throw();

    virtual ::std::string ice_name() const;
    virtual AccessDeniedException* ice_clone() const;
    virtual void ice_throw() const;

    ::std::string lockUserId;

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    using ::Ice::UserException::__writeImpl;
    using ::Ice::UserException::__readImpl;
};

class ICE_GRID_API AllocationException : public ::Ice::UserException
{
public:

    AllocationException() {}
    explicit AllocationException(const ::std::string&);
    virtual ~AllocationException() throw();

    virtual ::std::string ice_name() const;
    virtual AllocationException* ice_clone() const;
    virtual void ice_throw() const;

    ::std::string reason;

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    using ::Ice::UserException::__writeImpl;
    using ::Ice::UserException::__readImpl;
};

class ICE_GRID_API AllocationTimeoutException : public ::IceGrid::AllocationException
{
public:

    AllocationTimeoutException() {}
    explicit AllocationTimeoutException(const ::std::string&);
    virtual ~AllocationTimeoutException() throw();

    virtual ::std::string ice_name() const;
    virtual AllocationTimeoutException* ice_clone() const;
    virtual void ice_throw() const;

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    using ::IceGrid::AllocationException::__writeImpl;
    using ::IceGrid::AllocationException::__readImpl;
};

class ICE_GRID_API PermissionDeniedException : public ::Ice::UserException
{
public:

    PermissionDeniedException() {}
    explicit PermissionDeniedException(const ::std::string&);
    virtual ~PermissionDeniedException() throw();

    virtual ::std::string ice_name() const;
    virtual PermissionDeniedException* ice_clone() const;
    virtual void ice_throw() const;

    ::std::string reason;

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    using ::Ice::UserException::__writeImpl;
    using ::Ice::UserException::__readImpl;
};

class ICE_GRID_API ObserverAlreadyRegisteredException : public ::Ice::UserException
{
public:

    ObserverAlreadyRegisteredException() {}
    explicit ObserverAlreadyRegisteredException(const ::Ice::Identity&);
    virtual ~ObserverAlreadyRegisteredException() throw();

    virtual ::std::string ice_name() const;
    virtual ObserverAlreadyRegisteredException* ice_clone() const;
    virtual void ice_throw() const;

    ::Ice::Identity id;

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    using ::Ice::UserException::__writeImpl;
    using ::Ice::UserException::__readImpl;
};

class ICE_GRID_API FileNotAvailableException : public ::Ice::UserException
{
public:

    FileNotAvailableException() {}
    explicit FileNotAvailableException(const ::std::string&);
    virtual ~FileNotAvailableException() throw();

    virtual ::std::string ice_name() const;
    virtual FileNotAvailableException* ice_clone() const;
    virtual void ice_throw() const;

    ::std::string reason;

protected:
    virtual void __writeImpl(::IceInternal::BasicStream*) const;
    virtual void __readImpl(::IceInternal::BasicStream*);
    using ::Ice::UserException::__writeImpl;
    using ::Ice::UserException::__readImpl;
};

}

namespace Ice
{
template<>
struct StreamableTraits< ::IceGrid::ApplicationNotExistException>
{
    static const StreamHelperCategory helper = StreamHelperCategoryUserException;
};

template<>
struct StreamableTraits< ::IceGrid::ServerNotExistException>
{
    static const StreamHelperCategory helper = StreamHelperCategoryUserException;
};

template<>
struct StreamableTraits< ::IceGrid::ServerStartException>
{
    static const StreamHelperCategory helper = StreamHelperCategoryUserException;
};

template<>
struct StreamableTraits< ::IceGrid::ServerStopException>
{
    static const StreamHelperCategory helper = StreamHelperCategoryUserException;
};

template<>
struct StreamableTraits< ::IceGrid::AdapterNotExistException>
{
    static const StreamHelperCategory helper = StreamHelperCategoryUserException;
};

template<>
struct StreamableTraits< ::IceGrid::ObjectExistsException>
{
    static const StreamHelperCategory helper = StreamHelperCategoryUserException;
};

template<>
struct StreamableTraits< ::IceGrid::ObjectNotRegisteredException>
{
    static const StreamHelperCategory helper = StreamHelperCategoryUserException;
};

template<>
struct StreamableTraits< ::IceGrid::NodeNotExistException>
{
    static const StreamHelperCategory helper = StreamHelperCategoryUserException;
};

template<>
struct StreamableTraits< ::IceGrid::RegistryNotExistException>
{
    static const StreamHelperCategory helper = StreamHelperCategoryUserException;
};

template<>
struct StreamableTraits< ::IceGrid::DeploymentException>
{
    static const StreamHelperCategory helper = StreamHelperCategoryUserException;
};

template<>
struct StreamableTraits< ::IceGrid::NodeUnreachableException>
{
    static const StreamHelperCategory helper = StreamHelperCategoryUserException;
};

template<>
struct StreamableTraits< ::IceGrid::ServerUnreachableException>
{
    static const StreamHelperCategory helper = StreamHelperCategoryUserException;
};

template<>
struct StreamableTraits< ::IceGrid::RegistryUnreachableException>
{
    static const StreamHelperCategory helper = StreamHelperCategoryUserException;
};

template<>
struct StreamableTraits< ::IceGrid::BadSignalException>
{
    static const StreamHelperCategory helper = StreamHelperCategoryUserException;
};

template<>
struct StreamableTraits< ::IceGrid::PatchException>
{
    static const StreamHelperCategory helper = StreamHelperCategoryUserException;
};

template<>
struct StreamableTraits< ::IceGrid::AccessDeniedException>
{
    static const StreamHelperCategory helper = StreamHelperCategoryUserException;
};

template<>
struct StreamableTraits< ::IceGrid::AllocationException>
{
    static const StreamHelperCategory helper = StreamHelperCategoryUserException;
};

template<>
struct StreamableTraits< ::IceGrid::AllocationTimeoutException>
{
    static const StreamHelperCategory helper = StreamHelperCategoryUserException;
};

template<>
struct StreamableTraits< ::IceGrid::PermissionDeniedException>
{
    static const StreamHelperCategory helper = StreamHelperCategoryUserException;
};

template<>
struct StreamableTraits< ::IceGrid::ObserverAlreadyRegisteredException>
{
    static const StreamHelperCategory helper = StreamHelperCategoryUserException;
};

template<>
struct StreamableTraits< ::IceGrid::FileNotAvailableException>
{
    static const StreamHelperCategory helper = StreamHelperCategoryUserException;
};

}

#include <IceUtil/PopDisableWarnings.h>
#endif
