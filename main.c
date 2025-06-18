#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "funx.h"

void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int opcion = 0;
    do {
        printf("=== Calculadora de Promedios ===\n");
        printf("1. Ingresar calificaciones (placeholder)\n");
        printf("2. Mostrar calificaciones (placeholder)\n");
        printf("3. Calcular promedio (placeholder)\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("[Placeholder] Aquí se ingresarán las calificaciones.\n\n");
                break;
            case 2:
                printf("[Placeholder] Aquí se mostrarán las calificaciones.\n\n");
                break;
            case 3:
                printf("[Placeholder] Aquí se calculará el promedio.\n\n");
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n\n");
        }
    } while (opcion != 4);
}
