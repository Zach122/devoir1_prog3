#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<float> ConvertirLigneAFloat(const std::vector<std::string>&);
std::vector<std::vector<std::string>> ImportationDonnees(const std::string);
std::vector<float> ConvertirLigneAFloat(const std::vector<std::string>&);
std::vector<std::vector<float>> GetTrainData(float, const std::vector<std::vector<std::string>>&);
std::vector<std::vector<float>> GetTestData(float, const std::vector<std::vector<std::string>>&);