#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>

struct Studentas{
    std::string vardas;
    std::string pavarde;
    int* namuDarbai = nullptr; //namų darbų dinaminis masyvas
    int n = 0; //namų darbų skaičius
    int sum = 0; //namų darbų rezultatų suma
    int egz = 0; //egzamino rezultatas
    double galutinisVid = 0;
    double galutinisMed = 0;

    void apskaiciuotiGalutiniVid() {
        if (n > 0) {
            galutinisVid = ((double)sum / n * 0.4) + (egz * 0.6);
        } else {
            galutinisVid = (egz * 0.6);
        }
    }

    void apskaiciuotiGalutiniMed() {
        if(n > 0){
            std::sort(namuDarbai, namuDarbai + n); //išrikiuoti didėjimo tvarka
            if (n % 2 == 1) {
                galutinisMed = namuDarbai[n / 2]; //jei namų darbų skaičius yra nelyginis, mediana per vidurį
            } else {
                galutinisMed = (namuDarbai[n / 2 - 1] + namuDarbai[n / 2]) / 2.0; //jei ne, mediana dviejų vidurinių skaičių aritmetinis vidurkis
            }
            galutinisMed = (galutinisMed * 0.4) + (egz * 0.6);
        } else {
            galutinisMed = (egz * 0.6);
        }
    }

    ~Studentas() {
        delete[] namuDarbai;
    }
};

int patikrintiSkaiciu(bool yraPazymys = false) {
    int skaicius;
    while (true) {
        std::cin >> skaicius;
        if (std::cin.fail() || skaicius < 0 || (yraPazymys && (skaicius > 10))) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Neteisingai įvestas skaičius, bandykite dar kartą: ";
        } else {
            return skaicius;
        }
    }
}

int main() {
    std::cout << "Įveskite studentų skaičių: ";
    int m = patikrintiSkaiciu(); //studentų skaicius
    Studentas* studentai = new Studentas[m];
    for (int i = 0; i < m; i++) {
        std::cout << "  Įveskite #" << i + 1 << " studento vardą: ";
        std::cin >> studentai[i].vardas;
        std::cout << "  Įveskite #" << i + 1 << " studento pavardę: ";
        std::cin >> studentai[i].pavarde;
        std::cout << "  Įveskite #" << i + 1 << " studento egzamino rezultatą: ";
        studentai[i].egz = patikrintiSkaiciu(true);
        std::cout << "  Įveskite #" << i + 1 << " studento namų darbų skaičių: ";
        studentai[i].n = patikrintiSkaiciu();
        studentai[i].namuDarbai = new int[studentai[i].n];
        for (int v = 0; v < studentai[i].n; v++) {
            std::cout << "    Įveskite #" << v + 1 << " namų darbo rezultatą: ";
            studentai[i].namuDarbai[v] = patikrintiSkaiciu(true);
            studentai[i].sum += studentai[i].namuDarbai[v];
        }
        studentai[i].apskaiciuotiGalutiniVid();
        studentai[i].apskaiciuotiGalutiniMed();
    }
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