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

//  ̶T̶O̶D̶O̶ ̶(̶c̶o̶d̶e̶-̶w̶i̶d̶e̶)̶:̶ ̶f̶i̶x̶ ̶f̶u̶n̶c̶t̶i̶o̶n̶s̶ ̶t̶o̶ ̶N̶O̶T̶ ̶p̶r̶i̶n̶t̶ ̶a̶ ̶w̶h̶o̶l̶e̶ ̶s̶e̶n̶t̶e̶n̶c̶e̶.̶ ̶w̶h̶y̶ ̶d̶i̶d̶ ̶i̶ ̶t̶h̶i̶n̶k̶ ̶t̶h̶a̶t̶ ̶w̶a̶s̶ ̶a̶ ̶g̶o̶o̶d̶ ̶i̶d̶e̶a̶?̶  => FIXED!!! 
typedef struct
{
    float a[2];
    float b[2];
    float c[2];
} randNumbers;


randNumbers randomPoints(){
    // generating random points

    randNumbers rnums;

    for (int i = 0; i < 2; i++) {
        int randomNumber = rand() % 16;
        float randomFloat = ((float)rand() / RAND_MAX) * 0.5;
        float finalFloat = randomNumber + randomFloat;
        rnums.a[i] = finalFloat;
    }

    for (int i = 0; i < 2; i++) {
        int randomNumber = rand() % 16;
        float randomFloat = ((float)rand() / RAND_MAX) * 0.5;
        float finalFloat = randomNumber + randomFloat;
        rnums.b[i] = finalFloat;
    }

    for (int i = 0; i < 2; i++) {
        int randomNumber = rand() % 16;
        float randomFloat = ((float)rand() / RAND_MAX) * 0.5;
        float finalFloat = randomNumber + randomFloat;
        rnums.c[i] = finalFloat;
    }

    return rnums;
}

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
    return h;
}

float area_Triangle(float base, float height){
    float area = (base + height) / 2;

    // area of a triangle through base and height
    // b * h * 1/2

    return area;
}

float slope(float A[2], float B[2]){
    float s = (B[1] - A[1]) / (B[0] - A[0]);
    return s;
}

float circumference(float radius){

    float c = 2 * 3.14159 * radius;

    // circumference of a circle formula in actual math:
    // c = 2πr

    return c;
}

float herons(float sidea, float sideb, float sidec){
    float s = (sidea + sideb + sidec) / 2;
    float a = sqrt((s * (s - sidea) * (s - sideb) * (s - sidec)));

    // herons is used to find area through 3 sides of the triangle
    // herons formula in actual math
    // note that s is half of the perimeter
    // area = √s(s - a)(s - b)(s - c)

    return a;
}

float distance(float A[2], float B[2]){

    float step1 = (B[0] - A[0]) * (B[0] - A[0]);
    float step2 = (B[1] - A[1]) * (B[1] - A[1]);
    float d = sqrt((step1 + step2));

    // distance formula in actual math
    // d = √(x₂ - x₁)² + (y₂ - y₁)²

    return d;
}

typedef struct
{
    float x;
    float y;
} Points;


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

    printf("(%f, %f)\n", x, y);
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

    printf("(%f, %f), (%f, %f), (%f, %f)\n", A[0], A[1], B[0], B[1], C[0], C[1]);

    float s1 = (B[1] - A[1]) / (B[0] - A[0]);
    float s2 = (C[1] - B[1]) / (C[0] - B[0]);
    float s3 = (A[1] - C[1]) / (A[0] - C[0]);

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

    float b1 = mid_sidea_y - NEG_slope_sidea * mid_sidea_x; // y-intercept of line 1
    float b2 = mid_sideb_y - NEG_slope_sideb * mid_sideb_x; // y-intercept of line 2


    float circumcenter_x = (b2 - b1) / (NEG_slope_sidea - NEG_slope_sideb);
    float circumcenter_y = NEG_slope_sidea * circumcenter_x + b1;

    /*
    printf("y - %f = %f(x - %f)\n", mid_sidea_y, NEG_slope_sidea, mid_sidea_x);
    printf("y - %f = %f(x - %f)\n", mid_sideb_y, NEG_slope_sideb, mid_sideb_x);
    printf("y - %f = %f(x - %f)\n", mid_sidec_y, NEG_slope_sidec, mid_sidec_x);
    */

   printf("(%f, %f)\n", circumcenter_x, circumcenter_y);
}

int main(){

    srand(time(NULL));

    randNumbers randset = randomPoints();

    float A[2] = {0, 10};
    float B[2] = {6, 9};
    float C[2] = {3, 2};
    float D[2] = {3, 9.5};
    float E[2] = {3.1252,7.4281};

    circumcenter(randset.a, randset.b, randset.c);
    incenter(randset.a, randset.b, randset.c);

    return 0;
}
