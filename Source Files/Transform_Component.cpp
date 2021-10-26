# include "Transform_Component.h"

Transform_Component::Transform_Component() :
	height_{ 0 }, width_{ 0 }, scale_{1}
{}

Transform_Component::Transform_Component(const int& scale) :
	height_{ 32 }, width_{ 32 }, scale_{scale}
{}

Transform_Component::Transform_Component(const Vector2D& position_vector, const Vector2D& velocity_vector) :
	position_{position_vector} , velocity_{velocity_vector}
{}

Transform_Component::Transform_Component(const float& x_pos, const float& y_pos) :
	position_{ x_pos, y_pos }, height_{ 32 }, width_{ 32 }, scale_{ 1 }
{}

Transform_Component::Transform_Component(const float& x_pos, const float& y_pos, const int& height, const int& width, const int& scale) :
	position_{ x_pos, y_pos }, height_{ height }, width_{ width }, scale_{ scale }
{}

void Transform_Component::update(float mFT)
{
	position_.x_ += velocity_.x_ * mFT;
	position_.y_ += velocity_.y_ * mFT;
}


