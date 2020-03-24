#include <SFML/Graphics.hpp>
#include <windows.h>

using namespace sf;

int main()
{
	int jump = 0, poz = 200,m = 1, c=0;
	float timer228 = 0, delay228 = 0.2;
	Texture dino_;
	Clock clock228;
	RenderWindow window(VideoMode(1024, 200), "Google Dino!");

	// Главный цикл приложения: выполняется, пока открыто окно
	while (window.isOpen())
	{
		float time = clock228.getElapsedTime().asSeconds();
		clock228.restart();
		timer228 += time;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed) {

			}else if (event.key.code == Keyboard::Up) {
				jump = 1;
			}else if (event.key.code == Keyboard::Space) {
				jump = 1;
			}
			else if (event.key.code == Keyboard::Down) {
				if (c % 2 == 0) {
					dino_.loadFromFile("Z:/ИП-4/1Wawwo96YOA.jpg");//текстур у меня нет
				}
				else {
					dino_.loadFromFile("Z:/ИП-4/21tjPdyB30E.jpg");
				}
			}
		}
		// Установка цвета фона - белый
		window.clear(Color::White);

		
		if (timer228 > delay228) {
			c++;
			timer228 = 0;
		}

		//подшрузка текстуры дино и смена тестуры (типо бег)
		if (c % 2 == 0) {
			dino_.loadFromFile("Z:/ИП-4/1Wawwo96YOA.jpg");//текстур у меня нет
		}else {
			dino_.loadFromFile("Z:/ИП-4/21tjPdyB30E.jpg");
		}
		

		// Это дерьмо заставляет прыгать дино
		Sprite dino(dino_);
		if (jump == 1) {
			if (poz != 80 && m == 1) {
				Sleep(1);
				poz--;
			}
			if (poz == 80) {
				m = 0;
			}
			if (poz <= 150 && m == 0) {
				if (poz == 150) {
				m = 1;
				jump = 0;
			}
				Sleep(1);
				poz++;
			}
		}
		dino.setPosition(0, poz);

		// Отрисовка dino	 
		window.draw(dino);
		
		// Отрисовка окна
		window.display();
	}

}