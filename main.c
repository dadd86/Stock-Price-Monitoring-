#include <stdio.h>
#include <stdbool.h>
#include <time.h>

//Creamos una dato con estrutura
typedef struct{
    int OrdenCronologico;
    float valor;
} Cotizacion;

//Creamos funcion obtener la hora y fecha actual
struct tm obtenerHoraActual() {
    // Crear una variable para almacenar la hora actual
    time_t tiempoActual;
    // Obtener la hora actual
    time(&tiempoActual);
    // Convertir time_t a tm como estructura local
    struct tm *miTiempo = localtime(&tiempoActual);
    // Retornar una copia de la estructura local time
    return *miTiempo;
}
//Verifica de horario de bolsa
void verificarTiempo(bool *dentroHorarioBolsa) {
    time_t tiempoActual;
    struct tm *tiempoLocal;
    // Obtener tiempo actual
    tiempoActual = time(NULL);
    tiempoLocal = localtime(&tiempoActual);
    // Verificar si está dentro del horario de la bolsa (9:00 a 17:00)
    *dentroHorarioBolsa = (tiempoLocal->tm_hour >= 9 && tiempoLocal->tm_hour < 17);
}
//Verificacion de cada 10 minutos
void verificarMinutos(time_t ultimaCotizacion, bool *cada10) {
    time_t tiempoActual;
    struct tm *tiempoLocal;
    double segundosDesdeUltimaCotizacion;
    // Obtener tiempo actual
    tiempoActual = time(NULL);
    tiempoLocal = localtime(&tiempoActual);
    // Verificar si han pasado 10 minutos desde la última cotización
    segundosDesdeUltimaCotizacion = difftime(tiempoActual, ultimaCotizacion);
    //Se pueden modificar los segundos segun se requieran si se cambia de 600 a 60 estarias verificando verificando 1 minuto
    *cada10 = (segundosDesdeUltimaCotizacion >= 600);
}

// Función para imprimir los resultados del análisis.
void imprimirResultados(float media,
                        int contador,
                        int cotizacionesMenores,
                        int cotizacionesMayores,
                        int CotizacionIgual,
                        float primerValor,
                        float ultima,
                        float penultima,
                        float antepenultima,
                        bool cotizaciones,
                        bool bajadas,
                        const char *Mensaje,//mensaje no supera
                        const char *Mensaje1,//mensaje supera
                        const char *Mensaje2,//mensaje 4 bajistas
                        const char *Mensaje3,//cadena concretamente
                        const char *Mensaje4,//cadena concretamente
                        const char *Mensaje5,//cadena concretamente
                        const char *Mensaje6,//cadena concretamente
                        const char *Mensaje7,//****************
                        const char *Mensaje8,//la media
                        const char *Mensaje9,//numero por debajo al inicial
                        const char *Mensaje10,//cotizaciones iguales
                        struct tm horaActual){
    if (bajadas==true){
        printf("%s%s",Mensaje7,Mensaje2);
        printf("Concretamente se ha producido a las: %02d:%02d:%02d\n",horaActual.tm_hour, horaActual.tm_min, horaActual.tm_sec);
        if (cotizaciones==false){
            printf("%s%s%d%s%d%s%d%s%s%d\n%s",Mensaje,Mensaje3,contador,Mensaje4,cotizacionesMenores,Mensaje5,cotizacionesMayores,Mensaje6,Mensaje10,CotizacionIgual,Mensaje7);//impresion en pantalla
        }
    }
    if (cotizaciones==false && bajadas==false){
        printf("%s%s%s%d%s%d%s%d%s%s%d\n%s",Mensaje7,Mensaje,Mensaje3,contador,Mensaje4,cotizacionesMenores,Mensaje5,cotizacionesMayores,Mensaje6,Mensaje10,CotizacionIgual,Mensaje7);//impresion en pantalla
    }
    if (cotizaciones==true){
        // Imprime la media de cotización y otras estadísticas relevantes.
        printf("%s%s%s%.6f\n%s%d\n",Mensaje7,Mensaje1,Mensaje8,media,Mensaje9,cotizacionesMenores);
        // Determina la tendencia al alza basada en las tres últimas cotizaciones y su comparación con la primera.
        bool alAlza = ultima > primerValor && penultima > primerValor && antepenultima > primerValor;
        float mediaUltimasTres = (ultima + penultima + antepenultima) / 3.0f;
        if (alAlza && ((mediaUltimasTres / media) - 1.0f)*100.0f >= 0.03) {
            printf("**La cotización está al ALZA**\n");
        } else {
            printf("**La cotización está ESTABLE o a la BAJA**\n");
        }
        printf("%s",Mensaje7);
    }
}

