#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<float> ConvertirLigneAFloat(const std::vector<std::string>&);
void GetTrainDataLinked(float ratio, const std::vector<std::vector<std::string>>& donnees);
vector<float> GetTrainData(int, vector<float>);
vector<float> GetTestData(int, vector<float>);

class RessourceLoader {

};

