#include <sstream>
#include <SFML/Graphics.hpp>
#include "objects/Cloud.h"

using namespace sf;

void updateBranches(int seed);

const int NUM_CLOUDS = 3;
const int NUM_BRANCHES = 6;
Sprite branches[NUM_BRANCHES];

// Where is the player/branch?
enum class side { LEFT, RIGHT, NONE };
side branchPositions[NUM_BRANCHES];

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
    Cloud clouds[3] {
            Cloud(textureCloud, 0.0f, 0.0f, 0.0f),
            Cloud(textureCloud, 0.0f, 250.0f, 0.0f),
            Cloud(textureCloud, 0.0f, 500.0f, 0.0f)
    };

    Clock clock;

    // Time bar
    RectangleShape timeBar;
    float timeBarStartWidth = 400;
    float timeBarHeight = 80;
    timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
    timeBar.setFillColor(Color::Red);
    timeBar.setPosition((1920 / 2) - timeBarStartWidth / 2, 980);

    Time gameTimeTotal;
    float timeRemaining = 6.0f;
    float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;

    // Track whether the game is running
    bool paused = true;

    // Draw some text
    int score = 0;

    sf::Text messageText;
    sf::Text scoreText;

    // We need to choose a font
    Font font;
    font.loadFromFile("assets/fonts/KOMIKAP_.ttf");

    // Set the font to our message
    messageText.setFont(font);
    scoreText.setFont(font);

    // Assign the actual message
    messageText.setString("Press Enter to start!");
    scoreText.setString("Score = 0");

    // Make it really big
    messageText.setCharacterSize(75);
    scoreText.setCharacterSize(100);

    // Choose a color
    messageText.setColor(Color::White);
    scoreText.setColor(Color::White);

    // Position the text
    FloatRect textRect = messageText.getLocalBounds();

    messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
    scoreText.setPosition(20, 20);

    // Prepare 6 branches
    Texture textureBranch;
    textureBranch.loadFromFile("assets/graphics/branch.png");

    // Set the texture for each branch sprite
    for (auto &branch : branches) {
        branch.setTexture(textureBranch);
        branch.setPosition(-2000, -2000);
        // Set the sprite's origin to dead center
        // We can then spin it around without changing its position
        branch.setOrigin(220, 20);
    }

    updateBranches(1);
    updateBranches(2);
    updateBranches(3);
    updateBranches(4);
    updateBranches(5);

    while (window.isOpen())
    {
        // Handle players input
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Return))
        {
            paused = false;

            // Reset the time and score
            score = 0;
            timeRemaining = 5;
        }

        // Update the scene
        if (!paused) {
            // Measure time
            Time dt = clock.restart();

            // Subtract from the amount of time remaining
            timeRemaining -= dt.asSeconds();
            // size up the time bar
            timeBar.setSize(Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHeight));

            if (timeRemaining <= 0.0f)
            {
                // Pause the game
                paused = true;

                // Change the message shown to the player
                messageText.setString("Out of time!!");

                // Reposition the text based on its new size
                FloatRect textRect = messageText.getLocalBounds();
                messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
                messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
            }

            // Setup the bee
            if (!beeActive) {
                // How fast is the bee
                srand((uint) time(0));
                beeSpeed = (rand() % 200) + 200;

                // How high is the bee
                srand((uint) time(0) * 10);
                float height = (rand() % 500) + 500;
                spriteBee.setPosition(2000, height);
                beeActive = true;
            } else {
                // Move the bee
                spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()),
                                      spriteBee.getPosition().y);
                // Has the bee reached the right hand edge of the screen?
                if (spriteBee.getPosition().x < -100) {
                    beeActive = false;
                }
            }

            // Manage the clouds
            for (int i = 0; i < NUM_CLOUDS; i++)
            {
                if (!clouds[i].isActive())
                {
                    int seed = (i + 1) * 10;

                    // How fast are the clouds
                    srand((unsigned int) time(0) * seed);
                    clouds[i].setSpeed(rand() % 200);

                    // How high are the clouds
                    srand((unsigned int) time(0) * seed);
                    float height = (rand() % ((i + 1) * 175)) - 150;
                    clouds[i].setPosition(-200, height);
                    clouds[i].setActive(true);
                }
                else
                {
                    clouds[i].setPosition(
                            clouds[i].getPosition().x + (clouds[i].getSpeed() * dt.asSeconds()),
                            clouds[i].getPosition().y);
                    if (clouds[i].getPosition().x > 1920) {
                        clouds[i].setActive(false);
                    }
                }
            }

            std::stringstream ss;
            ss << "Score = " << score;
            scoreText.setString(ss.str());

            // update the branch sprites
            for (int i = 0; i < NUM_BRANCHES; i++)
            {
                float height = i * 150;
                if (branchPositions[i] == side::LEFT)
                {
                    // Move the sprite to the left side
                    branches[i].setPosition(610, height);

                    // Flip the sprite round the other way
                    branches[i].setRotation(180);
                }
                else if (branchPositions[i] == side::RIGHT)
                {
                    // Move the sprite to the right side
                    branches[i].setPosition(1330, height);
                    // Set the sprite rotation to normal
                    branches[i].setRotation(0);
                }
                else
                {
                    // Hide the branch
                    branches[i].setPosition(3000, height);
                }
            }
        } // if (!paused) {

        // Draw the scene

        // Clear everything from last frame
        window.clear();
        window.draw(spriteBackground);

        for (Cloud& c: clouds)
        {
            window.draw(c.getSprite());
        }

        window.draw(spriteTree);

        for (auto &branch: branches)
        {
            window.draw(branch);
        }

        window.draw(spriteBee);

        // Draw the score
        window.draw(scoreText);

        // Draw the time bar
        window.draw(timeBar);

        if (paused)
        {
            // Draw our message
            window.draw(messageText);
        }
        // Show everything we just drew
        window.display();
    }
    return 0;
}

void updateBranches(int seed)
{
    // Move all branches down one place
    for (int j = NUM_BRANCHES - 1; j > 0; j--)
    {
        branchPositions[j] = branchPositions[j - 1];
    }

    // Spawn a new branch at position 0
    // LEFT, RIGHT or NONE
    srand((uint) time(0) + seed);
    int r = (rand() % 5);
    switch (r)
    {
        case 0:
            branchPositions[0] = side::LEFT;
            break;
        case 1:
            branchPositions[0] = side::RIGHT;
            break;
        default:
            branchPositions[0] = side::NONE;
            break;
    }
}