# Lab 02

## Solution


On this laboratory we are focused on design a syntax compiler that checks the syntax errors
of another file. We are going to use C language to do this exercise. First we need to know what 
kind of errors we need to catch, on this case we are going to check braces, parenthesis, and brackets.
First we need to check all the file, for this we are going to use the function "getchar()" and the EOF (End of File)
variable to make a while method to check every character on the file, then we have three functions: inComment(), inQuote, search().

Search() method will use three type of counters (countBraces, countParentehis and countBrackets), every time that our 
compiler finds a "{" will increate the countBrackets by 1, and every time that finds a "}" will decrease the 
counter by 1, and this will work on the same way for the another counters, then we only check if the counter is 
different of 0, on this way we kan know if there is an error on the code.


## Instructions to run 

* Create a file named:
```Hello_world.c```

Run as:

```
    gcc my_compiler.c -o my_compiler
    ./my_compiler < Hello_world.c

```

