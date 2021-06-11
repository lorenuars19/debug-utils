```bash
curl https://raw.githubusercontent.com/lorenuars19/debug-utils/main/debug_utils.h -o debug_utils.h
```
```c
#include "debug_utils.h"
```
to add to your global include folder, so you can include with `#include <debug_utils.h>` run this <br>
```bash
sudo cp debug_utils.h /usr/include/debug_utils.h
```
# Debug-Utils
Header file containing useful debug macros I use all the time

## Parameters
Name           |How           | Compiler Option    | Description                                                                 | Default value
-------------- | ------------ | ------------------ | --------------------------------------------------------------------------- | -------------
`_BREAK_PAUSE` | compile with | `-D _BREAK_PAUSE=` | set `1`or `0` : `1` will pause, `0` will not pause.                         | 1
`_NEWLINE`     | compile with | `-D _NEWLINE=`     | set `1`or `0` : `1` will print newlines, `0` will give more compact output. | 1
`_FD`          | compile with | `-D _FD=`          | sets the File Descriptor on which you want to output.                       | 2
`_VAR_WIDTH`   | compile with | `-D _VAR_WIDTH=`   | to set the field width of printf for variables                              | 8
`_MSG_WIDTH`   | compile with | `-D _MSG_WIDTH=`   | to set the field width of printf for messages                               | 2
`_NO_COLORS`   | compile with |`-D _NO_COLORS`     | to remove all colors.                                                       | not defined by default
# Macros
## Automatic Macros
Macro Name     | Mnemonic Name            | Decritpion
-------------- | ------------------------ | ----------
`BR`           | BreakPoint               | will pause the execution using libc `getchar()` so you can just press enter in the terminal to continue your program, you can `-D BREAK_PAUSE=0` so it does not pause your program.
`BM(msg)`      | Breakpoint Message       | Same as `BR` but with a custom message but without pause.
`BMB(msg)`     | BreakPoint Message Break | Same as `BR` but with a custom message, with pause.
`DE(var)`      | Debug Variable           | Will try to detect variable type, and print it accordingly, using `_Generic()`.
`DM(msg, var)` | Debug Message            | same as `DE` but calls `BM(msg)` before.
`DB(...)`      | Debug Builder            | Allows to print a number of variables on one single line, and 'build' a debug line
`DBM(msg, ...)`| Debug Builder Message    | Same as `DB(...)` but calls `BM(msg)` before.
## Static Macros
In case `_Generic()` fails to determine the correct type.
Macro Name | Function
:--------- | :-------
`D_INT(var)` | (int) Print variable and its value.
`D_LINT(var)` | (long) Print variable and its value.
`D_DOUB(var)` | (double) Print variable and its value.
`D_STR(var)` | (string) Print variable and its value.
`D_CHR(var)` | (char) Print variable and its value.
`D_PTR(var)` | (pointer) Print variable and its value.

To debug memory manipulation with strings
Macro Name | Function
---------- | --------
`D_STR_DETAILS(str)` | Prints a string in details, printing control chars by their numeric value in the ascii table.
`D_STR_DETAILS_LEN(str, len)` | Prints a string in details forcing the len, printing control chars by their numeric value in the ascii table.

# Contributing
Feel free to make a pull request to add your own macros.

# Thanks
- Thanks to [Jjosephi](https://github.com/FlavorlessQuark), for teaching me the existence of `_Generic()`.
- Thanks to [Matthew-Dreemurr](https://github.com/Matthew-Dreemurr), for fixes.
- Thanks to [Jonathan Heathcote](https://github.com/mossblaser) the autor of [C Pre-Processor Magic](http://jhnet.co.uk/articles/cpp_magic#iterators), for taking the time to write this, I took the liberty to backup this wonderful article in case this site goes down
