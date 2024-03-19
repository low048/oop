#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "../include/studentas.h"
#include <deque>
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
void skaitytiIsFailo(std::deque<Studentas>& studentai, const std::string& failoPavadinimas);
void irasytiStudentuDuomenis(const std::string& failoPavadinimas, const std::deque<Studentas>& studentai);
void rikiuotiStudentus(std::deque<Studentas>& studentai, int rikiavimoPasirinkimas);

#endif
