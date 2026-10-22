# MiniMat Vector Calculator

## Description

MiniMat is a command-line vector calculator written in C. It can load vectors from CSV files, perform vector operations, display vectors, and save results to a CSV file.

## Build

```bash
make
```

Clean and rebuild:

```bash
make clean
make
```

## Run

```bash
./myveclab
```

## Supported Commands

Commands:
- a = 1 2 3
- a = 1,2,3
- a + b
- a - b
- a * 2
- 2 * a
- c = a + b
- list
- clear
- load
- save
- quit

## Dynamic Memory

The program stores vectors in a dynamically allocated array using:

- `malloc()` for the first vector
- `realloc()` when more vectors are added
- `free()` to release memory when the program exits

Valgrind reports no memory leaks or errors.
