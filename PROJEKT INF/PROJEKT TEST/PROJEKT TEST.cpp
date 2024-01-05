#include <SFML/Graphics.hpp>
#include <iostream>

enum class GameState { MENU, GAME }; // Stany aplikacji

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Menu");

    GameState currentState = GameState::MENU; // Pocz¹tkowy stan - menu

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (currentState == GameState::MENU) {
                        // SprawdŸ klikniêcie w obszar prostok¹ta w menu
                        // Jeœli klikniêto w prostok¹t, zmieñ stan aplikacji
                        if (/* warunek klikniêcia w prostok¹t */) {
                            currentState = GameState::GAME; // Zmiana stanu na "gra"
                            // Tutaj mo¿na wykonaæ jakieœ dzia³ania zwi¹zane z przejœciem do nowej czêœci programu
                        }
                    }
                }
            }
        }

        window.clear();

        if (currentState == GameState::MENU) {
            // Rysowanie prostok¹ta jako opcji w menu
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
