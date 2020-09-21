#include "stdafx.h"
#include "CppUnitTest.h"
#include "PolyDrawable.h"


using namespace std;
using namespace Gdiplus;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CPolyDrawableTest)
	{
	public:

		TEST_METHOD(TestCPolyDrawableName)
		{
			CPolyDrawable drawing(L"Test");
			Assert::AreEqual(std::wstring(L"Test"), drawing.GetName());
		}

		TEST_METHOD(TestCPolyDrawableColor)
		{
			CPolyDrawable drawing(L"Test");
			Gdiplus::Color blk = Gdiplus::Color::Black;

			Assert::IsTrue(drawing.GetColor().GetR() == blk.GetR());
			Assert::IsTrue(drawing.GetColor().GetB() == blk.GetB());
			Assert::IsTrue(drawing.GetColor().GetG() == blk.GetG());

			Gdiplus::Color test(255, 255, 255);
			drawing.SetColor(test);

			Assert::IsTrue(drawing.GetColor().GetR() == test.GetR());
			Assert::IsTrue(drawing.GetColor().GetB() == test.GetB());
			Assert::IsTrue(drawing.GetColor().GetG() == test.GetG());
		
		}


	};
}