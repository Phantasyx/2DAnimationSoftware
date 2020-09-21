#include "stdafx.h"
#include "CppUnitTest.h"
#include "Timeline.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CTimelineTest)
	{
	public:
		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestCTimelineGetDuration)
		{
			CTimeline timeline;

			// Default value
			Assert::AreEqual(10, timeline.GetDuration(), 0.0001);

			// Changed duration
			timeline.SetFrameRate(375);
			Assert::AreEqual(300.0 / 375.0, timeline.GetDuration(), 0.0001);

			timeline.SetNumFrames(789);
			Assert::AreEqual(789.0 / 375.0, timeline.GetDuration(), 0.0001);
		}

		TEST_METHOD(TestCTimelineGetCurrentFrame)
		{
			CTimeline timeline;

			// Default value
			Assert::AreEqual(0, timeline.GetCurrentFrame());

			// Changed time
			timeline.SetCurrentTime(9.27);
			Assert::AreEqual(278, timeline.GetCurrentFrame());
		}

		TEST_METHOD(TestCTimelineGetNumFrames)
		{
			CTimeline timeline;

			Assert::AreEqual(300, timeline.GetNumFrames());
			timeline.SetNumFrames(123);
			Assert::AreEqual(123, timeline.GetNumFrames());
		}
		TEST_METHOD(TestCTimelineGetFrameRate)
		{
			CTimeline timeline;

			Assert::AreEqual(30, timeline.GetFrameRate());
			timeline.SetFrameRate(24);
			Assert::AreEqual(24, timeline.GetFrameRate());
		}

		TEST_METHOD(TestCTimelineCurrentTime)
		{
			CTimeline timeline;

			Assert::AreEqual(0.0, timeline.GetCurrentTime(), 0.0001);
			timeline.SetCurrentTime(4.00);
			Assert::AreEqual(4.00, timeline.GetCurrentTime(), 0.0001);
		}
		
	};
}