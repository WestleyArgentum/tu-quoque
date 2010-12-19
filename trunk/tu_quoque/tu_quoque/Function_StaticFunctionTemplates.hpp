/******************************************************************************/
/*!
\file   Function_StaticFunctionTemplates.hpp
\author Chris Barrett
\brief
  'Static' Function type implementations.

  Copyright (C) 2009 DigiPen Institute of Technology.
  Reproduction or disclosure of this file or its contents without the
  prior written consent of DigiPen Institute of Technology is prohibited.

*/
/******************************************************************************/


#pragma once
#ifndef FUNCTION_STATICFUNCTIONTEMPLATES_HPP_INCLUDED_
#define FUNCTION_STATICFUNCTIONTEMPLATES_HPP_INCLUDED_

// disable warning about throw specifications being ignored
#ifdef _MSC_VER
#pragma warning(disable: 4290)
#endif // def _MSC_VER

#pragma warning ( push )
// Disabling the warning below:
// C4121: 'MFCore::StaticFunction_0Parameters<T_Return,T_ClassType>' : alignment of a member was sensitive to packing
#pragma warning( disable : 4121 )

template <typename T_Return>
struct StaticFunction_0Parameters : public BoundFunction
{
  typedef T_Return (*FunctionType)(void);
  
  StaticFunction_0Parameters(FunctionType function, AnyStack const & default_arguments)
      throw()
    :    BoundFunction(Signature( Reflection::getTypeID<T_Return>(), 0, false ), default_arguments)
      ,  function_(function)
  {}
  
  virtual void operator()(AnyStack & /*arguments*/)
  {
    last_return_ = function_();
  }
  
  FunctionType function_;
};


template <>
struct StaticFunction_0Parameters<void> : public BoundFunction
{
  typedef void (*FunctionType)(void);
  
  StaticFunction_0Parameters(FunctionType function, AnyStack const & default_arguments)
      throw()
    :    BoundFunction(Signature( Reflection::getTypeID<void>(), 0, false ), default_arguments)
      ,  function_(function)
  {}
  
  virtual void operator()(AnyStack & /*arguments*/)
  {
    function_();
    last_return_ = 0;
  }
  
  FunctionType function_;
};


template <typename T_Return, typename T_Parameter0>
struct StaticFunction_1Parameters : public BoundFunction
{
  typedef T_Return (*FunctionType)(T_Parameter0);

  StaticFunction_1Parameters(FunctionType function, AnyStack const & default_arguments)
      throw()
    :    BoundFunction(Signature( Reflection::getTypeID<T_Return>(), 0, false, T_Parameter0() ), default_arguments)
      ,  function_(function)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 1);
    
    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(0);
    last_return_ = function_(argument0);
  }

  FunctionType function_;
};


template <typename T_Parameter0>
struct StaticFunction_1Parameters<void,T_Parameter0> : public BoundFunction
{
  typedef void (*FunctionType)(T_Parameter0);

  StaticFunction_1Parameters(FunctionType function, AnyStack const & default_arguments)
      throw()
    :    BoundFunction(Signature( Reflection::getTypeID<void>(), 0, false, Reflection::getTypeID<T_Parameter0>() ), default_arguments)
      ,  function_(function)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 1);
    
    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(0);
    function_(argument0);
    last_return_ = 0;
  }

  FunctionType function_;
};


template <typename T_Return, typename T_Parameter0, typename T_Parameter1>
struct StaticFunction_2Parameters : public BoundFunction
{
  typedef T_Return (*FunctionType)(T_Parameter0, T_Parameter1);

  StaticFunction_2Parameters(FunctionType function, AnyStack const & default_arguments)
      throw()
    :    BoundFunction(Signature( Reflection::getTypeID<T_Return>(), 0, false, Reflection::getTypeID<T_Parameter0>(), Reflection::getTypeID<T_Parameter1>() ), default_arguments)
      ,  function_(function)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 2);
    
    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(0);
    T_Parameter1 argument1 = arguments.extract<T_Parameter1>(1);
    last_return_ = function_(argument0, argument1);
  }

  FunctionType function_;
};


