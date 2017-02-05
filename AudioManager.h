#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#include <SFML/Audio.hpp>
#include <map>
#include <iostream>

class AudioManager
{
private:
	AudioManager();
	AudioManager(AudioManager& const);
	void operator=(AudioManager& const);

	std::map <std::string, sf::SoundBuffer> buffers;
	std::map <std::string, sf::Sound> sounds;
	std::map <std::string, sf::Music*> musics;

	bool hasSound(std::string _id);
	bool hasMusic(std::string _id);
public:
	static AudioManager& getInstance();

	void addSound(std::string _id);
	void playSound(std::string _id);
	void stopSound(std::string _id);
	void setSoundVolume(int _volume);
	void addMusic(std::string _id);
	void playMusic(std::string _id);
	void stopMusic(std::string _id);
	void setMusicVolume(int _volume);
	void setMusicLoop(std::string _id, bool _val);

	~AudioManager();
};

#endif