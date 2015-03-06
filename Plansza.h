#ifndef PLANSZA_H
#define	PLANSZA_H

#include <stdexcept>
#include <iostream>
#include <vector>

class Obiekt;

class Plansza {
public:
    Plansza();
    Plansza(unsigned, unsigned);
    Plansza(const Plansza& orig);
    virtual ~Plansza();
    void ozywKomorke(unsigned, unsigned);
    void symuluj();
    void rysujPlansze();

private:
    unsigned width_, height_;
    Obiekt*** objectTab_;
    unsigned liczSasiadow(unsigned, unsigned);
    
    struct Para{
        Para(unsigned X, unsigned Y, bool z): x(X), y(Y), zmiana(z) { }
        unsigned x,y;
        bool zmiana;
    };
};


#endif	/* PLANSZA_H */

