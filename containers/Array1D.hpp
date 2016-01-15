#ifndef SRC_CONTAINERS_ARRAY1D_HPP_
#define SRC_CONTAINERS_ARRAY1D_HPP_

#include <stdint.h>
#include <cstddef>
#include <new>
#include "Allocator.hpp"
#include "../Logger/Logger.h"

namespace Containers{

	template <typename T, size_t _size>
	class Array1D{
	public:
		Array1D(const T& initialValues = T());
		T& at(size_t offset);
		const T& at(size_t offset) const;
		T& operator[](size_t offset);
		const T& operator[](size_t offset) const;
		size_t size(){return _size;}
		~Array1D();
	private:
		template <typename U>
		void destroy(U);
		template <typename U>
		void destroy(U*);
		union Data{
			Data(){}
			Data(const Data& rhs){
				for(size_t idx=0; idx < _size; ++idx)
					rawContainer[idx] = rhs.rawContainer[idx];
			}
			~Data(){}
			T rawContainer[_size];
		}m_data;
	};

	template <typename T, size_t _size>
	template <typename U>
	void Array1D<T, _size>::destroy(U elementToDestroy){
		LOG_DETAILED("");
		elementToDestroy.~U();
	}

	template <typename T, size_t _size>
	template <typename U>
	void Array1D<T, _size>::destroy(U *){LOG_DETAILED("");}

	template <typename T, size_t _size>
	Array1D<T, _size>::Array1D(const T& initialValues){
		LOG_DETAILED("");
		for(size_t currentOffset=0; currentOffset < _size; ++currentOffset){
			LOG_DETAILED("creating element: " << currentOffset);
			new(m_data.rawContainer + currentOffset) T(initialValues);
		}
	}

	template <typename T, size_t _size>
	Array1D<T, _size>::~Array1D(){
		LOG_DETAILED("");
		for(size_t currentOffset=0; currentOffset < _size; ++currentOffset){
			destroy(m_data.rawContainer[currentOffset]);
		}
	}

	template <typename T, size_t _size>
	T& Array1D<T, _size>::at(size_t offset){
		LOG_DETAILED("offset = " << offset);
		if(offset >= _size)
			LOG_ERROR("Out of bounds: " << offset << "/" << _size );
		return m_data.rawContainer[offset];
	}

	template <typename T, size_t _size>
	const T& Array1D<T, _size>::at(size_t offset) const{
		LOG_DETAILED("offset = " << offset);
		if(offset >= _size)
			LOG_ERROR("Out of bounds: " << offset << "/" << _size );
		return m_data.rawContainer[offset];
	}

	template <typename T, size_t _size>
	T& Array1D<T, _size>::operator[](size_t offset){
		LOG_DETAILED("offset = " << offset);
		if(offset >= _size)
			LOG_ERROR("Out of bounds: " << offset << "/" << _size );
		return m_data.rawContainer[offset];
	}

	template <typename T, size_t _size>
	const T& Array1D<T, _size>::operator[](size_t offset) const {
		LOG_DETAILED("offset = " << offset);
		if(offset >= _size)
			LOG_ERROR("Out of bounds: " << offset << "/" << _size );
		return m_data.rawContainer[offset];
	}
}

//#include "Array1DBool.hpp"

#endif /* SRC_CONTAINERS_ARRAY1D_HPP_ */
