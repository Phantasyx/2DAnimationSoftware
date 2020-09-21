/**
 * \file CPictureObserverTest.cpp
 *
 * \author Jordan Hill
 */
#include "stdafx.h"
#include "PictureObserver.h"
#include "Picture.h"

#include"CppUnitTest.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace Testing
{ 
class CPictureObserverMock : public CPictureObserver
{
public:
	CPictureObserverMock() : CPictureObserver() {}
	virtual void UpdateObserver() override { mUpdated = true; }
   bool mUpdated = false;


};

TEST_CLASS(CPictureObserverTest)
{
	TEST_METHOD(TestCPictureObserverConstruct)
	{

		CPictureObserverMock observer;
	}

	TEST_METHOD(TestCPictureObserverOneObserver)
	{
		// Allocate a CPicture object
		shared_ptr<CPicture> picture = make_shared<CPicture>();

		// Create a mock observer object
		CPictureObserverMock observer;

		// And set it for the observer:
		observer.SetPicture(picture);

		picture->UpdateObservers();

		Assert::IsTrue(observer.mUpdated);
	}

	TEST_METHOD(TestGetPicture)
	{

		CPictureObserverMock observer;
		shared_ptr<CPicture> picture = make_shared<CPicture>();
		
		observer.SetPicture(picture);
		Assert::IsTrue(observer.GetPicture() == picture);
	}


	TEST_METHOD(TestCPictureObserverTwoObservers)
	{

		CPictureObserverMock observer;
		CPictureObserverMock observer2;
		shared_ptr<CPicture> picture = make_shared<CPicture>();

		observer.SetPicture(picture);
		observer2.SetPicture(picture);

		picture->UpdateObservers();

		Assert::IsTrue(observer.mUpdated);
		Assert::IsTrue(observer2.mUpdated);
	}

	TEST_METHOD(TestDestructor)
	{
	
		CPictureObserverMock observer;
		shared_ptr<CPicture> picture = make_shared<CPicture>();

		observer.SetPicture(picture);

		{
			CPictureObserverMock observer2;

			// And set it for the observer:
			observer2.SetPicture(picture);
		}

		picture->UpdateObservers();

		Assert::IsTrue(observer.mUpdated);
	}
};




}