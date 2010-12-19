#pragma once

//#include "MFCoreConfig.hpp"
#include "TypeID.hpp"
using namespace Reflection;  // Wes here: This is for access to TypeID typedef

#include "BasicTypes.hpp"  // Wes here: This is for access to the MFCore basic types

#include <vector>



namespace MFCore
{

/*!\brief Used by BoundFunction.
 */
struct Signature
{
  Signature
    (
        TypeID const & return_type_id
      ,  TypeID const & class_type_id
      ,  B8 requires_invoking_object
    );
  
  Signature
    (
        TypeID const & return_type_id
      ,  TypeID const & class_type_id
      ,  B8 requires_invoking_object
      ,  TypeID const & argument0_type_id
    );
  
  Signature
    (
        TypeID const & return_type_id
      ,  TypeID const & class_type_id
      ,  B8 requires_invoking_object
      ,  TypeID const & argument0_type_id
      ,  TypeID const & argument1_type_id
    );
  
  Signature
    (
        TypeID const & return_type_id
      ,  TypeID const & class_type_id
      ,  B8 requires_invoking_object
      ,  TypeID const & argument0_type_id
      ,  TypeID const & argument1_type_id
      ,  TypeID const & argument2_type_id
    );
  
  Signature
    (
        TypeID const & return_type_id
      ,  TypeID const & class_type_id
      ,  B8 requires_invoking_object
      ,  TypeID const & argument0_type_id
      ,  TypeID const & argument1_type_id
      ,  TypeID const & argument2_type_id
      ,  TypeID const & argument3_type_id
    );
  
  Signature
    (
        TypeID const & return_type_id
      ,  TypeID const & class_type_id
      ,  B8 requires_invoking_object
      ,  TypeID const & argument0_type_id
      ,  TypeID const & argument1_type_id
      ,  TypeID const & argument2_type_id
      ,  TypeID const & argument3_type_id
      ,  TypeID const & argument4_type_id
    );
  
  TypeID return_type_id_;
  TypeID class_type_id_;
  std::vector< TypeID > argument_type_ids_;
  B8 requires_invoking_object_;
};

} // namespace MFCore
