#include <iostream>
using namespace std;

class Base
{
public:
    static int people_on_base;
    static int vehicles_on_base;
    static double petrol_on_base;
    static double goods_on_base;
};

class Vehicle
{
protected:
    double petrol_amount;
    double tank_volume;

public:
    Vehicle(double petrol, double tank);
    virtual ~Vehicle() = default;

    double getTankVolume() const;
    double getPetrolAmount() const;

    virtual void arrive();
    virtual bool leave();
};

class Bus : public Vehicle
{
    int people_count;
    int max_people;

public:
    Bus(int people, int max_people, double petrol, double tank);
    int getPeopleCount() const;
    int getMaxPeople() const;

    void arrive() override;
    bool leave() override;
};

class Truck : public Vehicle
{
    double load;
    double max_load;

public:
    Truck(double load, double max_load, double petrol, double tank);
    double getCurrentLoad() const;
    double getMaxLoad() const;

    void arrive() override;
    bool leave() override;
};

