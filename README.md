<div align="right">
<img width="32px" src="img/algo2.svg">
</div>

# NOMBRE TP/TDA

## Repositorio de Renata Bruno - 106860 - rc.brunoo@gmail.com

- Para compilar:

```bash
gcc -o pruebas_alumno pruebas_alumno.c
```

- Para ejecutar:

```bash
./pruebas_alumno 
```

- Para ejecutar con valgrind:
```bash
valgrind ./pruebas_alumno 
```
---
##  Funcionamiento

Explicación de cómo funcionan las estructuras desarrolladas en el TP y el funcionamiento general del mismo.

Aclarar en esta parte todas las decisiones que se tomaron al realizar el TP, cosas que no se aclaren en el enunciado, fragmentos de código que necesiten explicación extra, etc.

Incluír **EN TODOS LOS TPS** los diagramas relevantes al problema (mayormente diagramas de memoria para explicar las estructuras, pero se pueden utilizar otros diagramas si es necesario).

---

## Respuestas a las preguntas teóricas
- ¿Qué es una lista/pila/cola? Explicar con diagramas.
Una lista es una estructura de datos que permite almacenar datos de manera secuencial. Cada elemento de la lista tiene un dato y un puntero al siguiente elemento de la lista. 

<div align="center">
<img width="70%" src="img/diagrama.png">
</div>

Una pila es una estructura de datos que permite almacenar datos de manera secuencial. Cada elemento de la pila tiene un dato y un puntero al siguiente elemento de la pila. La diferencia con la lista es que la pila solo permite agregar y quitar elementos por el mismo extremo, el tope de la pila.

<div align="center">
<img width="70%" src="img/diagrama.png">
</div>

Una cola es una estructura de datos que permite almacenar datos de manera secuencial. Cada elemento de la cola tiene un dato y un puntero al siguiente elemento de la cola. La diferencia con la lista es que la cola solo permite agregar elementos por un extremo, el final de la cola, y quitar elementos por el otro extremo, el principio de la cola.

<div align="center">
<img width="70%" src="img/diagrama.png">
</div>

