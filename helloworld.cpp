
//
// This is example code from Chapter 6.6 "Trying the first version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

const char number = '8'; // we use '8' to represent a number

const char quit = 'x'; // for "quit"

const char print = '='; // for "print"

const string prompt = "> ";
const string result = "= ";

//------------------------------------------------------------------------------

class Token
{
public:
    char kind;     // what kind of token
    double value;  // for numbers: a value
    Token(char ch) // make a Token from a char
        : kind(ch), value(0)
    {
    }
    Token(char ch, double val) // make a Token from a char and a double
        : kind(ch), value(val)
    {
    }
};

//------------------------------------------------------------------------------

class Token_stream
{
public:
    Token get();           // get a Token
    void putback(Token t); // put a Token back
    void ignore(char c);    //discards characters up to and including "c"
private:
    bool full{false};     // is there a Token in the buffer?
    Token buffer = {'0'}; // where we store a 'putback' Token
};

//------------------------------------------------------------------------------

void Token_stream::putback(Token t)
{
    if (full)
        error("putback() into a full buffer");
    buffer = t;  // copy t to buffer
    full = true; // buffer is now full
}

//------------------------------------------------------------------------------

void Token_stream::ignore(char c) 
{
    if (full && c==buffer.kind) {
        full = false;
        return;
    }
    full = false;

    char ch = 0;
    while (cin>>ch) 
        if (ch==c) return;
}

//------------------------------------------------------------------------------

Token Token_stream::get()
//reading characters from cin and drawing up a Token
{
    if (full)     //checking if a Token is in the buffer
    {
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;      //note that operator >> skips whitespace

    switch (ch)
    {
    case print: // for "print"
    case quit:  // for "exit"
    case '(':
    case '{':
    case ')':
    case '}':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '!':
        return Token{ch}; // let each character represent itself
    case '.':   // floating point number can start with a point
    // numeric literal:
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
        cin.putback(ch);    // returning a digit to the input stream
        double val;
        cin >> val;     // reading a double
        return Token{number, val};
    }
    default:
        error("Bad Token");
    }
    return 0; //For compiler
}

//------------------------------------------------------------------------------

Token_stream ts; // provides get(), putback() and ignore()

//------------------------------------------------------------------------------

double expression(); // read and evaluate a Expression

//------------------------------------------------------------------------------

double term(); // read and evaluate a Term

//------------------------------------------------------------------------------

double secondary();  // read and evaluate a Factorial

//------------------------------------------------------------------------------

double primary(); // read and evaluate a Primary

//------------------------------------------------------------------------------

void clean_up_mess()
{
    ts.ignore(print);
}

//------------------------------------------------------------------------------

void calculate()    //expression evaluation loop
{
    while (cin)
    try {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print)
            t = ts.get();   //removing output
        if (t.kind == quit)
            break;
        ts.putback(t);
        cout << result << expression() << "\n";
    }
    catch (exception& e) {
        cerr << e.what() << '\n';
        clean_up_mess();
    }
}

int main()
try
{
    cout << "Welcome to the calculator! \nPlease, input expressions with real numbers, brackets and math operations +-*/%!\n";
    cout << "= - for result, x - for exit\n";
    calculate();
    return 0;
}
catch (exception &e)
{
    cerr << e.what() << endl;
    keep_window_open("~~");
    return 1;
}
catch (...)
{
    cerr << "exception \n";
    keep_window_open("~~");
    return 2;
}

//------------------------------------------------------------------------------

double expression()
{
    double left = term(); // read and evaluate a Term
    Token t = ts.get();   // get the next token
    while (true)
    {
        switch (t.kind)
        {
        case '+':
            left += term(); // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term(); // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left; // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

double term()
{
    double left = secondary();
    Token t = ts.get(); // get the next token

    while (true)
    {
        switch (t.kind)
        {
        case '*':
            left *= secondary();
            t = ts.get();
            break;
        case '/':
        {
            double d = secondary();
            if (d == 0)
                error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            double d = secondary();
            if (d == 0)
                error("divide by zero");
            left = fmod(left, d);
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
    Token t = ts.get(); // get the next token

    while (true)
    {
        switch (t.kind)
        {
        case '!':
        {
            if (left != round(left))
                error("integer expected for factorial");
            if (!left)
                return 1;
            int leftInt = (int)left;
            for (int i = leftInt - 1; i > 1; i--)
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

double primary() // read and evaluate a Primary
{
    Token t = ts.get();
    switch (t.kind)
    {
    case '(':  // handle '(' expression ')'
    case '{': // handle '{' expression '}'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')' && t.kind != '}')
            error("')' or '}' expected");
        return d;
    }
    case number:
        return t.value; // return the number's value
    case '-':
        return -primary();
    case '+':
        return primary();
    default:
        error("primary expected");
    }
    return 0; //For compiler
}

//------------------------------------------------------------------------------