#pragma once
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

template<class T>
bool productoEncontrado(T* t);

template<class Articulo>
class Almacen
{
    int posicionActual;
    int tamano;
    Articulo** arreglo;

public:

    static string nombreParaEncontrar;
    Almacen()
    {
        tamano = 100;
        arreglo = new Articulo*[tamano];
        posicionActual = 0;
    }

    virtual ~Almacen() {
      delete[] arreglo;
    }
    void agregar(Articulo* t)
    {
        if(posicionActual >= tamano)
        {
            cout << "no hay espacio para almacenar";
            return;
        }
        arreglo[posicionActual++] = t;
        return;
    }
    void eliminar(Articulo* t)
    {

    }
    void print()
    {
        for(int i=0; i<posicionActual; i++)
        {
            arreglo[i]->print();
        }
    }

    VideoJuego** encontrarPorNombre(string name)
    {
            return NULL;
    }
};

template<class T>
string Almacen<T>::nombreParaEncontrar = "";

template<class T>
bool productoEncontrado(T* t)
{
    return (t->getName().compare(Almacen<T>::nombreParaEncontrar) == 0);
}