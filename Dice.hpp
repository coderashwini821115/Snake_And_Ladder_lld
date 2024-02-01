#include<bits/stdc++.h>
using namespace std;
#ifndef DICE_HPP
#define DICE_HPP
class Dice {
    int noOfDice;
    public:
    Dice(int noOfDice=1) {
        this->noOfDice = noOfDice;
    }
    int rollDice() {
        return (rand()%(6*noOfDice+1-noOfDice)) + noOfDice;
    }
    int val() {
        return noOfDice;
    }
};
#endif