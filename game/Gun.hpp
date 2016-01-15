/*
 * Gun.hpp
 *
 *  Created on: 15 sty 2016
 *      Author: dpilarsk
 */

#ifndef SRC_GAME_GUN_HPP_
#define SRC_GAME_GUN_HPP_

#include "GameObject.hpp"

namespace Game {

class Gun {
public:
	Gun(GameObjectsManager* parent);

	virtual ~Gun();
};

} /* namespace Game */

#endif /* SRC_GAME_GUN_HPP_ */
