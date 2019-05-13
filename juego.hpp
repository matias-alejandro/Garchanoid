#ifndef JUEGO_HPP
#define JUEGO_HPP

#include <SFML/Graphics.hpp>

#include "jugador.hpp"

class Juego
{
	public:
		Juego();

		void actualizar(sf::RenderWindow &ventana);
		void KeyPressed(sf::Event &evento);
		void KeyReleased(sf::Event &evento);
	private:
		enum
		{
			ItemJuego,
			ItemEditor,
			ItemSalir,
			ItemMenu
		};
		int modo = ItemJuego; //Cambiar a ItemMenu
		Jugador jugador;
		//Menu menu;
};
#endif