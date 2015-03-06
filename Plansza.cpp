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
            objectTab_[i][j] = new Obiekt(false, i, j);
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

void gotoxy(SHORT x,SHORT y) {
    COORD coord = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void Plansza::rysujPlansze() {    
    for(int i = 0; i < width_; ++i) {
        for(int j = 0; j < height_; ++j) {
            gotoxy(i,j);
            if(objectTab_[i][j]->getStatus() == true){
                std::cout << "X";
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;            
    }
}

void Plansza::symuluj() {    
    std::vector<Para> vPar;
    unsigned liczba_sasiadow;
    
    for(unsigned i = 0; i < width_; ++i) {
        for(unsigned j = 0; j < height_; ++j) {
            liczba_sasiadow = liczSasiadow(i,j);
            if(liczba_sasiadow == 3)
                vPar.push_back(Para(i,j,true));
            else if(liczba_sasiadow >= 4 || liczba_sasiadow < 2)
                vPar.push_back(Para(i,j,false));
        }
            
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
        if(objectTab_[x+1][y+1]->getStatus())
            ++counter;
    
    if((x-1) >= 0 && (x-1) < width_ && y >= 0 && y < height_)
        if(objectTab_[x-1][y]->getStatus())
            ++counter;
    
    if((x-1) >= 0 && (x-1) < width_ && (y-1) >= 0 && (y-1) < height_)
        if(objectTab_[x-1][y-1]->getStatus())
            ++counter;
    
    if((x) >= 0 && (x) < width_ && (y-1) >= 0 && (y-1) < height_)
        if(objectTab_[x][y-1]->getStatus())
            ++counter;
    
    if((x-1) >= 0 && (x-1) < width_ && (y+1) >= 0 && (y+1) < height_)
        if(objectTab_[x-1][y+1]->getStatus())
            ++counter;
    
    if((x) >= 0 && (x) < width_ && (y+1) >= 0 && (y+1) < height_)
        if(objectTab_[x][y+1]->getStatus())
            ++counter;
    
    if((x+1) >= 0 && (x+1) < width_ && (y-1) >= 0 && (y-1) < height_)
        if(objectTab_[x+1][y-1]->getStatus())
            ++counter;
    
    return counter;
}