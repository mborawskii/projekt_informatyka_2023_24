#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "okno");
	sf::Font font;
	if (!font.loadFromFile("C:/Users/user/source/repos/PROJEKT INF/arial.ttf"))
		std::cout << "Blad ladowania pliku czcionki!" << std::endl;

	enum class GameState { MENU, GAME1 };
	GameState currentState = GameState::MENU;

	//MENU
		sf::Texture teksturatlo;
		if (!teksturatlo.loadFromFile("C:/Users/user/source/repos/PROJEKT INF/tlo.png")) {
			std::cout << "Blad ladowania pliku tla!" << std::endl;
		}
		sf::Sprite tlo(teksturatlo);

		sf::RectangleShape menu[4];
		for (int i = 0; i < 4; ++i) {
			menu[i].setSize(sf::Vector2f(300.f, 60.f));
			menu[i].setFillColor(sf::Color::Blue);
			menu[i].setPosition(370.f, 100.f * i + 350.f);
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

		//GAME
		sf::Texture statek1;
		if (!statek1.loadFromFile("C:/Users/user/source/repos/PROJEKT INF/statek.png")) {
			std::cout << "Blad ladowania pliku statku!" << std::endl;
		}
		sf::Sprite statek(statek1);
		statek.setPosition(450.f, 850.f);

		sf::Texture enemy1;
		if (!enemy1.loadFromFile("C:/Users/user/source/repos/PROJEKT INF/enemy1.png")) {
			std::cout << "Blad ladowania pliku enemy1!" << std::endl;
		}
		sf::Sprite wrog1(enemy1);
		std::vector<sf::Vector2f> positions;
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 3; ++j) {
				positions.push_back(sf::Vector2f(80 * i, 50 + 80 * j));
			}
		}
		float vex = 0.05f;
		float vey = 0.05f;

		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed){
					window.close();
				}

				if (event.type == sf::Event::MouseButtonPressed) {
					if (event.mouseButton.button == sf::Mouse::Left) {
						sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
						if (menu[0].getGlobalBounds().contains(mousePos)) {
							currentState = GameState::GAME1;
						}
					}
				}
			}

			if (currentState == GameState::GAME1) {
				float v = 0.3f;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
					statek.move(-v, 0);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
					statek.move(v, 0);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					statek.move(0, -v);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					statek.move(0, v);
				}
				
				window.clear();

				for (int i = 0; i < 27; ++i) {
					window.draw(wrog1);

					//// ruch w prawo
					//positions[i].x += vex;
					//wrog1.setPosition(positions[i]);
					//	if (positions[i].x + wrog1.getGlobalBounds().width +50.f>= window.getSize().x) {
					//		vex = 0;

					////ruch w dó³
					//		for (int j = 0; j < 27; ++j) {
					//			positions[j].y += vey;
					//		}
					//	}
					//	if (positions[i].y + wrog1.getGlobalBounds().height + 510.f >= window.getSize().y) {
					//		vey = 0;
					//			// Ruch w lewo
					//				for (int j = 0; j < 27; ++j) {
					//					positions[j].x -= vex;
					//				}
					//	}
					//	if (positions[i].x <= 0) {
					//		vex = 0;
					//	}

					if (positions[i].x + wrog1.getGlobalBounds().width + 50.f <= window.getSize().x && positions[i].y + wrog1.getGlobalBounds().height <= 500) {
						positions[i].x += vex;
						wrog1.setPosition(positions[i]);
					}
					
				}
				//&& wrog1.getGlobalBounds().height >= 300.f
				//+ wrog1.getGlobalBounds().width
				//&& positions[i].y + wrog1.getGlobalBounds().width >= 500
				window.draw(statek);
				window.display();

			}

			if (currentState == GameState::MENU) {
				window.clear();
				window.draw(tlo);
				window.draw(menu[0]);
				window.draw(menu[1]);
				window.draw(menu[2]);
				window.draw(menut[0]);
				window.draw(menut[1]);
				window.draw(menut[2]);
				window.display();
			}
		}
	return 0;
}
