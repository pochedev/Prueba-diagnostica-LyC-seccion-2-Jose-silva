#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generar_polinomio(int n, double x_val) {
    // Asignación de memoria dinámica para los coeficientes
    double *coef = (double *)malloc((n + 1) * sizeof(double));
    
    // Inicialización del Triángulo de Pascal (fila n)
    coef[0] = 1;
    for (int i = 1; i <= n; i++) {
        coef[i] = 0;
    }

    // Cálculo de coeficientes usando la propiedad de la fila anterior
    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 1; j--) {
            coef[j] = coef[j] + coef[j - 1];
        }
    }

    // a) Mostrar el polinomio generado
    printf("Polinomio f(x) = (x+1)^%d:\n", n);
    for (int i = n; i >= 0; i--) {
        if (coef[i] == 0) continue;
        printf("%.0f", coef[i]);
        if (i > 0) printf("x^%d + ", i);
    }
    printf("\n\n");

    // b) Cálculo paso a paso para x dado
    printf("Calculo para x = %.2f:\n", x_val);
    double resultado_total = 0;
    for (int i = n; i >= 0; i--) {
        double termino = coef[i];
        for (int j = 0; j < i; j++) termino *= x_val; // x^i
        
        printf("Paso %d: Coef[%d]*(%.2f)^%d = %.2f\n", n-i+1, i, x_val, i, termino);
        resultado_total += termino;
    }
    printf("Resultado final f(%.2f) = %.2f\n", x_val, resultado_total);

    free(coef); // Liberación de memoria
}

int main() {
    int n = 100; // Ejemplo corto para visualización
    double x = 2.0;
    
    clock_t start = clock();
    generar_polinomio(n, x);
    clock_t end = clock();
    
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    
    // Guardar en archivo para n=100
    FILE *f = fopen("resultado_c.txt", "w");
    fprintf(f, "Tiempo de ejecucion para n=100: %f segundos\n", time_spent);
    fclose(f);

    return 0;
}