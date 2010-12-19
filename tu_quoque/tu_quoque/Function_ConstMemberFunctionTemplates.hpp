/******************************************************************************/
/*!
\file   Function_ConstMemberFunctionTemplates.hpp
\author Chris Barrett
\brief
  Member Function type implementations.

  Copyright (C) 2009 DigiPen Institute of Technology.
  Reproduction or disclosure of this file or its contents without the
  prior written consent of DigiPen Institute of Technology is prohibited.

*/
/******************************************************************************/


#pragma once
#ifndef FUNCTION_CONSTMEMBERFUNCTIONTEMPLATES_HPP_INCLUDED_
#define FUNCTION_CONSTMEMBERFUNCTIONTEMPLATES_HPP_INCLUDED_

// disable warning about throw specifications being ignored
#ifdef _MSC_VER
#pragma warning(disable: 4290)
#endif // _MSC_VER

#pragma warning ( push )
// Disabling the warning below:
// C4121: 'MFCore::ConstMemberFunction_0Parameters<T_Return,T_ClassType>' : alignment of a member was sensitive to packing
#pragma warning( disable : 4121 )

template <typename T_Return, typename T_ClassType>
struct ConstMemberFunction_0Parameters : public BoundFunction
{
  typedef T_Return (T_ClassType::*FunctionType)(void) const;

  ConstMemberFunction_0Parameters(FunctionType function, AnyStack const & default_arguments)
      throw()
    :    BoundFunction(Signature( Reflection::getTypeID<T_Return>(), Reflection::getTypeID<T_ClassType>(), false ), default_arguments)
      ,  function_(function)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    T_ClassType * object_pointer = arguments.extract<T_ClassType*>(0);
    last_return_ = (object_pointer->*function_)();
  }
  
  virtual BoundFunction * toDelegate(Any invoker)
  {
    return new ConstDelegate_0Parameters<T_Return, T_ClassType>(function_, invoker.extract<T_ClassType*>());
  }

  FunctionType function_;
};


template <typename T_ClassType>
struct ConstMemberFunction_0Parameters<void,T_ClassType> : public BoundFunction
{
  typedef void (T_ClassType::*FunctionType)(void) const;

  ConstMemberFunction_0Parameters(FunctionType function, AnyStack const & default_arguments)
      throw()
    :    BoundFunction(Signature( Reflection::getTypeID<void>(), Reflection::getTypeID<T_ClassType>(), false ), default_arguments)
      ,  function_(function)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    T_ClassType * object_pointer = arguments.extract<T_ClassType*>(0);
    (object_pointer->*function_)();
    last_return_ = 0;
  }
  
  virtual BoundFunction * toDelegate(Any invoker)
  {
    return new ConstDelegate_0Parameters<void, T_ClassType>(function_, invoker.extract<T_ClassType*>());
  }

  FunctionType function_;
};


template <typename T_Return, typename T_ClassType, typename T_Parameter0>
struct ConstMemberFunction_1Parameters : public BoundFunction
{
  typedef T_Return (T_ClassType::*FunctionType)(T_Parameter0) const;

  ConstMemberFunction_1Parameters(FunctionType function, AnyStack const & default_arguments=AnyStack())
      throw()
    :    BoundFunction(Signature( Reflection::getTypeID<T_Return>(), Reflection::getTypeID<T_ClassType>(), false, Reflection::getTypeID<T_Parameter0>() ), default_arguments)
      ,  function_(function)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 1);

    T_ClassType * object_pointer = arguments.extract<T_ClassType*>(0);
    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(1);
    last_return_ = (object_pointer->*function_)(argument0);
  }
  
  virtual BoundFunction * toDelegate(Any invoker)
  {
    return new ConstDelegate_1Parameters<T_Return,T_ClassType,T_Parameter0>(function_, invoker.extract<T_ClassType*>());
  }

  FunctionType function_;
};


template <typename T_ClassType, typename T_Parameter0>
struct ConstMemberFunction_1Parameters<void,T_ClassType,T_Parameter0> : public BoundFunction
{
  typedef void (T_ClassType::*FunctionType)(T_Parameter0) const;

