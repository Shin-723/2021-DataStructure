/*******************************************************************************************************************************
* Name : 신재혁
*
* Student ID : 20181636
*
* Program ID : hw2_신재혁.cpp
*
* Description :
*- Dataile을 main에서 infile한다.
*- DataFile서 한줄씩 txt file을 infile하며 괄호를 탐색한다 (괄호 : (, ), {, }, [, ])
*- 여는 괄호와 닫는 괄호를 고려하여, 괄호가 있다면 방향과 순서가 알맞게 나열이 되어있는지 확인한다
*- 괄호의 종류를 매치하여 괄호가 종류별로, 세트가 완성되어 있는지 확인한다
*
* Algorithm :
*- hw2.txt 데이터 파일을 infile 하여 buffer를 통해 1라인씩 읽는다
*- class stack을 이용하여 괄호를 순서와 종류에 따라 읽는다
*- 함수 check를 이용하여 괄호를 여는 방향과 닫는 방향에 따라 처리하거나 stack이 비어있는지 차있는지에 따라도 처리한다
*- 함수 check 안에서 함수 match를 통해 괄호의 종류를 확인하면서 처리한다
*- 함수 match를 이용하여 괄호의 종류가 맞게 구성되어있는지 확인한다

* Variables :
*- BalancedCheck - 괄호의 조합이 알맞을 경우 증가하는 int 타입 변수
*- unbalancedCount - 괄호의 개수가 맞지 않을 경우 증가하는 int 타입 변수
*- mismatchedCount - 괄호의 조합이 알맞지 않을 경우 증가하는 int 타입 변수
*- bool check(char* exp) - 읽어온 텍스트 파일에서 괄호의 여부, 순서를 stack의 상태에 따라 메세지를 처리하는 boolean타입의 함수
*- bool match(char a, char b) - 함수 check()에서 가져온 stack의 최상위 원소를 인자로 받아 괄호의 종류를 매치하여 판단하는 boolean타입의 함수
*- temp - 함수 check안에서 닫는 괄호를 읽었을때 stack이 비어있지 않다면, 괄호의 조합을 판단하기 위해 가장 최근에 담았던 괄호를 담는 변수

*********************************************************************************************************************************/


#include <iostream>
#include <fstream>
#define MAX_SIZE 999

using namespace std;

int BalancedCheck = 0;
int UnbalancedCheck = 0;
int MismatchedCheck = 0;

bool check(char* exp);
bool match(char a,char b);

/********************************************************************
 * class stack
 *- Descrption: stack의 순서 리스트 개념을 이용하여 괄호를 탐색한다
 *- Variables: 
 *- char *stack - stack 선언
 *- int top - stack의 top, 맨 위, 최상위 원소
 *- int size - stack의 크기
 *- Stack(int value) - size만큼 공백 stack을 생성
 *- int IsFull() - stack의 원소 개수가 다 찼는지 판단
 *- int IsEmpty() - stack의 원소 개수가 0개인지 판단
 *- void push(char str) - stack에 원소 삽입
 *- char pop() - stack의 최상위 원소를 반환
 *- void displayStack() - stack이 비어있지 않다면 stack의 원소들을 출력
 * *****************************************************************/

class Stack {
public:
   char *stack;
   int top;
   int size;

   Stack(int value);
   int IsFull();
   int IsEmpty();
   void push(char str);
   char pop();
   void displayStack();

};

Stack::Stack(int value) {
   top = -1;
   size = value;
   stack = new char[size]; // stack을 value 사이즈만큼 공백 스택 생성한다
}

int Stack::IsFull() {
   if (top == size - 1) {// stack의 원소가 다 찼을때

      return 1;
   }
   else {
      return 0;
   }
}

int Stack::IsEmpty() {// stack의 원소가 없을 때
   if (top == -1) {
      return 1;
   }
   else {
      return 0;
   }
}

void Stack::push(char str) {// stack의 top에 str 삽입
   if (IsFull())
      return;
   else
      stack[++top] = str;
}

char Stack::pop() {// stack의 top 원소를 제거하고 그 포인터를 반환
   if (IsEmpty())
      return -1;
   else
      return stack[top--];
}

void Stack::displayStack() {
   int sp;
   if (IsEmpty()) {//stack이 비어있을때 비어있다고 출력
      cout << "Stack is empty!" << endl;
   }
   else {
      sp = top;
      while (sp != -1) {
         cout << stack[sp--]<< " ";
      }
      cout << endl;
   }
}

