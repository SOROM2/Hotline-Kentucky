#ifndef TILEMAP_H
#define TILEMAP_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "TileType.h"

class TileMap : public sf::Drawable, public sf::Transformable
{
private:
	std::vector<std::vector<TileType>> tiles;
	int tileSize;
	sf::Texture tileSet;
	int width;
	int height;
	sf::VertexArray vertices;
	
	void load();

	// From SFML docs
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// apply the transform
		states.transform *= getTransform();

		// apply the tileset texture
		states.texture = &tileSet;

		// draw the vertex array
		target.draw(vertices, states);
	}

public:
	TileMap(std::vector<std::vector<TileType>> startTiles, int startTileSize, sf::Texture startTileset);
	~TileMap();

	void SetTiles(std::vector<std::vector<TileType>> newTiles);
	
};

#endif