#include "Plansza.h"
#include "Obiekt.h"

const unsigned STD_WIDTH = 40;
const unsigned STD_HEIGHT = 40;

Plansza::Plansza() {
    Plansza(STD_WIDTH, STD_HEIGHT);
}

Plansza::Plansza(unsigned wid, unsigned hei): width_(wid), height_(hei) {
    if(width_ < 0 || height_ < 0)
        throw std::runtime_error("Podano zle wielkosci");
    
    objectTab_ = new Obiekt**[width_];
    for(int i = 0; i < width_; ++i) 
        objectTab_[i] = new Obiekt*[height_];
    
    for(int i = 0; i < width_; ++i)
        for(int j = 0; j < height_; ++j)
            objectTab_[i][j] = 0L;
}

Plansza::~Plansza() {
    for(int i = 0; i < width_; ++i)
        for(int j = 0; j < height_; ++j)
            delete objectTab_[i][j];
    
    for(int i = 0; i < width_; ++i) 
       delete[] objectTab_[i];
    
       delete[] objectTab_;
}

void Plansza::ozywKomorke(unsigned x, unsigned y) {
    if(x < 0 || x >= width_ || y < 0 || y >= height_)
        throw std::runtime_error("Zle wspolrzedne");
    
    if(objectTab_[x][y]->getStatus() == false)
        objectTab_[x][y]->changeStatus(true);
}

void Plansza::rysujPlansze() {
    // zal.pl
    for(int i = 0; i < 30; ++i) {
        std::cout << std::endl;
    }
    
    for(int i = 0; i < width_; ++i) {
        for(int j = 0; j < height_; ++j) {
            if(objectTab_[i][j]->getStatus() == true)
                std::cout << "X";
            else 
                std::cout << " ";
        }
        std::cout << std::endl;            
    }
}

void Plansza::symuluj() {    
    std::vector<Para> vPar;
    
    for(unsigned i = 0; i < width_; ++i) {
        for(unsigned j = 0; j < height_; ++j)
            if(liczSasiadow(i,j) == 3)
                vPar.push_back(Para(i,j,true));
            else if(liczSasiadow(i,j) == 4)
                vPar.push_back(Para(i,j,false));
            
    }
    for(std::vector<Para>::iterator it = vPar.begin(); it != vPar.end(); ++it) {
        objectTab_[(*it).x][(*it).y]->changeStatus((*it).zmiana);
    }            
}

unsigned Plansza::liczSasiadow(unsigned x, unsigned y) {
    unsigned counter = 0;
    if((x+1) >= 0 && (x+1) < width_ && y >= 0 && y < height_)
        if(objectTab_[x+1][y]->getStatus())
            ++counter;
    
    if((x+1) >= 0 && (x+1) < width_ && (y+1) >= 0 && (y+1) < height_)
        if(objectTab_[x+1][y]->getStatus())
            ++counter;
    
    if((x-1) >= 0 && (x-1) < width_ && y >= 0 && y < height_)
        if(objectTab_[x+1][y]->getStatus())
            ++counter;
    
    if((x-1) >= 0 && (x-1) < width_ && (y-1) >= 0 && (y-1) < height_)
        if(objectTab_[x+1][y]->getStatus())
            ++counter;
    
    return counter;
}