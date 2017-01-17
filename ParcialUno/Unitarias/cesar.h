#include<string>
#include<iostream>
#include <fstream>
using namespace std;

void buscarTexto(string palabra){
    string line;
    ifstream myfile ("diccionario.txt");
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            if(line == palabra){
                cout << "encontrado" << endl;
                break;
            }
        }
        myfile.close();
    }
}

void buscar(){
    string borrador;
    string name;
    string line;
    
    printf("Put the name of the file you want to read\n");
    cin >> name;   //read the input
 
    ifstream myfile (name);
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            break;
        }
        myfile.close();
    }

    else cout << "Unable to open file"; 
    
    borrador = line;
    for(int i = 1; i < 26; i++){
        for(int j = 0; j < line.size(); j++){
            if((int)line[j] + i > 90)
                borrador[j] = (int)line[j] + i - 90 + 64;
            else
                borrador[j] = (int)line[j] + i;
        }
        cout << borrador << endl;
        buscarTexto(borrador);
    }
    
}