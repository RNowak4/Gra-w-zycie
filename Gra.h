#ifndef GRA_H
#define	GRA_H

#include "Plansza.h"
#include <iostream>
#include <thread>
#include <chrono>

class Gra {
public:
    Gra();
    Gra(const Gra& orig);
    virtual ~Gra();
    void graj();

private:
    unsigned stepTime_;
    Plansza* plansza_;
};

#endif	/* GRA_H */

