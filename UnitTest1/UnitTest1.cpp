#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7.3(it)/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	namespace UnitTest1
	{
		TEST_CLASS(UnitTest1)
		{
		public:

			TEST_METHOD(TestMethod1)
			{
				 {
					const int rowCount = 3; 
					const int colCount = 3; 
					int** a = new int* [rowCount];
					for (int i = 0; i < rowCount; i++)
						a[i] = new int[colCount];
				}
			}
		};
	}
