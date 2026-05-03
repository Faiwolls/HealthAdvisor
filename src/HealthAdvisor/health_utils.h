#pragma once

#include <string>

class HealthAdvisor {
public:
    HealthAdvisor() = default;

    double CalculateBMI(double weightKg, double heightM) const;
    std::string GetBmiCategory(double bmi) const;
    std::string GetPulseCategory(int pulse) const;
    std::string GetPressureCategory(int systolic, int diastolic) const;
    int GetStepsRecommendation(const std::string& bmiCat, const std::string& pulseCat, const std::string& pressureCat) const;
    double GetWeightLossRecommendation(double weightKg, double heightM, bool* needGain = nullptr) const;
};