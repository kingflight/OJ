#include <fun.c>
#include <gtest/gtest.h>

TEST(Fun1Test,a)
{
	EXPECT_EQ('9',i2cnum(9));
	EXPECT_EQ('8',i2cnum(8));
	EXPECT_EQ('7',i2cnum(7));
}

int main(int argc ,char** argv)
{
	testing::InitGoogleTest(&argc,argv);
	int dwResult = RUN_ALL_TESTS();
	return dwResult;
}
