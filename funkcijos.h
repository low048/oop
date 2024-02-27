#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <vector>
#include <string>
#include "Studentas.h"

int patikrintiSkaiciu(int maziausias, int didziausias);
void generuotiVardaIrPavarde(std::string& vardas, std::string& pavarde);
void skaitytiIsFailo(std::vector<Studentas>& studentai, const std::string& failoPavadinimas);

#endif
