#include "Move_Component.h"

Move_Component::Move_Component(Transform_Component* transform) : transform_{transform}
{
}

void Move_Component::move(const Vector2D& direction)
{
	transform_->velocity_ += direction;
}
