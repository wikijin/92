Queue 的实现
======================================================================================
#ifndef QUEUE_H
#define QUEUE_H

namespace queuesavitch
{
	struct QueueNode
	{
		char data;
		QueueNode *link;
	};

	typedef QueueNote * QueueNotePtr;

	class Queue
	{
	public:
		Queue();
		//讲对象初始化为一个空的队列

		Queue(const Queue & aQueue);
		~Queue();

		void add(char item);
		//后条件：数据项已经添加到队列的末尾

		char remove();
		//前条件：对列为非空
		//返回队列前端的数据项并从队列中删除该项

		bool empty() const;
		//如果队列为空，就返回true；反之返回false

	private:
		QueueNotePtr front; //指向链表的表头
							//数据项在表头删除

		QueueNotePtr back; //指向链表的另一端，数据项在这一端添加

	}；
}

#endif

使用queue类的程序
======================================================================================
#include <iostream>
#include "queue.h"

using namespace std;
using namespace queuesavitch;

int main()
{
	Queue q;
	char next, ans;

	do
	{
		cout<< "Enter a word:";
		cin.get(next);
		while (next != '\n');
		{
			q.add(next);
			cin.get(next);
		}

		cout << "You entered";
		while (!q.empty())
		cout << q.remove();
		cout << endl;

		cout << cout "Again?(y/n)";
		cin >> ans;
		cin.ignore(10000, '\n');

	}while (ans!= 'n' && ans!= 'N');

	return 0;
}

Queue类的实现
=========================================================================================

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "queue.h"

using namespace std;

namespace QueueSavitch
{
	template<class T>
	Queue::	Queue() : front(NULL), back(NULL)
	{

	}

	Queue::Queue(const Queue& aQueue)
	{
		if (a.Queue.empty())
			front = back = NULL;
	

		else 
		{
		QueueNodePtr temp_ptr_old = aQueue.front;
		//temp_ptr_old 在aQueue 中从front 到 back，历遍所有节点。

		QueueNodePtr temp_ptr_new;
		//temp_ptr_new用于创建新节点

		back = new QueueNode;
		back->data = temp_ptr_old->data;
		back->link = NULL;
		front = back;
		

		temp_ptr_old = temp_ptr_old -> link;
		
		while(temp_ptr_old != NULL)
		{
			temp_ptr_new = new QueueNode;
			temp_ptr_new-> data temp_ptr_old->data;
			temp_ptr_new->link = NULL;
			back ->link =temp_ptr_new;
			back = temp_ptr_new;
			temp_ptr_old = temp_ptr_old->link;
		}
		
		}
	}


	Queue::~Queue()
	{
		char next;
		while (!empty())
			next = remove(); 
	}

	bool Queue::empty() const
	{
		return (back=NULL);
	}

	void Queue::add(char item)
	{
		if(empty())
		{
			front = new QueueNode;
			front -> data = item;
			front -> link = NULL;
			back = front;
		}

		else
		{
			QueueNodePtr temp_ptr;
			temp_ptr = new QueueNode;
			temp_ptr-> data = item;
			temp_ptr->link = NULL;
			back -> link = temp_ptr;
		}

	}

	char Queue::remove()
	{
		if (empty())
		{
			cout<< "Error: Romoving an item from an empty queue.\n"
			exit(1);
		}


		char result = front -> data;
		QueueNodePtr discard;
		discard = front;
		front = front -> link;
		if(front == NULL)
			back = NULL;
		delete discard;

		return result;
	}
}





































