#ifndef Position_Component_H
#define Position_Component_H

#include "Component.h"
#include <iostream>

struct Position_Component : Component
{

	Entity* entity_{ nullptr };

	Position_Component();

	void draw() override;

	void update(float mFT) override;

	void init() override;
};


#endif
