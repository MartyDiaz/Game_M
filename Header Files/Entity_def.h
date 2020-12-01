

/*#include "Component.h"
#include <array>
#include <memory>
#include <bitset>
#include <vector>
*/

#ifndef Entity_DEF_H
#define Entity_DEF_H

//#include "Component.h"

#include "Component.h"
#include <array>
#include <memory>
#include <bitset>
#include <vector>
#include <assert.h>

class Manager;
struct Component;

static constexpr std::size_t max_components{ 32 };
using Component_bit_set = std::bitset<max_components>;
using Component_array = std::array<Component*, max_components>;
using Component_id = std::size_t;

static constexpr std::size_t max_groups{ 32 };
using Group = std::size_t;
using Group_bit_set = std::bitset <max_groups>;


class Manager;

class Entity
{

private:
	//class Manager;

	Manager& manager;

	std::vector<std::unique_ptr<Component>> components;
	bool alive{ true };

	/*
	static constexpr std::size_t max_components{ 32 };
	using Component_bit_set = std::bitset<max_components>;
	using Component_array = std::array<Component*, max_components>;
	using Component_id = std::size_t;

	static constexpr std::size_t max_groups{ 32 };
	using Group = std::size_t;
	using Group_bit_set = std::bitset <max_groups>;
	*/

	Component_array component_array;
	Component_bit_set component_bit_set;
	Group_bit_set group_bit_set;

public:

	Entity(Manager& mManager);
	bool is_alive();
	void destroy();
	void update(float mFT);
	void draw();

	bool has_group(Group mGroup) const noexcept;
	void add_group(Group mGroup) noexcept;
	void del_group(Group mGroup) noexcept;


	// Add a component to the entities component vector. Remember it is a vector of unique pointers
	template <typename T, typename... TArgs>
	T& add_component(TArgs&&... mArgs)
	{
		assert(!has_component<T>());

		T* added_component(new T(std::forward<TArgs>(mArgs)...));

		added_component->entity = this; // Component that we added now has a pointer to parent entity.

		//std::unique_ptr<Component> u_ptr{ added_component }; 

		// Emplace the component we want to add as a unique pointer to the enitities component vector.
		components.emplace_back(std::unique_ptr<Component> {added_component});

		component_array[get_component_type_id<T>()] = added_component;
		component_bit_set[get_component_type_id<T>()] = true;

		added_component->init();

		return *added_component;
	}

	inline Component_id get_unique_component_id() const noexcept
	{

		static Component_id last_id{ 0u };
		return last_id++;

	}

	template <typename T>
	inline Component_id get_component_type_id() const noexcept
	{
		static_assert(std::is_base_of<Component, T>::value, "T must inherit from Component");

		static Component_id type_id{ get_unique_component_id() };
		return type_id;
	}

	template<typename T>
	bool has_component() const
	{
		return component_bit_set[get_component_type_id<T>()];
	}

	template <typename T>
	T& get_component() const
	{
		assert(has_component<T>());
		auto ptr(component_array[get_component_type_id<T>()]);
		return *static_cast<T*>(ptr);
	}

};

#endif