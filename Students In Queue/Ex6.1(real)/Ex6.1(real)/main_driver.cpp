#include "Queue.h"
#include <iostream>
#include <string>
using namespace queues;
int main()
{
	Queue queue;
	std::string name, major, id;
	std::cout << "We have 5 students waiting to see the advisor, let's input their info:" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Student " << i + 1 << "'s info:" << std::endl;
		std::cout << "Input the name:" << std::endl;
		std::cin >> name;
		std::cout << "Input the major:" << std::endl;
		std::cin >> major;
		std::cout << "Input the ID:" << std::endl;
		std::cin >> id;
		queue.add(name, major, id);
	}
	char choice = 'Y';
	std::string display = "display";
	std::string add = "add";
	std::string remove = "remove";
	do
	{
		std::cout << "If you would like to display the queue, type 'D', then press Enter." << std::endl;
		std::cout << "If you would like to add another student, type 'A', then press Enter." << std::endl;
		std::cout << "If you would like to remove an element, type 'R', then press Enter." << std::endl;
		std::cout << "If you would like to exit the program, type 'e', then press Enter." << std::endl;
		std::cout << "Please enter the word exactly, otherwise the menu will repeat itself and ask you again." << std::endl;
		std::cin >> choice;
		if (choice == 'D')
		{
			queue.display();
		}
		if (choice == 'A')
		{
			std::cout << "Input the name:" << std::endl;
			std::cin >> name;
			std::cout << "Input the major:" << std::endl;
			std::cin >> major;
			std::cout << "Input the ID:" << std::endl;
			std::cin >> id;
			queue.add(name, major, id);
		}
		if (choice == 'R')
		{
			queue.remove();
		}
	}while (choice != 'e');
	std::cout << "Thanks for your help!" << std::endl;
	return 0;
}