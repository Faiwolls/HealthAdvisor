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


void infinitInput(std::string message, std::string error, int& value) {

	bool wrongin = true;
	int val;

	while (wrongin) {

		std::cout << message;
		std::cin >> val;
		if (std::cin.fail() || val <= 0) {

			clearInput();
			std::cout << error;
			continue;
		}
		wrongin = false;
	}

	value = val;
}

void infinitInput(std::string message, std::string error, double& value) {

	bool wrongin = true;
	double val;

	while (wrongin) {

		std::cout << message;
		std::cin >> val;
		if (std::cin.fail() || val <= 0) {

			clearInput();
			std::cout << error;
			continue;
		}
		wrongin = false;
	}

	value = val;
}


int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	HealthAdvisor advisor;

	double weight = 0, height = 0;
	int pulse = 0, systolic = 0, diastolic = 0;
	double bmi = 0;

	std::string bmiCat = "";
	std::string pulseCat = "";
	std::string pressureCat = "";

	int steps;
	bool needGain;
	double weightDelta;


	//bool wrongin = true;
	int choice = 100;

	while (choice != 0) {

		system("cls");
		std::cout << "\n========= Помощник здоровья =========\n";
		std::cout << "1. Рассчитать ИМТ (индекс массы тела)\n";
		std::cout << "2. Проверить пульс\n";
		std::cout << "3. Проверить давление\n";
		std::cout << "4. Все результаты и рекомендации\n";
		std::cout << "0. Выход\n";
		std::cout << "=====================================\n";
		std::cout << "Выберите пункт меню: ";

		std::cin >> choice;
		if (std::cin.fail()) {
			clearInput();
			std::cout << "\nНекорректный ввод. Попробуйте снова.\n\n";
			system("pause");
			choice = 100;
			continue;
		}

		switch (choice) {

			// 1. Рассчитать ИМТ (индекс массы тела)
		case 1: {

			infinitInput("Введите вес (кг): ", "Некорректный вес.\n", weight);
			infinitInput("Введите рост (м, например 1.7): ", "Некорректный рост.\n", height);

			bmi = advisor.CalculateBMI(weight, height);
			bmiCat = advisor.GetBmiCategory(bmi);
			std::cout << "ИМТ: " << bmi << " - " << bmiCat << "\n\n";
			system("pause");
		} break;

			  // 2. Проверить пульс
		case 2: {

			infinitInput("Введите пульс в покое (уд/мин): ", "Некорректный пульс.\n", pulse);
			pulseCat = advisor.GetPulseCategory(pulse);
			std::cout << "Пульс: " << pulse << " уд/мин - " << pulseCat << "\n\n";
			system("pause");
		} break;

			  // 3. Проверить давление
		case 3: {

			infinitInput("Введите систолическое давление: ", "Некорректное систолическое давление.\n", systolic);
			infinitInput("Введите диастолическое давление: ", "Некорректное диастолическое давление.\n", diastolic);
			pressureCat = advisor.GetPressureCategory(systolic, diastolic);
			std::cout << "Давление: " << systolic << "/" << diastolic << " - " << pressureCat << "\n\n";
			system("pause");
		} break;

			  // 4. Все результаты и рекомендации
		case 4: {

			if (bmiCat == "") {

				std::cout << "\nРассчитайте ИМТ. Не хватает данных для рекомендаций\n\n";
				system("pause");
				continue;
			}
			else if (pulseCat == "") {

				std::cout << "\nПроверьте пульс. Не хватает данных для рекомендаций\n\n";
				system("pause");
				continue;
			}
			else if (pressureCat == "") {

				std::cout << "\nПроверьте давление. Не хватает данных для рекомендаций\n\n";
				system("pause");
				continue;
			}

			steps = advisor.GetStepsRecommendation(bmiCat, pulseCat, pressureCat);
			weightDelta = advisor.GetWeightLossRecommendation(weight, height, &needGain);

			std::cout << "\nРезультаты:\n";
			std::cout << "ИМТ: " << bmi << " - " << bmiCat << " (Вес: " << weight << ". Рост: " << height << ")\n";
			std::cout << "Пульс: " << pulse << " уд/мин - " << pulseCat << "\n";
			std::cout << "Давление: " << systolic << "/" << diastolic << " - " << pressureCat << "\n";
			std::cout << "\nРекомендации:\n";
			std::cout << "Рекомендуемое количество шагов в день: " << steps << "\n";
			if (needGain)
				std::cout << "Вам следует набрать " << weightDelta << " кг для достижения лучшего веса (ИМТ = 22.0).\n";
			else
				std::cout << "Вам следует сбросить " << weightDelta << " кг для достижения лучшего веса (ИМТ = 22.0).\n";
			std::cout << std::endl;
			system("pause");
		} break;

		case 0:
			break;

		default:
			std::cout << "\nНеверный пункт меню. Попробуйте снова.\n\n";
			system("pause");
			continue;
			break;
		}

	}

	return 0;
}