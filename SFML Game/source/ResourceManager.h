#pragma once
#include <SFML/Graphics.hpp>

class ResourceManager {
public:
	sf::Texture* GetTexture(std::string filePath) {
		if (_textureMap.find(filePath) == _textureMap.end()) {
			sf::Texture* texture = new sf::Texture();
			texture->setSmooth(true);
			if (!texture->loadFromFile(filePath)) {
				delete texture;
				printf("Failed to load texture (%s)!", filePath);
			} else {
				_textureMap[filePath] = texture;
			}
		}
		return _textureMap[filePath];
	}

	sf::Font* GetFont(std::string filePath) {
		if (_fontMap.find(filePath) == _fontMap.end()) {
			sf::Font* font = new sf::Font();
			if (!font->loadFromFile(filePath)) {
				delete font;
				printf("Failed to load font (%s)!", filePath);
			} else {
				_fontMap[filePath] = font;
			}
		}
		return _fontMap[filePath];
	}

private:
	std::map<std::string, sf::Texture*> _textureMap;
	std::map<std::string, sf::Font*> _fontMap;


public:
	static ResourceManager& GetInstance() {
		static ResourceManager instance;
		return instance;
	}
	ResourceManager(ResourceManager const&) = delete;
	void operator=(ResourceManager const&) = delete;
private:
	ResourceManager() {
	}
};