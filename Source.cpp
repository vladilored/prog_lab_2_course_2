#include "header.h"
#include <iostream>
#include <iomanip>

using namespace std;

int Wine::count = 0;

void Wine::normalizeData() {
    if (alcContent < 0.0) alcContent = 0.0;
    if (alcContent > 100.0) alcContent = 100.0;
    if (density < 0.5) density = 0.5;
}

Wine::Wine(double alc, double dens) : alcContent(alc), density(dens) {
    normalizeData();
    count++;
    cout << "  [Wine Constructor] Object created (" << fixed << setprecision(2)
         << alcContent << "%, " << density << " g/cm3). Total objects: " << count << endl;
}

Wine::~Wine() {
    count--;
    cout << "  [Wine Destructor] Object destroyed. Total objects: " << count << endl;
}

Wine* Wine::create(double alc, double dens) {
    return new Wine(alc, dens);
}

void Wine::destroy(Wine* obj) {
    delete obj;
}

void Wine::age() {
    alcContent += 0.3;
    density -= 0.002;
    normalizeData();
    cout << "  [Method age()] Wine aged. Alcohol: " << fixed << setprecision(2)
         << alcContent << "%, Density: " << density << " g/cm3" << endl;
}

void Wine::dilute(double ratio) {
    if (ratio <= 1.0) {
        cout << "  [Method dilute()] Ratio must be greater than 1.0!" << endl;
        return;
    }
    alcContent /= ratio;
    density = (density + (ratio - 1.0) * 1.0) / ratio;
    normalizeData();
    cout << "  [Method dilute()] Diluted by factor " << ratio << ". Alcohol: "
         << fixed << setprecision(2) << alcContent << "%, Density: " << density << " g/cm3" << endl;
}

void Wine::printInfo() const {
    cout << "  [Wine Info] Alcohol: " << fixed << setprecision(2) 
         << alcContent << "%, Density: " << density << " g/cm3" << endl;
}

int Wine::getCount() {
    return count;
}

Wine* externalCreate(double alc, double dens) {
    return new Wine(alc, dens);
}

void externalDestroy(Wine* obj) {
    delete obj;
}

void inspectWine(const Wine& wine) {
    cout << "  [Friend function inspectWine] Accessing private members -> Alcohol: "
         << fixed << setprecision(2) << wine.alcContent << "%, Density: " 
         << wine.density << " g/cm3" << endl;
}