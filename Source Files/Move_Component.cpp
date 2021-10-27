#include "Move_Component.h"

Move_Component::Move_Component(Transform_Component* transform) : transform_{transform}
{
}

void Move_Component::move(const Vector2D& direction)
{
	spdlog::info("Moving. Direction is {0} {1}.", direction.x_, direction.y_);
	transform_->velocity_ = direction;
}
