//
// Created by cristina on 29.04.2022.
//

#ifndef EROARE_H
#define EROARE_H
#include <iostream>

class eroare : public std::invalid_argument{
public:
    explicit eroare(const std::string &arg) : invalid_argument(arg){}
};
class eroare_constr : public eroare{
public:
    explicit eroare_constr(const std::string &arg) : eroare(arg){}
};

#endif //EROARE_H
