/*
 * is_pointer.hpp
 *
 *  Created on: 14 sty 2016
 *      Author: dpilarsk
 */

#ifndef SRC_METAPROGRAMMING_IS_POINTER_HPP_
#define SRC_METAPROGRAMMING_IS_POINTER_HPP_

template <typename T>
struct is_pointer_t{
	enum {value = false};
};

template <typename T>
struct is_pointer_t<T*>{
	enum {value=true};
};

template <typename T>
struct is_pointer_t<const T*>{
	enum {value=true};
};

template <typename T>
struct is_pointer_t<volatile T*>{
	enum {value = true};
};

template <typename T>
struct is_pointer_t<const volatile T*>{
	enum {value=true};
};

template <typename T>
bool is_pointer(const T&){
	return is_pointer_t<T>::value;
}


#endif /* SRC_METAPROGRAMMING_IS_POINTER_HPP_ */
