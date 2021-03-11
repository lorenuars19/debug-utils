`curl https://raw.githubusercontent.com/lorenuars19/debug-utils/main/debug_utils.h -o debug_utils.h`
# Debug-Utils
Header file containing useful debug macros I use all the time

# Macros
- `BR` : BreakPoint : will pause the execution using libc `getchar()` so you can just press enter in the terminal to continue your program, you can `-D BREAK_PAUSE=0` so it does not pause your program
- `BR_(var)` : Will try to detect variable type, and print it accordingly, using `_Generic()`
- `D_STR_DETAILS(str)` : Prints a string in details, printing control chars by their numeric value in the ascii table.

# Contributing
Feel free to make a pull request to add your own macros
