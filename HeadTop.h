/**
 * \file TopHead.h
 *
 * \author Jordan Hill
 *
 * 
 */

#pragma once
#include "ImageDrawable.h"
#include <memory>

class CHeadTop : public CImageDrawable
{
public:
	CHeadTop(const std::wstring &name, const std::wstring &filename);
	virtual ~CHeadTop();
	/** \brief Default constructor disabled */
	CHeadTop() = delete;

	/** \brief Copy constructor disabled */
	CHeadTop(const CHeadTop &) = delete;

	/** \brief Assignment operator disabled */
	void operator=(const CHeadTop &) = delete;
	

	/** Transform a point from a location on the bitmap to
	*  a location on the screen.
	* \param  p Point to transform
	* \returns Transformed point
	*/
	Gdiplus::Point TransformPoint(Gdiplus::Point p);


private :
	///left eye
	Gdiplus::Point mLeftEye = Gdiplus::Point(0, 0);
	/// right eye
	Gdiplus::Point mRightEye = Gdiplus::Point(0, 0);


};

