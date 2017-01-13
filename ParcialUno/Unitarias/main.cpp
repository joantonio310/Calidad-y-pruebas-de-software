#include"Almacen.h"
#include<iostream>

int main(){
    Almacen<int>hola(3);
    hola.add(3,3);
    std::cout << hola.size() << std::endl;
    hola.deletePos(0);
    std::cout << hola.empty() << std::endl;
    std::cout << hola.size() << std::endl;
}