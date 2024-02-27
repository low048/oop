#include "funkcijos.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <chrono>
#include <algorithm>


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
    std::cout << "Failo nuskaitymas užtruko " << std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start).count() << " s\n";
}

void rikiuotiStudentus(std::vector<Studentas>& studentai, int rikiavimoPasirinkimas) {
    switch (rikiavimoPasirinkimas) {
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
}