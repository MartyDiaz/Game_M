#pragma once
#include "Component.h"
#include "Transform_Component.h"
#include "SDL.h"

// Collider made from transform component
class Collider_Component : public Component
{

public:
	std::string tag_;
	SDL_Rect collider_;
	Transform_Component* transform_;

	Collider_Component(Transform_Component* transform_component, const std::string& tag);

	void update(float mFT) override;



};