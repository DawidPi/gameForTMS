#include "CollisionDetector.hpp"

namespace Game{

bool CollisionDetector::hasCommonArea(const GameObject& firstObject, const GameObject& secondObject){
	typedef Graphics::Point2D<size_t> Point;

	const Point position1 = firstObject.position();
	const size_t obj1Width = firstObject.graphics().width();
	const size_t obj1Height = firstObject.graphics().width();

	const Point position2 = secondObject.position();
	const size_t obj2Width = secondObject.graphics().width();
	const size_t obj2Height = secondObject.graphics().height();

	if(0 == obj1Width || 0 == obj1Height)
		return false;

	if(0 == obj2Width || 0 == obj2Height)
		return false;

	if(position1 == position2)
		return true;

	const Point position1LowerLeft = position1;
	const Point position1LowerRight = position1 + Point(firstObject.graphics().width(), 0);
	const Point position1UpperLeft = position1 + Point(0,firstObject.graphics().height());
	//const Point position1UpperRight = position1 + Point(firstObject.graphics().width(),
	//								firstObject.graphics().height());

	const Point position2LowerLeft = position2;
	const Point position2LowerRight = position2 + Point(secondObject.graphics().width(), 0);
	const Point position2UpperLeft = position2 + Point(0,secondObject.graphics().height());
	//const Point position2UpperRight = position2 + Point(secondObject.graphics().width(),
	//								secondObject.graphics().height());



	if(position1LowerLeft.width() >= position2LowerLeft.width() &&
			position1LowerLeft.width() <= position2LowerRight.width() &&
			position1UpperLeft.height() >= position2LowerRight.height())
		return true;

	if(position2LowerLeft.width() >= position1LowerLeft.width() &&
			position2LowerLeft.width() <= position1LowerRight.width() &&
			position2UpperLeft.height() >= position1LowerRight.height())
		return true;

	if(position1LowerLeft.width() >= position2LowerLeft.width() &&
			position1LowerLeft.width() <= position2LowerRight.width() &&
			position1LowerLeft.height() <= position2UpperLeft.height())
		return true;

	if(position2LowerLeft.width() >= position1LowerLeft.width() &&
			position2LowerLeft.width() <= position1LowerRight.width() &&
			position2LowerLeft.height() <= position1UpperLeft.height())
		return true;

	return false;

}

}



