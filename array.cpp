#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <string>

struct Studentas{
    std::string vardas;
    std::string pavarde;
    int* namuDarbai = nullptr; //namų darbų dinaminis masyvas
    int n = 0; //namų darbų skaičius
    int sum = 0; //namų darbų rezultatų suma
    int egz = 0; //egzamino rezultatas
    double galutinisVid = 0;
    double galutinisMed = 0;

    void apskaiciuotiGalutini() {
        if (n > 0) {
            std::sort(namuDarbai, namuDarbai + n); //išrikiuoti didėjimo tvarka
            if (n % 2 == 1) {
                galutinisMed = namuDarbai[n / 2]; //jei namų darbų skaičius yra nelyginis, mediana per vidurį
            } else {
                galutinisMed = (namuDarbai[n / 2 - 1] + namuDarbai[n / 2]) / 2.0; //jei ne, mediana dviejų vidurinių skaičių aritmetinis vidurkis
            }
            galutinisMed = (galutinisMed * 0.4) + (egz * 0.6);
            galutinisVid = ((double)sum / n * 0.4) + (egz * 0.6);
        } else {
            galutinisVid = (egz * 0.6);
            galutinisMed = (egz * 0.6);
        }
    }

    ~Studentas() {
        delete[] namuDarbai;
    }
};

int patikrintiSkaiciu(bool yraPazymys = false, bool yraMeniu = false) {
    int skaicius;
    while (true) {
        std::cin >> skaicius;
        if (std::cin.fail() || (!yraPazymys && skaicius < 0) || (yraPazymys && (skaicius > 10 || skaicius < -1)) || (yraMeniu && skaicius > 4)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Neteisingai įvestas skaičius, bandykite dar kartą: ";
        } else {
            return skaicius;
        }
    }
}

void generuotiVardaIrPavarde(std::string& vardas, std::string& pavarde) {
    std::string vardai[] = {"Jonas", "Petras", "Antanas", "Kazys", "Simas"};
    std::string pavardes[] = {"Jonaitis", "Petraitis", "Antanaitis", "Kazlauskas", "Simaitis"};
    vardas = vardai[rand() % 5];
    pavarde = pavardes[rand() % 5];
}

