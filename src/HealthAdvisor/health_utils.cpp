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

std::string HealthAdvisor::GetPressureCategory(int systolic, int diastolic) const {
    if (systolic < 90 && diastolic < 60) return "Пониженное давление";
    if (systolic >= 90 && systolic <= 119 && diastolic >= 60 && diastolic <= 79)
        return "Нормальное давление";
    if ((systolic >= 120 && systolic <= 139) || (diastolic >= 80 && diastolic <= 89))
        return "Предгипертония";
    if ((systolic >= 140 && systolic <= 159) || (diastolic >= 90 && diastolic <= 99))
        return "Гипертония 1-й степени";
    return "Гипертония 2-й степени";
}

int HealthAdvisor::GetStepsRecommendation(const std::string& bmiCat, const std::string& pulseCat, const std::string& pressureCat) const {
    int steps = 10000;
    if (bmiCat == "Недостаточный вес") steps -= 1000;
    else if (bmiCat == "Избыточный вес") steps += 2000;
    else if (bmiCat == "Ожирение") steps += 3000;

    if (pulseCat == "Низкий пульс") steps += 500;
    else if (pulseCat == "Высокий пульс") steps -= 2000;

    if (pressureCat == "Пониженное давление") steps -= 1000;
    else if (pressureCat == "Предгипертония" || pressureCat.find("Гипертония") != std::string::npos)
        steps -= 1500;

    return steps > 0 ? steps : 0;
}

double HealthAdvisor::GetWeightLossRecommendation(double weightKg, double heightM, bool& needGain) const {
    const double targetBMI = 22.0;
    double targetWeight = targetBMI * heightM * heightM;
    double diff = weightKg - targetWeight;
    needGain = (diff < 0.0);   
    return std::abs(diff);
}
