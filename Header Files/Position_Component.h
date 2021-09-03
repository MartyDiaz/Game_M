#ifndef Position_Component_H
#define Position_Component_H

#include "Component.h"
#include "Vector2D.h"
#include <iostream>

struct Position_Component : Component
{
	Entity* entity_{ nullptr };

	Vector2D position_;

	Position_Component(const Vector2D& position);

	void draw() override;

	void update(float mFT) override;

	void init() override;

};


#endif
