/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

/*
 This file has been autogenerated by update_pch.sh . It is possible to edit it
 manually (such as when an include file has been moved/renamed/removed. All such
 manual changes will be rewritten by the next run of update_pch.sh (which presumably
 also fixes all possible problems, so it's usually better to use it).
*/

#include "officecfg/Office/Common.hxx"
#include <algorithm>
#include <assert.h>
#include <boost/noncopyable.hpp>
#include <boost/numeric/conversion/cast.hpp>
#include <boost/ptr_container/ptr_map.hpp>
#include <boost/scoped_array.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/unordered_map.hpp>
#include <cassert>
#include <cmath>
#include <com/sun/star/awt/Point.hpp>
#include <com/sun/star/awt/Rectangle.hpp>
#include <com/sun/star/awt/Size.hpp>
#include <com/sun/star/beans/PropertyAttribute.hpp>
#include <com/sun/star/beans/PropertyValue.hpp>
#include <com/sun/star/beans/PropertyValues.hpp>
#include <com/sun/star/beans/XPropertySet.hpp>
#include <com/sun/star/configuration/theDefaultProvider.hpp>
#include <com/sun/star/container/ElementExistException.hpp>
#include <com/sun/star/container/NoSuchElementException.hpp>
#include <com/sun/star/container/XNameAccess.hpp>
#include <com/sun/star/container/XNameContainer.hpp>
#include <com/sun/star/frame/XConfigManager.hpp>
#include <com/sun/star/i18n/AmPmValue.hpp>
#include <com/sun/star/i18n/CalendarDisplayCode.hpp>
#include <com/sun/star/i18n/CalendarDisplayIndex.hpp>
#include <com/sun/star/i18n/CalendarFieldIndex.hpp>
#include <com/sun/star/i18n/KNumberFormatType.hpp>
#include <com/sun/star/i18n/KNumberFormatUsage.hpp>
#include <com/sun/star/i18n/LocaleCalendar.hpp>
#include <com/sun/star/i18n/ScriptType.hpp>
#include <com/sun/star/i18n/TransliterationModulesExtra.hpp>
#include <com/sun/star/io/WrongFormatException.hpp>
#include <com/sun/star/lang/Locale.hpp>
#include <com/sun/star/lang/XComponent.hpp>
#include <com/sun/star/lang/XMultiServiceFactory.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/lang/XSingleServiceFactory.hpp>
#include <com/sun/star/registry/XRegistryKey.hpp>
#include <com/sun/star/script/Converter.hpp>
#include <com/sun/star/ucb/Command.hpp>
#include <com/sun/star/ucb/IllegalIdentifierException.hpp>
#include <com/sun/star/ucb/InsertCommandArgument.hpp>
#include <com/sun/star/ucb/InteractiveIOException.hpp>
#include <com/sun/star/ucb/NameClashException.hpp>
#include <com/sun/star/ucb/SimpleFileAccess.hpp>
#include <com/sun/star/ucb/UniversalContentBroker.hpp>
#include <com/sun/star/ucb/UnsupportedCommandException.hpp>
#include <com/sun/star/ucb/XCommandEnvironment.hpp>
#include <com/sun/star/ucb/XCommandProcessor.hpp>
#include <com/sun/star/ucb/XContent.hpp>
#include <com/sun/star/ucb/XSimpleFileAccess.hpp>
#include <com/sun/star/ucb/XUniversalContentBroker.hpp>
#include <com/sun/star/uno/Any.h>
#include <com/sun/star/uno/Any.hxx>
#include <com/sun/star/uno/Exception.hpp>
#include <com/sun/star/uno/Reference.hxx>
#include <com/sun/star/uno/RuntimeException.hpp>
#include <com/sun/star/uno/Sequence.hxx>
#include <com/sun/star/uno/XComponentContext.hpp>
#include <com/sun/star/uri/UriReferenceFactory.hpp>
#include <com/sun/star/uri/XUriReference.hpp>
#include <com/sun/star/uri/XUriReferenceFactory.hpp>
#include <com/sun/star/util/Date.hpp>
#include <com/sun/star/util/DateTime.hpp>
#include <com/sun/star/util/XPropertyReplace.hpp>
#include <com/sun/star/util/XReplaceDescriptor.hpp>
#include <com/sun/star/util/XReplaceable.hpp>
#include <com/sun/star/util/XSearchDescriptor.hpp>
#include <com/sun/star/util/XSearchable.hpp>
#include <comphelper/configuration.hxx>
#include <comphelper/extract.hxx>
#include <comphelper/flagguard.hxx>
#include <comphelper/processfactory.hxx>
#include <comphelper/sequence.hxx>
#include <comphelper/servicehelper.hxx>
#include <comphelper/sharedmutex.hxx>
#include <comphelper/string.hxx>
#include <cppuhelper/factory.hxx>
#include <cppuhelper/implbase2.hxx>
#include <cppuhelper/supportsservice.hxx>
#include <cppuhelper/weakref.hxx>
#include <cstdarg>
#include <cstdlib>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <functional>
#include <i18nlangtag/lang.h>
#include <i18nlangtag/languagetag.hxx>
#include <i18nlangtag/mslangid.hxx>
#include <limits.h>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <osl/diagnose.h>
#include <osl/endian.h>
#include <osl/file.h>
#include <osl/file.hxx>
#include <osl/mutex.hxx>
#include <osl/security.hxx>
#include <osl/socket.hxx>
#include <osl/time.h>
#include <rtl/alloc.h>
#include <rtl/crc.h>
#include <rtl/digest.h>
#include <rtl/instance.hxx>
#include <rtl/math.hxx>
#include <rtl/strbuf.hxx>
#include <rtl/string.hxx>
#include <rtl/ustrbuf.hxx>
#include <rtl/ustring.h>
#include <rtl/ustring.hxx>
#include <sal/config.h>
#include <sal/log.hxx>
#include <sal/macros.h>
#include <sal/types.h>
#include <salhelper/linkhelper.hxx>
#include <set>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tools/bigint.hxx>
#include <tools/color.hxx>
#include <tools/date.hxx>
#include <tools/debug.hxx>
#include <tools/diagnose_ex.h>
#include <tools/inetmime.hxx>
#include <tools/mapunit.hxx>
#include <tools/resmgr.hxx>
#include <tools/simplerm.hxx>
#include <tools/solar.h>
#include <tools/stream.hxx>
#include <tools/tenccvt.hxx>
#include <tools/time.hxx>
#include <tools/urlobj.hxx>
#include <tools/vcompat.hxx>
#include <tools/wldcrd.hxx>
#include <ucbhelper/content.hxx>
#include <unotools/bootstrap.hxx>
#include <unotools/calendarwrapper.hxx>
#include <unotools/charclass.hxx>
#include <unotools/configitem.hxx>
#include <unotools/digitgroupingiterator.hxx>
#include <unotools/intlwrapper.hxx>
#include <unotools/localedatawrapper.hxx>
#include <unotools/misccfg.hxx>
#include <unotools/nativenumberwrapper.hxx>
#include <unotools/numberformatcodewrapper.hxx>
#include <unotools/options.hxx>
#include <unotools/pathoptions.hxx>
#include <unotools/searchopt.hxx>
#include <unotools/streamwrap.hxx>
#include <unotools/syslocale.hxx>
#include <unotools/syslocaleoptions.hxx>
#include <unotools/useroptions.hxx>
#include <utility>
#include <vector>

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
