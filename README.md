*This project was created as part of the 42 curriculum by mhaddad.*

# libft

## Description

A small C static library implementing character, memory, string, allocation,
file-descriptor output, and singly linked-list utilities. Building these routines
from first principles develops an understanding of pointers, byte-oriented
operations, ownership, callbacks, and reusable library interfaces.

The library contains 43 function implementations and exposes its interface in
[`libft.h`](libft.h). This repository preserves the original implementation;
the limitations found during verification are recorded below.

## Instructions

Requirements: a C compiler, Make, and `ar` on a Unix-like system.

```sh
git clone git@github.com:mohammadhaddad11/libft.git
cd libft
make
cc -Wall -Wextra -Werror -I. examples/split.c libft.a -o libft_example
./libft_example
```

The example prints `memory`, `pointers`, and `ownership`, one per line, and frees
both the split strings and their pointer array. To use the library in another
program, include `libft.h` and place `libft.a` after the source/object files in
the linker command.

| Target | Result |
| --- | --- |
| `make` | Build `libft.a`, including linked-list functions |
| `make clean` | Remove object files |
| `make fclean` | Remove objects and the archive |
| `make re` | Rebuild from scratch |

There is no separate `bonus` target in this implementation.

## Technical Implementation

| Family | Functions |
| --- | --- |
| Characters | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower` |
| Memory | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp` |
| Strings and conversion | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_atoi` |
| Allocation and string construction | `ft_calloc`, `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri` |
| Descriptor output | `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` |
| Lists | `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap` |

### Memory and ownership

- Memory routines work byte by byte; `ft_memmove` chooses a copying direction
  for overlapping ranges. `ft_memcpy` requires nonoverlapping ranges.
- `ft_calloc` checks multiplication overflow before allocating and zeroing.
- Allocating functions return heap memory owned by the caller. A split result
  requires freeing each token and then the NULL-terminated pointer array.
- `ft_split` uses one delimiter character and cleans up earlier tokens when an
  allocation fails.
- A list node owns its node allocation, but content ownership is chosen by the
  caller. Destructive list functions receive a content-deletion callback.
- `ft_lstmap` allocates new nodes and uses the supplied deletion callback to
  clean up partially constructed output on node-allocation failure.

## Algorithms and Data Structures

Most scanning and copying routines are linear in the processed byte count.
`ft_strtrim` checks both ends against a character set; `ft_split` first counts
words and then constructs substrings. `ft_itoa` widens its input to `long` and
fills digits backward, including the negative `int` boundary.

Lists contain `void *content` and a `next` pointer. Front insertion is constant
time; finding the last node or appending traverses the list. Because `ft_lstmap`
repeatedly appends, constructing its result can take quadratic time.

## Design Decisions

The implementation favors small, inspectable routines and a single public
header. It does not introduce an allocator abstraction or a generic container
framework. Helpers return raw pointers, so callers must handle allocation
failure and ownership explicitly. Many functions assume valid, terminated
strings and do not provide general NULL-input protection.

## Verification and Known Issues

Publication checks on Fedora, 2026-10-27:

- `make re` passed with `-Wall -Wextra -Werror`.
- The example and [`tests/smoke.c`](tests/smoke.c) passed. Coverage includes ASCII
  classification, overlapping moves, bounded copies, split/trim/map operations,
  integer formatting, and independent list allocation/cleanup.
- Separate Clang AddressSanitizer/UndefinedBehaviorSanitizer probes found:

| Routine | Reproduced issue |
| --- | --- |
| `ft_atoi` | `"-2147483648"` overflows the positive `int` accumulator before applying its sign |
| `ft_strnstr` | Searching `"abc"` for `"bc"` with length 20 can read past both terminators because the inner loop does not stop at the needle terminator |
| `ft_strlcat` | A two-byte destination `{'a', 'b'}` with size 2 is scanned past its bound by `ft_strlen` |

These implementations have not been silently repaired. A successful ordinary
smoke run does not negate the sanitizer findings or establish full libc parity.
The earlier README mentioned libftTester; that external suite was not rerun in
this publication session.

Run the bundled smoke checks:

```sh
make
cc -Wall -Wextra -Werror -I. tests/smoke.c libft.a -o libft_smoke
./libft_smoke
```

## Resources

- Linux manual pages: `memcpy(3)`, `memmove(3)`, `calloc(3)`, `strdup(3)`, `write(2)`.
- [Makefile Tutorial](https://makefiletutorial.com/).
- [libftTester](https://github.com/Tripouille/libftTester), an optional external tester.
## AI Usage

The earlier project README records AI assistance with documentation, concept
explanations, style refactoring, and debugging/review. During portfolio
publication, an AI coding assistant compared source versions, revised this
documentation, and added examples and verification checks. The existing library
implementations were preserved; this disclosure does not establish additional
historical AI use beyond the author's existing account.
