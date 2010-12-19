/******************************************************************************/
/*!
\file   Delegate.hpp
\author Chris Barrett
\brief
  Delegate declaration.

  Copyright (C) 2009 DigiPen Institute of Technology.
  Reproduction or disclosure of this file or its contents without the
  prior written consent of DigiPen Institute of Technology is prohibited.

*/
/******************************************************************************/


#pragma once
#ifndef CONSTDELEGATE_HPP_INCLUDED_
#define CONSTDELEGATE_HPP_INCLUDED_

// disable warning about throw specifications being ignored
#ifdef _MSC_VER
#pragma warning(disable: 4290)
#endif // def _MSC_VER

// ConstDelegate_0Parameters
template <typename T_Return, typename T_ClassType>
struct ConstDelegate_0Parameters : public ConstMemberFunction_0Parameters<T_Return, T_ClassType>
{
  typedef T_Return (T_ClassType::*FunctionType)(void) const;
  
  ConstDelegate_0Parameters(FunctionType function, T_ClassType * object_pointer, AnyStack const & default_arguments=AnyStack())
    :  ConstMemberFunction_0Parameters<T_Return, T_ClassType>(function, default_arguments),
      object_pointer_(object_pointer)
  {}

  virtual void operator()(AnyStack & /*arguments*/)
  {
    last_return_ = (object_pointer_->*function_)();
  }

  virtual void* getObjectPointer(void) const
  {
    return object_pointer_;
  }
  
  private:
    T_ClassType * object_pointer_;
};


// ConstDelegate_0Parameters - void return type specialization
template <typename T_ClassType>
struct ConstDelegate_0Parameters<void, T_ClassType> : public ConstMemberFunction_0Parameters<void, T_ClassType>
{
  typedef void (T_ClassType::*FunctionType)(void) const;
  
  ConstDelegate_0Parameters(FunctionType function, T_ClassType * object_pointer, AnyStack const & default_arguments=AnyStack())
    :  ConstMemberFunction_0Parameters<void, T_ClassType>(function, default_arguments),
      object_pointer_(object_pointer)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    (object_pointer_->*function_)();
    last_return_ = 0;
  }

  virtual void* getObjectPointer(void) const
  {
    return object_pointer_;
  }
  
  private:
    T_ClassType * object_pointer_;
};


// ConstDelegate_1Parameters
template <typename T_Return, typename T_ClassType, typename T_Parameter0>
struct ConstDelegate_1Parameters : public ConstMemberFunction_1Parameters<T_Return, T_ClassType, T_Parameter0>
{
  typedef T_Return (T_ClassType::*FunctionType)(T_Parameter0) const;
  
  ConstDelegate_1Parameters(FunctionType function, T_ClassType * object_pointer, AnyStack const & default_arguments=AnyStack())
    :  ConstMemberFunction_1Parameters<T_Return, T_ClassType, T_Parameter0>(function, default_arguments),
      object_pointer_(object_pointer)
  {
    if (object_pointer)
    {}
  }

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 1);

    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(0);
    last_return_ = (object_pointer_->*function_)(argument0);
  }

  virtual void* getObjectPointer(void) const
  {
    return object_pointer_;
  }
  
  private:
    T_ClassType * object_pointer_;
};


// ConstDelegate_1Parameters - void return type specialization
template <typename T_ClassType, typename T_Parameter0>
struct ConstDelegate_1Parameters<void, T_ClassType, T_Parameter0> : public ConstMemberFunction_1Parameters<void, T_ClassType, T_Parameter0>
{
  typedef void (T_ClassType::*FunctionType)(T_Parameter0) const;

  ConstDelegate_1Parameters(FunctionType function, T_ClassType * object_pointer, AnyStack const & default_arguments=AnyStack())
    :  ConstMemberFunction_1Parameters<void, T_ClassType, T_Parameter0>(function, default_arguments),
      object_pointer_(object_pointer)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 1);

    if (object_pointer_ == 0 || this == 0)
    {
			/// TODO: Use error reporting here - attempt to invoke on null object
      //DebugBreak();
      object_pointer_ = object_pointer_;
    }

    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(0);
    (object_pointer_->*function_)(argument0);
    last_return_ = 0;
  }

  virtual void* getObjectPointer(void) const
  {
    return object_pointer_;
  }

  private:
    T_ClassType * object_pointer_;
};


// ConstDelegate_2Parameters
template <typename T_Return, typename T_ClassType, typename T_Parameter0, typename T_Parameter1>
struct ConstDelegate_2Parameters : public ConstMemberFunction_2Parameters<T_Return, T_ClassType, T_Parameter0, T_Parameter1>
{
  typedef T_Return (T_ClassType::*FunctionType)(T_Parameter0, T_Parameter1) const;
  
