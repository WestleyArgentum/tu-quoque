/******************************************************************************/
/*!
\file   Delegate_BindFunctionTemplates.hpp
\author Chris Barrett
\brief
  Function binding methods for the Delegate type.

  Copyright (C) 2009 DigiPen Institute of Technology.
  Reproduction or disclosure of this file or its contents without the
  prior written consent of DigiPen Institute of Technology is prohibited.

*/
/******************************************************************************/


#pragma once
#include "Delegate.hpp"


template <typename T_Return, typename T_Class>
BoundFunction * BindFunction( T_Class * object_pointer, T_Return (T_Class::*function)(void), AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new Delegate_0Parameters<T_Return, T_Class>(function, object_pointer, default_arguments);
}

template <typename T_Return, typename T_Class, typename T_Parameter0>
BoundFunction * BindFunction( T_Class * object_pointer, T_Return (T_Class::*function)(T_Parameter0), AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new Delegate_1Parameters<T_Return, T_Class, T_Parameter0>(function, object_pointer, default_arguments);
}

template <typename T_Return, typename T_Class, typename T_Parameter0, typename T_Parameter1>
BoundFunction * BindFunction( T_Class * object_pointer, T_Return (T_Class::*function)(T_Parameter0, T_Parameter1), AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new Delegate_2Parameters<T_Return, T_Class, T_Parameter0, T_Parameter1>(function, object_pointer, default_arguments);
}

template <typename T_Return, typename T_Class, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2>
BoundFunction * BindFunction( T_Class * object_pointer, T_Return (T_Class::*function)(T_Parameter0, T_Parameter1, T_Parameter2), AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new Delegate_3Parameters<T_Return, T_Class, T_Parameter0, T_Parameter1, T_Parameter2>(function, object_pointer, default_arguments);
}

template <typename T_Return, typename T_Class, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2, typename T_Parameter3>
BoundFunction * BindFunction( T_Class * object_pointer, T_Return (T_Class::*function)(T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3), AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new Delegate_4Parameters<T_Return, T_Class, T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3>(function, object_pointer, default_arguments);
}

template <typename T_Return, typename T_Class, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2, typename T_Parameter3, typename T_Parameter4>
BoundFunction * BindFunction( T_Class * object_pointer, T_Return (T_Class::*function)(T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3, T_Parameter4), AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new Delegate_5Parameters<T_Return, T_Class, T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3, T_Parameter4>(function, object_pointer, default_arguments);
}


#include "ConstDelegate.hpp"


template <typename T_Return, typename T_Class>
BoundFunction * BindFunction( T_Class * object_pointer, T_Return (T_Class::*function)(void) const, AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new ConstDelegate_0Parameters<T_Return, T_Class>(function, object_pointer, default_arguments);
}

template <typename T_Return, typename T_Class, typename T_Parameter0>
BoundFunction * BindFunction( T_Class * object_pointer, T_Return (T_Class::*function)(T_Parameter0) const, AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new ConstDelegate_1Parameters<T_Return, T_Class, T_Parameter0>(function, object_pointer, default_arguments);
}

template <typename T_Return, typename T_Class, typename T_Parameter0, typename T_Parameter1>
BoundFunction * BindFunction( T_Class * object_pointer, T_Return (T_Class::*function)(T_Parameter0, T_Parameter1) const, AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new ConstDelegate_2Parameters<T_Return, T_Class, T_Parameter0, T_Parameter1>(function, object_pointer, default_arguments);
}

template <typename T_Return, typename T_Class, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2>
BoundFunction * BindFunction( T_Class * object_pointer, T_Return (T_Class::*function)(T_Parameter0, T_Parameter1, T_Parameter2) const, AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new ConstDelegate_3Parameters<T_Return, T_Class, T_Parameter0, T_Parameter1, T_Parameter2>(function, object_pointer, default_arguments);
}

template <typename T_Return, typename T_Class, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2, typename T_Parameter3>
BoundFunction * BindFunction( T_Class * object_pointer, T_Return (T_Class::*function)(T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3) const, AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new ConstDelegate_4Parameters<T_Return, T_Class, T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3>(function, object_pointer, default_arguments);
}

template <typename T_Return, typename T_Class, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2, typename T_Parameter3, typename T_Parameter4>
BoundFunction * BindFunction( T_Class * object_pointer, T_Return (T_Class::*function)(T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3, T_Parameter4) const, AnyStack const & default_arguments=AnyStack() )
  throw(std::bad_alloc)
{
  return new ConstDelegate_5Parameters<T_Return, T_Class, T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3, T_Parameter4>(function, object_pointer, default_arguments);
}
