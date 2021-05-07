/*******************************************************************************************************************************
* Name : 신재혁
* Student ID : 20181636
* Program ID : lab5_신재혁.cpp
*******************************************************************************************************************************/
#include <iostream>
#include <fstream>


using namespace std;

typedef enum {lparen, rparen, times, divide, Plus, Minus, operand}precedence;
int isp[] = {0,3,2,2,1,1,0}; 
int icp[] = {4,3,2,2,1,1,0}; 
const int stackSize = 100;
char arr[100]={0}; 
void postfix(char buffer[]);
int eval(char arr[]);
ifstream infile("lab5.txt"); 

class STACK
{ 
    private:
        int stack[stackSize];
        int top;
    public:
        STACK()
        {
        top = -1;
        }

        int isEmpty()
        { 
            if(top == -1)
                return true;
            else return false;
        }

        void push(int val)
        { 
            ++top;
            stack[top]=val;
        }

        int pop()
        { 
            return(stack[top--]);
        }

        int getTop()
        { 
            return stack[top];
        }

        void displayStack()
        { 
            int sp;
            if (isEmpty()) cout << "Stack is empty!" << endl;
            else 
            {
                sp = top;
                while (sp != -1) 
                {
                    cout << stack[sp]; --sp;
                }
            }
        }
};
STACK ST; 
STACK RST; 
precedence getToken(char s)
{ 
    switch(s)
    {
        case '(': 
            return lparen;
        case ')': 
            return rparen;
        case '*': 
            return times;
        case '/': 
            return divide;
        case '+': 
            return Plus;
        case '-': 
            return Minus;
        default:
            return operand;
	}
    
    
}
char getVal(precedence T)
{ 
    switch (T) 
    {
        case lparen: 
            return '(';
        case rparen: 
            return ')';
        case times: 
            return '*';
        case divide: 
            return '/';
        case Plus: 
            return '+';
        case Minus: 
            return '-';
        default:
            return '\0';
	}

}
precedence op;

int main()
{
    
    char buffer[100];

    while(infile.getline(buffer,100))
    {
        
        cout << "Infix expression : " << buffer<<" ";
        cout << "The Postfix conversion : ";
        postfix(buffer);
        cout <<endl<<endl<< "The final result : " ;
        eval(arr);
        cout <<endl<<endl;

    }
    return 0;

}

void postfix(char buffer[])
{ 
    int temp =0;
    
    for(int i = 0; i< strlen(buffer); i++)
    {
        if(buffer[i]>='0' && buffer[i]<='9')
        { 
            arr[temp++]=buffer[i]; 
            cout << buffer[i]; 
        }
        else if (buffer[i]=='('){ 
            ST.push(lparen); 
        }
        else if (buffer[i]==')')
        { 
            while((op=(precedence)ST.pop())!=lparen)
            { 
                arr[temp++]=getVal(op);
                cout << getVal(op);

            }
        }
        else 
        {
            while(!ST.isEmpty()&&(icp[getToken(buffer[i])]<=isp[ST.getTop()]))
            {
                
                op=(precedence)ST.pop();
                arr[temp++]=getVal(op);
                cout << getVal(op);
                
            }
            ST.push(getToken(buffer[i]));
        }
    }
    while(!ST.isEmpty())
    {
        op=(precedence)ST.pop();
        cout << getVal(op);
        arr[temp++]=getVal(op);
    }
}

int eval(char arr[])
{
    
    int op1, op2; 
    int top = -1;
    for(int i=0; i<strlen(arr);i++)
    {
        if(arr[i]>='0' && arr[i]<='9')
        {
            RST.push(arr[i]-48); 
        }
        else
        {
            op2 = RST.pop();
            op1 = RST.pop();
            switch (arr[i]) 
            {
                case '*':
                    RST.push(op1 * op2);
                    break;
                case '/':
                    RST.push(op1 / op2);
                    break;
                case '+':
                    RST.push(op1 + op2);
                    break;
                case '-':
                    RST.push(op1 - op2);
                    break;
            }
        }
    }
    cout<< RST.pop(); 
    return 0;
    
}

