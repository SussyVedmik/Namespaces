#include "MilitaryBase.h"

int Base::people_on_base = 20;
int Base::vehicles_on_base = 6;
double Base::petrol_on_base = 800.0;
double Base::goods_on_base = 34.0;

Vehicle::Vehicle(double petrol, double tank) : petrol_amount(petrol), tank_volume(tank) {}

double Vehicle::getTankVolume() const
{
    return tank_volume;
}

double Vehicle::getPetrolAmount() const
{
    return petrol_amount;
}

void Vehicle::arrive()
{
    Base::vehicles_on_base++;
    Base::people_on_base++;
}

bool Vehicle::leave()
{
    if (Base::people_on_base < 1 || Base::petrol_on_base < (tank_volume - petrol_amount))
        return false;

    Base::people_on_base--;
    Base::petrol_on_base -= (tank_volume - petrol_amount);
    petrol_amount = tank_volume;
    Base::vehicles_on_base--;
    return true;
}

Bus::Bus(int people, int max_people, double petrol, double tank)
    : Vehicle(petrol, tank), people_count(people), max_people(max_people) {}

int Bus::getPeopleCount() const
{
    return people_count;
}

int Bus::getMaxPeople() const
{
    return max_people;
}

void Bus::arrive()
{
    Vehicle::arrive();
    Base::people_on_base += people_count;
    people_count = 0;
}

bool Bus::leave()
{
    if (!Vehicle::leave())
        return false;

    int people_to_take = min(max_people, Base::people_on_base);
    Base::people_on_base -= people_to_take;
    people_count = people_to_take;
    return true;
}

Truck::Truck(double load, double max_load, double petrol, double tank)
    : Vehicle(petrol, tank), load(load), max_load(max_load) {}

double Truck::getCurrentLoad() const
{
    return load;
}

double Truck::getMaxLoad() const
{
    return max_load;
}

void Truck::arrive()
{
    Vehicle::arrive();
    Base::goods_on_base += load;
    load = 0;
}

bool Truck::leave()
{
    if (!Vehicle::leave())
        return false;

    double load_to_take = min(max_load, Base::goods_on_base);
    Base::goods_on_base -= load_to_take;
    load = load_to_take;
    return true;
}
