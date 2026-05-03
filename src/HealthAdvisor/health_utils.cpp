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

std::string HealthAdvisor::GetPulseCategory(int pulse) const {
    if (pulse < 60) return "Низкий пульс";
    if (pulse <= 100) return "Нормальный пульс";
    return "Высокий пульс";
}