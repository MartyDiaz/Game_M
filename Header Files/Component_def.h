#ifndef Component_Def_H
#define Component_Def_H

class Entity;
struct Component
{
private:
	
public:
	Entity* entity{ nullptr };
	virtual ~Component();
	virtual void init();
	virtual void draw();
	virtual void update(float mFT);
};

#endif

