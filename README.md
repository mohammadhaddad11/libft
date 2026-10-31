*This project was created as part of the 42 curriculum by mhaddad.*

# libft

Libft is a reusable C library for operations that many programs need before
their own application logic can begin: inspect characters, copy memory, build
strings, convert integers, print to descriptors, and manage linked lists.
Its 43 functions are compiled into a static archive, `libft.a`.

The 42 learning objective is to implement these operations directly and learn
what higher-level library calls normally hide: pointer boundaries, terminators,
allocation sizes, overlapping storage, and responsibility for freeing memory.

## Build and integrate

Requirements: a C compiler, Make, and `ar` on a Unix-like system.

```sh
git clone git@github.com:mohammadhaddad11/libft.git
cd libft
make
cc -Wall -Wextra -Werror -I. examples/split.c libft.a -o libft_example
./libft_example
```

The [example](examples/split.c) prints:

```text
memory
pointers
ownership
```

Include [`libft.h`](libft.h) in a client and put the archive **after** its
source/object files in the linker command. `-I.` makes the header available
when compiling from the library root. The archive supplies routines used by
the client; it is not an executable and contains no application `main`.

| Target | Effect |
| --- | --- |
| `make` | Build the archive, including all linked-list functions |
| `make clean` | Remove intermediate `.o` files |
| `make fclean` | Remove objects and `libft.a` |
| `make re` | Rebuild from scratch |

There is no separate `bonus` target. The Makefile does not generate automatic
header dependencies, so use a clean rebuild after changing the public header.

## What the library contains

| Area | Available operations |
| --- | --- |
| Characters | `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`, `toupper`, `tolower` equivalents with `ft_` prefixes |
| Raw memory | Set/zero bytes, copy/move regions, search for a byte, compare regions |
| Strings | Length, bounded copy/append, character/substring search, bounded comparison |
| Owned values | Zeroed allocation, duplication, substring, join, trim, split, integer formatting |
| Callbacks | Build a mapped string or visit an existing string by index |
| Descriptor output | Write characters, strings, lines, and integers to a chosen descriptor |
| Singly linked lists | Construct, insert, traverse, delete, clear, iterate, and map nodes |

The complete signatures are in the header. Functions returning a pointer do
not all have the same ownership: a search can return an address **inside the
input**, whereas a constructor returns a new allocation.

## How the important pieces work

### Copy bytes without confusing them with strings

Memory helpers use an explicit byte count, so embedded zero bytes are data,
not terminators. [`ft_memmove`](ft_memmove.c) chooses a direction based on the
relative pointers. Copying backward when the destination is later in the same
region prevents newly written bytes from destroying source bytes still needed.

```c
char text[] = "abcdef";
ft_memmove(text + 2, text, 4);
/* text is now "ababcd": the existing terminator was not moved. */
```

`ft_memcpy` is the simpler forward-copy operation and requires nonoverlapping
regions. Neither routine knows the actual size of a caller's allocation.

### Construct strings with explicit ownership

[`ft_substr`](ft_substr.c) bounds the requested length against the source,
allocates room for the selected bytes plus a terminator, and returns an
allocated empty string if `start` is beyond the source. That result still
needs freeing; it is not a shared string literal.

[`ft_strtrim`](ft_strtrim.c) scans inward from both ends while characters
belong to a supplied set, then delegates the resulting interval to `ft_substr`.
The set is a set of individual characters, not a substring to remove:

```c
char *clean = ft_strtrim(" \t42 school\n", " \t\n");
if (clean != NULL)
{
    ft_putendl_fd(clean, 1); /* prints: 42 school */
    free(clean);
}
```

[`ft_split`](ft_split.c) first counts words separated by one delimiter
character, then allocates a pointer array and one substring per word. Repeated
delimiters are skipped: `ft_split("C,,pointers,memory", ',')` gives three words,
not an empty item between the commas. A final NULL pointer marks the array end.
If constructing a token fails, previously created tokens and the array are
freed before returning NULL.

### Allocate and convert values

[`ft_calloc`](ft_calloc.c) checks the unsigned multiplication used to size the
allocation, calls `malloc`, then zeroes the bytes. It returns NULL for detected
overflow or allocation failure.

[`ft_itoa`](ft_itoa.c) calculates output length, allocates once, and fills digits
from the end toward the beginning. It widens the input to `long` before
handling the sign, providing room for the negative `int` boundary on the
tested 64-bit Linux platform. `ft_strmapi` similarly constructs a new string
through a callback, while `ft_striteri` modifies characters in existing storage.

## Memory ownership in a client

| Result | Who owns it? |
| --- | --- |
| `ft_strchr`, `ft_memchr`, similar searches | Borrowed address in existing input; do not free it as a new allocation |
| `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_itoa`, `ft_strmapi` | Caller owns the returned allocation and must free it |
| `ft_split` | Caller frees every token, then the pointer array |
| `ft_memcpy`/`ft_memmove` return value | Same destination supplied by the caller; no new ownership |

Standalone `ft_strjoin` does **not** consume its input strings. This matters
when combining it with similarly named helpers from other projects, which
may have different ownership contracts.

## Linked lists: nodes and contents are separate resources

The public node stores an arbitrary content pointer and a link:

```text
head → [content | next] → [content | next] → NULL
```

`ft_lstnew(content)` allocates a node but does not copy the content. Front
insertion changes the head in constant time; appending uses `ft_lstlast` to
walk to the end. There is no separately maintained tail pointer.

`ft_lstdelone` invokes the caller's deletion callback for content, then frees
the node. `ft_lstclear` saves each successor before deleting the current node
and advances the caller's head until it becomes NULL. This permits heap-owned
strings, structs, or deliberately borrowed values to use different policies.
Passing `free` is appropriate only for content that should be freed that way.

[`ft_lstmap`](ft_lstmap.c) applies a content callback and constructs a new node
for every input node. If node allocation fails, it deletes the just-produced
content and clears the partial new list. The callback must supply appropriate
content/cleanup semantics: the function does not independently treat a NULL
callback result as allocation failure.

Because it repeatedly appends by walking the result, this `ft_lstmap` can take
quadratic time. Most byte/string scans are linear in the bytes processed, but
there is no blanket complexity guarantee covering all routines.

## Checks and known limitations

The strict build, split example, and bundled [smoke checks](tests/smoke.c) were
run successfully:

```sh
cc -Wall -Wextra -Werror -I. tests/smoke.c libft.a -o libft_smoke
./libft_smoke
```

The library is not certified as a complete libc replacement. Existing
boundary-case defects remain:

- `ft_atoi("-2147483648")` overflows its positive `int` accumulator before
  applying the negative sign; general overflow detection is absent.
- `ft_strnstr` can continue after matching terminators and read beyond a string.
- `ft_strlcat` obtains destination length with an unbounded scan, so an
  unterminated destination bounded only by `size` can be read out of bounds.
- NULL-input protection is inconsistent, and descriptor-output helpers do not
  provide a robust write-error reporting interface.

These limitations are distinct from normal-path example success. They are
important when deciding whether this learning library is suitable for a client.

## Resources

- C/POSIX manual pages: `memcpy(3)`, `memmove(3)`, `calloc(3)`, `strdup(3)`, `write(2)`
- [Makefile Tutorial](https://makefiletutorial.com/)
- [libftTester](https://github.com/Tripouille/libftTester), optional external tests

## AI Usage

The project's existing disclosure records AI support for documentation,
explanations, style refactoring, and debugging/review. AI also assisted this
README and checking its examples. The implementation and author credit remain
those of the project; external tester coverage is not implied by the checks above.
