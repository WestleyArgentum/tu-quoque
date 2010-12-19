#include "Signature.hpp"


namespace MFCore
{

// Signature()
Signature::Signature
  (
      TypeID const & return_type_id
    ,  TypeID const & class_type_id
    ,  B8 requires_invoking_object
  ):
      return_type_id_(return_type_id)
    ,  class_type_id_(class_type_id)
    ,  requires_invoking_object_(requires_invoking_object)
{}


// Signature()
Signature::Signature
  (
      TypeID const & return_type_id
    ,  TypeID const & class_type_id
    ,  B8 requires_invoking_object
    ,  TypeID const & argument0_type_id
  ):
      return_type_id_(return_type_id)
    ,  class_type_id_(class_type_id)
    ,  requires_invoking_object_(requires_invoking_object)
{
  argument_type_ids_.push_back( argument0_type_id );
}


// Signature()
Signature::Signature
  (
      TypeID const & return_type_id
    ,  TypeID const & class_type_id
    ,  B8 requires_invoking_object
    ,  TypeID const & argument0_type_id
    ,  TypeID const & argument1_type_id
  ):
      return_type_id_(return_type_id)
    ,  class_type_id_(class_type_id)
    ,  requires_invoking_object_(requires_invoking_object)
{
  argument_type_ids_.push_back( argument0_type_id );
  argument_type_ids_.push_back( argument1_type_id );
}


// Signature()
Signature::Signature
  (
      TypeID const & return_type_id
    ,  TypeID const & class_type_id
    ,  B8 requires_invoking_object
    ,  TypeID const & argument0_type_id
    ,  TypeID const & argument1_type_id
    ,  TypeID const & argument2_type_id
  ):
      return_type_id_(return_type_id)
    ,  class_type_id_(class_type_id)
    ,  requires_invoking_object_(requires_invoking_object)
{
  argument_type_ids_.push_back( argument0_type_id );
  argument_type_ids_.push_back( argument1_type_id );
  argument_type_ids_.push_back( argument2_type_id );
}


// Signature()
Signature::Signature
  (
      TypeID const & return_type_id
    ,  TypeID const & class_type_id
    ,  B8 requires_invoking_object
    ,  TypeID const & argument0_type_id
    ,  TypeID const & argument1_type_id
    ,  TypeID const & argument2_type_id
    ,  TypeID const & argument3_type_id
  ):
      return_type_id_(return_type_id)
    ,  class_type_id_(class_type_id)
    ,  requires_invoking_object_(requires_invoking_object)
{
  argument_type_ids_.push_back( argument0_type_id );
  argument_type_ids_.push_back( argument1_type_id );
  argument_type_ids_.push_back( argument2_type_id );
  argument_type_ids_.push_back( argument3_type_id );
}


// Signature()
Signature::Signature
  (
      TypeID const & return_type_id
    ,  TypeID const & class_type_id
    ,  B8 requires_invoking_object
    ,  TypeID const & argument0_type_id
    ,  TypeID const & argument1_type_id
    ,  TypeID const & argument2_type_id
    ,  TypeID const & argument3_type_id
    ,  TypeID const & argument4_type_id
  ):
      return_type_id_(return_type_id)
    ,  class_type_id_(class_type_id)
    ,  requires_invoking_object_(requires_invoking_object)
{
  argument_type_ids_.push_back( argument0_type_id );
  argument_type_ids_.push_back( argument1_type_id );
  argument_type_ids_.push_back( argument2_type_id );
  argument_type_ids_.push_back( argument3_type_id );
  argument_type_ids_.push_back( argument4_type_id );
}

} // namespace MFCore
