#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>
#include <algorithm>

struct Studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> namuDarbai;
    int sum = 0; //namų darbų rezultatų suma
    int egz = 0; //egzamino rezultatas
    float galutinisVid = 0.0;
    float galutinisMed = 0.0;

    void apskaiciuotiGalutini();
};

#endif