template <typename T_Parameter0, typename T_Parameter1>
struct StaticFunction_2Parameters<void,T_Parameter0,T_Parameter1> : public BoundFunction
{
  typedef void (*FunctionType)(T_Parameter0, T_Parameter1);

  StaticFunction_2Parameters(FunctionType function, AnyStack const & default_arguments)
      throw()
    :    BoundFunction(Signature( Reflection::getTypeID<void>(), 0, false, Reflection::getTypeID<T_Parameter0>(), Reflection::getTypeID<T_Parameter1>() ), default_arguments)
      ,  function_(function)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 2);
    
    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(0);
    T_Parameter1 argument1 = arguments.extract<T_Parameter1>(1);
    function_(argument0, argument1);
    last_return_ = 0;
  }

  FunctionType function_;
};


template <typename T_Return, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2>
struct StaticFunction_3Parameters : public BoundFunction
{
  typedef T_Return (*FunctionType)(T_Parameter0, T_Parameter1, T_Parameter2);

  StaticFunction_3Parameters(FunctionType function, AnyStack const & default_arguments)
      throw()
    :    BoundFunction(Signature( Reflection::getTypeID<T_Return>(), 0, false, Reflection::getTypeID<T_Parameter0>(), Reflection::getTypeID<T_Parameter1>(), Reflection::getTypeID<T_Parameter2>() ), default_arguments)
      ,  function_(function)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 3);

    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(0);
    T_Parameter1 argument1 = arguments.extract<T_Parameter1>(1);
    T_Parameter2 argument2 = arguments.extract<T_Parameter2>(2);
    last_return_ = function_(argument0, argument1, argument2);
  }

  FunctionType function_;
};


template <typename T_Parameter0, typename T_Parameter1, typename T_Parameter2>
struct StaticFunction_3Parameters<void,T_Parameter0,T_Parameter1,T_Parameter2> : public BoundFunction
{
  typedef void (*FunctionType)(T_Parameter0, T_Parameter1, T_Parameter2);

  StaticFunction_3Parameters(FunctionType function, AnyStack const & default_arguments)
      throw()
    :    BoundFunction(Signature( Reflection::getTypeID<void>(), 0, false, Reflection::getTypeID<T_Parameter0>(), Reflection::getTypeID<T_Parameter1>(), Reflection::getTypeID<T_Parameter2>() ), default_arguments)
      ,  function_(function)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 3);

    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(0);
    T_Parameter1 argument1 = arguments.extract<T_Parameter1>(1);
    T_Parameter2 argument2 = arguments.extract<T_Parameter2>(2);
    function_(argument0, argument1, argument2);
    last_return_ = 0;
  }

  FunctionType function_;
};


template <typename T_Return, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2, typename T_Parameter3>
struct StaticFunction_4Parameters : public BoundFunction
{
  typedef T_Return (*FunctionType)(T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3);
  
  StaticFunction_4Parameters(FunctionType function, AnyStack const & default_arguments)
      throw()
    :    BoundFunction(Signature( Reflection::getTypeID<T_Return>(), 0, false, Reflection::getTypeID<T_Parameter0>(), Reflection::getTypeID<T_Parameter1>(), Reflection::getTypeID<T_Parameter2>(), Reflection::getTypeID<T_Parameter3>() ), default_arguments)
      ,  function_(function)
  {}
  
  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 4);

    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(0);
    T_Parameter1 argument1 = arguments.extract<T_Parameter1>(1);
    T_Parameter2 argument2 = arguments.extract<T_Parameter2>(2);
    T_Parameter3 argument3 = arguments.extract<T_Parameter3>(3);
    last_return_ = function_(argument0, argument1, argument2, argument3);
  }
  
  FunctionType function_;
};


