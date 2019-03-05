#include "token.h"

const int MAX_COLUMNS = 100;
const int MAX_ROWS = 20;
const int MAX_BUFFER = 1024;

class STokenizer{
    public:
        STokenizer();
        STokenizer(char str[]);
        bool is_done();            //true: there are no more tokens
        bool has_failed();
        //-- big three --

        //---------------
        //extract one token (very similar to the way cin >> works)
        friend STokenizer& operator >> (STokenizer& s, Token& t){
            cout << s._buffer;
            t = Token("strings", 1);
            return s;
        }

        //set a new string as the input string
        void set_string(char str[]);

    private:
        //create table for all the tokens we will recognize
        //                      (e.g. doubles, words, etc.)
        void make_table(int _table[][MAX_COLUMNS]);

        //extract the longest string that match
        //     one of the acceptable token types
        bool get_token(int start_state, string& token);
        //---------------------------------
        char _buffer[MAX_BUFFER];       //input string
        int _pos;                       //current position in the string
        static int _table[MAX_ROWS][MAX_COLUMNS];
};
STokenizer::STokenizer(){
    // _pos = 0;
    cout << "standard tokeenizer constructor called";
}
STokenizer::STokenizer(char str[]){
    // _pos = 0;
    set_string(str);
}
// void STokenizer::set_string(char str[]){
//     _buffer = str;
// }
void STokenizer::set_string(char str[]){
    // strncpy(_buffer, str);
    memcpy(_buffer, str, sizeof(_buffer));
}
bool STokenizer::has_failed(){
    return _pos <= strlen(_buffer);
}
bool STokenizer::get_token(int start_state, string& token){

}