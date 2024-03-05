#include <iomanip>
#include "studentas.h"
#include "funkcijos.h"
#include "timer.h"

int main() {
    std::vector<Studentas> studentai;
    int meniuPasirinkimas = 0;
    do {
        std::cout << "Meniu:\n"
            << "1 - Įvesti duomenis ranka\n"
            << "2 - Generuoti pažymius\n"
            << "3 - Generuoti pažymius ir studentų vardus, pavardes\n"
            << "4 - Nuskaityti studentų duomenis iš failo\n"
            << "5 - Generuoti atsitiktinį studentų sąrašo failą\n"
            << "6 - Rūšiuoti studentus pagal nepatenkinamus ir patenkinamus galutinius įvertinimus\n"
            << "7 - Baigti darbą\n"
            << "Pasirinkimas: ";
        meniuPasirinkimas = patikrintiSkaiciu(1, 7);
        switch(meniuPasirinkimas) {
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
                int n = patikrintiSkaiciu(0, std::numeric_limits<int>::max());
                for (int v = 0; v < n; v++) {
                    int pazymys = generuotiAtsitiktiniSkaiciu(1, 10);
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
                int studentuSkaicius = patikrintiSkaiciu(0, std::numeric_limits<int>::max());
                std::cout << "  Įveskite namų darbų skaičių: ";
                int namuDarbuSkaicius = patikrintiSkaiciu(0, std::numeric_limits<int>::max());
                for (int i = 0; i < studentuSkaicius; i++) {
                    Studentas naujasStudentas;
                    naujasStudentas.vardas = "Vardas" + std::to_string(i + 1);
                    naujasStudentas.pavarde = "Pavarde" + std::to_string(i + 1);
                    naujasStudentas.egz = generuotiAtsitiktiniSkaiciu(1, 10);;
                    for (int v = 0; v < namuDarbuSkaicius; v++) {
                        int pazymys = generuotiAtsitiktiniSkaiciu(1, 10);;
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
                std::cout << "Galimi failai: " << std::flush;
                system("dir *.txt");
                std::cout << "  Įveskite failo pavadinimą: ";
                std::cin >> failoPavadinimas;
                Timer t;
                skaitytiIsFailo(studentai, failoPavadinimas);
                std::cout << "Failo nuskaitymas užtruko " << t.elapsed() << " s\n";
                break;
            }
            case 5: {
                //atsitiktinio studentų sąrašo failo generavimas
                std::cout << "Įveskite studentų skaičių: ";
                int studentuSkaicius = patikrintiSkaiciu(1, std::numeric_limits<int>::max());
                std::cout << "Įveskite namų darbų skaičių: ";
                int namuDarbuSkaicius = patikrintiSkaiciu(1, std::numeric_limits<int>::max());
                std::string failoPavadinimas = "studentai_" + std::to_string(studentuSkaicius) + ".txt";
                std::ofstream rezultatuFailas(failoPavadinimas);
                if (rezultatuFailas.is_open()) {
                    rezultatuFailas << std::left << std::setw(20) << "Vardas" << std::right << std::setw(20) << "Pavarde";
                    for (int i = 0; i < namuDarbuSkaicius; i++) {
                        rezultatuFailas << std::setw(10) << "ND" + std::to_string(i + 1);
                    }
                    rezultatuFailas << std::setw(10) << "Egz." << std::endl;
                    for (int i = 0; i < studentuSkaicius; i++) {
                        std::string vardas = "Vardas" + std::to_string(i + 1);
                        std::string pavarde = "Pavarde" + std::to_string(i + 1);
                        rezultatuFailas << std::left << std::setw(20) << vardas;
                        rezultatuFailas << std::right << std::setw(20) << pavarde;
                        for (int j = 0; j < namuDarbuSkaicius; j++) {
                            int pazymys = generuotiAtsitiktiniSkaiciu(1, 10);
                            rezultatuFailas << std::setw(10) << pazymys;
                        }
                        int egzaminas = generuotiAtsitiktiniSkaiciu(1, 10);
                        rezultatuFailas << std::setw(10) << egzaminas << std::endl;
                    }
                    rezultatuFailas.close();
                    std::cout << "Duomenys išsaugoti faile: " << failoPavadinimas << '\n';
                } else {
                    std::cout << "Nepavyko atidaryti failo rašymui: " << failoPavadinimas << '\n';
                }
            }
            case 6: {
                //studentų rūšiavimas pagal galutinius įvertinimus
                
            }
            case 7: {
                //darbo baigimas, rikiavimas
                std::cout << "Rikiuoti pagal:\n1 - Vardą\n2 - Pavardę\n3 - Galutinį (Vid.)\n4 - Galutinį (Med.)\nPasirinkimas: ";
                int rikiavimoPasirinkimas = patikrintiSkaiciu(1, 4);
                Timer t;
                rikiuotiStudentus(studentai, rikiavimoPasirinkimas);
                std::cout << "Rikiavimas užtruko " << t.elapsed() << " s\n";
                break;
            }
            default:
                std::cout << "Netinkamas pasirinkimas, bandykite iš naujo.\n";
        }
    } while(meniuPasirinkimas != 7);
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