  ConstMemberFunction_1Parameters(FunctionType function, AnyStack const & default_arguments=AnyStack())
      throw()
    :    BoundFunction(Signature( Reflection::getTypeID<void>(), Reflection::getTypeID<T_ClassType>(), false, Reflection::getTypeID<T_Parameter0>() ), default_arguments)
      ,  function_(function)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 1);

    T_ClassType * object_pointer = arguments.extract<T_ClassType*>(0);
    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(1);
    (object_pointer->*function_)(argument0);
    last_return_ = 0;
  }
  
  virtual BoundFunction * toDelegate(Any invoker)
  {
    return new ConstDelegate_1Parameters<void,T_ClassType,T_Parameter0>(function_, invoker.extract<T_ClassType*>());
  }

  FunctionType function_;
};


template <typename T_Return, typename T_ClassType, typename T_Parameter0, typename T_Parameter1>
struct ConstMemberFunction_2Parameters : public BoundFunction
{
  typedef T_Return (T_ClassType::*FunctionType)(T_Parameter0, T_Parameter1) const;

  ConstMemberFunction_2Parameters(FunctionType function, AnyStack const & default_arguments)
      throw()
    :    BoundFunction(Signature( Reflection::getTypeID<T_Return>(), Reflection::getTypeID<T_ClassType>(), false, Reflection::getTypeID<T_Parameter0>(), Reflection::getTypeID<T_Parameter1>() ), default_arguments)
      ,  function_(function)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 2);

    T_ClassType * object_pointer = arguments.extract<T_ClassType*>(0);
    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(1);
    T_Parameter1 argument1 = arguments.extract<T_Parameter1>(2);
    last_return_ = (object_pointer->*function_)(argument0, argument1);
  }
  
  virtual BoundFunction * toDelegate(Any invoker)
  {
    return new ConstDelegate_2Parameters<T_Return, T_ClassType, T_Parameter0, T_Parameter1>(function_, invoker.extract<T_ClassType*>());
  }

  FunctionType function_;
};


template <typename T_ClassType, typename T_Parameter0, typename T_Parameter1>
struct ConstMemberFunction_2Parameters<void,T_ClassType,T_Parameter0,T_Parameter1> : public BoundFunction
{
  typedef void (T_ClassType::*FunctionType)(T_Parameter0, T_Parameter1) const;

  ConstMemberFunction_2Parameters(FunctionType function, AnyStack const & default_arguments)
      throw()
    :    BoundFunction(Signature( Reflection::getTypeID<void>(), Reflection::getTypeID<T_ClassType>(), false, Reflection::getTypeID<T_Parameter0>(), Reflection::getTypeID<T_Parameter1>() ), default_arguments)
      ,  function_(function)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 2);

    T_ClassType * object_pointer = arguments.extract<T_ClassType*>(0);
    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(1);
    T_Parameter1 argument1 = arguments.extract<T_Parameter1>(2);
    (object_pointer->*function_)(argument0, argument1);
    last_return_ = 0;
  }
  
  virtual BoundFunction * toDelegate(Any invoker)
  {
    return new ConstDelegate_2Parameters<void, T_ClassType, T_Parameter0, T_Parameter1>(function_, invoker.extract<T_ClassType*>());
  }

  FunctionType function_;
};


template <typename T_Return, typename T_ClassType, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2>
struct ConstMemberFunction_3Parameters : public BoundFunction
{
  typedef T_Return (T_ClassType::*FunctionType)(T_Parameter0, T_Parameter1, T_Parameter2) const;

  ConstMemberFunction_3Parameters(FunctionType function, AnyStack const & default_arguments)
      throw()
    :    BoundFunction(Signature( Reflection::getTypeID<T_Return>(), Reflection::getTypeID<T_ClassType>(), false, Reflection::getTypeID<T_Parameter0>(), Reflection::getTypeID<T_Parameter1>(), Reflection::getTypeID<T_Parameter2>() ), default_arguments)
      ,  function_(function)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 3);

    T_ClassType * object_pointer = arguments.extract<T_ClassType*>(0);
    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(1);
    T_Parameter1 argument1 = arguments.extract<T_Parameter1>(2);
    T_Parameter2 argument2 = arguments.extract<T_Parameter2>(3);
    last_return_ = (object_pointer->*function_)(argument0, argument1, argument2);
  }
  
  virtual BoundFunction * toDelegate(Any invoker)
  {
    return new ConstDelegate_3Parameters<T_Return, T_ClassType, T_Parameter0, T_Parameter1, T_Parameter2>(function_, invoker.extract<T_ClassType*>());
  }

  FunctionType function_;
};


