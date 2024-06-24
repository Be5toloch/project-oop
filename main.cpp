#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

class SmallFireFighter : public FireFighter {
public:
    void fightFire() override {
        cout << "Small fire at " << address << ". Using water extinguisher." << endl;
    }

    void chooseEquipment() override {
        cout << "Choosing water extinguisher and fire blanket for small fire." << endl;
    }
};
