#include<iostream>
using namespace std;

bool bisiesto(int year){
    if((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))
        cout << "verdadero" << endl;
    else
        cout << "falso" << endl;
}

int main(int argc, char** argv){
    if(argc == 2){
        bisiesto(argc);
    }
}