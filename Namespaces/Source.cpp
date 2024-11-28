#include "MilitaryBase.h"

int main()
{
    cout << "Initial state of the base:" << endl;
    cout << "People: " << Base::people_on_base << endl;
    cout << "Vehicles: " << Base::vehicles_on_base << endl;
    cout << "Petrol: " << Base::petrol_on_base << " liters" << endl;
    cout << "Goods: " << Base::goods_on_base << " tons" << endl;

    Bus bus(34, 30, 10, 50);
    Truck truck(6, 10, 20, 60);

    cout << "Bus arriving..." << endl;
    bus.arrive();

    cout << "Truck arriving..." << endl;
    truck.arrive();

    cout << "State of the base after arrivals:" << endl;
    cout << "People: " << Base::people_on_base << endl;
    cout << "Vehicles: " << Base::vehicles_on_base << endl;
    cout << "Petrol: " << Base::petrol_on_base << " liters" << endl;
    cout << "Goods: " << Base::goods_on_base << " tons" << endl;

    cout << "Bus leaving..." << endl;
    if (bus.leave())
    {
        cout << "Bus left the base." << endl;
    }
    else
    {
        cout << "Bus couldn't leave the base." << endl;
    }

    cout << "Truck leaving..." << endl;
    if (truck.leave())
    {
        cout << "Truck left the base." << endl;
    }
    else
    {
        cout << "Truck couldn't leave the base." << endl;
    }

    cout << "Final state of the base:" << endl;
    cout << "People: " << Base::people_on_base << endl;
    cout << "Vehicles: " << Base::vehicles_on_base << endl;
    cout << "Petrol: " << Base::petrol_on_base << " liters" << endl;
    cout << "Goods: " << Base::goods_on_base << " tons" << endl;

    return 0;
}
