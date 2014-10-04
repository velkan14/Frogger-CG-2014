#include "Entity.h"

class GameObject : Entity {

public:
	GameObject();
	~GameObject();
	void draw();
	void update(double delta_t);
};