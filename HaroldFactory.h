/**
 * \file HaroldFactory.h
 *
 * \author Jordan Hill
 *
 * 
 */

#pragma once
#include <memory>
#include "Actor.h"
#include "ActorFactory.h"

/**
* Factory class that builds the Harold character
*/
class CHaroldFactory : public CActorFactory
{
public:
	/** Constructor */
	CHaroldFactory();
	/** Virtual Deconstructor */
	virtual ~CHaroldFactory();
	/** Create function */
	std::shared_ptr<CActor> Create();
};

