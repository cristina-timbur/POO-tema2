#include "concert_all.h"
#include <algorithm>


std::ostream &operator<< (std::ostream &os, const concert_all &c){
    os << "Concert: " << c.nume << ". \nAcces culise: " << c.acces_culise << "\n";
    os << "Pret: " << c.pret << "\n";
    os << "Zona: " << c.zona << "\n";
    os << "Piese: \n";
    for (auto const &artist: c.artisti){
        os << "\t" << artist << "\n";
    }
    os << "\n---------------------------------------------\n";
    return os;
}

concert_all::concert_all(const concert_all& c) : concert(c) {
    zona = c.zona;
    pret = c.pret;
    bratara_food = c.bratara_food;
    std::for_each(c.concerte_all.begin(), c.concerte_all.end(), [&](auto &concert_){ concerte_all.push_back(concert_->clone()); });
}

std::shared_ptr<concert> concert_all::clone() const {
    return std::make_shared <concert_all>(*this);
}

void swap(concert_all& c1, concert_all& c2){
    using std::swap;
    swap(c1.concerte_all, c2.concerte_all);
    swap(c1.nume, c2.nume);
    swap(c1.artisti, c2.artisti);
    swap(c1.acces_culise, c2.acces_culise);
}
concert_all& concert_all::operator=(const concert_all& other) {
    auto copie{other};
    swap(copie, *this);
    return *this;
}

concert_all::concert_all() : concert(){}
