#include "jugador.hpp"

/*********************************************************************/
Jugador::Jugador() : sf::Sprite()
{
	if(!jugadorimg.loadFromFile("Imagenes/jugador.png"))
	{
		return;
	}
	jugadorimg.setSmooth(true);
	jugadorimg.setRepeated(false);
	
	this->alto=22;
	this->ancho=120;
	this->setPosition( (cnst::GLOBAL_ANCHO_PANTALLA/2)-(this->ancho/2) , cnst::GLOBAL_ALTO_PANTALLA-this->alto );
	this->setTexture(jugadorimg);
}
/*********************************************************************/
void Jugador::actualizar(sf::RenderWindow &ventana)
{
	this->move(velocidad);

	pelota.actualizar(this->mitad(),this->ladoSuperior());
	ventana.draw(this->pelota);
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->ladoIzquierdo() > 0)
	{
		velocidad.x = -cnst::GLOBAL_VELOCIDAD_JUGADOR;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && this->ladoDerecho() < cnst::GLOBAL_ANCHO_PANTALLA)
	{
		velocidad.x = cnst::GLOBAL_VELOCIDAD_JUGADOR;
	}
	else
	{
		velocidad.x = 0;	
	}
}
/*********************************************************************/
void Jugador::teclado(sf::Event &evento)
{
	if(evento.key.code == sf::Keyboard::W)
	{
		this->pelota.tirar();
	}
}
/*********************************************************************/
float Jugador::ladoDerecho()
{
	return this->getPosition().x+this->ancho;
}
/*********************************************************************/
float Jugador::ladoIzquierdo()
{
	return this->getPosition().x;
}
/*********************************************************************/
float Jugador::ladoSuperior()
{
	return this->getPosition().y-this->alto;
}
/*********************************************************************/
float Jugador::mitad()
{
	return this->getPosition().x+(this->ancho)/2;
}
/*********************************************************************/