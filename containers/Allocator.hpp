/*
 * Allocator.hpp
 *
 *  Created on: 14 sty 2016
 *      Author: dpilarsk
 */

#ifndef SRC_CONTAINERS_ALLOCATOR_HPP_
#define SRC_CONTAINERS_ALLOCATOR_HPP_

template <typename T, size_t elements>
class Allocator{
public:
	void* getRawSpace(){
		return rawTab;
	}
private:
	char rawTab[sizeof(T)*elements];
};



#endif /* SRC_CONTAINERS_ALLOCATOR_HPP_ */
