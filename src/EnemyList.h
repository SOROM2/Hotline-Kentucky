#ifndef ENEMYLIST_H
#define ENEMYLIST_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "EntityList.h"
#include "Enemy.h"
#include "EnemyState.h"

class EnemyList : public EntityList {

    public:
        EnemyList();
        ~EnemyList();
        void Draw(sf::RenderWindow* window, const std::vector<std::vector<bool>>& fogOfWar);
        void Shoot(sf::RectangleShape& rect);
        void DeleteDead();
};

#endif