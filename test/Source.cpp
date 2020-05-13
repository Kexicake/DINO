#include <SFML/Graphics.hpp>
#include <random>
//#include <windows.h>

using namespace sf;

int road[4] = { 0, 300, 600, 900 };
int randRo[4] = { 
	300 * (rand() % 4),300 * (rand() % 4),300 * (rand() % 4),300 * (rand() % 4) 
};
int jump = 0, gop_stop = 0, y = 140, poz = 145, m = 1, c = 0, y_Ka = 132;
float timer = 0, delay = 0.1;
int kaktysArr[12]{
	0,80,160,240,320,400,480,560,640,720,800,880
};
int randKa[12] = {
	29 * 3,29 * 3, 29 * 3, 29 * 3, 29 * 3, 29 * 3, 29 * 3, 29 * 3, 29 * 3,29 * (rand() % 5),29 * (rand() % 5)
};




RenderWindow window(VideoMode(720, 200), "Google Dino!");
Event event;

void jumping() {
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
}
void background() {
	Texture backgroung;
	window.clear(Color::White);
	backgroung.loadFromFile("Texture/road.png");
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
}
void kaktysu() {
	Texture kaktys;
	
	kaktys.loadFromFile("Texture/cactus.png");
	Sprite sprite(kaktys, IntRect(randKa[0], 0, 29, 59));
	sprite.setPosition(kaktysArr[0], y_Ka);
	if (!(kaktysArr[0] > 29)) {
		window.draw(sprite);
	}

	Sprite sprite2(kaktys, IntRect(randKa[1], 0, 29, 59));
	sprite2.setPosition(kaktysArr[1], y_Ka);
	if (!(randKa[1] > 29)) {
		window.draw(sprite2);
	}

	Sprite sprite3(kaktys, IntRect(randKa[2], 0, 29, 59));
	sprite3.setPosition(kaktysArr[2], y_Ka);
	if (!(randKa[2] > 29)) {
		window.draw(sprite3);
	}

	Sprite sprite4(kaktys, IntRect(randKa[3], 0, 29, 59));
	sprite4.setPosition(kaktysArr[3], y_Ka);
	if (!(randKa[3] > 29)) {
		window.draw(sprite4);
	}

	Sprite sprite5(kaktys, IntRect(randKa[4], 0, 29, 59));
	sprite5.setPosition(kaktysArr[4], y_Ka);
	if (!(randKa[4] > 29)) {
		window.draw(sprite5);
	}

	Sprite sprite6(kaktys, IntRect(randKa[5], 0, 29, 59));
	sprite6.setPosition(kaktysArr[5], y_Ka);
	if (!(randKa[5] > 29)) {
		window.draw(sprite6);
	}

	Sprite sprite7(kaktys, IntRect(randKa[6], 0, 29, 59));
	sprite7.setPosition(kaktysArr[6], y_Ka);
	if (!(randKa[6] > 29)) {
		window.draw(sprite7);
	}

	Sprite sprite8(kaktys, IntRect(randKa[7], 0, 29, 59));
	sprite8.setPosition(kaktysArr[7], y_Ka);
	if (!(randKa[7] > 29)) {
		window.draw(sprite8);
	}

	Sprite sprite9(kaktys, IntRect(randKa[8], 0, 29, 59));
	sprite9.setPosition(kaktysArr[8], y_Ka);
	if (!(randKa[8] > 29)) {
		window.draw(sprite9);
	}

	Sprite sprite10(kaktys, IntRect(randKa[9], 0, 29, 59));
	sprite10.setPosition(kaktysArr[9], y_Ka);
	if (!(randKa[9] > 29)) {
		window.draw(sprite10);
	}

	Sprite sprite11(kaktys, IntRect(randKa[10], 0, 29, 59));
	sprite11.setPosition(kaktysArr[10], y_Ka);
	if (!(randKa[10] > 29)) {
		window.draw(sprite11);
	}

	Sprite sprite12(kaktys, IntRect(randKa[11], 0, 29, 59));
	sprite12.setPosition(randKa[11], y_Ka);
	if (!(kaktysArr[11] > 29)) {
			window.draw(sprite12);
	}
	

	for (int i = 0; i < 12; i++)
	{
		if (kaktysArr[i] > -70) {
			kaktysArr[i] -= 2;
		}
		else {
			kaktysArr[i] = 880;
			randKa[i] = 29 * (rand() % 5);
		}

	}
}
int main()
{
	Clock clock;
	while (window.isOpen())
	{
		Texture dino_;
		dino_.loadFromFile("Texture/dino.png");
		Sprite dino(dino_);

		//для бега таймер смены ног
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;
		if (timer > delay) {
			c++;
			timer = 0;
		}

		background();

			//Events ёптать
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
				gop_stop = 10;
			}
		} 
		
		//текстуры дино во время бега и приседания и прыжка
		if (jump == 1) {
			dino.setTextureRect(IntRect(0, 0, 44, 50));
		}
		else if (gop_stop >= 1) {
			poz = 160;
			if (c % 2 == 0) {
				dino.setTextureRect(IntRect(0, 50, 55, 31));//текстур у меня нет
			}
			else {
				dino.setTextureRect(IntRect(55+2, 50, 55, 31));
			}
			gop_stop--;
			
		}
		else if (jump == 0) {
			poz = 141;
			if (c % 2 == 0) {
				dino.setTextureRect(IntRect(88, 0, 44, 50));//текстур у меня нет
			}
			else {
				dino.setTextureRect(IntRect(88 + 44, 0, 44, 50));
			}
		}

		kaktysu();
		jumping();
		dino.setPosition(3, poz);
		// Отрисовка dino	 
		window.draw(dino);
		
		// Отрисовка окна
		window.display();
	}
}