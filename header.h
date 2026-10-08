#ifndef HEADER_H
#define HEADER_H

class Wine {
private:
    double alcContent;
    double density;
    static int count;

    Wine(double alc = 0.0, double dens = 0.0);
    ~Wine();

public:
    static Wine* create(double alc = 0.0, double dens = 0.0);
    static void destroy(Wine* obj);

    void checkOut();
    void Diagnose(const char* diagnosis);

    static int getCount();

    friend Wine* externalCreate(double alc, double dens);
    friend void externalDestroy(Wine* obj);
    friend void diagnoseWine(Wine& wine, const char* diagnosis);
};

Wine* externalCreate(double alc, double dens);
void externalDestroy(Wine* obj);
void diagnoseWine(Wine& wine, const char* diagnosis);

#endif