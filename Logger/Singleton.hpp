/*
 * Singleton.hpp
 *
 *  Created on: 14 sty 2016
 *      Author: dpilarsk
 */

#ifndef SRC_LOGGER_SINGLETON_HPP_
#define SRC_LOGGER_SINGLETON_HPP_

template <typename InheritingClass>
class Singleton{
public:
	static InheritingClass& instance(){
		static InheritingClass singletonClass;
		return singletonClass;
	}
protected:
	Singleton(){};
	Singleton(const Singleton&){};
	const Singleton& operator= (const Singleton&);
};



#endif /* SRC_LOGGER_SINGLETON_HPP_ */
