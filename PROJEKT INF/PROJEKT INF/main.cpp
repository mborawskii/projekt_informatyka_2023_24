//temat 1, scenariusz 1
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "okno");
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
		std::cout << "Blad ladowania pliku czcionki!" << std::endl;

	enum class OKNO { MENU, POZIOMY, PRZEGRALES, WYGRALES, GAME1, GAME2};
	OKNO okno = OKNO::MENU;
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	//MENU
		sf::Texture teksturatlo;
		if (!teksturatlo.loadFromFile("tlo.png")) {
			std::cout << "Blad ladowania pliku tla!" << std::endl;
		}
		sf::Sprite tlo(teksturatlo);

		sf::RectangleShape menu[3];
		for (int i = 0; i < 3; ++i) {
			menu[i].setSize(sf::Vector2f(300.f, 60.f));
			menu[i].setFillColor(sf::Color::White);
			menu[i].setPosition(370.f, 100.f * i + 350.f);
		}

		sf::RectangleShape menu2[3];
		for (int i = 0; i < 3; ++i) {
			menu2[i].setSize(sf::Vector2f(290.f, 50.f));
			menu2[i].setFillColor(sf::Color::Black);
			menu2[i].setPosition(375.f, 100.f * i + 355.f);
		}

		sf::Text menut[3];
		menut[0].setString("Kampania");
		menut[1].setString("Wybor poziomow");
		menut[2].setString("Autorzy");
		for (int i = 0; i < 3; ++i) {
			menut[i].setFont(font);
			menut[i].setCharacterSize(24);
			menut[i].setFillColor(sf::Color::White);
			menut[i].setPosition(380, 100.f * i + 360.f);
		}

	//POZIOMY

		sf::RectangleShape POZIOMY[6];
		for (int i = 0; i < 6; ++i) {
			POZIOMY[i].setSize(sf::Vector2f(300.f, 60.f));
			POZIOMY[i].setFillColor(sf::Color::White);
			POZIOMY[i].setPosition(370.f, 100.f * i + 200.f);
		}

		sf::RectangleShape POZIOMY2[6];
		for (int i = 0; i < 6; ++i) {
			POZIOMY2[i].setSize(sf::Vector2f(290.f, 50.f));
			POZIOMY2[i].setFillColor(sf::Color::Black);
			POZIOMY2[i].setPosition(375.f, 100.f * i + 205.f);
		}

		sf::Text POZIOMYt[6];
		POZIOMYt[0].setString("Powrot");
		POZIOMYt[1].setString("Poziom 1");
		POZIOMYt[2].setString("Poziom 2");
		POZIOMYt[3].setString("Poziom 3");
		POZIOMYt[4].setString("Poziom 4");
		POZIOMYt[5].setString("Poziom 5");
		for (int i = 0; i < 6; ++i) {
			POZIOMYt[i].setFont(font);
			POZIOMYt[i].setCharacterSize(24);
			POZIOMYt[i].setFillColor(sf::Color::White);
			POZIOMYt[i].setPosition(380.f, 100.f * i + 210.f);
		}
	//PRZEGRALES
		sf::RectangleShape przegralesb;
		przegralesb.setSize(sf::Vector2f(1000.f, 1000.f));
		przegralesb.setFillColor(sf::Color::Black);

		sf::Text przegrales;
		przegrales.setString("Przegrales :(");
		przegrales.setFont(font);
		przegrales.setCharacterSize(50);
		przegrales.setFillColor(sf::Color::White);
		przegrales.setPosition(350.f, 400.f);
	//WYGRALES
		sf::RectangleShape wygralesb;
		wygralesb.setSize(sf::Vector2f(1000.f, 1000.f));
		wygralesb.setFillColor(sf::Color::Black);

		sf::Text wygrales;
		wygrales.setString("Wygrales :)");
		wygrales.setFont(font);
		wygrales.setCharacterSize(50);
		wygrales.setFillColor(sf::Color::White);
		wygrales.setPosition(350.f, 400.f);
	//GAME1
		sf::Texture statek1;
		if (!statek1.loadFromFile("statek.png")) {
			std::cout << "Blad ladowania pliku statku!" << std::endl;
		}
		sf::Sprite statek(statek1);
		statek.setPosition(450.f, 850.f);

		sf::Texture enemy1;
		if (!enemy1.loadFromFile("enemy1.png")) {
			std::cout << "Blad ladowania pliku enemy1!" << std::endl;
		}
		sf::Sprite wrog1(enemy1);

		std::vector<sf::Vector2f> positions1;
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 3; ++j) {
				positions1.push_back(sf::Vector2f(30 + 80 * i, 50 + 80 * j));
			}
		}
		std::vector<sf::Vector2f> positions;
		positions = positions1;
		sf::Vector2f invisibleEnemyPosition(500.f, -10000.f); // Przyk³adowa pozycja poza obszarem gry
		positions.push_back(invisibleEnemyPosition);

		sf::RectangleShape pocisk(sf::Vector2f(10.f, 10.f));
		pocisk.setFillColor(sf::Color::Red);
		std::vector<sf::RectangleShape> bullets;

		std::vector<sf::RectangleShape> bullets1;


		float cooldown = 10.f; // Prêdkoœæ strzelania 10.f
		float s0 = 0.01f;	  // Prêdkoœæ ruchu enemy 0.01f
		int p0 = 5000;

		int p = p0;
		float s = s0;
		float vex = s;
		float vey = s;
		float times = 0.0f;
		int score = 0;

		enum class STANRUCHU {Right1,Down1,Left1,Down2,Right2,Down3,Left2,Down4,Right3,End};
		STANRUCHU stanruchu = STANRUCHU::Right1;


		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed){
					window.close();
				}
				if (event.type == sf::Event::MouseButtonPressed && okno == OKNO::MENU) {
					if (event.mouseButton.button == sf::Mouse::Left) {
						sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
						if (menu[0].getGlobalBounds().contains(mousePos)) {
							okno = OKNO::GAME1;
						}
						if (menu[1].getGlobalBounds().contains(mousePos)) {
							okno = OKNO::POZIOMY;
						}
					}
				}
				if (event.type == sf::Event::MouseButtonPressed && okno == OKNO::POZIOMY) {
					if (event.mouseButton.button == sf::Mouse::Left) {
						sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
						if (POZIOMY[0].getGlobalBounds().contains(mousePos)) {
							okno = OKNO::MENU;
						}
						if (POZIOMY[1].getGlobalBounds().contains(mousePos)) {
							okno = OKNO::GAME1;
						}
						if (POZIOMY[2].getGlobalBounds().contains(mousePos)) {
							okno = OKNO::GAME2;
							score = 28;
						}
		
					}
				}
				if (event.type == sf::Event::MouseButtonPressed && okno == OKNO::PRZEGRALES) {
					if (event.mouseButton.button == sf::Mouse::Left) {
						sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
						if (przegralesb.getGlobalBounds().contains(mousePos)) {
							okno = OKNO::MENU;
						}
					}
				}
				if (event.type == sf::Event::MouseButtonPressed && okno == OKNO::WYGRALES) {
					if (event.mouseButton.button == sf::Mouse::Left) {
						sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
						if (wygralesb.getGlobalBounds().contains(mousePos)) {
							okno = OKNO::GAME2;
						}
					}
				}

			}

			if (okno == OKNO::MENU) {
				score = 0;
				stanruchu = STANRUCHU::Right1;
				for (int i = 0; i < 27; ++i) {
					wrog1.setPosition(positions1[i]);
					positions[i] = positions1[i];
				}
				window.clear();
				window.draw(tlo);
				window.draw(menu[0]);
				window.draw(menu[1]);
				window.draw(menu[2]);
				window.draw(menu2[0]);
				window.draw(menu2[1]);
				window.draw(menu2[2]);
				window.draw(menut[0]);
				window.draw(menut[1]);
				window.draw(menut[2]);
				window.display();
			}
			if (okno == OKNO::POZIOMY) {
				window.clear();
				window.draw(POZIOMY[0]);
				window.draw(POZIOMY[1]);
				window.draw(POZIOMY[2]);
				window.draw(POZIOMY[3]);
				window.draw(POZIOMY[4]);
				window.draw(POZIOMY[5]);

				window.draw(POZIOMY2[0]);
				window.draw(POZIOMY2[1]);
				window.draw(POZIOMY2[2]);
				window.draw(POZIOMY2[3]);
				window.draw(POZIOMY2[4]);
				window.draw(POZIOMY2[5]);

				window.draw(POZIOMYt[0]);
				window.draw(POZIOMYt[1]);
				window.draw(POZIOMYt[2]);
				window.draw(POZIOMYt[3]);
				window.draw(POZIOMYt[4]);
				window.draw(POZIOMYt[5]);
				window.display();
			}
			if (okno == OKNO::PRZEGRALES) {
				window.clear();
				window.draw(przegralesb);
				window.draw(przegrales);
				window.display();
			}
			if (okno == OKNO::WYGRALES) {
				window.clear();
				window.draw(wygralesb);
				window.draw(wygrales);
				window.display();
			}
			if (okno == OKNO::GAME1 || okno == OKNO::GAME2) {
				window.clear();
				if (okno == OKNO::GAME1){
					s = s0;
					p= p0;
				}
				if (okno == OKNO::GAME2) {
					s = s0*2;
					p = p0 / 2;
				}

			//ruch statkiem
				float v = 0.3f;
				if (statek.getPosition().x >= 0) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
						statek.move(-v, 0);
					}
				}
				if (statek.getPosition().x <= 850) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
						statek.move(v, 0);
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					statek.move(0, 0);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					statek.move(0, 0);
				}

			//pociski statku
				if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
					if (times >= cooldown) {
						sf::RectangleShape bullet = pocisk;
						bullet.setPosition(statek.getPosition().x + 65.f, statek.getPosition().y);
						bullets.push_back(bullet);
						times = 0.0f;
					}
				}
				times += 0.01f;
				for (size_t i = 0; i < bullets.size(); ++i) {
					bullets[i].move(0, -0.2f);
					window.draw(bullets[i]);
					if (bullets[i].getPosition().y < 0) {
						bullets.erase(bullets.begin() + i);
					}
				}

			//ruch enemy
				for (int i = 0; i < 27; ++i) {
					switch (stanruchu) {
					case STANRUCHU::Right1:
						window.draw(wrog1);
						wrog1.setPosition(positions[i]);
						positions[i].x += s;
						positions.push_back(invisibleEnemyPosition);
						if (positions[i].x >= window.getSize().x - 75.f) {
							stanruchu = STANRUCHU::Down1;
						}
						break;
					case STANRUCHU::Down1:
						window.draw(wrog1);
						wrog1.setPosition(positions[i]);
						positions[i].y += s;
						if (positions[i].y >= 430.f) {
							stanruchu = STANRUCHU::Left1;
						}
						break;
					case STANRUCHU::Left1:
						window.draw(wrog1);
						wrog1.setPosition(positions[i]);
						positions[i].x -= s;
						if (positions[i].x <= 30) {
							stanruchu = STANRUCHU::Down2;
						}
						break;
					case STANRUCHU::Down2:
						window.draw(wrog1);
						wrog1.setPosition(positions[i]);
						positions[i].y += s;
						if (positions[i].y >= 630.f) {
							stanruchu = STANRUCHU::Right2;
						}
						break;
					case STANRUCHU::Right2:
						window.draw(wrog1);
						wrog1.setPosition(positions[i]);
						positions[i].x += s;
						if (positions[i].x >= window.getSize().x - 75.f) {
							stanruchu = STANRUCHU::Down3;
						}
						break;
					case STANRUCHU::Down3:
						window.draw(wrog1);
						wrog1.setPosition(positions[i]);
						positions[i].y += s;
						if (positions[i].y >= 830.f) {
							stanruchu = STANRUCHU::Left2;
						}
						break;
					case STANRUCHU::Left2:
						window.draw(wrog1);
						wrog1.setPosition(positions[i]);
						positions[i].x -= s;
						if (positions[i].x <= 30) {
							stanruchu = STANRUCHU::Down4;
						}
						break;
					case STANRUCHU::Down4:
						window.draw(wrog1);
						wrog1.setPosition(positions[i]);
						positions[i].y += s;
						if (positions[i].y >= 1030.f) {
							stanruchu = STANRUCHU::Right3;
						}
						break;
					case STANRUCHU::Right3:
						window.draw(wrog1);
						wrog1.setPosition(positions[i]);
						positions[i].x += s;
						if (positions[i].x >= window.getSize().x - 75.f) {
							stanruchu = STANRUCHU::End;
						}
						break;
					case STANRUCHU::End:
						okno = OKNO::PRZEGRALES;
						stanruchu = STANRUCHU::Right1;
						score = 0;
						break;

					}
			//usuwanie pocisku i wroga
					for (size_t j = 0; j < bullets.size(); ++j) {
						if (bullets[j].getGlobalBounds().intersects(wrog1.getGlobalBounds())) {
							bullets.erase(bullets.begin() + j);
							positions.erase(positions.begin() + i);
							score += 1;
							std::cout << score << std::endl;
							break;
						}
					}
			//wygrana1
					if (score == 27) {
						okno = OKNO::WYGRALES;
						stanruchu = STANRUCHU::Right1;
						positions = positions1;
						score += 1;
						bullets.clear();
						bullets1.clear();
					}
					if (score >= 55) {
						okno = OKNO::MENU;
						stanruchu = STANRUCHU::Right1;
						positions = positions1;
						bullets.clear();
						bullets1.clear();
					}
			//przegrana
					if (wrog1.getGlobalBounds().intersects(statek.getGlobalBounds())) {
						okno = OKNO::PRZEGRALES;
						stanruchu = STANRUCHU::Right1;
						std::cout << "b" << std::endl;
						score = 0;
						positions = positions1;
						bullets.clear();
						bullets1.clear();
					}
			//przegrana2
					for (size_t j = 0; j < bullets1.size(); ++j) {
						if (bullets1[j].getGlobalBounds().intersects(statek.getGlobalBounds())) {
							score = 0;
							okno = OKNO::PRZEGRALES;
							/*for (size_t i = 0; i < bullets.size(); ++i) {
								bullets1.erase(bullets1.begin() + i);
							}*/
							bullets.clear();
							bullets1.clear();
							std::cout << "trafiony" << std::endl;
							break;
						}
					}

				}
			//pociski enemy
				if (rand() % p == 1) { // 5% szansy na wystrzelenie pocisku
					int idx = rand() % 27;
					sf::RectangleShape bullet1(sf::Vector2f(5.f, 5.f));
					bullet1.setFillColor(sf::Color::Yellow);
					bullet1.setPosition(positions[idx].x + 20.f, positions[idx].y + 50.f);
					bullets1.push_back(bullet1);
				}
				for (size_t i = 0; i < bullets1.size(); ++i) {
					bullets1[i].move(0.f, 0.05f);
					if (bullets1[i].getPosition().y > window.getSize().y) {
						bullets1.erase(bullets1.begin() + i);
					}
				}
				for (const auto& bullet1 : bullets1) {
					window.draw(bullet1);
				}

				window.draw(statek);
				window.display();
			}
			}
	return 0;
}
