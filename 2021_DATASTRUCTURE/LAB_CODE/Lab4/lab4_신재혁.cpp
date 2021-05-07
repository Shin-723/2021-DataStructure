/*******************************************************************************************************************************
* Name : 신재혁
* Student ID : 20181636
*********************************************************************************************************************************/

#include <iostream>
#include <fstream>
#define MAX_SIZE 36 

using namespace std;

struct matrix
{ 
    int row;
    int col;
    int value;
};

void original();
void Sparse();
void Trans_Sparse(matrix a[], matrix b[]);
void Fast_Trans(matrix a[], matrix b[]);

matrix A[6][6]; 
matrix SparseA[MAX_SIZE];
matrix TransSparseA[MAX_SIZE];
matrix Fast_TransA[MAX_SIZE];


int main(){

    original();
    cout << endl;

    Sparse();
    cout << endl;

    Trans_Sparse(SparseA, TransSparseA);
    cout << endl;

    Fast_Trans(TransSparseA, Fast_TransA);
    cout << endl;

    return -1;
}

void original()
{

    ifstream infile;

    infile.open("lab4.txt", ios::in);
    
    if(infile.fail())
    { 
        cout << "can't open the input file" << endl;
        exit(1);
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            infile >> A[i][j].value;
            A[i][j].col = i;
            A[i][j].row = j;
            
        }
    }

    infile.close(); 

    cout << "1) Original Matrix : A " << endl;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << A[i][j].value << " ";
        }
        cout << endl;
    }
    
    cout << endl;

}


void Sparse(){

    int ValueNum = 0;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (A[i][j].value != 0)
            {
                ValueNum += 1;
            }
        }
    }
   
    SparseA[0].row = 6; 
    SparseA[0].col = 6; 
    SparseA[0].value = ValueNum; 

    int location = 1; 

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (A[i][j].value != 0)
            {
                SparseA[location].row = i;
                SparseA[location].col = j;
                SparseA[location].value = A[i][j].value;
                location += 1;
            }
        }
    }

    cout << "2) (matrix B) - row major " << endl;

    for (int i = 1; i < ValueNum+1; i++)
    { 
        cout << SparseA[i].row << " " << SparseA[i].col << " " << SparseA[i].value << endl;
    }

}

void Trans_Sparse(matrix a[], matrix b[])
{ 
    
    int i, j, currentb;

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = a[0].value;

    if (a[0].value > 0) 
    {
        currentb = 1; 
        for (int i = 0; i < a[0].col; i++)
        { 
            for (int j = 0; j <= a[0].value; j++)
            { 
                if (a[j].col == i)
                { 
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].value = a[j].value;
                    currentb += 1;
                }
            }
        }
    }

    cout << "3) (Btrans) - Transposed matrix B, column major " << endl;

    for (int i = 1; i < currentb; i++)
    {
        cout << b[i].row << " " << b[i].col << " " << b[i].value << endl;
    }

}

void Fast_Trans(matrix a[], matrix b[])
{

    int row_terms[MAX_SIZE], starting_pos[MAX_SIZE];
    int i, j, num_cols = a[0].col, num_terms = a[0].value;

    b[0].row = num_cols; 
    b[0].col = a[0].row; 
    b[0].value = num_terms; 

    if (num_terms > 0)
    {
        for (int i = 0; i <num_cols; i++)
        {
            row_terms[i] = 0; 
        }

        for (int i = 1; i <= num_terms; i++)
        {
            row_terms[a[i].col]++; 
        }

        starting_pos[0] = 1; 

        for (int i = 1; i < num_cols; i++)
        { 
            starting_pos[i] = starting_pos[i-1] + row_terms[i-1];
        }

        for (int i = 1; i <= num_terms; i++)
        { 
            j = starting_pos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }

    cout << "4) (matrix B) -Fast transpose (Btrans -> B) " << endl;

    for (int i = 1; i < num_terms + 1; i++)
    {
        cout << b[i].row << " " << b[i].col << " " << b[i].value << endl;
    }
    
}

