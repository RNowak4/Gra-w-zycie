#include "Obiekt.h"

Obiekt::Obiekt(bool status, unsigned x, unsigned y): status_(status),
                            x_(x), y_(y) { }

Obiekt::Obiekt(const Obiekt& orig) {
}

Obiekt::~Obiekt() {
}