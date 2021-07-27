
#ifndef Physics_Component_H
#define Physics_Component_H

#include "Component.h"
#include "Header Files/Vector2D.h"
#include <iostream>

struct Physics_Component : Component
{
private:
	Entity* entity_{ nullptr };

	Vector2D position;

	Vector2D velocity;

public:
	
	void draw() override;

	void update(float mFT) override;

	void init() override;

};
#endif
