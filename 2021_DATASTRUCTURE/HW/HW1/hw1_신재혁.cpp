/*******************************************************************************************************************************
* Name : 신재혁
* Student ID : 20181636
* Program ID : hw1_신재혁.cpp
* Description :
* - data 파일로부터 불러온 데이터를 배열로 입력받는다.
* - 저장한 배열을 메인에서 요구받은 방식으로 구현한 좌측 우측 가운데 정렬 함수로 새로운 배열을 수정하여 출력한다. 
* Description :
* -main() 에서 출력 form을 맞춰준 후 n의 값을 입력받는다.
* -입력받은 값이 4가 아닐때 계속해서 while문 안에 switch case문을 돌려준다.
* -case 1번 좌측정렬 Left()함수를 call 한다
* -case 2번 우측정렬 Right()함수를 call한다.
* -case 3번 가운데정렬 Center()함수를 call한다.
* -case 4번이 나오면 while문을 정지 시킨다.
* -1. Left()함수는 hw1.txt파일을 입력받을 char 타입의 배열 buffer와 결과물을 출력할 char 타입의 배열 string buffer를 선언해준다.
* -hw1.txt파일을 fstream헤더의 getline()함수로 한줄씩 buffer 배열로 입력을 받는다.
* -또한 좌측정렬을 한 결과물을 출력할 char 타입의 배열 stringbuffer를 선언해준다.
* -정수형 변수 i 와 j를 0으로 초기화 하고  buffer 배열에서 문자일때까지 i++해준다.  i-> 데이터의 시작지점
* -그 후 buffer의 index i 부터 하나씩 늘려가며 stringbuffer배열에 j번째 index에 넣어주고 j++해준다.
* -j=0에서 1씩 +되기때문에 출력시 왼쪽 끝 index 즉 0번째 index부터 채워지며 죄측 정렬이 된다.
* -2. Right() 함수 마찬가지로 hw1.txt파일을 입력받을 char 타입의 배열 buffer와 결과물을 출력할 char 타입의 배열 string buffer를 선언해준다.
* -hw1.txt파일을 fstream헤더의 getline()함수로 한줄씩 buffer 배열로 입력을 받는다.
* -정수형 변수 i,j,k 0으로 초기화해준다.
* -buffer 배열의 i번째 idex 값이 문자일 때 까지 i++해준다. i-> 데이터의 시작지점
* -buffer 배열의  k번째 index 값을 입력 받은 배열 buffer 한 줄이 끝날때 까지 0으로 초기화 했던 k의 값을 늘려준다. 여기서 조건문에 \0이 있는 이유는 문장이 끝날 때 \0이 끝에 숨어있기 때문이다. k->데이터 한라인의 글자수
* -공백의 수는 80-글자의 수 이기때문에 80-k가 되는것이고 글자의 수를 뺀 공백의 수만큼 stringbuffer에  앞부터 인덱스를 0인 j의 값을 하나씩 늘려가며 공백수 만큼 늘려 공백으로 채워준다.
* -buffer의 i번째 index는 글자가 시작하는 부분이고 stringbuffer의 j번째 index는 글자가 시작해야 할 index값이다.
* -stringbuffer[j]=buffer[i]를 해주며 buffer[i]의 값이 한 줄이 끝날 때까지 i++ j++를 해주며 index값을 늘려가며 문자들로 채워준다.
* -그 후 stringbuffer의 마지막 index j의 자리에 \0를 추가해 줌으로써 stringbuffer의 오른쪽 정렬 배열이 마무리 된다.
* -Center()함수 마찬가지로 hw1.txt파일을 입력받을 char 타입의 배열 buffer와 결과물을 출력할 char 타입의 배열 string buffer를 선언해준다.
* -hw1.txt파일을 fstream헤더의 getline()함수로 한줄씩 buffer 배열로 입력을 받는다.
* -정수형 변수 i,j,k 0으로 초기화해준다.
* -buffer 배열의 i번째 idex 값이 문자일 때 까지 i++해준다. i-> 데이터의 시작지점
* -buffer의 k번째 index 값을 입력 받은 배열 buffer 한 줄이 끝날때 까지 0으로 초기화 했던 k의 값을 늘려준다.
* -그럼 k의 값은 글자의 수가 되는것이고 가운데 정렬의 특성상 80으로 정해놓은 배열의 한줄의 크기를 고려하여 앞뒤 공백의 수는 각각 (80-k)/2가 되는것이다. k->데이터 한라인의 글자수 
* -공백의 수 만큼 0으로 초기화한 j의 값을 늘려주면서 공백의 수 만큼 stringbuffer에 공백을 채워준다. 
* -그 후 buffer가 한줄이 끝날때 까지 stringbuffer[j]=buffer[i]를 해주며 i와 j의 값을 1씩 늘려준다.
* -buffer[i]가 끝난 값까지 stringbuffer[j]에 넣어주게 되면 가운데 정렬이 완성되게 된다.

* Variables :
* -Left() : 왼쪽 정렬 함수
* -Right() : 오른쪽 정렬 함수
* -Center() : 가운데 정렬 함수
* -buffer : char 타입의 입력값을 받는 배열
* -stringbuffer : char타입의 출력값을 저장하는 배열
* -i : 데이터 1라인의 시작점 인덱스 변수
* -j : 출력할 데이터의 인덱스 변수
* -k : 데이터 1라인의 글자 수 변수


*********************************************************************************************************************************/

