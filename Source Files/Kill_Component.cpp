#include "Kill_Component.h"

Kill_Component::Kill_Component(Counter_Component* cCounter) : cCounter_(cCounter)
{

}

void Kill_Component::draw()
{

}

void Kill_Component::update(float mFT)
{
	if (cCounter_->counter_ >= 100) entity_->destroy();
}

void Kill_Component::init()
{

}