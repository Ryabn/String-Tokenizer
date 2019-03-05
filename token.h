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