Key::Key()
{
	this -> m_texture.loadFromFile("content/particles/key.png");
	this -> m_shape.setTexture(&m_texture);
	this -> m_shape.setSize({100.0f, 100.0f});
	this -> m_shape.setOrigin(50.0f, 50.0f);
	this -> m_type = 3;
}
void Key::draw(sf::RenderWindow *window)
{
	window -> draw(this -> m_shape);
}