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
// Class Label interface


//
// label.cpp - implementation for a label screen object
//
#include <assert.h>
#include "label.h"

Label::Label(SimpleWindow &Window, const Position &p,
 const string &t, const color &textcolor,
 const color &c) : WindowObject(Window, p),
 TextColor(textcolor), BackgroundColor(c), Text(t) {
	// No code needed!
}
Label::Label(SimpleWindow &Window, float XCoord, float YCoord,
 const string &t, const color &textcolor,
 const color &c) : WindowObject(Window,
 Position(XCoord, YCoord)), TextColor(textcolor),
 BackgroundColor(c), Text(t) {
	// No code needed!
}
Label::Label(SimpleWindow &Window, const Position &p,
 const char *t, const color &textcolor,
 const color &c) : WindowObject(Window, p),
 TextColor(textcolor), BackgroundColor(c), Text(t) {
	// No code needed!
}

Label::Label(SimpleWindow &Window, float XCoord, float YCoord,
 const char *t, const color &textcolor,
 const color &c) : WindowObject(Window,
 Position(XCoord, YCoord)), TextColor(textcolor),
 BackgroundColor(c), Text(t) {
	// No code needed!
}

Label::~Label() {
   // No body needed
}

void Label::SetColor(const color &c) {
	BackgroundColor = c;
   return;
}

color Label::GetColor() const {
   return BackgroundColor;
}

void Label::Draw() {
	const Position Center = GetPosition();
	const Position UpperLeft = Center +  Position(-2.0f, -2.0f);
	const Position LowerRight = Center + Position( 2.0f,  2.0f);

	GetWindow().RenderText(UpperLeft, LowerRight,
	 Text.c_str(), TextColor, BackgroundColor);
   return;
}


void Label::Erase() {
	const Position Center = GetPosition();
	const Position UpperLeft = Center +  Position(-2.0f, -2.0f);
	const Position LowerRight = Center + Position( 2.0f,  2.0f);

	GetWindow().RenderText(UpperLeft, LowerRight,
	 Text.c_str(), BackgroundColor, BackgroundColor);
   return;
}



