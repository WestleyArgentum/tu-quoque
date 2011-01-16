// HashCompare.cpp : This file contains the implementation for the hash_compare classes as well
//                   as the FindPerfectSeed function.
#include "HashCompare.hpp"

#include "HashFunctions.hpp"

#include <set>

namespace SD
{

  // seed value for MurmurHash
  static const unsigned SEED = 2;


  // FindPerfectSeed tests seeds with a vector of strings until it finds a perfect seed that
  // generates no collisions.
  //
  // If we found other hash functions that were less computationally heavy than Murmur (no that
  // murmur is computationally heavy) and that took in seed values, then we could tack on a param
  // and feed this function the other hash functions to find perfect seeds for (and we'd win in
  // the end because the other functions could be cheaper).
  unsigned FindPerfectSeed ( std::vector< std::string >& strings )
  {
    unsigned seed = 0;
    std::set<int> hash_results;

    for (;;)
    {
      std::pair< std::set< int >::iterator, bool > ret;
      for ( unsigned i = 0; i < strings.size(); ++i )
      {
        ret = hash_results.insert( MurmurHash2A( strings[i].c_str(), strings[i].size(), seed ) );

        // if the hash of this string has already been generated then break and try the next seed.
        if( ret.second != true )
          break;
        // if this was the last one we needed to check, we found our seed value ^.^
        else if (i == strings[i].size() - 1)
          return seed;
      }

      // try the next seed
      ++seed;
      hash_results.clear();
    }
  }


  // Murmur_HashCompare implementation -----------------

  Murmur_HashCompare::Murmur_HashCompare()
  {
    // set some values for the hash map here
  }


  // operator ( str ) is the hash function that calls MurmurHash
  unsigned Murmur_HashCompare::operator()( const std::string& str ) const
  {
    return MurmurHash2A( str.c_str(), str.size(), SEED );
  }


  // operator ( Key1, Key2 ) is used to compare keys to resolve collisions
  bool Murmur_HashCompare::operator()( const std::string& Key1, const std::string& Key2 ) const
  {
    return comp( Key1, Key2 );
  }

  // ---------------------------------------------------

}
