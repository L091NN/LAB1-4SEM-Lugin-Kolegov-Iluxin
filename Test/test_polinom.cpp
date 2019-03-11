#include"gtest.h"
#include"Polinom.h"

using namespace std;

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
	EXPECT_EQ(P.GetPolinom().size(), 3);
	list<Monom> LM = P.GetPolinom();
	auto I = LM.begin();
	EXPECT_EQ(I->Getp(), 800);
	EXPECT_EQ(I->GetNum(), 0);
	I++;
	EXPECT_EQ(I->Getp(), 777);
	EXPECT_EQ(I->GetNum(), 1);
	I++;
	EXPECT_EQ(I->Getp(), 5);
	EXPECT_EQ(I->GetNum(), 2);


}

TEST(Polinom, throw_when_double_plus)
{
	ASSERT_ANY_THROW(Polinom P("x^3y^7z^1++x"));
}

TEST(Polinom, throw_when_last_symbol_incorrect)
{
	ASSERT_ANY_THROW(Polinom P("x^3y^7z^1+"));
}

TEST(Polinom, check_getpolinom_str_1)
{
	string s1 = "1.05(x^3)(y^2)(z^2)+8.00";
	Polinom P(s1);
	string s2 = P.GetPolinom_str();
	EXPECT_EQ(s1, s2);
}

TEST(Polinom, check_getpolinom_str_2)
{
	string s1 = "xyz-3.00xz+8.50(y^6)(z^9)-3.22";
	Polinom P(s1);
	string s2 = P.GetPolinom_str();
	EXPECT_EQ(s1, s2);
}

TEST(Polinom, check_plus)
{
	string s1 = "xyz-3.00xz+8.50(y^6)(z^9)-3.22";
	Polinom P1(s1);
	Polinom P2(s1);
	Polinom P3;
	P3 = P2 + P1;
	string s2 = "2.00xyz-6.00xz+17.00(y^6)(z^9)-6.44";
	EXPECT_EQ(P3.GetPolinom_str(), s2);
}