#include <iomanip>
#include "string_tokenizer.h"


void test_string_tokenizer(){

    char s[] = "it was the night of october 17th. pi was still 3.14.";
    STokenizer stk(s);
    Token t;
    stk >> t;
    // while(!stk.has_failed()){
        cout << setw(10) << t.type_string() << setw(10) << t << endl;
        // t = Token();
        // stk >> t;
    // }
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