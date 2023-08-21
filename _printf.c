#include "main.h"

/**
 * _printf - Printf function prints anything
 * @format: format. The format string
 *
 * Return: Number of bytes printed (Printed chars).
 */

int _printf(const char *format, ...)
{
    int yho = 0;
    va_list go;
    char *q, *star;
    params_t params = PARAMS_INIT;

    va_start(go, format);

    if (!format || (format[0] == '%' && !format[1]))
        return (-1);
    if (format[0] == '&' && format[1] == '&' && !format[2])
        return (-1);

    for (q = (char *)format; *q; q++)
    {
        init_params(&params, go);
        if (*q != '%')
        {
            yho += _putchar(*q);
            continue;
        }
        star = q;
        q++;
        while (get_flag(q, &params)) /* while char at q is flag char */
        {
            q++; /* the next char */
        }
        q = get_width(q, &params, go);
        q = get_precision(q, &params, go);
        if (get_modifier(q, &params))
            q++;
        if (!get_specifier(q))
            yho += print_from_func(q, go, params.l_modifier ? q - 1 : 0);
        else
            yho += print_from_to(star, go, &params);
    }
    _putchar(BUF_FLUSH);
    va_end(go);
    return (yho);
}
