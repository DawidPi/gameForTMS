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
		Array1D(const Array1D& rhs);
		T& at(size_t offset);
		const T& at(size_t offset) const;
		T& operator[](size_t offset);
		const T& operator[](size_t offset) const;
		size_t size(){return _size;}
		~Array1D();
	private:
		Allocator<T, _size> m_spaceForT;
		template <typename U>
		void destroy(U);
		template <typename U>
		void destroy(U*);
		/* unrestricted unions only in C++11
		union Data{
		T rawContainer[_size];
		} m_data; */
		T(& m_tabT)[_size];
	};

	template <typename T, size_t _size>
	template <typename U>
	void Array1D<T, _size>::destroy(U elementToDestroy){
		LOG_INFO("");
		elementToDestroy.~U();
	}

	template <typename T, size_t _size>
	template <typename U>
	void Array1D<T, _size>::destroy(U *){LOG_INFO("");}

	template <typename T, size_t _size>
	Array1D<T, _size>::Array1D(const T& initialValues): m_tabT(reinterpret_cast<T(&)[_size]>(m_spaceForT.getRawSpace())){
		LOG_INFO("");
		for(size_t currentOffset=0; currentOffset < _size; ++currentOffset){
			LOG_INFO("creating element: " << currentOffset);
			new(m_tabT + currentOffset) T(initialValues);
		}
	}

	template <typename T, size_t _size>
	Array1D<T, _size>::~Array1D(){
		LOG_INFO("");
		for(size_t currentOffset=0; currentOffset < _size; ++currentOffset){
			destroy((m_tabT)[currentOffset]);
		}
	}

	template <typename T, size_t _size>
	Array1D<T, _size>::Array1D(const Array1D& rhs) : m_tabT(rhs.m_tabT),
		m_spaceForT(rhs.m_spaceForT){LOG_INFO("");}

	template <typename T, size_t _size>
	T& Array1D<T, _size>::at(size_t offset){
		LOG_INFO("");
		return (m_tabT)[offset];
	}

	template <typename T, size_t _size>
	const T& Array1D<T, _size>::at(size_t offset) const{
		LOG_INFO("");
		return (m_tabT)[offset];
	}

	template <typename T, size_t _size>
	T& Array1D<T, _size>::operator[](size_t offset){
		LOG_INFO("");
		return (m_tabT)[offset];
	}

	template <typename T, size_t _size>
	const T& Array1D<T, _size>::operator[](size_t offset) const {
		LOG_INFO("");
		return (m_tabT)[offset];
	}
}

#include "Array1DBool.hpp"

#endif /* SRC_CONTAINERS_ARRAY1D_HPP_ */
