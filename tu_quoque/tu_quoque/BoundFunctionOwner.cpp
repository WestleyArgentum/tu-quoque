#include "BoundFunctionOwner.hpp"

#include <cassert>



namespace MFCore
{

////////////////////////////////////////////////////////////////////////////////////////////////////
//[ BoundFunctionOwner - constructors (begin)
//////////////////////////////////////////////////


// BoundFunctionOwner()
BoundFunctionOwner::BoundFunctionOwner (void)
    :
       bound_function_ (0)
      ,reference_count_ (0)
{}



// BoundFunctionOwner()
BoundFunctionOwner::BoundFunctionOwner (BoundFunction * bound_function)
{
  bound_function_ = bound_function;
  reference_count_ = new unsigned(1);
}


// BoundFunctionOwner()
BoundFunctionOwner::BoundFunctionOwner( const BoundFunctionOwner &rhs )
  : bound_function_(rhs.bound_function_), reference_count_(rhs.reference_count_)
{
    if ( reference_count_ )
    {
        ++(*reference_count_);
    }
}


// BoundFunctionOwner()
//BoundFunctionOwner::BoundFunctionOwner (Signature const & signature, AnyStack const & default_arguments /* =AnyStack */)
/*
{
  bound_function_ = new BoundFunction (signature, default_arguments);
  reference_count_ = new unsigned(1);
}
//*/




// ~BoundFunctionOwner()
BoundFunctionOwner::~BoundFunctionOwner (void)
{
  releaseFunction();
}


//////////////////////////////////////////////////
//] BoundFunctionOwner - constructors (end)
////////////////////////////////////////////////////////////////////////////////////////////////////
//[ BoundFunctionOwner - methods (begin)
//////////////////////////////////////////////////


// operator=()
void BoundFunctionOwner::operator= (BoundFunctionOwner bound_function_owner)
{
  releaseFunction();
  
  reference_count_ = bound_function_owner.reference_count_;
  if (reference_count_)
    ++(*reference_count_);
  
  bound_function_ = bound_function_owner.bound_function_;
}



// operator=()
void BoundFunctionOwner::operator= (BoundFunction * bound_function)
{
  releaseFunction();
  
  bound_function_ = bound_function;
  reference_count_ = new unsigned(1);
}



// operator==()
bool BoundFunctionOwner::operator== (BoundFunctionOwner const & rhs)
{
  return (bound_function_ == rhs.bound_function_);
}




// operator!=()
bool BoundFunctionOwner::operator!= (BoundFunctionOwner const & rhs)
{
  return (bound_function_ != rhs.bound_function_);
}


// operator!()
bool BoundFunctionOwner::operator!( void )
{
  return !bound_function_;
}


// operator()()
void BoundFunctionOwner::operator()(AnyStack & arguments /*= AnyStack()*/)
{
  assert (bound_function_);
  
  bound_function_->operator() (arguments);
}



// getLastReturn()
Any const & BoundFunctionOwner::getLastReturn(void) const
{
  assert (bound_function_);
  
  return bound_function_->getLastReturn();
}




// getReturnType()
TypeID BoundFunctionOwner::getReturnType(void) const
{
  assert (bound_function_);
  
  return bound_function_->getReturnType();
}



// getSignature()
Signature const & BoundFunctionOwner::getSignature(void) const
{
  assert (bound_function_);
  
  return bound_function_->getSignature();
}




// toDelegate()
BoundFunctionOwner BoundFunctionOwner::toDelegate(Any invoker)
{
  assert (bound_function_);
  
  return BoundFunctionOwner (bound_function_->toDelegate (invoker));
}




// releaseFunction()
void BoundFunctionOwner::releaseFunction (void)
{
  if (reference_count_)
  {
    // decrement the reference count.  If it drops to zero, we're the last user of our data
    if (--(*reference_count_) == 0)
    {
      delete reference_count_;
      delete bound_function_;
    }
  }
  
  reference_count_ = 0;
  bound_function_ = 0;
}


//////////////////////////////////////////////////
//] BoundFunctionOwner - methods (end)
////////////////////////////////////////////////////////////////////////////////////////////////////


} // namespace MFCore
