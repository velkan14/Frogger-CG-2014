#include "Vector3.h"
#include <iostream>

int main()
{
	Vector3 vec(1, 1, 1);
	Vector3 vec2(2, 2, 2);

	std::cout << "x:" << vec.getX()<<" y:" << vec.getY() << " z:"<< vec.getZ() << std::endl;
	std::cout << "x:" << vec2.getX()<<" y:" << vec2.getY() << " z:"<< vec2.getZ() << std::endl;
	Vector3 vec3 = vec-vec2;
	vec = vec3;
	std::cout << "x:" << vec.getX()<<" y:" << vec.getY() << " z:"<< vec.getZ() << std::endl;
	system("pause");
	return 0;
}