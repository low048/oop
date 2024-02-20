#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <climits>

struct Studentas{
    std::string vardas;
    std::string pavarde;
    std::vector<int> namuDarbai;
    int sum = 0; //namų darbų rezultatų suma
    int egz = 0; //egzamino rezultatas
    double galutinisVid = 0;
    double galutinisMed = 0;

    void apskaiciuotiGalutini() {
        if(!namuDarbai.empty()){
            std::sort(namuDarbai.begin(), namuDarbai.end()); //išrikiuoti didėjimo tvarka
            size_t n = namuDarbai.size();
            if (n % 2 == 1) {
                galutinisMed = namuDarbai[n / 2]; //jei namų darbų skaičius yra nelyginis, mediana per vidurį
            } else {
                galutinisMed = (namuDarbai[n / 2 - 1] + namuDarbai[n / 2]) / 2.0; //jei ne, mediana dviejų vidurinių skaičių aritmetinis vidurkis
            }
            galutinisMed = (galutinisMed * 0.4) + (egz * 0.6);
            galutinisVid = ((double)sum / n * 0.4) + (egz * 0.6);
        } else {
            galutinisMed = (egz * 0.6);
            galutinisVid = (egz * 0.6);
        }
    }
};

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
    std::ifstream failas(failoPavadinimas);
    if (!failas.is_open()) {
        std::cout << "Nepavyko atidaryti failo: " << failoPavadinimas << std::endl;
        return;
    }
    std::string eilute;
    std::getline(failas, eilute);

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
        studentai.push_back(naujasStudentas);
    }
    failas.close();
}

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
                    std::cout << "    Įveskite namų darbo rezultatą (0-10), -1 baigia įvedimą: ";
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
                std::string failoVardas = "studentai10000.txt";
                skaitytiIsFailo(studentai, failoVardas);
                break;
            }
            case 5:{
                std::cout << "Rūšiuoti pagal:\n1 - Vardą\n2 - Pavardę\n3 - Galutinį (Vid.)\n4 - Galutinį (Med.)\nPasirinkimas: ";
                int rusiavimoPasirinkimas = patikrintiSkaiciu(1, 4);
                switch (rusiavimoPasirinkimas) {
                    case 1:
                        std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
                            return a.vardas < b.vardas; });
                        break;
                    case 2:
                        std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
                            return a.pavarde < b.pavarde; });
                        break;
                    case 3:
                        std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
                            return a.galutinisVid < b.galutinisVid; });
                        break;
                    case 4:
                        std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
                            return a.galutinisMed < b.galutinisMed; });
                        break;
                    default:
                        std::cout << "Netinkamas pasirinkimas, naudojamas numatytasis (Vardas).\n";
                        std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
                            return a.vardas < b.vardas; });
                }
                break;
            }

            default:
                std::cout << "Netinkamas pasirinkimas, bandykite iš naujo.\n";
        }
    } while(meniuPasirinkimas != 5);
    std::cout << std::endl << "Pavardė\tVardas\tGalutinis (Vid.)\tGalutinis (Med.)" << std::endl << "-------------------------------------------------" << std::endl;
    for (const auto& studentas : studentai) {
        std::cout << studentas.pavarde << '\t' << studentas.vardas << '\t' 
                  << std::fixed << std::setprecision(2) << studentas.galutinisVid << "\t\t" 
                  << studentas.galutinisMed << std::endl;
    }
    std::cin.get();
    std::cin.get();
    return 0;
}