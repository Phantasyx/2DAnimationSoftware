/**
 * \file Actor.h
 *
 * \author Jordan Hill
 *
 *
 */

#pragma once
#include <vector>
/**
* Class for actors in our drawings.
*
* An actor is some graphical object that consists of
* one or more parts. Actors can be animated.
*/
#pragma once

#include "Drawable.h"

#include <string>
#include <memory>

class CPicture;

/**
* Class for actors in our drawings.
*
* An actor is some graphical object that consists of
* one or more parts. Actors can be animated.
*/
class CActor
{
public:
	/**
	* Constructor
	*/
	CActor(const std::wstring &name);

	/** Default constructor disabled */
	CActor() = delete;
	/** Copy constructor disabled */
	CActor(const CActor &) = delete;
	/** Assignment operator disabled */
	void operator=(const CActor &) = delete;
	/** Deconstructor */
	virtual ~CActor();
	/** Set root */
	void SetRoot(std::shared_ptr<CDrawable> root);
	/** Draw function */
	void Draw(Gdiplus::Graphics *graphics);
	/** tests if clicked */
	std::shared_ptr<CDrawable> HitTest(Gdiplus::Point pos);
	/** Adds drawable object to the picture */
	void AddDrawable(std::shared_ptr<CDrawable> drawable);

	/** Get the actor name
	* \returns Actor name */
	std::wstring GetName() const { return mName; }

	/** The actor position
	* \returns The actor position as a point */
	Gdiplus::Point GetPosition() const { return mPosition; }

	/** The actor position
	* \param pos The new actor position */
	void SetPosition(Gdiplus::Point pos) { mPosition = pos; }


	/** Actor is enabled
	* \returns enabled status */
	bool IsEnabled() const { return mEnabled; }

	/** Set Actor Enabled
	* \param enabled New enabled status */
	void SetEnabled(bool enabled) { mEnabled = enabled; }

	/** Actor is clickable
	* \returns true if actor is clickable */
	bool IsClickable() const { return mClickable; }

	/** Actor clickable
	* \param clickable New clickable status */
	void SetClickable(bool clickable) { mClickable = clickable; }
	/** Gets picture object */
	CPicture *GetPicture() { return mPicture; }
	void SetPicture(CPicture* picture){ mPicture = picture; };
private:
	/// name member
	std::wstring mName;
	/// flags enabled status
	bool mEnabled = true;
	/// point position in space set to 0
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);
	/// if the item is clickable status
	bool mClickable = true;
	/// The root drawable
	std::shared_ptr<CDrawable> mRoot;
	/// The drawables in drawing order
	std::vector<std::shared_ptr<CDrawable>> mDrawablesInOrder;
	/// picture that the actor is in
	CPicture *mPicture;
};
