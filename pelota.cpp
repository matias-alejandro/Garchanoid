#include "pelota.hpp"

/*********************************************************************/
Pelota::Pelota() : sf::CircleShape()
{
	this->estado=SOBRE_JUGADOR;
	this->setRadius(radio);
	this->setPosition(-5,-5);//Fuera del mapa para que no rompa bloques antes de empezar
	this->setFillColor(sf::Color(255,255,255));
	this->velocidad.x = cnst::GLOBAL_VELOCIDAD_PELOTA;
	this->velocidad.y = -cnst::GLOBAL_VELOCIDAD_PELOTA; //Negativo para que al sacar por primera vez vaya para arriba
}
/*********************************************************************/
void Pelota::tirar()
{
	this->estado=TIRADA;
}
/*********************************************************************/
void Pelota::invertirHorizontal()
{
	this->velocidad.x *= -1;
}
/*********************************************************************/
void Pelota::invertirVertical()
{
	this->velocidad.y *= -1;
}
/*********************************************************************/
void Pelota::actualizar(float medioJugador, float ladoSuperiorJugador)
{
	switch(this->estado)
	{
		case TIRADA:
			if(this->getPosition().x-this->radio <= 0 || this->getPosition().x+this->radio >= cnst::GLOBAL_ANCHO_PANTALLA) 
			{
				this->invertirHorizontal();
			}

			if(this->getPosition().y-this->radio <= 0)
			{
				this->invertirVertical();
			}
				
			if(this->getPosition().y+this->radio >= cnst::GLOBAL_ALTO_PANTALLA)
			{
				this->invertirVertical();
				this->estado=SOBRE_JUGADOR;
			}
		break;

		case SOBRE_JUGADOR:
			this->setPosition(medioJugador, ladoSuperiorJugador);
		break;
	}
	this->move(velocidad);
	/*if(this->getGlobalBounds().intersects(jugador.getGlobalBounds()))
	{
		if (this->get_PosX() < objJugador->get_PosMid())
		{
			this->velocidad.x = -cnst::GLOBAL_VELOCIDAD_PELOTA;
		}
		else 
		{
			this->velocidad.x = cnst::GLOBAL_VELOCIDAD_PELOTA;
		}
		this->velocidad.y = -cnst::GLOBAL_VELOCIDAD_PELOTA;
	}*/
}
