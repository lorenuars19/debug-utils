`curl https://raw.githubusercontent.com/lorenuars19/debug-utils/main/debug_utils.h -o debug_utils.h`
# Debug-Utils
Header file containing useful debug macros I use all the time

# Macros
Automatic Macros
- `BR` : BreakPoint : will pause the execution using libc `getchar()` so you can just press enter in the terminal to continue your program, you can `-D BREAK_PAUSE=0` so it does not pause your program
- `DE(var)` : Will try to detect variable type, and print it accordingly, using `_Generic()`

Static typed (in case `_Generic()` fails)
- `D_INT(var)` : (int) Print variable and its value
- `D_LINT(var)` : (long) Print variable and its value
- `D_STR(var)` : (String) Print variable and its value
- `D_PTR(var)` : (Pointer) Print variable and its value

To debug memory manipulation with strings
- `D_STR_DETAILS(str)` : Prints a string in details, printing control chars by their numeric value in the ascii table.

# Contributing
Feel free to make a pull request to add your own macros

# Thanks
Thanks to Jjosephi, for teaching me the existence of `_Generic()`
