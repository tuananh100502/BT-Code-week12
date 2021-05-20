#include <iostream>
 
class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};
 
public:
	Fraction(int numerator=0, int denominator=1):
		m_numerator{numerator}, m_denominator{denominator}
	{
		
		reduce();
	}
 
	
	static int gcd(int a, int b)
	{
		return b == 0 ? a : gcd(b, a % b);
	}
 
	void reduce()
	{
		if (m_numerator != 0 && m_denominator != 0)
		{
			int gcd{ Fraction::gcd(m_numerator, m_denominator) };
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
	}
 
	friend Fraction operator*(const Fraction &f1, const Fraction &f2);
	friend Fraction operator*(const Fraction &f1, int value);
	friend Fraction operator*(int value, const Fraction &f1);
 
	void print() const
	{
		std::cout << m_numerator << '/' << m_denominator << '\n';
	}
};
 
Fraction operator*(const Fraction &f1, const Fraction &f2)
{
	return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}
 
Fraction operator*(const Fraction &f1, int value)
{
	return Fraction(f1.m_numerator * value, f1.m_denominator);
}
 
Fraction operator*(int value, const Fraction &f1)
{
	return Fraction(f1.m_numerator * value, f1.m_denominator);
}

int main()
{
	Fraction f1{};
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;
 
	Fraction f2{};
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;
 
	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value
 
	return 0;
}
