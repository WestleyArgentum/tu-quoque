/******************************************************************************/
/*!
\file   AnyStack.hpp
\author Chris Barrett
\brief
  AnyStack declaration.

  Copyright (C) 2009 DigiPen Institute of Technology.
  Reproduction or disclosure of this file or its contents without the
  prior written consent of DigiPen Institute of Technology is prohibited.

*/
/******************************************************************************/


#pragma once
#ifndef ANYSTACK_HPP_INCLUDED_
#define ANYSTACK_HPP_INCLUDED_

// disable warning about throw specifications being ignored
#ifdef _MSC_VER
#pragma warning(disable: 4290)
#endif // def _MSC_VER

#include "Any.hpp"
#include "TypeID.hpp"

#include <vector>

/*!\brief A container of Any data.
 */
class AnyStack
{
  //////////////////////////////////////////////////////////////////////////////////////////////////
  //[ AnyStack - constructors (begin)
  /////////////////////////////////////////////////
  
  
  public:
    
    AnyStack(void)
      :  stack_()
    {}
    
    
    template <typename T_Element0>
    AnyStack(const T_Element0 & element0)
      :  stack_()
    {
      stack_.reserve(1);
      stack_.push_back( Any(element0) );
    }
    
    
    template <typename T_Element0, typename T_Element1>
    AnyStack(const T_Element0 & element0, const T_Element1 & element1)
      :  stack_()
    {
      stack_.reserve(2);
      stack_.push_back( Any(element0) );
      stack_.push_back( Any(element1) );
    }
    
    
    template <typename T_Element0, typename T_Element1, typename T_Element2>
    AnyStack(const T_Element0 & element0, const T_Element1 & element1, const T_Element2 & element2)
      :  stack_()
    {
      stack_.reserve(3);
      stack_.push_back( Any(element0) );
      stack_.push_back( Any(element1) );
      stack_.push_back( Any(element2) );
    }
    
    
    template <typename T_Element0, typename T_Element1, typename T_Element2, typename T_Element3>
    AnyStack(const T_Element0 & element0, const T_Element1 & element1, const T_Element2 & element2, const T_Element3 & element3)
      :  stack_()
    {
      stack_.reserve(4);
      stack_.push_back( Any(element0) );
      stack_.push_back( Any(element1) );
      stack_.push_back( Any(element2) );
      stack_.push_back( Any(element3) );
    }
    
    
    template <typename T_Element0, typename T_Element1, typename T_Element2, typename T_Element3, typename T_Element4>
    AnyStack(const T_Element0 & element0, const T_Element1 & element1, const T_Element2 & element2, const T_Element3 & element3, const T_Element4 & element4)
      :  stack_()
    {
      stack_.reserve(5);
      stack_.push_back( Any(element0) );
      stack_.push_back( Any(element1) );
      stack_.push_back( Any(element2) );
      stack_.push_back( Any(element3) );
      stack_.push_back( Any(element4) );
    }
    
    
    template <typename T_Element0, typename T_Element1, typename T_Element2, typename T_Element3, typename T_Element4, typename T_Element5>
    AnyStack(const T_Element0 & element0, const T_Element1 & element1, const T_Element2 & element2, const T_Element3 & element3, const T_Element4 & element4, const T_Element5 & element5)
      :  stack_()
    {
      stack_.reserve(6);
      stack_.push_back( Any(element0) );
      stack_.push_back( Any(element1) );
      stack_.push_back( Any(element2) );
      stack_.push_back( Any(element3) );
      stack_.push_back( Any(element4) );
      stack_.push_back( Any(element5) );
    }
  
  
  /////////////////////////////////////////////////
  //] AnyStack - constructors (end)
  //////////////////////////////////////////////////////////////////////////////////////////////////
  //[ AnyStack - methods (begin)
  /////////////////////////////////////////////////
  
  
  public:
    
    template <typename T_Data>
    void push(T_Data const & data)
    {
      stack_.push_back( data );
    }
    
    
    template <typename T_Data>
    T_Data back(void)
    {
      return stack_.back();
    }
    
    
    void pop(void)
    {
      stack_.erase( stack_.end() );
    }
    
    
    Any & operator[](unsigned index)
    {
      return stack_[index];
    }
    
    
    Any const & operator[](unsigned index) const
    {
      return stack_[index];
    }
    
    
    template <typename T_Data>
    T_Data extract(std::vector<Any>::size_type index)
    {
      #ifdef _DEBUG
      return stack_.at(index).extract<T_Data>();
      #else
      return stack_[index].extract<T_Data>();
      #endif
    }
    
    
    std::vector<Any>::size_type size(void) const
      throw()
    {
      return stack_.size();
    }
  
  
  /////////////////////////////////////////////////
  //] AnyStack - methods (end)
  //////////////////////////////////////////////////////////////////////////////////////////////////
  //[ AnyStack - data (begin)
  /////////////////////////////////////////////////
  
  
  private:
    
    std::vector< Any > stack_;
  
  
  /////////////////////////////////////////////////
  //] AnyStack - data (end)
  //////////////////////////////////////////////////////////////////////////////////////////////////
};

#endif // ndef ANYSTACK_HPP_INCLUDED_
