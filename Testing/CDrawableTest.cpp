#include "stdafx.h"
#include "CppUnitTest.h"
#include <cmath>
#include "Drawable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace Testing
{
	class CDrawableMock : public CDrawable
	{
	public:
		CDrawableMock(const std::wstring &name) : CDrawable(name) {}
		virtual void Draw(Gdiplus::Graphics *graphics) override {}
		virtual bool HitTest(Gdiplus::Point pos) override { return false; }

	};
	TEST_CLASS(CDrawableTest){
		TEST_METHOD(TestCDrawableName)
		{

			CDrawableMock drawing(L"Test");
			Assert::AreEqual(std::wstring(L"Test"), drawing.GetName());

		}
	


	TEST_METHOD(TestCDrawablePosition)
	{
		CDrawableMock drawing(L"Test");
		Assert::AreEqual(0, drawing.GetPosition().X);
		Assert::AreEqual(0, drawing.GetPosition().Y);

		drawing.SetPosition(Gdiplus::Point(800, 600));
		Assert::AreEqual(800, drawing.GetPosition().X);
		Assert::AreEqual(600, drawing.GetPosition().Y);
	}

	TEST_METHOD(TestCDrawableRotation)
	{
		CDrawableMock drawing(L"Test");
		Assert::AreEqual(0, drawing.GetRotation(), 0.00001);

		drawing.SetRotation(1.01);
		Assert::AreEqual(1.01, drawing.GetRotation(), 0.00001);

		double a = 0.333;
		double b = acos(cos(a));
		Assert::AreEqual(a, b, 0.000000001);
	}

	TEST_METHOD(TestCDrawableAssociation)
	{
		CDrawableMock body(L"Body");
		auto arm = std::make_shared<CDrawableMock>(L"Arm");
		auto leg = std::make_shared<CDrawableMock>(L"Leg");

		body.AddChild(arm);
		body.AddChild(leg);

		Assert::IsTrue(arm->GetParent() == &body);
		Assert::IsTrue(leg->GetParent() == &body);
	}
	};
}