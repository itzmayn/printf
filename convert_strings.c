#include "main.h"

/**
 * convert_s - Converts an argument to a string and stores it to a buffer
 *             contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @output: A buffer_t struct containing a character array.
 * @flags: Flag modifiers.
 * @width: A width modifier.
 * @precision: A precision modifier.
 * @length: A length modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_s(va_list args, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char length)
{
	char *str, *null = "(null)";
	int size = 0;
	unsigned int ret = 0;

	(void)flags;
	(void)length;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	while (*(str + size))
		size++;

	ret += print_string_width(output, flags, width, precision, size);

	precision = (precision == -1) ? size : precision;
	while (*str != '\0' && precision > 0)
	{
		ret += _memcpy(output, str, 1);
		precision--;
		str++;
	}

	ret += print_neg_width(output, ret, flags, width);

	return (ret);
}

/**
 * convert_S - Converts an argument to a string and stores it to a buffer
 *             contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @output: A buffer_t struct containing a character array.
 * @flags: Flag modifiers.
 * @width: A width modifier.
 * @precision: A precision modifier.
 * @length: A length modifier.
 *
 * Return: The number of bytes stored to the buffer.
 *
 * Description: Non-printable characteres (ASCII values < 32 or >= 127) are
 *              stored as \x followed by the ASCII code value in hex.
 */
unsigned int convert_S(va_list args, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char length)
{
	char *str, *null = "(null)", *hex = "\\x", zero = '0';
	int size = 0, index = 0;
	unsigned int ret = 0;

	(void)length;
	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	while (str[size])
		size++;

	ret += print_string_width(output, flags, width, precision, size);

	precision = (precision == -1) ? size : precision;
	while (*(str + index) != '\0' && index < precision)
	{
		if (*(str + index) < 32 || *(str + index) >= 127)
		{
			ret += _memcpy(output, hex, 2);
			if (*(str + index) < 16)
				ret += _memcpy(output, &zero, 1);
			ret += convert_ubase(output, *(str + index),
					     "0123456789ABCDEF", flags, 0, 0);
			continue;
		}
		ret += _memcpy(output, (str + index), 1);
		index++;
	}

	ret += print_neg_width(output, ret, flags, width);

	return (ret);
}

/**
 * convert_r - Reverses a string and stores it
 *             to a buffer contained in a struct.
 * @args: A va_list pointing to the string to be reversed.
 * @output: A buffer_t struct containing a character array.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_r(va_list args, buffer_t *output, unsigned char flags,
		       int wid, int prec, unsigned char len)
{
	char *str, *null = "(null)";
	int size, end, i;
	unsigned int ret = 0;

	(void)len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (size = 0; *(str + size); size++)
		;

	ret += print_string_width(output, flags, wid, prec, size);

	end = size - 1;
	prec = (prec == -1) ? size : prec;
	for (i = 0; end >= 0 && i < prec; i++, end--)
		ret += _memcpy(output, (str + end), 1);

	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}

/**
 * convert_R - Converts a string to ROT13 and stores
 *             it to a buffer contained in a struct.
 * @args: A va_list pointing to the string to be converted.
 * @output: A buffer_t struct containing a character array.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A lenth modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_R(va_list args, buffer_t *output, unsigned char flags,
		       int wid, int prec, unsigned char len)
{
	char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str, *null = "(null)";
	int i, j, size;
	unsigned int ret = 0;

	(void)len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (size = 0; *(str + size); size++)
		;

	ret += print_string_width(output, flags, wid, prec, size);

	prec = (prec == -1) ? size : prec;
	for (i = 0; *(str + i) != '\0' && i < prec; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (*(str + i) == *(alpha + j))
			{
				ret += _memcpy(output, (rot13 + j), 1);
				break;
			}
		}
		if (j == 52)
			ret += _memcpy(output, (str + i), 1);
	}

	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}
