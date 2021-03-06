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

#ifndef INCLUDED_FRAMEWORK_INC_UIELEMENT_UICOMMANDDESCRIPTION_HXX
#define INCLUDED_FRAMEWORK_INC_UIELEMENT_UICOMMANDDESCRIPTION_HXX

#include <boost/unordered_map.hpp>

#include <stdtypes.h>

#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/container/XNameAccess.hpp>
#include <com/sun/star/frame/XModuleManager2.hpp>
#include <com/sun/star/uno/XComponentContext.hpp>

#include <cppuhelper/basemutex.hxx>
#include <cppuhelper/compbase2.hxx>
#include <cppuhelper/supportsservice.hxx>
#include <rtl/ustring.hxx>

namespace framework
{
typedef ::cppu::WeakComponentImplHelper2< com::sun::star::lang::XServiceInfo,
        com::sun::star::container::XNameAccess > UICommandDescription_BASE;

class UICommandDescription : private cppu::BaseMutex,
                             public UICommandDescription_BASE
{
    public:
        UICommandDescription( const ::com::sun::star::uno::Reference< ::com::sun::star::uno::XComponentContext >& rxContext );
        virtual ~UICommandDescription();

        virtual OUString SAL_CALL getImplementationName()
            throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        {
            return OUString("com.sun.star.comp.framework.UICommandDescription");
        }

        virtual sal_Bool SAL_CALL supportsService(OUString const & ServiceName)
            throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        {
            return cppu::supportsService(this, ServiceName);
        }

        virtual css::uno::Sequence<OUString> SAL_CALL getSupportedServiceNames()
            throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE
        {
            css::uno::Sequence< OUString > aSeq(1);
            aSeq[0] = OUString("com.sun.star.frame.UICommandDescription");
            return aSeq;
        }

private:
        // XNameAccess
        virtual ::com::sun::star::uno::Any SAL_CALL getByName( const OUString& aName )
            throw ( ::com::sun::star::container::NoSuchElementException, ::com::sun::star::lang::WrappedTargetException, ::com::sun::star::uno::RuntimeException, std::exception) SAL_OVERRIDE;

        virtual ::com::sun::star::uno::Sequence< OUString > SAL_CALL getElementNames()
            throw (::com::sun::star::uno::RuntimeException, std::exception) SAL_OVERRIDE;

        virtual sal_Bool SAL_CALL hasByName( const OUString& aName )
            throw (::com::sun::star::uno::RuntimeException, std::exception) SAL_OVERRIDE;

        // XElementAccess
        virtual ::com::sun::star::uno::Type SAL_CALL getElementType()
            throw (::com::sun::star::uno::RuntimeException, std::exception) SAL_OVERRIDE;
        virtual sal_Bool SAL_CALL hasElements()
            throw (::com::sun::star::uno::RuntimeException, std::exception) SAL_OVERRIDE;

public:
        typedef ::boost::unordered_map< OUString,
                                 OUString,
                                 OUStringHash,
                                 ::std::equal_to< OUString > > ModuleToCommandFileMap;

        typedef ::boost::unordered_map< OUString,
                                 ::com::sun::star::uno::Reference< ::com::sun::star::container::XNameAccess >,
                                 OUStringHash,
                                 ::std::equal_to< OUString > > UICommandsHashMap;

    protected:
        UICommandDescription( const ::com::sun::star::uno::Reference< ::com::sun::star::uno::XComponentContext>& rxContext, bool  );
        virtual ::com::sun::star::uno::Reference< ::com::sun::star::container::XNameAccess > impl_createConfigAccess(const OUString& _sName);
        void impl_fillElements(const sal_Char* _pName);
        bool                                                                            m_bConfigRead;
        OUString                                                                       m_aPrivateResourceURL;
        ::com::sun::star::uno::Reference< ::com::sun::star::uno::XComponentContext >        m_xContext;
        ModuleToCommandFileMap                                                              m_aModuleToCommandFileMap;
        UICommandsHashMap                                                                   m_aUICommandsHashMap;
        ::com::sun::star::uno::Reference< ::com::sun::star::container::XNameAccess >        m_xGenericUICommands;
        ::com::sun::star::uno::Reference< ::com::sun::star::frame::XModuleManager2 >        m_xModuleManager;
};

} // namespace framework

#endif // __FRAMEWORK_SERVICES_UICOMMANDDESCRPTION_HXX_

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
