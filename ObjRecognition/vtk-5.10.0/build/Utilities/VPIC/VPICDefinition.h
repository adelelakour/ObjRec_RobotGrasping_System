#ifndef VPICDefinition_h
#define VPICDefinition_h

#include <vtksys/Configure.h>
#include <string>
#include <iostream>

#include "vtkABI.h"

using namespace std;

/* #undef BUILD_SHARED_LIBS */

// Now set up all of the export macros
#if defined(BUILD_SHARED_LIBS)
 #if defined(VPIC_EXPORTS)
  #define VPIC_EXPORT VTK_ABI_EXPORT
 #else
  #define VPIC_EXPORT VTK_ABI_IMPORT
 #endif
#else
 #define VPIC_EXPORT
#endif

#define vpicNotUsed(x)


#define WORDSIZE 8
const int LINESIZE      = 1024;

const int VPIC_OK       = 0;
const int VPIC_FAIL     = 1;

const int NONE          = -1;

const double MIN_FLOAT  = -1e07;
const double MAX_FLOAT  =  1e07;

const int VPIC_FIELD            = 1;    // Field data file
const int VPIC_HYDRO            = 2;    // Hydro data file

const int DIMENSION             = 3;    // Grid and vector
const int TENSOR_DIMENSION      = 6;    // Tensor
const int TENSOR9_DIMENSION     = 9;    // Tensor

const int CONSTANT              = 0;    // Structure types
const int SCALAR                = 1;
const int VECTOR                = 2;
const int TENSOR                = 3;
const int TENSOR9               = 4;

const int FLOAT                 = 0;    // Basic data types
const int INTEGER               = 1;

typedef      float   GRID_T;

//
// Neighbors are enumerated so that particles can be attached to the correct
// neighbor, but these pairs must be preserved for the ParticleExchange.
// Every processor should be able to send and receive on every iteration of
// the exchange, so if everyone sends RIGHT and receives LEFT it works
//
// Do not change this pairing order.
//
enum NEIGHBOR
{
  X0,                   // Left face
  X1,                   // Right face

  Y0,                   // Bottom face
  Y1,                   // Top face

  Z0,                   // Front face
  Z1,                   // Back face

  X0_Y0,                // Left   bottom edge
  X1_Y1,                // Right  top    edge

  X0_Y1,                // Left   top    edge
  X1_Y0,                // Right  bottom edge

  Y0_Z0,                // Bottom front  edge
  Y1_Z1,                // Top    back   edge

  Y0_Z1,                // Bottom back   edge
  Y1_Z0,                // Top    front  edge

  Z0_X0,                // Front  left   edge
  Z1_X1,                // Back   right  edge

  Z0_X1,                // Front  right  edge
  Z1_X0,                // Back   left   edge

  X0_Y0_Z0,             // Left  bottom front corner
  X1_Y1_Z1,             // Right top    back  corner

  X0_Y0_Z1,             // Left  bottom back  corner
  X1_Y1_Z0,             // Right top    front corner

  X0_Y1_Z0,             // Left  top    front corner
  X1_Y0_Z1,             // Right bottom back  corner

  X0_Y1_Z1,             // Left  top    back  corner
  X1_Y0_Z0              // Right bottom front corner
};

const int NUM_OF_NEIGHBORS      = 26;

// Read character string from file
string readString(FILE* filePtr, int size);

// Read number of unsigned integer items from file, byte swapping if needed
void readData(
        bool littleEndian,
        unsigned short* data,
        unsigned long dataSize,
        unsigned long dataCount,
        FILE* fp);

// Read number of integer items from file, byte swapping if needed
void readData(
        bool littleEndian,
        int* data,
        unsigned long dataSize,
        unsigned long dataCount,
        FILE* fp);

// Read number of float items from file, byte swapping if needed
void readData(
        bool littleEndian,
        float* data,
        unsigned long dataSize,
        unsigned long dataCount,
        FILE* fp);

// Read number of float items from file, byte swapping if needed
void readData(
        bool littleEndian,
        double* data,
        unsigned long dataSize,
        unsigned long dataCount,
        FILE* fp);

// Greatest Common Divisor
int GCD(int a, int b);

// Templated function BinaryWrite
template< class outDataType >
inline void BinaryWrite(ostream& outStream, const outDataType& outData)
{
  outStream.write(
    reinterpret_cast<const char*>(&outData), sizeof(outDataType));
}

// Templated function BinaryRead
template< class inHolderType >
inline istream& BinaryRead(istream& inStream, inHolderType& inHolder)
{
   return inStream.read(
      reinterpret_cast<char*>(&inHolder), sizeof(inHolderType));
}

#endif
