// calificaciones.h
#ifndef Calificaciones_H
#define Calificaciones_H

#include <stdio.h>
#include <stdlib.h>

// Estructura para almacenar calificaciones
typedef struct {
    float *calificaciones;  // Array dinámico de calificaciones
    int num_materias;       // Número de materias (se convierte de float a int)
} Calificaciones;

// Inicializa la estructura con memoria dinámica
void inicializarCalificaciones(Calificaciones *cal, float cantidad_materias) {
    cal->num_materias = (int)cantidad_materias;  // Conversión de float a int
    cal->calificaciones = (float *)malloc(cal->num_materias * sizeof(float));
    
    if (cal->calificaciones == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria.\n");
        exit(EXIT_FAILURE);
    }
}

// Pide al usuario ingresar las calificaciones
void ingresarCalificaciones(Calificaciones *cal) {
    printf("Ingrese las calificaciones de %d materias:\n", cal->num_materias);
    for (int i = 0; i < cal->num_materias; i++) {
        printf("Calificación materia %d: ", i + 1);
        scanf("%f", &cal->calificaciones[i]);
        
        // Validación (0.0 - 10.0)
        while (cal->calificaciones[i] < 0.0f || cal->calificaciones[i] > 10.0f) {
            printf("Error: La calificación debe estar entre 0.0 y 10.0. Reintente: ");
            scanf("%f", &cal->calificaciones[i]);
        }
    }
}

// Libera la memoria asignada
void liberarCalificaciones(Calificaciones *cal) {
    free(cal->calificaciones);
    cal->calificaciones = NULL;
    cal->num_materias = 0;
}

#endif // CALIFICACIONES_H