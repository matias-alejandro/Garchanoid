#ifndef JUGADORES_HPP
#define JUGADORES_HPP

#include <SFML/Graphics.hpp>
#include "constantes.hpp"
#include "pelota.hpp"

class Jugador : public sf::Sprite
{
	public:
		sf::Vector2f velocidad;
		sf::Texture jugadorimg;
		Jugador();

		float ladoDerecho();
		float ladoIzquierdo();
		float ladoSuperior();
		float mitad();

		void actualizar(sf::RenderWindow &ventana);
		void teclado(sf::Event &evento);
	private:
		Pelota pelota;
		int alto, ancho;
};
#endif