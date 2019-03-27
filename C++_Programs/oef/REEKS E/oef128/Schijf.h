#ifndef SCHIJF_H
#define SCHIJF_H

template <typename T>
class Schijf {
   private:
    Doos<T>* a;

   public:
    Schijf() : a(0);
    Schijf(const Schijf<T>& s) {
        if (s.a != 0) {
            a = new Doos<T>(*(s.a));
        } else
            a = 0;
    }
    Schijf<T>& operator=(const Schijf<T>& schijf) {
        if (this != &schijf) {
            delete a;
            a = 0;
            if (schijf.a != 0) {
                a = new Doos<T>(*(schijf.a));
            }
        }
        return *this;
    }
    virtual ~Schijf<T>() {  //destructor
        delete a;
    }
    (Schijf<T>&& s) : a(s.a) {  //move constructor
        s.a = nullptr;
    }
    Schijf<T>& operator=(Schijf<T>&& s) {  //move operator
        if (this != &s) {
            a = s.a;
            s.a = nullptr;
        }
        return *this;
    }
};

#endif