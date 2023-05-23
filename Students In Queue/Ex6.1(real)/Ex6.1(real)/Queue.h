#ifndef QUEUE_H
#define QUEUE_H
#include<string>
namespace queues
{
	struct QueueNode
	{
		std::string Name;
		std::string Major;
		std::string ID;
		QueueNode* link;
	};
	typedef QueueNode* QueueNodePtr;

	class Queue
	{
	public:
		Queue();//basic constructor
		Queue(const Queue& aQueue);//copy constructor
		~Queue();//destructor
		void add(std::string name, std::string major, std::string id);//adds an element to the queue
		void remove();//removes the front element of the queue
		bool empty() const;//returns true if the queue is empty
		void display();//displays the queue

	private:
		QueueNodePtr front;
		QueueNodePtr back;
	};
}
#endif