#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

#include <stdint.h>

/* Fator de escala para a fração 17.14 (2^14 = 16384) */
#define FP_SHIFT 14
#define FP_F (1 << FP_SHIFT)

/* Tipos definidos para clareza no código */
typedef int fixed_point_t;

/* Converte inteiro n para ponto fixo */
static inline fixed_point_t int_to_fp(int n) {
    return n * FP_F;
}

/* Converte ponto fixo x para inteiro (truncando casas decimais) */
static inline int fp_to_int_trunc(fixed_point_t x) {
    return x / FP_F;
}

/* Converte ponto fixo x para inteiro (arredondando para o mais próximo) */
static inline int fp_to_int_round(fixed_point_t x) {
    if (x >= 0)
        return (x + FP_F / 2) / FP_F;
    else
        return (x - FP_F / 2) / FP_F;
}

/* Soma de dois números em ponto fixo (x + y) */
static inline fixed_point_t fp_add(fixed_point_t x, fixed_point_t y) {
    return x + y;
}

/* Subtração de dois números em ponto fixo (x - y) */
static inline fixed_point_t fp_sub(fixed_point_t x, fixed_point_t y) {
    return x - y;
}

/* Soma de ponto fixo x com inteiro n (x + n) */
static inline fixed_point_t fp_add_int(fixed_point_t x, int n) {
    return x + n * FP_F;
}

/* Subtração de inteiro n de ponto fixo x (x - n) */
static inline fixed_point_t fp_sub_int(fixed_point_t x, int n) {
    return x - n * FP_F;
}

/* Multiplicação de ponto fixo x por inteiro n (x * n) */
static inline fixed_point_t fp_mul_int(fixed_point_t x, int n) {
    return x * n;
}

/* Multiplicação de dois números em ponto fixo (x * y) */
static inline fixed_point_t fp_mul(fixed_point_t x, fixed_point_t y) {
    return (fixed_point_t) (((int64_t) x) * y / FP_F);
}

/* Divisão de ponto fixo x por inteiro n (x / n) */
static inline fixed_point_t fp_div_int(fixed_point_t x, int n) {
    return x / n;
}

/* Divisão de dois números em ponto fixo (x / y) */
static inline fixed_point_t fp_div(fixed_point_t x, fixed_point_t y) {
    return (fixed_point_t) (((int64_t) x) * FP_F / y);
}

#endif /* threads/fixed-point.h */
