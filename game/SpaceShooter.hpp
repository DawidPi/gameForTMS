#ifndef SRC_GAME_SPACESHOOTER_HPP_
#define SRC_GAME_SPACESHOOTER_HPP_

#include "../R_P_KEYBOARD_TMSLAB.h"
#include "../R_P_LCD_TMSLAB.h"
#include "../R_P_LEDBAR_TMSLAB.h"
#include "GameObject.hpp"
#include "../containers/Array1D.hpp"
#include "GameObjectsManager.hpp"
#include "../display/display.hpp"
#include "../containers/Array1D.hpp"
#include "Enemy.hpp"

namespace Game {

class SpaceShooter {
public:
	SpaceShooter(R_P_KEYBOARD_TMSLAB& keyboard, R_P_LCD_TMSLAB& lcd,
			R_P_LEDBAR_TMSLAB ledbar, Display& display) : m_keyboard(keyboard), m_lcd(lcd),
			m_ledBar(ledbar), m_display(display){}

	void start();
private:
	void initEnemies(Containers::Array2D<Enemy, 11,2>&, GameObjectsManager& manager);
	template <size_t sizeOfContainer>
	void drawObjectsFromContainer(const Containers::Array1D<GameObject*, sizeOfContainer>&);
	R_P_KEYBOARD_TMSLAB& m_keyboard;
	R_P_LCD_TMSLAB& m_lcd;
	R_P_LEDBAR_TMSLAB& m_ledBar;
	Display& m_display;
};

template <size_t sizeOfContainer>
void SpaceShooter::drawObjectsFromContainer(const Containers::Array1D<GameObject*, sizeOfContainer>& container){
	for(size_t currentObjIdx=0; currentObjIdx < sizeOfContainer; ++currentObjIdx){
		if(0 == container[currentObjIdx])
			continue;

		m_display.draw(container[currentObjIdx]->graphics(), container[currentObjIdx]->position());
	}
}

} /* namespace Game */


#endif /* SRC_GAME_SPACESHOOTER_HPP_ */
