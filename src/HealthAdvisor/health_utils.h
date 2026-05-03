#pragma once

#include <string>

class HealthAdvisor {
public:
    HealthAdvisor() = default;

    double CalculateBMI(double weightKg, double heightM) const;
    std::string GetBmiCategory(double bmi) const;
    std::string GetPulseCategory(int pulse) const;

};