#include<iostream>
#include<fstream>
#include<string>
#include<cstdio>


using namespace std;

/************************************************************
 * Function: Left
 * Descrption: Left의 사용 목적은 데이터를 왼쪽 정렬하기 위한 함수
 * **********************************************************/
void Left();

/************************************************************
 * Function: Right
 * Descrption: Right의 사용 목적은 데이터를 오른쪽 정렬하기 위한 함수
 * **********************************************************/
void Right();

/************************************************************
 * Function: Center
 * Descrption: Center의 사용 목적은 데이터를 가운데 정렬하기 위한 함수
 * **********************************************************/
void Center();


int main()
{
    
    int n=0;
    while (n!=4)
    {//입력받은 n의 값이 4 즉 terminate를 하겠다는 input값이 들어오기 전까지 계속 실행.
        cout << "**********************************"<<endl;
        cout << "1. Left     Justification"<<endl;
        cout << "2. Right    Justification"<<endl;
        cout << "3. Centered Justification"<<endl;
        cout << "4. Terminate "<<endl<<endl;
        cout <<"Enter your choice : ";
        cin >> n;
        cout<<endl;
        for(int i=0;i<8;i++)
        {
            for(int j=1;j<=10;j++) cout<<j%10;
        }
        cout<<endl<<endl;


        switch(n) 
        {//입력받은 n의 값에 따라 위에 출력한 옵션에 걸맞는 함수들을 call한다.
            case 1:
                Left();
                cout <<endl;
                break;
            case 2:
                Right();
                cout <<endl;
                break;
            case 3:
                Center();
                cout <<endl;
                break;
            default:
                break;
        }

        
    }
}

