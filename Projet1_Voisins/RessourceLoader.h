#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<float> ConvertirLigneAFloat(const std::vector<std::string>&);
vector<float> GetTrainData(int, vector<float>);
vector<float> GetTestData(int, vector<float>);

class dataset {
public:
    dataset(float aciditeFixe, float acideVolatile, float acideCitrique, float sucreResiduel, float chlorureSodium, float dioxydeSoufreLibre, float dioxydeSoufreTotal, float densite, float pH, float sulfatePotassium, float alcool, float bon)
    {
        m_aciditeFixe = aciditeFixe; // (grammes d’acide tartrique / dm3)
        m_acideVolatile = acideVolatile; // (grammes d’acide acétique / dm3)
        m_acideCitrique = acideCitrique; // (g / dm3)
        m_sucreResiduel = sucreResiduel; // (g / dm3)
        m_chlorureSodium = chlorureSodium; // (g / dm3)
        m_dioxydeSoufreLibre = dioxydeSoufreLibre; // (mg / dm3)
        m_dioxydeSoufreTotal = dioxydeSoufreTotal; // (mg / dm3)
        m_densite = densite; // (g / cm3)
        m_pH = pH;
        m_sulfatePotassium = sulfatePotassium; // (g / dm3)
        m_alcool = alcool; // (vol.%)
        m_bon = bon;
    }

private:
    float m_aciditeFixe;
    float m_acideVolatile;
    float m_acideCitrique;
    float m_sucreResiduel;
    float m_chlorureSodium;
    float m_dioxydeSoufreLibre;
    float m_dioxydeSoufreTotal;
    float m_densite;
    float m_pH;
    float m_sulfatePotassium;
    float m_alcool;
    float m_bon;
};

