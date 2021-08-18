#include "Counter_Component.h"

Counter_Component::Counter_Component(float counter) : counter_(counter)
{

}

void Counter_Component::draw()
{
	
}

void Counter_Component::update(float mFT)
{
	counter_++;
	std::cout << counter_ << "\n";
}

void Counter_Component::init()
{

}
