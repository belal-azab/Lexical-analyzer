#include <iostream>  
#include <fstream>   
#include <cctype>    
#include <string>    

using namespace std;

// Character classes
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99
#define END_OF_FILE -1

// Token codes
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26

// Global variables
int charClass;
string lexeme;
char nextChar;
int nextToken;
ifstream in_fp;

// Function declarations
void addChar();
void getChar();
void getNonBlank();
int lookup(char ch);
int lex();

// addChar: Appends the current character to the lexeme string
void addChar() {
    lexeme += nextChar;
}

// getChar: Reads the next character from the input file and sets its class
void getChar() {
    if (in_fp.get(nextChar)) {  // If a character is successfully read
        if (isalpha(nextChar))  // If it's a letter
            charClass = LETTER;
        else if (isdigit(nextChar))  // If it's a digit
            charClass = DIGIT;
        else
            charClass = UNKNOWN;  // For any other symbol
    }
    else {
        charClass = END_OF_FILE;  // Mark end of file if no characters left
    }
}

// getNonBlank: Skips over whitespace characters
void getNonBlank() {
    while (isspace(nextChar))
        getChar();
}

// lookup: Processes special characters like operators and parentheses
int lookup(char ch) {
    switch (ch) {
    case '(':
        addChar();
        nextToken = LEFT_PAREN;
        break;
    case ')':
        addChar();
        nextToken = RIGHT_PAREN;
        break;
    case '+':
        addChar();
        nextToken = ADD_OP;
        break;
    case '-':
        addChar();
        nextToken = SUB_OP;
        break;
    case '*':
        addChar();
        nextToken = MULT_OP;
        break;
    case '/':
        addChar();
        nextToken = DIV_OP;
        break;
    case '=':
        addChar();
        nextToken = ASSIGN_OP;
        break;
    default:
        addChar();
        nextToken = END_OF_FILE;
        break;
    }
    return nextToken;  // Return the token type
}

// lex: Main lexer function, determines the next token
int lex() {
    lexeme = "";
    getNonBlank();

    switch (charClass) {
    case LETTER:
        addChar();
        getChar();
        while (charClass == LETTER || charClass == DIGIT) {
            addChar();
            getChar();
        }
        nextToken = IDENT;
        break;

    case DIGIT:
        addChar();
        getChar();
        while (charClass == DIGIT) {
            addChar();
            getChar();
        }
        nextToken = INT_LIT;
        break;

    case UNKNOWN:
        lookup(nextChar);
        getChar();
        break;

    case END_OF_FILE:
        nextToken = END_OF_FILE;
        lexeme = "EOF";
        break;
    }

    // Output for debugging: display the token and lexeme
    cout << "Next token is: " << nextToken << ", Next lexeme is " << lexeme << endl;

    return nextToken;  // Return the token to the caller
}

// main: Program entry point, processes the input file
int main() {
    in_fp.open("front.in");  // Open input file

    if (!in_fp) {  // Error handling for file opening
        cerr << "ERROR - cannot open front.in" << endl;
        return 1;
    }

    getChar();  // Get the first character

    do {
        lex();  // Process the next token
    } while (nextToken != END_OF_FILE);  // Continue until end of file

    in_fp.close();  // Close the input file
    return 0;
}