template <typename T_ClassType, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2>
struct ConstMemberFunction_3Parameters<void,T_ClassType,T_Parameter0,T_Parameter1,T_Parameter2> : public BoundFunction
{
  typedef void (T_ClassType::*FunctionType)(T_Parameter0, T_Parameter1, T_Parameter2) const;

  ConstMemberFunction_3Parameters(FunctionType function, AnyStack const & default_arguments)
      throw()
    :    BoundFunction(Signature( Reflection::getTypeID<void>(), Reflection::getTypeID<T_ClassType>(), false, Reflection::getTypeID<T_Parameter0>(), Reflection::getTypeID<T_Parameter1>(), Reflection::getTypeID<T_Parameter2>() ), default_arguments)
      ,  function_(function)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 3);

    T_ClassType * object_pointer = arguments.extract<T_ClassType*>(0);
    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(1);
    T_Parameter1 argument1 = arguments.extract<T_Parameter1>(2);
    T_Parameter2 argument2 = arguments.extract<T_Parameter2>(3);
    (object_pointer->*function_)(argument0, argument1, argument2);
    last_return_ = 0;
  }
  
  virtual BoundFunction * toDelegate(Any invoker)
  {
    return new ConstDelegate_3Parameters<void, T_ClassType, T_Parameter0, T_Parameter1, T_Parameter2>(function_, invoker.extract<T_ClassType*>());
  }

  FunctionType function_;
};


template <typename T_Return, typename T_ClassType, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2, typename T_Parameter3>
struct ConstMemberFunction_4Parameters : public BoundFunction
{
  typedef T_Return (T_ClassType::*FunctionType)(T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3) const;

  ConstMemberFunction_4Parameters(FunctionType function, AnyStack const & default_arguments)
      throw()
    :    BoundFunction(Signature( Reflection::getTypeID<T_Return>(), Reflection::getTypeID<T_ClassType>(), false, Reflection::getTypeID<T_Parameter0>(), Reflection::getTypeID<T_Parameter1>(), Reflection::getTypeID<T_Parameter2>(), Reflection::getTypeID<T_Parameter3>() ), default_arguments)
      ,  function_(function)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 4);

    T_ClassType * object_pointer = arguments.extract<T_ClassType*>(0);
    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(1);
    T_Parameter1 argument1 = arguments.extract<T_Parameter1>(2);
    T_Parameter2 argument2 = arguments.extract<T_Parameter2>(3);
    T_Parameter3 argument3 = arguments.extract<T_Parameter3>(4);
    last_return_ = (object_pointer->*function_)(argument0, argument1, argument2, argument3);
  }
  
  virtual BoundFunction * toDelegate(Any invoker)
  {
    return new ConstDelegate_4Parameters<T_Return, T_ClassType, T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3>(function_, invoker.extract<T_ClassType*>());
  }

  FunctionType function_;
};


template <typename T_ClassType, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2, typename T_Parameter3>
struct ConstMemberFunction_4Parameters<void,T_ClassType,T_Parameter0,T_Parameter1,T_Parameter2,T_Parameter3> : public BoundFunction
{
  typedef void (T_ClassType::*FunctionType)(T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3) const;

