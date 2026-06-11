#include <SFML/Graphics.hpp>
import std;

std::string readTextFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return "cant open input.txt";
    }
    
    std::string content;
    std::string line;
    while (std::getline(file, line)) {
        content += line + " ";
    }
    return content;
}
int main() {
    std::string message = readTextFromFile("input.txt");
    
    sf::RenderWindow window(sf::VideoMode({800, 200}), "edit input.txt",
                            sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
    
    sf::Font font;
    std::string fontPath = "/usr/share/fonts/TTF/DejaVuSans-Bold.ttf";
    if (!font.openFromFile(fontPath)) {
    
        fontPath = "C:\\Windows\\Fonts\\Arial.ttf";
        if (!font.openFromFile(fontPath)) {
            return -1;
        }
    }
    
    sf::Text text(font, message);
    text.setFillColor(sf::Color::White);
    
    float x = 800;
    float speed = 300.0f;
    sf::Clock clock;
    
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            
            if (const auto* resized = event->getIf<sf::Event::Resized>()) {
                sf::FloatRect viewRect({0, 0}, sf::Vector2f(resized->size));
                window.setView(sf::View(viewRect));
            }
        }
        
        sf::Vector2u windowSize = window.getSize();
        float windowWidth = static_cast<float>(windowSize.x);
        float windowHeight = static_cast<float>(windowSize.y);
        
        unsigned int fontSize = static_cast<unsigned int>(windowHeight / 2.5f);
        text.setCharacterSize(fontSize);
        
        x -= speed * dt;
        
        float textWidth = text.getGlobalBounds().size.x;
        if (x + textWidth < 0) {
            x = windowWidth;
        }
        
        float textHeight = text.getGlobalBounds().size.y;
        float y = (windowHeight / 2.0f) - (textHeight / 2.0f);
        text.setPosition({x, y});
        
        window.clear(sf::Color::Black);
        window.draw(text);
        window.display();
    }
    return 0;
}