#ifndef SRC_DRAWABLE_POINT2D_HPP_
#define SRC_DRAWABLE_POINT2D_HPP_

#include "../Logger/Logger.h"

namespace Graphics{

	template <typename T>
	class Point2D{
	public:
		Point2D(T width = 0, T height = 0): m_width(width), m_height(height){};
		T width() const {return m_width;}
		T height() const {return m_height;}
		void setWidth(T width){m_width = width;}
		void setHeight(T height){m_height = height;}

		Point2D operator-(const Point2D& rhs) const;
		const Point2D& operator-=(const Point2D& rhs);
		Point2D operator+(const Point2D& rhs) const;
		const Point2D& operator+=(const Point2D& rhs);

		bool operator==(const Point2D& rhs) const;
	private:
		T m_width;
		T m_height;
	};

	template <typename T>
	Point2D<T> Point2D<T>::operator-(const Point2D<T>& rhs) const{
		LOG_INFO("");
		return Point2D<T>(width()-rhs.width(), height()-rhs.height());
	}

	template <typename T>
	const Point2D<T>& Point2D<T>::operator-=(const Point2D<T>& rhs){
		LOG_INFO("");
		setWidth(width() - rhs.width());
		setHeight(height() - rhs.height());
		return *this;
	}

	template <typename T>
	Point2D<T> Point2D<T>::operator+(const Point2D& rhs) const{
		LOG_INFO("");
		return Point2D<T>(width() + rhs.width(), height() + rhs.height());
	}

	template <typename T>
	const Point2D<T>& Point2D<T>::operator+=(const Point2D& rhs){
		LOG_INFO("");
		setWidth(width + rhs.width());
		setHeight(height() + rhs.height());
		return *this;
	}

	template <typename T>
	bool Point2D<T>::operator ==(const Point2D<T>& rhs) const{
		LOG_INFO("");
		if(width() == rhs.width() && height() == rhs.height())
			return true;

		return false;
	}
}

#endif /* SRC_DRAWABLE_POINT2D_HPP_ */
