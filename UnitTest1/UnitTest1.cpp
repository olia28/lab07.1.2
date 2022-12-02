#include "pch.h"
#include "CppUnitTest.h"
#include "../lab07.1.rec/lab07.1.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int sum = 0;
            int k;
            int** q;
            int result;
            const int row_count = 4;
            const int col_count = 4;
            int m[row_count][col_count];
            int m[4][4]
            {
                {1, 5, 6, 10},
                { 4, 12, 18, 9 },
                { 3, -2, 7, 0 },
                { -3, 4, 6, 7 }
            };
            int* q[4] = { m[0], m[1], m[2], m[3] };
            Calc(q, 4, 4, sum, k, 4, 4);
            result = sum;

            Assert::AreEqual(27, result);
		}
	};
}
