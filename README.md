# JUC Compiler

A compiler for **JUC**, a Java-inspired programming language, developed as part of the **Compiler Construction** course in the B.Sc. in Informatics Engineering at the **University of Coimbra**.

The objective of the project was to design and implement the core stages of a compiler, from lexical analysis to semantic analysis, using standard compiler construction tools.

---

## Features

The compiler implements the following stages:

- Lexical analysis
- Syntax analysis (parsing)
- Abstract Syntax Tree (AST) construction
- Symbol table management
- Semantic analysis
- Type checking
- Error reporting

---

## Technologies

- C
- Flex
- Bison

---

## Project Structure

```
.
├── ast.c / ast.h        # Abstract Syntax Tree implementation
├── semantic.c           # Semantic analysis
├── symbol_table.c       # Symbol table
├── lexer.l              # Lexical analyser
├── parser.y             # Grammar and parser
└── ...
```

*(Update this tree to reflect your actual repository structure.)*

---

## Example

Input:

```java
int factorial(int n) {
    if (n <= 1)
        return 1;

    return n * factorial(n - 1);
}
```

The compiler performs lexical and syntax analysis, constructs the Abstract Syntax Tree, and validates semantic correctness before reporting any compilation errors.

---

## Learning Outcomes

Through this project I gained practical experience with:

- Compiler design
- Context-free grammars
- Lexical analysis
- LR parsing
- Abstract Syntax Trees
- Symbol table implementation
- Semantic analysis
- Static type checking
- Error handling

---

## Repository

This repository contains the implementation developed during the Compiler Construction course. It also includes a collection of test programs used to validate the compiler's correctness.

---

## Future Improvements

Possible extensions include:

- Intermediate code generation
- Code optimization
- Target code generation
- Additional language features
- Improved diagnostic messages
