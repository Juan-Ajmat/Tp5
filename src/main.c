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

int Suma(int a, int b);

int Resta(int a, int b);

int Producto(int a, int b);

int Cociente(int a, int b);

/* === Public variable definitions ============================================================= */
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
/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */


/* === Public function implementation ========================================================== */

int main(void) {

    int resultado = 0;
    
    calculadora_t mi_calculadora = CrearCalculadora();

    
    AgregarOperacion(mi_calculadora, '+', Suma);
    AgregarOperacion(mi_calculadora, '-', Resta);
    AgregarOperacion(mi_calculadora, '*', Producto);
    AgregarOperacion(mi_calculadora, '/', Cociente);

   
    resultado = Calcular(mi_calculadora, "10+2");
    printf("El resultado de la suma es:\n 10 + 2 = %i\n", resultado);

    resultado = Calcular(mi_calculadora, "10-2");
    printf("El resultado de la resta es:\n 10 - 2 = %i\n", resultado);

    resultado = Calcular(mi_calculadora, "10*2");
    printf("El resultado de la multiplicación es:\n 10 x 2 = %i\n", resultado);

    resultado = Calcular(mi_calculadora, "10/2");
    printf("El resultado de la division es:\n 10 / 2 = %i\n", resultado);

    return 0;
}

/**
 * \endcond
 */

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */