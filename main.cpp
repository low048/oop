#include <iostream>
#include <iomanip>

struct Studentas{
    std::string vardas;
    std::string pavarde;    
    int n = 0; //namų darbų skaičius
    int sum = 0; //namų darbų rezultatų suma
    int egz = 0; //egzamino rezultatas
    double galutinis = 0;
    void apskaiciuotiGalutini(){
        galutinis = ((sum/n) * 0.4) + (egz * 0.6);
    }
};

int main() {
    int m = 0; //studentų skaicius
    std::cout << "Įveskite studentų skaičių: ";
    std::cin >> m;
    Studentas* studentai = new Studentas[m];
    for(int i = 0; i < m; i++){
        Studentas studentas;
        std::cout << "  Įveskite #" << i+1 << " studento vardą: ";
        std::cin >> studentas.vardas;
        std::cout << "  Įveskite #" << i+1 << " studento pavardę: ";
        std::cin >> studentas.pavarde;
        std::cout << "  Įveskite #" << i+1 << " studento egzamino rezultatą: ";
        std::cin >> studentas.egz;
        std::cout << "  Įveskite #" << i+1 << " studento namų darbų skaičių: ";
        std::cin >> studentas.n;
        for(int v = 0; v < studentas.n; v++){
            int rezultatas = 0;
            std::cout << "    Įveskite #" << v+1 << " namų darbo rezultatą: ";
            std::cin >> rezultatas;
            studentas.sum += rezultatas;
        }
        studentai[i] = studentas;
    }
    std::cout << std::endl << "Pavardė\tVardas\tGalutinis (Vid.)" << std::endl << "-------------------------------------" << std::endl;
    for(int i = 0; i < m; i++){
        Studentas studentas = studentai[i];
        studentas.apskaiciuotiGalutini();
        std::cout << studentas.pavarde << '\t' << studentas.vardas << '\t' << std::fixed << std::setprecision(2) << studentas.galutinis << std::endl;
    }
    delete[] studentai;
    std::cin.get();
    std::cin.get();
    return 0;
}