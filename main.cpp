#include <iostream>

struct Studentas{
    std::string vardas;
    std::string pavarde;    
    int n = 0; //namu darbu skaicius
    int sum = 0; //namu darbu rezultatu suma
    int egz = 0; //egzamino rezultatas
    double galutinis = 0;
    void apskaiciuotiGalutini(){
        galutinis = ((sum/n) * 0.4) + (egz * 0.6);
    }
};

int main() {
    int m = 0; //studentu skaicius
    std::cout << "Iveskite studentu skaiciu: ";
    std::cin >> m;
    Studentas* studentai = new Studentas[m];
    for(int i = 0; i < m; i++){
        Studentas studentas;
        std::cout << "  Iveskite #" << i+1 << " studento varda: ";
        std::cin >> studentas.vardas;
        std::cout << "  Iveskite #" << i+1 << " studento pavarde: ";
        std::cin >> studentas.pavarde;
        std::cout << "  Iveskite #" << i+1 << " studento egzamino rezultata: ";
        std::cin >> studentas.egz;
        std::cout << "  Iveskite #" << i+1 << " studento namu darbu skaiciu: ";
        std::cin >> studentas.n;
        for(int v = 0; v < studentas.n; v++){
            int rezultatas = 0;
            std::cout << "    Iveskite #" << v+1 << " namu darbo rezultata: ";
            std::cin >> rezultatas;
            studentas.sum += rezultatas;
        }
        studentai[i] = studentas;
    }
    std::cout << std::endl << "Pavardė\tVardas\tGalutinis (Vid.)" << std::endl << "-------------------------------------" << std::endl;
    for(int i = 0; i < m; i++){
        Studentas studentas = studentai[i];
        studentas.apskaiciuotiGalutini();
        std::cout << studentas.vardas << '\t' << studentas.pavarde << '\t' << studentas.galutinis << std::endl;
    }
    delete[] studentai;
    std::cin.get();
    std::cin.get();
    return 0;
}