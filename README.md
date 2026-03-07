
*This project has been created as part of the 42 curriculum by iboujdad.*
  
### ft_printf  
  
# Description  
  
`ft_printf` is a reimplementation of the standard C library function `printf`.  
  
The goal of this project is to understand how formatted output works internally by recreating the behavior of `printf`. This includes parsing format strings, handling variadic arguments, and formatting output according to different conversion specifiers and flags.  
  
This implementation supports several conversions and flag combinations, including width, precision, and alignment.  
  
### Supported Conversions  
  
- `%c` → Character  
- `%s` → String  
- `%p` → Pointer address  
- `%d` → Signed decimal integer  
- `%i` → Signed decimal integer  
- `%u` → Unsigned decimal integer  
- `%x` → Hexadecimal (lowercase)  
- `%X` → Hexadecimal (uppercase)  
- `%%` → Percent sign  
  
### Supported Flags (Bonus)  
  
This implementation supports combinations of the following flags:  
  
| Flag | Description |  
|-----|-------------|  
| `-` | Left-align the output within the field width |  
| `0` | Pad the output with zeros instead of spaces |  
| `.` | Precision specifier |  
| width | Minimum field width |  

Example format specifiers supported:  
- %08d  
- %-10s  
- %.5d  
- %10.5d  
- %-10.5s  
- %020x  
  
  
---  
  
# Instructions  
  
## Compilation  
  
Clone the repository and compile using `make`.  
  
```bash  
$>git clone <GIT repository>.  
$>cd ft_printf  
$>make  
$>make test  
```
make test will compile your main.c and creates an output file named ./tester  

## Usage  

```C
#include "ft_printf.h  
  
int main(void)
{
    ft_printf("Hello %s!\n", "Castle");  
    ft_printf("Number: %010d\n", 42);  
    return(0);  
}
```

compile with :  
$>make test  

# Resources  
- https://www.tutorialspoint.com/c_standard_library/c_macro_va_arg.htm  
- https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/va-arg-va-copy-va-end-va-start?view=msvc-170
  
  
  
# Conclusion

The `ft_printf` project provides a deeper understanding of how formatted output works in C.  
By recreating the behavior of the standard `printf` function, this project explores important programming concepts such as:

- Variadic functions (`stdarg.h`)
- String parsing
- Memory and type handling
- Low-level output with `write`

This project is an essential step in the 42 curriculum, strengthening both **algorithmic thinking** and **low-level programming skills in C**.

**Made By**: Ismael Boujdad (castle_sp5).
