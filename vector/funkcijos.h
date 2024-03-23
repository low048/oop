#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "../include/studentas.h"
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
#include <iomanip>

int patikrintiSkaiciu(int maziausias, int didziausias);
bool patikrintiTaipNe();
int generuotiAtsitiktiniSkaiciu(int maziausias, int didziausias);
void skaitytiIsFailo(std::vector<Studentas>& studentai, const std::string& failoPavadinimas);
void irasytiStudentuDuomenis(const std::string& failoPavadinimas, const std::vector<Studentas>& studentai);
void rikiuotiStudentus(std::vector<Studentas>& studentai, int rikiavimoPasirinkimas);

#endif
