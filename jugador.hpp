#ifndef JUGADORES_HPP
#define JUGADORES_HPP

#include <SFML/Graphics.hpp>
#include "constantes.hpp"

class Jugador : public sf::Sprite
{
	public:
		sf::Vector2f velocidad;
		sf::Texture jugadorimg;
		Jugador();

		float ladoDerecho();
		float ladoIzquierdo();

		void actualizar();
	private:
		int alto, ancho;
};
#endif