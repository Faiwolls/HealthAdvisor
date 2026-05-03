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
    };
}
