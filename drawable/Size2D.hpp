#ifndef SRC_DRAWABLE_SIZE2D_HPP_
#define SRC_DRAWABLE_SIZE2D_HPP_

#include "Point2D.hpp"

namespace Graphics{

	template <typename T>
	class Size2D : public Point2D<T>{
	public:
		T area() const {return width() * height();}
	};

}

#endif /* SRC_DRAWABLE_SIZE2D_HPP_ */
