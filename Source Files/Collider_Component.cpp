#include "Collider_Component.h"

Collider_Component::Collider_Component(Transform_Component* transform_component, const std::string& tag) 
	: transform_{transform_component}, tag_{tag}
{
	collider_.x = static_cast<int>(transform_->position_.x_);
	collider_.y = static_cast<int>(transform_->position_.y_);
	collider_.w = transform_->width_ * transform_->scale_;
	collider_.h = transform_->height_ * transform_->scale_;
}

void Collider_Component::update(float mFT)
{
	collider_.x = static_cast<int>(transform_->position_.x_);
	collider_.y = static_cast<int>(transform_->position_.y_);
	collider_.w = transform_->width_ * transform_->scale_;
	collider_.h = transform_->height_ * transform_->scale_;
}