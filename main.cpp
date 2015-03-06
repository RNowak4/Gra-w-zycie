/***
 * Standardowa wersja gry w zycie
 * Zrobic Plansze jako singleton
 */

#include "Gra.h"

using namespace std;

int main(int argc, char** argv) {
    Gra* gra;
    gra = new Gra();
    gra->graj();
    return 0;
}