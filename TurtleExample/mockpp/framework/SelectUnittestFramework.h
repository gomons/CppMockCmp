/***************************************************************************
   SelectUnittestFramework.h  -  setup for unittest framework in use
                             -------------------
    begin                : Fri Dec 9 2005
    copyright            : (C) 2002-2010 by Ewald Arnold
    email                : mockpp at ewald-arnold dot de

  $Id: SelectUnittestFramework.h 1506 2010-01-04 19:28:05Z ewald-arnold $

 ***************************************************************************/

/**************************************************************************
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2 of the License,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 ***************************************************************************/

#ifndef MOCKPP_SELECTUNITTESTFRAMEWORK_H
#define MOCKPP_SELECTUNITTESTFRAMEWORK_H

#include <mockpp/mockpp.h>  // always first

/** @defgroup grp_framework Support for test frameworks.
  * Mockpp as no test framework of its own. For that reason
  * there is support for various existing test frameworks.
  */

/** @def MOCKPP_DERIVE_PUBLIC_UNITFRAMEWORK
  * @ingroup grp_framework
  * Contains a code fragment to create a test suite that contains
  * one or more test cases which are arranged as class methods.
  * This is done by publicly deriving from an according class of
  * the test framework.
  * For frameworks that don't support this, the macro is empty.
  */

/** @def MOCKPP_TESTMETHOD_DECL
  * @ingroup grp_framework
  * Depending on the test framework the test methods are
  * regular class methods or rather static to react like free
  * functions. So this macro is used to declare the methods accordingly.
  */

#ifdef DOXYGEN_SHOULD_INCLUDE_THIS // make doxygen happily include docs
#define MOCKPP_USE_CXXTEST
#define MOCKPP_USE_CPPUNIT
#define MOCKPP_USE_BOOSTTEST
#endif

/** @def MOCKPP_USE_CXXTEST
  * @ingroup grp_config
  * Defined if CxxTest is used as framework.
  */

/** @def MOCKPP_USE_CPPUNIT
  * @ingroup grp_config
  * Defined if CppUnit is used as framework.
  */

/** @def MOCKPP_USE_BOOSTTEST
  * @ingroup grp_config
  * Defined if Boost.Test is used as framework.
  */

//=================================================
#if defined(MOCKPP_USE_CXXTEST)
//=================================================

# define MOCKPP_DERIVE_PUBLIC_UNITFRAMEWORK : public CXXTEST_NS::TestSuite

#define MOCKPP_TESTMETHOD_DECL /* static or not */

#define CXXTEST_HAVE_STD
#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD

#ifndef MOCKPP_NO_EXCEPTIONS
#define CXXTEST_ABORT_TEST_ON_FAIL
#define _CXXTEST_HAVE_EH
#endif

#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/RealDescriptions.h>

#include <mockpp/framework/CxxTestSupport.h>

//=================================================
#elif defined(MOCKPP_USE_CPPUNIT)
//=================================================

#define MOCKPP_TESTMETHOD_DECL /* not static */

# include <cppunit/extensions/HelperMacros.h>
# define MOCKPP_DERIVE_PUBLIC_UNITFRAMEWORK : public CppUnit::TestFixture

//=================================================
#elif defined(MOCKPP_USE_BOOSTTEST)
//=================================================

// before boost headers
// # define BOOST_TEST_NO_MAIN mockpp
// # define BOOST_TEST_DYN_LINK
// # define BOOST_ALL_DYN_LINK
// before boost headers

# include <boost/test/unit_test.hpp>
# include <cstdio>

# define MOCKPP_TESTMETHOD_DECL static

# define MOCKPP_DERIVE_PUBLIC_UNITFRAMEWORK /* : public boost::test_case */

#define MOCKPP_JOIN( X, Z ) MOCKPP_DO_JOIN3( X, __, Z )
#define MOCKPP_DO_JOIN3( X, Y, Z ) X##Y##Z

/** Register a method as test.
  * @ingroup grp_framework
  * @param class_name classname
  * @param func_name method name of the static class method.
  */
#define MOCKPP_BOOST_TEST(class_name, func_name) \
BOOST_AUTO_TEST_CASE( MOCKPP_JOIN(class_name, func_name) )  \
{                                                           \
    /*printf(#class_name "::" #func_name "\n");*/           \
    class_name :: func_name();                              \
}

//=================================================
#else
//=================================================

# pragma message ("No unittest framework available at compile time")
# define MOCKPP_DERIVE_PUBLIC_UNITFRAMEWORK   /**/

#endif // frameworks

#endif // MOCKPP_SELECTUNITTESTFRAMEWORK_H
