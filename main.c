#include <stdio.h>
#include "ordenes.h"

int main() {
    Orden ordenes[100];
    int cantidad = 0;
    int opcion;

    cargarCSV(ordenes, &cantidad);

    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1. Registrar orden\n");
        printf("2. Listar ordenes\n");
        printf("3. Buscar orden\n");
        printf("4. Actualizar orden\n");
        printf("5. Eliminar orden\n");
        printf("6. Guardar cambios en archivo\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1:
                registrarOrden(ordenes, &cantidad);
                break;

            case 2:
                listarOrdenes(ordenes, cantidad);
                break;

            case 3:
                buscarOrden(ordenes, cantidad);
                break;

            case 4:
                actualizarOrden(ordenes, cantidad);
                break;

            case 5:
                eliminarOrden(ordenes, &cantidad);
                break;

            case 6:
                guardarCSV(ordenes, cantidad);
                break;

            case 7:
                guardarCSV(ordenes, cantidad);
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion no valida.\n");
                break;
        }

    } while (opcion != 7);

    return 0;
}