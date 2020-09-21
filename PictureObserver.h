/**
 * \file PictureObserver.h
 *
 * \author Jordan Hill
 *
 *
* Observer base class for a picture.
*
* This class implements the base class functionality for
* an observer in the observer pattern.
*/
#pragma once
#include <memory>
class CPicture;

class CPictureObserver
{
protected:
	CPictureObserver();
public :
	virtual ~CPictureObserver();
	//! Copy Constructor (Disabled)
	CPictureObserver(const CPictureObserver &) = delete;
	//! Assignment Operator (Disabled)
	CPictureObserver &operator=(const CPictureObserver &) = delete;
	/// This function is called to update any observers
	virtual void UpdateObserver() = 0;
	void SetPicture(std::shared_ptr<CPicture> picture);
	/**
	* Returns picture object
	*/
	std::shared_ptr<CPicture> GetPicture() { return mPicture; }
private :
 /// Picture we are observing
    std::shared_ptr<CPicture> mPicture;

};

