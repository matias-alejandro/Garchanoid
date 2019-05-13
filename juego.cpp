#include "juego.hpp"

/*********************************************************************/
Juego::Juego()
{
	//this->menu.agregarOpcion("Jugar");
	//this->menu.agregarOpcion("Editor");
	//this->menu.agregarOpcion("Salir");
}
/*********************************************************************/
void Juego::actualizar(sf::RenderWindow &ventana)
{
	switch(modo)
	{
		case ItemJuego:
			this->jugador.actualizar();
			ventana.draw(this->jugador);
		break;

		case ItemEditor:
			//ventana.draw(this->);
		break;

		case ItemMenu:
			//this->menu.actualizar(ventana);
		break;

		case ItemSalir:
			ventana.close();
		break;
	}
}
/*********************************************************************/
void Juego::KeyPressed(sf::Event &evento)
{
}
/*********************************************************************/
void Juego::KeyReleased(sf::Event &evento)
{
}
/*********************************************************************/