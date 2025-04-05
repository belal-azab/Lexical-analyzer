# Lexical Analyzer in C++

This is a simple *Lexical Analyzer* implemented in *C++*. The program reads an input file (`front.in`), analyzes the content, and outputs the lexemes along with their corresponding token codes.


## Main Program Workflow

1. The program opens an input file (`front.in`).
2. It reads characters from the file, processes them using `lex()`, and generates tokens.
3. It prints the next token and lexeme each time `lex()` is called.
4. The process ends when the end of the file is reached.

   
## 📋 Features

- Recognizes:
  - Identifiers (e.g., `x`, `total`, `sum1`)
  - Integer literals (e.g., `123`, `42`)
  - Arithmetic operators (`+`, `-`, `*`, `/`)
  - Assignment operator (`=`)
  - Parentheses (`(` and `)`)
- Ignores whitespace
- Outputs a token and its lexeme for each recognized element

- ## Function Breakdown

- **addChar()**: Appends the current `nextChar` to the `lexeme`.
- **getChar()**: Reads the next character from the input file and classifies it (as a letter, digit, unknown character, or end of file).
- **getNonBlank()**: Skips over any whitespace characters in the input.
- **lookup()**: Checks `nextChar` to determine which token to generate for symbols like operators and parentheses.
- **lex()**: Main lexer function, which processes the input and generates tokens. It calls `getChar()` and `lookup()` to determine the next token, then outputs the token and lexeme.

## 🧠 Token Codes

| Token                         | Code |
|-------------------------------|------|
| Integer Literal (INT_LIT)      | 10   |
| Identifier (IDENT)             | 11   |
| Assignment Operator (=)        | 20   |
| Addition Operator (+)          | 21   |
| Subtraction Operator (-)       | 22   |
| Multiplication Operator (*)    | 23   |
| Division Operator (/)          | 24   |
| Left Parenthesis (()           | 25   |
| Right Parenthesis ())          | 26   |
| End of File (EOF)              | -1   |

## 📁 File Structure

- `main.cpp` — The main source code for the lexical analyzer.
- `front.in` — The input file containing source code to be analyzed.

## 🤝 Contributing

Feel free to fork this project and submit a pull request if you'd like to add new features like:
- Support for floating-point numbers
- Multi-character operators (`==`, `!=`, etc.)
- Comments handling
- Error reporting


---

Happy Lexing! 🚀

