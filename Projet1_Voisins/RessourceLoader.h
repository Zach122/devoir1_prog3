#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Liste.h"
using namespace std;

vector<float> ConvertirLigneAFloat(const std::vector<std::string>&);
Liste GetTrainDataLinked(float, const std::string&);
Liste GetTestDataLinked(float, const std::string&);
std::vector<std::vector<std::string>> ImportationDonnees(const std::string&);

