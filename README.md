# Lexical Analyzer for Simple Programming Language

This code implements a **lexical analyzer** (lexer or scanner) for a simple programming language. The lexical analyzer reads a stream of characters from an input file and breaks it into a series of tokens, each representing a meaningful unit in the source code (such as keywords, identifiers, operators, literals, etc.).

## Features

- **Tokenization**: The lexer generates tokens for:
  - Identifiers (e.g., variable names)
  - Integer literals (e.g., `123`)
  - Operators (e.g., `+`, `=`, etc.)
  - Parentheses (e.g., `(`, `)`)
  
- **Character Classification**: Differentiates between letters, digits, and unknown symbols.

- **Lexeme Processing**: Outputs both the token type and lexeme for each identified token.

## Character Classes and Token Codes

- **Character Classes:**
  - `LETTER (0)`: Alphabetic characters (used for identifiers).
  - `DIGIT (1)`: Numeric characters (used for integer literals).
  - `UNKNOWN (99)`: Unrecognized characters (e.g., operators or symbols).
  - `END_OF_FILE (-1)`: Marks the end of input.

- **Token Codes:**
  - `INT_LIT (10)`: Integer literal (e.g., `123`).
  - `IDENT (11)`: Identifier (e.g., variable names).
  - `ASSIGN_OP (20)`: Assignment operator (`=`).
  - `ADD_OP (21)`: Addition operator (`+`).
  - `SUB_OP (22)`: Subtraction operator (`-`).
  - `MULT_OP (23)`: Multiplication operator (`*`).
  - `DIV_OP (24)`: Division operator (`/`).
  - `LEFT_PAREN (25)`: Left parenthesis (`(`).
  - `RIGHT_PAREN (26)`: Right parenthesis (`)`).

## Function Breakdown

- **addChar()**: Appends the current `nextChar` to the `lexeme`.
- **getChar()**: Reads the next character from the input file and classifies it (as a letter, digit, unknown character, or end of file).
- **getNonBlank()**: Skips over any whitespace characters in the input.
- **lookup()**: Checks `nextChar` to determine which token to generate for symbols like operators and parentheses.
- **lex()**: Main lexer function, which processes the input and generates tokens. It calls `getChar()` and `lookup()` to determine the next token, then outputs the token and lexeme.

## Main Program Workflow

1. The program opens an input file (`front.in`).
2. It reads characters from the file, processes them using `lex()`, and generates tokens.
3. It prints the next token and lexeme each time `lex()` is called.
4. The process ends when the end of the file is reached.

## Example

For an input like:

```cpp
sum = 25 + 30 / (10 - 5)
