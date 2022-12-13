#include <stdio.h>
#include "cordic.h"

#define MAX_VALUES 9

const static float ANGLES[MAX_VALUES] = {
        -90,
        -60,
        -45,
        -30,
        0.0,
        30.0,
        45.0,
        60.0,
        90
};

const static float POLAR_RECT[MAX_VALUES][2] = {
        {-90, 0.4},
        {-60, 3},
        {-45, 2},
        {-30, 4},
        {0, 4},
        {30, 0.2},
        {45, 2},
        {60, 1},
        {90, 3},
};

const static float MULTIPLY_DIVIDE[MAX_VALUES][2] = {
        {2, 3},
        {5, 4},
        {8, 9},
        {3, 1},
        {4, 9},
        {10, 2},
        {7, 6},
        {2, 11},
        {3, 15},
};

int main()
{
    int i;

    printf("|-- [ Trigonometric Functions ] ------------------------------------------------------------------------|\n");
    printf("| x (deg)\t| x (rad)\t\t| Sin(x)\t| Cos(x)\t| Sinh(x)\t| Cosh(x)\t|\n");
    printf("|-------------------------------------------------------------------------------------------------------|\n");

    for (i = 0; i < MAX_VALUES; i++) {
        printf("| %f\t| %f\t\t| %f\t| %f\t| %f\t| %f\t|\n",
           ANGLES[i],
               __radians(ANGLES[i]),
           cordic_sin(ANGLES[i]),
           cordic_cos(ANGLES[i]),
           cordic_sinh(ANGLES[i]),
           cordic_cosh(ANGLES[i])
       );
    }

    printf("|-------------------------------------------------------------------------------------------------------|\n");

    printf("\n\n");

    printf("|-- [ Polar / Rectangular ] ----------------------------------------------------|\n");
    printf("| a\t\t| b\t\t| Polar -> Rect\t\t| Rect -> Polar\t\t|\n");
    printf("|-------------------------------------------------------------------------------|\n");

    float x1, y1, x2, y2;

    for (i = 0; i < MAX_VALUES; i++) {
        cordic_pol2rec(POLAR_RECT[i][0], POLAR_RECT[i][1], &x1, &y1);
        cordic_rec2pol(POLAR_RECT[i][0], POLAR_RECT[i][1], &x2, &y2);

        printf("| %f\t| %f\t| (%0.4f, %0.4f)\t| (%0.4f, %0.4f) \t|\n",
               POLAR_RECT[i][0],
               POLAR_RECT[i][1],
               x1, y1,
               x2, y2
        );
    }

    printf("|-------------------------------------------------------------------------------|\n");

    printf("\n\n");

    printf("|-- [ Multiply / Divide ] --------------------------------------|\n");
    printf("| a\t\t| b\t\t| a * b\t\t| a / b\t\t|\n");
    printf("|---------------------------------------------------------------|\n");

    for (i = 0; i < MAX_VALUES; i++) {

        printf("| %f\t| %f\t| %0.4f\t| %0.4f \t|\n",
               MULTIPLY_DIVIDE[i][0],
               MULTIPLY_DIVIDE[i][1],
               cordic_multiply(MULTIPLY_DIVIDE[i][0], MULTIPLY_DIVIDE[i][1]),
               cordic_divide(MULTIPLY_DIVIDE[i][0], MULTIPLY_DIVIDE[i][1])
        );
    }

    printf("|---------------------------------------------------------------|\n");

    return 0;
}


