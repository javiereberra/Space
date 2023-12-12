#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode(800, 600), "Space");


	//establecer posicion del objeto//
	Vector2f position(300.0f, 400.0f);

	//establecer velocidad horizontal//
	float velocity(0.0f);
	//establecer aceleracion en 0//
	float acceleration(0.0f);

	//provesar eventos en el bucle//
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		//aumentar la aceleraci�n en cada direcci�n seg�n la tecla presionada

		//EJERCICIO SPACE: la din�mica funciona pero si se presiona demasiado
		//la aceleraci�n aumenta demasiado la velocidad y el c�rculo empieza a rebotar
		//contra los bordes.

			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Key::Right) {

					acceleration += 0.01f;
					//se agrega una salida por consola para controlar la aceleraci�n del objeto
					cout << acceleration << endl;

				}
			}
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Key::Left) {

					acceleration -= 0.01f;
					//se agrega una salida por consola para controlar la aceleraci�n del objeto
					cout << acceleration << endl;
				}
			}
		
		
		}

		//establecer el deltaTime a 60fps//
		float deltaTime = 1.0f / 60.0f;

		//la aceleraci�n aplicada a la velocidad
		velocity += acceleration * deltaTime;

		//aplicar el movimiento ajustando la posici�n a la velocidad//
		position.x += velocity * deltaTime;

		//condicional para que el c�rculo rebote en los l�mites 
		if (position.x >= 750.0f)
		{
			position.x = 749.0f;
			velocity = -velocity;
		}

		if (position.x <= 0.0f)
		{
			position.x = 1.0f;
			velocity = -velocity;
		}


		window.clear();

		CircleShape object;
		object.setRadius(25);
		object.setPosition(position);
		object.setFillColor(Color::Blue);
		window.draw(object);

		window.display();

	}










	return 0;


}