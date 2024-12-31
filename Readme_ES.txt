Proyecto de Monitoreo de Cotizaciones Bursátiles

Este proyecto tiene como objetivo monitorear las cotizaciones bursátiles de una acción a lo largo de una jornada de bolsa,
evaluando su comportamiento y determinando si la secuencia de cotizaciones supera un control basado en las variaciones con respecto al primer valor registrado. 
La aplicación permite realizar un análisis en tiempo real de las cotizaciones, evaluando tendencias al alza, a la baja o estabilidad.

Descripción del Proyecto
El programa permite al usuario ingresar cotizaciones bursátiles en intervalos de tiempo de 10 minutos y proporciona estadísticas sobre las cotizaciones, 
como el número de cotizaciones mayores, menores o iguales al primer valor, y si hay una tendencia al alza o a la baja. 
El sistema también verifica si la cotización se encuentra dentro del horario de la bolsa (de 9:00 a 17:00) y analiza las cotizaciones de forma acumulativa.

Estructuras de Datos
Cotización: Representa una cotización bursátil, con:

OrdenCronologico: Número de orden cronológico de la cotización.
valor: Valor de la cotización en el momento en que se registra.
Estructura tm (hora y fecha): Estructura utilizada para almacenar la hora y fecha actuales.

Funcionalidades
Obtener Hora Actual: Obtiene la hora y fecha actual utilizando la función obtenerHoraActual().
Verificar Horario de Bolsa: Verifica si el tiempo actual está dentro del horario de la bolsa (9:00 a 17:00) usando la función verificarTiempo().
Verificación de Intervalo de 10 Minutos: Verifica si han transcurrido al menos 10 minutos desde la última cotización registrada utilizando verificarMinutos().
Escribir Datos de Cotización: Permite al usuario ingresar los datos de la cotización, como el valor y el orden cronológico, a través de la función EscrituraDatos().
Imprimir Resultados: Imprime los resultados del análisis, incluyendo la media de las cotizaciones, el número de cotizaciones mayores, 
menores y iguales al primer valor, y si la secuencia ha alcanzado una tendencia bajista o al alza.
Tendencia de Cotización: Determina si la cotización está al alza o estable, en función de las últimas tres cotizaciones registradas.
Bajadas Consecutivas: Si se registran 4 cotizaciones consecutivas a la baja, se marca una tendencia bajista y termina el análisis.

Flujo del Programa:
	Inicio: El programa verifica si se encuentra dentro del horario de la bolsa. Si no es así, muestra un mensaje de error y termina la ejecución.
	Ingreso de Cotizaciones: El usuario ingresa cotizaciones a intervalos de 10 minutos.
		El programa calcula la media de las cotizaciones, cuenta las cotizaciones menores, mayores o iguales al primer valor, 
		y detecta si hay una tendencia a la baja (bajadas consecutivas).
	Cálculo y Análisis: Después de registrar las cotizaciones, el programa calcula la media y analiza la tendencia de las cotizaciones, 
		determinando si la secuencia supera un control basado en el comportamiento de las cotizaciones.
	Resultados: El programa imprime un análisis detallado de las cotizaciones y la tendencia detectada.

Funciones Clave:
obtenerHoraActual(): Obtiene la hora actual del sistema.
verificarTiempo(): Verifica si la hora actual está dentro del horario de la bolsa (9:00 a 17:00).
verificarMinutos(): Verifica si han pasado al menos 10 minutos desde la última cotización.
EscrituraDatos(): Permite al usuario ingresar datos de cotización (valor y orden cronológico).
imprimirResultados(): Imprime el análisis final de las cotizaciones, incluyendo la tendencia de las mismas.
tendencia(): Determina si la cotización está en una tendencia al alza, estable o a la baja.

Requisitos:

Compilador: Se requiere un compilador de C compatible con el estándar C99 o superior.
Sistema Operativo: Funciona en sistemas operativos como Windows, Linux y macOS.
Instrucciones de Uso
Compilación y Ejecución:

Para compilar el proyecto, utiliza un compilador de C (por ejemplo, GCC) con el siguiente comando:
	gcc -o monitor_bolsa monitor_bolsa.c

Para ejecutar el programa, utiliza el siguiente comando:
	./monitor_bolsa

Interacción:

El programa verificará si está dentro del horario de la bolsa (de 9:00 a 17:00).
Si está dentro del horario, el usuario podrá ingresar cotizaciones en intervalos de 10 minutos.
Al final de la jornada o cuando se detecten 4 bajadas consecutivas, el programa imprimirá un análisis detallado.

Ejemplo de Uso:

Ingresar Cotizaciones:
	El usuario ingresa las cotizaciones bursátiles con un valor y un orden cronológico. El programa las registra y las utiliza para calcular estadísticas.
Verificación de Tendencia:
	El programa calculará la tendencia de las cotizaciones, indicando si están al alza, estables o a la baja, y verificará si se ha producido una bajada consecutiva de 4 cotizaciones.
Resultados del Análisis:
	El programa imprimirá el análisis final, con la media de las cotizaciones, el número de cotizaciones menores, mayores e iguales al primer valor, y un mensaje indicando si la secuencia está al alza o a la baja.

Contribuciones:

Las contribuciones al proyecto son bienvenidas. Si deseas mejorar el código, agregar nuevas funcionalidades o corregir errores, por favor sigue estos pasos:
	Haz un fork del repositorio.
	Crea una nueva rama para tu cambio (git checkout -b feature/nueva-funcionalidad).
	Realiza tus cambios y haz commit (git commit -am 'Añadir nueva funcionalidad').
	Haz push a la rama (git push origin feature/nueva-funcionalidad).
	Crea un pull request describiendo los cambios realizados.