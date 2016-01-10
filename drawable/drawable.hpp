#ifndef SRC_DRAWABLE_DRAWABLE_HPP_
#define SRC_DRAWABLE_DRAWABLE_HPP_

#include <cstdlib>
#include "Point2D.hpp"

namespace Graphics{

	class Drawable{
	public:
		virtual size_t width() const =0;
		virtual size_t height() const =0;
		virtual bool at(Point2D<size_t> point)const =0;
		virtual ~Drawable(){}
	};

}



#endif /* SRC_DRAWABLE_DRAWABLE_HPP_ */
