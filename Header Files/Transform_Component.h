#ifndef Transform_Component_H
#define Transform_Component_H

#include "Component.h"
#include "Vector2D.h"
// Transorm_Component contains the position and velocity vector of an entity.
// The position will change based on the velocity during the update method.
// TODO:: Not sure if Transform_Component should have a width_ and height_.
// TODO:: Currently these variables are not used because the width and height
// TODO:: are held by the texture_ in the Graphic_Component.
// TODO:: I will leave it as is for now, maybe they can be used for colliders later.
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
