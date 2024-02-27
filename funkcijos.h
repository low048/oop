#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <vector>
#include <string>
#include "studentas.h"

int patikrintiSkaiciu(int maziausias, int didziausias);
void generuotiVardaIrPavarde(std::string& vardas, std::string& pavarde);
void skaitytiIsFailo(std::vector<Studentas>& studentai, const std::string& failoPavadinimas);
void rikiuotiStudentus(std::vector<Studentas>& studentai, int rikiavimoPasirinkimas);

#endif
