/*******************************************************************************************************************************
* Name : 신재혁
* Student ID : 20181636
* Program ID : hw3_신재혁.cpp
* Description : 
* - 양쪽에 각각 link를 가진(next, prev) Doubly Linked List를 직접 구현해 리스트를 만들어보고, ADT들이 올바르게 동작하는지 테스트 해본다.
* Algorithm :
* - InsertAfter 함수 : 만약 리스트가 비어있을 경우엔 새로 만든 노드를 head로 설정해준다. 만약 current 노드가 마지막 노드가 아니라면 current 노드와 
*                     새 노드, current 노드의 next였던 노드와 새 노드를 각각 연결해준다. 두 경우 다 아니였을 경우엔 current 노드가 마지막 노드인
*                     것이므로 current 노드와 새 노드 사이만 연결해 준다. 그리고 마지막엔 current를 새 노드로 지정해준다.
* - InsertBefore 함수 : 만약 리스트가 비어있을 경우엔 새로 만든 노드를 head로 설정해준다. 만약 current 노드가 head라면 새 노드와 원래의 head 노드를
*                      연결해준 후 새 노드를 head로 지정해준다. 만약 둘 다 아니라면 current 노드와 새 노드, current 노드의 prev였던
*                      노드와 새 노드를 각각 연결해준다. 그리고 마지막엔 current를 새 노드로 지정해준다.
* - InsertFirst 함수 : 만약 리스트가 비어있을 경우엔 새로 만든 노드를 head로 설정해준다. 그게 아니라면, 새 노드를 원래 head 노드와 연결해준 후
*                     head와 current를 새 노드로 지정해준다.
* - InsertLast 함수 : 만약 리스트가 비어있을 경우엔 새로 만든 노드를 head로 설정해준다. 그게 아니라면, 마지막 노드까지 while문으로 이동한 후 
*                    마지막 노드의 뒤에 새 노드를 연결해준다. 그리고 current를 새 노드로 지정해준다.
* - DeleteCurrent 함수 : 만약 리스트가 비어있을 경우엔 리스트가 비어있다고 출력해준다. 만약 current가 head였을 경우엔 next 노드로 current와 head를 
*                       옮겨준 후 원래의 head 노드를 삭제해준다. 만약 current가 마지막 노드였을 경우엔 마지막 노드를 삭제해준 후 current를 head로
*                       만들어준다. 둘 다 아니라면, current 노드의 next 노드와 prev 노드를 서로 연결해준 후 원래 current 노드의 next로 current를
*                       옮겨주고 원래의 current였던 노드를 삭제해준다.
* - LocateCurrent 함수 : 만약 리스트가 비어있을 경우엔 리스트가 비어있다고 출력해준다. 그것이 아니라면 리스트의 전체 길이가 입력받은 숫자 이상인지 검사해준 후,
*                       아니라면 별도의 메시지를 출력해준다. 만약 맞다면, while문으로 올바른 노드까지 이동해 val를 출력해준 후 current를 그 노드로
*                       지정해준다.
* - UpdateCurrent 함수 : current의 val을 입력받은 data로 변경해준다.
* - DisplayList 함수 : 리스트의 head부터 시작해 while문을 통해 리스트의 끝까지 차례대로 리스트를 출력해준다.
* - listLength 함수 : 리스트의 끝까지 while문을 돌리며 cnt를 증가시켜 리스트의 길이(노드의 개수)를 구해준다. 
* Variables :
* - struct Node : int형 변수 val과 포인터형 변수 next, prev를 가지고 있는 구조체이다. next와 prev로 다른 노드들을 연결해줄 수 있다.
* - class List : DLL을 구현하기 위한 클래스이다. Node 포인터형 변수 head와 current, 그리고 다양한 함수들을 가지고 있다. head는 리스트의 가장 첫번째
*                노드를 가리키는 포인터이고, current는 현재(가장 최근에 사용한)의 노드를 가리키는 포인터이다.
*******************************************************************************************************************************/
#include <iostream>

using namespace std;

/*******************************************************************************************************************************
* struct : Node
* description : Node의 사용 목적은 DLL에서 데이터들을 저장하고 이전/이후의 다른 노드들과 연결해 주기 위함이다. 
* Variables :
* - int val : 각 노드마다 int형 데이터를 담기 위한 int형 변수이다.
* - struct Node *next : 다음 노드를 연결해 주기 위한 포인터 변수이다.
* - struct Node *prev : 이전 노드를 연결해 주기 위한 포인터 변수이다.
******************************************************************************************************************************/
struct Node{
    int val;
    struct Node *next;
    struct Node *prev;
    Node(int data){
        val = data;
        next = NULL;
        prev = NULL;
    }    
};

