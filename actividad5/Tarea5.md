# Tarea 5
Conceptos importantes de SO
## Kernel
El kernel es el componente central de un sistema operativo. Actúa como un intermediario entre el hardware de la computadora y las aplicaciones de software que se ejecutan en el sistema. Algunas clasificaciones comunes de este son


| Kernel | Descripción|Ventajas| Desventajas| Ejemplos|
|--------|------------|--------|------------|----------|
| Monolítico     | Todos los servicios del sistema operativo se ejecutan en un solo espacio.   | Alto rendimiento debido a la comunicación directa entre componentes.| Si un componente falla, puede afectar todo el sistema.| Linux, Windows NT|
| Microkernel| Solo las funciones esenciales están en el kernel; otros servicios en usuario.| Mayor estabilidad y seguridad.| Rendimiento inferior debido a la comunicación entre servicios.| Minix, QNX |
| Híbrido| Combina características de monolíticos y microkernels. | Equilibrio entre rendimiento y estabilidad.  | Puede ser complejo y difícil de mantener. | Windows NT, macOS|
| Exokernel | Minimiza las funciones del kernel, delegando operaciones a aplicaciones.| Alta flexibilidad y eficiencia.| Requiere que las aplicaciones gestionen tareas normalmente manejadas por el SO.| Aegis, Xok|

## User vs Kernel Mode
| Modo | Descripción|Ventajas | Desventajas | Ejemplos|
|------|-----------|----------|-------------|---------|
| User Mode | Las aplicaciones se ejecutan con privilegios limitados, sin acceso directo al hardware. | Protege el sistema de operaciones maliciosas o errores de las aplicaciones.| No permite a las aplicaciones acceder directamente a recursos críticos del sistema.| Navegadores web, procesadores de texto. |
| Kernel Mode   | El sistema operativo y sus componentes se ejecutan con privilegios elevados. | Control completo de los recursos del hardware, esencial para funciones críticas del SO.      | Si un componente falla, puede comprometer la estabilidad del sistema. | Controladores de dispositivos, gestión de memoria. |

## Interrupciones vs traps
| Concepto       | Descripción     | Origen | Ejemplos| Manejo |
|----------------|-----------------|--------|---------|--------|
| Interrupciones | Señales enviadas al procesador por dispositivos externos para notificar eventos que requieren atención inmediata. | Externo (hardware)| Tecla presionada, llegada de un paquete de red, temporizador expira. | El procesador detiene la tarea actual, guarda su estado, y ejecuta una rutina de servicio de interrupción (ISR). |
| Traps| Instrucciones especiales generadas por software para indicar al procesador que debe cambiar al Kernel Mode y ejecutar un servicio del SO. | Interno (software)| Llamadas al sistema, excepciones como división por cero.  | Similar a una interrupción, pero iniciada por el software. Cambia al Kernel Mode para ejecutar el servicio solicitado. |
