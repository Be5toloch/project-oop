#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class FireFighter {
protected:
    string address;

public:
    void setAddress(const string& addr) {
        address = addr;
    }

    virtual string fightFire() = 0;
    virtual string chooseEquipment() = 0;
    virtual ~FireFighter() {}
};

class SmallFireFighter : public FireFighter {
public:
    string fightFire() override {
        return "Small fire at " + address + ". Using water extinguisher.";
    }

    string chooseEquipment() override {
        return "Choosing water extinguisher and fire blanket for small fire.";
    }
};

class MediumFireFighter : public FireFighter {
public:
    string fightFire() override {
        return "Medium fire at " + address + ". Using CO2 extinguisher.";
    }

    string chooseEquipment() override {
        return "Choosing CO2 extinguisher and protective gear for medium fire.";
    }
};

class LargeFireFighter : public FireFighter {
public:
    string fightFire() override {
        return "Large fire at " + address + ". Using foam extinguisher and fire hose.";
    }

    string chooseEquipment() override {
        return "Choosing foam extinguisher and fire hose for large fire.";
    }
};

void runTests() {
    {
        SmallFireFighter firefighter;
        firefighter.setAddress("1 Test St");
        assert(firefighter.fightFire() == "Small fire at 1 Test St. Using water extinguisher.");
        assert(firefighter.chooseEquipment() == "Choosing water extinguisher and fire blanket for small fire.");
    }

    {
        MediumFireFighter firefighter;
        firefighter.setAddress("2 Test St");
        assert(firefighter.fightFire() == "Medium fire at 2 Test St. Using CO2 extinguisher.");
        assert(firefighter.chooseEquipment() == "Choosing CO2 extinguisher and protective gear for medium fire.");
    }

    {
        LargeFireFighter firefighter;
        firefighter.setAddress("3 Test St");
        assert(firefighter.fightFire() == "Large fire at 3 Test St. Using foam extinguisher and fire hose.");
        assert(firefighter.chooseEquipment() == "Choosing foam extinguisher and fire hose for large fire.");
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
        cout << firefighter->chooseEquipment() << endl;
        cout << firefighter->fightFire() << endl;

        delete firefighter;

        cout << "Do you want to enter another fire? (y/n): ";
        cin >> continueInput;

    } while (continueInput == 'y');

    return 0;
}
