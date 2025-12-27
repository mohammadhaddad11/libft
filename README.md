*This activity has been created as part of the 42 curriculum by <mhaddad>.*

# Libft - Your First C Library

## 📝 Description
**Libft** is the first project in the 42 curriculum. The goal is to create a custom C library named `libft.a`. This library allows us to re-implement standard C library functions to understand how they work under the hood, as well as create additional utility functions for string manipulation, memory management, and linked lists.

Since we are often not allowed to use standard C library functions in 42 projects, this library serves as a foundational toolkit for our future assignments.

## 📚 Library Contents

### 1. Libc Functions
Re-implementation of standard C library functions.

| Function | Description |
| :--- | :--- |
| `ft_isalpha` | Checks for an alphabetic character. |
| `ft_isdigit` | Checks for a digit (0 through 9). |
| `ft_isalnum` | Checks for an alphanumeric character. |
| `ft_isascii` | Checks whether c is a 7-bit unsigned char value that fits into the ASCII character set. |
| `ft_isprint` | Checks for any printable character including space. |
| `ft_strlen` | Calculates the length of a string. |
| `ft_memset` | Fills memory with a constant byte. |
| `ft_bzero` | Erases the data in the n bytes of the memory by writing zeros. |
| `ft_memcpy` | Copies memory area. |
| `ft_memmove` | Copies memory area (handles overlapping). |
| `ft_strlcpy` | Copies string to a specific size. |
| `ft_strlcat` | Concatenates string to a specific size. |
| `ft_toupper` | Converts char to uppercase. |
| `ft_tolower` | Converts char to lowercase. |
| `ft_strchr` | Locates character in string (first occurrence). |
| `ft_strrchr` | Locates character in string (last occurrence). |
| `ft_strncmp` | Compares two strings. |
| `ft_memchr` | Scans memory for a character. |
| `ft_memcmp` | Compares memory areas. |
| `ft_strnstr` | Locates a substring in a string. |
| `ft_atoi` | Converts a string to an integer. |
| `ft_calloc` | Allocates memory and sets its bytes' values to 0. |
| `ft_strdup` | Creates a duplicate for the string passed as parameter. |

### 2. Additional Functions
Useful functions that are not part of the standard Libc.

| Function | Description |
| :--- | :--- |
| `ft_substr` | Allocates and returns a substring from the string 's'. |
| `ft_strjoin` | Allocates and returns a new string, which is the result of the concatenation of 's1' and 's2'. |
| `ft_strtrim` | Allocates and returns a copy of 's1' with the characters specified in 'set' removed from the beginning and the end of the string. |
| `ft_split` | Allocates and returns an array of strings obtained by splitting 's' using the character 'c' as a delimiter. |
| `ft_itoa` | Allocates and returns a string representing the integer received as an argument. |
| `ft_strmapi` | Applies the function 'f' to each character of the string 's', and passing its index as first argument to create a new string. |
| `ft_striteri` | Applies the function 'f' on each character of the string passed as argument, passing its index as first argument. |
| `ft_putchar_fd` | Outputs the character 'c' to the given file descriptor. |
| `ft_putstr_fd` | Outputs the string 's' to the given file descriptor. |
| `ft_putendl_fd` | Outputs the string 's' to the given file descriptor followed by a newline. |
| `ft_putnbr_fd` | Outputs the integer 'n' to the given file descriptor. |

### 3. Linked List Functions (Bonus)
Functions to manipulate lists.

| Function | Description |
| :--- | :--- |
| `ft_lstnew` | Allocates and returns a new node. |
| `ft_lstadd_front` | Adds the node 'new' at the beginning of the list. |
| `ft_lstsize` | Counts the number of elements in a list. |
| `ft_lstlast` | Returns the last node of the list. |
| `ft_lstadd_back` | Adds the node 'new' at the end of the list. |
| `ft_lstdelone` | Takes as a parameter a node and frees the memory of the node’s content using the function 'del' given as a parameter and free the node. |
| `ft_lstclear` | Deletes and frees the given node and every successor of that node, using the function 'del' and free(3). |
| `ft_lstiter` | Iterates the list 'lst' and applies the function 'f' on the content of each node. |
| `ft_lstmap` | Iterates the list 'lst' and applies the function 'f' on the content of each node to create a new list. |

## 🛠️ Instructions

### Compilation
To compile the library (including all mandatory and bonus parts), simply run:

```bash
make
