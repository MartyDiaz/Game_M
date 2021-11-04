#pragma once
#include "SDL.h"
#include "Collider_Component.h"
namespace Collision
{
	bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
	bool AABB(const Collider_Component& collider_a, const Collider_Component& collider_b);
}