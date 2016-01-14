/*
 * Allocator.hpp
 *
 *  Created on: 14 sty 2016
 *      Author: dpilarsk
 */

#include "../Logger/Logger.h"

#ifndef SRC_CONTAINERS_ALLOCATOR_HPP_
#define SRC_CONTAINERS_ALLOCATOR_HPP_

template <typename T, size_t elements>
class Allocator{
public:
	Allocator() : m_rawPointer(m_rawTab){LOG_INFO("");}
	void*& getRawSpace(){
		LOG_INFO("");
		return m_rawPointer;
	}
private:
	char m_rawTab[sizeof(T)*elements];
	void* m_rawPointer;
};



#endif /* SRC_CONTAINERS_ALLOCATOR_HPP_ */
