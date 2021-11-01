# include "Transform_Component.h"

Transform_Component::Transform_Component() :
	height_{ 0 }, width_{ 0 }, scale_{1}
{}

Transform_Component::Transform_Component(const int& scale) :
	height_{ 32 }, width_{ 32 }, scale_{scale}
{}

Transform_Component::Transform_Component(const Vector2D& position_vector, const Vector2D& velocity_vector) :
	position_{position_vector} , velocity_{velocity_vector}, height_{ 0 }, width_{ 0 }, scale_{ 1 }
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
	if ((position_.x_ < 0) || (position_.x_ > Constants::LEVEL_WIDTH))
	{
		//Move back
		position_.x_ -= velocity_.x_;
	}

	position_.y_ += velocity_.y_ * mFT;
	if ((position_.y_ < 0) || (position_.y_ > Constants::LEVEL_HEIGHT))
	{
		//Move back
		position_.y_ -= velocity_.y_;
	}
	//spdlog::info("Position is {0} {1}.", position_.x_, position_.y_);
	//spdlog::info("Velocity is {0} {1}.", velocity_.x_, velocity_.y_);
}


