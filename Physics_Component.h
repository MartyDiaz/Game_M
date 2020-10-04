
#ifndef Physics_Component_H
#define Physics_Component_H

#include "Component.h"
#include <iostream>

struct Physics_Component : Component
{
private:

public:
	Entity* entity{ nullptr };
	
	void draw() override;

	void update(float mFT) override;

	void init() override;

};
#endif
