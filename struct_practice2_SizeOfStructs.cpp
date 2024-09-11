#include <iostream>
using namespace std;

struct One{     // This means that the overall size of a struct is determined by the data type within it that requires the most memory
    int a, b;   // for this case is int
    char c, d;  //  [      a        ] = 4 bytes  
                //  [      b        ] = 4 bytes  
                //  [c ][ d ][  ][  ] = 4 bytes
};              // size = 12

struct Two{        // One char = 1 byte
    char c, d;     // [ c ][ d ] = 2 bytes
};                 // size = 2

struct Three{   // size of a pointer is 4 in 32 bit system and 8 in 64 bit 
    int *a;     // [*a][*a][*a][*a][*a][*a][*a][*a] = 8bytes
    int b, c;   // [b ][b ][b ][b ][c ][c ][c ][c ] = 8 bytes
};              // size = 16

struct Four{     // int arr[3] - an array of integers 
    int arr[3];  // [arr][arr][arr][arr] = 4
    char a, b;   // [arr][arr][arr][arr] = 4
    int c, d;    // [arr][arr][arr][arr] = 4
                 // [ a ][ b ][   ][   ] = 4  / still 4 even if it's empty because int can't fit in there
                 // [ c ][ c ][ c ][ c ] = 4
                 // [ d ][ d ][ d ][ d ] = 4
};

struct Five{ 
    double a;  // [ a ][ a ][ a ][ a ][ a ][ a ][ a ][ a ] = 8
    float b;   // [ b ][ b ][ b ][ b ][ c ][ c ][ c ][ c ] = 8
    int c;     // [ d ][   ][   ][   ][   ][   ][   ][   ] = 8 
    char d;    // [ *e][ *e][ *e][ *e][ *e][ *e][ *e][ *e] = 8
    int *e;    // size = 32
};             //(P.S im using dev c++) / dev c++ and vscode have different sizes when it come to pointers

struct Six{
    int** a;  // size =  8
};

struct Seven{
    string str; // vscode size = 24 // dev c size = 8;
};


int main(){
    cout << "Size of struct One is " << sizeof(One) << " bytes" << endl;
    cout << "Size of struct Two is " << sizeof(Two) << " bytes" << endl;
    cout << "Size of struct Three is " << sizeof(Three) << " bytes" << endl;
    cout << "Size of struct Four is " << sizeof(Four) << " bytes" << endl;
    cout << "Size of struct Five is " << sizeof(Five) << " bytes" << endl;
    cout << "Size of struct Six is " << sizeof(Six) << " bytes" << endl;
    cout << "Size of struct Seven is " << sizeof(Seven) << " bytes" << endl;
}
