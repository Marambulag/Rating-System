#ifndef SERIE_HPP
#define SERIE_HPP
#include "movie.hpp"

class serie : public video {
private:
    int numeroepisodios_;
    std::string tituloepisodio_;
    std::string temporada_;
    std::string nombreSerie_;

public:
    serie(int id, std::string titulo, int anio, int duracion, std::string genero, double calificacion,
          std::string tituloepisodio, std::string temporada, int numeroepisodios, std::string nombreserie);
    void GetInfo() override;
    void Menu() override;
    void Calificar() override;
};

#endif 