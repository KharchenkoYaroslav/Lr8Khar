#include <iostream>
using namespace std;
class coord
{
public:
    int x, y; 
    coord()
    {
        x = 0;
        y = 0;
    }
    coord(int i, int j)
    {
        x = i;
        y = j;
    }
    void get_xy(int &i, int &j)
    {
        i = x;
        j = y;
    }
    friend coord operator+(const coord &ob1, const coord &ob2);
    friend coord operator-(const coord &ob1, const coord &ob2);
    coord operator=(coord ob2);
};
// Overload + relative to coord class .
coord operator+(const coord &ob1, const coord &ob2)
{
    coord temp;
    cout << " Using coord operator +() \n";
    temp.x = ob1.x + ob2.x;
    temp.y = ob1.y + ob2.y;
    return temp;
} // Overload - relative to coord class .
coord operator-(const coord &ob1, const coord &ob2)
{
    coord temp;
    cout << " Using coord operator -() \n";
    temp.x = ob1.x - ob2.x;
    temp.y = ob1.y - ob2.y;
    return temp;
}
// Overload = relative to coord .
coord coord::operator=(coord ob2)
{
    cout << " Using coord operator =() \n";
    x = ob2.x;
    y = ob2.y;
    return *this; 
}
class quad : public coord
{
    int quadrant;

public:
    quad()
    {
        x = 0;
        y = 0;
        quadrant = 0;
    }
    quad(int x, int y) : coord(x, y)
    {
        if (x >= 0 && y >= 0)
            quadrant = 1;
        else if (x < 0 && y >= 0)
            quadrant = 2;
        else if (x < 0 && y < 0)
            quadrant = 3;
        else
            quadrant = 4;
    }
    void showq()
    {
        cout << " Point in Quadrant : " << quadrant << '\n';
    }
    quad operator=(coord ob2);
};
quad quad ::operator=(coord ob2)
{
    cout << " Using quad operator =() \n";
    x = ob2.x;
    y = ob2.y;
    if (x >= 0 && y >= 0)
        quadrant = 1;
    else if (x < 0 && y >= 0)
        quadrant = 2;
    else if (x < 0 && y < 0)
        quadrant = 3;
    else
        quadrant = 4;
    return *this;
}
int main()
{
    quad o1(10, 10), o2(15, 3), o3;
    int x, y;
    o3 = o1 + o2; // невідома координатна чверть, виклик quad operator =()
    o3.get_xy(x, y);
    o3.showq();
    cout << "(o1 + o2) X: " << x << ", Y: " << y << "\n";
    o3 = o1 - o2; // невідома координатна чверть, виклик quad operator =()
    o3. get_xy (x, y);
    o3.showq();
    cout << "(o1 - o2) X: " << x << ", Y: " << y << "\n";
    o3 = o1; // координатна чверть відома та не змінюється, виклик coord operator =()
    o3. get_xy (x, y); o3. showq (); 
    cout << "(o3 = o1) X: " << x << ", Y: " << y << "\n";
    return 0;
}