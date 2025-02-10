#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Liste.h"

using namespace std;

vector<float> ConvertirLigneAFloat(const vector<string>&);
Liste GetTrainDataLinked(float, const string&);
Liste GetTestDataLinked(float, const string&);
vector<vector<string>> ImportationDonnees(const string&);

