//
// Created by fabio on 11/12/2022.
//

#ifndef CORDIC_CORDIC_H
#define CORDIC_CORDIC_H

#include <stdint.h>

// Parameters
#define RESOLUTION 16
#define GAIN_DEFAULT 0.607252935
#define GAIN_HYPERBOLIC 1.20749706

#define METHOD_LINEAR 0
#define METHOD_CIRCULAR 1
#define METHOD_HYPERBOLIC 2

#define MODE_ROTATION 0
#define MODE_VECTORING 1

// Public functions
float cordic_sin(float angle);
float cordic_cos(float angle);
float cordic_sinh(float angle);
float cordic_cosh(float angle);
float cordic_divide(float a, float b);
float cordic_multiply(float a, float b);
void cordic_pol2rec(float angle, float radius, float * x, float * y);
void cordic_rec2pol(float a, float b, float * x, float * y);

// Internal functions

/**
 * Cordic engine algorithm
 *
 * @param int16_t x
 * @param int16_t y
 * @param int16_tz
 * @param short method
 * @param short mode
 */
void __cordic(
        int16_t * x,
        int16_t * y,
        int16_t * z,
        int16_t method,
        int16_t mode
);

/**
 * Converts a integer value
 * to an equivalent in float type
 */
double __decimal(int16_t value);

/**
 * Converts a float value
 * to an equivalent in int type
 */
int16_t __int(float value);

/**
 * Converts a degree value into radian
 *
 * @param float degree
 * @return float
 */
float __radians(float degree);

/**
 * Returns the direction to CORDIC
 *
 * @param int16_t x
 * @param int16_t y
 * @param int16_t z
 * @param short   mode
 */
int16_t __d(int16_t x, int16_t y, int16_t z, int16_t mode);

#endif //CORDIC_CORDIC_H
