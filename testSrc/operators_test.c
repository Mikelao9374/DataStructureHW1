#include <gtest/gtest.h>

extern "C"
{
#include "operators.h"
}

TEST(Operators, Exchange)
{
	char str[] = "123456779";

	Exchange(str);

	EXPECT_STREQ(str, "977654321");
}

TEST(Operators, Plus)
{
	char int1[] = "1255";
	char int2[] = "70";
	char result[10];

	Plus(int1, int2, result);

	EXPECT_STREQ(result, "1325");
}

TEST(Operators, Mutiply)
{
	char int1[] = "331";
	char int2[] = "2";
	char result[10];

	Mutiply(int1, int2, result);

	EXPECT_STREQ(result, "662");
}
