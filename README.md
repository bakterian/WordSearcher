# WordSearcher
A simple app used for searching words within a letter matrics

# Example
If we are searching for a word "adidas" within a 6x6. This is how the matrix looks like:
```
Word placement in matrix: 
 ----------
|_ida______|
|_d________|
|_a________|
|_s________|
|__________|
|__________|
|__________|
|__________|
|__________|
|__________|
 ----------

Filled matrix: 
 ----------
|aidaefghij|
|adcdefghij|
|aacdefghij|
|ascdefghij|
|abcdefghij|
|abcdefghij|
|abcdefghij|
|abcdefghij|
|abcdefghij|
|abcdefghij|
 ----------
```

# Execution
After building, execute this file:
```
WordSearcher.Console.exe
```
If we want to change the word, word placement, matrix size the arguments\
of the TestBoardGen::GetBoardWithPattern should be changed in the WordSearcher.Console.cpp.


# Testing
This application is google tested and google mocked. After builing just execute this file:
```
WordSearcher.LibUnitTests.exe
```
