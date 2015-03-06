#ifndef OBIEKT_H
#define	OBIEKT_H

class Obiekt {
public:
    Obiekt(bool, unsigned, unsigned);
    Obiekt(const Obiekt& orig);
    virtual ~Obiekt();
    unsigned returnX() { return x_; }
    unsigned returnY() { return y_; }
    void changeStatus(bool statusToChange) {
        status_ = statusToChange;
    }
    bool getStatus() { return status_; }
    
private:
    unsigned x_,y_;
    bool status_;
};

#endif	/* OBIEKT_H */

