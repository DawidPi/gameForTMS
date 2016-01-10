#ifndef SRC_GAME_COLLISIONDETECTOR_HPP
#define SRC_GAME_COLLISIONDETECTOR_HPP

#include "../containers/Array1D.hpp"
#include "GameObject.hpp"

namespace Game{

class CollisionDetector{
public:
	template <size_t numOfBullets, size_t numOfObjects>
	void detectAndPropagate(Containers::Array1D<GameObject*, numOfBullets>& bullets,Containers::Array1D<GameObject*, numOfObjects>& objects);
private:
	bool hasCommonArea(const GameObject& firstObject,const GameObject& secondObject);
};

template <size_t numOfBullets, size_t numOfObjects>
void CollisionDetector::detectAndPropagate(Containers::Array1D<GameObject*, numOfBullets>& bullets,Containers::Array1D<GameObject*, numOfObjects>& objects){
	for(size_t currentBulletIdx=0; currentBulletIdx < numOfBullets; ++currentBulletIdx){
		if(bullets[currentBulletIdx] == 0)
			continue;
		for(size_t currentObjectIdx=0; currentObjectIdx < numOfObjects; ++currentObjectIdx){
			if(objects[currentObjectIdx] == 0)
				continue;

			if(bullets[currentBulletIdx] == objects[currentObjectIdx])
				continue;

			if(hasCommonArea(*bullets[currentBulletIdx], *objects[currentObjectIdx])){
				bullets[currentBulletIdx]->onCollision(*objects[currentObjectIdx]);
				objects[currentObjectIdx]->onCollision(*bullets[currentBulletIdx]);
			}
		}
	}
}

}

#endif //SRC_GAME_COLLISIONDETECTOR_HPP
