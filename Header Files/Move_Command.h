#pragma once

#include "Move_Command.h"
#include "Command.h"
#include "Vector2D.h"
#include "Move_Component.h"


class Move_Command : Command
{

public:
	Vector2D direction_;

	void execute(const Entity& entity) override;

};