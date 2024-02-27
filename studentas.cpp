#include "studentas.h"
#include <algorithm>

void Studentas::apskaiciuotiGalutini() {
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
