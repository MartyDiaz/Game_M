
#ifndef Manager_DEF_H
#define Manager_DEF_H

#include <vector>
#include <memory>
#include <bitset>

class Entity;

/*static constexpr std::size_t max_groups{ 32 };
using Group = std::size_t;
using Group_bit_set = std::bitset <max_groups>;
*/

class Manager
{
private:
	/*
	static constexpr std::size_t max_groups{ 32 };
	using Group = std::size_t;
	using Group_bit_set = std::bitset <max_groups>;
	*/
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