/*******************************************************************************************************************************
* class : List
* description : List의 사용 목적은 DLL을 구현하고, DLL에 사용할 각종 ADT를 구현하기 위함이다.
* Variables :
* - Node *head : 리스트의 가장 첫번째 노드를 가리키는 포인터 변수이다.
* - Node *current : 현재(가장 최근에 사용한)의 노드를 가리키는 포인터 변수이다.
* - List() : List 클래스의 생성자로, 처음 List 객체를 생성해주면 head와 current를 NULL로 설정해준다.
*******************************************************************************************************************************/
class List{
    private:
        Node *head;
        Node *current;
    public:
        List();
        ~List();
        bool isEmpty();
        void InsertAfter(int data);
        void InsertBefore(int data);
        void InsertFirst(int data);
        void InsertLast(int data);
        void DeleteCurrent();
        void LocateCurrent(int nth);
        void UpdateCurrent(int data);
        void DisplayList();
        int listLength();
};

List::List(){
    head = NULL;
    current = NULL;
}

List::~List(){ // 리스트 클리어
    Node *p;
	while (!isEmpty()) {
		p = head;
		head = head->next;
		delete p;
	}
}


/*******************************************************************************************************************************
* function : isEmpty()
* description : inEmpty의 사용 목적은 리스트가 현재 비었는지 아닌지를 검사해주기 위함이다.
*******************************************************************************************************************************/
bool List::isEmpty(){
    if(head == 0){
        return true;
    }
    else{
        return false;
    }
}

/*******************************************************************************************************************************
* function : InsertAfter(int data)
* description : InsertAfter의 사용 목적은 current의 뒤에 하나의 노드를 추가해주기 위함이다.
* variables :
* - Node *temp : 매개변수로 받아온 데이터를 이용해 새로 만들어 줄 노드를 가리키는 포인터이다.
* - Node *p : 노드를 새로 추가하는 과정에서 필요할 때 다른 노드를 저장해 주고 사용할 포인터이다.
*******************************************************************************************************************************/
void List::InsertAfter(int data){
    Node *temp = new Node(data);
    Node *p;

    if (head == NULL){
        head = temp;
    }
    
    else if (current -> next != NULL){ //새로운 노드를 노드들 사이(중간)에 삽입
        p = current -> next;
        temp -> next = p;
        temp -> prev = current;
        current -> next = temp;
        p -> prev = temp;
    }

    else{ //새로운 노드를 마지막 노드 뒤에 삽입
        current -> next = temp;
        temp -> prev = current;
    }

    current = temp;
}

/*******************************************************************************************************************************
* function : InsertBefore(int data)
* description : InsertBefore의 사용 목적은 current의 앞에 하나의 노드를 추가해주기 위함이다.
* variables :
* - Node *temp : 매개변수로 받아온 데이터를 이용해 새로 만들어 줄 노드를 가리키는 포인터이다.
* - Node *p : 노드를 새로 추가하는 과정에서 필요할 때 다른 노드를 저장해 주고 사용할 포인터이다.
*******************************************************************************************************************************/
void List::InsertBefore(int data){
    Node *temp = new Node(data);
    Node *p;

    if (head == NULL){
        head = temp;
    }

    else if (current == head){ //head 노드 앞에 새로운 노드 삽입
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }

    else{ //새로운 노드를 중간(다른 노드들 사이)에 삽입
        p = current -> prev;
        temp -> next = current;
        temp -> prev = p;
        p -> next = temp;
        current -> prev = temp;
    }

    current = temp;
}

/*******************************************************************************************************************************
* function : InsertFirst(int data)
* description : InsertFirst의 사용 목적은 리스트의 맨 앞에 노드를 하나 추가해주기 위함이다.
* variables :
* - Node *temp : 매개변수로 받아온 데이터를 이용해 새로 만들어 줄 노드를 가리키는 포인터이다.
*******************************************************************************************************************************/
void List::InsertFirst(int data){
    Node *temp = new Node(data);
    
    if (head == NULL){
        head = temp;
    }

    else{
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }

    current = temp;
}

/*******************************************************************************************************************************
* function : InsertLast(int data)

* description : InsertLast의 사용 목적은 리스트의 맨 뒤에 노드를 하나 추가해주기 위함이다.
* variables :
* - Node *temp : 매개변수로 받아온 데이터를 이용해 새로 만들어 줄 노드를 가리키는 포인터이다.
* - Node *p : 노드를 새로 추가하는 과정에서 필요할 때 다른 노드를 저장해 주고 사용할 포인터이다.
*******************************************************************************************************************************/
void List::InsertLast(int data){
    Node *temp = new Node(data);
    Node *p;
    
    if (head == NULL){
        head = temp;
    }

    else{
        p = head;
        
        while (p -> next != NULL){
            p = p -> next;
        }

        p -> next = temp;
        temp -> prev = p;
    }
    
    current = temp;
}

/*******************************************************************************************************************************
* function : DeleteCurrent()
* description : DeleteCurrent의 사용 목적은 current가 가리키고 있는 노드를 삭제해준 뒤 current를 다음 노드로 옮겨주기 위함이다.
* variables :
* - Node *p, *q, *r : 노드를 삭제해주는 과정에서 필요할 때 다른 노드를 저장해 주고 사용할 포인터이다.
*******************************************************************************************************************************/
void List::DeleteCurrent(){
    Node *p, *q, *r;

    if (head == NULL){
        cout << "List is empty" << endl;
    }

    else if (current == head){
        p = head;
        head = p -> next;
        current = head;
        head -> prev = NULL;
        delete p;
    }

    else if (current -> next == NULL){ //마지막 노드를 삭제할 경우
        p = current;
        q = current -> prev;
        q -> next = NULL;
        delete p;
        current = head;
    }

    else{ //중간에 있는 노드를 삭제할 경우(= head와 마지막 노드가 아닌 경우)
        r = current;
        p = current -> prev;
        q = current -> next;
        p -> next = q;
        q -> prev = p;
        current = q;
        delete r;
    }

}

