#include <SFML/Graphics.hpp>
#include <iostream>

enum class GameState { MENU, GAME }; // Stany aplikacji

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Menu");

    GameState currentState = GameState::MENU; // Pocz�tkowy stan - menu

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (currentState == GameState::MENU) {
                        // Sprawd� klikni�cie w obszar prostok�ta w menu
                        // Je�li klikni�to w prostok�t, zmie� stan aplikacji
                        if (/* warunek klikni�cia w prostok�t */) {
                            currentState = GameState::GAME; // Zmiana stanu na "gra"
                            // Tutaj mo�na wykona� jakie� dzia�ania zwi�zane z przej�ciem do nowej cz�ci programu
                        }
                    }
                }
            }
        }

        window.clear();

        if (currentState == GameState::MENU) {
            // Rysowanie prostok�ta jako opcji w menu
            // ...
        }
        else if (currentState == GameState::GAME) {
            // Logika i rysowanie dla stanu "gra"
            // ...
        }

        window.display();
    }

    return 0;
}
