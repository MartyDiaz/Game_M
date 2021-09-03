#include "Physics_Component.h"

Physics_Component::Physics_Component(Position_Component* position_component) :
	position_component_{ position_component } {}

void Physics_Component::draw()
{
	std::cout << " Physics_Component drawing " << "\n";
}

void Physics_Component::update(float mFT)
{
	std::cout << " Physics_Component updating " << "\n";
	
	position_component_->position_.x_ += (velocity_.x_ * mFT);
	position_component_->position_.y_ += (velocity_.y_ * mFT);
}

void Physics_Component::init()
{
	std::cout << " Physics_Component Initializing" << "\n";
}
