/** @file
    @brief    Stub calling a functor.

  $Id: CallStub.h 1499 2010-01-03 17:05:29Z ewald-arnold $

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

#ifndef MOCKPP_CallStub_H
#define MOCKPP_CallStub_H

#include <mockpp/mockpp.h> // always first

#include <mockpp/compat/Formatter.h>

#include <mockpp/stub/TypelessStub.h>


MOCKPP_NS_START


/** Always call some functor.
  * @ingroup grp_stub
  * @see mockpp::returnValueAndCall
  */
template <  typename F     // Functor
         >
class CallStub : public TypelessStub<void>
{
  public:

  /** Creates the object.
    * @param  in_functor  functor to call
    */
    CallStub(  F in_functor )
      : functor(in_functor)
    {}

  /** Mock the invocation without passing parameters.
    * Calls the functor.
    */
    virtual void typelessInvoke()
    {
      functor();
    }

  /** Appends the description of this object to the buffer.
    * @param buffer The buffer that the description is appended to.
    * @return The current content of the buffer data
    */
    virtual String describeTo( String &buffer ) const
    {
      String fmt;
      fmt += MOCKPP_PCHAR("calls functor\n");
      buffer += fmt;

      return buffer;
    }

  private:

    F   functor;
};


MOCKPP_NS_END

#endif // MOCKPP_CallStub_H


