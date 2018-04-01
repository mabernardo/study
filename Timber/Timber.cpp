#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Timber!!!", Style::Fullscreen);

    Texture textureBackground;
    textureBackground.loadFromFile("assets/graphics/background.png");

    Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);

    while (window.isOpen())
    {
        // Handle players input
        if (Keyboard::isKeyPressed(Keyboard::Escape))
            window.close();

        // Update the scene

        // Clear everything from last frame
        window.clear();

        // Draw the scene
        window.draw(spriteBackground);

        // Show everything we just drew
        window.display();
    }
    return 0;
}