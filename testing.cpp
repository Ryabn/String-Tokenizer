#include <iomanip>
#include "string_tokenizer.h"

void test_strings();
void test_string_tokenizer(char s[]);
void test_token();

void test_strings(){
    char s[] = "it was the night of october 17th. pi was still 3.14.";
    test_string_tokenizer(s);
}
void test_string_tokenizer(char *s){
    STokenizer stk(s);
    while(!stk.is_done()){
        Token t;
        stk >> t;   
        cout << setw(10) << t.type_string() << setw(10) << t << endl;
    }
}
void test_token(){
    Token t;
    t = Token(" ", 0);
    cout << setw(10) << t.type_string() << setw(10) << t << endl;
    t = Token("string", 1);
    cout << setw(10) << t.type_string() << setw(10) << t << endl;
    t = Token("2534", 2);
    cout << setw(10) << t.type_string() << setw(10) << t << endl;
    t = Token(".", -1);
    cout << setw(10) << t.type_string() << setw(10) << t << endl;
}