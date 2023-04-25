# Creating a GUI window in C
This program demonstrates how to create a basic GUI window in C without any external modules.

# Prerequisites
C compiler (GCC, Clang, etc.)/n
For Windows: MinGW or Visual Studio (if using Visual Studio, some modifications may be required)/n
For Unix-based systems: Xlib development library
# How to build and run
Windows
Open the command prompt and navigate to the directory containing the source code file main.c.
Compile the code using ```bash
  gcc main.c -o main
```
Run the program using ```bash
  main.exe
```
Unix-based systems
Open the terminal and navigate to the directory containing the source code file main.c.
Compile the code using gcc main.c -o main -lX11.
Run the program using ./main.
How it works
The program uses conditional compilation to differentiate between Windows and Unix-based systems, as the method for creating GUI windows is different for each.

On Windows, the program uses the Win32 API to register a window class, create a window, and enter a message loop. On Unix-based systems, the program uses Xlib to create a simple window, map it to the screen, and wait for a key press event.

License
This program is licensed under the MIT License. See the LICENSE file for details.
# c-window
a simple c program to generate a window in windows and linux also .👾

## Run

To run the code :

```bash
  gcc app.c
```
 
```bash
  ./app.exe
```

## Screenshots

![App Screenshot](/screenshort.png)

## License

[MIT](https://choosealicense.com/licenses/mit/)
