#include <iostream>
#include <iomanip>
#include <vector>
#include "movie.hpp"
#include "serie.hpp"

// Color definitions
const std::string reset = "\033[0m";      // Reset to default color
const std::string red = "\033[31m";        // Red color
const std::string yellow = "\033[33m";     // Yellow color
const std::string green = "\033[32m";      // Green color
const std::string blue = "\033[34m";       // Blue color
const std::string cyan = "\033[36m";       // Cyan color

void printBanner() {
    std::cout << red << "======================================" << reset << std::endl;
    std::cout << yellow << "      Welcome to the Rating System    " << reset << std::endl;
    std::cout << red << "======================================" << reset << std::endl;
}

void printSeparator() {
    std::cout << blue << "--------------------------------------" << reset << std::endl;
}

void printMenu() {
    std::cout << "\n" << cyan << "Please choose an option:" << reset << std::endl;
    std::cout << green << "1. Rate a Movie" << reset << std::endl;
    std::cout << green << "2. Rate a Series" << reset << std::endl;
    std::cout << green << "3. Filter by Genre" << reset << std::endl;
    std::cout << green << "0. Exit" << reset << std::endl;
    std::cout << red << "======================================" << reset << std::endl;
    std::cout << "Your choice: ";
}

int main() {
    printBanner();

    // Movies
    std::vector<video> movies = {
        video(1, "Inception", 2010, 148, "Sci-Fi", 0),
        video(2, "The Dark Knight", 2008, 152, "Action", 0),
        video(3, "Interstellar", 2014, 169, "Sci-Fi", 0),
        video(4, "The Godfather", 1972, 175, "Crime", 0),
        video(5, "Pulp Fiction", 1994, 154, "Crime", 0),
        video(6, "The Shawshank Redemption", 1994, 142, "Drama", 0),
        video(7, "Schindler's List", 1993, 195, "Biography", 0),
        video(8, "The Lord of the Rings: The Return of the King", 2003, 201, "Fantasy", 0),
        video(9, "Fight Club", 1999, 139, "Drama", 0),
        video(10, "Forrest Gump", 1994, 142, "Drama", 0),
        video(11, "The Matrix", 1999, 136, "Sci-Fi", 0),
        video(12, "Goodfellas", 1990, 146, "Crime", 0),
        video(13, "The Silence of the Lambs", 1991, 118, "Thriller", 0),
        video(14, "Se7en", 1995, 127, "Thriller", 0),
        video(15, "The Usual Suspects", 1995, 106, "Crime", 0),
        video(16, "Gladiator", 2000, 155, "Action", 0),
        video(17, "The Social Network", 2010, 120, "Biography", 0),
        video(18, "Avatar", 2009, 162, "Sci-Fi", 0),
        video(19, "Titanic", 1997, 195, "Romance", 0),
        video(20, "The Avengers", 2012, 143, "Action", 0)
    };

    // Series
    std::vector<serie> series = {
        serie(1, "Game of Thrones", 2011, 60, "Drama", 0, "1: Winter Is Coming", "Season 1", 10, "Game of Thrones"),
        serie(2, "Breaking Bad", 2008, 47, "Drama", 0, "1: Pilot", "Season 1", 7, "Breaking Bad"),
        serie(3, "Stranger Things", 2016, 50, "Sci-Fi", 0, "1: Stranger Things", "Season 1", 8, "Stranger Things"),
        serie(4, "The Crown", 2016, 58, "Biography", 0, "1: Wolfe", "Season 1", 10, "The Crown"),
        serie(5, "The Mandalorian", 2019, 39, "Sci-Fi", 0, "1: Chapter 1", "Season 1", 8, "The Mandalorian"),
        serie(6, "The Office", 2005, 22, "Comedy", 0, "1: Pilot", "Season 1", 9, "The Office"),
        serie(7, "Friends", 1994, 22, "Comedy", 0, "1: The One Where Monica Gets a Roommate", "Season 1", 10, "Friends"),
        serie(8, "Sherlock", 2010, 90, "Mystery", 0, "1: A Study in Pink", "Season 1", 4, "Sherlock"),
        serie(9, "Narcos", 2015, 49, "Crime", 0, "1: Descenso", "Season 1", 10, "Narcos"),
        serie(10, "The Witcher", 2019, 60, "Fantasy", 0, "1: The End's Beginning", "Season 1", 8, "The Witcher"),
        serie(11, "Westworld", 2016, 68, "Sci-Fi", 0, "1: The Original", "Season 1", 10, "Westworld"),
        serie(12, "The Boys", 2019, 60, "Action", 0, "1: The Name of the Game", "Season 1", 8, "The Boys"),
        serie(13, "Ozark", 2017, 58, "Crime", 0, "1: Sugarwood", "Season 1", 4, "Ozark"),
        serie(14, "Better Call Saul", 2015, 45, "Drama", 0, "1: Uno", "Season 1", 6, "Better Call Saul"),
        serie(15, "Dark", 2017, 60, "Sci-Fi", 0, "1: Secrets", "Season 1", 3, "Dark"),
        serie(16, "The Walking Dead", 2010, 42, "Horror", 0, "1: Days Gone Bye", "Season 1", 11, "The Walking Dead"),
        serie(17, "Money Heist", 2017, 70, "Action", 0, "1: Episode 1", "Season 1", 5, "Money Heist"),
        serie(18, "The Handmaid's Tale", 2017, 52, "Drama", 0, "1: Offred", "Season 1", 4, "The Handmaid's Tale"),
        serie(19, "Fargo", 2014, 50, "Crime", 0, "1: The Crocodile's Dilemma", "Season 1", 4, "Fargo"),
        serie(20, "The Good Place", 2016, 22, "Comedy", 0, "1: Everything is Fine", "Season 1", 4, "The Good Place")
    };

    std::vector<video*> videos;
    for (int i = 0; i < movies.size(); ++i) {
        videos.push_back(&movies[i]);
    }
    for (int i = 0; i < series.size(); ++i) {
        videos.push_back(&series[i]);
    }

    while (true) {
        printMenu();
        int opcion;
        std::cin >> opcion;

        if (opcion == 0) {
            break;
        }

        switch (opcion) {
            case 1: {
                clearScreen();
                std::cout << yellow << "Movies: " << reset << std::endl;
                printSeparator();
                for (int i = 0; i < movies.size(); ++i) {
                    videos[i]->Menu();
                }
                std::cout << "Choose a movie to rate (1-20): ";
                int movie_choice;
                std::cin >> movie_choice;
                if (movie_choice >= 1 && movie_choice <= 20) {
                    clearScreen();
                    videos[movie_choice - 1]->GetInfo();
                    videos[movie_choice - 1]->Calificar();
                } else {
                    std::cout << red << "Invalid choice!" << reset << std::endl;
                }
                break;
            }
            case 2: {
                clearScreen();
                std::cout << yellow << "Series: " << reset << std::endl;
                printSeparator();
                for (int i = 0; i < series.size(); ++i) {
                    videos[movies.size() + i]->Menu();
                }
                std::cout << "Choose a series to rate (21-40): ";
                int series_choice;
                std::cin >> series_choice;
                if (series_choice >= 21 && series_choice <= 40) {
                    clearScreen();
                    videos[series_choice - 1]->GetInfo();
                    videos[series_choice - 1]->Calificar();
                } else {
                    std::cout << red << "Invalid choice!" << reset << std::endl;
                }
                break;
            }
            case 3: {
                clearScreen();
                std::cout << yellow << "Filter by genre:" << reset << std::endl;
                std::string genre;
                std::cout << "Enter genre (e.g., Sci-Fi, Drama): ";
                std::cin >> genre;
                video::FiltrarPorGenero(videos, genre);
                break;
            }
            default:
                std::cout << red << "Invalid option. Please choose a valid option." << reset << std::endl;
        }
    }

    std::cout << "\n" << green << "Thank you for using the Rating System. Goodbye!" << reset << std::endl;
    return 0;
}