//Funcion para escribir los datos del usuario
Cotizacion EscrituraDatos(void){
    Cotizacion cotizacion={0,0.0f};
    printf("\nIntroduce el tiempo: ");
    scanf("%d",&cotizacion.OrdenCronologico);
    if (cotizacion.OrdenCronologico!=-1){
        printf("\nIntroduce el valor Bursatil: ");
        scanf("%f",&cotizacion.valor);
    }
    return cotizacion;
}

int main() {
    //Declaramos e inicializamos todas las variables
    int contador = 0, cotizacionesMenores = 0, cotizacionesMayores=0, CotizacionIgual=0,bajadasConsecutivas = 0;
    float suma = 0.0f, primerValor=0.0f;
    float ultima = 0.0f, penultima = 0.0f, antepenultima = 0.0f; // Variables para las tres últimas cotizacion
    bool Cotizaciones = false, Bajadas=false,dentroHorarioBolsa=false, cada10=false;
    time_t UltimaCotizacion;
    //Creamos la variable con la estructura de tm
    struct tm horaBajada;
    //llamamos la funcion verificartiempo
    verificarTiempo(&dentroHorarioBolsa);
    //si esta trabajando fuera de horaraio POR FAVOR ELIMINE EL ! DE LA VARIABLE dentroHorarioBolsa
    if (!dentroHorarioBolsa){
        printf("Estas fuera de horario de trabajo");
        return 0;
    }
    Cotizacion cotizacion = EscrituraDatos();//Aqui hacemos asignacion de la estructura Cotizacion a la variable cotizacion y llamamos a funcion
    primerValor=cotizacion.valor;//Guardamos el primer valor para referencia
    UltimaCotizacion=time(NULL);// Guardar el tiempo después de la primera cotización
    while (cotizacion.OrdenCronologico != -1) {
        verificarMinutos(UltimaCotizacion,&cada10);
        if(cada10){
            cotizacion = EscrituraDatos();
            UltimaCotizacion=time(NULL);
            suma += cotizacion.valor; // Suma acumulativa de cotizaciones.
            contador++; // Incremento del contador de cotizaciones.
            if (cotizacion.valor < primerValor && contador > 0) {
                cotizacionesMenores++; // Contador de cotizaciones inferiores al primer valor.
            }else if(cotizacion.valor>primerValor){
                    cotizacionesMayores++;
                }
            else if(cotizacion.valor==primerValor){
                    CotizacionIgual++;
                }
            // Gestión de las bajadas consecutivas.
            bajadasConsecutivas = (cotizacion.valor <= ultima) ? bajadasConsecutivas + 1 : 0;
            if (bajadasConsecutivas == 4){
                Bajadas=true;
                // Obtener la hora actual antes de llamar a imprimirResultados
                horaBajada = obtenerHoraActual();
                break; // Si hay 4 bajadas seguidas, termina el análisis.
            }
            // Rotación de las últimas tres cotizaciones.
            antepenultima = penultima;
            penultima = ultima;
            ultima = cotizacion.valor;
            UltimaCotizacion=time(NULL);
        }else{
            printf("Aun no han pasado 10 minutos desde la última cotización.\n");
            //pausamos el programa durante 120 segundos antes de volver a comprobar
            sleep(120);
        }
    }
    if(contador > 0){
        float media = suma / contador; // Calcula la media.
        if (cotizacionesMenores > cotizacionesMayores) {
            Cotizaciones =false;
        }else{
            Cotizaciones=true;
        }
        imprimirResultados(media,
                           contador,
                           cotizacionesMenores,
                           cotizacionesMayores,
                           CotizacionIgual,
                           primerValor,
                           ultima,
                           penultima,
                           antepenultima,
                           Cotizaciones,
                           Bajadas,
                           "La secuencia no supera el control: hay más cotizaciones inferiores a la inicial que superiores.\n",
                           "La secuencia supera el control: hay más cotizaciones superiores a la inicial que inferiores.\n",
                           "La sesión ha terminado temprano debido a una tendencia negativa sostenida.\n",
                           "concretamente de ",
                           " lecturas, ",
                           " son inferiores a la inicial y ",
                           " son superiores a esta,",
                           "*****************************************************************************************************\n",
                           "La media de cotización de la acción durante el día es de ",
                           "El número de cotizaciones que se han situado por debajo de la primera es de ",
                           " y las cotizaciones iguales a la inicial ",
                           horaBajada);
    }else {
        printf("No se introdujeron cotizaciones válidas.\n");
    }
    return 0;
}
