
namespace SD
{

  // Enum_HashCompare implementation ---------------

  template < typename Integral >
  Integral_HashCompare<Integral>::Integral_HashCompare()
  {}


  // For now, pretty much the best thing I can think to do for hashing enums is to simply
  // return the value of the enum. It wont ever collide and I can probably tell the hash_map
  // to be very dense without fear.
  // I will compare my Unsigned_HashCompare with the default hash function and see whats what.
  template < typename Integral >
  unsigned Integral_HashCompare<Integral>::operator()( const Integral key ) const
  {
    return static_cast<unsigned>(key);
  }


  // operator ( Key1, Key2 ) is used to compare keys to resolve collisions
  template < typename Integral >
  bool Integral_HashCompare<Integral>::operator()( const Integral Key1, const Integral Key2 ) const
  {
    return comp( Key1, Key2 );
  }

  // ---------------------------------------------------

}
