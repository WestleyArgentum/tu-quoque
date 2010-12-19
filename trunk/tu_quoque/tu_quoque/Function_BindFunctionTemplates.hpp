/******************************************************************************/
/*!
\file   Function_BindFunctionTemplates.hpp
\author Chris Barrett
\brief
  Function binding methods for the 'static' Function type.

  Copyright (C) 2009 DigiPen Institute of Technology.
  Reproduction or disclosure of this file or its contents without the
  prior written consent of DigiPen Institute of Technology is prohibited.

*/
/******************************************************************************/


#pragma once
#ifndef FUNCTION_BINDFUNCTIONTEMPLATES_HPP_INCLUDED_
#define FUNCTION_BINDFUNCTIONTEMPLATES_HPP_INCLUDED_

////////////////////////////////////////////////////////////////////////////////////////////////////
//[ Static function binders (begin)
//////////////////////////////////////////////////

#include "Function_StaticFunctionTemplates.hpp"

template <typename T_Return>
BoundFunction * BindFunction( T_Return (*function)(), AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new StaticFunction_0Parameters<T_Return>(function, default_arguments);
}

template <typename T_Return, typename T_Parameter0>
BoundFunction * BindFunction( T_Return (*function)(T_Parameter0), AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new StaticFunction_1Parameters<T_Return, T_Parameter0>(function, default_arguments);
}

template <typename T_Return, typename T_Parameter0, typename T_Parameter1>
BoundFunction * BindFunction( T_Return (*function)(T_Parameter0, T_Parameter1), AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new StaticFunction_2Parameters<T_Return, T_Parameter0, T_Parameter1>(function, default_arguments);
}

template <typename T_Return, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2>
BoundFunction * BindFunction( T_Return (*function)(T_Parameter0, T_Parameter1, T_Parameter2), AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new StaticFunction_3Parameters<T_Return, T_Parameter0, T_Parameter1, T_Parameter2>(function, default_arguments);
}

template <typename T_Return, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2, typename T_Parameter3>
BoundFunction * BindFunction( T_Return (*function)(T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3), AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new StaticFunction_4Parameters<T_Return, T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3>(function, default_arguments);
}

template <typename T_Return, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2, typename T_Parameter3, typename T_Parameter4>
BoundFunction * BindFunction( T_Return (*function)(T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3, T_Parameter4), AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new StaticFunction_5Parameters<T_Return, T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3, T_Parameter4>(function, default_arguments);
}

//////////////////////////////////////////////////
//] Static function binders (end)
////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region Member function binders
//[ Member function binders (begin)
//////////////////////////////////////////////////

#include "Function_MemberFunctionTemplates.hpp"

template <typename T_Return, typename T_Class>
BoundFunction * BindFunction( T_Return (T_Class::*function)(), AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new MemberFunction_0Parameters<T_Return, T_Class>(function, default_arguments);
}

template <typename T_Return, typename T_Class, typename T_Parameter0>
BoundFunction * BindFunction( T_Return (T_Class::*function)(T_Parameter0), AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new MemberFunction_1Parameters<T_Return, T_Class, T_Parameter0>(function, default_arguments);
}

template <typename T_Return, typename T_Class, typename T_Parameter0, typename T_Parameter1>
BoundFunction * BindFunction( T_Return (T_Class::*function)(T_Parameter0, T_Parameter1), AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new MemberFunction_2Parameters<T_Return, T_Class, T_Parameter0, T_Parameter1>(function, default_arguments);
}

template <typename T_Return, typename T_Class, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2>
BoundFunction * BindFunction( T_Return (T_Class::*function)(T_Parameter0, T_Parameter1, T_Parameter2), AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new MemberFunction_3Parameters<T_Return, T_Class, T_Parameter0, T_Parameter1, T_Parameter2>(function, default_arguments);
}

template <typename T_Return, typename T_Class, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2, typename T_Parameter3>
BoundFunction * BindFunction( T_Return (T_Class::*function)(T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3), AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new MemberFunction_4Parameters<T_Return, T_Class, T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3>(function, default_arguments);
}

template <typename T_Return, typename T_Class, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2, typename T_Parameter3, typename T_Parameter4>
BoundFunction * BindFunction( T_Return (T_Class::*function)(T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3, T_Parameter4), AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new MemberFunction_5Parameters<T_Return, T_Class, T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3, T_Parameter4>(function, default_arguments);
}

//////////////////////////////////////////////////
//] Member function binders (end)
#pragma endregion
////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region Const_Member function binders
//[ Const member function binders (begin)
//////////////////////////////////////////////////

#include "Function_ConstMemberFunctionTemplates.hpp"

template <typename T_Return, typename T_Class>
BoundFunction * BindFunction( T_Return (T_Class::*function)() const, AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new ConstMemberFunction_0Parameters<T_Return, T_Class>(function, default_arguments);
}

template <typename T_Return, typename T_Class, typename T_Parameter0>
BoundFunction * BindFunction( T_Return (T_Class::*function)(T_Parameter0) const, AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new ConstMemberFunction_1Parameters<T_Return, T_Class, T_Parameter0>(function, default_arguments);
}

template <typename T_Return, typename T_Class, typename T_Parameter0, typename T_Parameter1>
BoundFunction * BindFunction( T_Return (T_Class::*function)(T_Parameter0, T_Parameter1) const, AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new ConstMemberFunction_2Parameters<T_Return, T_Class, T_Parameter0, T_Parameter1>(function, default_arguments);
}

template <typename T_Return, typename T_Class, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2>
BoundFunction * BindFunction( T_Return (T_Class::*function)(T_Parameter0, T_Parameter1, T_Parameter2) const, AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new ConstMemberFunction_3Parameters<T_Return, T_Class, T_Parameter0, T_Parameter1, T_Parameter2>(function, default_arguments);
}

template <typename T_Return, typename T_Class, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2, typename T_Parameter3>
BoundFunction * BindFunction( T_Return (T_Class::*function)(T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3) const, AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new ConstMemberFunction_4Parameters<T_Return, T_Class, T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3>(function, default_arguments);
}

template <typename T_Return, typename T_Class, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2, typename T_Parameter3, typename T_Parameter4>
BoundFunction * BindFunction( T_Return (T_Class::*function)(T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3, T_Parameter4) const, AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new ConstMemberFunction_5Parameters<T_Return, T_Class, T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3, T_Parameter4>(function, default_arguments);
}

//////////////////////////////////////////////////
//] Const member function binders (end)
#pragma endregion
////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // ndef FUNCTION_BINDFUNCTIONTEMPLATES_HPP_INCLUDED_
