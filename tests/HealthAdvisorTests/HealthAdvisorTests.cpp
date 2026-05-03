#include "pch.h"
#include "CppUnitTest.h"
#include <../src/HealthAdvisor/health_utils.cpp>
#include <../src/HealthAdvisor/health_utils.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HealthAdvisorTests
{
    TEST_CLASS(HealthAdvisorTest)
    {
    public:
        TEST_METHOD(CreateObject)
        {
            HealthAdvisor advisor;
            Assert::IsTrue(true); // проверяем, что объект создаётся
        }

        TEST_METHOD(CalculateBMI_ValidInput)
        {
            HealthAdvisor advisor;
            Assert::AreEqual(22.86, advisor.CalculateBMI(70.0, 1.75), 0.01);
            Assert::AreEqual(19.53, advisor.CalculateBMI(50.0, 1.60), 0.01);
        }

        TEST_METHOD(BmiCategory)
        {
            HealthAdvisor advisor;
            Assert::AreEqual("Недостаточный вес", advisor.GetBmiCategory(18.4).c_str());
            Assert::AreEqual("Нормальный вес", advisor.GetBmiCategory(18.5).c_str());
            Assert::AreEqual("Нормальный вес", advisor.GetBmiCategory(24.9).c_str());
            Assert::AreEqual("Избыточный вес", advisor.GetBmiCategory(25.0).c_str());
            Assert::AreEqual("Избыточный вес", advisor.GetBmiCategory(29.9).c_str());
            Assert::AreEqual("Ожирение", advisor.GetBmiCategory(30.0).c_str());
        }

        TEST_METHOD(PulseCategory)
        {
            HealthAdvisor advisor;
            Assert::AreEqual("Низкий пульс", advisor.GetPulseCategory(50).c_str());
            Assert::AreEqual("Нормальный пульс", advisor.GetPulseCategory(60).c_str());
            Assert::AreEqual("Нормальный пульс", advisor.GetPulseCategory(100).c_str());
            Assert::AreEqual("Высокий пульс", advisor.GetPulseCategory(101).c_str());
        }

        TEST_METHOD(PressureCategory)
        {
            HealthAdvisor advisor;
            Assert::AreEqual("Пониженное давление", advisor.GetPressureCategory(80, 50).c_str());
            Assert::AreEqual("Нормальное давление", advisor.GetPressureCategory(90, 60).c_str());
            Assert::AreEqual("Нормальное давление", advisor.GetPressureCategory(119, 79).c_str());
            Assert::AreEqual("Предгипертония", advisor.GetPressureCategory(120, 80).c_str());
            Assert::AreEqual("Предгипертония", advisor.GetPressureCategory(139, 89).c_str());
            Assert::AreEqual("Гипертония 1-й степени", advisor.GetPressureCategory(140, 90).c_str());
            Assert::AreEqual("Гипертония 2-й степени", advisor.GetPressureCategory(160, 100).c_str());
        }
    };
}
