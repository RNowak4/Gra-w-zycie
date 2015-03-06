#include "Gra.h"

Gra::Gra() {
    unsigned x,y,time;
    std::cout << "Podaj wymiary planszy" << std::endl;
    std::cin >> x >> y;
    std::cout << "Podaj czas w ms" << std::endl;
    std::cin >> time;
    plansza_ = new Plansza(x,y);
    stepTime_ = time;
    
    int posX, posY;
    std::cout << "Wpisuj namiary na komorki, ktore maja byc zywe" << std::endl
            << "ktorakolwiek wartosc ujemna zakonczy petle i" << std::endl;
    do {
        std::cin >> posX >> posY;
        if(posX < 0 || posY < 0)
            break;
        plansza_->ozywKomorke(posX, posY);
    } while(true);
}

Gra::Gra(const Gra& orig) {
}

Gra::~Gra() {
    delete plansza_;
}

void Gra::graj() {
    while(true) {
        plansza_->symuluj();
        plansza_->rysujPlansze();
        std::this_thread::sleep_for(std::chrono::milliseconds(stepTime_));
    }
}