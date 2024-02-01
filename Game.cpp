#include<bits/stdc++.h>
#include "Dice.hpp"
#include "Ladder.hpp"
#include "Player.hpp"
#include "Snakes.hpp"
#include "Board.hpp"

using namespace std;

int main() {
    int size, dc;
    cout << "Enter no. of dice and size of board " <<endl;
    cin >> dc >> size;
    Dice dice(dc);
    // cout << dice.val() << endl;
    queue<Player> next_turn;
    map<int , int> snakes;
    map<int , int> ladder;
    snakes[17] = 7;
    snakes[54] = 34;
    ladder[62] = 81;
    ladder[87] = 96;
    int np = 0;
    cout << "Enter no. of player " << endl;
    cin >> np;
    for(int i=0; i<np; i++) {
        cout << "enter the name of player " << i+1 << endl;
       string name; cin >> name;
       Player p(name, 0);
       next_turn.push(p);
    }
    Board b(size, next_turn, snakes, ladder, dice);
    b.start();

    return 0;
}
