#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>

template <typename T>
class user;
template <typename T>
std::ostream &operator<<(std::ostream &out, const user<T> &u);
template <typename T>
std::istream &operator>>(std::istream &in, user <T> &u);
template <typename T>
class user {
	std::string lastname, firstname;
	std::string email; 
    int age;
    // orele de inceput si sfarsit ale concertului preferate de user (pentru sondaj)
    T ora_inceput;
    T ora_final;
public:
    user(std::string lastname="-", std::string firstname="-", std::string email="-", int age=18, const T ora_inceput=12);
    virtual ~user() = default;
    void Quest();
    T calcDurata() const;
    friend std::ostream &operator<< <>(std::ostream &out, const user<T> &u);
    friend std::istream &operator>> <>(std::istream &in, user <T> &u);
};

#endif //USER_H
