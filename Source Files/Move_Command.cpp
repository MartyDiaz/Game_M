#include "Move_Command.h"


void Move_Command::execute(Entity& entity)
{
	Move_Component* move_component;
	move_component = &entity.get_component<Move_Component>();
	move_component->move(direction_);
}

bool Move_Command::not_zero()
{
	Vector2D zero_v{ 0,0 };
	if (direction_ == zero_v)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Move_Command::zero()
{
	direction_.zero();
}