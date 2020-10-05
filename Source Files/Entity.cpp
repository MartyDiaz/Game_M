#include "Entity.h"

Entity::Entity(Manager& mManager) : manager(mManager) 
{

}

bool Entity::is_alive()
{
	return alive;
}

void Entity::destroy()
{
	alive = false;
}

void Entity::update(float mFT)
	{
		for (auto& const c : components) { c->update(mFT); }
	}
	
	void Entity::draw()
	{
		for (auto& const c : components) { c->draw(); }
	}

	bool Entity::has_group(Group mGroup) const noexcept
	{
		return group_bit_set[mGroup];
	}

	void Entity::add_group(Group mGroup) noexcept
	{
		group_bit_set[mGroup] = true;
		manager.add_to_group(mGroup, this);
	}

	void Entity::del_group(Group mGroup) noexcept
	{
		group_bit_set[mGroup] = false;
	}

	
