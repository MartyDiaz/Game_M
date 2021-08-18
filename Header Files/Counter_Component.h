#ifndef Counter_Component_H
#define Counter_Component_H

#include "Component.h"
#include <iostream>

struct Counter_Component : Component
{

	Entity* entity_{ nullptr };

	float counter_;
	
	Counter_Component(float counter);

	void draw() override;

	void update(float mFT) override;

	void init() override;
};


#endif