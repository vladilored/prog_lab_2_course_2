#include "header.h"
#include <iostream>

using namespace std;

int main() {
    cout << "=== Start of main() ===" << endl;
    cout << "Objects count at start of main: " << Wine::getCount() << endl;

    cout << "\n--- Static array creation (via static methods) ---" << endl;
    Wine* staticArray[3];
    staticArray[0] = Wine::create(12.5, 0.99);
    staticArray[1] = Wine::create(14.0, 1.01);
    staticArray[2] = Wine::create(10.0, 0.98);
    cout << "Objects count after static array creation: " << Wine::getCount() << endl;

    cout << "\n--- Dynamic object creation ---" << endl;
    Wine* dynamicWine = Wine::create(15.0, 1.02);
    cout << "Objects count after dynamic object creation: " << Wine::getCount() << endl;

    cout << "\n--- Testing class methods ---" << endl;
    staticArray[0]->checkOut();
    staticArray[1]->Diagnose("Excellent quality");
    dynamicWine->checkOut();
    dynamicWine->Diagnose("Premium vintage");

    cout << "\n--- Testing friend function ---" << endl;
    diagnoseWine(*staticArray[0], "Friend diagnosis: High alcohol content");

    cout << "\n--- Testing external functions ---" << endl;
    Wine* externalWine = externalCreate(18.0, 1.05);
    cout << "Objects count after external creation: " << Wine::getCount() << endl;
    externalWine->checkOut();
    externalDestroy(externalWine);
    cout << "Objects count after external destruction: " << Wine::getCount() << endl;

    cout << "\n--- Static array destruction ---" << endl;
    for (int i = 0; i < 3; i++) {
        Wine::destroy(staticArray[i]);
    }
    cout << "Objects count after static array destruction: " << Wine::getCount() << endl;

    cout << "\n--- Dynamic object destruction ---" << endl;
    Wine::destroy(dynamicWine);
    cout << "Objects count after dynamic object destruction: " << Wine::getCount() << endl;

    cout << "\n=== End of main() ===" << endl;
    cout << "Final objects count: " << Wine::getCount() << endl;

    return 0;
}