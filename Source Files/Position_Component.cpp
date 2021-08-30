#include "Position_Component.h"

Position_Component::Position_Component(const Vector2D& position) : position_{position}
{
	
}

void Position_Component::draw()
{

}

void Position_Component::update(float mFT)
{
	
}

void Position_Component::init()
{

}

float Position_Component::x()
{
	return position_.get_x();
}

float Position_Component::y()
{
	return position_.get_y();
}