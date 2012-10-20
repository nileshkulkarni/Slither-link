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
// Authors: James P. Cohoon and Jack W. Davidson
// Date: 7/15/96
// $Revision: 1.3 $
// $Name: $
//
//**************************************************************************
// Class WindowObject implementation


#include <assert.h>
#include "wobject.h"


WindowObject::WindowObject(SimpleWindow &w,
 const Position &p) : Window(w), Location(p) {
 // No body needed
}


Position WindowObject::GetPosition() const {
	return Location;
}

void WindowObject::GetPosition(float &x, float &y) const {
   x = Location.GetXDistance();
   y = Location.GetYDistance();
   return;
}

SimpleWindow& WindowObject::GetWindow() const {
   return Window;
}

void WindowObject::SetPosition(const Position &p) {
   Location = p;
   return;
}

void WindowObject::SetPosition(float x, float y) {
   Location = Position(x, y);
   return;
}



