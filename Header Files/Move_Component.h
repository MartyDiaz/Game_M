#pragma once

#include "Component.h"
#include "Vector2D.h"
#include "Transform_Component.h"

struct Move_Component : Component
{
	Move_Component();

	Transform_Component* transform;

	void move(const Vector2D& direction);
};