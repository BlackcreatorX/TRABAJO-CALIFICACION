#include <stdio.h>
#include <stdlib.h>
#include "Calificaciones.h"
#include "promedio.h"

void menu();
void mostrarCalificaciones(Calificaciones *cal);
float calcularPromedioTotal(Calificaciones *cal);

int main() {
    menu();
    return 0;
}

void menu() {
    Calificaciones cal;
    float cantidad;
    int opcion = 0;
    float promedio = 0;
    int calificacionesIngresadas = 0; // Bandera para verificar si hay datos

    do {
        printf("\n=== Calculadora de Promedios ===\n");
        printf("1. Ingresar calificaciones\n");
        printf("2. Mostrar calificaciones\n");
        printf("3. Calcular promedio\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese la cantidad de materias: ");
                scanf("%f", &cantidad);
                inicializarCalificaciones(&cal, cantidad);
                ingresarCalificaciones(&cal);
                calificacionesIngresadas = 1;
                break;
            case 2:
                if (calificacionesIngresadas) {
                    mostrarCalificaciones(&cal);
                } else {
                    printf("Primero debe ingresar calificaciones.\n");
                }
                break;
            case 3:
                if (calificacionesIngresadas) {
                    promedio = calcularPromedioTotal(&cal);
                    printf("El promedio general es: %.2f\n", promedio);
                } else {
                    printf("Primero debe ingresar calificaciones.\n");
                }
                break;
            case 4:
                if (calificacionesIngresadas) {
                    liberarCalificaciones(&cal);
                }
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 4);
}

void mostrarCalificaciones(Calificaciones *cal) {
    printf("\n--- Calificaciones ingresadas ---\n");
    for (int i = 0; i < cal->num_materias; i++) {
        printf("Materia %d: %.2f\n", i + 1, cal->calificaciones[i]);
    }
}

float calcularPromedioTotal(Calificaciones *cal) {
    float suma = 0;
    for (int i = 0; i < cal->num_materias; i++) {
        suma += cal->calificaciones[i];
    }
    return suma / cal->num_materias;
}