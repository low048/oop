#include "funkcijos.h"

int patikrintiSkaiciu(int maziausias, int didziausias) {
    int skaicius;
    std::string ivestis;
    bool ivestisTeisinga = false;
    while (!ivestisTeisinga) {
        if (std::cin.peek() == '\n') {
            std::cin.ignore();
        }
        if (!std::getline(std::cin, ivestis)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignoruoti likusią eilutę
            std::cout << "Įvyko klaida skaitant įvestį, bandykite dar kartą: ";
            continue;
        }
        try {
            skaicius = std::stoi(ivestis);
            if (skaicius < maziausias || skaicius > didziausias) {
                throw std::out_of_range("Skaičius už leistino intervalo.");
            }
            ivestisTeisinga = true;
        } catch (const std::invalid_argument&) {
            std::cout << "Įvesta reikšmė nėra skaičius, bandykite dar kartą: ";
        } catch (const std::out_of_range&) {
            std::cout << "Įvestas skaičius yra už leistino intervalo, bandykite dar kartą: ";
        }
    }
    return skaicius;
}

bool patikrintiTaipNe() {
    std::string ivestis;
    while (true) {
        if (std::cin.peek() == '\n') {
            std::cin.ignore();
        }
        std::getline(std::cin, ivestis);
        if (ivestis == "t" || ivestis == "n") {
            return ivestis == "t";
        }
        std::cout << "Įvesta reikšmė nėra 't' arba 'n', bandykite dar kartą: ";
    }
}

int generuotiAtsitiktiniSkaiciu(int maziausias, int didziausias) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(maziausias, didziausias);
    
    return dis(gen);
}

void skaitytiIsFailo(std::vector<Studentas>& studentai, const std::string& failoPavadinimas) {
    try {
        std::ifstream failas(failoPavadinimas);
        if (!failas.is_open())
            throw std::runtime_error("nepavyko atidaryti failo " + failoPavadinimas);

        std::string eilute;
        std::getline(failas, eilute); //praleisti eilutę su antraštėmis


        while (std::getline(failas, eilute)) {
            try {
                std::istringstream eilutesSrautas(eilute);
                Studentas naujasStudentas;
                if (!(eilutesSrautas >> naujasStudentas.vardas >> naujasStudentas.pavarde)) {
                    throw std::logic_error("nepavyko nuskaityti studento vardo ar pavardės.");
                }
                int pazymys;
                while (eilutesSrautas >> pazymys) {
                    if (pazymys < 0 || pazymys > 10) {
                        throw std::out_of_range("pažymys yra už leistino intervalo (0-10).");
                    }
                    naujasStudentas.namuDarbai.push_back(pazymys);
                    naujasStudentas.sum += pazymys;
                }
                if (eilutesSrautas.fail() && !eilutesSrautas.eof()) {
                    throw std::logic_error("nepavyko nuskaityti visų pažymių.");
                }
                if (!naujasStudentas.namuDarbai.empty()) {
                    naujasStudentas.egz = naujasStudentas.namuDarbai.back();
                    naujasStudentas.sum -= naujasStudentas.egz;
                    naujasStudentas.namuDarbai.pop_back(); //pašalinti paskutinį pažymį, kadangi jis yra egzamino įvertinimas
                }
                naujasStudentas.apskaiciuotiGalutini();
                studentai.push_back(std::move(naujasStudentas));
            } catch (std::exception& e) {
                std::cout << "Nuskaitant eilutę įvyko klaida: " << e.what() << '\n';
            }

        }
        failas.close();
    } catch (std::exception& e) {
        std::cout << "Nuskaitant failą įvyko klaida: " << e.what() << '\n';
    }
}

void irasytiStudentuDuomenis(const std::string& failoPavadinimas, const std::vector<Studentas>& studentai) {
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
        std::cerr << "Nepavyko atidaryti failo rašymui: " << failoPavadinimas << '\n';
    }
}

void rikiuotiStudentus(std::vector<Studentas>& studentai, int rikiavimoPasirinkimas) {
    switch (rikiavimoPasirinkimas) {
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
