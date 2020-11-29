
//
// This is example code from Chapter 6.6 "Trying the first version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token get();            // get a Token
    void putback(Token t);  // put a Token back
private:
    bool full{ false };      // is there a Token in the buffer?
    Token buffer = { '0' };           // where we store a 'putback' Token
};

//------------------------------------------------------------------------------

void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;         // copy t to buffer
    full = true;        // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;

    switch (ch) {
    case '=':       // for "print"
    case 'x':       // for "quit"
    case '(':
    case '{':
    case ')':
    case '}':
    case '+':
    case '-':
    case '*':
    case '/':
    case '!':
        return Token{ ch };   // let each character represent itself
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {
        cin.putback(ch);
        double val;
        cin >> val;
        return Token{ '8', val };
    }
    default:
        error("Bad Token");
    }
    return 0; //For compiler
}

//------------------------------------------------------------------------------

Token_stream ts;      // provides get() and putback()

//------------------------------------------------------------------------------

double expression();  // read and evaluate a Expression

//------------------------------------------------------------------------------

double term();        // read and evaluate a Term

//------------------------------------------------------------------------------

double primary();     // read and evaluate a Primary

//------------------------------------------------------------------------------

double secondary();

//------------------------------------------------------------------------------

int main()
try {
    cout << "Welcome to the calculator! \nPlease, input expressions with real numbers, brackets and math operations +-*/!\n";
    cout << "= - for result, x - for exit\n";
    double val = 0;
    bool b = false;
    while (cin) {
        Token t = ts.get();
        if (t.kind == 'x') break;
        if (t.kind == '=') {if (!b) cout << "= " << val << '\n'; b = true; continue;}
        else {ts.putback(t); b = false;}
        val = expression();
    }
    //keep_window_open();
}
catch (exception& e) {
    cerr << e.what() << endl;
    keep_window_open("~1");
    return 1;
}
catch (...) {
    cerr << "exception \n";
    keep_window_open("~2");
    return 2;
}

//------------------------------------------------------------------------------

double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token
    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

double term()
{
    double left = secondary();
    Token t = ts.get();     // get the next token

    while (true) {
        switch (t.kind) {
        case '*':
            left *= secondary();
            t = ts.get();
            break;
        case '/':
        {
            double d = secondary();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;
        }
    }
}

//------------------------------------------------------------------------------

double secondary()
{
    double left = primary();
    Token t = ts.get();     // get the next token

    while (true) {
        switch (t.kind) {
        case '!':
        {
            if (left != round(left)) error("integer expected for factorial");
            if (!left) return 1;
            int leftInt = (int)left;
            for (int i = leftInt-1; i > 1; i--)
                leftInt *= i;
            left = leftInt;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;
        }
    }
}

//------------------------------------------------------------------------------

double primary()     // read and evaluate a Primary
{
    Token t = ts.get();
    switch (t.kind) {
    case '(': case '{':    // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')' && t.kind != '}') error("')' or '}' expected");
        return d;
    }
    case '8':            // we use '8' to represent a number
        return t.value;  // return the number's value
    default:
        error("primary expected");
    }
    return 0; //For compiler
}

//------------------------------------------------------------------------------