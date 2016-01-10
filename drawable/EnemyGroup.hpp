
#ifndef SRC_DRAWABLE_ENEMYGROUP_HPP_
#define SRC_DRAWABLE_ENEMYGROUP_HPP_

#include "drawable.hpp"
#include "Enemy.hpp"
#include "../containers/Array2D.hpp"

namespace Graphics {

class EnemyGroup: public Drawable {
public:

	EnemyGroup();

	void destroyEnemy(size_t column, size_t row);
	void resurrectEnemy(size_t column, size_t row);

	size_t enemiesInRow(){return 12;}
	size_t enemiesInCol(){return 2;}

	virtual size_t width() const;
	virtual size_t height() const;
	virtual bool at(Point2D<size_t> point) const;

	virtual ~EnemyGroup(){};
private:
	Containers::Array2D<bool, 12, 2> m_enemiesOn;
	Graphics::Enemy m_enemyGraphics;
};

} /* namespace Graphics */

#endif /* SRC_DRAWABLE_ENEMYGROUP_HPP_ */
