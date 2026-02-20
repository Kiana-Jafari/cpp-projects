# Base Numbers Calculator

### 1. Project Scope
This project is an introduction to Base Numbers, a main topic covered in *Digital Logic Design (DLD)* and the fundamentals of *How Computers Work*. </br>
The aim of this project is to design and implement a base numbers calculator from scratch that is able to calculate the following based on the user input:

- Get a number in decimal and convert it to any base, including:
    - Binary
    - Quinary
    - Octal
    - Hexadecimal
    - Other non-popular bases

- Get a number in any base and convert it to decimal

- Get two numbers in any base and do Bitwise Operations on them (AND, OR, XOR)

- Get a decimal number and return its `1's complement`

- Calculate and return the `2's complement` of a given number

- Get a plaintext and return the ciphertext, encrypted information
    The main approach for this method is as follows: </br>
    Text → ASCII → Binary → Base-7 → Shift digits → Output
  
---

### Test Cases

input:

1. Convert from Decimal → Base

| Decimal | Base | Number |
| ------- | ---- | ------ |
| 345     | 7    | 1002   |
| 255     | 16   | FF     |
| 100     | 2    | 1100100|

2. Convert from Base → Decimal

| Number | Base | Decimal |
| ------ | ---- | ------- |
| 1323   | 7    | 502     |
| 0xA8FE3| 16   | 692195  |
| 1100100| 2    | 100     |

3. Bitwise Operations

| Number 1 | Number 2 | Operator | Output |
| -------- | -------- | -------- | ------ |
| 12       | 10       | AND      | 8      |
| 12       | 10       | OR       | 14     |
| 12       | 10       | XOR      | 6      |

4. 1’s Complement of a Decimal Number

| Decimal | 1’s complement |
| ------- | -------------- |
| 12      | 11110011       |

5. 2’s Complement of a Decimal Number

| Decimal | 2’s Complement |
| ------- | -------------- |
| 12      | 11110100       |

6. Generate Ciphertext from Plaintext

**Input:**

```
Plaintext: Hi
Base: 7
Shift key: 3
```

```
H = 72 → 132₇
i = 105 → 210₇

Shift digits +3 mod 7:

132 → 465
210 → 543
```

**Output**
```
465 543
```
