/*******************************************************************************************************************************
* Name : 신재혁
*
* Student ID : 20181636
*
* Program ID : lab7_신재혁.cpp
*********************************************************************************************************************************/

#include <iostream>
using namespace std;

struct Node{
   int data;
   Node *next;
   Node(int value) {
      data = value;
      next = 0;
   }
};

class linkedStack {
private:
   Node *head;
public:
   linkedStack() { head = 0; }
   ~linkedStack();
   void push(int data);
   int pop();
   int isEmpty();
   void displayStack();


};


linkedStack::~linkedStack() {

}

void linkedStack::push(int data) {
   Node *temp = new Node(data);
   if (head == 0) head = temp;
   else { temp->next = head; head = temp; }
}

int linkedStack::pop() {
   Node *p;
   int num;
   num = head->data;
   p = head;
   head = head->next;
   delete p;
   return num;
}

int linkedStack::isEmpty() {
   if (head == 0) return 1;
   else return 0;
}


void linkedStack::displayStack() {
   Node *p;
   if (!isEmpty()) {
      p = head;
      while (p) {
         cout <<"  "<<p->data<<" "; p = p->next;
      }
   }
   else { cout << " "; }
}

class linkedQueue {
private:
   Node *front;
   Node *rear;
public:
   linkedQueue() { front = 0; rear = 0; }
   ~linkedQueue();
   void enqueue(int data);
   int dequeue();
   int isEmpty();
   void displayQueue();

};
linkedQueue::~linkedQueue() {
   Node *p;
   while (rear != 0) {
      p = front;
      front = front->next;
      delete p;
   }
}

int linkedQueue::isEmpty() {
   if (front == 0) return 1;
   else return 0;
}

void linkedQueue::enqueue(int data) {
   Node *temp = new Node(data);
   if (front == 0) {
      front = temp;
      rear = temp;
   }
   else {
      rear->next = temp;
      rear = temp;
   }
}

int linkedQueue::dequeue() {
   Node *p; int num;
   num = front->data;
   p = front;

   if (front == rear) {
      front = 0;
      rear = 0;
   }
   else front = front->next;

   delete p;
   return num;
}

void linkedQueue::displayQueue() {
   Node *p;

   if (!isEmpty()) {
      p = front;
      while (p) {
         cout<<"  "<< p->data<<" ";
         p = p->next;
      }
      cout << endl;
   }
   else cout << " \n";
}
class List {
private:
   Node *head;
public:
   List() { head = NULL; }
   bool isEmpty();
   void InsertNode(int data);
   void traverse();
   void merge(linkedStack &a, linkedQueue &b);
   ~List();

};
List::~List(){
	Node *p;
	while (head != 0) {
		p = head;
		head = head->next;
		delete p;
	}
}

bool List::isEmpty() {
   if (head == NULL) return true;
   else return false;
}

void List::InsertNode(int data) {
   Node *temp = new Node(data);
   Node *p, *q;
   p = q = NULL;

   if (head == NULL) {
      temp->data = data;
      head = temp;
   }
   else if (temp->data < head->data) {
      temp->next = head;
      head = temp;
   }
   else {
      p = head;
      while (p != NULL && temp->data > p->data) {
         q = p;
         p = p->next;
      }
      if (p != NULL) {
         temp->next = p;
         q->next = temp;
      }
      else {
         q->next = temp;
      }
   }

}
void List::merge(linkedStack &a, linkedQueue &b) {
  
   while (!a.isEmpty())
   {
      InsertNode(a.pop());
   }
   while (!b.isEmpty())
   {
      InsertNode(b.dequeue());
   }

}


void List::traverse() {
   Node *p;
   if (!isEmpty()) {
      p = head;
      while (p) {
         cout << p->data << " ";
         p = p->next;
      }
      cout << endl;
   }
   else
      cout << "List is empty!\n";
}

int main() {
   linkedStack List1;
   linkedQueue List2;
   List List3;
   while (1) {
        int a;
		cout << "MENU (1.push   2.pop   3.enqueue  4.dequeue   5.MakeList  6.quit) : ";
		cin >> a;
		switch (a) {
            case 1: {
                int data;
                cout << "Enter an integer to push => ";
                cin >> data;
                List1.push(data);
                cout <<"Stack : "<<endl;
				List1.displayStack();
                cout << endl;
                break;
            }
            case 2: {
                if(List1.isEmpty()){cout << "Stack is Empty"<<endl; break;}
                else{
                    cout << List1.pop() << "  ==>  is popped!";
                    cout <<endl;
                    cout <<"Stack : "<<endl;
				    List1.displayStack();
                    cout << endl;
                    break;
                }
            }
            case 3: {
                int data;
                cout << "Enter an integer to enque => ";
                cin >> data;
                List2.enqueue(data);
                cout <<"Queue : "<<endl;
				List2.displayQueue();

                break;
            }
            case 4: {
                if(List2.isEmpty()){cout << "Queue is Empty"<<endl; break;}
                else{
                    cout << List2.dequeue() << "  ==>  is dequed!";
                    cout << endl;
                    cout <<"Queue : "<<endl;
				    List2.displayQueue();
                    break;
                }
                
            }
            case 5: {
                cout << "List:  ";
                List3.merge(List1,List2);
                List3.traverse();
                break;
                
                
            }
            case 6: {
                List1.~linkedStack();
                List2.~linkedQueue();
                List3.~List();
                return 0;
		    }


	    }
    }
}
   


