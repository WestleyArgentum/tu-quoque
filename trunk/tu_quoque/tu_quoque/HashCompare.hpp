// HashCompare.hpp : This file contains classes that are derived from hash_compare. These
//                   classes can be plopped in to a stdext::hash_map.
//                   It also contains the declaration for FindPerfectSeed.

#pragma once

#include <hash_map>
#include <string>

namespace SD
{

  // FindPerfectSeed tests seeds with a vector of strings until it finds a perfect seed that
  // generates no collisions.
  //
  // If we found other hash functions that were less computationally heavy than Murmur (not that
  // murmur is computationally heavy) and that took in seed values, then we could tack on a param
  // and feed this function the other hash functions to find perfect seeds for (and we'd win in
  // the end because the other functions could be cheaper).
  unsigned FindPerfectSeed ( std::vector< std::string >& strings );


  // Murmur_HashCompare is a hash_compare for hash_maps that use std::string as a key
  class Murmur_HashCompare : public stdext::hash_compare< std::string >
  {
  public:
    Murmur_HashCompare ();

    enum  // parameters for hash table
    {
      bucket_size = 4,  // bucket_size > 0
      min_buckets = 8  // min_buckets = 2 ^ N, N > 0
    };

    // operator ( str ) is the hash function that calls MurmurHash
    unsigned operator () ( const std::string& str ) const;

    // operator ( Key1, Key2 ) is used to compare keys to resolve collisions
    bool operator () ( const std::string& _Key1, const std::string& _Key2 ) const;
  };


  // Enum_HashCompare is a hash_compare to be used with hash_maps that use enums as a key.
  template < typename Integral >
  class Integral_HashCompare : public stdext::hash_compare< Integral >
  {
  public:
    Integral_HashCompare ();

    enum  // parameters for hash table
    {
      bucket_size = 4,  // bucket_size > 0
      min_buckets = 8  // min_buckets = 2 ^ N, N > 0
    };

    // operator ( str ) is the hash function that calls MurmurHash
    unsigned operator () ( const Integral key ) const;

    // operator ( Key1, Key2 ) is used to compare keys to resolve collisions
    bool operator () ( const Integral Key1, const Integral Key2 ) const;
  };

}

#include "HashCompareTemplates.cpp"
