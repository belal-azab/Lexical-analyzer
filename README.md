# Lexical Analyzer

A simple **Lexical Analyzer** (lexer) that reads a source code file, tokenizes it into identifiers, integers, operators, and parentheses, and outputs the token types along with their lexemes. This project forms the foundation for building compilers or interpreters.

## Features

- **Tokenization**: Identifies and generates tokens for:
  - Identifiers (e.g., variable names)
  - Integer literals (e.g., numbers)
  - Operators (e.g., `+`, `=`, etc.)
  - Parentheses (e.g., `(`, `)`)
  
- **Character Classification**: Differentiates between letters, digits, and unknown symbols.
  
- **Lexeme Processing**: Outputs both the token type and lexeme for each identified token.

## How It Works

1. **Input**: The program reads an input source code file (`front.in`).
2. **Tokenization**: Each character is processed, classified, and tokens are generated.
3. **Output**: The program outputs the token types and their corresponding lexemes.

## Usage

1. Ensure the source code file (`front.in`) is in the same directory.
2. Compile and run the program.
3. View the output tokens and lexemes printed to the console.

## Example

For an input like:

```cpp
int x = 5 + 3;
