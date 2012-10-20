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
/* EzWindows Library Header File 
   FILE:        bitmap.h
   AUTHOR:      Devon Lockwood
   Time-stamp:  <97/01/21 22:40:40 dcl3a>

   Description
   ===========
   This file contains the class definition for the BitMap class. 
   BitMap objects handle the creation and manipulation of
   XPM pictures.
*/
#ifndef BITMAP_H
#define BITMAP_H

#include <iostream>
#include <assert.h>
#include <xpm.h>
#include "Graphic.h"
#include "ezwin.h"


const unsigned int ColorCloseness = 60000;

enum BitMapStatus {NoBitMap, BitMapOkay, NoWindow};


class BitMap {
   public:
      BitMap(SimpleWindow *DisplayWindow);
      BitMap(SimpleWindow &DisplayWindow);
      BitMap();
     ~BitMap();

      BitMapStatus Load     (const string &Filename);
      void         SetWindow(SimpleWindow &Window);

      int          Draw        ()                       const;
      int          Erase       ()                       const;
      int          IsInside    (const Position &AtPosn) const;      
      float        GetXPosition()                       const;
      float        GetYPosition()                       const;
      float        GetWidth    ()                       const;
      float        GetHeight   ()                       const;
      BitMapStatus GetStatus   ()                       const;
      Position     GetPosition ()                       const;

      void SetPosition(const Position &NewPosn);

   private:
      int             status;
      Position        Posn;
      SimpleWindow   *W;
      Pixmap          PixelMap;
      XpmAttributes  *Attributes;
};


#endif
