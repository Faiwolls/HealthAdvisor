#include <iostream>
#include <limits>
#define NOMINMAX               // отключаем макросы min/max из windows.h
#include <windows.h>
#include <clocale>
#include "health_utils.h"

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    HealthAdvisor advisor;

    while (true) {
        std::cout << "\n===== Помощник здоровья =====\n";
        std::cout << "1. Рассчитать ИМТ и получить рекомендации\n";
        std::cout << "2. Выход\n";
        std::cout << "Выберите пункт меню: ";

        int choice;
        std::cin >> choice;
        if (std::cin.fail()) {
            clearInput();
            std::cout << "Некорректный ввод. Попробуйте снова.\n";
            continue;
        }

        if (choice == 2) break;
        if (choice != 1) {
            std::cout << "Неверный пункт меню. Попробуйте снова.\n";
            continue;
        }

        double weight, height;
        int pulse, systolic, diastolic;

        std::cout << "Введите вес (кг): ";
        std::cin >> weight;
        if (std::cin.fail() || weight <= 0) { clearInput(); std::cout << "Некорректный вес.\n"; continue; }

        std::cout << "Введите рост (м): ";
        std::cin >> height;
        if (std::cin.fail() || height <= 0) { clearInput(); std::cout << "Некорректный рост.\n"; continue; }

        std::cout << "Введите пульс в покое (уд/мин): ";
        std::cin >> pulse;
        if (std::cin.fail() || pulse <= 0) { clearInput(); std::cout << "Некорректный пульс.\n"; continue; }

        std::cout << "Введите систолическое давление: ";
        std::cin >> systolic;
        if (std::cin.fail() || systolic <= 0) { clearInput(); std::cout << "Некорректное систолическое давление.\n"; continue; }

        std::cout << "Введите диастолическое давление: ";
        std::cin >> diastolic;
        if (std::cin.fail() || diastolic <= 0) { clearInput(); std::cout << "Некорректное диастолическое давление.\n"; continue; }

        double bmi = advisor.CalculateBMI(weight, height);
        std::string bmiCat = advisor.GetBmiCategory(bmi);
        std::string pulseCat = advisor.GetPulseCategory(pulse);
        std::string pressureCat = advisor.GetPressureCategory(systolic, diastolic);
        int steps = advisor.GetStepsRecommendation(bmiCat, pulseCat, pressureCat);
        bool needGain;
        double weightDelta = advisor.GetWeightLossRecommendation(weight, height, &needGain);

        std::cout << "\nРезультаты:\n";
        std::cout << "ИМТ: " << bmi << " (" << bmiCat << ")\n";
        std::cout << "Пульс: " << pulse << " уд/мин (" << pulseCat << ")\n";
        std::cout << "Давление: " << systolic << "/" << diastolic << " (" << pressureCat << ")\n";
        std::cout << "Рекомендуемое количество шагов в день: " << steps << "\n";
        if (needGain)
            std::cout << "Вам следует набрать " << weightDelta << " кг для достижения нормального веса.\n";
        else
            std::cout << "Вам следует сбросить " << weightDelta << " кг для достижения нормального веса.\n";
    }

    return 0;
}