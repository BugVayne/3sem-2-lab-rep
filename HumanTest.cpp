#include "pch.h"
#include "CppUnitTest.h"
#include"Human.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(HumanTest)
	{
	public:
		TEST_METHOD(PrintInfoTest)
		{
			Human human;
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			human.PrintInfo();
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual('t', a);
		}
	};	
}
