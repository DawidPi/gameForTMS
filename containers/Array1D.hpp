#ifndef SRC_CONTAINERS_ARRAY1D_HPP_
#define SRC_CONTAINERS_ARRAY1D_HPP_

#include <stdint.h>
#include <cstddef>
#include <new>
#include "Allocator.hpp"

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
		Allocator<T, _size> spaceForT;
		/* unrestricted unions only in C++11
		union Data{
		T rawContainer[_size];
		} m_data; */

		char m_rawMemory[sizeof(T) * _size];
		T(& m_tabT)[_size];
	};

	template <typename T, size_t _size>
	Array1D<T, _size>::Array1D(const T& initialValues): m_tabT(reinterpret_cast<T(&)[_size]>(spaceForT.getRawSpace())){
		for(size_t currentOffset=0; currentOffset < _size; ++currentOffset){
			new(m_tabT + currentOffset) T(initialValues);
		}
	}

	template <typename T, size_t _size>
	Array1D<T, _size>::~Array1D(){
		for(size_t currentOffset=0; currentOffset < _size; ++currentOffset){
			m_tabT[currentOffset].~T();
		}
	}

	template <typename T, size_t _size>
	Array1D<T, _size>::Array1D(const Array1D& rhs) : m_tabT(rhs.m_tabT),
		m_rawMemory(rhs.m_rawMemory){}

	template <typename T, size_t _size>
	T& Array1D<T, _size>::at(size_t offset){
		return m_tabT[offset];
	}

	template <typename T, size_t _size>
	const T& Array1D<T, _size>::at(size_t offset) const{
		return m_tabT[offset];
	}

	template <typename T, size_t _size>
	T& Array1D<T, _size>::operator[](size_t offset){
		return m_tabT[offset];
	}

	template <typename T, size_t _size>
	const T& Array1D<T, _size>::operator[](size_t offset) const {
		return m_tabT[offset];
	}
}

#include "Array1DBool.hpp"

#endif /* SRC_CONTAINERS_ARRAY1D_HPP_ */
