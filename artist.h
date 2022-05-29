#ifndef POO_TEMA2_ARTIST_H
#define POO_TEMA2_ARTIST_H

#include "eroare.h"
class artist{
private:
    friend class artist_builder;
    std::string nume;
    int varsta;
//  albumul cel mai popular
    std::string album;
//    daca e trupa sau artist solo;
    bool trupa;

public:
    artist() = default;
    friend std::ostream &operator << (std::ostream &os, const artist& a){
        std::cout << a.nume << " ";
        return os;
    }
    friend std::istream &operator >> (std::istream &in, artist &a){
        std::cin >> a.nume;
        return in;
    }
};

class artist_builder{
private:
    artist a;
public:
    artist_builder() = default;
    artist_builder& nume(const std::string& str){
        a.nume = str;
        return *this;
    }

    artist_builder& varsta(int ani){
        a.varsta = ani;
        return *this;
    }

    artist_builder& album(const std::string& str){
        a.album = str;
        return *this;
    }

    artist_builder& trupa(bool da){
        a.trupa = da;
        return *this;
    }
    artist build(){
        if (a.nume != "")
            return a;
        else
            throw eroare_builder("nu sunt toate atributele artistului setate");
    }
};

#endif //POO_TEMA2_ARTIST_H

