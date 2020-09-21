/**
 * \file ImageDrawable.h
 *
 * \author Jordan Hill
 *
 * 
 */

#pragma once
#include "Drawable.h"
#include <memory>
/** Image drawable class
* Allows user to draw figure onto the screen
*/
class CImageDrawable : public CDrawable
{
public:
	/** Constructor */
	CImageDrawable(const std::wstring &name, const std::wstring &filename);
	/** Deconstructor */
	virtual ~CImageDrawable();

	/** \brief Default constructor disabled */
	CImageDrawable() = delete;
	/** \brief Copy constructor disabled */
	CImageDrawable(const CImageDrawable &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CImageDrawable &) = delete;

	/** Drawing function */
	virtual void Draw(Gdiplus::Graphics *graphics) override;
	/** Hit testing function */
	virtual bool HitTest(Gdiplus::Point pos) override;
	/** Sets the center */
	void SetCenter(Gdiplus::Point center) { mCenter = center; }
	/** Gets the current center */
	Gdiplus::Point GetCenter() const{ return mCenter; }

protected :
	/// The image for this drawable
	std::unique_ptr<Gdiplus::Bitmap> mImage;
private:
	/// center of image
	Gdiplus::Point mCenter = Gdiplus::Point(0, 0);
};

