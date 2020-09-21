/**
 * \file PictureFactory.h
 *
 * \author Jordan Hill
 *
 * 
 */

#pragma once
#include <memory>
#include "Picture.h"
/**
 * A factory class that builds our picture.
 */
class CPictureFactory
{
public:
	/** Constructor */
	CPictureFactory();
	/** DEConstructor */
	virtual ~CPictureFactory();
	/** creation function */
	std::shared_ptr<CPicture> Create();

};

