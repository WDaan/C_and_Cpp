#ifndef SCHIJF_H
#define SCHIJF_H

template <typename T>
class Schijf {
   private:
    Doos* raw_ptr;

   public:
    Schijf() : raw_ptr(0);
    Schijf(const Schijf<T>& s) {
        if (schijf.a != 0) {
            a = new Doos<T>(*(schijf.a));
        } else
            a = 0;
    }
    Schijf<T>& operator=(const Schijf<T>&) {
        if (this != &schijf) {
            delete a;
            a = 0;
            if (schijf.a != 0) {
                a = new Doos<T>(*(schijf.a));
            }
        }
        return *this;
    }
    ~Schijf<T>() {  //destructor
        delete raw_ptr;
    }
};

#endif