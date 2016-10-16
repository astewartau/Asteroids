#pragma once
#include <SFML/Graphics.hpp>

class ResourceManager {
public:
	ResourceManager() {

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

	void AddFont(int fontID, std::string filePath) {
		if (_fontMap.find(fontID) != _fontMap.end()) {
			printf("Font already loaded (%s)!", filePath);
		}
		else {
			sf::Font* font = new sf::Font();
			
			if (!font->loadFromFile(filePath)) {
				delete font;
				printf("Failed to load font (%s)!", filePath);
			}
			else {
				_fontMap[fontID] = font;
			}
		}
	}

	sf::Font* GetFont(int fontID) {
		return _fontMap[fontID];
	}

private:
	std::map<int, sf::Texture*> _textureMap;
	std::map<int, sf::Font*> _fontMap;
};