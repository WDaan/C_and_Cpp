#ifndef DOOS_H
#define DOOS_H

template <typename T>
class Doos {
   private:
    Doos<T>* c;     //c in de opgave, pointer naar volgende doos
    vector<T> b;    //vector
    Schijf<T>** d;  //array van schijven

   public:
    Doos<T>() : b(4), c(0) {
        d = new Schijf<T>*[3];
        for (int i = 0; i < 3; i++) d[i] = 0;
    }
    virtual ~Doos() {
        delete c;
        for (int i = 0; i < 3; i++) {
            delete (d[i]);
        }
        delete[] d;
    }
    template <typename T>
    Doos(const Doos<T>& ds) {
        b = doos.b;  //vector kopieren
        if (doos.c != 0) {
            c = new Doos<T>(doos.c);
        } else
            c = 0;
        d = new Schijf<T>*[3];  //3 elementen in de array
        // de elementen van de array d moeten nu elk een nieuwe schijf toegewezen krijgen , als
        // de parameter ’doos’ daar ook een schijf heeft.
        for (int i = 0; i < 3; i++) {
            if (doos.d[i] != 0) {
                d[i] = new Schijf<T>(*doos.d[i]);
            } else
                d[i] = 0;
        }
    }
    template <typename T>
    Doos& operator=(const Doos > T > &ds) {
        if (this != &doos) {
            b = doos.b;  //vector kopieren
            delete c;
            if (doos.c != 0) {
                c = new Doos<T>(*(doos.c));
            }  // de elementen van de array d moeten nu elk een nieuwe schijf toegewezen krijgen , als
            // de parameter ’doos’ daar ook een schijf heeft.
            for (int i = 0; i < 3; i++) {
                delete d[i];
                if (doos.d[i] != 0) {
                    d[i] = new Schijf<T>(*(doos.d[i]));
                } else
                    d[i] = 0;
            }
        }
        return *this;
    }
    Doos(Doos<T>&& ds) : b(move(ds.b)), c(ds.c), d(ds.d) {  //move constructor
        ds.c = nullptr;
        ds.d = nullptr;
    }
    Doos<T>& operator=(Doos<T>&& ds) {  //move operator
        if (this ! = ds) {
            b = move(ds.b);
            c = ds.c;
            ds.c = nullptr;
            for (int i = 0; i < 3; i++) delete (d[i]);  //oude array verwijderen
            delete[] d;
            d = ds.d;
            ds.d = nullptr;
        }
        return *this;
    }
};

#endif