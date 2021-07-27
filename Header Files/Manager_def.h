
#ifndef Manager_DEF_H
#define Manager_DEF_H

#include <vector>
#include <memory>
#include <bitset>

class Entity;

// Manager will hold all entities and have functions that will traverse and 
// update, draw, and refresh all entities. Manager will also contain 
// grouped_entities, a array of vectors with each vector containing entities. 
// The reason for grouped entites is to group entities in more specific ways.
// For example have all drawable entites in one group and then traverse and 
// draw that group only instead of traversing all entities that may not all 
// have draw functions.
class Manager
{
private:

	std::vector<std::unique_ptr<Entity>> entities_;
	std::array<std::vector<Entity*>, max_groups> grouped_entities_;

public:

	Entity& add_entity();
	void update(float mFT);
	void draw();

	// Remove Entities that were marked for deletion in both entities vector 
	// and grouped_entities.
	void refresh();

	void add_to_group(Group mGroup, Entity*);

	std::vector<Entity*>& get_entities_by_group(Group mGroup);
};
#endif
