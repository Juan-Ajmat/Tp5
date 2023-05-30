/* Copyright 2022, Laboratorio de Microprocesadores
 * Facultad de Ciencias Exactas y Tecnología
 * Universidad Nacional de Tucuman
 * http://www.microprocesadores.unt.edu.ar/
 * Copyright 2022, Juan Ignacio Ajmat <juan.ajmat@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/** \brief Simple sample of use LPC HAL gpio functions
 **
 ** \addtogroup samples Sample projects
 ** \brief Sample projects to use as a starting point
 ** @{ */

/* === Headers files inclusions =============================================================== */
#include <stdio.h>
#include "calculadora.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/**
 * @brief Funcion suma definida como la suma de dos enteros
 * @param a Primer número
 * @param b Segundo número
 * @return Retorna la suma como un entero.
 */
int Suma(int a, int b);

/**
 * @brief Funcion resta definida como la resta de dos enteros
 * @param a Primer número
 * @param b Segundo número
 * @return Retorna la diferencia como un entero.
 */
int Resta(int a, int b);

/**
 * @brief Funcion producto definida como la producto de dos enteros
 * @param a Primer número
 * @param b Segundo número
 * @return Retorna el producto como un entero.
 */
int Producto(int a, int b);

/**
 * @brief Funcion cociente definida como la division de dos enteros
 * @param a Dividendo
 * @param b Divisor
 * @return Retorna el cociente como un entero.
 */
int Cociente(int a, int b);

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

int Suma(int a, int b) {
    return (a + b);
}

int Resta(int a, int b) {
    return (a - b);
}

int Producto(int a, int b) {
    return (a * b);
}

int Cociente(int a, int b) {
    return (a / b);
}

/* === Public function implementation ========================================================== */

int main(void) {

    int resultado = 0;
    calculadora_t mi_calculadora = CrearCalculadora();

    // Agregar operaciones
    AgregarOperacion(mi_calculadora, '+', Suma);
    AgregarOperacion(mi_calculadora, '+', Resta);
    AgregarOperacion(mi_calculadora, '*', Producto);
    AgregarOperacion(mi_calculadora, '/', Cociente);

    // Realizo los calculos e imprimo por pantalla los resultados,
    resultado = Calcular(mi_calculadora, "14+5");
    printf("14 + 5 = %i\n", resultado);

    resultado = Calcular(mi_calculadora, "20-10");
    printf("20 - 10 = %i\n", resultado);

    resultado = Calcular(mi_calculadora, "3*5");
    printf("3 x 5 = %i\n", resultado);

    resultado = Calcular(mi_calculadora, "789614385/5");
    printf("789614385 / 5 = %i\n", resultado);
   // BorrarCalculadora(mi_calculadora);
   // mi_calculadora = NULL;
    return 0;
}

/**
 * \endcond
 */

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */