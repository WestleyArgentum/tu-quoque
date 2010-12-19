/******************************************************************************/
/*!
\file   Any.hpp
\author Chris Barrett
\brief
  Any declaration (generic storage class).

  Copyright (C) 2009 DigiPen Institute of Technology.
  Reproduction or disclosure of this file or its contents without the
  prior written consent of DigiPen Institute of Technology is prohibited.

*/
/******************************************************************************/

#pragma once
#ifndef ANY_HPP_INCLUDED_
#define ANY_HPP_INCLUDED_

// disable warning about throw specifications being ignored
#ifdef _MSC_VER
#pragma warning(disable: 4290)
#endif // def _MSC_VER


#include "TypeID.hpp"
using namespace Reflection;  // Wes here: This is a hack to get access to the TypeID typedef

#include "BasicTypes.hpp"  // Wes here: This is to get access to the MFCore basic types

// std::swap()
#include <algorithm>
// std::type_info type
// typeid()
#include <typeinfo>
// std::logic_error type
#include <stdexcept>

namespace MFCore
{


/*!\brief Essentially a copy of boost::any.  The Any is able to represent any data of any type,
 *  without dealing with templates or losing type safety.
 *
 *
 * \detail
 *  The internals of the Any use templates.  This class lets the client not have to deal with them.
 *  \par
 *  I wanted to at least make myself type all the characters and really read and understand how it
 *  works, rather than just take in the whole boost library and use it as a black box.<br/>
 *  Resources used:<br/>
 *  boost::any header: http://www.boost.org/doc/libs/1_40_0/boost/any.hpp <br/>
 *  "Learning C++: boost::any" blog entry by Abhishek Padmanabh:
 *  http://learningcppisfun.blogspot.com/2007/09/boostany.html <br/>
 */
class Any
{
  //////////////////////////////////////////////////////////////////////////////////////////////////
  //[ Any - types (begin)
  /////////////////////////////////////////////////
  
  
  private:
    
    struct AnyDataHolder
    {
      AnyDataHolder(TypeID type_id=0)
        :    type_id_(type_id)
      {}
      
      virtual ~AnyDataHolder(void)
      {}
      
      virtual AnyDataHolder * clone(void) const
        throw(std::bad_alloc)
        =0;
      
      virtual std::type_info const & type(void) =0;
      
      TypeID type_id_;
    };
    
    
    template <typename T_Data>
    class AnyDataHolderSpecialization : public AnyDataHolder
    {
      public:
        
        AnyDataHolderSpecialization(T_Data data)
        //AnyDataHolderSpecialization(const T_Data  data)
        //AnyDataHolderSpecialization(const T_Data & data)
          :    AnyDataHolder(Reflection::getTypeID<T_Data>())
            ,  data_(data)
        {
          //type_id_ = ;
        }
        
        ~AnyDataHolderSpecialization(void)
        {
          //int i = 0;
        }
        
        virtual AnyDataHolderSpecialization<T_Data> * clone(void) const
          throw(std::bad_alloc)
        {
          return new AnyDataHolderSpecialization<T_Data>(data_);
        }
        
        virtual std::type_info const & type(void)
        {
          return typeid(T_Data);
        }
      
      private:
        
        AnyDataHolderSpecialization(const AnyDataHolderSpecialization & other);
        AnyDataHolderSpecialization & operator=(const AnyDataHolderSpecialization & rhs);
        
        T_Data data_;
      
      friend class Any;
    };
    
    
    /*template <void>
    class AnyDataHolderSpecialization : public AnyDataHolder
    {
      public:
        
        AnyDataHolderSpecialization(void)
          :  data_(0)
        {}
        
        virtual AnyDataHolderSpecialization<void> * clone(void) const
          throw(std::bad_alloc)
        {
          return new AnyDataHolderSpecialization<void>(data_);
        }
        
        virtual std::type_info const & type(void)
        {
          return typeid(void);
        }
      
      private:
        
        AnyDataHolderSpecialization(const AnyDataHolderSpecialization & other);
        AnyDataHolderSpecialization & operator=(const AnyDataHolderSpecialization & rhs);
    };*/
  
  
  /////////////////////////////////////////////////
  //] Any - types (end)
  ////////////////////////////////////////////////////////////////////////////////////////////////// 
  //[ Any - constructors (begin)
  /////////////////////////////////////////////////
  
  
  public:
    
