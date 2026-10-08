#include "header.h"
#include <iostream>
using namespace std;

int Wine::count = 0;

Wine::Wine(double alc, double dens) : alcContent(alc), density(dens) {
    count++;
    cout << "Wine object created. Total objects: " << count << endl;
}

Wine::~Wine() {
    count--;
    cout << "Wine object destroyed. Total objects: " << count << endl;
}

Wine* Wine::create(double alc, double dens) {
    return new Wine(alc, dens);
}

void Wine::destroy(Wine* obj) {
    delete obj;
}

void Wine::checkOut() {
    cout << "Wine checked out. Alcohol content: " << alcContent
         << "%, Density: " << density << endl;
}

void Wine::Diagnose(const char* diagnosis) {
    cout << "Diagnosis for wine: " << diagnosis << endl;
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

void diagnoseWine(Wine& wine, const char* diagnosis) {
    cout << "[Friend function] Diagnosis: " << diagnosis
         << " for wine with alcohol: " << wine.alcContent
         << "% and density: " << wine.density << endl;
}