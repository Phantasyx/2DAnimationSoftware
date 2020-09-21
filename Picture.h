/**
 * \file Picture.h
 *
 * \author Jordan Hill
 *
 *
 * The picture we are drawing.
 *
 * There will be one picture object that contains all of
 * our actors, which then contains the drawables.
 */


#pragma once
#include "PictureObserver.h"
#include <vector>
#include "Actor.h"
/** forward reference */
class CPictureObserver;
/** Class for the picture where images will be added to */
class CPicture
{
public:
	/** Constructor */
	CPicture();
	/** Deconstructor */
	~CPicture();
	/// Copy Constructor (Disabled)
	CPicture(const CPicture &) = delete;
	/// Assignment Operator (Disabled)
	CPicture &operator=(const CPicture &) = delete;
	/** The picture size
	* \returns Size */
	Gdiplus::Size GetSize() { return mSize; }

	/** The picture size
	* \param size The new picture size */
	void SetSize(Gdiplus::Size size) { mSize = size; }
	/** Adds observer */
	void AddObserver(CPictureObserver *observer);
	/** removes observer */
	void RemoveObserver(CPictureObserver *observer);
	/** Updates Observers */
	void UpdateObservers();
	/** Draws the image */
	void Draw(Gdiplus::Graphics *graphics);
	/** Adds actor to the picture */
	void AddActor(std::shared_ptr<CActor> actor);

	/**
	* Iterator that iterates over actors in a picutre
	*/
	class Iter
	{
	public:
		/**
		* Constructor
		*/
		Iter(CPicture *picture, int pos) : mPicture(picture), mPos(pos) {}
		bool operator != (const Iter &other) const
		{
			return mPos != other.mPos;
		}

		std::shared_ptr<CActor> operator *() const { return mPicture->mActors[mPos]; }

		const Iter& operator++()
		{
			mPos++;
			return *this;
		}
	private:
		CPicture * mPicture; /// iterated picture
		int mPos;/// current position
	};
	/** begining of the iteration */
	Iter begin()
	{
		return Iter(this, 0);
	}
	/** last element of iteration */
	Iter end()
	{
		return Iter(this, mActors.size());
	}

private:
	/// The picture size
	Gdiplus::Size mSize = Gdiplus::Size(800, 600);
	/// The observers of this picture
	std::vector<CPictureObserver *> mObservers;
	/// actor pointer
	std::vector<std::shared_ptr<CActor>> mActors;

};

