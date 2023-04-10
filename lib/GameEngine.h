
#ifndef GAMEENGINE_H
#define GAMEENGINE_H


#include "mbed.h"
#include "N5110.h"
#include "Ladder.h"
#include "Floor.h"
#include "Utils.h"
#include "Player.h"

class GameEngine {
    public:
        GameEngine();  // pass in the lcd object from the main file
        void player_init(int player_x,int player_y,SKIN player_skin,PLAYER_DIRECTION player_direction);
        void floors_init(int floor1_x, int floor1_y, int floor1_width, int floor2_x, int floor2_y, int floor2_width, int floor3_x, int floor3_y, int floor3_width);
        void ladders_init(int ladder1_x,int ladder1_y, int ladder2_x,int ladder2_y, int ladder3_x,int ladder3_y);
        void update(UserInput input);
        void draw(N5110 &lcd);
        void movement();
        bool check_ceiling_collision();
        bool check_floor_collision();
        bool check_ladder();
    private:
        Floor _floor1;
        Floor _floor2;
        Floor _floor3;
        Player _player;
        Ladder _ladder1;
        Ladder _ladder2;
        Ladder _ladder3;

};


#endif

