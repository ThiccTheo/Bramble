#pragma once
#include <iostream>
#include <unordered_map>

#include "../../Include/CommonSFML.hpp"

enum class TextureId {};

enum class SoundBufferId {};

enum class FontId {};


class ResourceManager
{
public:
	static std::unordered_map<TextureId, sf::Texture> textureMap;
	static std::unordered_map<SoundBufferId, sf::SoundBuffer> soundBufferMap;
	static std::unordered_map<FontId, sf::Font> fontMap;

	static const bool load();
};

