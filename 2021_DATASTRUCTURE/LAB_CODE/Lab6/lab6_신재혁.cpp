/*******************************************************************************************************************************
* Name : 신재혁
*
* Student ID : 20181636
*
* Program ID : lab6_신재혁.cpp
*********************************************************************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int value)
	{
		data = value;
		next = NULL;
	}
};

class Stack
{
private:
	int top;
	vector<int> stack;
public:
	Stack();
	bool isEmpty();
	void push(int value);
	int pop();
};

Stack::Stack()
{
	top = -1;
	vector<int> stack(1);
}

bool Stack::isEmpty()
{
	if (top == -1) return true;
	else return false;
}

void Stack::push(int value)
{
	stack.push_back(value);
	top++;
}

int Stack::pop()
{
	if (top == -1)
		return -1;
	else
	{
		int num = stack[top--];
		stack.pop_back();
		return num;
	}
}

class LinkedList
{
private:
	Node *head;
public:
	LinkedList();
	~LinkedList();
	bool isEmpty();
	void insertNode(int value);
	void deleteNode(int value);
	void searchNode(int value);
	void printList();
    void findMax();
};

LinkedList::LinkedList()
{
	head = NULL;
}

LinkedList::~LinkedList()
{
	Node *p;

	while (head != NULL)
	{
		p = head;
		head = head->next;
		delete p;
	}
}

bool LinkedList::isEmpty()
{
	if (head == NULL)
		return true;
	else
		return false;
}

void LinkedList::insertNode(int value)
{
	Node *temp = new Node(value);
	Node *p, *q;

	if (isEmpty())
		head = temp;
	else if (temp->data < head->data)
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		p = head;
		q = head;
		while ((p != NULL) && (p->data < temp->data))
		{
			q = p;
			p = p->next;
		}
		if (p != NULL)
		{
			temp->next = p;
			q->next = temp;
		}
		else
			q->next = temp;
	}
}

void LinkedList::deleteNode(int value)
{
	Node *p = NULL;
	Node *q = NULL;

	if (isEmpty())
		cout << "List is Empty" << endl;
	else if (head->data == value)
	{
		p = head;
		head = head->next;
		delete p;
	}
	else
	{
		p = head;
		while ((p != NULL) && (p->data != value))
		{
			q = p;
			p = p->next;
		}
		if (p != NULL)
		{
			q->next = p->next;
			delete p;
		}
		else
			cout << value << " is not in the list" << endl;
	}
}

void LinkedList::searchNode(int value)
{
	Node *p = head;
    if(head!=NULL){
        while(p!=0&&p->data!=value) p=p->next;
        if(p!=0) cout <<value<<" is found"<<endl;
        else cout <<value<< " is not fond"<<endl;
    }
    else cout << "list is empty";
}


void LinkedList::printList()
{
    int count=1;
	if (isEmpty())
		cout << "List is Empty" << endl;
	else
	{
		Node *p = head;
		cout << "---List--- ";
		while (p != NULL)
		{
            cout << "   "<<endl;
			cout << "   " << count<< " : "<< p->data << " ";
			p = p->next;
            count++;
		}
		cout << endl;

	}
}
void LinkedList::findMax()
{
    Node*p=head;
    Node*max=head;
    while(p->next!=NULL){
        if(max->data<p->next->data) max=p->next;
        p=p->next;
    }
    cout <<"Max Number is : "<< max->data<<endl;

}


int main()
{
	LinkedList sll;

	int data;
    int num = 0;

    while( num != 5 ){
        cout << "Command : 1)insert, 2)delete, 3)search, 4)findMax, 5)quit" << "==> ";
        cin >> num;

        switch (num){
            case 1 :
                cout << "Input a number => ";
                cin >> data;
                sll.insertNode(data);
                sll.printList();
                break;

            case 2 :
                cout << "Input a number => ";
                cin >> data;
                sll.deleteNode(data);
                sll.printList();
                break;

            case 3 :
                cout << "Input a number => ";
                cin >> data;
                sll.searchNode(data);
                sll.printList();
                break;

            case 4 :
                sll.findMax();
                sll.printList();
                break;

            case 5 :
                sll.~LinkedList();
                break;

        }
    }

    return -1;
}
