/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

#ifndef INCLUDED_SW_SOURCE_CORE_UIBASE_UNO_UNOMODULE_HXX
#define INCLUDED_SW_SOURCE_CORE_UIBASE_UNO_UNOMODULE_HXX

#include <rtl/ustring.hxx>
#include <com/sun/star/frame/XDispatchProvider.hpp>
#include <com/sun/star/frame/XNotifyingDispatch.hpp>
#include <com/sun/star/uno/RuntimeException.hpp>
#include <com/sun/star/frame/DispatchDescriptor.hpp>
#include <com/sun/star/uno/Reference.h>
#include <cppuhelper/implbase3.hxx>

#include <com/sun/star/lang/XServiceInfo.hpp>

namespace com
{
    namespace sun
    {
        namespace star
        {
            namespace lang
            {
                class XMultiServiceFactory;
            }
            namespace beans
            {
                struct PropertyValue;
            }
        }
    }
}

class SwUnoModule : public ::cppu::WeakImplHelper3< css::frame::XDispatchProvider, css::frame::XNotifyingDispatch, css::lang::XServiceInfo >
{
    css::uno::Reference < css::lang::XMultiServiceFactory > m_xFactory;

public:
                            SwUnoModule( const css::uno::Reference < css::lang::XMultiServiceFactory >& xFactory )
                                : m_xFactory( xFactory )
                            {}

    // XNotifyingDispatch
    virtual void SAL_CALL dispatchWithNotification( const css::util::URL& aURL, const css::uno::Sequence< css::beans::PropertyValue >& aArgs, const css::uno::Reference< css::frame::XDispatchResultListener >& xListener ) throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE;

    // XDispatch
    virtual void SAL_CALL dispatch( const css::util::URL& aURL, const css::uno::Sequence< css::beans::PropertyValue >& aArgs ) throw( css::uno::RuntimeException, std::exception ) SAL_OVERRIDE;
    virtual void SAL_CALL addStatusListener(const css::uno::Reference< css::frame::XStatusListener > & xControl, const css::util::URL& aURL) throw( css::uno::RuntimeException, std::exception ) SAL_OVERRIDE;
    virtual void SAL_CALL removeStatusListener(const css::uno::Reference< css::frame::XStatusListener > & xControl, const css::util::URL& aURL) throw( css::uno::RuntimeException, std::exception ) SAL_OVERRIDE;

    // XDispatchProvider
    virtual css::uno::Sequence< css::uno::Reference< css::frame::XDispatch > > SAL_CALL queryDispatches( const css::uno::Sequence< css::frame::DispatchDescriptor >& seqDescriptor ) throw( css::uno::RuntimeException, std::exception ) SAL_OVERRIDE ;
    virtual css::uno::Reference< css::frame::XDispatch > SAL_CALL queryDispatch(  const   css::util::URL &            aURL            ,
                                                            const   OUString &   sTargetFrameName,
                                                                    sal_Int32   eSearchFlags    ) throw( css::uno::RuntimeException, std::exception ) SAL_OVERRIDE ;
    // XServiceInfo
    virtual OUString SAL_CALL getImplementationName(  ) throw(css::uno::RuntimeException, std::exception) SAL_OVERRIDE;
    virtual sal_Bool SAL_CALL supportsService( const OUString& ServiceName ) throw(css::uno::RuntimeException, std::exception) SAL_OVERRIDE;
    virtual css::uno::Sequence< OUString > SAL_CALL getSupportedServiceNames(  ) throw(css::uno::RuntimeException, std::exception) SAL_OVERRIDE;
};

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
