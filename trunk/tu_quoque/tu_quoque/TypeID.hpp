/******************************************************************************/
/*!
\file   TypeID.hpp
\author Chris Barrett
\brief
  To allow each type to be given its own unique ID.

  Copyright (C) 2010 DigiPen Institute of Technology.
  Reproduction or disclosure of this file or its contents without the
  prior written consent of DigiPen Institute of Technology is prohibited.

*/
/******************************************************************************/

#pragma once

#include <string>



namespace Reflection
{
	typedef unsigned TypeID;
	
	/*!\brief Used to generate semi-unique integral IDs for differing types.
	 *
	 *  The TypeID of \c void is always zero.
	 *
	 * \see
	 *  TypeIDGenerator::getTypeID
	 */
	//namespace TypeIDGenerator
	//{
		//////////////////////////////////////////////////////////////////////////////////////
		#pragma region TypeIDGenerator - data/types
		///////////////////////////////////////////
		
		
		struct Internal
		{
			
			/*!\brief Allows per-getTypeID-instantiation counting, so each type gets its own
			 *  TypeID.
			 */
			static TypeID next_type_id_;
		};
		
		
		///////////////////////////////////////////
		#pragma endregion
		//////////////////////////////////////////////////////////////////////////////////////
		#pragma region TypeIDGenerator - methods
		///////////////////////////////////////////
		
	    /*!\brief Used for lining up specific, built-in TypeID values with those from AntTweakBar.
	     */
	    enum AntTweakBarTypeIDs
	    {
		    UNDEFINED_ID    = 0 // void in this system, anything unrecognized in ATB's system
		    ,  B8_ID         = 1
		    , I8_ID         = 6 // to be consistent with AntTweakBar
		    , U8_ID // unsigned char
		    ,I16_ID // short
		    ,U16_ID // unsigned short
		    ,I32_ID // int
		    ,U32_ID // unsigned

		    ,F32_ID // float
		    ,F64_ID // double

		    ,STRING_ID      = 18 // to be consistent with AntTweakBar

		    //,I64_ID // not present in AntTweakBar
		    //,U64_ID // not present in AntTweakBar
	    };
		
		/*!\brief Retrieves the TypeID of the given type.  The type \b must be manually specified.
		 *
		 * \par How To Use:
		 *  \code
		 *  TypeID int_typeid = TypeIDGenerator::getTypeID< int >();
		 *  TypeID foo_typeid = TypeIDGenerator::getTypeID< foo >();
		 *  //                          type specification (^^^) is required
		 *  \endcode
		 */
		template <typename T>
		inline TypeID getTypeID (void)
		{
			static TypeID type_id_ = STRING_ID + Internal::next_type_id_++;
			return type_id_;
		}
		
	    // bool
	    template <>
	    static inline TypeID getTypeID<bool>(void)
	    { return B8_ID; }
    	
	    // char
	    template <>
	    static inline TypeID getTypeID<signed char>(void)
	    { return I8_ID; }
    	
	    // unsigned char
	    template <>
	    static inline TypeID getTypeID<unsigned char>(void)
	    { return U8_ID; }
    	
	    // short
	    template <>
	    static inline TypeID getTypeID<short>(void)
	    { return I16_ID; }
    	
	    // unsigned short
	    template <>
	    static inline TypeID getTypeID<unsigned short>(void)
	    { return U16_ID; }
    	
	    // int
	    template <>
	    static inline TypeID getTypeID<int>(void)
	    { return I32_ID; }
    	
	    // unsigned int
	    template <>
	    static inline TypeID getTypeID<unsigned int>(void)
	    { return U32_ID; }
    	
	    // float
	    template <>
	    static inline TypeID getTypeID<float>(void)
	    { return F32_ID; }
    	
	    // double
	    template <>
	    static inline TypeID getTypeID<double>(void)
	    { return F64_ID; }
    	
	    // std::string
	    template <>
	    static inline TypeID getTypeID<std::string>(void)
	    { return STRING_ID; }
    	

		/*!\brief Retrieves the TypeID of \c void; this is always 0.
		 *
		 * \see
		 *  getTypeID()
		 */
		template <>
		inline TypeID getTypeID <void> (void)
		{
			return 0;
		}
		
		
		///////////////////////////////////////////
		#pragma endregion
		//////////////////////////////////////////////////////////////////////////////////////
	//}
}
