/******************************************************************************/
/*!
\file   BoundFunction.cpp
\author Chris Barrett
\brief
  BoundFunction implementation.

  Copyright (C) 2009 DigiPen Institute of Technology.
  Reproduction or disclosure of this file or its contents without the
  prior written consent of DigiPen Institute of Technology is prohibited.

*/
/******************************************************************************/

/*
#include "LeakCheck.h"
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
//*/

/*!\file
 *
 * \author Chris Barrett
 */

#include "BoundFunction.hpp"

namespace MFCore
{


// BoundFunction()
BoundFunction::BoundFunction(Signature const & signature, AnyStack const & default_arguments)
  :    signature_(signature)
    ,  default_arguments_(default_arguments)
{}


// getLastReturn()
Any const & BoundFunction::getLastReturn(void) const
  throw()
{
  return last_return_;
}


// getReturnType()
TypeID BoundFunction::getReturnType(void) const
{
  return signature_.return_type_id_;
}


// getSignature()
Signature const & BoundFunction::getSignature(void) const
{
  return signature_;
}


// getObjectPointer
void* BoundFunction::getObjectPointer( void ) const
{
  return NULL;
}


// toDelegate()
BoundFunction* BoundFunction::toDelegate(Any invoker)
{
  return NULL;
};


// mergeArgumentsWithDefaultArguments()
void BoundFunction::mergeArgumentsWithDefaultArguments
  (  AnyStack & arguments
  , AnyStack const & default_arguments
  , unsigned argument_count
  )
{
  // if the given arguments are sufficient to fill the function's parameters (meaning no defaults
  //  are needed), take no action
  if (arguments.size() >= argument_count)
    return;
  
  /*// old reverse-order default arguments
  unsigned arguments_needed = argument_count - arguments.size();
  unsigned default_argument_index = static_cast<unsigned>(default_arguments.size())
    - (static_cast<unsigned>(default_arguments_.size()) - arguments_needed) - 1;
  */
  
  // new 'normal-order' default arguments (right-aligned)
  unsigned arguments_needed = argument_count - arguments.size();
  unsigned default_argument_index = static_cast<unsigned>(default_arguments.size()) - arguments_needed;
  // left-bind default arguments
  if (default_arguments.size() > argument_count)
    default_argument_index -= static_cast<unsigned>(default_arguments.size()) - argument_count;
  
  while (arguments_needed > 0)
  {
    if (default_argument_index >= default_arguments.size())
      throw(std::logic_error( "Too few arguments given." ));
    
    arguments.push(default_arguments[ default_argument_index ]);
    
    --arguments_needed;
    ++default_argument_index;
  }
}

}
