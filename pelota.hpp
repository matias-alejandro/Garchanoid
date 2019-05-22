#ifndef PELOTA_HPP
#define PELOTA_HPP

#include <SFML/Graphics.hpp>
#include "constantes.hpp"

class Pelota : public sf::CircleShape
{
	public:
		Pelota();
		void actualizar(float medioJugador, float ladoSuperiorJugador);
		void invertirVertical();
		void invertirHorizontal();
		void tirar();
		
	private:
		sf::Vector2f velocidad;
		enum
		{
			TIRADA,
			SOBRE_JUGADOR
		};
		int estado;
		int const radio = 5;
};
#endif