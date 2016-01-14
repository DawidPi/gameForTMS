#ifndef SRC_CONTAINERS_ARRAY2D_HPP_
#define SRC_CONTAINERS_ARRAY2D_HPP_

#include "Array1D.hpp"
#include "../Logger/Logger.h"

namespace Containers{

	template <typename T, size_t xSize, size_t ySize>
	class Array2D{
	public:
		Array2D(const T& initialValues= T());
		Array2D(const Array2D& rhs);
		Array1D<T, ySize>& at(size_t offsetx);
		const Array1D<T, ySize>& at(size_t offsetx) const;
		Array1D<T, ySize>& operator[](size_t offset);
		const Array1D<T, ySize>& operator[](size_t offset)const;
		size_t width()const {return xSize;}
		size_t height()const {return ySize;}
		~Array2D();
	private:
		Allocator<Array1D<T, ySize>, xSize> m_spaceForT;
		Array1D<T, ySize>(& m_tabT)[xSize];
	};

	template <typename T, size_t xSize, size_t ySize>
	Array2D<T, xSize, ySize>::Array2D(const Array2D& rhs)
		: m_spaceForT(rhs.m_spaceForT), m_tabT(rhs.m_tabT)
	{
		LOG_INFO("");
	}

	template <typename T, size_t xSize, size_t ySize>
	Array2D<T, xSize, ySize>::Array2D(const T& initialValues)
		: m_tabT(reinterpret_cast<Array1D<T, ySize>(&)[xSize]>(m_spaceForT.getRawSpace()))
	{
		LOG_INFO("");
		for(size_t currentX=0; currentX < xSize; ++currentX){
			new(m_tabT + currentX) Array1D<T, ySize>(initialValues);
			LOG_INFO("element: " << currentX << " created");
		}
	}

	template <typename T, size_t xSize, size_t ySize>
	Array2D<T, xSize, ySize>::~Array2D(){
		LOG_INFO("");
		for(size_t currentX=0; currentX < xSize; ++currentX){
			(m_tabT)[currentX].~Array1D<T, ySize>();
		}
	}

	template <typename T, size_t xSize, size_t ySize>
	Array1D<T, ySize>& Array2D<T, xSize, ySize>::at(size_t offsetx){
		LOG_INFO("");
		return (m_tabT)[offsetx];
	}

	template <typename T, size_t xSize, size_t ySize>
	const Array1D<T, ySize>& Array2D<T, xSize, ySize>::at(size_t offsetx) const{
		LOG_INFO("");
		return (m_tabT)[offsetx];
	}

	template <typename T, size_t xSize, size_t ySize>
	Array1D<T, ySize>& Array2D<T, xSize, ySize>::operator [](size_t offset){
		LOG_INFO("");
		return (m_tabT)[offset];
	}

	template <typename T, size_t xSize, size_t ySize>
	const Array1D<T, ySize>& Array2D<T, xSize, ySize>::operator [](size_t offset) const{
		LOG_INFO("");
		return (m_tabT)[offset];
	}

}

#endif /* SRC_CONTAINERS_ARRAY2D_HPP_ */
