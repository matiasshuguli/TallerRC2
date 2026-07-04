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

void buscarOrden(Orden ordenes[], int cantidad) {
    char datoBuscado[50];
    int i;
    int encontrado;

    encontrado = 0;

    if (cantidad == 0) {
        printf("\nNo hay ordenes para buscar.\n");
    } else {
        printf("\nIngrese el codigo o parte del nombre del cliente: ");
        leerCadena(datoBuscado, 50);

        printf("\n--- Resultados de busqueda ---\n");

        for (i = 0; i < cantidad; i++) {
            if (strcmp(ordenes[i].codigo_orden, datoBuscado) == 0 ||
                strstr(ordenes[i].nombre_cliente, datoBuscado) != NULL) {

                printf("\nOrden encontrada\n");
                printf("Codigo: %s\n", ordenes[i].codigo_orden);
                printf("Cliente: %s\n", ordenes[i].nombre_cliente);
                printf("Equipo: %s\n", ordenes[i].equipo);
                printf("Tipo de trabajo: %s\n", ordenes[i].tipo_trabajo);
                printf("Costo base: %.2f\n", ordenes[i].costo_base);
                printf("Horas de trabajo: %d\n", ordenes[i].horas_trabajo);
                printf("Costo total: %.2f\n", calcularCostoTotal(ordenes[i]));
                printf("-----------------------------\n");

                encontrado = 1;
            }
        }

        if (encontrado == 0) {
            printf("No se encontro ninguna orden.\n");
        }
    }
}

void actualizarOrden(Orden ordenes[], int cantidad) {
    char codigo[16];
    int i;
    int posicion;
    int encontrado;
    int opcion;

    encontrado = 0;
    posicion = 0;

    if (cantidad == 0) {
        printf("\nNo hay ordenes para actualizar.\n");
    } else {
        printf("\nIngrese el codigo de la orden a actualizar: ");
        leerCadena(codigo, 16);

        for (i = 0; i < cantidad; i++) {
            if (strcmp(ordenes[i].codigo_orden, codigo) == 0) {
                encontrado = 1;
                posicion = i;
            }
        }

        if (encontrado == 0) {
            printf("No se encontro la orden.\n");
        } else {
            do {
                printf("\n--- Actualizar orden ---\n");
                printf("1. Nombre del cliente\n");
                printf("2. Equipo\n");
                printf("3. Tipo de trabajo\n");
                printf("4. Costo base\n");
                printf("5. Horas de trabajo\n");
                printf("6. Salir de actualizacion\n");
                printf("Seleccione una opcion: ");
                scanf("%d", &opcion);
                getchar();

                switch (opcion) {
                    case 1:
                        printf("Nuevo nombre del cliente: ");
                        leerCadena(ordenes[posicion].nombre_cliente, 50);
                        printf("Nombre actualizado.\n");
                        break;

                    case 2:
                        printf("Nuevo equipo: ");
                        leerCadena(ordenes[posicion].equipo, 40);
                        printf("Equipo actualizado.\n");
                        break;

                    case 3:
                        printf("Nuevo tipo de trabajo: ");
                        leerCadena(ordenes[posicion].tipo_trabajo, 60);
                        printf("Tipo de trabajo actualizado.\n");
                        break;

                    case 4:
                        do {
                            printf("Nuevo costo base: ");
                            scanf("%f", &ordenes[posicion].costo_base);
                            getchar();

                            if (ordenes[posicion].costo_base <= 0) {
                                printf("El costo base debe ser mayor a 0.\n");
                            }

                        } while (ordenes[posicion].costo_base <= 0);

                        printf("Costo base actualizado.\n");
                        break;

                    case 5:
                        do {
                            printf("Nuevas horas de trabajo: ");
                            scanf("%d", &ordenes[posicion].horas_trabajo);
                            getchar();

                            if (ordenes[posicion].horas_trabajo < 0) {
                                printf("Las horas no pueden ser negativas.\n");
                            }

                        } while (ordenes[posicion].horas_trabajo < 0);

                        printf("Horas actualizadas.\n");
                        break;

                    case 6:
                        printf("Saliendo de actualizacion.\n");
                        break;

                    default:
                        printf("Opcion no valida.\n");
                        break;
                }

            } while (opcion != 6);
        }
    }
}

void eliminarOrden(Orden ordenes[], int *cantidad) {
    char codigo[16];
    char respuesta;
    int i;
    int posicion;
    int encontrado;

    encontrado = 0;
    posicion = 0;

    if (*cantidad == 0) {
        printf("\nNo hay ordenes para eliminar.\n");
    } else {
        printf("\nIngrese el codigo de la orden a eliminar: ");
        leerCadena(codigo, 16);

        for (i = 0; i < *cantidad; i++) {
            if (strcmp(ordenes[i].codigo_orden, codigo) == 0) {
                encontrado = 1;
                posicion = i;
            }
        }

        if (encontrado == 0) {
            printf("No se encontro la orden.\n");
        } else {
            printf("\nOrden encontrada:\n");
            printf("Codigo: %s\n", ordenes[posicion].codigo_orden);
            printf("Cliente: %s\n", ordenes[posicion].nombre_cliente);
            printf("Equipo: %s\n", ordenes[posicion].equipo);
            printf("Tipo de trabajo: %s\n", ordenes[posicion].tipo_trabajo);
            printf("Costo base: %.2f\n", ordenes[posicion].costo_base);
            printf("Horas de trabajo: %d\n", ordenes[posicion].horas_trabajo);
            printf("Costo total: %.2f\n", calcularCostoTotal(ordenes[posicion]));

            printf("\nEsta seguro que desea eliminar esta orden? (s/n): ");
            scanf("%c", &respuesta);
            getchar();

            if (respuesta == 's' || respuesta == 'S') {
                for (i = posicion; i < *cantidad - 1; i++) {
                    ordenes[i] = ordenes[i + 1];
                }

                *cantidad = *cantidad - 1;

                printf("Orden eliminada correctamente.\n");
            } else {
                printf("Eliminacion cancelada.\n");
            }
        }
    }
}

/* Estas funciones se completan en el siguiente commit */

void guardarCSV(Orden ordenes[], int cantidad) {
    printf("\nFuncion de guardado pendiente.\n");
}

void cargarCSV(Orden ordenes[], int *cantidad) {
    printf("\nFuncion de carga pendiente.\n");
}