#include <iostream>
#include <cstring>
#include "string_tokenizer.h"

using namespace std;

int STokenizer::_table[MAX_ROWS][MAX_COLUMNS];

STokenizer::STokenizer(){
    make_table(&_table[0]);
    _pos = 0;
}
STokenizer::STokenizer(char str[]){
    make_table(&_table[0]);
    set_string(str);
}
void STokenizer::set_string(char str[]){
    _pos = 0;
    memcpy(_buffer, str, sizeof(_buffer));
}
bool STokenizer::is_done(){
    return _pos > strlen(_buffer);
}
void STokenizer::get_token(int start_state, Token& t){
    string token_value;
    int cur_state = start_state,
        state_level = 0,
        token_type = -1;
    while( !(cur_state > strlen(_buffer)) && state_level != -1 ){
        switch(state_level){
            case 1:
            case 3:
                token_type = 2; // is num type
                break;
            case 5:
                token_type = 1; // is alpha type
                break;
            case 9:
                token_type = 0; // is string type
                break;
            default:
                break;
        }
        state_level = _table[state_level][(int)_buffer[cur_state]];
        cur_state += 1;
    }
    cur_state += cur_state == start_state + 1 ? 1 : -1; // move on if invalid token
    token_value = string(&_buffer[start_state], &_buffer[cur_state]);
    _pos = cur_state;                   // move position
    t = Token(token_value, token_type); // sets token
}
void STokenizer::make_table(int _table[][MAX_COLUMNS]){
    //set all values to fail states
    for(int i = 0 ; i < MAX_ROWS; i++){
        fill_n(_table[i], MAX_COLUMNS, -1);
    }
    //spaces
    _table[0][32] = 9;  //init
    _table[9][0] = 1;   //success state
    _table[9][32] = 9; 

    //alpha
    _table[5][0] = 1;   //success state
    fill_n(&_table[0][65], 26, 5);
    fill_n(&_table[0][97], 26, 5);
    fill_n(&_table[5][65], 26, 5);
    fill_n(&_table[5][97], 26, 5);

    // //numbers
    _table[1][0] = 1;   //success state
    _table[2][0] = 0;   //not yet success
    _table[3][0] = 1;   //success
    fill_n(&_table[0][48], 10, 1);
    fill_n(&_table[1][48], 10, 1);
    fill_n(&_table[2][48], 10, 3);
    fill_n(&_table[3][48], 10, 3);
    _table[1][46] = 3;

}
STokenizer& operator >> (STokenizer& s, Token& t){
    s.get_token(s._pos, t);
    return s;
}
