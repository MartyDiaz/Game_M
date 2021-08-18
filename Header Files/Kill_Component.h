#ifndef Kill_Component_H
#define Kill_Component_H

#include "Counter_Component.h"
#include "Component.h"
#include <iostream>

struct Kill_Component : Component
{

	Entity* entity_{ nullptr };

	Counter_Component* cCounter_{ nullptr };

	Kill_Component(Counter_Component* cCounter_);

	void draw() override;

	void update(float mFT) override;

	void init() override;
};


#endif