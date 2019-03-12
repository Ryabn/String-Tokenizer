#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <ostream>
using namespace std;

class Token{
    public:
        Token();
        Token(string str, int type);
        friend ostream& operator << (ostream& outs, const Token& t){
            cout << "|" << t._token << "|";
            return outs;
        }
        int type();
        string type_string();
        string token_str();
    private:
        string _token;
        int _type;
};

#endif /* TOKEN_H */