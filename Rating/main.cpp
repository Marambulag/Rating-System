#include <iostream>
#include "clase.hpp"
#include "serie.hpp"
#include <vector>

int main() {
    video pelicula1(1, "Inception", 2010, 148, "Sci-Fi", 0);
    video pelicula2(2, "The Dark Knight", 2008, 152, "Action", 0);
    video pelicula3(3, "Interstellar", 2014, 169, "Sci-Fi", 0);
    video pelicula4(4, "The Godfather", 1972, 175, "Crime", 0);
    video pelicula5(5, "Pulp Fiction", 1994, 154, "Crime", 0);

    serie serie1(6, "Game of Thrones", 2011, 60, "Drama", 0, "1: Winter Is Coming, 2: The Kingsroad, 3: Lord Snow", "Season 1", 10, "Game of Thrones");
    serie serie2(7, "Breaking Bad", 2008, 47, "Drama", 0, "1: Pilot, 2: Cat's in the Bag..., 3: And the Bag's in the River", "Season 1", 7, "Breaking Bad");
    serie serie3(8, "Friends", 1994, 22, "Comedy", 0, "1: The One Where Monica Gets a Roommate, 2:The One with the Sonogram at the End, 3:The One with the Thumb", "Season 1", 24, "Friends");
    serie serie4(9, "Stranger Things", 2016, 51, "Drama", 0, "Chapter One: The Vanishing of Will Byers, Chapter Two: The Weirdo on Maple Street, Chapter Three: Holly, Jolly", "Season 1", 8, "Stranger Things");
    serie serie5(10, "The Crown", 2016, 58, "Drama", 0, "1: Wolferton Splash, 2: Hyde Park Corner, 3: Windsor", "Season 1", 10, "The Crown");

    std::vector<video*> videos = { &pelicula1, &pelicula2, &pelicula3, &pelicula4, &pelicula5, &serie1, &serie2, &serie3, &serie4, &serie5 };

    while (true) {
        int opcion;
        std::cout << "Peliculas en orden 1 a 5:" << std::endl;
        std::cout << "------------------------" << std::endl;
        for (int i = 0; i < 5; ++i) {
            videos[i]->Menu();
        }
       
        std::cout << "Series en orden 6 a 10:" << std::endl;
        std::cout << "------------------------" << std::endl;
        for (int i = 5; i < 10; ++i) {
            videos[i]->Menu();
        }
       
        std::cout << "Seleccione la pelicula o serie a calificar (1-10), 11 para filtrar por genero o 0 para salir: ";
        std::cin >> opcion;

        if (opcion == 0) {
            break;
        } else if (opcion == 11) {
            std::string genero;
            std::cout << "Ingrese el genero por el cual quiere filtrar: Drama, Comedy, Sci-Fi, Crime, Action: ";
            std::cin >> genero;
            clearScreen();
            video::FiltrarPorGenero(videos, genero);
        } else if (opcion >= 1 && opcion <= 10) {
            clearScreen();
            videos[opcion - 1]->GetInfo();
            videos[opcion - 1]->Calificar();
        } else {
            std::cout << "Opcion invalida. Por favor seleccione un numero entre 1 y 11, o 0 para salir." << std::endl;
        }
    }

    video* mejor_pelicula = videos[0];
    for (int i = 1; i < 5; ++i) {
        if (*videos[i] > *mejor_pelicula) {
            mejor_pelicula = videos[i];
        }
    }
    std::cout << "Tu pelicula favorita es: " << std::endl;
    mejor_pelicula->GetInfo();

    video* mejor_serie = videos[5];
    for (int i = 6; i < 10; ++i) {
        if (*videos[i] > *mejor_serie) {
            mejor_serie = videos[i];
        }
    }

    std::cout << "Tu serie favorita es: " << std::endl;
    mejor_serie->GetInfo();

    std::cout << "Sesion cerrada, Gracias por visitarnos!" << std::endl;

    return 0;
}