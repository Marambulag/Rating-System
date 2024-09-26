#ifndef MOVIE_HPP
#define MOVIE_HPP
#include <iostream>
#include <string>
#include <vector>

void clearScreen();

class video {
public:
    video(int id, std::string titulo, int anio, int duracion, std::string genero, double calificacion);
    
    virtual void GetInfo();
    virtual void Menu();
    virtual void Calificar();
   
    friend bool operator >(const video& object1, const video& object2);
    static void FiltrarPorGenero(const std::vector<video*>& videos, const std::string& genero);

protected:
    int id_;
    std::string titulo_;
    int anio_;
    int duracion_;
    std::string genero_;
    double calificacion_;
    std::vector<int> calificaciones_;
};

#endif 