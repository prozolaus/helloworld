
//
// This is example code from Chapter 6.6 "Trying the first version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"
#include "roman_int.h"

//------------------------------------------------------------------------------

const char number = '8'; // we use '8' to represent a number

const char quit = 'q';          // for "quit"
const string quit_str = "exit"; // for "quit"

const char help = 'h';          // for "instructions"
const string help_str = "help"; // for "instructions"

const char print = ';'; // for "print"

const string prompt = "> ";
const string result = "= ";

const char name = 'a';
const char let = 'L';
const string deckley = "let"; //keyword "let"
const char const_kind = 'C';
const string const_key = "const"; //keyword "const"
const char sqrt_kind = 'S';
const string sqrt_key = "sqrt";
const char pow_kind = 'P';
const string pow_key = "pow";

//------------------------------------------------------------------------------

void instructions()
{
    cout << "Welcome to the calculator! \nPlease, input expressions with real numbers, brackets and math operations +-*/%!\n";
    cout << "The symbol \'" << print << "\' is for result printing and \'" << quit << "\' - for exit\n";
}

//------------------------------------------------------------------------------

class Token
{
public:
    char kind;    // what kind of token
    double value; // for numbers: a value
    string name;
    Token(char ch) // make a Token from a char
        : kind(ch), value(0)
    {
    }
    Token(char ch, double val) // make a Token from a char and a double
        : kind(ch), value(val)
    {
    }
    Token(char ch, string n) // make a Token from a char and a string
        : kind(ch), name(n)
    {
    }
};

//------------------------------------------------------------------------------

class Token_stream
{
public:
    Token_stream();          // make a Token_stream that reads from cin
    Token_stream(istream &); // Token_stream that reads from an istream
    Token get();             // get a Token
    void putback(Token t);   // put a Token back
    void ignore(char c);     //discards characters up to and including "c"
private:
    bool full;    // is there a Token in the buffer?
    Token buffer; // where we store a 'putback' Token
};

//------------------------------------------------------------------------------

// constructor
Token_stream::Token_stream()
    : full(false), buffer(0) {} // no Token in buffer

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
//the "c" character provides a variety of tokens
{
    //first check the buffer
    if (full && c == buffer.kind)
    {
        full = false;
        return;
    }
    full = false;

    //now we check the input
    char ch = 0;
    while (cin >> ch)
        if (ch == c)
            return;
}

//------------------------------------------------------------------------------

Token Token_stream::get()
//reading characters from cin and drawing up a Token
{
    if (full) //checking if a Token is in the buffer
    {
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch; //note that operator >> skips whitespace

    switch (ch)
    {
    case print: // for "print"
    case quit:  // for "exit"
    case '=':
    case '(':
    case '{':
    case ')':
    case '}':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case ',':
    case '!':
        return Token{ch}; // let each character represent itself
    case '.':             // floating point number can start with a point
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
        cin.putback(ch); // returning a digit to the input stream
        double val;
        cin >> val; // reading a double
        return Token{number, val};
    }
    case 'I':
    case 'V':
    case 'X':
    case 'L':
    case 'C':
    case 'D':
    case 'M':
    {
        string s;
        s += ch;
        while (cin.get(ch) && isalpha(ch))
            s += ch;
        cin.putback(ch);
        Roman_int rmn{s};
        double d = (double)rmn.as_int();
        return Token{number, d};
    }
    case '#':
        return Token{let}; //keyword "let"
    default:
        if (isalpha(ch))
        {
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
                s += ch;
            cin.putback(ch);
            if (s == deckley)
                return Token{let}; //keyword "let"
            if (s == const_key)
                return Token{const_kind}; //keyword "let"
            if (s == sqrt_key)
                return Token{sqrt_kind, s};
            if (s == pow_key)
                return Token{pow_kind, s};
            if (s == quit_str)
                return Token{quit, s}; //for "exit"
            if (s == help_str)
                return Token{help, s}; //for "printing instructions"
            return Token{name, s};
        }
        error("Bad Token");
    }
    return 0; //For compiler
}

//------------------------------------------------------------------------------

Token_stream ts; // provides get(), putback() and ignore()

//------------------------------------------------------------------------------

double expression(Token_stream &); // read and evaluate a Expression

//------------------------------------------------------------------------------

double term(Token_stream &); // read and evaluate a Term

//------------------------------------------------------------------------------

double secondary(Token_stream &); // read and evaluate a Factorial

//------------------------------------------------------------------------------

double primary(Token_stream &); // read and evaluate a Primary

//------------------------------------------------------------------------------

