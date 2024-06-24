#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Base class FireFighter
class FireFighter {
protected:
    string address;

public:
    void setAddress(const string& addr) {
        address = addr;
    }

    virtual void fightFire() = 0;
    virtual void chooseEquipment() = 0;
    virtual ~FireFighter() {}
};
