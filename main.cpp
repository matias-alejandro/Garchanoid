/*********************************************************************
[GARCHANOID - MAIN] MATÍAS DEL PIN 
*********************************************************************/
#include <SFML/Graphics.hpp>
//#include <fstream>
#include "constantes.hpp"
#include "juego.hpp"

/*********************************************************************/
int main()
{
	sf::RenderWindow ventana(sf::VideoMode(cnst::GLOBAL_ANCHO_PANTALLA, cnst::GLOBAL_ALTO_PANTALLA/*+25*/), "Garchanoid");
	sf::Event evento;
	ventana.setVerticalSyncEnabled(true);

	Juego juego;

	while (ventana.isOpen())
	{	
		ventana.clear(sf::Color::Black);

		juego.actualizar(ventana);

		ventana.display();

		while (ventana.pollEvent(evento))
		{
			switch (evento.type)
	   		{
				case evento.Closed:
					ventana.close();
					break;
				case evento.KeyPressed:
					juego.KeyPressed(evento);
					break;
				case evento.KeyReleased:
					juego.KeyReleased(evento);
					break;
				default:
					break;
			}
		}
	}
    return 0;
}
