#include<list>
#include <vector>
#include<iostream>

template<class T>
class Almacen{
public:
    Almacen(int espacios){
        for(int i = 0; i < espacios; i++){
            std::cout << "ingresa tu item" << std::endl;
            std::cin >> item;
            cola.push_front(item);
        }
    }
    bool empty(){
        if(cola.size() > 0)
            return false;
        else
            return true;
    }
    int size(){
        return cola.size();
    }
    void add(T begin, T end){
        cola.push_back(end);
        cola.push_front(begin);
    }
    void deletePos(int posicion){
        std::list<int>::iterator it;
        it = cola.begin();
        for(int i = 0; i <= posicion; i++){
            ++it;
        }
        cola.erase(it);
    }
private:
    std::list<T> cola;
    T item;
};