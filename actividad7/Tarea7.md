# Tarea 7 Completely Fair Scheduler (CFS) 

El "Completely Fair Scheduler" (Planificador Completamente Justo) es un algoritmo de planificación utilizado en sistemas operativos Linux para distribuir de manera equitativa el tiempo de CPU entre todos los procesos en ejecución. Este algoritmo prioriza la equidad, intentando asignar recursos de forma que ningún proceso sea favorecido injustamente sobre los demás, utilizando técnicas como el uso de árboles rojo-negro para mantener un seguimiento eficiente de las colas de procesos y sus prioridades dinámicas.


## Caracteristicas

1. **Equidad en la CPU**:
   - CFS busca repartir el tiempo de CPU de manera justa entre todos los procesos en ejecución. Cada proceso debería recibir un porcentaje equitativo del tiempo de CPU, en función de su "peso" o prioridad.
  
2. **Distribución basada en árboles rojos-negros**:
   - CFS organiza los procesos en una estructura de datos conocida como un **árbol rojo-negro** (Red-Black Tree), que permite buscar, insertar y eliminar procesos en tiempo logarítmico. Esto ayuda a mantener la eficiencia del scheduler incluso con muchos procesos en ejecución.

3. **Reloj virtual**:
   - CFS usa un concepto de **reloj virtual** que cuenta cuánto tiempo de CPU ha recibido cada proceso. Los procesos que han recibido menos tiempo son programados con más prioridad para equilibrar el uso de la CPU.

4. **Prioridades ponderadas**:
   - CFS tiene en cuenta la **prioridad** de los procesos mediante una ponderación. Los procesos con mayor prioridad (menor valor de nice) reciben más tiempo de CPU, pero aun así respetando el principio de equidad. Los procesos con menor prioridad recibirán menos tiempo, pero no serán completamente privados de CPU.

5. **Sin periodos fijos de tiempo (time slices)**:
   - A diferencia de los planificadores tradicionales basados en **time slices** o porciones de tiempo, CFS no asigna tiempos fijos a cada proceso. En su lugar, decide cuánto tiempo de CPU le corresponde a cada proceso según lo "justo" que ha sido tratado hasta ese momento, en relación con los demás procesos.

6. **Latencia mínima de proceso**:
   - CFS garantiza que cada proceso obtenga tiempo de CPU dentro de un intervalo llamado **latencia mínima**, que es el tiempo máximo que un proceso puede esperar antes de ser programado nuevamente. Este valor se ajusta dinámicamente en función de la cantidad de procesos activos.

7. **Soporte para múltiples núcleos**:
   - CFS distribuye eficientemente los procesos entre múltiples núcleos de CPU, balanceando la carga entre los diferentes núcleos para maximizar el rendimiento.

## Funcionamiento

1. **Recolección de procesos**:
   - Los procesos listos para ser ejecutados se colocan en un árbol rojo-negro, donde se ordenan por el tiempo que ya han consumido en la CPU (en relación a su prioridad). Los procesos que menos tiempo han recibido están más cerca de la raíz del árbol.

2. **Selección del proceso**:
   - El scheduler selecciona el proceso que ha consumido menos tiempo de CPU hasta ese momento (el que se encuentra en la raíz del árbol) y lo ejecuta. El tiempo de ejecución exacto depende de la latencia mínima y la cantidad de procesos en cola.

3. **Reloj virtual**:
   - Mientras se ejecuta un proceso, se incrementa su "tiempo de CPU" en el reloj virtual. Una vez que el proceso ha consumido suficiente CPU, se lo coloca de nuevo en el árbol, y el scheduler selecciona el siguiente proceso a ejecutar.

4. **Asignación dinámica**:
   - Si un proceso nuevo de mayor prioridad ingresa al sistema, CFS lo ajusta inmediatamente, y este proceso puede ser seleccionado antes que los demás, sin romper la equidad global del sistema.





