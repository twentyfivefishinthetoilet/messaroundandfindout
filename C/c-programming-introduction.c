// C CRASH COURSE
// DO NOT RUN THIS FILE, IT WILL NOT WORK LIKE YOU THINK IT WILL
// like, your computer will probably explode i think

// LESSON 1: HELLO WORLD
#include <stdio.h>

int main(){
    printf("Hello, World!");
    return 0;
}

// LESSON 2: COMPILE WITH "gcc helloworld.c"

// LESSON 3: ESCAPE SEQUENCES

int main(){
    printf("Hello, World!\tGoodbye, World!"); // \n is new line, \t is tab, but we already knew that
    return 0;
}

// LESSON 4: VARIABLES

int main(){

    int number = 5;
    float decimals = 5.120;
    char character = '+'; // HAS TO BE IN SINGULAR QUOTES
    char name[] = "Hello, World!";

    printf("STRING: %s\tINT: %d\nCHARACTER: %c\nDECIMAL: %f",name,number,character,decimals);
    return 0;
}

// LESSON 5: DATA TYPES
// unsigned char (0 - +255)
// char (-128 - +127)
// unsigned multiplies the positive range while executing the negative range
// OVERFLOW GETS SENT BACK TO ITS ORIGINAL VALUE, UNSIGNED = 0

#include <stdbool.h>
int main(){

    int number = 5;
    float decimals = 5.120;
    char character = '+'; // HAS TO BE IN SINGULAR QUOTES
    char name[] = "Hello, World!"; // string is actually an array of chars!

    double decimalsDoubled = 5.120; // double the amount of a float 一 %lf 
    bool t = true; // true or false 一 %d
    char c = 100; // using ascii values like this will print the character 一 %c

    printf("STRING: %s\tINT: %d\nCHARACTER: %c\nDECIMAL: %f",name,number,character,decimals);
    return 0;
}

// LESSON 6: FORMAT SPECIFIERS
// %c : character
// %s : string 
// %f : float
// %lf : double
// %d : int
// %.1 : decimal precision
// %1 : minimum field width
// %- : left align

// LESSON 7: CONSTANTS
// add "const" before the variable to make it a constant variable
// consts cant be edited during execution

// LESSON 8: ARITHMETIC OPERATORS

int main(){

    int x = 5;
    int y = 10;

    int sum = x + y;
    int diff = x - y;
    int prod = x * y;
    float divi = x / y;
    int modul = x % y; // remainder of any division

    x++; // increment
    y--; // decrement

    printf(sum);

    return 0;
}

// LESSON 9: AUGMENTED ASSIGNMENT OPERATORS
// int x = 5;
// x += 5;
// x NOW EQUALS 10
// WORKS WITH *=, -=, /=, %=, AND +=

// LESSON 10: USER INPUT

int main(){
    
    char food[25]; // BYTES
    
    printf("What would you like to order? ");
    fgets(food, 25, stdin); // scanf() READS UP TO ANY WHITE SPACE, fgets() IGNORES WHITE SPACES.

    printf("You ordered: %s",food);

    return 0;
}

// LESSON 11: MATH FUNCTIONS
// these are self explainatory...

#include <math.h>
int main(){

    int x = 13;
    int y = 2;

    double a = sqrt(x);
    double b = pow(x,y);
    int c = round(3.14159);
    int d = ceil(3.14159);
    int e = floor(3.14159);
    double f = fabs(-x);
    double g = log(y);
    double h = sin(x);
    double i = cos(x);
    double j = tan(x);

    printf("a = %lf\tb = %lf\nc = %d\td = %d\ne = %d\tf = %lf\ng = %lf\th = %lf\ni = %lf\tj = %lf",a,b,c,d,e,f,g,h,i,j);

    return 0;
}