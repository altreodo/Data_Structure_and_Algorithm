#include <iostream>
#include <math.h>
using namespace std;
class simplecalculator
{
    int a, b;

public:
    int sum, mult, div, sub;
    void get(int x, int y)
    {
        a = x;
        b = y;
    }
    void sumb(void)
    {
        sum = a + b;
    }
    void multiplication(void)
    {
        mult = a * b;
    }
    void division(void)
    {
        div = a / b;
    }
    void subtraction(void)
    {
        sub = a - b;
    }
    void display(void)
    {
        cout << "Addition of " << a << " and " << b << " is " << sum << endl;
        cout << "subtraction of " << a << " and " << b << " is " << sub << endl;
        cout << "multiplication of " << a << " and " << b << " is " << mult << endl;
        cout << "division of " << a << " and " << b << " is " << div << endl;
    }
};
class Scientificalculators
{
    int a, b;

public:
    int s, s2;
    void get2(int x, int y)
    {
        a = x;
        b = y;
    }
    void sin2(void)
    {
        s = sin(a);
        s2 = sin(b);
    }
    void display2(void)
    {
        cout << "sin of " << a << " is " << s << " and "
             << " sin of " << b << " is " << s2 << endl;
    }
};
class Hybridcalculator : public simplecalculator, public Scientificalculators
{
};
int main()
{
    Hybridcalculator obj;
    obj.get(8, 4);
    obj.sumb();
    obj.multiplication();
    obj.division();
    obj.subtraction();
    obj.get2(60, 30);
    obj.display();
    obj.display2();
    return 0;
}