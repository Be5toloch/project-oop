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

void runTests() {

    {
        SmallFireFighter firefighter;
        firefighter.setAddress("123 Test St");
        firefighter.fightFire();
        firefighter.chooseEquipment();
    }

    {
        MediumFireFighter firefighter;
        firefighter.setAddress("456 Test St");
        firefighter.fightFire();
        firefighter.chooseEquipment();
    }

    {
        LargeFireFighter firefighter;
        firefighter.setAddress("789 Test St");
        firefighter.fightFire();
        firefighter.chooseEquipment();
    }

    cout << "All tests passed!" << endl;
}


int main() {

    runTests();

    vector<FireFighter*> firefighters;
    firefighters.push_back(new SmallFireFighter());
    firefighters.push_back(new MediumFireFighter());
    firefighters.push_back(new LargeFireFighter());

    string address;
    int fireLevel;
    char continueInput;

    do {
        cout << "Enter the address of the fire: ";
        cin.ignore();
        getline(cin, address);

        cout << "Enter the fire level (1 for small, 2 for medium, 3 for large): ";
        cin >> fireLevel;

        FireFighter* firefighter = nullptr;

        switch (fireLevel) {
            case 1:
                firefighter = new SmallFireFighter();
                break;
            case 2:
                firefighter = new MediumFireFighter();
                break;
            case 3:
                firefighter = new LargeFireFighter();
                break;
            default:
                cout << "Invalid fire level entered." << endl;
                continue;
        }

        firefighter->setAddress(address);
        firefighter->chooseEquipment();
        firefighter->fightFire();

        delete firefighter;

        cout << "Do you want to enter another fire? (y/n): ";
        cin >> continueInput;

    } while (continueInput == 'y');

    return 0;
}
