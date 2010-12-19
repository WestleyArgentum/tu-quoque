/******************************************************************************/
/*!
\file   BoundFunction.hpp
\author Chris Barrett
\brief
  BoundFunction declaration.

  Copyright (C) 2009 DigiPen Institute of Technology.
  Reproduction or disclosure of this file or its contents without the
  prior written consent of DigiPen Institute of Technology is prohibited.

*/
/******************************************************************************/


#pragma once
#ifndef FUNCTION_HPP_INCLUDED_
#define FUNCTION_HPP_INCLUDED_

//#include "MFCoreConfig.hpp"
// Any type
#include "Any.hpp"
// AnyStack type
#include "AnyStack.hpp"
#include "TypeID.hpp"
#include "Signature.hpp"
// debugWarn
//#include "Debug.hpp"

/// TODO: Fix this later.
#pragma warning (push)
#pragma warning (disable: 4239) // nonstandard extension used : 'default argument' : conversion from 'AnyStack' to 'AnyStack &'

namespace MFCore
{

/*!\brief Abstract class to 'collapse' any function into one object with the same 'signature'.  That
 *  function now just takes a single AnyStack parameter.  'Unwinding' of this stack to actually call
 *  the function is handled automatically.
 *
 * \detail
 *  This is strongly based on an example Chris Peters showed two other students (Robert Onulak and
 *  Kyle Holdwick) and myself at the DigiPen Institute of Technology.  This occurred on October 9th,
 *  2009; during our Sophomore year.
 *
 * \TODO
 *  Check \a size() of \a arguments before attempting to extract.  Calling a function with however
 *  many parameters are available will re-enable C++'s built-in default argument values.
 */
struct BoundFunction
{
  //////////////////////////////////////////////////////////////////////////////////////////////////
  //[ BoundFunction - constructors (begin)
  /////////////////////////////////////////////////
  
  BoundFunction(Signature const & signature, AnyStack const & default_arguments=AnyStack());
  
  /*!\brief Virtual destructor, since inheriting classes will be of differing sizes.
   */
  virtual ~BoundFunction()
    throw()
  {}
  
  /////////////////////////////////////////////////
  //] BoundFunction - constructors (end)
  //////////////////////////////////////////////////////////////////////////////////////////////////
  //[ BoundFunction - methods (begin)
  /////////////////////////////////////////////////
  
  /*!\brief Invokes this Function, using the given arguments.
   *
   * \param arguments
   *  The arguments to pass to the function being invoked.
   *
   * \return
   *  Has no return.  To acquire the returned value from the invoked function, pop the only
   *  remaining item off the passed AnyStack.  This only being possible if one passes in an
   *  AnyStack with a sufficient lifespan (meaning not one constructed in the call to
   *  Function::operator() ).  \b Alternately, use Function::getLastReturn to get an Any containing
   *  the returned value.
   *
   * \see
   *  Function::getLastReturn
   */
  /// TODO: Fix this later
  virtual void operator()(AnyStack & arguments = AnyStack()) =0;
  //{
    //DebugWarn("Invocation of undefined Function.");
  //}
  
  /*!\brief Invokes this Function, using the given arguments.  This is just a wrapper around
   *  operator() for readability.
   *
   * \see
   *  Function::operator()
   */
  /// TODO: Fix this later
  void invoke(AnyStack & arguments = AnyStack())
  {
    operator()(arguments);
  }
  
  /*void invoke(Any arg0)
  {
    AnyStack arguments;
    arguments.push(arg0);
    
    operator()( arguments );
  }*/
  
  /*// interesting idea...  Since Any has a templated implicit conversion constructor, the client
  //   would never have to know about the AnyStack at all
  void operator()(Any param0)
  { operator()(AnyStack(param0)); }
  void operator()(Any param0, Any param1)
  { operator()(AnyStack(param0, param1)); }
  */
  
  /*!\brief Returns a copy of the Any which contains the return, if any, from the last time this
   *  Function was invoked.
   *
   * \return
   *  Copy of the returned data from the last time this Function was invoked.
   */
  virtual Any const & getLastReturn(void) const
  throw();
  
  TypeID getReturnType(void) const;
  
  Signature const & getSignature(void) const;

  virtual void* getObjectPointer(void) const;
  
  virtual BoundFunction* toDelegate(Any invoker);
  
  
  protected:
    
    /*!\brief Merges default arguments into an argument list.
     *
     *  The default arguments are right-aligned.  So if a function takes (int i, float f, string s),
     *  a default argument list for its last two parameters would be of the form (float f, string s).
     *  
     *  This list is also left-bound.  So if too many default arguments are given, the right-most
     *  ones are ignored.  This enables behavior such as the default argument list of (int i, float f)
     *  to be used in invoking both methods with a parameter list of (int i, float f) and just (int i).
     *
     * \post
     *  The given argument list will contain new data to match the default arguments.
     *
     * \param[in,out] arguments
     *  The given arguments when calling a function.
     *
     * \param[in] default_arguments
     *  The function's "default arguments".  This list is "right-aligned" with the functions
     *  actual parameters.  
     *
     * \param[in] argument_count
     *  The total number of parameters the function requires.
     */
    void mergeArgumentsWithDefaultArguments(AnyStack & arguments, AnyStack const & default_arguments, unsigned argument_count);
  
  /////////////////////////////////////////////////
  //] BoundFunction - methods (end)
  //////////////////////////////////////////////////////////////////////////////////////////////////
  //[ BoundFunction - data (begin)
  /////////////////////////////////////////////////
  
  public:
    
    AnyStack default_arguments_;
  
  
  protected:
    
    /*!\brief Contains the returned data from the last time this Function was invoked.
     */
    Any last_return_;
    
    Signature signature_;
  
  /////////////////////////////////////////////////
  //] BoundFunction - data (end)
  //////////////////////////////////////////////////////////////////////////////////////////////////
};


#include "Function_BindFunctionTemplates.hpp"
#include "Delegate_BindFunctionTemplates.hpp"

}
using namespace MFCore;

#pragma warning (pop)

#endif // ndef FUNCTION_HPP_INCLUDED_
