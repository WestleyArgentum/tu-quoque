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

#include "BoundFunction.hpp"
#include "Signature.hpp"
#include "AnyStack.hpp"

/// TODO: Fix later
#pragma warning (push)
#pragma warning (disable: 4239) // nonstandard extension used : 'default argument' : conversion from 'AnyStack' to 'AnyStack &'

namespace MFCore
{


/*!\brief Taking responsibility for BoundFunction allocations.
 */
class BoundFunctionOwner
{
  //////////////////////////////////////////////////////////////////////////////////////////////////
  //[ BoundFunctionOwner - data/types (begin)
  /////////////////////////////////////////////////
  
  private:
    
    BoundFunction * bound_function_;
    
    unsigned * reference_count_;
  
  /////////////////////////////////////////////////
  //[ BoundFunctionOwner - data/types (end)
  //////////////////////////////////////////////////////////////////////////////////////////////////
  //[ BoundFunctionOwner - constructors (begin)
  /////////////////////////////////////////////////
  
  public:
    
    BoundFunctionOwner (void);
    
    BoundFunctionOwner (BoundFunction * bound_function);

    BoundFunctionOwner( const BoundFunctionOwner &rhs );
    
    //BoundFunctionOwner (Signature const & signature, AnyStack const & default_arguments=AnyStack());
    
    ~BoundFunctionOwner (void);
  
  /////////////////////////////////////////////////
  //[ BoundFunctionOwner - constructors (end)
  //////////////////////////////////////////////////////////////////////////////////////////////////
  //[ BoundFunctionOwner - methods (begin)
  /////////////////////////////////////////////////
  
  public:
    
    void operator= (BoundFunctionOwner bound_function_owner);
    
    void operator= (BoundFunction * bound_function);
    
    bool operator== (BoundFunctionOwner const & rhs);
    
    bool operator!= (BoundFunctionOwner const & rhs);

    bool operator!( void );

    BoundFunction* operator->( void ) { return bound_function_; }

    void operator()(AnyStack & arguments = AnyStack());
    
    void invoke(AnyStack & arguments = AnyStack())
    { operator()(arguments); }
    
    Any const & getLastReturn(void) const;
    
    TypeID getReturnType(void) const;
    
    Signature const & getSignature(void) const;
    
    BoundFunctionOwner toDelegate(Any invoker);
  
  private:
    
    //void acquireFunction (
    
    void releaseFunction (void);
  
  /////////////////////////////////////////////////
  //] BoundFunctionOwner - methods (end)
  //////////////////////////////////////////////////////////////////////////////////////////////////
};

} // namespace MFCore

#pragma warning (pop)
