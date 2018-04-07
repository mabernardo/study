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

    // Tree sprite
    Texture textureTree;
    textureTree.loadFromFile("assets/graphics/tree.png");
    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);

    // Bee sprite
    Texture textureBee;
    textureBee.loadFromFile("assets/graphics/bee.png");
    Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(0, 800);

    // Is the bee currently moving?
    bool beeActive = false;

    // How fast can the bee fly
    float beeSpeed = 0.0f;

    // Clouds
    Texture textureCloud;
    textureCloud.loadFromFile("assets/graphics/cloud.png");
    Sprite spriteCloud1;
    Sprite spriteCloud2;
    Sprite spriteCloud3;
    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);

    spriteCloud1.setPosition(0, 0);
    spriteCloud2.setPosition(0, 250);
    spriteCloud3.setPosition(0, 500);

    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;

    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;

    Clock clock;

    while (window.isOpen())
    {
        // Handle players input
        if (Keyboard::isKeyPressed(Keyboard::Escape))
            window.close();

        // Update the scene

        // Measure time
        Time dt = clock.restart();

        // Setup the bee
        if (!beeActive)
        {
            // How fast is the bee
            srand((int) time(0));
            beeSpeed = (rand() % 200) + 200;

            // How high is the bee
            srand((int) time(0) * 10);
            float height = (rand() % 500) + 500;
            spriteBee.setPosition(2000, height);
            beeActive = true;
        }
        else
        {
            // Move the bee
            spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), spriteBee.getPosition().y);
            // Has the bee reached the right hand edge of the screen?
            if (spriteBee.getPosition().x < -100)
            {
                beeActive = false;
            }
        }

        // Manage the clouds
        // Cloud 1
        if (!cloud1Active)
        {
            // How fast is the cloud
            srand((int) time(0) * 10);
            cloud1Speed = (rand() % 200);

            // How high is the cloud
            srand((int) time(0) * 10);
            float height = (rand() % 150);
            spriteCloud1.setPosition(-200, height);
            cloud1Active = true;
        }
        else
        {
            spriteCloud1.setPosition(
                    spriteCloud1.getPosition().x + (cloud1Speed * dt.asSeconds()),
                    spriteCloud1.getPosition().y);
            // Has the cloud reached the right hand edge of the screen?
            if (spriteCloud1.getPosition().x > 1920)
            {
                cloud1Active = false;
            }
        }

        // Cloud 2
        if (!cloud2Active)
        {
            // How fast is the cloud
            srand((int) time(0) * 20);
            cloud2Speed = (rand() % 200);

            // How high is the cloud
            srand((int) time(0) * 20);
            float height = (rand() % 300) - 150;
            spriteCloud2.setPosition(-200, height);
            cloud2Active = true;
        }
        else
        {
            spriteCloud2.setPosition(
                    spriteCloud2.getPosition().x + (cloud2Speed * dt.asSeconds()),
                    spriteCloud2.getPosition().y);
            // Has the cloud reached the right hand edge of the screen?
            if (spriteCloud2.getPosition().x > 1920)
            {
                cloud2Active = false;
            }
        }

        // Cloud 3
        if (!cloud3Active)
        {
            // How fast is the cloud
            srand((int) time(0) * 30);
            cloud3Speed = (rand() % 200);

            // How high is the cloud
            srand((int) time(0) * 30);
            float height = (rand() % 450) - 150;
            spriteCloud3.setPosition(-200, height);
            cloud3Active = true;
        }
        else
        {
            spriteCloud3.setPosition(
                    spriteCloud3.getPosition().x + (cloud3Speed * dt.asSeconds()),
                    spriteCloud3.getPosition().y);
            // Has the cloud reached the right hand edge of the screen?
            if (spriteCloud3.getPosition().x > 1920)
            {
                cloud3Active = false;
            }
        }
        // Clear everything from last frame
        window.clear();

        // Draw the scene
        window.draw(spriteBackground);

        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);

        window.draw(spriteTree);

        window.draw(spriteBee);

        // Show everything we just drew
        window.display();
    }
    return 0;
}