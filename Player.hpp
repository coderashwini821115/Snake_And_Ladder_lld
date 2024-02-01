#include<bits/stdc++.h>
using namespace std;

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {
    string name;
    int position;
    int moves = 0;
    public:
    Player(string name, int pos) {
        this->name = name;
        position = pos;
    }
    string get_name() {
        return name;
    }
    int getPosition() {
        return position;
    }
    void setPosition(int x) {
        position = x;
    }
    int get_moves() {
        return moves;
    }
    void setmove(int mov) {
        moves = mov;
    }
};

#endif