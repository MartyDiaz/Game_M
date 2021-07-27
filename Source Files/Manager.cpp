#include "Manager.h"

Entity& Manager::add_entity()
{
    Entity* added_entity( new Entity(*this) );

    entities_.emplace_back(std::unique_ptr<Entity> {added_entity});

    return *added_entity;
}

void Manager::update(float mFT)
{

    for (auto& e : entities_) e->update(mFT);
}

void Manager::draw()
{
    for (auto& e : entities_) e->draw();

}

void Manager::refresh()
{
    for (auto i(0u); i < max_groups; ++i)
    {
        auto& v(grouped_entities_[i]);

        v.erase(
            std::remove_if(std::begin(v), std::end(v),
                [i](Entity* mEntity)
                {
                    return !mEntity->is_alive() || !mEntity->has_group(i);
                }),
            std::end(v));

        entities_.erase(
            std::remove_if(entities_.begin(), entities_.end(), 
                [](const std::unique_ptr<Entity>& mEntity)
            {
                return !mEntity->is_alive();
            }),
            std::end(entities_));
     
    }
}


void Manager::add_to_group(Group mGroup, Entity* mEntity)
{
    grouped_entities_[mGroup].emplace_back(mEntity);
}

std::vector<Entity*>& Manager::get_entities_by_group(Group mGroup)
{
    return grouped_entities_[mGroup];
}
