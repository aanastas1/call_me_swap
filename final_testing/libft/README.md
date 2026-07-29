*This project has been created as part of the 42 curriculum by aloiko.*

# Libft

## Description

Libft is the first project in the study program at School 42. The purpose of the project is to introduce students to standard C functions that we will be able to use in our future projects. To gain a deeper understanding of how functions work, we needed to create our own implementations of standard functions.

All functions are created in accordance with 42 Norminette — the set of rules that defines how code should be formatted.

The project consists of 3 logical parts:

### Part 1 — Libc functions

This section reimplements a set of functions from the standard C library (libc). These functions have the same prototypes and behavior as the originals, strictly adhering to their descriptions in the man page. The only difference is in the function names: they begin with the prefix `ft_`. For example, `strlen` becomes `ft_strlen`.

- `ft_isalpha` — checks whether the character is an alphabetic letter  
- `ft_isdigit` — checks whether the character is a decimal digit  
- `ft_isalnum` — checks whether the character is alphanumeric (letter or digit)  
- `ft_isascii` — checks whether the character is a valid ASCII value (0–127)  
- `ft_isprint` — checks whether the character is printable (according to ASCII)  
- `ft_strlen` — returns the length of a string up to the null terminator  
- `ft_memset` — fills a block of memory with a given byte value  
- `ft_bzero` — sets a block of memory to zero bytes  
- `ft_memcpy` — copies bytes from one memory area to another (no overlap)  
- `ft_memmove` — copies bytes safely between memory areas even if they overlap  
- `ft_strlcpy` — copies a C-string into a buffer safely and returns the size it tried to create  
- `ft_strlcat` — appends a C-string to a buffer safely and returns the size it tried to create  
- `ft_toupper` — converts a letter to uppercase if it’s lowercase  
- `ft_tolower` — converts a letter to lowercase if it’s uppercase  
- `ft_strchr` — finds the first occurrence of a character in a string  
- `ft_strrchr` — finds the last occurrence of a character in a string  
- `ft_strncmp` — compares two strings up to `n` characters  
- `ft_memchr` — finds the first occurrence of a byte in a memory block  
- `ft_memcmp` — compares two memory blocks byte-by-byte  
- `ft_strnstr` — finds a substring within the first `n` characters of a string  
- `ft_atoi` — converts a string to an integer  
- `ft_calloc` — allocates memory and sets it to zero  
- `ft_strdup` — duplicates a string by allocating new memory and copying it  

### Part 2 — Additional functions

The second part presents a set of functions that are either missing from libc or appear there in a different form.

- `ft_substr` — creates a substring from a string starting at `start` with up to `len` characters  
- `ft_strjoin` — concatenates two strings `s1` and `s2` into a newly allocated string  
- `ft_strtrim` — removes characters in `set` from the beginning and end of `s1`  
- `ft_split` — splits a string `s` into an array of strings using delimiter `c` (NULL-terminated)  
- `ft_itoa` — converts an integer `n` into a newly allocated string  
- `ft_strmapi` — creates a new string by applying function `f` to each character with its index  
- `ft_striteri` — applies function `f` to each character (by address) with its index, allowing modification  
- `ft_putchar_fd` — writes a single character to file descriptor `fd`  
- `ft_putstr_fd` — writes a string to file descriptor `fd`  
- `ft_putendl_fd` — writes a string to `fd` followed by a newline  
- `ft_putnbr_fd` — writes an integer to file descriptor `fd`  

### Part 3 — Linked list

In this third part, functions for working with a linked list using a structure are implemented.

To do this, the following structure declaration was added to the `libft.h` file:

```c
typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;
```
Fields of the `t_list` structure:<br>- **content:** the data contained in the node. Using the `void *` type allows storing data of any type.<br>- **next:** the address of the next node, or `NULL` if the current node is the last one.

- `ft_lstnew` — allocates a new list node, sets its `content`, and sets `next` to `NULL`  
- `ft_lstadd_front` — adds a node at the beginning of the list  
- `ft_lstsize` — returns the number of nodes in the list  
- `ft_lstlast` — returns the last node of the list  
- `ft_lstadd_back` — adds a node at the end of the list  
- `ft_lstdelone` — deletes one node: frees its `content` using `del`, then frees the node itself (does not touch `next`)  
- `ft_lstclear` — clears the whole list: deletes all nodes and their contents using `del`, then sets the list pointer to `NULL`  
- `ft_lstiter` — iterates through the list and applies `f` to each node’s `content`  
- `ft_lstmap` — creates a new list by applying `f` to each node’s `content`; uses `del` to free content if needed  

## Instructions

The library is written in C, so it needs the `gcc` compiler and some standard C libraries to run.

### Compiling the library

Makefile has 4 main options:

- `make` — compiles C files, creates object files and the `libft.a` library  
- `make clean` — removes object files  
- `make fclean` — removes `libft.a`  
- `make re` — recompiles the library  

To compile the library, run:

```sh
$ cd path/to/libft && make
```

### Using it in your code

To use the library functions in your code, include its header:

```c
#include "libft.h"
```

## Resources

- Manual pages - UNIX (`man`) pages for reference on expected behaviour, return values, and edge cases.

- Online documentation – GNU C Library docs, web search to find relevant information and resources, and peer‑to‑peer feedback from fellow 42 students.

- AI was used to quickly polish and format the README.md text.