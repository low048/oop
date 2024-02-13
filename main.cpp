#include <iostream>
#include <iomanip>
#include <algorithm>

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
        galutinisVid = ((double)sum / n * 0.4) + (egz * 0.6);
    }

    void apskaiciuotiGalutiniMed() {
        std::sort(namuDarbai, namuDarbai + n); //išrikiuoti didėjimo tvarka
        if (n % 2 == 1) {
            galutinisMed = namuDarbai[n / 2]; //jei namų darbų skaičius yra nelyginis, mediana per vidurį
        } else {
            galutinisMed = (namuDarbai[n / 2 - 1] + namuDarbai[n / 2]) / 2.0; //jei ne, mediana dviejų vidurinių skaičių aritmetinis vidurkis
        }
        galutinisMed = (galutinisMed * 0.4) + (egz * 0.6);
    }

    ~Studentas() {
        delete[] namuDarbai;
    }
};

int main() {
    int m = 0; //studentų skaicius
    std::cout << "Įveskite studentų skaičių: ";
    std::cin >> m;
    Studentas* studentai = new Studentas[m];
    for (int i = 0; i < m; i++) {
        std::cout << "  Įveskite #" << i + 1 << " studento vardą: ";
        std::cin >> studentai[i].vardas;
        std::cout << "  Įveskite #" << i + 1 << " studento pavardę: ";
        std::cin >> studentai[i].pavarde;
        std::cout << "  Įveskite #" << i + 1 << " studento egzamino rezultatą: ";
        std::cin >> studentai[i].egz;
        std::cout << "  Įveskite #" << i + 1 << " studento namų darbų skaičių: ";
        std::cin >> studentai[i].n;
        studentai[i].namuDarbai = new int[studentai[i].n];
        for (int v = 0; v < studentai[i].n; v++) {
            std::cout << "    Įveskite #" << v + 1 << " namų darbo rezultatą: ";
            std::cin >> studentai[i].namuDarbai[v];
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