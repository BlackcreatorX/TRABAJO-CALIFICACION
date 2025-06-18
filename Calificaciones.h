#ifndef Calificaciones_H
#define Calificaciones_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float *calificaciones;
    int num_materias;
} Calificaciones;

void inicializarCalificaciones(Calificaciones *cal, float cantidad_materias) {
    cal->num_materias = (int)cantidad_materias;
    cal->calificaciones = (float *)malloc(cal->num_materias * sizeof(float));
    
    if (cal->calificaciones == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria.\n");
        exit(EXIT_FAILURE);
    }
}

void ingresarCalificaciones(Calificaciones *cal) {
    printf("Ingrese las calificaciones de %d materias:\n", cal->num_materias);
    for (int i = 0; i < cal->num_materias; i++) {
        printf("Calificación materia %d: ", i + 1);
        scanf("%f", &cal->calificaciones[i]);
        
        while (cal->calificaciones[i] < 0.0f || cal->calificaciones[i] > 10.0f) {
            printf("Error: La calificación debe estar entre 0.0 y 10.0. Reintente: ");
            scanf("%f", &cal->calificaciones[i]);
        }
    }
}

void liberarCalificaciones(Calificaciones *cal) {
    free(cal->calificaciones);
    cal->calificaciones = NULL;
    cal->num_materias = 0;
}

#endif