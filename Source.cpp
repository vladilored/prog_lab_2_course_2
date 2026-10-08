#include "header.h"
#include <iostream>

int Wine::count = 0;

Wine::Wine(double alc, double dens) : alcContent(alc), density(dens) {
    count++;
    std::cout << "Wine object created. Total objects: " << count << std::endl;
}

Wine::~Wine() {
    count--;
    std::cout << "Wine object destroyed. Total objects: " << count << std::endl;
}

Wine* Wine::create(double alc, double dens) {
    return new Wine(alc, dens);
}

void Wine::destroy(Wine* obj) {
    delete obj;
}

void Wine::checkOut() {
    std::cout << "Wine checked out. Alcohol content: " << alcContent
              << "%, Density: " << density << std::endl;
}

void Wine::Diagnose(const char* diagnosis) {
    std::cout << "Diagnosis for wine: " << diagnosis << std::endl;
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
    std::cout << "[Friend function] Diagnosis: " << diagnosis
              << " for wine with alcohol: " << wine.alcContent
              << "% and density: " << wine.density << std::endl;
}