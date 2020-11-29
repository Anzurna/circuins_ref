SoundProducer::SoundProducer()
{
	bufferShooting.loadFromFile("content/sound/laser1.ogg");
}
void SoundProducer::setVolume (GlobalContext &glob)
{
	volume = glob.getVolume();
}
void SoundProducer::playMusic(std::string name)
{
	music.openFromFile("content/sound/" + name + ".ogg");
	music.play();
	music.setVolume(volume);
}
void SoundProducer::soundShoot()
{
	soundShooting.setBuffer(bufferShooting);
	soundShooting.play();
}