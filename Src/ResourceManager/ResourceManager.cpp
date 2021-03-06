#include "ResourceManager.hpp"

std::unordered_map<TextureId, sf::Texture> ResourceManager::textureMap;
std::unordered_map<SoundBufferId, sf::SoundBuffer> ResourceManager::soundBufferMap;
std::unordered_map<FontId, sf::Font> ResourceManager::fontMap;

const bool ResourceManager::load()
{
	return true;
}