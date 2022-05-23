//
// Created by cristina
//

#ifndef EROARE_H
#define EROARE_H
#include <iostream>

class eroare_aplicatie : public std::invalid_argument{
public:
    explicit eroare_aplicatie(const std::string &arg) : invalid_argument(arg){}
};
class eroare_ora_concert : public eroare_aplicatie{
public:
    explicit eroare_ora_concert(const std::string &arg) : eroare_aplicatie(arg){}
};
class eroare_nr_artist: public eroare_aplicatie{
public:
    explicit eroare_nr_artist(const std::string &arg) : eroare_aplicatie(arg){}
};
#endif //EROARE_H