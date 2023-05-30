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
#include <string.h>
#include <stdlib.h>
/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

typedef struct operacion_s * operacion_t;

struct calculadora_s {
    operacion_t operaciones;
};

struct operacion_s {
    char operador;
    funcion_t funcion;
    operacion_t siguiente;
};

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */


operacion_t BuscarOperacion(calculadora_t calculadora, char operador);

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

calculadora_t CrearCalculadora(void) {
    calculadora_t calculadora = malloc(sizeof(struct calculadora_s));
    if (calculadora) {
        memset(calculadora, 0, sizeof(struct calculadora_s));
    }
    return calculadora;
}

bool AgregarOperacion(calculadora_t calculadora, char operador, funcion_t funcion) {
    operacion_t operacion = NULL;

    if (!BuscarOperacion(calculadora, operador)) {
        operacion = malloc(sizeof(struct operacion_s));
    }
    if (operacion) {
        operacion->operador = operador;
        operacion->funcion = funcion;
        operacion->siguiente = calculadora->operaciones;
        calculadora->operaciones = operacion;
    }
    return (operacion != NULL);
}

operacion_t BuscarOperacion(calculadora_t calculadora, char operador) {
    operacion_t result = NULL;
    operacion_t actual = calculadora->operaciones;

    if (actual != NULL) {
        for (actual; actual != NULL; actual = actual->siguiente) {
            if (actual->operador == operador) {
                result = actual;
                break;
            }
        }
    }
    return result;
}

int Calcular(calculadora_t calculadora, char * cadena) {
    int a, b;
    char operador;
    int resultado = 0;
    operacion_t operacion = NULL;

    for (int index = 0; index < strlen(cadena); index++) {
        if (cadena[index] < '0') {
            operador = cadena[index];
            a = atoi(cadena);
            b = atoi(cadena + index + 1);
            break;
        }
    }

    operacion = BuscarOperacion(calculadora, operador);
    if (operacion) {
        resultado = operacion->funcion(a, b);
    }

    return resultado;
}

/* === Public function implementation ========================================================== */

/**
 * \endcond
 */

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */