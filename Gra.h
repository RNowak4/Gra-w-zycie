#ifndef GRA_H
#define	GRA_H

#include "Plansza.h"

class Gra {
public:
    Gra();
    Gra(const Gra& orig);
    virtual ~Gra();

private:
    unsigned stepTime_;
    Plansza* plansza_;
};

#endif	/* GRA_H */

