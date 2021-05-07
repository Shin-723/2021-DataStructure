#include <iostream>
#include <cmath>
using namespace std;

bool Is_Prime(int num) {
	if (num < 2) return false;
	int a = (int) sqrt(num);
	for (int i = 2; i <= a; i++) if (num % i == 0) return false;
	return true;
}

int Large_prime(int n)
{
    int m = n+1 ;

    while(!Is_Prime(m))
    {
        m+=1;
    }
    return m;

}



int main() 
{
    int a;
    
	while (1)
    {
       cout << "Enter any number : ";
       cin >> a;
       if (Is_Prime(a)==true)
       {
           cout << a <<"is prime number"<<endl;
       }
       else cout << a << "is not prime number"<<endl;
    
       
       cout << "prime number larger than given number :"<<Large_prime(a) << endl;
    }
    

	return 0;
}