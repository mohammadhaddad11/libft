*This project was created as part of the 42 curriculum by mhaddad.*

# libft

A static C library built from scratch: familiar libc routines, additional string helpers, and singly linked-list utilities.

## Description

The project explores pointers, allocation ownership, character and byte operations, and API design. The 43 functions are declared in [`libft.h`](libft.h) and compiled into `libft.a`.

| Family | Representative functions |
| --- | --- |
| Character checks | `ft_isalpha`, `ft_isdigit`, `ft_isprint` |
| Memory | `ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_memcmp` |
| Strings | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strnstr` |
| Allocation | `ft_calloc`, `ft_strdup`, `ft_split`, `ft_itoa` |
| File-descriptor output | `ft_putchar_fd`, `ft_putstr_fd`, `ft_putnbr_fd` |
| Linked lists | `ft_lstnew`, `ft_lstadd_back`, `ft_lstclear`, `ft_lstmap` |

## Instructions

Requires a C compiler, `make`, and `ar`.

```sh
git clone git@github.com:mohammadhaddad11/libft.git
cd libft
make
cc -Wall -Wextra -Werror -I. examples/split.c libft.a -o libft_example
./libft_example
```

| Command | Action |
| --- | --- |
| `make` | Build `libft.a`, including list functions |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and archive |
| `make re` | Rebuild everything |

## Implementation Notes

- `ft_memmove` handles overlapping regions; `ft_memcpy` assumes no overlap.
- Functions returning newly allocated strings transfer ownership to the caller. A `ft_split` result requires freeing each string and the array itself.
- `ft_calloc` checks multiplication overflow before allocating.
- List nodes store `void *content`; the caller chooses who owns and frees that content.
- `ft_lstmap` builds a new list through repeated appends, which can take quadratic time.

## Testing and Limitations

The repository includes [a smoke-test driver](tests/smoke.c). A strict build, linking example, and targeted memory/string/list checks were run during the earlier portfolio publication.

Three boundary-case problems remain in the current source:

| Function | Limitation |
| --- | --- |
| `ft_atoi` | Parsing `"-2147483648"` overflows an intermediate positive `int` |
| `ft_strnstr` | A terminating-match case may read past a string terminator |
| `ft_strlcat` | An unterminated destination can be scanned beyond the supplied size |

These are documented findings, **not** claims of complete libc compatibility. The implementation has not been modified to conceal them.

## Resources

- C/POSIX manual pages: `memcpy(3)`, `memmove(3)`, `calloc(3)`, `strdup(3)`, `write(2)`
- [Makefile Tutorial](https://makefiletutorial.com/)
- [libftTester](https://github.com/Tripouille/libftTester) (optional third-party tester; not rerun for this refresh)

## AI Usage

Earlier project documentation records AI assistance with documentation, concept explanations, style refactoring, and debugging/review. AI also helped prepare publication examples and targeted checks. This README refresh used AI-assisted review and retained all C implementation files.
