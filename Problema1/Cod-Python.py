import time

def resolver_polinomio(n, x_val):
    start_time = time.time()
    
    # Generación de coeficientes (Triángulo de Pascal)
    # En Python, las listas son arreglos dinámicos
    coeficientes = [1]
    for _ in range(n):
        nueva_fila = [1]
        for j in range(len(coeficientes) - 1):
            nueva_fila.append(coeficientes[j] + coeficientes[j+1])
        nueva_fila.append(1)
        coeficientes = nueva_fila

    # a) Mostrar polinomio
    polinomio_str = " + ".join([f"{c}x^{n-i}" if n-i > 0 else f"{c}" 
                               for i, c in enumerate(coeficientes)])
    print(f"Polinomio generado:\nf(x) = {polinomio_str}\n")

    # b) Cálculo paso a paso
    print(f"Cálculo para x = {x_val}:")
    suma_total = 0
    for i, c in enumerate(coeficientes):
        exponente = n - i
        valor_termino = c * (x_val ** exponente)
        suma_total += valor_termino
        print(f"  Término {i+1}: {c} * ({x_val})^{exponente} = {valor_termino}")

    end_time = time.time()
    duracion = end_time - start_time

    # Escritura en archivo txt
    with open("resultado_python.txt", "w") as f:
        f.write(f"Resultados para n={n}\n")
        f.write(f"Tiempo de ejecución: {duracion:.10f} segundos\n")
        f.write(f"Suma total: {suma_total}\n")

    return duracion

# Ejecución para n=100 (como pide el enunciado)
ejecutar = resolver_polinomio(100, 2)
