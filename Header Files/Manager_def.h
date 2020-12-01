
#ifndef Manager_DEF_H
#define Manager_DEF_H

#include <vector>
#include <memory>
#include <bitset>

class Entity;

class Manager
{
private:
	
	std::vector<std::unique_ptr<Entity>> entities;
	std::array<std::vector<Entity*>, max_groups> grouped_entities;

public:

	Entity& add_entity();
	void update(float mFT);
	void draw();
	void refresh();

	void add_to_group(Group mGroup, Entity*);
	std::vector<Entity*>& get_entities_by_group(Group mGroup);
};
#endif