int main() {
    srand(time(0));
    Studentas* studentai = nullptr; //dinaminis studentų masyvas
    int m = 0; //studentų skaicius
    int meniuPasirinkimas = 0;
    do {
        std::cout << "Meniu:\n"
            << "1 - Įvesti duomenis ranka\n"
            << "2 - Generuoti pažymius\n"
            << "3 - Generuoti pažymius ir studentų vardus, pavardes\n"
            << "4 - Baigti darbą\n"
            << "Pasirinkimas: ";
        meniuPasirinkimas = patikrintiSkaiciu(false, true);
        switch(meniuPasirinkimas){
            case 1:{
                //duomenys įvedami ranka
                Studentas* temp = new Studentas[m + 1];
                for (int i = 0; i < m; ++i) {
                    temp[i] = studentai[i]; //kopijuoti studentai[] į temp[]
                    //gilus masyvo kopijavimas, kadangi prieš tai buvo kopijuojama tik rodyklė į masyvą, todėl lūždavo programa po destruktoriaus iškvietimo
                    temp[i].namuDarbai = new int[temp[i].n]; 
                    for (int j = 0; j < temp[i].n; ++j) {
                        temp[i].namuDarbai[j] = studentai[i].namuDarbai[j];
                    }
                }
                if (studentai != nullptr) {
                    delete[] studentai; //ištrinti studentai[]
                }
                studentai = temp;
                std::cout << "  Įveskite #" << m + 1 << " studento vardą: ";
                std::cin >> studentai[m].vardas;
                std::cout << "  Įveskite #" << m + 1 << " studento pavardę: ";
                std::cin >> studentai[m].pavarde;
                std::cout << "  Įveskite #" << m + 1 << " studento egzamino rezultatą: ";
                studentai[m].egz = patikrintiSkaiciu(true);
                int dydis = 4; //pradinė namų darbų masyvo talpa
                studentai[m].namuDarbai = new int[dydis];
                studentai[m].n = 0;
                while (true) {
                    std::cout << "    Įveskite #" << studentai[m].n + 1 << " namų darbo rezultatą (0-10), -1 baigia įvedimą: ";
                    int pazymys = patikrintiSkaiciu(true);
                    if (pazymys == -1)
                        break;
                    if (studentai[m].n == dydis) { //jei namų darbų skaičius yra lygus talpai, padidinti masyvą
                        dydis *= 2;
                        int* tempPazymiai = new int[dydis];
                        for (int i = 0; i < studentai[m].n; ++i) {
                            tempPazymiai[i] = studentai[m].namuDarbai[i];
                        }
                        delete[] studentai[m].namuDarbai;
                        studentai[m].namuDarbai = tempPazymiai;
                    }
                    studentai[m].namuDarbai[studentai[m].n] = pazymys;
                    studentai[m].sum += pazymys;
                    studentai[m].n++;
                }
                studentai[m].apskaiciuotiGalutini();
                m++;
                break;
            }
            case 2:{
                //atsitiktinai generuojami tik pažymiai
                Studentas* temp = new Studentas[m + 1];
                for (int i = 0; i < m; ++i) {
                    temp[i] = studentai[i];
                    temp[i].namuDarbai = new int[temp[i].n]; 
                    for (int j = 0; j < temp[i].n; ++j) {
                        temp[i].namuDarbai[j] = studentai[i].namuDarbai[j];
                    }
                }
                if (studentai != nullptr) {
                    delete[] studentai;
                }
                studentai = temp;
                std::cout << "  Įveskite #" << m + 1 << " studento vardą: ";
                std::cin >> studentai[m].vardas;
                std::cout << "  Įveskite #" << m + 1 << " studento pavardę: ";
                std::cin >> studentai[m].pavarde;
                std::cout << "  Įveskite #" << m + 1 << " studento egzamino rezultatą: ";
                studentai[m].egz = patikrintiSkaiciu(true);
                std::cout << "  Įveskite namų darbų skaičių: ";
                studentai[m].n = patikrintiSkaiciu();
                studentai[m].namuDarbai = new int[studentai[m].n];
                for (int v = 0; v < studentai[m].n; v++) {
                    studentai[m].namuDarbai[v] = rand() % 10 + 1;
                    studentai[m].sum += studentai[m].namuDarbai[v];
                }
                studentai[m].apskaiciuotiGalutini();
                m++;
                break;
            }
            case 3:{
                //atsitiktinai generuojami studento vardas, pavardė bei pažymiai
                std::cout << "  Įveskite studentų skaičių: ";
                int studentuSkaicius = patikrintiSkaiciu();
                std::cout << "  Įveskite maksimalų namų darbų skaičių: ";
                int maxNamuDarbu = patikrintiSkaiciu();
                Studentas* temp = new Studentas[m + studentuSkaicius];
                for (int i = 0; i < m; ++i) {
                    temp[i] = studentai[i];
                    temp[i].namuDarbai = new int[temp[i].n]; 
                    for (int j = 0; j < temp[i].n; ++j) {
                        temp[i].namuDarbai[j] = studentai[i].namuDarbai[j];
                    }
                }
                if (studentai != nullptr){
                    delete[] studentai;
                }
                studentai = temp;
                for (int i = m; i < m + studentuSkaicius; ++i) {
                    generuotiVardaIrPavarde(studentai[i].vardas, studentai[i].pavarde);
                    studentai[i].egz = rand() % 10 + 1;
                    int n = rand() % maxNamuDarbu + 1;
                    studentai[i].namuDarbai = new int[n];
                    studentai[i].n = n;
                    for (int v = 0; v < n; v++) {
                        studentai[i].namuDarbai[v] = rand() % 10 + 1;
                        studentai[i].sum += studentai[i].namuDarbai[v];
                    }
                    studentai[i].apskaiciuotiGalutini();
                }
                m += studentuSkaicius;
                break;
            }
            case 4:
                break;
            default:
                std::cout << "Netinkamas pasirinkimas, bandykite iš naujo.\n";
        }
    } while(meniuPasirinkimas != 4);
    std::cout << std::endl << "Pavardė\tVardas\tGalutinis (Vid.)\tGalutinis (Med.)" << std::endl << "-------------------------------------------------" << std::endl;
    for (int i = 0; i < m; i++) {
        std::cout << studentai[i].pavarde << '\t' << studentai[i].vardas << '\t' 
                  << std::fixed << std::setprecision(2) << studentai[i].galutinisVid << "\t\t" 
                  << studentai[i].galutinisMed << std::endl;
    }
    delete[] studentai;
    std::cin.get();
    std::cin.get();
    return 0;
}