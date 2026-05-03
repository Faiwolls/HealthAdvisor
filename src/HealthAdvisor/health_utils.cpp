#include "health_utils.h"

double HealthAdvisor::CalculateBMI(double weightKg, double heightM) const {
    return weightKg / (heightM * heightM);
}