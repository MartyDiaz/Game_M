#ifndef Physics_Component_H
#define Physics_Component_H

#include "Component.h"
#include "Position_Component.h"
#include "Vector2D.h"
#include <iostream>

struct Physics_Component : Component
{

	Entity* entity_{ nullptr };

	Position_Component* position_component_;

	Vector2D velocity_;

	Physics_Component(Position_Component* poistion_component);
	
	void draw() override;

	void update(float mFT) override;

	void init() override;

};
#endif
