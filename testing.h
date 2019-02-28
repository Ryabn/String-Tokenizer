#include <iomanip>
#include "string_tokenizer.h";


void test_string_tokenizer(){
    char s[] = "it was the night of october 17th. pi was still 3.14.";
    STokenizer stk(s);
    Token t;
    stk>>t;
    while(stk.more()){
        cout<<setw(10)<<t.type_string()<<setw(10)<<t<<endl;

        t = Token();
        stk>>t;
    }
}