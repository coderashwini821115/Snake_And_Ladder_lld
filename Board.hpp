#include<bits/stdc++.h>
#include "Dice.hpp"
#include "Ladder.hpp"
#include "Player.hpp"
#include "Snakes.hpp"

using namespace std;
#ifndef BOARD_HPP
#define BOARD_HPP
class Board
 {
    int size;
    Dice dice;
    queue<Player> next_turn;
    map<int , int> snakes;
    map<int , int> ladder;

    public:
    Board(int sz, queue<Player> nxt, map<int, int> snk, map<int, int> ladd, Dice di ) {
        size = sz;
        next_turn = nxt;
        snakes = snk;
        ladder = ladd;
        dice = di;
    }
    void start() {
        while (next_turn.size() > 1)
        {
            Player player = next_turn.front();
            // cout << player.get_name() << " " <<player.getPosition() << endl;
            next_turn.pop();
            int prev_pos = player.getPosition();
            int roll = dice.rollDice();
            int new_pos = roll+prev_pos;
            cout << player.get_name() << " rolled a " << roll << endl;
            
            int curr_pos = new_pos;
            // if(new_pos > size) {
            //     next_turn.push(player);
            //     continue;
            // }
            // else if(new_pos == size) {
                
            //     continue;
            // }
            if(new_pos <= size){
                
                do {
                    new_pos = curr_pos;
                    if(snakes.find(curr_pos) != snakes.end()) {
                        cout << player.get_name() << " bitten by snake at " << curr_pos << endl;
                        curr_pos = snakes[curr_pos];
                    }
                    else if(ladder.find(curr_pos) != ladder.end()) {
                    cout << player.get_name() << " takes the ladder at " << curr_pos << endl;
                    curr_pos = ladder[curr_pos];
                    }
                } while(curr_pos != new_pos);
            }
            if(new_pos > size) new_pos = prev_pos;
            cout << player.get_name() << " is at " << new_pos << endl;
            int mov = player.get_moves();
            player.setmove(++mov);
            if(new_pos == size) {
                cout << player.get_name() << " won the match in " << player.get_moves() << endl;
                continue;
            }
            // if(new_pos < size)
            player.setPosition(new_pos);
            next_turn.push(player);
        }
        
    }
};
#endif