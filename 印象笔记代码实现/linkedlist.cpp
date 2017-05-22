#include <iostream>

using namespace std;

节点
============================================================

struct ListNode
{
	string item;
	int count;
	ListNode *link; //一个ListNode类型的pointer
	
}；
typedef ListNode * ListNodePtr;

ListNodePtr head;

//如果需要修改node里面的值

(*head).count=12; 或者等价于 head->count=12;

链表
=============================================================

链表是节点的列表，其中每个节点都有一个指针成员变量指向列表中的下一个节点

struct Node{
	int data;
	Node *link;
};
typedef Node* NodePtr;

NodePtr head; //构造开头部分

head= new Node;//创建动态变量，它将成为链表的第一个节点

head->data=3;
head->link = NULL;

在表头插入节点
==============================================================

void head_insert(NodePtr&head, int the_number);
这个函数共包含两个参数。第一个是传引用参数，代表指向链表表头的指针变量，另一个参数指定要在新节点中储存的数字。

代码实现：
struct Node{
	int data;
	Node *link;
};

typedef Node* NodePtr;

void head_insert(NodePtr& head, int the_number);

void head_insert(NodePtr& head, int the_number)
{
	NodePtr temp_ptr;
	temp_ptr = new Node;
	
	temp_ptr->data = the_number;
	temp_ptr->link = head;
	head = temp_ptr;
}


搜索链表
==============================================================
NodePtr search(NodePtr head, int target);   先不考虑空链表的问题。这里我们可以用名为here的局部指针变量遍历列表，并在遍历过程中查找target。

函数声明
struct NodePtr{
	int data;
	Node * link;
};
typedef Node* NodePtr;

NodePtr search(NodePtr head, int target);
//前条件，head指针指向链表的表头。
//最后一个节点的指针变量是NULL。
//如果列表为空，那么head为Null，返回一个指针，它指向包含target的第一个节点。
//如果没有任何节点包含target，函数返回Null。

NodePtr search(NodePtr head, int target)
{
	NodePtr here=head;
	
	if (here == NULL)
	{
		return NULL;
	}
	else 
	{
		while (here->data != target && here->link != NULL)
		{
			here = here -> link;
			
			if (here->data == target)
				return here;
			else 
				return NULL;
		}
	}
}

在列表中插入和删除节点
==================================================================================
void insert(NodePtr after_me, int the_number);
//前条件：after_me指向链表中的一个节点
//后条件：将包含the——number的一个新节点放在after——me指向的节点之后。

struct Node
{
	int data;
	Node *link;
};

typedef Node* NodePtr;

void insert(NodePtr after_me, int the_number)
{
	NodePtr temp_ptr;
	temp_ptr = new Node;
	
	temp_ptr->data = the number;
	temp_ptr->link = after_me->link;
	
	after_me->link = temp_ptr;
}

类构成的链表
==================================================================================












删除节点：

void (NodePtr before, Node)
struct  NodePtr{
	int data;
	Node* link;
};

typedef Node * NodePtr;















