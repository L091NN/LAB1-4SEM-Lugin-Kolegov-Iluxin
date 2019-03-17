#include "gtest.h"
#include "Monom.h"

TEST(Monom, can_create_monom)
{
	ASSERT_NO_THROW(Monom M);
}

TEST(Monom, cant_create_monom_with_negative_powers)
{
	ASSERT_ANY_THROW(Monom(1.0, -1));
	ASSERT_ANY_THROW(Monom(1.0, 0, -1));
	ASSERT_ANY_THROW(Monom(1.0, 0, 0, -1));
}

TEST(Monom, check_GetXpower)
{
	Monom M(1.0, 7, 3, 8);
	EXPECT_EQ(7, M.GetXpower());
}

TEST(Monom, check_GetYpower)
{
	Monom M(1.0, 7, 3, 8);
	EXPECT_EQ(3, M.GetYpower());
}

TEST(Monom, check_GetZpower)
{
	Monom M(1.0, 7, 3, 8);
	EXPECT_EQ(8, M.GetZpower());
}

TEST(Monom, check_equal)
{
	Monom M1(1.0, 1, 9, 9);
	Monom M2;
	M2.SetXpower(1);
	M2.SetYpower(9);
	M2.SetZpower(9);
	EXPECT_EQ(1, M1 == M2);
}

TEST(Monom, check_assign)
{
	Monom M1(1.0, 1, 9, 9);
	Monom M2 = M1;
	EXPECT_EQ(1,M1 == M2);
}

TEST(Monom, check_plus)
{
	Monom M1(1.0, 1, 9, 9);
	Monom M2 = M1;
	M1 = M1 + M2;
	EXPECT_EQ(2.0, M1.GetK());
}

TEST(Monom, throw_when_power_not_equal)
{
	Monom M1(1.0, 1, 9, 9);
	Monom M2 = M1;
	M1.SetXpower(5);
	ASSERT_ANY_THROW(M1 = M1 + M2);
}

TEST(Monom, p_null_when_k_null)
{
	Monom M(0.0);
	EXPECT_EQ(0, M.Getp());
}
