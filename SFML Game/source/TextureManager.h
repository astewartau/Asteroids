#pragma once
#include <SFML/Graphics.hpp>


class TextureManager {
public:
	TextureManager() {

	}

	void AddTexture(int textureID, std::string filePath) {
		if (_textureMap.find(textureID) != _textureMap.end()) {
			printf("Texture already loaded (%s)!", filePath);
		} else {
			sf::Texture* texture = new sf::Texture();
			texture->setSmooth(true);
			if (!texture->loadFromFile(filePath)) {
				delete texture;
				printf("Failed to load texture (%s)!", filePath);
			} else {
				_textureMap[textureID] = texture;
			}
		}
	}

	sf::Texture* GetTexture(int textureID) {
		return _textureMap[textureID];
	}


private:
	std::map<int, sf::Texture*> _textureMap;
};