#ifndef SRC_GAME_KEYBOARDEVENTMANAGER_HPP_
#define SRC_GAME_KEYBOARDEVENTMANAGER_HPP_

#include "../containers/Array1D.hpp"
#include "GameObject.hpp"
#include "../R_P_KEYBOARD_TMSLAB.h"

namespace Game {

class KeyboardEventManager {
public:
	template <size_t sizeOfContainer>
	void detectAndPropagate(R_P_KEYBOARD_TMSLAB& keyboard, Containers::Array1D<GameObject*, sizeOfContainer>&);
};

template <size_t sizeOfContainer>
void KeyboardEventManager::detectAndPropagate(R_P_KEYBOARD_TMSLAB& keyboard,Containers::Array1D<GameObject*, sizeOfContainer>& objects){
	LOG_INFO("");
	Containers::Array1D<bool, 10> keysPressed(false);

	for(size_t currentObject=0; currentObject < sizeOfContainer ; ++currentObject){
		if(objects[currentObject] == 0)
			continue;

		for(size_t keyChecked=0; keyChecked < 10; ++keyChecked){
			if(keyboard.CheckKey(keyChecked)){
				objects[currentObject]->onButtonPressed(keyChecked);
			}
		}
	}
}

} /* namespace Game */

#endif /* SRC_GAME_KEYBOARDEVENTMANAGER_HPP_ */
