#include "Collision.h"

bool Collision::AABB(const SDL_Rect& recA, const SDL_Rect& recB)
{
	if (
		recA.x + recA.w >= recB.x &&
		recB.x + recB.w >= recA.x &&
		recA.y + recA.h >= recB.y &&
		recB.y + recB.h >= recA.y
		)
	{
		return true;
	}

	return false;
}

bool Collision::AABB(const Collider_Component& collider_a, const Collider_Component& collider_b)
{
	if (AABB(collider_a.collider_, collider_b.collider_))
	{
		spdlog::info("Collider hit.");
		return true;
	}
	else
	{
		return false;
	}
}