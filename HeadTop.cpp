/**
 * \file TopHead.cpp
 *
 * \author Jordan Hill
 */

#include "stdafx.h"
#include "HeadTop.h"
#include "Actor.h"
#include "Picture.h"

using namespace std;
using namespace Gdiplus;

/** Constructor \loads image */
CHeadTop::CHeadTop(const std::wstring &name, const std::wstring &filename)
	: CImageDrawable(name, filename)
{
}


CHeadTop::~CHeadTop()
{
}

/** Transform a point from a location on the bitmap to
*  a location on the screen.
* \param  p Point to transform
* \returns Transformed point
*/
Gdiplus::Point CHeadTop::TransformPoint(Gdiplus::Point p)
{
    // Make p relative to the image center
    p = p - GetCenter();

    // Rotate as needed and offset
    return RotatePoint(p, mPlacedR) + mPlacedPosition;
}

