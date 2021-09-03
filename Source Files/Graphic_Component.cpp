#include "Graphic_Component.h"

Graphic_Component::Graphic_Component(Transform_Component* transform_component,
	const Texture_Storage* texture_storage, const std::string& texture_file, const SDL_Rect& camera) 
	: transform_component_{ transform_component }, texture_storage_{ texture_storage },
	camera_{camera}

{
	set_texture(texture_file);
	source_rect.x = source_rect.y = 0;
	source_rect.w = transform_component_->width_;
	source_rect.h = transform_component_->height_;
}
	
void Graphic_Component::set_texture(std::string texture_file)
{
	texture_ = texture_storage_->get_texture("texture1");
}

void Graphic_Component::draw()
{
	texture_->render(source_rect, destination_rect);
}

void Graphic_Component::update(float mFT)
{
	destination_rect.x = static_cast<int>(transform_component_->position_.x_) - camera_.x;
	destination_rect.y = static_cast<int>(transform_component_->position_.y_) - camera_.y;
	
	destination_rect.w = texture_->get_width() * transform_component_->scale_;
	destination_rect.h = texture_->get_height() * transform_component_->scale_;
	
}