  ConstDelegate_2Parameters(FunctionType function, T_ClassType * object_pointer, AnyStack const & default_arguments=AnyStack())
    :  ConstMemberFunction_2Parameters<T_Return, T_ClassType, T_Parameter0, T_Parameter1>(function, default_arguments),
      object_pointer_(object_pointer)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 2);

    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(0);
    T_Parameter1 argument1 = arguments.extract<T_Parameter1>(1);
    last_return_ = (object_pointer_->*function_)(argument0, argument1);
  }

  virtual void* getObjectPointer(void) const
  {
    return object_pointer_;
  }
  
  private:
    T_ClassType * object_pointer_;
};


// ConstDelegate_2Parameters - void return type specialization
template <typename T_ClassType, typename T_Parameter0, typename T_Parameter1>
struct ConstDelegate_2Parameters<void, T_ClassType, T_Parameter0, T_Parameter1> : public ConstMemberFunction_2Parameters<void, T_ClassType, T_Parameter0, T_Parameter1>
{
  typedef void (T_ClassType::*FunctionType)(T_Parameter0, T_Parameter1) const;
  
  ConstDelegate_2Parameters(FunctionType function, T_ClassType * object_pointer, AnyStack const & default_arguments=AnyStack())
    :  ConstMemberFunction_2Parameters<void, T_ClassType, T_Parameter0, T_Parameter1>(function, default_arguments),
      object_pointer_(object_pointer)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 2);

    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(0);
    T_Parameter1 argument1 = arguments.extract<T_Parameter1>(1);
    (object_pointer_->*function_)(argument0, argument1);
    last_return_ = 0;
  }

  virtual void* getObjectPointer(void) const
  {
    return object_pointer_;
  }
  
  private:
    T_ClassType * object_pointer_;
};


// ConstDelegate_3Parameters
template <typename T_Return, typename T_ClassType, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2>
struct ConstDelegate_3Parameters : public ConstMemberFunction_3Parameters<T_Return, T_ClassType, T_Parameter0, T_Parameter1, T_Parameter2>
{
  typedef T_Return (T_ClassType::*FunctionType)(T_Parameter0, T_Parameter1, T_Parameter2) const;
  
  ConstDelegate_3Parameters(FunctionType function, T_ClassType * object_pointer, AnyStack const & default_arguments=AnyStack())
    :  ConstMemberFunction_3Parameters<T_Return, T_ClassType, T_Parameter0, T_Parameter1, T_Parameter2>(function, default_arguments),
      object_pointer_(object_pointer)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 3);

    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(0);
    T_Parameter1 argument1 = arguments.extract<T_Parameter1>(1);
    T_Parameter2 argument2 = arguments.extract<T_Parameter2>(2);
    last_return_ = (object_pointer_->*function_)(argument0, argument1, argument2);
  }

  virtual void* getObjectPointer(void) const
  {
    return object_pointer_;
  }
  
  private:
    T_ClassType * object_pointer_;
};


// ConstDelegate_3Parameters - void return type specialization
template <typename T_ClassType, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2>
struct ConstDelegate_3Parameters<void, T_ClassType, T_Parameter0, T_Parameter1, T_Parameter2> : public ConstMemberFunction_3Parameters<void, T_ClassType, T_Parameter0, T_Parameter1, T_Parameter2>
{
  typedef void (T_ClassType::*FunctionType)(T_Parameter0, T_Parameter1, T_Parameter2) const;
  
  ConstDelegate_3Parameters(FunctionType function, T_ClassType * object_pointer, AnyStack const & default_arguments=AnyStack())
    :  ConstMemberFunction_3Parameters<void, T_ClassType, T_Parameter0, T_Parameter1, T_Parameter2>(function, default_arguments),
      object_pointer_(object_pointer)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 3);

    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(0);
    T_Parameter1 argument1 = arguments.extract<T_Parameter1>(1);
    T_Parameter2 argument2 = arguments.extract<T_Parameter2>(2);
    (object_pointer_->*function_)(argument0, argument1, argument2);
    last_return_ = 0;
  }

  virtual void* getObjectPointer(void) const
  {
    return object_pointer_;
  }
  
  private:
    T_ClassType * object_pointer_;
};


// ConstDelegate_4Parameters
template <typename T_Return, typename T_ClassType, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2, typename T_Parameter3>
struct ConstDelegate_4Parameters : public ConstMemberFunction_4Parameters<T_Return, T_ClassType, T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3>
{
  typedef T_Return (T_ClassType::*FunctionType)(T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3) const;
  
