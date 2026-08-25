# cub3D

## Descripción

**cub3D** es un motor de juego en 3D implementado en C. El objetivo del proyecto es recrear desde cero un explorador de laberintos gráfico al estilo de *Wolfenstein 3D*, introduciéndonos en las matemáticas del Raycasting y en el uso práctico de una librería gráfica (MLX42).

El motor procesa un archivo de configuración de mapa para construir una cuadrícula 2D y utiliza el algoritmo Digital Differential Analysis (DDA) para trazar rayos desde la perspectiva del jugador, calculando distancias para renderizar un entorno en pseudo-3D. Cuenta con una estricta validación de mapas, mapeo dinámico de texturas, colisiones con deslizamiento por paredes, movimiento diagonal fluido y una gestión de memoria robusta mediante un Garbage Collector propio.

### Características principales

- **Motor de Raycasting:** Utiliza el algoritmo DDA para renderizar una perspectiva 3D a partir de un mapa 2D en tiempo real.
- **Validación estricta de mapas:** Parsea archivos `.cub`, validando colores, rutas de texturas y asegurando que el mapa esté completamente cerrado mediante una combinación de escaneo de matrices y un algoritmo recursivo Flood Fill.
- **Mapeo de texturas:** Renderizado dinámico de diferentes texturas `.png` según la orientación cardinal del muro (Norte, Sur, Este, Oeste).
- **Movimiento fluido:** Implementación matemática sin bifurcaciones (*branchless*) para gestionar la entrada de múltiples teclas, permitiendo un movimiento diagonal fluido y colisiones continuas con deslizamiento por las paredes.
- **Gestión de memoria:** Implementación de un Garbage Collector propio mediante listas enlazadas para rastrear y liberar todas las asignaciones dinámicas y recursos gráficos, garantizando cero fugas (*leaks*).
- **Renderizado personalizado:** Renderizado preciso píxel a píxel del techo y suelo mediante códigos de color RGBA con desplazamiento de bits.

## Instrucciones

### Requisitos

Este proyecto depende de la librería **MLX42**, la cual requiere `glfw`.

Para Linux (Debian/Ubuntu):
```sh
sudo apt-get update
sudo apt-get install build-essential libglfw3-dev libglfw3 xorg-dev
```

### Compilación

Compilar la parte obligatoria:
```sh
make
```

### Ejecución

```sh
./cub3D maps/valid_map.cub
```

### Ejemplos de configuración de mapa

```text
NO ./textures/north.png
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png

F 220,100,0
C 225,30,0

111111
100001
10N001
111111
```

### Controles del juego

| Tecla / Acción | Descripción |
| :--- | :--- |
| `W` | Mover hacia adelante |
| `S` | Mover hacia atrás |
| `A` | Desplazamiento lateral a la izquierda (*strafe*) |
| `D` | Desplazamiento lateral a la derecha (*strafe*) |
| `⬅️ Flecha Izquierda` | Rotar la cámara hacia la izquierda |
| `➡️ Flecha Derecha` | Rotar la cámara hacia la derecha |
| `ESC` / `Botón X` | Salir del juego de forma limpia |
