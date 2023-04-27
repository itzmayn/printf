/*
 * File: modifiers.c
 */

#include "main.h"

/**
 * print_width - Stores leading spaces to a buffer for a width modifier.
 * @output: A buffer_t struct containing a character array.
 * @printed: The current number of characters already printed to output
 *           for a given number specifier.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int print_width(buffer_t *output, unsigned int printed,
                         unsigned char flags, int wid)
{
    unsigned int ret = 0;
    char width = ' ';

    if (!(flags & NEG_FLAG))
    {
        for (wid -= printed; wid > 0; wid--)
            ret += _memcpy(output, &width, 1);
    }

    return (ret);
}

/**
 * print_string_width - Stores leading spaces to a buffer for a width modifier.
 * @output: A buffer_t struct containing a character array.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @size: The size of the string.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int print_string_width(buffer_t *output,
                                unsigned char flags, int wid, int prec, int size)
{
    unsigned int ret = 0;
    char width = ' ';

    if (!(flags & NEG_FLAG))
    {
        wid -= (prec == -1) ? size : prec;
        for (; wid > 0; wid--)
            ret += _memcpy(output, &width, 1);
    }

    return (ret);
}

/**
 * print_neg_width - Stores trailing spaces to a buffer for a '-' flag.
 * @output: A buffer_t struct containing a character array.
 * @printed: The current number of bytes already stored to output
 *           for a given specifier.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int print_neg_width(buffer_t *output, unsigned int printed,
                             unsigned char flags, int wid)
{
    unsigned int ret = 0;
    char width = ' ';

    if (flags & NEG_FLAG)
    {
        for (wid -= printed; wid > 0; wid--)
            ret += _memcpy(output, &width, 1);
    }

    return (ret);
}
