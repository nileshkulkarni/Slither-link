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
/* EzWindows Library Header Filer
   FILE:        Constants.h
   AUTHOR:      Devon Lockwood
   Time-stamp:  <97/01/18 17:16:17 dcl3a>

   Description
   ===========
   Some global constants
*/

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
using namespace std;

const int             MaxColors    = 8;
const string          NoTitle       ("Untitled");
const string          WindowFont    ("9x15");
const Position        LogicalOrigin (3.0, 3.0);
const GraphicPosition DeviceOrigin  (0, 0);

enum color        {Black, White, Red, Green, Blue, Yellow, Cyan, Magenta};
enum WindowStatus {WindowClosed, WindowOpen, WindowFailure};




#endif
