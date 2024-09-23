#include "clase.hpp"
#include <cstdlib> 

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

video::video(int id, std::string titulo, int anio, int duracion, std::string genero, double calificacion)
    : id_(id), titulo_(titulo), anio_(anio), duracion_(duracion), genero_(genero), calificacion_(calificacion) {}

void video::GetInfo() {
    std::cout << "ID: " << id_ << std::endl;
    std::cout << "Titulo: " << titulo_ << std::endl;
    std::cout << "Anio: " << anio_ << std::endl;
    std::cout << "Duracion: " << duracion_ << " minutos" << std::endl;
    std::cout << "Genero: " << genero_ << std::endl;
    std::cout << "Calificacion: " << calificacion_ << std::endl;
}

void video::Menu() {
    std::cout << titulo_ << std::endl;
}

void video::Calificar() {
    int numero;
    std::cout << "Califica la pelicula del 1 al 5: ";
    std::cin >> numero;
    if (numero < 1 || numero > 5) {
        std::cout << "Calificacion invalida. Por favor ingresa un numero entre 1 y 5." << std::endl;
    } else {
        calificaciones_.push_back(numero);
        double suma = 0;
        for (int calif : calificaciones_) {
            suma += calif;
        }
        calificacion_ = suma / calificaciones_.size();
        std::cout << "Nueva calificacion es: " << calificacion_ << std::endl;
    }
}

bool operator >(const video& object1, const video& object2) {
    return object1.calificacion_ > object2.calificacion_;
}

void video::FiltrarPorGenero(const std::vector<video*>& videos, const std::string& genero) {
    for (const auto& v : videos) {
        if (v->genero_ == genero) {
            v->GetInfo();
            std::cout << "------------------------" << std::endl;
        }
    }
}