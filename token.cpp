#include "token.h"

Token::Token(){
    _token = "";
    _type = -1;
}
Token::Token(string str, int type){
    _token = str;
    _type = type;
}
int Token::type(){
    return _type;
}
string Token::type_string(){
    switch(_type){
        case 0:
            return "SPACE";
        case 1:
            return "ALPHA";
        case 2:
            return "NUMBER";
        default:
            return "UNKNOWN";
    }
}
string Token::token_str(){
    return _token;
}
