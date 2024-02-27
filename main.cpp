#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <climits>
#include <chrono>
#include "studentas.h"
#include "funkcijos.h"

int main() {
    srand(time(0));
    std::vector<Studentas> studentai;
    int meniuPasirinkimas = 0;
    do {
        std::cout << "Meniu:\n"
            << "1 - Įvesti duomenis ranka\n"
            << "2 - Generuoti pažymius\n"
            << "3 - Generuoti pažymius ir studentų vardus, pavardes\n"
            << "4 - Nuskaityti studentų duomenis iš failo\n"
            << "5 - Baigti darbą\n"
            << "Pasirinkimas: ";
        meniuPasirinkimas = patikrintiSkaiciu(1, 5);
        switch(meniuPasirinkimas){
           case 1: {
                //duomenys įvedami ranka
                Studentas naujasStudentas;
                std::cout << "  Įveskite studento vardą: ";
                std::cin >> naujasStudentas.vardas;
                std::cout << "  Įveskite studento pavardę: ";
                std::cin >> naujasStudentas.pavarde;
                std::cout << "  Įveskite studento egzamino rezultatą: ";
                naujasStudentas.egz = patikrintiSkaiciu(0, 10);
                while (true) {
                    std::cout << "    Įveskite #" << naujasStudentas.namuDarbai.size() + 1 << " namų darbo rezultatą (0-10), -1 baigia įvedimą: ";
                    int pazymys = patikrintiSkaiciu(-1, 10);
                    if (pazymys == -1)
                        break;
                    naujasStudentas.namuDarbai.push_back(pazymys);
                    naujasStudentas.sum += pazymys;
                }
                naujasStudentas.apskaiciuotiGalutini();
                studentai.push_back(naujasStudentas);
                break;
            }
            case 2: {
                //atsitiktinai generuojami tik pažymiai
                Studentas naujasStudentas;
                std::cout << "  Įveskite studento vardą: ";
                std::cin >> naujasStudentas.vardas;
                std::cout << "  Įveskite studento pavardę: ";
                std::cin >> naujasStudentas.pavarde;
                std::cout << "  Įveskite studento egzamino rezultatą: ";
                naujasStudentas.egz = patikrintiSkaiciu(0, 10);
                std::cout << "  Įveskite namų darbų skaičių: ";
                int n = patikrintiSkaiciu(0, INT_MAX);
                for (int v = 0; v < n; v++) {
                    int pazymys = rand() % 10 + 1;
                    naujasStudentas.namuDarbai.push_back(pazymys);
                    naujasStudentas.sum += pazymys;
                }
                naujasStudentas.apskaiciuotiGalutini();
                studentai.push_back(naujasStudentas);
                break;
            }
            case 3: {
                //atsitiktinai generuojami studento vardas, pavardė bei pažymiai
                std::cout << "  Įveskite studentų skaičių: ";
                int studentuSkaicius = patikrintiSkaiciu(0, INT_MAX);
                std::cout << "  Įveskite maksimalų namų darbų skaičių: ";
                int maxNamuDarbu = patikrintiSkaiciu(0, INT_MAX);
                for (int i = 0; i < studentuSkaicius; i++) {
                    Studentas naujasStudentas;
                    generuotiVardaIrPavarde(naujasStudentas.vardas, naujasStudentas.pavarde);
                    naujasStudentas.egz = rand() % 10 + 1;
                    int n = rand() % maxNamuDarbu + 1;
                    for (int v = 0; v < n; v++) {
                        int pazymys = rand() % 10 + 1;
                        naujasStudentas.namuDarbai.push_back(pazymys);
                        naujasStudentas.sum += pazymys;
                    }
                    naujasStudentas.apskaiciuotiGalutini();
                    studentai.push_back(naujasStudentas);
                }
                break;
            }
            case 4: {
                //failo nuskaitymas
                std::string failoPavadinimas;
                system("dir *.txt");
                std::cout << "  Įveskite failo pavadinimą: ";
                std::cin >> failoPavadinimas;
                skaitytiIsFailo(studentai, failoPavadinimas);
                break;
            }
            case 5:{
                //darbo baigimas, rūšiavimas
                std::cout << "Rūšiuoti pagal:\n1 - Vardą\n2 - Pavardę\n3 - Galutinį (Vid.)\n4 - Galutinį (Med.)\nPasirinkimas: ";
                int rusiavimoPasirinkimas = patikrintiSkaiciu(1, 4);
                auto start = std::chrono::high_resolution_clock::now();
                switch (rusiavimoPasirinkimas) {
                    case 1:
                        std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
                            return a.vardas > b.vardas; });
                        break;
                    case 2:
                        std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
                            return a.pavarde > b.pavarde; });
                        break;
                    case 3:
                        std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
                            return a.galutinisVid > b.galutinisVid; });
                        break;
                    case 4:
                        std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
                            return a.galutinisMed > b.galutinisMed; });
                        break;
                    default:
                        std::cout << "Netinkamas pasirinkimas, naudojamas numatytasis (Vardas).\n";
                        std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
                            return a.vardas > b.vardas; });
                }
                std::cout << "Rūšiavimas užtruko " << (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count())/1000.0 << " s\n";
                break;
            }
            default:
                std::cout << "Netinkamas pasirinkimas, bandykite iš naujo.\n";
        }
    } while(meniuPasirinkimas != 5);
    std::cout << "Išvesti į:\n1 - Konsolę\n2 - Failą\nPasirinkimas: ";
    int isvestiesPasirinkimas = patikrintiSkaiciu(1, 2);
    if (isvestiesPasirinkimas == 2) {
        std::cout << "Įveskite failo pavadinimą: ";
        std::string failoPavadinimas;
        std::cin >> failoPavadinimas;
        std::ofstream rezultatuFailas(failoPavadinimas);
        if (rezultatuFailas.is_open()) {
            rezultatuFailas << "Pavardė       Vardas        Galutinis (Vid.)  Galutinis (Med.)\n";
            rezultatuFailas << "-----------------------------------------------------------------\n";
            for (const auto& studentas : studentai) {
                rezultatuFailas << std::left << std::setw(14) << studentas.pavarde << std::setw(14) << studentas.vardas
                                << std::setw(18) << std::fixed << std::setprecision(2) << studentas.galutinisVid
                                << std::setw(18) << studentas.galutinisMed << '\n';
            }
            rezultatuFailas.close();
            std::cout << "Duomenys išsaugoti faile: " << failoPavadinimas << '\n';
        } else {
            std::cout << "Nepavyko atidaryti failo rašymui: " << failoPavadinimas << '\n';
        }
    } else {
        std::cout << "Pavardė       Vardas        Galutinis (Vid.)  Galutinis (Med.)\n";
        std::cout << "-----------------------------------------------------------------\n";
        for (const auto& studentas : studentai) {
            std::cout << std::left << std::setw(14) << studentas.pavarde << std::setw(14) << studentas.vardas
                      << std::setw(18) << std::fixed << std::setprecision(2) << studentas.galutinisVid
                      << std::setw(18) << studentas.galutinisMed << '\n';
        }
    }
    std::cin.get();
    std::cin.get();
    return 0;
}