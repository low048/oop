#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "studentas.h"
#include <list>
#include <string>
#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <random>
#include <iomanip>

int patikrintiSkaiciu(int maziausias, int didziausias);
int generuotiAtsitiktiniSkaiciu(int maziausias, int didziausias);
void skaitytiIsFailo(std::list<Studentas>& studentai, const std::string& failoPavadinimas);
void irasytiStudentuDuomenis(const std::string& failoPavadinimas, const std::list<Studentas>& studentai);
void rikiuotiStudentus(std::list<Studentas>& studentai, int rikiavimoPasirinkimas);


#endif
