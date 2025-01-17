#include "Player.h"
DigitalIn jump(PC_10);


Player::Player() { }


void Player::init(int x, int y, SKIN Player_Skin, PLAYER_DIRECTION Player_Direction) {
    printf("Player: Init\n");
    //initialise all player conditions
    _jumping = 0; //not jumping or falling. Stationary. Height=0
    _falling = 0;
    _stationary = 1;
    _height = 0;
    _x = x;
    _y = y;
    _Player_Direction = Player_Direction;
    _Player_Skin = Player_Skin;
}


void Player::draw(N5110 &lcd) {
    //printf("Player: Draw\n");
    if(_Player_Skin == RIGHT1){
        lcd.drawSprite(_x,_y,16,10,(int *)Right1);      
    }
    else if(_Player_Skin == LEFT1){
        lcd.drawSprite(_x,_y,16,10,(int *)Left1);      
    }
    else if(_Player_Skin == RIGHT2){
        lcd.drawSprite(_x,_y,16,17,(int *)Right2);      
    }
    else if(_Player_Skin == LEFT2){
        lcd.drawSprite(_x,_y,16,17,(int *)Left2);      
    }


}


void Player::update(UserInput input) { //updates DIRECTION and JUMPING (if not already jumping) based on user inputs (joystick and buttons)
  
    if (input.d == E||input.d == NE||input.d == SE){ //if joystick on RHS, direction = right
        _Player_Direction = RIGHT;
        _stationary = 0; //player is not stationary

        }
    else if (input.d == W||input.d == NW||input.d == SW){ //if joystick on LHS, direction =left
            _Player_Direction = LEFT;
            _stationary = 0; //player not stationary
            }
    else if (input.d == CENTRE||input.d == N||input.d == S){//if joystick up, down or centre
            _stationary = 1; //player is stationary
            }

    if(_jumping == 0){ //if not already jumping
        _jumping = jump.read(); //jumping if switch is pressed
    }

}

//accessors
Position2D Player::get_pos() { return {_x,_y}; }
int Player::get_x(){return _x;}
int Player::get_y(){return _y;}
int Player::get_height(){return _height;}
bool Player::get_jumping(){return _jumping;}
bool Player::get_falling(){return _falling;}
bool Player::get_stationary(){return _stationary;}
SKIN Player::get_skin(){return _Player_Skin;}
PLAYER_DIRECTION Player::get_direction(){return _Player_Direction;}

//mutators
    void Player::set_x(int x){_x=x;}
    void Player::set_y(int y){_y=y;}
    void Player::set_height(int h){_height=h;}
    void Player::set_jumping(bool jumping){_jumping=jumping;}
    void Player::set_falling(bool falling){_falling=falling;}
    void Player::set_skin(SKIN skin){_Player_Skin=skin;};


