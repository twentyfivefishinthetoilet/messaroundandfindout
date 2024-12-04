// this project originally was just a screw around thing but then i got tired of math so here we are
// uses escape sequences for colors (if you couldn't tell already)
// blame me for being lazy and not implementing type conversion yet

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define GRAY "\033[38;5;8m"
#define RESET "\033[38;5;255m"
#define BOLD "\033[1m"
#define NORMAL "\033[22m"

float hypotenuse(float sidea, float sideb){
    float h = sqrt(pow(sidea, 2) + pow(sideb, 2));

    // hypotenuse in real world math:
    // c = √a² + b²

    printf("Your hypotenuse is " BOLD "%.2f\n", h);
    return h;
}

float area_Triangle(float base, float height){
    float area = (base + height) / 2;

    // area of a triangle through base and height
    // b * h * 1/2

    printf("The area of %.2f" GRAY " (base) " RESET "and %.2f" GRAY " (height) " RESET "is %.2f\n", base, height, area);
    return area;
}

float slope(float A[2], float B[2]){
    float s = (B[1] - A[1]) / (B[0] - A[0]);
    printf("The slope of the line passing through points (%.2f, %.2f) and (%.2f, %.2f) is " BOLD "%.2f. " RESET GRAY "(%.2f/%.2f)" RESET, A[0], A[1], B[0], B[1], s, (B[1] - A[1]), (B[0] - A[0]));
}

float circumference(float radius){

    float c = 2 * 3.14159 * radius;

    // circumference of a circle formula in actual math:
    // c = 2πr

    printf("The area of the circle with the radius of %.2f is" BOLD " %.2f." RESET, radius, c);

    return c;
}

float herons(float sidea, float sideb, float sidec){
    float s = (sidea + sideb + sidec) / 2;
    float a = sqrt((s * (s - sidea) * (s - sideb) * (s - sidec)));

    // herons is used to find area through 3 sides of the triangle
    // herons formula in actual math
    // note that s is half of the perimeter
    // area = √s(s - a)(s - b)(s - c)

    printf("The area of this triangle with sides %.2f, %.2f, and %.2f is" BOLD " %.2f" RESET, sidea, sideb, sidec, a);

    return a;
}

float distance(float A[2], float B[2]){

    float step1 = (B[0] - A[0]) * (B[0] - A[0]);
    float step2 = (B[1] - A[1]) * (B[1] - A[1]);
    float d = sqrt((step1 + step2));

    // distance formula in actual math
    // d = √(x₂ - x₁)² + (y₂ - y₁)²

    printf("The distance between points (%.2f, %.2f) and (%.2f, %.2f) is" BOLD " %.2f" RESET, A[0], A[1], B[0], B[1], d);
}

float incenter(float A[2], float B[2], float C[2]){

    // a = length of side BC
    // b = length of side AC
    // c = length of side AB

    // step one: distance formula
    float a = sqrt(pow((B[0] - C[0]), 2) + pow((B[1] - C[1]), 2));
    float b = sqrt(pow((C[0] - A[0]), 2) + pow((C[1] - A[1]), 2));
    float c = sqrt(pow((A[0] - B[0]), 2) + pow((A[1] - B[1]), 2));

    // step two: incenter x and y
    float x = (a * A[0] + b * B[0] + c * C[0]) / (a + b + c);
    float y = (a * A[1] + b * B[1] + c * C[1]) / (a + b + c);

    // incenter formula in actual math
    // for x: ax₁ + bx₂ + cx₃ / a + b + c
    // for y: ay₁ + by₂ + cy₃ / a + b + c

    printf("The incenter of points\nA " GRAY "(%.2f, %.2f)," RESET
    "\nB " GRAY "(%.2f, %.2f)," RESET "\nC " GRAY "(%.2f, %.2f)," RESET
    "\nis " BOLD "(%.4f, %.4f)" RESET, A[0], A[1], B[0], B[1], C[0], C[1], x, y);
}

int main(){

    srand(time(NULL));

    float randA[2] = {};
    float randB[2] = {};
    float randC[2] = {};

    // generating random floats to use with incenter()
    for (int i = 0; i < 2; i++){
        int randomNumber = rand() % (15 - 0 + 1) + 0;
        float randomFloat = (rand() % 2) * 0.50;
        float finalFloat = randomNumber + randomFloat;
        randA[i] = finalFloat;
    }

    for (int i = 0; i < 2; i++){
        int randomNumber = rand() % (15 - 0 + 1) + 0;
        float randomFloat = (rand() % 2) * 0.50;
        float finalFloat = randomNumber + randomFloat;
        randB[i] = finalFloat;
    }

    for (int i = 0; i < 2; i++){
        int randomNumber = rand() % (15 - 0 + 1) + 0;
        float randomFloat = (rand() % 2) * 0.50;
        float finalFloat = randomNumber + randomFloat;
        randC[i] = finalFloat;
    }
    // look man, use chatgpt or calculate it yourself if you're in the mood to fact check me

    float A[2] = {2.00, 1.00};
    float B[2] = {6.00, 4.00};
    float C[2] = {12.00, 1.00};

    // hypotenuse(3, 4); // float hypotenuse(float sidea, float sideb)
    // area_Triangle(3, 4); // float area_Triangle(float base, float height)
    // incenter(A, B, C); // float incenter(float A[2], float B[2], float C[2])
    // herons(4.50, 4.00, 3.102); // float herons(float sidea, float sideb, float sidec)
    //area_Circle(2.00); // float area_Circle(float radius)
    // distance(A, B); // float distance(float A[2], float B[2])

    slope(randA, randB);

    return 0;
}
