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