  ConstDelegate_4Parameters(FunctionType function, T_ClassType * object_pointer, AnyStack const & default_arguments=AnyStack())
    :  ConstMemberFunction_4Parameters<T_Return, T_ClassType, T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3>(function, default_arguments),
      object_pointer_(object_pointer)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 4);

    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(0);
    T_Parameter1 argument1 = arguments.extract<T_Parameter1>(1);
    T_Parameter2 argument2 = arguments.extract<T_Parameter2>(2);
    T_Parameter3 argument3 = arguments.extract<T_Parameter3>(3);
    last_return_ = (object_pointer_->*function_)(argument0, argument1, argument2, argument3);
  }

  virtual void* getObjectPointer(void) const
  {
    return object_pointer_;
  }
  
  private:
    T_ClassType * object_pointer_;
};


// ConstDelegate_4Parameters - void return type specialization
template <typename T_ClassType, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2, typename T_Parameter3>
struct ConstDelegate_4Parameters<void, T_ClassType, T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3> : public ConstMemberFunction_4Parameters<void, T_ClassType, T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3>
{
  typedef void (T_ClassType::*FunctionType)(T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3) const;
  
  ConstDelegate_4Parameters(FunctionType function, T_ClassType * object_pointer, AnyStack const & default_arguments=AnyStack())
    :  ConstMemberFunction_4Parameters<void, T_ClassType, T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3>(function, default_arguments),
      object_pointer_(object_pointer)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 4);

    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(0);
    T_Parameter1 argument1 = arguments.extract<T_Parameter1>(1);
    T_Parameter2 argument2 = arguments.extract<T_Parameter2>(2);
    T_Parameter3 argument3 = arguments.extract<T_Parameter3>(3);
    (object_pointer_->*function_)(argument0, argument1, argument2, argument3);
    last_return_ = 0;
  }

  virtual void* getObjectPointer(void) const
  {
    return object_pointer_;
  }
  
  private:
    T_ClassType * object_pointer_;
};


// ConstDelegate_5Parameters
template <typename T_Return, typename T_ClassType, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2, typename T_Parameter3, typename T_Parameter4>
struct ConstDelegate_5Parameters : public ConstMemberFunction_5Parameters<T_Return, T_ClassType, T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3, T_Parameter4>
{
  typedef T_Return (T_ClassType::*FunctionType)(T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3, T_Parameter4) const;
  
  ConstDelegate_5Parameters(FunctionType function, T_ClassType * object_pointer, AnyStack const & default_arguments=AnyStack())
    :  ConstMemberFunction_5Parameters<T_Return, T_ClassType, T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3, T_Parameter4>(function, default_arguments),
      object_pointer_(object_pointer)
  {}

  virtual void operator()(AnyStack & arguments)
  {
    // make use of default arguments, if needed
    mergeArgumentsWithDefaultArguments(arguments, default_arguments_, 5);

    T_Parameter0 argument0 = arguments.extract<T_Parameter0>(0);
    T_Parameter1 argument1 = arguments.extract<T_Parameter1>(1);
    T_Parameter2 argument2 = arguments.extract<T_Parameter2>(2);
    T_Parameter3 argument3 = arguments.extract<T_Parameter3>(3);
    T_Parameter3 argument4 = arguments.extract<T_Parameter4>(4);
    last_return_ = (object_pointer_->*function_)(argument0, argument1, argument2, argument3, argument4);
  }

  virtual void* getObjectPointer(void) const
  {
    return object_pointer_;
  }
  
  private:
    T_ClassType * object_pointer_;
};


// ConstDelegate_5Parameters - void return type specialization
template <typename T_ClassType, typename T_Parameter0, typename T_Parameter1, typename T_Parameter2, typename T_Parameter3, typename T_Parameter4>
struct ConstDelegate_5Parameters<void, T_ClassType, T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3, T_Parameter4> : public ConstMemberFunction_5Parameters<void, T_ClassType, T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3, T_Parameter4>
{
  typedef void (T_ClassType::*FunctionType)(T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3, T_Parameter4) const;
  
  ConstDelegate_5Parameters(FunctionType function, T_ClassType * object_pointer, AnyStack const & default_arguments=AnyStack())
    :  ConstMemberFunction_5Parameters<void, T_ClassType, T_Parameter0, T_Parameter1, T_Parameter2, T_Parameter3, T_Parameter4>(function, default_arguments),
      object_pointer_(object_pointer)
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
    (object_pointer_->*function_)(argument0, argument1, argument2, argument3, argument4);
    last_return_ = 0;
  }

  virtual void* getObjectPointer(void) const
  {
    return object_pointer_;
  }
  
  private:
    T_ClassType * object_pointer_;
};

#endif // ndef CONSTDELEGATE_HPP_INCLUDED_