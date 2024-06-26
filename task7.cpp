#include <iostream>
using namespace std;
// A base class for various types of vehicle:
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
        cout << "Wheels: " << num_wheels << '\n';
        cout << "Range: " << range << '\n';
    }
};
class car : public vehicle
{
    int passengers;

public:
    car(int w, int r, int p) : vehicle(w, r)
    {
        passengers = p;
    }
    void show()
    {
        showv();
        cout << "Passengers: " << passengers << '\n';
    }
};
class truck : public vehicle
{
    int loadlimit;

public:
    truck(int w, int r, int l) : vehicle(w, r)
    {
        loadlimit = l;
    }
    void show()
    {
        showv();
        cout << "Loadlimit: " << loadlimit << '\n';
    }
};
int main()
{
    car objc(5, 4, 500);
    truck objt(3000, 12, 1200); // 3000 Wheels X_X
    cout << "Car:\n";
    objc.show();
    cout << "Truck:\n";
    objt.show();
    return 0;
}
