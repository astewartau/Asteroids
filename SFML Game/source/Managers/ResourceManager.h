#pragma once
#include <SFML/Graphics.hpp>
#include "Collision.h"

class ResourceManager {
public:
	ResourceManager() {}

	~ResourceManager() {
		for (std::map<std::string, sf::Texture*>::iterator itr = _textureMap.begin(); itr != _textureMap.end(); itr++) {
			delete itr->second;
		}

		for (std::map<std::string, sf::Font*>::iterator itr = _fontMap.begin(); itr != _fontMap.end(); itr++) {
			delete itr->second;
		}
	}

	sf::Texture* GetTexture(std::string filePath) {
		if (_textureMap.find(filePath) == _textureMap.end()) {

			sf::Texture* texture = new sf::Texture();
			if (!Collision::CreateTextureAndBitmask(*texture, filePath)) {
				delete texture;
				printf("Failed to load texture (%s)!", filePath.c_str());
			} else {
				_textureMap[filePath] = texture;
			}

			texture->setSmooth(true);
		}
		return _textureMap[filePath];
	}

	sf::Font* GetFont(std::string filePath) {
		if (_fontMap.find(filePath) == _fontMap.end()) {
			sf::Font* font = new sf::Font();
			if (!font->loadFromFile(filePath)) {
				delete font;
				printf("Failed to load font (%s)!", filePath.c_str());
			} else {
				_fontMap[filePath] = font;
			}
		}
		return _fontMap[filePath];
	}

private:
	std::map<std::string, sf::Texture*> _textureMap;
	std::map<std::string, sf::Font*> _fontMap;
};
