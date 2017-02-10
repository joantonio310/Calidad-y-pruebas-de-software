#pragma once

#include"VideoJuego.h"
#include<iostream>

using namespace std;

class FabricaJuegos
{
protected:
    VideoJuego* game;
    void concepcion(){ cout << "en concepcion" << endl; }
    void disenio(){ cout << "en disenio" << endl; }
    void planificacion(){ cout << "en planificacion" << endl; }
    void produccion(){ cout << "en produccion" << endl; }
    void pruebasAceptacion(){ cout << "en pruebasAceptacion" << endl; }
public:
    void crearJuego(VideoJuego*& game, string categoria, VideoJuego::tipo tipo_juego, string nombre, int num_serie)
    {
        if(categoria == "Aventura")
         {
             string rate_category = "a";
             game = new Aventura(nombre, num_serie,  tipo_juego, rate_category);
         }
         if(categoria == "Estrategia")
         {
             int number_of_players = 3;
             game = new Estrategia(nombre, num_serie, tipo_juego, number_of_players);
         }
         if(categoria == "Aprendizaje")
         {
             int num_niveles = 4;
             game = new Aprendizaje(nombre, num_serie, tipo_juego, num_niveles);
         }
    }
};