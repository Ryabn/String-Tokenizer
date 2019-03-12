#ifndef STRING_TOKENIZER_H
#define STRING_TOKENIZER_H
#include "token.h"

const int MAX_COLUMNS = 128;
const int MAX_ROWS = 16;
const int MAX_BUFFER = 512;

class STokenizer{
    public:
        STokenizer();
        STokenizer(char str[]);
        bool is_done();
        friend STokenizer& operator >> (STokenizer& s, Token& t);
        void set_string(char str[]);
    private:
        void make_table(int _table[][MAX_COLUMNS]);
        void get_token(int start_state, Token& token);
        char _buffer[MAX_BUFFER];       //input string
        int _pos;                       //current position in the string
        static int _table[MAX_ROWS][MAX_COLUMNS];
};
#endif /* STRING_TOKENIZER_H */