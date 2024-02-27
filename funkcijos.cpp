#include "funkcijos.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <chrono>


int patikrintiSkaiciu(int maziausias, int didziausias) {
    int skaicius;
    while (true) {
        std::cin >> skaicius;
        if (std::cin.fail() || skaicius < maziausias || skaicius > didziausias) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Neteisingai įvestas skaičius, bandykite dar kartą: ";
        } else {
            return skaicius;
        }
    }
}

void generuotiVardaIrPavarde(std::string& vardas, std::string& pavarde) {
    std::vector<std::string> vardai{"Jonas", "Petras", "Antanas", "Kazys", "Simas"};
    std::vector<std::string> pavardes{"Jonaitis", "Petraitis", "Antanaitis", "Kazlauskas", "Simaitis"};
    vardas = vardai[rand() % 5];
    pavarde = pavardes[rand() % 5];
}

void skaitytiIsFailo(std::vector<Studentas>& studentai, const std::string& failoPavadinimas) {
    auto start = std::chrono::high_resolution_clock::now();
    std::ifstream failas(failoPavadinimas);
    if (!failas.is_open()) {
        std::cout << "Nepavyko atidaryti failo: " << failoPavadinimas << '\n';
        return;
    }
    std::string eilute;
    std::getline(failas, eilute); //praleisti eilutę su antraštėmis

    while (std::getline(failas, eilute)) {
        std::istringstream eilutesSrautas(eilute);
        Studentas naujasStudentas;
        eilutesSrautas >> naujasStudentas.vardas >> naujasStudentas.pavarde;
        int pazymys;
        while (eilutesSrautas >> pazymys) {
            naujasStudentas.namuDarbai.push_back(pazymys);
            naujasStudentas.sum += pazymys;
        }
        if (!naujasStudentas.namuDarbai.empty()) {
            naujasStudentas.egz = naujasStudentas.namuDarbai.back();
            naujasStudentas.sum -= naujasStudentas.egz;
            naujasStudentas.namuDarbai.pop_back(); //pašalinti paskutinį pažymį, kadangi jis yra egzamino įvertinimas
        }
        naujasStudentas.apskaiciuotiGalutini();
        studentai.push_back(std::move(naujasStudentas));
    }
    failas.close();
    std::cout << "Failo nuskaitymas užtruko " << (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count())/1000.0 << " s\n";
}
