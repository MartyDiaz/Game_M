#include "Move_Command.h"


void Move_Command::execute(const Entity& entity)
{
	Move_Component* move_component;
	move_component = &entity.get_component<Move_Component>();
	move_component->move(direction_);
}