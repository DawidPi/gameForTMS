#ifndef SRC_CONTAINERS_ARRAY2D_HPP_
#define SRC_CONTAINERS_ARRAY2D_HPP_

#include "Array1D.hpp"

namespace Containers{

	template <typename T, size_t xSize, size_t ySize>
	class Array2D{
	public:
		Array2D(const T& initialValues= T());
		Array1D<T, ySize>& at(size_t offsetx);
		const Array1D<T, ySize>& at(size_t offsetx) const;
		Array1D<T, ySize>& operator[](size_t offset);
		const Array1D<T, ySize>& operator[](size_t offset)const;
		size_t width()const {return xSize;}
		size_t height()const {return ySize;}
		~Array2D();
	private:
		Allocator<Array1D<T, ySize>, xSize> m_spaceForT;
		Array1D<T, ySize>(* m_tabT)[xSize];
	};

	template <typename T, size_t xSize, size_t ySize>
	Array2D<T, xSize, ySize>::Array2D(const T& initialValues)
		: m_tabT(static_cast<Array1D<T, ySize>(*)[xSize]>(m_spaceForT.getRawSpace()))
	{
		for(size_t currentX=0; currentX < xSize; ++currentX){
			new(m_tabT + currentX) Array1D<T, ySize>(initialValues);
		}
	}

	template <typename T, size_t xSize, size_t ySize>
	Array2D<T, xSize, ySize>::~Array2D(){
		for(size_t currentX=0; currentX < xSize; ++currentX){
			(*m_tabT)[currentX].~Array1D<T, ySize>();
		}
	}

	template <typename T, size_t xSize, size_t ySize>
	Array1D<T, ySize>& Array2D<T, xSize, ySize>::at(size_t offsetx){
		return (*m_tabT)[offsetx];
	}

	template <typename T, size_t xSize, size_t ySize>
	const Array1D<T, ySize>& Array2D<T, xSize, ySize>::at(size_t offsetx) const{
		return (*m_tabT)[offsetx];
	}

	template <typename T, size_t xSize, size_t ySize>
	Array1D<T, ySize>& Array2D<T, xSize, ySize>::operator [](size_t offset){
		return (*m_tabT)[offset];
	}

	template <typename T, size_t xSize, size_t ySize>
	const Array1D<T, ySize>& Array2D<T, xSize, ySize>::operator [](size_t offset) const{
		return (*m_tabT)[offset];
	}

}

#endif /* SRC_CONTAINERS_ARRAY2D_HPP_ */
