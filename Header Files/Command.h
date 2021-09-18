#pragma once
#include "Entity.h"

class Command
{
private:

public:

	virtual void execute(const Entity& entity);
};