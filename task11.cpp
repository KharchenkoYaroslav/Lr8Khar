#include <iostream>
using namespace std;
// A base class for various types of vehicles .
class vehicle
{
    int num_wheels;
    int range;

public:
    vehicle(int w, int r)
    {
        num_wheels = w;
        range = r;
    }
    void showv()
    {
        cout << " Wheels : " << num_wheels << '\n';
        cout << " Range : " << range << '\n';
    }
};
enum motor
{
    gas,
    electric,
    diesel
};
class motorized : public virtual vehicle// так як ми використовуємо конструктор vehical неодноразово, необхідно прописати тут virtual
{
    enum motor mtr;

public:
    motorized(enum motor m, int w, int r) : vehicle(w, r)
    {
        mtr = m;
    }
    void showm()
    {
        cout << " Motor : ";
        switch (mtr)
        {
        case gas:
            cout << "Gas \n";
            break;
        case electric:
            cout << " Electric \n";
            break;
        case diesel:
            cout << " Diesel \n";
            break;
        }
    }
};
class road_use : public virtual vehicle// аналогічно до motorized дописано virtual
{
    int passengers;

public:
    road_use(int p, int w, int r) : vehicle(w, r)
    {
        passengers = p;
    }
    void showr()
    {
        cout << " Passengers : " << passengers << '\n';
    }
};
enum steering
{
    power,
    rack_pinion,
    manual
};
class car : public motorized, public road_use
{
    enum steering strng;

public:
    car(enum steering s, enum motor m, int w, int r, int p) : vehicle(w, r), motorized(m, w, r), road_use(p, w, r)// Виправлений порядок виклику конструкторів
    {
        strng = s;
    }
    void show()
    {
        showv();
        showr();
        showm();
        cout << " Steering : ";
        switch (strng)
        {
        case power:
            cout << " Power \n";
            break;
        case rack_pinion:
            cout << " Rack and Pinion \n ";
                break;
        case manual:
            cout << " Manual \n";
            break;
        }
    }
};
int main()
{
    //ХЗ де тут проблема зі свічами, в мене її нема ¯\_(ツ)_/¯
    car c(power, gas, 4, 500, 5);
    c.show();
    return 0;
}