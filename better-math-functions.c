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

void swap(float point1[2], float point2[2]) {
    float butter[2]; // this was going to say buffer but i kept typing butter so it's butter now.
    butter[0] = point1[0];
    butter[1] = point1[1];
    point1[0] = point2[0];
    point1[1] = point2[1];
    point2[0] = butter[0];
    point2[1] = butter[1];
}

float midpoint(float A[2], float B[2]){
    float mid_x = (A[0] + B[0]) / 2.00;
    float mid_y = (A[1] + B[1]) / 2.00;
    float m[2] = {mid_x, mid_y};

    return m[0], m[1];
}

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

    printf("The distance between points (%.2f, %.2f) and (%.2f, %.2f) is" BOLD " %f" RESET, A[0], A[1], B[0], B[1], d);
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
    // look man, use chatgpt or calculate it yourself if you're in the mood to fact check me
}

float circumcenter(float A[2], float B[2], float C[2]){

    if (A[0] > B[0] || (A[0] == B[0] && A[1] > B[1])) {
        swap(A, B);
    }
    if (B[0] > C[0] || (B[0] == C[0] && B[1] > C[1])) {
        swap(B, C);
    }
    if (A[0] > B[0] || (A[0] == B[0] && A[1] > B[1])) {
        swap(A, B);
    }

    printf("(%.4f, %.4f), (%.4f, %.4f), (%.4f, %.4f)\n", A[0], A[1], B[0], B[1], C[0], C[1]);

    float s1 = (B[1] - A[1]) / (B[0] - A[0]);
    float s2 = (C[1] - B[1]) / (C[0] - B[0]);
    float s3 = (A[1] - C[1]) / (A[0] - C[0]);

    printf("y - %f = %f(x - %f) {%f < x < %f}\n", A[1], s1, A[0], A[0], B[0]);
    printf("y - %f = %f(x - %f) {%f < x < %f}\n", B[1], s2, B[0], B[0], C[0]);
    printf("y - %f = %f(x - %f) {%f < x < %f}\n", C[1], s3, C[0], A[0], C[0]);

    float mp_sidea = midpoint(A, B);

    float mid_sidea_x = (A[0] + B[0]) / 2.00;
    float mid_sidea_y = (A[1] + B[1]) / 2.00;

    float mp_sideb = midpoint(B, C);

    float mid_sideb_x = (B[0] + C[0]) / 2.00;
    float mid_sideb_y = (B[1] + C[1]) / 2.00;

    float mp_sidec = midpoint(C, A);

    float mid_sidec_x = (C[0] + A[0]) / 2.00;
    float mid_sidec_y = (C[1] + A[1]) / 2.00;

    float slope_sidea = (B[1] - A[1]) / (B[0] - A[0]);
    float slope_sideb = (C[1] - B[1]) / (C[0] - B[0]);
    float slope_sidec = (A[1] - C[1]) / (A[0] - C[0]);

    float NEG_slope_sidea = -1.0 / slope_sidea;
    float NEG_slope_sideb = -1.0 / slope_sideb;
    float NEG_slope_sidec = -1.0 / slope_sidec;

    /* printf("%f\n", slope_sidea);
    printf("%f\n", slope_sideb);
    printf("%f", slope_sidec); */

    printf("y - %f = %f(x - %f)\n", mid_sidea_y, NEG_slope_sidea, mid_sidea_x);
    printf("y - %f = %f(x - %f)\n", mid_sideb_y, NEG_slope_sideb, mid_sideb_x);
    printf("y - %f = %f(x - %f)\n", mid_sidec_y, NEG_slope_sidec, mid_sidec_x);

}

int main(){

    srand(time(NULL));

    float randA[2] = {};
    float randB[2] = {};
    float randC[2] = {};

    // generating random points
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

    float A[2] = {0.0000,14.5000};
    float B[2] = {4.0000,15.5000};
    float C[2] = {10, 14};

    // hypotenuse(3, 4); // float hypotenuse(float sidea, float sideb)
    // area_Triangle(3, 4); // float area_Triangle(float base, float height)
    // incenter(A, B, C); // float incenter(float A[2], float B[2], float C[2])
    // herons(4.50, 4.00, 3.102); // float herons(float sidea, float sideb, float sidec)
    //area_Circle(2.00); // float area_Circle(float radius)
    // distance(A, B); // float distance(float A[2], float B[2])
    // printf("MIDPOINT: (%f, %f)", midpoint(A, B));

    circumcenter(randA, randB, randC);

    return 0;
}
