#include <iostream >
using namespace std;

class building
{
    int floors;
    int rooms;
    int area;

public:
    building(int floors, int rooms, int area): floors(floors), rooms(rooms), area(area){};

    void showBuilding()
    {
        cout << "Floors: " << floors << endl;
        cout << "Rooms: " << rooms << endl;
        cout << "Area: " << area << endl;
    }
};
class house : public building
{
    int bathrooms;
    int bedrooms;

public:
    house(int floors, int rooms, int area, int bathrooms, int bedrooms) : building(floors, rooms, area)
    {
        this->bathrooms = bathrooms;
        this->bedrooms = bedrooms;
    }
    void show()
    {
        cout << endl << "House:"<< endl << endl;
        showBuilding();
        cout << "Bathrooms: " << bathrooms << endl;
        cout << "Bedrooms: " << bedrooms << endl;
    }
};
class office: public building
{
    int fireExtinguishers;
    int phones;

public:
    office(int floors, int rooms, int area, int fireExtinguishers, int phones) : building(floors, rooms, area)
    {
        this->fireExtinguishers = fireExtinguishers;
        this->phones = phones;
    }
    void show()
    {
        cout << endl << "Office:"<< endl << endl;
        showBuilding();
        cout << "Fire extinguishers: " << fireExtinguishers << endl;
        cout << "Phones: " << phones << endl;
    }
};
int main()
{
    house obj1(2, 5, 200, 2, 3);
    obj1.show();

    office obj2(1, 3, 100, 2, 5);
    obj2.show();
  
    return 0;
}
