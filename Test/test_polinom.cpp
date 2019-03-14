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
	string s1 = "xyz-3.00xz+8.50(y^2)(z^4)-3.22";
	Polinom P(s1);
	string s2 = P.GetPolinom_str();
	EXPECT_EQ(s1, s2);
}

TEST(Polinom, check_plus)
{
	string s1 = "xyz-3.00xz+8.50(y^2)(z^4)-3.22";
	Polinom P1(s1);
	Polinom P2(s1);
	Polinom P3;
	P3 = P2 + P1;
	string s2 = "2.00xyz-6.00xz+17.00(y^2)(z^4)-6.44";
	EXPECT_EQ(P3.GetPolinom_str(), s2);
}

TEST(Polinom, check_minus)
{
	string s1 = "xyz-3.00xz+8.50(y^2)(z^4)-3.22";
	Polinom P1(s1);
	Polinom P2(s1);
	Polinom P3;
	P3 = P2 - P1;
	string s2 = "";
	EXPECT_EQ(P3.GetPolinom_str(), s2);
}

TEST(Polinom, check_mult_1)
{
	string s1 = "xyz-3.00xz+8.50(y^2)(z^4)-3.22";
	Polinom P1(s1);
	Polinom P2(s1);
	Polinom P3;
	P3 = P2 * P1;
	string s2 = "(x^2)(y^2)(z^2)-6.00(x^2)y(z^2)+9.00(x^2)(z^2)+17.00x(y^3)(z^5)-51.00x(y^2)(z^5)-6.44xyz+19.32xz+72.25(y^4)(z^8)-54.74(y^2)(z^4)+10.36";
	EXPECT_EQ(P3.GetPolinom_str(), s2);
}

TEST(Polinom, check_mult_2)
{
	string s1 = "x+y+z";
	Polinom P1(s1);
	Polinom P2(s1);
	Polinom P3;
	P3 = P2 * P1;
	string s2 = "(x^2)+2.00xy+2.00xz+(y^2)+2.00yz+(z^2)";
	EXPECT_EQ(P3.GetPolinom_str(), s2);
}

TEST(Polinom, check_dx)
{
	string s1 = "(x^6)+(x^2)(z^7)-5x^2y+xyz3-1.0+5.2x";
	Polinom P1(s1);
	P1 = P1.dx();
	string s2 = "6.00(x^5)-10.00xy+2.00x(z^7)+y(z^3)+5.20";
	EXPECT_EQ(P1.GetPolinom_str(), s2);
}

TEST(Polinom, check_dy)
{
	string s1 = "(y^6)+(y^2)(z^7)-5y^2x+xyz3-1.0+5.2y";
	Polinom P1(s1);
	P1 = P1.dy();
	string s2 = "-10.00xy+x(z^3)+6.00(y^5)+2.00y(z^7)+5.20";
	EXPECT_EQ(P1.GetPolinom_str(), s2);
}

TEST(Polinom, check_dz)
{
	string s1 = "(z^6)+(z^2)(y^7)-5z^2x+xyz3-1.0+5.2z";
	Polinom P1(s1);
	P1 = P1.dz();
	string s2 = "3.00xy(z^2)-10.00xz+2.00(y^7)z+6.00(z^5)+5.20";
	EXPECT_EQ(P1.GetPolinom_str(), s2);
}

TEST(Polinom, check_Ix)
{
	string s1 = "(x^3)+(x^7)(z^7)-5x^3y+xyz3-1.0+5x";
	Polinom P1(s1);
	P1 = P1.Ix();
	string s2 = "0.12(x^8)(z^7)-1.25(x^4)y+0.25(x^4)+0.50(x^2)y(z^3)+2.50(x^2)-1.00x";
	EXPECT_EQ(P1.GetPolinom_str(), s2);
}

TEST(Polinom, check_Iy)
{
	string s1 = "(x^3)+(x^7)(z^7)-5x^3y+xyz3-1.0+5x";
	Polinom P1(s1);
	P1 = P1.Iy();
	string s2 = "(x^7)y(z^7)-2.50(x^3)(y^2)+(x^3)y+0.50x(y^2)(z^3)+5.00xy-1.00y";
	EXPECT_EQ(P1.GetPolinom_str(), s2);
}

TEST(Polinom, check_Iz)
{
	string s1 = "(x^3)+(x^7)(z^7)-5x^3y+xyz3-1.0+5x";
	Polinom P1(s1);
	P1 = P1.Iz();
	string s2 = "0.12(x^7)(z^8)-5.00(x^3)yz+(x^3)z+0.25xy(z^4)+5.00xz-1.00z";
	EXPECT_EQ(P1.GetPolinom_str(), s2);
}

TEST(Polinom, check_count_1)
{
	string s1 = "x+y+z";
	Polinom P(s1);
	EXPECT_EQ(P.count(1, 1, 1), 3.0);
}

TEST(Polinom, check_count_2)
{
	string s1 = "2.0x+y5+5.0z2";
	Polinom P(s1);
	EXPECT_EQ(P.count(0, 2, 2), 52.0);
}

TEST(Polinom, check_count_3)
{
	string s1 = "x9y9z9-3z9+x-5+yz-3";
	Polinom P(s1);
	EXPECT_EQ(P.count(-1, -1, 2), -1035.0);
}