template <typename T_Parameter0, typename T_Parameter1, typename T_Parameter2, typename T_Parameter3>
struct StaticFunction_4Parameters<void,T_Parameter0,T_Parameter1,T_Parameter2,T_Parameter3> : public BoundFunction
{
  typedef void (*FunctionType)(T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3);
  
  StaticFunction_4Parameters(FunctionType function, AnyStack const & default_arguments)
      throw()
    :    BoundFunction(Signature( Reflection::getTypeID<void>(), 0, false, Reflection::getTypeID<T_Parameter0>(), Reflection::getTypeID<T_Parameter1>(), Reflection::getTypeID<T_Parameter2>(), Reflection::getTypeID<T_Parameter3>() ), default_arguments)
      ,  function_(function)
  {}
  
  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 4);

    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(0);
    T_Parameter1 argument1 = arguments.extract<T_Parameter1>(1);
    T_Parameter2 argument2 = arguments.extract<T_Parameter2>(2);
    T_Parameter3 argument3 = arguments.extract<T_Parameter3>(3);
    function_(argument0, argument1, argument2, argument3);
    last_return_ = 0;
  }
  
  FunctionType function_;
};


template <typename T_Return, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2, typename T_Parameter3, typename T_Parameter4>
struct StaticFunction_5Parameters : public BoundFunction
{
  typedef T_Return (*FunctionType)(T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3, T_Parameter4);

  StaticFunction_5Parameters(FunctionType function, AnyStack const & default_arguments)
      throw()
    :    BoundFunction(Signature( Reflection::getTypeID<T_Return>(), 0, false, Reflection::getTypeID<T_Parameter0>(), Reflection::getTypeID<T_Parameter1>(), Reflection::getTypeID<T_Parameter2>(), Reflection::getTypeID<T_Parameter3>(), Reflection::getTypeID<T_Parameter4>() ), default_arguments)
      ,  function_(function)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 5);

    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(0);
    T_Parameter1 argument1 = arguments.extract<T_Parameter1>(1);
    T_Parameter2 argument2 = arguments.extract<T_Parameter2>(2);
    T_Parameter3 argument3 = arguments.extract<T_Parameter3>(3);
    T_Parameter4 argument4 = arguments.extract<T_Parameter4>(4);
    last_return_ = function_(argument0, argument1, argument2, argument3, argument4);
  }

  FunctionType function_;
};


template <typename T_Parameter0, typename T_Parameter1, typename T_Parameter2, typename T_Parameter3, typename T_Parameter4>
struct StaticFunction_5Parameters<void,T_Parameter0,T_Parameter1,T_Parameter2,T_Parameter3,T_Parameter4> : public BoundFunction
{
  typedef void (*FunctionType)(T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3, T_Parameter4);

  StaticFunction_5Parameters(FunctionType function, AnyStack const & default_arguments)
      throw()
    :    BoundFunction(Signature( Reflection::getTypeID<void>(), 0, false, Reflection::getTypeID<T_Parameter0>(), Reflection::getTypeID<T_Parameter1>(), Reflection::getTypeID<T_Parameter2>(), Reflection::getTypeID<T_Parameter3>(), Reflection::getTypeID<T_Parameter4>() ), default_arguments)
      ,  function_(function)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 5);

    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(0);
    T_Parameter1 argument1 = arguments.extract<T_Parameter1>(1);
    T_Parameter2 argument2 = arguments.extract<T_Parameter2>(2);
    T_Parameter3 argument3 = arguments.extract<T_Parameter3>(3);
    T_Parameter4 argument4 = arguments.extract<T_Parameter4>(4);
    function_(argument0, argument1, argument2, argument3, argument4);
    last_return_ = 0;
  }

  FunctionType function_;
};

#pragma warning ( pop )

#endif // ndef FUNCTION_STATICFUNCTIONTEMPLATES_HPP_INCLUDED_
