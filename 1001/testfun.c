#include <fun.c>
#include <gtest/gtest.h>

TEST(Fun1Test,a)
{
	EXPECT_EQ('9',i2cnum(9));
	EXPECT_EQ('8',i2cnum(8));
	EXPECT_EQ('7',i2cnum(7));
}

TEST(countAfterPointNum,a)
{
	EXPECT_EQ(5,countAfterPointNum("0.00023"));
	EXPECT_EQ(1,countAfterPointNum("0.3"));
	EXPECT_EQ(0,countAfterPointNum("23"));
}

TEST(myStrip,one)
{
	char s1[100]="0023.002300";
	char s1_r[100]="23.0023";
	myStripZeros(s1);	
	EXPECT_EQ(strcmp(s1,s1_r),0);
}

int main(int argc ,char** argv)
{
	testing::InitGoogleTest(&argc,argv);
	int dwResult = RUN_ALL_TESTS();
	return dwResult;
}
