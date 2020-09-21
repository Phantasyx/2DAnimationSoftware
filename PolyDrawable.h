/**
 * \file PolyDrawable.h
 *
 * \author Jordan Hill
 *
 * 
 */

#pragma once
#include "Drawable.h"
#include <vector>
/**
* A drawable based on polygon images.
*
* This class has a list of points and draws a polygon
* drawable based on those points.
*/
class CPolyDrawable : public CDrawable
{
public:
	CPolyDrawable(const std::wstring &name) : CDrawable(name){}
	

	/** \brief Default constructor disabled */
	CPolyDrawable() = delete;
	/** \brief Copy constructor disabled */
	CPolyDrawable(const CPolyDrawable &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CPolyDrawable &) = delete;
	
	virtual ~CPolyDrawable();

	/**  \brief Drawing function */
	virtual void Draw(Gdiplus::Graphics *graphics) override;
	/**  \brief points function */
	void AddPoint(Gdiplus::Point point);

	/** \brief Set the color for the polygon
	* \param color New color to set */
	void SetColor(Gdiplus::Color color) { mColor = color; }
	bool HitTest(Gdiplus::Point pos);

	/**
	* gets the drawable color
	*/
	Gdiplus::Color GetColor() const { return mColor; }

private:
	/// The array of point objects
	std::vector<Gdiplus::Point> mPoints;
	/// The polygon color
	Gdiplus::Color mColor = Gdiplus::Color::Black;
};

