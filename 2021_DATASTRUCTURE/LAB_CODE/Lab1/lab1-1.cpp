//////////////////////////////////////////////////////
//Lab1-1: Find Min and Max numbers
//Name: 신재혁
//ID: 20181636
//Program Description: Find Min and Max numbers
//Algorithm: 첫번째 숫자를 기준으로 하나씩 보면서 더 작은수/큰수 저장 
//Variable: for : 반복하여 수행
///////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int findMin(const int data[], int n) 
{
    int min = data[0];
    int position = 0;
    for (int i = 1; i < n; i++) 
    {
        if (data[i] < min) 
        {
            min = data[i];
            position = i;
        }
    }
    return position;
}
int findMax(const int data[], int n) 
{
    int max = data[0];
    int posi = 0;
    for (int i = 1; i < n; i++)
    {
        if (data[i]> max) 
        {
            max = data[i];
            posi = i;
        }
    }
    return posi;
}


int main() 
{
    int number, count;
    int data[10] = {0,};

    ifstream infile("input_lab01-1.txt");
    count = 0;

    while (infile >> number) 
    {
        data[count++] = number;
    }

    int minnum = findMin(data, count);

    cout << "Minimum number is " << data[minnum] << " at position " << minnum + 1 << endl;
    

    int maxnum = findMax(data, count);

    cout << "Maximum number is " << data[maxnum] << " at position " << maxnum + 1 << endl;
    
    return 0;



}