/*************************************************************************************************
 * Function : check <boolean type>
 * Descrption: 읽어온 텍스트 파일에서 괄호의 여부, 순서를 stack의 상태에 따라 메세지를 처리하는 boolean타입의 함수
 * Variables: 
 *- exp[i] - 불러온 데이터를 순서리스트로 받아 buffer의 i번째 값을 담는 변수
 *- temp - 닫는 괄호를 읽었을때 stack이 비어있지 않다면, 괄호의 조합을 판단하기 위해 가장 최근에 담았던 괄호를 담는 변수
 * ***********************************************************************************************/
bool check(char* exp) {
    Stack stack(MAX_SIZE);
    for(int i = 0; i < strlen(exp); i++){
        if (exp[i]=='(' || exp[i] == '{' || exp[i] == '['){//괄호를 여는 방향은 stack에 push 한다
            stack.push(exp[i]);
        }
        if (exp[i]==')' || exp[i] == '}' || exp[i] == ']'){ //괄호를 닫는 방향일때는 조건식을 둔다
            if(stack.IsEmpty()){
                cout << "The Expression has unbalanced parentheses\n";// 닫는 방향의 괄호는 무조건 밸런스가 맞지 않는다
                cout << "The Expression is Invalid\n" << endl;
                UnbalancedCheck += 1;
                return false;
            }
            else{//stack이 비어있지 않다면
                char temp = stack.pop(); // 새로운 문자타입의 변수 temp에 stack의 최상위 원소를 반환하여 담는다
                if (!match(temp, exp[i])){ // match 함수에 인자로 넣어 괄호의 종류가 맞는지 확인하고, 맞지 않은 경우 메세지를 출력한다
                    cout << "The Mismatched Parenthes in the Expression are " << temp << " and " << exp[i] << "\n" ;
                    cout << "The Expression is Invalid\n" << endl;
                    MismatchedCheck += 1;
                    return false;
                }
            }
        }
    }

    if(stack.IsEmpty()){// for문을 마친 후에 stack이 비어있다면, true라고 리턴
        return true;
    }
    else{ // for문이 끝난후 stack이 비어있지 않다면, 언밸런스의 메세지를 출력한
        cout << "The Expression has unbalanced parentheses\n";
        cout << "The Expression is Invalid\n" << endl;
        UnbalancedCheck += 1;
        return false;
    }
}
/*********************************************************************************************************
 * Function : match <boolean type>
 * Descrption: 함수 check()에서 가져온 stack의 최상위 원소를 인자로 받아 괄호의 종류를 매치하여 판단하는 boolean타입의 함수
 * Variables: 
 * a - stack에서 가장 최근에 담았던 원소(check 함수의 temp 값을 받는 변수)
 * b - check 함수에서 읽어온 괄호를 담는 변수(check 함수의 exp[i] 값을 받는 변수) 
 * ******************************************************************************************************/
bool match(char a, char b) {// check 함수에서 괄호를 탐색하는 과정에서 필요한 괄호 종류를 판별하는 match 함수
    switch(a)
    {// 첫번째 인자로 들어오는 문자의 값에 따라 '( )' '{ }' '[ ]'으로 한쌍이라 판별
    case '(':
        if (b == ')') return true;
        else return false;
        break;
    case '{':
        if (b == '}') return true;
        else return false;
        break;
    case '[':
        if(b == ']') return true;
        else return false;
        break;
    }
    
    return 0;
}

/*********************************************************************************************************
 * Function : main <int type>
 * Descrption: DataFile을 infile하고 앞서 만든 함수들을 이용한 출력값을 출력하는 역할 
 * ******************************************************************************************************/
int main() {
   char buffer[80];
   ifstream infile;
   infile.open("quiz.txt",ios::in); // DataFile hw2.txt을 infile
   cout <<"<< Hw2: Balanced Parenthese >>"<<endl<<endl;
   while(infile.getline(buffer,80))
   {// 데이터 1라인을 읽어온다
       cout<<"Input Data "<<buffer<<endl;
       bool validity = check(buffer); // 데이터 1라인을 check 함수로 판단하여 bool 타입의 변수에 함수 리턴값을 넣는다
       if(validity){
           cout << "a palindrome\n" << endl;
           BalancedCheck += 1;
       }
       else cout <<"not a palindrome";
   } 

   return 0;
}