  ConstMemberFunction_4Parameters(FunctionType function, AnyStack const & default_arguments)
      throw()
    :    BoundFunction(Signature( Reflection::getTypeID<void>(), Reflection::getTypeID<T_ClassType>(), false, Reflection::getTypeID<T_Parameter0>(), Reflection::getTypeID<T_Parameter1>(), Reflection::getTypeID<T_Parameter2>(), Reflection::getTypeID<T_Parameter3>() ), default_arguments)
      ,  function_(function)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 4);

    T_ClassType * object_pointer = arguments.extract<T_ClassType*>(0);
    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(1);
    T_Parameter1 argument1 = arguments.extract<T_Parameter1>(2);
    T_Parameter2 argument2 = arguments.extract<T_Parameter2>(3);
    T_Parameter3 argument3 = arguments.extract<T_Parameter3>(4);
    (object_pointer->*function_)(argument0, argument1, argument2, argument3);
    last_return_ = 0;
  }
  
  virtual BoundFunction * toDelegate(Any invoker)
  {
    return new ConstDelegate_4Parameters<void, T_ClassType, T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3>(function_, invoker.extract<T_ClassType*>());
  }

  FunctionType function_;
};


template <typename T_Return, typename T_ClassType, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2, typename T_Parameter3, typename T_Parameter4>
struct ConstMemberFunction_5Parameters : public BoundFunction
{
  typedef T_Return (T_ClassType::*FunctionType)(T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3, T_Parameter4) const;

  ConstMemberFunction_5Parameters(FunctionType function, AnyStack const & default_arguments)
      throw()
    :    BoundFunction(Signature( Reflection::getTypeID<T_Return>(), Reflection::getTypeID<T_ClassType>(), false, Reflection::getTypeID<T_Parameter0>(), Reflection::getTypeID<T_Parameter1>(), Reflection::getTypeID<T_Parameter2>(), Reflection::getTypeID<T_Parameter3>(), Reflection::getTypeID<T_Parameter4>() ), default_arguments)
      ,  function_(function)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 5);

    T_ClassType * object_pointer = arguments.extract<T_ClassType*>(0);
    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(1);
    T_Parameter1 argument1 = arguments.extract<T_Parameter1>(2);
    T_Parameter2 argument2 = arguments.extract<T_Parameter2>(3);
    T_Parameter3 argument3 = arguments.extract<T_Parameter3>(4);
    T_Parameter4 argument4 = arguments.extract<T_Parameter4>(5);
    last_return_ = (object_pointer->*function_)(argument0, argument1, argument2, argument3, argument4);
  }
  
  virtual BoundFunction * toDelegate(Any invoker)
  {
    return new ConstDelegate_5Parameters<T_Return, T_ClassType, T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3, T_Parameter4>(function_, invoker.extract<T_ClassType*>());
  }

  FunctionType function_;
};


template <typename T_ClassType, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2, typename T_Parameter3, typename T_Parameter4>
struct ConstMemberFunction_5Parameters<void,T_ClassType,T_Parameter0,T_Parameter1,T_Parameter2,T_Parameter3,T_Parameter4> : public BoundFunction
{
  typedef void (T_ClassType::*FunctionType)(T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3, T_Parameter4) const;

  ConstMemberFunction_5Parameters(FunctionType function, AnyStack const & default_arguments)
      throw()
    :    BoundFunction(Signature( Reflection::getTypeID<void>(), Reflection::getTypeID<T_ClassType>(), false, Reflection::getTypeID<T_Parameter0>(), Reflection::getTypeID<T_Parameter1>(), Reflection::getTypeID<T_Parameter2>(), Reflection::getTypeID<T_Parameter3>(), Reflection::getTypeID<T_Parameter4>() ), default_arguments)
      ,  function_(function)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 5);

    T_ClassType * object_pointer = arguments.extract<T_ClassType*>(0);
    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(1);
    T_Parameter1 argument1 = arguments.extract<T_Parameter1>(2);
    T_Parameter2 argument2 = arguments.extract<T_Parameter2>(3);
    T_Parameter3 argument3 = arguments.extract<T_Parameter3>(4);
    T_Parameter4 argument4 = arguments.extract<T_Parameter4>(5);
    (object_pointer->*function_)(argument0, argument1, argument2, argument3, argument4);
    last_return_ = 0;
  }
  
  virtual BoundFunction * toDelegate(Any invoker)
  {
    return new ConstDelegate_5Parameters<void, T_ClassType, T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3, T_Parameter4>(function_, invoker.extract<T_ClassType*>());
  }

  FunctionType function_;
};

#pragma warning ( pop )

#endif // ndef FUNCTION_CONSTMEMBERFUNCTIONTEMPLATES_HPP_INCLUDED_

