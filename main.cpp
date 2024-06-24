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

class MediumFireFighter : public FireFighter {
public:
    void fightFire() override {
        cout << "Medium fire at " << address << ". Using CO2 extinguisher." << endl;
    }

    void chooseEquipment() override {
        cout << "Choosing CO2 extinguisher and protective gear for medium fire." << endl;
    }
};

class LargeFireFighter : public FireFighter {
public:
    void fightFire() override {
        cout << "Large fire at " << address << ". Using foam extinguisher and fire hose." << endl;
    }

    void chooseEquipment() override {
        cout << "Choosing foam extinguisher and fire hose for large fire." << endl;
    }
};