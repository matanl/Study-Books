#include "bar.h"
#include "BeersAndWines.h"
#include <iostream>
Bar::Bar()
{
	stock[0] = new Heineken();
	stock[1] = new Goldstar();
	stock[2] = new Maccabi();
	stock[3] = new Tuborg();

	stock[4] = new EmeraldRieslingCarmel(1986);
	stock[5] = new GoldenSmadar(1989);
	stock[6] = new YardenShardone(1997);

	stock[7] = new Chianti(1997);
	stock[8] = new YardenMountHermonRed(1994);
	stock[9] = new YardenCabernetSauvignon(1997);
	stock[10] = new ChadeauMargot(1997);
}


Bar::~Bar()
{
	for (int i = 0; i < SHELF_SIZE; i++)
	{
		delete stock[i];
	}
}

void Bar::Bartender()
{
	int choice;
	Drink* last_drink=nullptr;
	do
	{
		std::cout << "What can i get you, sir? (0 - list options)" << std::endl;
		std::cin >> choice;
		std::cout << std::endl;
		if (choice==0){
			std::cout << "(0)\tlist options" << std::endl;
			for (int i = 0; i < SHELF_SIZE; i++)
			{
				std::string a = std::to_string(i + 1);
				std::string b = stock[i]->getName();
				std::cout << "("+std::to_string(i+1)+")\t"+stock[i]->getName() << std::endl;
			}
			if (last_drink != nullptr){
				std::cout << "(99)\tHow did you prepare my last drink?" << std::endl;
			}
			std::cout << "(100)\tLeave the bar" << std::endl;
			std::cout << std::endl;
			
		}
		else if (choice == 99 && last_drink!=nullptr)
		{
			std::cout << last_drink->prepare() << std::endl << std::endl;
		}
		else if (choice == 100){
			std::cout << "Bar is closed. Good night." << std::endl << std::endl;
		}
		else
		{
			last_drink = stock[choice-1];
			std::cout << "One " << last_drink ->getName() << " coming up, sir."  << std::endl << std::endl;
		}
	} while (choice !=100);
}