    /*!\brief Default constructor creates an empty Any.
     */
    Any()
      throw()
      :  data_(NULL)
    {}
    
    
    /*!\brief Implicit conversion constructor can create an Any from anything.
     *
     * \param data
     *  Data to be copied into the Any.
     *
     * \throws std::bad_alloc
     *  If the dynamic allocation of memory for the Any's underlying data holder class fails.
     */
    template <typename T_Data>
    Any(const T_Data & data)
      throw(std::bad_alloc)
      :  data_(new AnyDataHolderSpecialization<T_Data>(data))
    {}
    
    
    /*!\brief Copy constructor.
     *
     * \param other
     *  Another Any instance to copy.
     *
     * \throws std::bad_alloc
     *  The 'virtual constructor' of one of Any's underlying classes may throw a std::bad_alloc if
     *  memory allocation from new fails.
     */
    Any(const Any & other)
      throw(std::bad_alloc)
      //: data_(other.data_ ? other.data_->clone() : 0)
      :  data_(0)
    {
      //delete data_;
      
      if (other.data_ != NULL)
        data_ = other.data_->clone();
    }
    
    
    /*!\brief Deletes the data being held by this Any.
     */
    ~Any()
      throw()
    {
      delete data_;
    }
  
  
  /////////////////////////////////////////////////
  //] Any - constructors (end)
  //////////////////////////////////////////////////////////////////////////////////////////////////
  //[ Any - methods (begin)
  /////////////////////////////////////////////////
  
  
  public:
    
    /*!\brief Returns true if this Any has no data.  This situation is similar to a null pointer.
     *
     * \return
     *  true if this Any has no data.  false otherwise.
     */
    bool isEmpty() const
      throw()
    {
      return data_ == NULL;
    }
    
    
    /*!\brief Returns the enumerated TypeID of the data being held by this Any.
     *
     * \see
     *      typeToTypeID
     *  <br>typeIDToType
     */
    TypeID getTypeID(void) const
    {
      return data_->type_id_;
    }
    
    
    /*!\brief Returns a copy of the data contained within.  Type-safety checking takes place
     *  to ensure the attempt to convert data is safe.
     */
    template <typename T_Data>
    T_Data extract(void) const
    {
      if (data_ == NULL)
        throw(std::logic_error("Attempt to extract from an empty Any!"));
      
      if (data_->type() != typeid(T_Data))
        throw(std::logic_error("Bad attempt to extract data from an Any.  Wrong data type!"));
      
      return static_cast< Any::AnyDataHolderSpecialization< T_Data > * >(data_)->data_;
    }
    
    
    /*!\brief Swaps the contents of this Any with the passed Any.
     *
     * \detail
     *  Exception-safe due to use of std::swap.
     *
     * \post
     *  This Any will contain the passed Any's data, and the passed Any will contain this Any's
     *  original data.
     *
     * \param rhs
     *  Another Any to swap data with.
     *
     * \return
     *  Reference to this Any.
     */
    Any & swap(Any & rhs)
      throw()
    {
      std::swap(data_, rhs.data_);
      
      return *this;
    }
    
    
    /*!\brief Templated operator= overload to allow an Any to be set to hold any kind of data.
     *
     * \post
     *  This Any will contain the passed data, and the old data will be deleted.
     *
     * \param rhs
     *  The data to be copied.
     *
     * \return
     *  Reference to this Any.
     */
    template <typename T_Data>
    Any & operator=(const T_Data & rhs)
      throw()
    {
      Any(rhs).swap(*this);
      
      return *this;
    }
    
    
    /*!\brief Sets the data of this Any to be a copy of the data contained within the passed Any.
     *
     * \param rhs
     *  The other Any to copy data from.
     *
     * \return
     *  Reference to this Any.
     */
    Any & operator=(Any rhs)
      throw()
    {
      // since the passed Any is a copy, rather than the usual constant reference, doing this
      //   swaps the data from a temporary, stack-allocated Any with the data in this Any.  This also
      //   means the destructor on the temporary Any will handle the deletion of the old data from
      //   this Any.  Clever boost.
      rhs.swap(*this);
      
      return *this;
    }
  
  
  /////////////////////////////////////////////////
  //] Any - methods (end)
  //////////////////////////////////////////////////////////////////////////////////////////////////
  //[ Any - data (begin)
  /////////////////////////////////////////////////
  
  
  private:
    
    /*!\brief Pointer to an abstract base class used to hold Any data.  Its only subclass (though
     *  really it has an indefinite number of subclasses), is the AnyDataHolderSpecialized, which
     *  is templated to handle any kind of data we may need.
     */
    AnyDataHolder * data_;
  
  
  /////////////////////////////////////////////////
  //] Any - data (end)
  //////////////////////////////////////////////////////////////////////////////////////////////////
};


} // namespace MFCore

#endif // ndef ANY_HPP_INCLUDED_
