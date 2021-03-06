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
#ifndef INCLUDED_EDITENG_SHADITEM_HXX
#define INCLUDED_EDITENG_SHADITEM_HXX

#include <tools/color.hxx>
#include <svl/eitem.hxx>
#include <editeng/svxenum.hxx>
#include <editeng/editengdllapi.h>


// class SvxShadowItem ---------------------------------------------------

/*  [Description]

    This item describes the shadow attribute (color, width and position).
*/

#define SHADOW_TOP      ((sal_uInt16)0)
#define SHADOW_BOTTOM   ((sal_uInt16)1)
#define SHADOW_LEFT     ((sal_uInt16)2)
#define SHADOW_RIGHT    ((sal_uInt16)3)

class EDITENG_DLLPUBLIC SvxShadowItem : public SfxEnumItemInterface
{
    Color               aShadowColor;
    sal_uInt16              nWidth;
    SvxShadowLocation   eLocation;
public:
    TYPEINFO_OVERRIDE();

    explicit SvxShadowItem( const sal_uInt16 nId ,
                 const Color *pColor = 0, const sal_uInt16 nWidth = 100 /*5pt*/,
                 const SvxShadowLocation eLoc = SVX_SHADOW_NONE );

    inline SvxShadowItem& operator=( const SvxShadowItem& rFmtShadow );

    // "pure virtual Methods" from SfxPoolItem
    virtual bool             operator==( const SfxPoolItem& ) const SAL_OVERRIDE;
    virtual bool             QueryValue( com::sun::star::uno::Any& rVal, sal_uInt8 nMemberId = 0 ) const SAL_OVERRIDE;
    virtual bool             PutValue( const com::sun::star::uno::Any& rVal, sal_uInt8 nMemberId = 0 ) SAL_OVERRIDE;

    virtual SfxItemPresentation GetPresentation( SfxItemPresentation ePres,
                                    SfxMapUnit eCoreMetric,
                                    SfxMapUnit ePresMetric,
                                    OUString &rText, const IntlWrapper * = 0 ) const SAL_OVERRIDE;

    virtual SfxPoolItem*     Clone( SfxItemPool *pPool = 0 ) const SAL_OVERRIDE;
    virtual SfxPoolItem*     Create(SvStream &, sal_uInt16) const SAL_OVERRIDE;
    virtual SvStream&        Store(SvStream &, sal_uInt16 nItemVersion ) const SAL_OVERRIDE;
    virtual bool             ScaleMetrics( long nMult, long nDiv ) SAL_OVERRIDE;
    virtual bool             HasMetrics() const SAL_OVERRIDE;

    const Color& GetColor() const { return aShadowColor;}
    void SetColor( const Color &rNew ) { aShadowColor = rNew; }

    sal_uInt16 GetWidth() const { return nWidth; }
    SvxShadowLocation GetLocation() const { return eLocation; }

    void SetWidth( sal_uInt16 nNew ) { nWidth = nNew; }
    void SetLocation( SvxShadowLocation eNew ) { eLocation = eNew; }

    // Calculate width of the shadow on the page.
    sal_uInt16 CalcShadowSpace( sal_uInt16 nShadow ) const;

    virtual sal_uInt16      GetValueCount() const SAL_OVERRIDE;
    virtual OUString   GetValueTextByPos( sal_uInt16 nPos ) const SAL_OVERRIDE;
    virtual sal_uInt16      GetEnumValue() const SAL_OVERRIDE;
    virtual void            SetEnumValue( sal_uInt16 nNewVal ) SAL_OVERRIDE;
};

inline SvxShadowItem &SvxShadowItem::operator=( const SvxShadowItem& rFmtShadow )
{
    aShadowColor = rFmtShadow.aShadowColor;
    nWidth = rFmtShadow.GetWidth();
    eLocation = rFmtShadow.GetLocation();
    return *this;
}

#endif // INCLUDED_EDITENG_SHADITEM_HXX

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