/*******************************************************************************************************************************
* function : LoacteCurrent(int nth)
* description : LocateCurrent의 사용 목적은 매개변수로 입력받은 nth번째의 노드를 출력해주고 그 노드를 current로 만들어주기 위함이다.
* variables :
* - Node *p : 노드를 찾는 과정에서 필요할 때 다른 노드를 저장해 주고 사용할 포인터이다.
* - int pos : 몇번째 노드를 찾았는지 저장해주기 위한 int형 변수이다.
*******************************************************************************************************************************/
void List::LocateCurrent(int nth){
    Node *p;
    int pos = 1;

    if (isEmpty()){
        cout << "List is empty!\n";
    }

    else if (listLength() >= nth){ //현재의 링크드 리스트의 전체 길이보다 nth가 작거나 같아야 한다.
        p = head;
        while(pos != nth){
            p = p->next;
            pos++;
        }
        cout << pos << " *  ";
        cout << p->val << endl;
        current = p;
    }

    else{ //nth가 현재 리스트의 길이보다 클 경우
        cout << "No such a line" << endl;
    }
}

/*******************************************************************************************************************************
* function : UpdateCurrent(int data)
* description : UpdateCurrent의 사용 목적은 current가 가리키는 노드의 val값을 바꿔주기 위함이다.
*******************************************************************************************************************************/
void List::UpdateCurrent(int data){
    current -> val = data;
}

/*******************************************************************************************************************************
* function : DisplayList()
* description : DisplayList의 사용 목적은 현재 리스트를 head부터 마지막까지 차례대로 출력해주기 위함이다.
* variables :
* - Node *p : 노드를 출력해주는 과정에서 필요할 때 다른 노드를 저장해주고 사용할 포인터이다.
* - int index : 리스트를 출력해주는 과정에서 각 노드들이 몇번째 노드인지 출력해주기 위해 사용할 int형 변수이다.
*******************************************************************************************************************************/
void List::DisplayList(){
    if(!isEmpty()){
        Node *p = head;
        int index = 1;
        cout << "--- List ---" << endl;
        while ( p != NULL ){

            cout << "   " << index;

            if (p == current){
                cout << "   *   ";
            }
            else{
                cout << "   :   ";
            }

            cout << p  -> val << endl;
            p = p -> next;
            index += 1;
        }
    }

    else{
        cout << "List is empty!\n";
    }
}

/*******************************************************************************************************************************
* function : listLength()
* description : listLength의 사용 목적은 현재 리스트의 길이(노드의 갯수)를 알아내기 위함이다.
* variables :
* - int cnt : 리스트의 길이를 세기 위해 사용할 int형 변수이다.
* - Node *p : 리스트의 길이를 알아내는 과정에서 다른 노드를 저장해 주고 사용하기 위한 포인터이다.
*******************************************************************************************************************************/
int List::listLength(){
    if(!isEmpty()){
        int cnt = 0;
        Node *p = head;
        while( p != 0 ){
            p = p -> next;
            cnt += 1;
        }
        return cnt;
    }
    else{
        return 0;
    }

}



int main(){
    List DLL;
    int data;
    int num = 0;

    while( num != 9 ){
        cout << "Command: (1)insertAfter   (2)insertBefore   (3)insertFirst   (4)insertLast   (5)deleteQurrent" << endl;
        cout << "         (6)locateQurrent (7)updateCurrent  (8)displayList   (9)quit" << endl;
        cout << "==>  ";
        cin >> num;

        switch (num){
            case 1 :
                cout << "Enter a data to insert => ";
                cin >> data;
                DLL.InsertAfter(data);
                DLL.DisplayList();
                break;

            case 2 :
                cout << "Enter a data to insert => ";
                cin >> data;
                DLL.InsertBefore(data);
                DLL.DisplayList();
                break;

            case 3 :
                cout << "Enter a data to insert => ";
                cin >> data;
                DLL.InsertFirst(data);
                DLL.DisplayList();
                break;

            case 4 :
                cout << "Enter a data to insert => ";
                cin >> data;
                DLL.InsertLast(data);
                DLL.DisplayList();
                break;

            case 5 :
                DLL.DeleteCurrent();
                DLL.DisplayList();
                break;

            case 6 :
                cout << "Enter a position to locate => ";
                cin >> data;
                DLL.LocateCurrent(data);
                break;
            
            case 7 :
                cout << "Enter a data to update => ";
                cin >> data;
                DLL.UpdateCurrent(data);
                DLL.DisplayList();
                break;

            case 8 :
                DLL.DisplayList();
                break;

            case 9 :
                DLL.~List();
                break;
        }
    }

    return -1;
}
