#include"gtest.h"
#include"Polinom.h"

TEST(Polinom, can_create_polinom_1)
{
	ASSERT_NO_THROW(Polinom P);
}

TEST(Polinom, can_create_polinom_2)
{
	ASSERT_NO_THROW(Polinom P("x^3y^7z^1"));
}

TEST(Polinom, can_create_polinom_with_1_monom)
{
	Monom M;
	ASSERT_NO_THROW(Polinom P(M));
}

TEST(Polinom, check_sort_polinom)
{
	Polinom P("2.0x7y7z7-0.5z5+5x8");

}