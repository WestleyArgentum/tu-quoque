/******************************************************************************/
/*!
\file   BasicTypes.hpp
\author Chris Barrett
\brief
  BasicTypes declarations.

  Copyright (C) 2009 DigiPen Institute of Technology.
  Reproduction or disclosure of this file or its contents without the
  prior written consent of DigiPen Institute of Technology is prohibited.

*/
/******************************************************************************/


#pragma once
#ifndef BASIC_TYPES_HPP_
#define BASIC_TYPES_HPP_

//#include "MFCoreConfig.hpp"

//#ifdef MFCORE_BASIC_TYPES_INCLUDES_STRING_
#include <string>
//#endif

namespace MFCore
{


typedef bool                B8;// 8 bits under Microsoft

typedef   signed char        I8;
typedef unsigned char        U8;
typedef          short      I16;
typedef unsigned short      U16;
typedef          int        I32;
typedef unsigned int        U32;
typedef          long long  I64;
typedef unsigned long long  U64;

typedef float                F32;
typedef double              F64;

#ifdef MFCORE_BASIC_TYPES_INCLUDES_STRING_
typedef std::string          STRING;
#endif


}
using namespace MFCore;

#endif // ndef BASIC_TYPES_HPP_
