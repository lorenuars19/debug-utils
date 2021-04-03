`curl https://raw.githubusercontent.com/lorenuars19/debug-utils/main/debug_utils.h -o debug_utils.h`
Add to your global include folder, so you can include with `#include <debug_utils.h>` <br>
`sudo cp debug_utils.h /usr/include/debug_utils.h`
# Debug-Utils
Header file containing useful debug macros I use all the time

# Parameters
- `BREAK_PAUSE` (default : 1) compile with `-D BREAK_PAUSE=` set `1|0` : 1 will pause, 0 will not pause
- `_NEWLINE` (default : 1) compile with `-D _NEWLINE=` set `1|0` : 1 will print newlines, 0 will give more compact output
- `_FD` (default : 2) compile with `-D _FD=` sets the File Descriptor on which you want to output

# Macros
Automatic Macros
- `BR` : BreakPoint : will pause the execution using libc `getchar()` so you can just press enter in the terminal to continue your program, you can `-D BREAK_PAUSE=0` so it does not pause your program.
- `BM(msg)` : Same as `BR` but with a custom message.
- `DE(var)` : Will try to detect variable type, and print it accordingly, using `_Generic()`.
- `DM(msg, var)` : same as `DE` but you can put a message.

Static typed (in case `_Generic()` fails)
- `D_INT(var)` : (int) Print variable and its value.
- `D_LINT(var)` : (long) Print variable and its value.
- `D_STR(var)` : (String) Print variable and its value.
- `D_PTR(var)` : (Pointer) Print variable and its value.

To debug memory manipulation with strings
- `D_STR_DETAILS(str)` : Prints a string in details, printing control chars by their numeric value in the ascii table.

# Contributing
Feel free to make a pull request to add your own macros.

# Thanks
Thanks to [Jjosephi](https://github.com/FlavorlessQuark), for teaching me the existence of `_Generic()`
Thanks to [Mhadad](https://github.com/Matthew-Dreemurr), for fixes.
