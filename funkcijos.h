#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "studentas.h"
#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <random>

int patikrintiSkaiciu(int maziausias, int didziausias);
int generuotiAtsitiktiniSkaiciu(int maziausias, int didziausias);
void skaitytiIsFailo(std::vector<Studentas>& studentai, const std::string& failoPavadinimas);
void rikiuotiStudentus(std::vector<Studentas>& studentai, int rikiavimoPasirinkimas);

#endif
