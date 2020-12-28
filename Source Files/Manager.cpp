#include "Manager.h"

Entity& Manager::add_entity()
{
    Entity* added_entity( new Entity(*this) );

    entities.emplace_back(std::unique_ptr<Entity> {added_entity});

    return *added_entity;
}

void Manager::update(float mFT)
{

    for (auto& e : entities) e->update(mFT);
}

void Manager::draw()
{
    for (auto & e : entities) e->draw();

}

void Manager::refresh()
{
    for (auto i(0u); i < max_groups; ++i)
    {
        auto& v(grouped_entities[i]);

        v.erase(
            std::remove_if(std::begin(v), std::end(v),
                [i](Entity* mEntity)
                {
                    return !mEntity->is_alive() || !mEntity->has_group(i);
                }),
            std::end(v));

        entities.erase(
            std::remove_if(entities.begin(), entities.end(), 
                [](const std::unique_ptr<Entity>& mEntity)
            {
                return !mEntity->is_alive();
            }),
            std::end(entities));
     
    }
}


void Manager::add_to_group(Group mGroup, Entity* mEntity)
{
    grouped_entities[mGroup].emplace_back(mEntity);
}

std::vector<Entity*>& Manager::get_entities_by_group(Group mGroup)
{
    return grouped_entities[mGroup];
}
