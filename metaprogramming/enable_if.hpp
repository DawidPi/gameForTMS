/*
 * enable_if.hpp
 *
 *  Created on: 14 sty 2016
 *      Author: dpilarsk
 */

#ifndef SRC_METAPROGRAMMING_ENABLE_IF_HPP_
#define SRC_METAPROGRAMMING_ENABLE_IF_HPP_

template <bool B, typename T=void>
struct enable_if{};

template <typename T>
struct enable_if<true, T>{
	typedef T type;
};

template <typename T>
struct Type{
	typedef T type;
};


#endif /* SRC_METAPROGRAMMING_ENABLE_IF_HPP_ */
