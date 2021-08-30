# include "Transform_Component.h"

Transform_Component::Transform_Component() :
	height_{ 0 }, width_{ 0 }, scale_{1}
{

}

Transform_Component::Transform_Component(int scale) :
	height_{ 0 }, width_{ 0 }, scale_{scale}
{

}

Transform_Component::Transform_Component(float x_pos, float y_pos) :
	position_{ x_pos, y_pos }, height_{ 0 }, width_{ 0 }, scale_{ 1 }
{

}

Transform_Component::Transform_Component(float x_pos, float y_pos, int height, int width, int scale) :
	position_{ x_pos, y_pos }, height_{ height }, width_{ width }, scale_{ scale }
{

}

void Transform_Component::update(float mFT)
{
	position_.x += velocity_.x * mFT;
	position_.y += velocity_.y * mFT;
}


