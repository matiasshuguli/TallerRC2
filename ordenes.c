#include <stdio.h>
#include <string.h>
#include "ordenes.h"

void leerCadena(char cadena[], int tamano) {
    fgets(cadena, tamano, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
}

float calcularCostoTotal(Orden orden) {
    float total;

    total = orden.costo_base + (orden.horas_trabajo * 10);

    return total;
}

void registrarOrden(Orden ordenes[], int *cantidad) {
    Orden nueva;
    int i;
    int repetido;

    if (*cantidad >= 100) {
        printf("No se pueden registrar mas ordenes.\n");
    } else {
        printf("\n--- Registrar orden ---\n");

        do {
            repetido = 0;

            printf("Codigo de orden: ");
            leerCadena(nueva.codigo_orden, 16);

            for (i = 0; i < *cantidad; i++) {
                if (strcmp(ordenes[i].codigo_orden, nueva.codigo_orden) == 0) {
                    repetido = 1;
                }
            }

            if (repetido == 1) {
                printf("Ese codigo ya existe. Ingrese otro.\n");
            }

        } while (repetido == 1);

        printf("Nombre del cliente: ");
        leerCadena(nueva.nombre_cliente, 50);

        printf("Equipo: ");
        leerCadena(nueva.equipo, 40);

        printf("Tipo de trabajo: ");
        leerCadena(nueva.tipo_trabajo, 60);

        do {
            printf("Costo base: ");
            scanf("%f", &nueva.costo_base);
            getchar();

            if (nueva.costo_base <= 0) {
                printf("El costo base debe ser mayor a 0.\n");
            }

        } while (nueva.costo_base <= 0);

        do {
            printf("Horas de trabajo: ");
            scanf("%d", &nueva.horas_trabajo);
            getchar();

            if (nueva.horas_trabajo < 0) {
                printf("Las horas no pueden ser negativas.\n");
            }

        } while (nueva.horas_trabajo < 0);

        ordenes[*cantidad] = nueva;
        *cantidad = *cantidad + 1;

        printf("Orden registrada correctamente.\n");
    }
}

void listarOrdenes(Orden ordenes[], int cantidad) {
    int i;

    if (cantidad == 0) {
        printf("\nNo hay ordenes registradas.\n");
    } else {
        printf("\n--- Lista de ordenes ---\n");

        for (i = 0; i < cantidad; i++) {
            printf("\nOrden #%d\n", i + 1);
            printf("Codigo: %s\n", ordenes[i].codigo_orden);
            printf("Cliente: %s\n", ordenes[i].nombre_cliente);
            printf("Equipo: %s\n", ordenes[i].equipo);
            printf("Tipo de trabajo: %s\n", ordenes[i].tipo_trabajo);
            printf("Costo base: %.2f\n", ordenes[i].costo_base);
            printf("Horas de trabajo: %d\n", ordenes[i].horas_trabajo);
            printf("Costo total: %.2f\n", calcularCostoTotal(ordenes[i]));
            printf("-----------------------------\n");
        }
    }
}

/* Estas funciones se completan en los siguientes commits */

void buscarOrden(Orden ordenes[], int cantidad) {
    printf("\nFuncion de busqueda pendiente.\n");
}

void actualizarOrden(Orden ordenes[], int cantidad) {
    printf("\nFuncion de actualizacion pendiente.\n");
}

void eliminarOrden(Orden ordenes[], int *cantidad) {
    printf("\nFuncion de eliminacion pendiente.\n");
}

void guardarCSV(Orden ordenes[], int cantidad) {
    printf("\nFuncion de guardado pendiente.\n");
}

void cargarCSV(Orden ordenes[], int *cantidad) {
    printf("\nFuncion de carga pendiente.\n");
}