*This project has been created as part of the 42 curriculum by ***mel-herc***.*

# Description
The **ft_printf** project consists of implementing a library that contains `ft_printf()`, a function that will mimic the original `printf()`.

The main goal of this project is to understand how variadic functions like `printf()` work in C.

This project also introduces the concept of maintaining state between function calls using **variadic arguments**.

# Instructions

####    Compilation

The ft_printf project is compiled using the provided `Makefile`. The Makefile includes the following standard rules:

- `make` or `make all`: Compiles the project and creates the static library `libftprintf.a`.
- `make clean`: Removes object files `(.o)`.
- `make fclean`: Removes object files and the library `libftprintf.a`.
- `make re`: Performs a full recompile (fclean followed by all).

####    Example Compilation

After making and generating the library `libftprintf.a`, the project can be compiled using the following command:
```
cc -Wall -Werror -Wall main.c libftprintf.a
```

# Resources

[printf().](https://man7.org/linux/man-pages/man3/printf.3.html)

[variadic arguments.](https://thejat.in/blog/variadic-function-working-in-c)

[invalid format specifiere.](https://wiki.sei.cmu.edu/confluence/spaces/c/pages/87152280/CC.+Undefined+Behavior) (167)

#### AI usage:

`Artificial Intelligence tools` were used in accordance with the 42 guidelines. They were employed to refine and validate my understanding of the theoretical concepts studied by comparing my own explanations with AI feedback.
No `AI tools` were used to generate or write the project’s source code.

# Additional section

`ft_printf()` iterates through the format string character by character. When it encounters a `non-%` character, it is written directly to the stdout. When it encounters the `%` character, it parses the next character to determine the format specifier `(c%, s%, p%, d%, i%, u%, x%, X%)`. It uses `va_arg` to extract the corresponding argument from the `variable argument list` based on the specifier's type. It then converts the argument into its character representation. This involves calling various internal helper functions specific to different data types. 
