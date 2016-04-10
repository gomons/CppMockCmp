/** @file
    @brief Creates a stub returning a value and calling a functor

  $Id: ReturnValueAndCall.h 1506 2010-01-04 19:28:05Z ewald-arnold $

 ***************************************************************************/

/**************************************************************************

   begin                : Mon Nov 10 2008
   copyright            : (C) 2008 by Mathieu Champlon
   email                : mockpp at ewald-arnold dot de

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation; either version 2 of the License,
   or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

 **/

#ifndef MOCKPP_ReturnAndCall_H
#define MOCKPP_ReturnAndCall_H

#include <mockpp/mockpp.h> // always first

#include <mockpp/stub/ReturnAndCallStub.h>
#include <mockpp/stub/CallStub.h>


MOCKPP_NS_START


/** Creates a stub returning a value and calling a functor
  * @ingroup grp_stub_abbrev
  * @see mockpp::ReturnStub
  * @param  o    the value to return
  * @param  f    functor to call
  * @return the new stub
  */
template <  typename R      // Return Value
          , typename F      // Functor Parameter
         >
typename TypelessStub<R>::AP returnValueAndCall(const R &o, F f)
{
  return new ReturnAndCallStub<R, F>(o, f);
}


/** Creates a stub calling a functor
  * @ingroup grp_stub_abbrev
  * @see mockpp::ReturnStub
  * @param  f    functor to call
  * @return the new stub
  */
template <  typename F      // Functor Parameter
         >
typename TypelessStub<void>::AP call(F f)
{
  return new CallStub<F>( f );
}


MOCKPP_NS_END


#endif // MOCKPP_ReturnAndCall_H
