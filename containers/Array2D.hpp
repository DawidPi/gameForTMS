#ifndef SRC_CONTAINERS_ARRAY2D_HPP_
#define SRC_CONTAINERS_ARRAY2D_HPP_

#include "Array1D.hpp"
#include "../Logger/Logger.h"

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
		union Data{
			Data(){}
			Data(const Data& rhs){
				for(size_t idx=0; idx < xSize; ++idx)
					rawContainer[idx] = rhs.rawContainer[idx];
			}
			~Data(){}
			Array1D<T,ySize> rawContainer[xSize];
		}m_data;
	};

	template <typename T, size_t xSize, size_t ySize>
	Array2D<T, xSize, ySize>::Array2D(const T& initialValues)
	{
		LOG_INFO("");
		for(size_t currentX=0; currentX < xSize; ++currentX){
			new(m_data.rawContainer + currentX) Array1D<T, ySize>(initialValues);
			LOG_INFO("element: " << currentX << " created");
		}
	}

	template <typename T, size_t xSize, size_t ySize>
	Array2D<T, xSize, ySize>::~Array2D(){
		LOG_INFO("");
		for(size_t currentX=0; currentX < xSize; ++currentX){
			m_data.rawContainer[currentX].~Array1D<T, ySize>();
		}
	}

	template <typename T, size_t xSize, size_t ySize>
	Array1D<T, ySize>& Array2D<T, xSize, ySize>::at(size_t offsetx){
		LOG_INFO("");
		return m_data.rawContainer[offsetx];
	}

	template <typename T, size_t xSize, size_t ySize>
	const Array1D<T, ySize>& Array2D<T, xSize, ySize>::at(size_t offsetx) const{
		LOG_INFO("");
		return m_data.rawContainer[offsetx];
	}

	template <typename T, size_t xSize, size_t ySize>
	Array1D<T, ySize>& Array2D<T, xSize, ySize>::operator [](size_t offset){
		LOG_INFO("");
		return m_data.rawContainer[offset];
	}

	template <typename T, size_t xSize, size_t ySize>
	const Array1D<T, ySize>& Array2D<T, xSize, ySize>::operator [](size_t offset) const{
		LOG_INFO("");
		return m_data.rawContainer[offset];
	}

}

#endif /* SRC_CONTAINERS_ARRAY2D_HPP_ */
