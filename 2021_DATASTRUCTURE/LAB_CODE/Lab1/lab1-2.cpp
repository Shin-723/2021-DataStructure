//////////////////////////////////////////////////////
//Name: 신재혁
//ID: 20181636
//Program Description: Exercising File I/O
//Algorithm: 데이터 파일에서 한 줄씩 리딩-> 기준을 공백으로 잡고 단어를 세어 저장 -> 총 단어 갯수에 더하기 -> 리딩한 것과 단어 갯수 출력
//Variable: buffer[]: 데이터 파일에서 데이터를 저장하는 역할
///////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

void WordCount(string buffer, int *wc) 
{
    int i = 0;
    const int IN = 1 , OUT = 0; //단어 시작할 때 IN
    int state = 0;
    *wc = 0;

    while (buffer[i] != '\0') 
    { //한 줄 끝날 때 까지
        if (isalpha(buffer[i])) //영단어 판별
        {
            if (state == OUT) //out 상태일때
            { 
                ++*wc;
                state = IN; //문자인 조건과 state = IN 이면 아무것도 하지 않음
            }
        } else if (buffer[i] == ' ') //공백이 있을떄
        {
            state = OUT; //상태 OUT
        }
        i++;
    }
}

int main() {

    ifstream infile;

    char buffer[80];
    int wc = 0;
    int total = 0;

    infile.open("lab1-2.txt", ios::in);

    if (infile.fail()) 
    {
        cout << "can't open the input file" << endl;
        exit(1);
    }

    while (infile.getline(buffer, 80)) 
    {
        cout << buffer << endl;
        WordCount(buffer, &wc);
        cout << wc << endl;
        total = total + wc;
    }
    cout << endl;
    cout << "Total Number of Words :" << total << endl;

    return 0;
}
