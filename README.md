# Portafolio: Clases y Algoritmos en C++

Repositorio de ejercicios enfocados en estructuras de datos y algoritmos clasicos, implementados en C++ para practica academica.

## Contenido del portafolio

### 1. Binary Search

Archivo: `BinarySearch/main.cpp`

Incluye dos funciones sobre un arreglo ordenado:
- `binarySearchPos`: retorna el indice de un valor objetivo.
- `binarySearchExiste`: retorna si el valor existe o no.

Complejidad:
- Tiempo: `O(log n)` por busqueda.
- Espacio: `O(1)`.

---

### 2. Segment Tree para minimo en rango

Archivo: `SegmentTree/forMin.cpp`

Implementa un Segment Tree con soporte para:
- Construccion del arbol (`build`).
- Actualizacion puntual (`update`).
- Consulta de minimo en rango (`query`).

Complejidad:
- Construccion: `O(n)`.
- Actualizacion: `O(log n)`.
- Consulta: `O(log n)`.

---

### 3. Segment Tree para suma en rango

Archivo: `SegmentTree/forSum.cpp`

Implementa un Segment Tree similar al anterior, pero para:
- Suma en rango.
- Actualizacion de un solo indice.

Complejidad:
- Construccion: `O(n)`.
- Actualizacion: `O(log n)`.
- Consulta: `O(log n)`.

---

### 4. Segment Tree para conteo de inversiones (en linea)

Archivo: `SegmentTree/inversion.cpp`

Procesa elementos y, para cada valor, calcula cuantas apariciones previas son mayores o iguales (segun el rango consultado) usando consultas y actualizaciones sobre Segment Tree.

Complejidad:
- Tiempo total aproximado: `O(n log n)`.
- Espacio: `O(n)`.

## Estructura del proyecto

```text
ClasesYAlgoritmos/
|- README.md
|- BinarySearch/
|  |- main.cpp
|- SegmentTree/
|  |- forMin.cpp
|  |- forSum.cpp
|  |- inversion.cpp
```

## Objetivo academico

Este portafolio muestra implementaciones base para entender:
- Busqueda binaria.
- Segment Tree para operaciones de rango.
- Analisis de complejidad temporal y espacial.

Es una base util para cursos de estructuras de datos, programacion competitiva y practica de algoritmos.
