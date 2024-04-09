#include <iostream>
using namespace std;
class mybase
{
    int a, b;

public:
    int c;
    void setab(int i, int j)
    {
        a = i;
        b = j;
    }
    void getab(int &i, int &j)
    {
        i = a;
        j = b;
    }
};
class derived1 : public mybase
{
    // ...
};
class derived2 : private mybase
{
    // ...
};
int main()
{
    derived1 obj1;
    //derived2 obj2;// - просто щоб компілятор не жалівся що об'єкт не використовується
    int i, j;

    obj1.getab(i, j);
    //obj2.getab(i, j); //не можна бо маємо приватне наслідування
    obj1.c = 10;
    //obj2.c = 10; //не можна бо маємо приватне наслідування
}