void clean_up_mess()
{
    ts.ignore(print);
}

//------------------------------------------------------------------------------

class Variable
{
public:
    string name;
    double value;
    bool con;                                //true - for const, false - for variable
    Variable(string var, double val, bool c) // make a Variable from a string, a double and a bool (for const)
        : name(var), value(val), con(c)
    {
    }
};

class Symbol_table
{
public:
    vector<Variable> var_table; // it stores values of variables and constants
    double get(string s);
    void set(string s, double d);
    bool is_declared(string var);
    double define_name(string var, double val, bool c);
};

Symbol_table st;

double Symbol_table::get(string s)
//returns the value of a variable named "s"
{
    for (const Variable &v : var_table)
        if (v.name == s)
            return v.value;
    error("get: undefined variable ", s);
    return 0;
}

void Symbol_table::set(string s, double d)
// assigns a value 'd' to an 's' object of type Variable
{
    for (Variable &v : var_table)
        if (v.name == s)
        {
            if (v.con)
                error("set: constant cannot be changed");
            v.value = d;
            return;
        }
    error("set: undefined variable ", s);
}

//-------------------------------------------------------------------------------

bool Symbol_table::is_declared(string var)
//Is there a variable 'var' in the var_table vector?
{
    for (const Variable &v : var_table)
        if (v.name == var)
            return true;
    return false;
}

double Symbol_table::define_name(string var, double val, bool c)
// add a triple (var, val, c) to the vector var_table
{
    if (is_declared(var))
        set(var, val);
    //error(var, " re-declaring a variable");
    else
        var_table.push_back(Variable(var, val, c));
    return val;
}

double declaration(bool c)
{
    Token t = ts.get();
    if (t.kind != name)
        error("variable name is expected in the declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=')
        error("the = symbol is missing in the declaration ", var_name);
    double d = expression(ts);
    st.define_name(var_name, d, c);
    return d;
}

double statement()
{
    Token t = ts.get();
    switch (t.kind)
    {
    case let:
        return declaration(false); // false is a variable
    case const_kind:
        return declaration(true); // true is a constant
    default:
        ts.putback(t);
        return expression(ts);
    }
}

//------------------------------------------------------------------------------

void calculate() //statement evaluation loop
{
    while (cin)
        try
        {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print)
                t = ts.get(); //removing output
            if (t.kind == help)
                instructions();
            else
            {
                if (t.kind == quit)
                    return;
                ts.putback(t);
                cout << result << statement() << "\n";
            }
        }
        catch (exception &e)
        {
            cerr << e.what() << '\n'; //error message output
            clean_up_mess();
        }
}

int main()
try
{
    //Predefined names
    st.define_name("pi", 3.1415926535, true);
    st.define_name("e", 2.7182818284, true);
    st.define_name("k", 1000, true);
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

double expression(Token_stream &ts)
{
    double left = term(ts); // read and evaluate a Term
    Token t = ts.get();     // get the next token
    while (true)
    {
        switch (t.kind)
        {
        case '+':
            left += term(ts); // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term(ts); // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left; // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

double term(Token_stream &ts)
{
    double left = secondary(ts);
    Token t = ts.get(); // get the next token

    while (true)
    {
        switch (t.kind)
        {
        case '*':
            left *= secondary(ts);
            t = ts.get();
            break;
        case '/':
        {
            double d = secondary(ts);
            if (d == 0)
                error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            double d = secondary(ts);
            if (d == 0)
                error("divide by zero");
            left = fmod(left, d);
            t = ts.get();
            break;
        }
        case ',':
        {
            int i = narrow_cast_pow<int>(secondary(ts));
            left = pow(left, i);
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

double secondary(Token_stream &ts)
{
    double left = primary(ts);
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

double primary(Token_stream &ts) // read and evaluate a Primary
{
    Token t = ts.get();
    switch (t.kind)
    {
    case '(': // handle '(' expression ')'
    case '{': // handle '{' expression '}'
    {
        double d = expression(ts);
        t = ts.get();
        if (t.kind != ')' && t.kind != '}')
            error("')' or '}' expected");
        return d;
    }
    case number:
        return t.value; // return the number's value
    case '-':
        return -primary(ts);
    case '+':
    case pow_kind:
        return primary(ts);
    case name:
        return st.get(t.name); // return a variable's or constant's value
    case sqrt_kind:
    {
        double d = primary(ts);
        if (d < 0)
            error("cannot take the square root of a negative number.");
        return sqrt(d); //returns the expression's square root
    }
    default:
        error("primary expected");
    }
    return 0; //For compiler
}

//------------------------------------------------------------------------------
