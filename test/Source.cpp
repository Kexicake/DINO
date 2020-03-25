#include <SFML/Graphics.hpp>
#include <random>
//#include <windows.h>

using namespace sf;
int road[4] = { 0, 300, 600, 900 }, y = 140,set = 0;
int cloud1 = 0, cloud2 = 300, cloud3 = 600, cloud4 = 900, y2 = 25;
//5 = 1200
RenderWindow window(VideoMode(720, 200), "Google Dino!");
Event event;
int randRo[4] = { 300 * (rand() % 4),300 * (rand() % 4),300 * (rand() % 4),300 * (rand() % 4) };

int main()
{
	int jump = 0, poz = 145,m = 1, c = 0;
	float timer228 = 0, delay228 = 0.2;
	Texture dino_;
	Clock clock228;
	

	while (window.isOpen())
	{
		float time = clock228.getElapsedTime().asSeconds();
		clock228.restart();
		//int sit = 0;
		timer228 += time;

		
		
		
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
				set = 10;
			}
		} 
		// Установка цвета фона - белый
		window.clear(Color::White);

		dino_.loadFromFile("C:/Users/vladandlexa/Desktop/work/DINO/x64/Debug/Texture/dino.png");
		Sprite dino(dino_);

		if (timer228 > delay228) {
			c++;
			timer228 = 0;
		}

		if (jump == 1) {
			dino.setTextureRect(IntRect(0, 0, 44, 50));
		}
		else if (set >= 1) {
			poz = 160;
			if (c % 2 == 0) {
				dino.setTextureRect(IntRect(0, 50, 55, 31));//текстур у меня нет
			}
			else {
				dino.setTextureRect(IntRect(55+2, 50, 55, 31));
			}
			
				
				set--;
			
		} else if(jump == 0){
			poz = 141;
			if (c % 2 == 0) {
				dino.setTextureRect(IntRect(88, 0, 44, 50));//текстур у меня нет
			}
			else {
				dino.setTextureRect(IntRect(88 + 44, 0, 44, 50));
			}

		}
		

			Texture backgroung;

			// Подгружаем нашу текстуру из файла texture.png
			backgroung.loadFromFile("C:/Users/vladandlexa/Desktop/work/DINO/x64/Debug/Texture/road.png");
			Sprite sprite(backgroung, IntRect(randRo[0], 0, 300, 200));
			sprite.setPosition(road[0], 0); 
			window.draw(sprite);

			Sprite sprite2(backgroung, IntRect(randRo[1], 0, 300, 200));
			sprite2.setPosition(road[1], 0);	 
			window.draw(sprite2);

			Sprite sprite3(backgroung, IntRect(randRo[2], 0, 300, 200));
			sprite3.setPosition(road[2], 0);	 
			window.draw(sprite3);

			Sprite sprite4(backgroung, IntRect(randRo[3], 0, 300, 200));
			sprite4.setPosition(road[3], 0);	 
			window.draw(sprite4);
			
			//Sprite sprite5(texture, IntRect(0, 0, 300, 110));
			//sprite5.setPosition(road5, y);
			// Отрисовка спрайта	 
			//window.draw(sprite5);
			for (int i = 0; i < 4; i++)
			{
				if (road[i] > -290) {
					road[i] -= 2;
				}
				else {
					road[i] = 900;
					randRo[i] = 300 * (rand() % 4);
				}

			}
		

		if (jump == 1) {
			
			if (poz != 90 && m == 1) {
				//Sleep(1);
				poz--;
			}
			if (poz == 90) {
				m = 0;
			}
			if (poz <= 140 && m == 0) {
				if (poz == 140) {
				m = 1;
				jump = 0;
			}
				//Sleep(1);
				poz++;
			}
		} 
		dino.setPosition(3, poz);

		// Отрисовка dino	 
		window.draw(dino);
		
		// Отрисовка окна
		window.display();
	}

}