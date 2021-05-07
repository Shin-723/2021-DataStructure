#include<iostream>
#include<string>

using namespace std;

int Add(int x,int y)
{
    if(x==0) return y;
    else return Add(--x,++y);
}

int Diffs(int x,int y)
{
    if(x==0) return y;
    else if(y==0) return x;
    else return Diffs(--x,--y);
}

int Sum(int num)
{
    if (num!=0) return num + Sum(num-1);
    else return num;
}


string Reverse(string str){
    if (str.length() == 1) {
        return str;
    }else{
        return Reverse(str.substr(1,str.length())) + str.at(0);
    }
}

int main()
{
    int a,b,c,d,e;
    string str;
    
    cout << "Enter number : ";
    cin >> a;
    cout << "Enter number : ";
    cin >> b;
    cout << "Sum is :"<< Add(a,b) << endl;

    cout << "Enter number1 : ";
    cin >> c;
    cout << "Enter number2 : ";
    cin >> d;
    cout << "Difference is "<< Diffs(c,d) << endl;

    cout << "Enter any positive integer: ";
    cin >> e;
    cout << "Sum of numbers :"<< Sum(e) << endl;

    cout << "Enter String : " ;
    cin >> str ;
    cout << "Reverse of the string is :" <<Reverse(str);
    
}

