#include <fun.c>
#include <gtest/gtest.h>
#include <string>

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
	EXPECT_STREQ(s1,s1_r);
	
	char s2[100]="00.0000";
	char s2_r[100]="0";
	myStripZeros(s2);	
	EXPECT_STREQ(s2,s2_r);

	char s3[100]="00.0300";
	char s3_r[100]=".03";
	myStripZeros(s3);	
	EXPECT_STREQ(s3,s3_r);

	char s4[100]="00300";
	char s4_r[100]="300";
	myStripZeros(s4);	
	EXPECT_STREQ(s4,s4_r);
}

TEST(isAllZero,one)
{
	EXPECT_TRUE(isAllZero("0000000"));
	EXPECT_FALSE(isAllZero("0.0000.0"));
	EXPECT_TRUE(isAllZero("0"));
}

TEST(deleteindex,one)
{
	char s[50] = "he is a fool";
	deleteindex(s,8);
	EXPECT_STREQ(s,"he is a ool");
	deleteindex(s,0);
	EXPECT_STREQ(s,"e is a ool");
}

TEST(char_num_convert,one)
{
	EXPECT_EQ('1',i2cnum(1));
	EXPECT_EQ('2',i2cnum(2));
	EXPECT_EQ('3',i2cnum(3));
	EXPECT_EQ('4',i2cnum(4));
	EXPECT_EQ('5',i2cnum(5));
	EXPECT_EQ('6',i2cnum(6));
	EXPECT_EQ('7',i2cnum(7));
	EXPECT_EQ('8',i2cnum(8));
	EXPECT_EQ('9',i2cnum(9));
	
	EXPECT_EQ(9,cnum2i('9'));
}

TEST(HasDecPoint,one)
{
	char s[50] = "0.00023";
	EXPECT_TRUE(HasDecPoint(s));
	char s1[50] = "102343512";
	EXPECT_FALSE(HasDecPoint(s1));
}

TEST(insertMultiCharAtBegin,one)
{
	char s[50] = "234";
	char s_r[50] = "00000234";
	insertMultiCharAtBegin(s,5,'0');
	EXPECT_STREQ(s,s_r);
}

int main(int argc ,char** argv)
{
	testing::InitGoogleTest(&argc,argv);
	int dwResult = RUN_ALL_TESTS();
	return dwResult;
}
