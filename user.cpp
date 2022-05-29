#include "user.h"
#include <fstream>

template<typename T>
user<T>::user(T ora_inceput, T ora_final, std::string lastname, std::string firstname, std::string email, int age):
    lastname(std::move(lastname)), firstname(std::move(firstname)), email(std::move(email)), age(age), ora_inceput(ora_inceput), ora_final(ora_final){}

template<typename T>
std::ostream &operator<<(std::ostream &out, const user<T> &u) {
	out << "User: " << u.lastname << " " << u.firstname << ". Email: ." << u.email << "Age: "<< u.age << ".\n";
	return out;
}

template<typename T>
T user<T>::calcDurata() const{
    return (T) (ora_final - ora_inceput);
}

template<typename T>
std::istream &operator>>(std::istream &in, user<T> &u) {
	std::string email;
    int age;
	std::cout << "Please enter your first and last name: ";
	in >> u.firstname >> u.lastname;
	std::cout << "Please enter your email: ";

	while (true) {
		in >> email;
			if (email.find('@') >= email.length())
				std::cout <<"Invalid input! Please enter a real email.\n";
			else
                break;
	}
	u.email = email;
	std::cout << "Please enter your age: ";
    while (true){
        in >> age;
            if (age <= 0 or age > 105)
                std::cout << "Invalid age! \n";
            else
                break;
    }
    u.age = age;
    std::cout << "Please enter your preferred start hour: ";
    in >> u.ora_inceput;
    std::cout << "Please enter your preferred final hour: ";
    in >> u.ora_final;
	return in;
}

template<typename T>
void user<T>::Quest(){
    std::string ans, name, fname;
    std::ofstream fout("quest.txt", std::ios::app);

    std::cout << "Where did you find out about our festival?\n";
    std::cout << "1) friends.   2) media.  3)family.\n";
    while (true){
        std::cin >> ans;
        if (ans != "friends" && ans != "media" && ans != "family")
            std::cout << "Choose one of the options from above.\n";
        else
            break;
    }
    if (age < 16){
        std::cout << "All under 16’s must be accompanied by an adult ticket holder, (parent or guardian) who is over 18 years old.\n";
        std::cout << "Please introduce the following information:\n";
        std::cout << "Adult's firstname: ";
        std::cin >> fname;
        std::cout << "Adult's lastname: ";
        std::cin >> name;
    }
	fout << firstname + " " + lastname << " " << ans << " " << calcDurata() << " ";
    if (age < 16)
        fout << age << " " << name << " " << fname;

    std::ofstream fout1("unu.txt");
    fout1 << firstname;
    fout1.close();
    fout.close();
}




template class user<int>;
template class user<double>;
template
std::ostream &operator<< <>(std::ostream &out, const user<int> &u);
template
std::ostream &operator<< <>(std::ostream &out, const user<double> &u);
template
std::istream &operator>> <>(std::istream &in, user<int> &u);
template
std::istream &operator>> <>(std::istream &in, user<double> &u);