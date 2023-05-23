#include "Queue.h"
#include <iostream>
using namespace queues;
//preconditon: Queue has not been made
Queue::Queue()
{
	front = NULL;
	back = NULL;
}//postconditon: Queue is made
//precondition: A Queue has been made
Queue::Queue(const Queue& aQueue)
{
	front = aQueue.front;
	back = aQueue.back;
}//postcondition: New queue is copied from the source Queue
//precondition:Queue has been made
Queue::~Queue()
{
	delete front;
	delete back;
}//postcondition: The elements of the queue are deleted
//precondition: Queue has been made
void Queue::add(std::string name, std::string major, std::string id)
{
	QueueNodePtr temp = new QueueNode;
	temp->Name = name;
	temp->Major = major;
	temp->ID = id;
	temp->link = NULL;
	if (back == NULL)
	{
		back = temp;
		front = temp;
	}
	else
	{
		temp->link = back;
		back = temp;
	}
}//postcondition: 'name', 'major', and 'id' are inputted as elements of the queue
//preconditon: Queue has been made and presumably has an element(s)
void Queue::remove()
{
	if (back == NULL)
	{
		std::cout << "Queue is empty, nothing to remove. Ending Program.";
		exit(1);
	}
	QueueNodePtr temp;
	temp = back;
	int i = 0;
	while (temp->link != NULL)
	{
		temp = temp->link;
		i++;
	}
	QueueNodePtr temp2;
	temp2 = back;
	for (int j = 0; j < i - 1; j++)
	{
		temp2 = temp2->link;
	}
	temp2->link = NULL;
	front = temp2;
	delete temp;
}//postconditon: removes the front of the queue
//precondition:Queue has been made
bool Queue::empty() const
{
	if (back == NULL)
	{
		return 1;
	}
	else if (back != NULL)
	{
		return 0;
	}
}//postconditon: returns true if the queue is empty, false if it is not.
//precondition: Queue has been created an presumably contains an element(s)
void Queue::display()
{
	QueueNodePtr temp = NULL;
	temp = back;
	while (temp != NULL)
	{
		std::cout << "Name: " << temp->Name << std::endl << "Major: " << temp->Major << std::endl << "ID: " << temp->ID << std::endl << std::endl;
		temp = temp->link;
	}
}//postcondition: displays all elements of the queue