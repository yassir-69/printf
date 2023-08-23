#include "main.h"

/**
 * custom_printf - Generates formatted output according to the provided format.
 * @format_string: The format string.
 *
 * Return: The count of bytes that have been printed.
 */

int custom_printf(const char *format_string, ...) {

    int byte_count = 0;
    va_list arguments;
    char *current_char, *format_start;
    params_t parameters = PARAMS_INIT;

    va_start(arguments, format_string);

    if (!format_string || (format_string[0] == '%' && !format_string[1]))
        return -1;

    if (format_string[0] == '%' && format_string[1] == ' ' && !format_string[2])
        return -1;

    for (current_char = (char *)format_string; *current_char; current_char++) {

        initialize_params(&parameters, arguments);

        if (*current_char != '%') {
            byte_count += output_character(*current_char);
            continue;
        }

        format_start = current_char;
        current_char++;

        while (extract_flag(current_char, &parameters))
            current_char++;

        current_char = extract_width(current_char, &parameters, arguments);
        current_char = extract_precision(current_char, &parameters, arguments);

        if (extract_modifier(current_char, &parameters))
            current_char++;

        if (!extract_specifier(current_char)) {
            byte_count += print_range(format_start, current_char,
                parameters.l_modifier || parameters.h_modifier ? current_char - 1 : 0);
        } else {
            byte_count += get_print_function(current_char, arguments, &parameters);
        }
    }

    output_character(BUFFER_FLUSH);
    va_end(arguments);
    return byte_count;
}
