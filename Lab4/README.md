# Semantics

- Accurate error messages

## Type checking and type warnings

- truncating a real to an integer will throw a warning
- arithmetic with real and integer returns a real

## Functions

- Proper function return checkinFunctions
- Proper function return checking

## stack 
- make sure that already in scope variables don't get declared twice. (may be hard)
- 




# how it works

the parser only knows the symbol based on an int which corresponds to it from the string table, from the int we can get from the string table. The lexer reads the identifiers and saves them to the string table, the parser, when declaring identifiers adds them to the symbol table from their index. 
