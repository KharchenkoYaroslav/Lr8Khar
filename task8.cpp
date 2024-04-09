#include <iostream >
using namespace std;
class A
{
    int i;

public:
    A(int a) { i = a; }
    int getA()
    {
        return i;
    }
};
class B
{
    int j;

public:
    B(int a) { j = a; }
    int getB()
    {
        return j;
    }
};
class C : public A, public B
{
    int k;

public:
    C(int a, int b, int c) : A(a), B(b)
    {
        k = c;
    }
    void showABC()
    {
        cout << "A: " << getA() << ", B: " << getB() << ", C: " << k;
    }
};
int main()
{
    C c(1, 2, 3);
    c.showABC();
    return 0;
}
