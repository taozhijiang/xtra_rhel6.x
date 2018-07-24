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
// Generated from file `Catalog.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//


// Freeze types in this file:
// name="Freeze::Catalog", key="string", value="Freeze::CatalogData"

#ifndef __Catalog_h__
#define __Catalog_h__

#include <IceUtil/PushDisableWarnings.h>
#include <Freeze/Map.h>
#include <Freeze/CatalogData.h>

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

#ifndef FREEZE_API
#   ifdef FREEZE_API_EXPORTS
#       define FREEZE_API ICE_DECLSPEC_EXPORT
#   elif defined(ICE_STATIC_LIBS)
#       define FREEZE_API /**/
#   else
#       define FREEZE_API ICE_DECLSPEC_IMPORT
#   endif
#endif

namespace Freeze
{

class FREEZE_API Catalog : public Freeze::Map< ::std::string, ::Freeze::CatalogData, ::Freeze::MapKeyCodec< ::std::string >, ::Freeze::MapValueCodec< ::Freeze::CatalogData >, Freeze::IceEncodingCompare >
{
public:


    Catalog(const Freeze::ConnectionPtr&, const std::string&, bool = true, const Freeze::IceEncodingCompare& = Freeze::IceEncodingCompare());

    template <class _InputIterator>
    Catalog(const Freeze::ConnectionPtr& __connection, const std::string& __dbName, bool __createDb, _InputIterator __first, _InputIterator __last, const Freeze::IceEncodingCompare& __compare = Freeze::IceEncodingCompare())
        : Freeze::Map< ::std::string, ::Freeze::CatalogData, ::Freeze::MapKeyCodec< ::std::string >, ::Freeze::MapValueCodec< ::Freeze::CatalogData >, Freeze::IceEncodingCompare >(__connection, __dbName, keyTypeId(), valueTypeId(), __createDb, __first, __last, __compare)
    {
    }

    static std::string keyTypeId();
    static std::string valueTypeId();
};

}

#include <IceUtil/PopDisableWarnings.h>
#endif
