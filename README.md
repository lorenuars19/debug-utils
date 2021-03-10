# Debug-Utils
Header file containing useful debug macros I use all the time

# Macros
- `BR` : BreakPoint : will pause the execution using libc `getchar()` so you can just press enter in the terminal to continue your program, you can `-D BREAK_PAUSE=0` so it does not pause your program

- `D_INT(var)` : (int) Print you variable and its value
- `D_LINT(var)` : (long) Print you variable and its value
- `D_STR(var)` : (String) Print you variable and its value
- `D_PTR(var)` : (Pointer) Print you variable and its value

- `D_STR_DETAILS(str)` : Prints a string in details, printing control chars by their numeric value in the ascii table.
