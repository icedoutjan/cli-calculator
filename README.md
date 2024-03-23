# cli-calculator

The project has a Makefile for easy compiling and installing. just run in the project directory:
```bash
make install clean
```
The install option will put a copy of the binary to the path.
```bash
~/.local/bin
```
All of my programs that I want to run system-wide are located on this path.

 Pass the program a mathematical function as string. example: 
 ```bash
calc "12+12*5="
 ``` 
or
```bash
calc "12 +  12*5="
```
the program ignores space.

The program needs the "=" at the end of the string i will fix this bug.
I will also include a method to handle negativ numbers and Potencies.
