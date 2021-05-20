#include<iostream>
using namespace std;
class Fraction
{
public:
		const int Tu_so;
		const int Mau_so;
        int convert(int a, int b) {
        
            if (a == 0 || b == 0) {
                return a + b;
            }
            while (a != b) {
                if (a > b) {
                    a=a-b; 
                }
                else {
                    b=b-a;
                }
            }
            return a; 
        }

		void print(int a)
		{
            cout << this->Tu_so / a<< "/" << this->Mau_so / a;
		}
};

int main() {
	Fraction fraction1 = { 7, 21 };
	fraction1.print(fraction1.convert(fraction1.Tu_so, fraction1.Mau_so));
	return 0;
}
