#include "serie.hpp"

serie::serie(int id, std::string titulo, int anio, int duracion, std::string genero, double calificacion,
             std::string tituloepisodio, std::string temporada, int numeroepisodios, std::string nombreserie)
    : video(id, titulo, anio, duracion, genero, calificacion),
      tituloepisodio_(tituloepisodio), temporada_(temporada),
      numeroepisodios_(numeroepisodios), nombreSerie_(nombreserie) {}

void serie::GetInfo() {
    std::cout << "Nombre de la serie: " << nombreSerie_ << std::endl;
    std::cout << "Episodios: " << tituloepisodio_ << std::endl;
    std::cout << "Temporada: " << temporada_ << std::endl;
    std::cout << "Numero de episodios: " << numeroepisodios_ << std::endl;
    std::cout << "Calificacion: " << calificacion_ << std::endl;
}

void serie::Menu() {
    std::cout << titulo_ << std::endl;
}

void serie::Calificar() {
    int numero;
    std::cout << "Califica la serie del 1 al 5: ";
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