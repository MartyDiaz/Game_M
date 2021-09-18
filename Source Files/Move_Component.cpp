#include "Move_Component.h"

Move_Component::Move_Component()
{
	transform = &entity_->get_component<Transform_Component>();
}

void Move_Component::move(const Vector2D& direction)
{
	transform->velocity_ += direction;
}