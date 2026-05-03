#include "health_utils.h"

double HealthAdvisor::CalculateBMI(double weightKg, double heightM) const {
    return weightKg / (heightM * heightM);
}

std::string HealthAdvisor::GetBmiCategory(double bmi) const {
    if (bmi < 18.5) return "Недостаточный вес";
    if (bmi < 25.0) return "Нормальный вес";
    if (bmi < 30.0) return "Избыточный вес";
    return "Ожирение";
}