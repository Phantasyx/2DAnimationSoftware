/**
 * \file ActorFactory.h
 *
 * \author Jordan Hill
 *
 * 
 */

#pragma once
#include <memory>
#include "Actor.h"
/**
* Abstract base class for actor factories.
*/
class CActorFactory
{
public:
	/** Constructor */
	CActorFactory();
	/** Deconstructor */
	virtual ~CActorFactory();
	/** Creats a ptr to a actor */
	virtual std::shared_ptr<CActor> Create() = 0;

};

