#include <iostream>
#include "Plot.h"
#include "Wheat.h"
#include "wateringCan.h"

using namespace std;

class WateringCanTest {
public:
    void runWateringCanTests() {
        testConstructor();
        testWaterCrop();
        testUse();
        testGetUses();
        testSetUses();
    }

private:
    void testConstructor() {
        wateringCan can;
        if (can.getUses() == 4) {
        } else {
            cout << "testConstructor failed: Expected 4, got " << can.getUses() << endl;
        }
    }

    void testWaterCrop() {
        wateringCan can;
        Plot plot;
        Wheat wheat;
        plot.sow();
        plot.plantCrop(&wheat);

        can.waterCrop(plot);
        if (wheat.getWaterLevel() == 100 && can.getUses() == 3) {
        } else {
            cout << "testWaterCrop failed: Expected water level 100 and uses 3, got water level "
                 << wheat.getWaterLevel() << " and uses " << can.getUses() << endl;
        }
    }

    void testUse() {
        wateringCan can;
        Plot plot;
        Wheat wheat;
        plot.sow();
        plot.plantCrop(&wheat);

        can.use(plot);
        if (wheat.getWaterLevel() == 100 && can.getUses() == 3) {
        } else {
            cout << "testUse failed: Expected water level 100 and uses 3, got water level "
                 << wheat.getWaterLevel() << " and uses " << can.getUses() << endl;
        }
    }

    void testGetUses() {
        wateringCan can;
        if (can.getUses() == 4) {
        } else {
            cout << "testGetUses (initial) failed: Expected 4, got " << can.getUses() << endl;
        }
        
        Plot plot;
        Wheat wheat;
        plot.sow();
        plot.plantCrop(&wheat);
        can.use(plot);

        if (can.getUses() == 3) {
        } else {
            cout << "testGetUses (after use) failed: Expected 3, got " << can.getUses() << endl;
        }
    }

    void testSetUses() {
        wateringCan can;
        can.setUses(2);
        if (can.getUses() == 2) {
        } else {
            cout << "testSetUses (initial) failed: Expected 2, got " << can.getUses() << endl;
        }

        Plot plot;
        Wheat wheat;
        plot.sow();
        plot.plantCrop(&wheat);
        can.use(plot);

        if (can.getUses() == 1) {
        } else {
            cout << "testSetUses (after use) failed: Expected 1, got " << can.getUses() << endl;
        }
    }
};
