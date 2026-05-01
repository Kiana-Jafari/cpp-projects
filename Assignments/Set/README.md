# Set Class Template – Assignment README

This project implements a generic `Set` class in C++ that stores a finite set of unique elements (maximum capacity 100). The class supports common set operations and works with any data type (e.g., `int`, `double`, `char`).

## Requirements 
- Maximum set size: 100 (fixed capacity)
- Elements can be of character, integer, or floating-point types → use templates

## Methods
- Constructor: Initializes an empty set
- Destructor
- isPresent(x): Checks if `x` is a member
- insert(x): Adds `x` if not already present and space permits
- remove(x): Removes `x` if present
- save(): Saves set elements to a file (`numbers.txt`)
- getInput(): Reads `n` and `n` elements from user, inserts them
- operator+: Returns the union of two sets
- operator-: Returns the difference of two sets
- operator*: Returns the intersection of two sets

## Examples

Examples including edge cases are provided in the `main.cpp`.
