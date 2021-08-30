#ifndef Transform_Component_H
#define Transform_Component_H

#include "Component.h"
#include "Vector2D.h"
struct Transform_Component : Component
{
	Vector2D position_;
	Vector2D velocity_;

	int height_;
	int width_;
	int scale_;

	Transform_Component();

	Transform_Component(int scale);

	Transform_Component(float x_pos, float y_pos);

	Transform_Component(float x_pos, float y_pos, int height, int width, int scale);

	void update(float mFT) override;


};

#endif