/************************************************************
* -Function: Left
* -Descrption: 사용 목적은 데이터를 왼쪽 정렬하기 위함
* -Variables: 
***************-buffer : 불러온 텍스트 파일 문자타입 변수
***************-stringbuffer : 왼쪽 정렬한 데이터 출력 변수
***************-i : 데이터 1라인의 시작점 index 변수
***************-j : 출력할 데이터의 index 변수
*************************************************************/
void Left()
{
    char buffer[80];//char 타입의 크기가 80인 배열 buffer 선언 -> infile한 데이터를 저장할 배열
    char stringbuffer[80];//char 타입의 크기가 80인 배열 stringbuffer 선언 -> 최종적으로 출력할 결과물을 저장할 배열
    ifstream infile;
    infile.open("hw1.txt", ios::in); //file open
    
    
    while(infile.getline(buffer,80))//크기가 80인 buffer에 한줄씩 입력받기
    {
        int i=0;
        int j=0;
       
        while(buffer[i] == ' ') i++;//문자형 데이터가 나올 때 까지 i값을 1씩 증가시킴
        while(buffer[j]!='\0')// 1라인 데이터의 끝을 만날때까지

        {
            stringbuffer[j]=buffer[i]; // 출력 버퍼로 데이터 복사
            i++;
            j++;
        }
        stringbuffer[j]='\0';
    
        cout << stringbuffer <<endl;
        
        
    }
    
}
/************************************************************
* Function: Right
* Descrption: 사용 목적은 데이터를 오른쪽 정렬하기 위함
* Variables: 
***************-buffer : 불러온 텍스트 파일 문자타입 변수
***************-stringbuffer : 오른쪽 정렬한 데이터 출력 변수
***************-i : 데이터 1라인의 시작점 index 변수
***************-j : 출력할 데이터의 index 변수
***************-k : 데이터 1라인의 글자 수 변수
**************************************************************/
void Right()
{
    char buffer[80];//char 타입의 크기가 80인 배열 buffer 선언 -> infile한 데이터를 저장할 배열
    char stringbuffer[80];//char 타입의 크기가 80인 배열 stringbuffer 선언 -> 최종적으로 출력할 결과물을 저장할 배열
    ifstream infile;
    infile.open("hw1.txt", ios::in);//file open
    while (infile.getline(buffer, 80)) //크기가 80인 buffer에 한줄씩 입력받기
    { // 1 라인을 읽음
        int i=0;
        int j=0;
        int k=0;
        while(buffer[i] == ' ') i++;//문자형 데이터가 나올 때 까지 i값을 1씩 증가시킴
        while(buffer[k]!='\0') k++;//한 줄의 데이터가 끝날 때 까지 k값을 증가시킴.-> k==한라인의 글자수

        for(int h=0; h<79-k; h++)//80-k가 공백의 수지만 마지막 index에 \0를 넣어줘야 함으로 79-k번
        {
            stringbuffer[j++]=' '; //0번째 index부터 79-k-1번째까지 공백 삽입
        }
        while(buffer[i]!='\0')//한줄의 데이터가 끝날때 까지
        {
            stringbuffer[j]=buffer[i]; //buffer데이터의 시작점부터 끝까지의 값을 공백을 넣은 j 번째 index의 stringbuffer배열에 추가해줌
            i++;
            j++;
        }
        stringbuffer[j]='\0'; // 마지막 index에 \0 추가
        
        cout << stringbuffer <<endl; //출력
    }
}
/************************************************************
* Function: Center
* Descrption: 사용 목적은 데이터를 가운데 정렬하기 위함
* Variables: 
***************-buffer : 불러온 텍스트 파일 문자타입 변수
***************-stringbuffer : 가운데 정렬한 데이터 출력 변수
***************-i : 데이터 1라인의 시작점 index 변수
***************-j : 출력할 데이터의 index 변수
***************-k : 데이터 1라인의 글자 수 변수
*************************************************************/
void Center()
{
    char buffer[80];//char 타입의 크기가 80인 배열 buffer 선언 -> infile한 데이터를 저장할 배열
    char stringbuffer[80];//char 타입의 크기가 80인 배열 stringbuffer 선언 -> 최종적으로 출력할 결과물을 저장할 배열
    ifstream infile;
    infile.open("hw1.txt", ios::in);//file open
    while (infile.getline(buffer, 80)) //크기가 80인 buffer에 한줄씩 입력받기
    { // 1 라인을 읽음
        int i=0;
        int j=0;
        int k=0;
        while(buffer[i] == ' ') i++;//문자형 데이터가 나올 때 까지 i값을 1씩 증가시킴
        while(buffer[k]!='\0') k++;//한 줄의 데이터가 끝날 때 까지 k값을 증가시킴.-> k==한라인의 글자수
        for(int h=0; h<(79-k)/2; h++)//(80-k)/2가 각각 앞뒤로 들어와야되는 공백의 수지만 마지막 index에 \0를 넣어줘야 함으로 (79-k)/2번
        {
            stringbuffer[j++]=' ';//0번째 index부터 (79-k)/2-1번째까지 공백 삽입
        }
        while(buffer[i]!='\0')//한줄의 데이터가 끝날때 까지
        {
            stringbuffer[j]=buffer[i]; //buffer데이터의 시작점부터 끝까지의 값을 공백을 넣은 j 번째 index의 stringbuffer배열에 추가해줌
            i++;
            j++;
        }
        stringbuffer[j]='\0';// 마지막 index에 \0 추가

        
        cout << stringbuffer <<endl; //출력
    }
}