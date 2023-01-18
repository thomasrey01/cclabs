# Checks:

- Checks if a declaration exists first in local scope (shadowing) then in global
- Checks if lhs of assignment is defined
- Checks if lhs of statement is not a constant
- checks if real numbers aren't used in integer operations (for example mod and div)
- Assigns proper type to variables (ex: division always returns real, any legal operation with real and integer returns a real)
- Checks if the right number of arguments are given in a function/procedure call
- Checks if functions/procedures are called with legal argument types (ex: using an int as a real argument simply means that the int will get casted to a real and thus will be accepted but not the other way around)
- Checks that a function doesn't get called as a procedure (functions always have to return a value in this case)
- Makes sure that functions called as arguments map to the right variable type
