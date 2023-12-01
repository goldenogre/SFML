#include <SFML/Graphics.hpp>
#include <iostream>
/* page 103 */
using namespace sf;
int main()
{
    // Setup Variables
	int VIDEO_W  = 1920;
	int VIDEO_H = 1080;
	sf::VideoMode videoMode(VIDEO_W, VIDEO_H);
	sf::RenderWindow window(videoMode, "SFML Game v1.0");
	sf::Event event;
	
	
	Texture tx_Background; 
	if(!tx_Background.loadFromFile("graphics/background.png")){
		std::cout << "Error loading background" << std::endl;
	}
	
	Sprite spriteBG;
	spriteBG.setTexture(tx_Background);
	spriteBG.setPosition(0,0);
	
	
	// Make a tree sprite
	Texture tx_Tree;
	Sprite sp_Tree;
	if(!tx_Tree.loadFromFile("graphics/tree.png")){
		std::cout << "Error loading tree" << std::endl;
	}
	sp_Tree.setTexture(tx_Tree);
	sp_Tree.setPosition(810,0);
	// Make Bee sprite
	Texture tx_Bee;
	Sprite sp_Bee;
	if(!tx_Bee.loadFromFile("graphics/bee.png")){
		std::cout << "Error loading bee" << std::endl;
	}
	sp_Bee.setTexture(tx_Bee);
	sp_Bee.setPosition(0,800);
	// Is be moving?
	bool beeActive = false;
	float beeSpeed = 0.0f;
	// 3 Clouds
	Texture tx_Cloud;
	if(!tx_Cloud.loadFromFile("graphics/cloud.png")){
		std::cout << "Error loading cloud texture" << std::endl;
	}
	Sprite sp_cloud1;
	Sprite sp_cloud2;
	Sprite sp_cloud3;
	sp_cloud1.setTexture(tx_Cloud);
	sp_cloud2.setTexture(tx_Cloud);
	sp_cloud3.setTexture(tx_Cloud);
	sp_cloud1.setPosition(0,0);
	sp_cloud2.setPosition(0,250);
	sp_cloud3.setPosition(0,500);
	bool cloud1Active = false;
	bool cloud2Active = false;
	bool cloud3Active = false;
	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;
	
	// how fast is the cloud?
	
    while (window.isOpen())
    {
        /* Time */
		Time deltaTime = clock.restart();
		if(!beeActive){
			// how fast is the bee
			srand((int)time(0));
			beeSpeed = (rand() % 200) + 200;
			
			// How high is the bee
			srand((int)time(0)*10);
			float height = (rand() % 500) + 500;
			sp_Bee.setPosition(2000, height);
			beeActive = true;
			
		} else {
			sp_Bee.setPosition(sp_Bee.getPosition().x -(beeSpeed * deltaTime.asSeconds()),sp_Bee.getPosition().y);
			if (sp_Bee.getPosition().x < -100){
			// Set it up ready to be a whole new cloud next frame
				beeActive = false;
			}

		}
		if (!cloud1Active)
{
 // How fast is the cloud
 srand((int)time(0) * 10);
 cloud1Speed = (rand() % 200);
 // How high is the cloud
 srand((int)time(0) * 10);
 float height = (rand() % 150);
 sp_cloud1.setPosition(-200, height);
 cloud1Active = true;
}
		/* Player Input**************************/
		if(Keyboard::isKeyPressed(Keyboard::Escape)){
			window.close();
		}
	
		
		/****************************************/
		
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
		// Manditory to clear screen
		window.clear(sf::Color::Blue);
		// Draw something Sprites, Text, shapes
		window.draw(spriteBG);
		window.draw(sp_cloud1);
		window.draw(sp_cloud2);
		window.draw(sp_cloud3);
		window.draw(sp_Tree);
		window.draw(sp_Bee);
		
		
        window.display();
    }
	return 0;
}