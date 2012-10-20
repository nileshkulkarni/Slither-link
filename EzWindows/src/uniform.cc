//**************************************************************************
//
// Copyright (c) 1997.
//      Richard D. Irwin, Inc.
//
// This software may not be distributed further without permission from
// Richard D. Irwin, Inc.
//
// This software is distributed WITHOUT ANY WARRANTY. No claims are made
// as to its functionality or purpose.
//
// Author: Devon Lockwood
// Date: 1/30/97
// $Revision: 1.1 $
// $Name: $
//
//**************************************************************************
/* EzWindows Library Source File
   FILE:        uniform.cc
   AUTHOR:      Devon Lockwood
   Time-stamp:  <96/12/07 20:06:39 dcl3a>

   Description
   ===========
   Functions below provides random generation of integers.
*/
#include "uniform.h"


void InitializeSeed() {

   srand((unsigned) (clock() / CLOCKS_PER_SEC));
}


// Uniform -- generate a random number in the range
// i to j inclusive
int Uniform(int i, int j) {
   
   assert(i >= 0 && j >= 0 && j >= i);
   return (rand() % (j - i + 1)) + i;
}
