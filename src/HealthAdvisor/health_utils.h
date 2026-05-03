#pragma once

class HealthAdvisor {
public:
    HealthAdvisor() = default;

    double CalculateBMI(double weightKg, double heightM) const;
};