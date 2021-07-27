#include "Entity.h"

Entity::Entity(Manager& mManager) : manager_(mManager) 
{

}

bool Entity::is_alive()
{
	return alive_;
}

void Entity::destroy()
{
	alive_ = false;
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
		return group_bit_set_[mGroup];
	}

	void Entity::add_group(Group mGroup) noexcept
	{
		group_bit_set_[mGroup] = true;
		manager_.add_to_group(mGroup, this);
	}

	void Entity::del_group(Group mGroup) noexcept
	{
		group_bit_set_[mGroup] = false;
	}

	
