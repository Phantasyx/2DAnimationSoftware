/**
 * \file Drawable.h
 *
 * \author Jordan Hill
 *
 *
 */

#pragma once
#include <memory>
#include <vector>
#include <string>
#include <cmath>

class CActor;
/**
* Abstract base class for drawable elements of our picture.
*
* A drawable is one part of an actor. Drawable parts can be moved
* independently.
*/
class CDrawable
{
public:
	virtual ~CDrawable();

	/** Default constructor disabled */
	CDrawable() = delete;

	/** Copy constructor disabled */
	CDrawable(const CDrawable &) = delete;

	/** Assignment operator disabled */
	void operator=(const CDrawable &) = delete;
	/** Set root */
	void SetActor(CActor *actor);

	/** draw function */
	virtual void Draw(Gdiplus::Graphics *graphics) = 0;
	/** place rotation function */
	void Place(Gdiplus::Point offset, double rotate);
	/** adds child */
	void AddChild(std::shared_ptr<CDrawable> child);
	/** Tests for hits */
	virtual bool HitTest(Gdiplus::Point pos) = 0;
	/** bool for movablitity */
	virtual bool IsMovable() { return false; }
	/** move function */
	void Move(Gdiplus::Point delta);
	/** Gets parent function */
	CDrawable *GetParent() { return mParent; }

	/** Set the drawable position
	* \param pos The new drawable position*/
	void SetPosition(Gdiplus::Point pos) { mPosition = pos; }

	/** Get the drawable position
	* \returns The drawable position*/
	Gdiplus::Point GetPosition() const { return mPosition; }

	/** Set the rotation angle in radians
	* \param r The new rotation angle in radians*/
	void SetRotation(double r) { mRotation = r; }

	/** Get the rotation angle in radians
	* \returns The rotation angle in radians*/
	double GetRotation() const { return mRotation; }

	/** Get the drawable name
	* \returns The drawable name */
	std::wstring GetName() const { return mName; }
	/** sets the parent object */
	void SetParent(CDrawable *parent) { mParent = parent; }
	/** Sets the name */
	CDrawable(const std::wstring &name);
	/** rotate point function */
	Gdiplus::Point RotatePoint(Gdiplus::Point point, double angle);


	/// The actual postion in the drawing
	Gdiplus::Point mPlacedPosition = Gdiplus::Point(0, 0);

	/// The actual rotation in the drawing
	double mPlacedR = 0;

private:
	/// The drawable name
	std::wstring mName;

	/// The position of this drawable relative to its parent
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);

	/// The rotation of this drawable relative to its parent
	double mRotation = 0;
	/// The actor using this drawable
	CActor *mActor = nullptr;

	/// child drawn
	std::vector<std::shared_ptr<CDrawable>> mChildren;
	/// parent of child
	CDrawable *mParent = nullptr;
};