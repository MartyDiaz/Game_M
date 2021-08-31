#pragma once

#ifndef Graphic_Component_H
#define Graphic_Component_H

#include "Component.h"
#include "Texture.h"
#include "Transform_Component.h"
#include "Texture_Storage.h"
//Graphic_Component is added to enitities for them to be drawable.
//Graphic_Components need a Transform_Component to know where to
//draw the texture, a Texture_Storage to set it's Texture to be drawn,
//texture_file name to obtain the Texture from Texture_Storage, and a
//camera to to properly offset where to be drawn.
struct Graphic_Component : Component
{
	Transform_Component* transform_component_;
	const SDL_Rect& camera_;
	const Texture_Storage* texture_storage_;
	Texture* texture_;

	SDL_Rect destination_rect;
	SDL_Rect source_rect;

	Graphic_Component(Transform_Component* transform_component, 
		const Texture_Storage* texture_storage_,
		std::string texture_file,
		const SDL_Rect& camera
	);

	void set_texture(std::string texture_file);

	void draw() override;

	//During update() the x, y, and scale of destination_rect is updated based
	//on the transform_components_ x, y, and scale.
	void update(float mFT);

};

#endif