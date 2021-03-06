//era un const neinit in constr/ solutie il face ne const/ il initializezi in lista de constr

#include <iostream>
#include <fstream>
#include "festival.h"
#include "concert_artist.h"
#include "user.h"

void postp(int nr){
    auto f = festival::get_festival();
    f->Postpone_f(nr);
}

int main(){
    try {
        user<int> u;
        user<double> u1;
        std::cin >> u1;
        u1.calcDurata();
        auto f = festival::get_festival();
        std::ifstream fin("festival.txt");
        concert_artist c("alic", 24, "noname", false, 16, true);
        c.setPret(175);
        fin >> *f;
        f->read();
        postp(1);
        f->restart_f(1);
        f->AddSong(2, "lights out!");
        std::cin >> u;
        u.calcDurata();
        u.Quest();
        f->draw();
        festival::QuestA();
    }
    catch (const std::invalid_argument &err){
        std::cout << err.what();
    }

    return 0;
}