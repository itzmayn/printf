_printf

This is an implementation of the printf standard function and variadic function in C programming language. The function receives a format (const char *format) and a list of arguments using the magic of variadic functions. The string format is then searched for specific patterns, and the match pattern is passed to another function that prints it.
What is printf?

Printf is a function that writes the C string pointed by format to the standard output (stdout).
Patterns


The three functions that serve as the bases for this project include:

    Printf: This function is the frontend of all the algorithm, so is the prototype, and just receives the variables.
    Handler: This function is the controller for the string and the formats, and also does the counter for the numbers of bytes that are printing.
    Percent handler: This function compares a list of possible specifiers with the current pattern and returns the corresponding function.

Contributors
2

- Maria Mothiba
- Marwa Abu Essa
