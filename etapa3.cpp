/*
    En la etapa final, nuestro amigo ciclista desea volver a modificar la aplicación una vez más. 
    En este caso, quiere poder registrar los entrenamientos realizados en todo 1 mes y obtener datos
    de todo el mes de entrenamiento.
    El ciclista desea que luego de cargar los datos de todo el mes de entrenamiento, la aplicación
    tenga la capacidad de indicarle:
    a. Cúal fue el entrenamiento con la vuelta más rápida y su tiempo. Debe mostrar también
    los datos de la vuelta correspondiente
    b. Cúal fue el entrenamiento con la vuelta más lenta y su tiempo.

    DATOS PARA PRUEBAS:
    3.5 01 2021 1 5 0320 6 0400 4 0312 3 0315 2 0322 1 0400 7 0340 8 0329 9 0349 10 0310 3 5 0420 4 0412 3 0215 7 0350 2 0100 1 0410 9 0319 10 0310 8 0309 6 0430 2 4 0422 3 0245 7 0350 2 0522 1 0410 9 0319 10 0350 8 0309 6 0330 5 0420

*/

#include <iostream>
using namespace std;

#define VUELTAS 10
#define MAX_DIAS 31

typedef struct
{
    int dia;
    int mes;
    int anio;
} ST_FECHA;

typedef struct
{
    int numVuelta;
    int tiempoVuelta;
    float velocidadMedia;
    ST_FECHA fecha;
} ST_ENTRENAMIENTO;

typedef struct
{
    int vueltaMasRapida;
    int vueltaMasLenta;
    int tiempoMasRapida;
    int tiempoMasLenta;
    ST_ENTRENAMIENTO entrenamiento[VUELTAS];
} ST_MES;

float pedirDatokm(string);

ST_FECHA pedirFecha(int mes, int anio)
{
    ST_FECHA fecha;
    cout << "Ingrese día de entrenamiento: " << endl;
    cin >> fecha.dia;

    fecha.mes = mes;
    fecha.anio = anio;

    return fecha;
}

float calcularVelocidadMedia(float kmCircuito, int tiempoVuelta)
{
    float velocidad = 0;
    float mtsCircuito = kmCircuito * 1000;

    int tiempoVueltaMS = (tiempoVuelta / 100) * 60 + (tiempoVuelta % 100);

    velocidad = (float)mtsCircuito / tiempoVuelta;

    return velocidad;
}

void ordenarXNumVuelta(ST_ENTRENAMIENTO entrenamiento[VUELTAS])
{
    int i = 0;
    bool ordenado = false;
    ST_ENTRENAMIENTO aux;

    while (i < VUELTAS && !ordenado)
    {
        ordenado = true;
        for (int j = 0; j < VUELTAS - i - 1; j++)
        {
            if (entrenamiento[j].numVuelta > entrenamiento[j + 1].numVuelta)
            {
                aux = entrenamiento[j];
                entrenamiento[j] = entrenamiento[j + 1];
                entrenamiento[j + 1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
}

void ordenXTiempo(ST_ENTRENAMIENTO entrenamiento[VUELTAS])
{
    int i = 0;
    bool ordenado = false;
    ST_ENTRENAMIENTO aux;

    while (i < VUELTAS && !ordenado)
    {
        ordenado = true;
        for (int j = 0; j < VUELTAS - i - 1; j++)
        {
            if (entrenamiento[j].tiempoVuelta > entrenamiento[j + 1].tiempoVuelta)
            {
                aux = entrenamiento[j];
                entrenamiento[j] = entrenamiento[j + 1];
                entrenamiento[j + 1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
}

void ordenXFecha(ST_MES mesEntrenamiento[MAX_DIAS], int diasDelMes)
{
    int i = 0;
    bool ordenado = false;
    ST_MES aux;

    while (i < diasDelMes && !ordenado)
    {
        ordenado = true;
        for (int j = 0; j < diasDelMes - i - 1; j++)
        {
            if (mesEntrenamiento[j].entrenamiento[0].fecha.dia > mesEntrenamiento[j + 1].entrenamiento[0].fecha.dia)
            {
                aux = mesEntrenamiento[j];
                mesEntrenamiento[j] = mesEntrenamiento[j + 1];
                mesEntrenamiento[j + 1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
}

void cargarVueltas(ST_ENTRENAMIENTO entrenamiento[VUELTAS], ST_FECHA fecha, float kmCircuito)
{
    int i = 0;
    cout << "Ingrese numero de vuelta a cargar: " << endl;
    cin >> i;
    entrenamiento[i - 1].numVuelta = i;
    cout << "Ingrese tiempo de vuelta " << i << " (MMSS): " << endl;
    cin >> entrenamiento[i - 1].tiempoVuelta;
    entrenamiento[i - 1].fecha = fecha;
    entrenamiento[i - 1].velocidadMedia = calcularVelocidadMedia(kmCircuito, entrenamiento[i - 1].tiempoVuelta);
}

void buscarVueltaMasRapidaMes(ST_MES mesEntrenamiento[MAX_DIAS], int diasDelMes, int& vueltaMasRapidaMes, int& tiempoMasRapidaMes, int& diaVueltaMasRapidaMes)
{
    int i = 0;

    while (i < diasDelMes)
    {
        if (tiempoMasRapidaMes > mesEntrenamiento[i].tiempoMasRapida || tiempoMasRapidaMes == 0)
        {
            tiempoMasRapidaMes = mesEntrenamiento[i].tiempoMasRapida;
            vueltaMasRapidaMes = mesEntrenamiento[i].vueltaMasRapida;
            diaVueltaMasRapidaMes = mesEntrenamiento[i].entrenamiento[0].fecha.dia;
        }
        i++;
    }
            
}

void buscarVueltaMasLentaMes(ST_MES mesEntrenamiento[MAX_DIAS], int diasDelMes, int& vueltaMasLentaMes, int& tiempoMasLentaMes, int& diaVueltaMasLentaMes)
{
    int i = 0;

    while (i < diasDelMes)
    {
        if (tiempoMasLentaMes < mesEntrenamiento[i].tiempoMasLenta || tiempoMasLentaMes == 0)
        {
            tiempoMasLentaMes = mesEntrenamiento[i].tiempoMasLenta;
            vueltaMasLentaMes = mesEntrenamiento[i].vueltaMasLenta;
            diaVueltaMasLentaMes = mesEntrenamiento[i].entrenamiento[0].fecha.dia;
        }
       i++;
    }
            
}

void imprimirVuelta(ST_MES mesEntrenamiento[VUELTAS], int nroVuelta, int dia)
{
    cout << "Vuelta nro: " << nroVuelta << endl;
    cout << "Tiempo: " << mesEntrenamiento[dia - 1].entrenamiento[nroVuelta - 1].tiempoVuelta << endl;
    cout << "Fecha de entrenamiento: " << mesEntrenamiento[dia - 1].entrenamiento[nroVuelta - 1].fecha.dia
         << "/" << mesEntrenamiento[dia - 1].entrenamiento[nroVuelta - 1].fecha.mes
         << "/" << mesEntrenamiento[dia - 1].entrenamiento[nroVuelta - 1].fecha.anio << endl;
    cout << "Velocidad media de la vuelta: " << mesEntrenamiento[dia - 1].entrenamiento[nroVuelta - 1].velocidadMedia << endl;
}

int main()
{
    int anio = 0;
    int mes = 0;
    //Suponemos que no es un año bisiesto.
    int VecDiasDelMes[12] = {3, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int diasDelMes = 0;
    // Ingresar kilometros del circuito
    float kmCircuito = 0;
    kmCircuito = pedirDatokm("Ingrese los kilómetros del circuito: ");

    int diaVueltaMasRapidaMes = 0;
    int vueltaMasRapidaMes = 0;
    int tiempoMasRapidaMes = 0;

    int diaVueltaMasLentaMes = 0;
    int vueltaMasLentaMes = 0;
    int tiempoMasLentaMes = 0;

    // Instanciar estructura de entrenamiento
    ST_ENTRENAMIENTO entrenamiento[VUELTAS];

    // Pegrunta que mes desea ingresar.
    cout << "Ingrese el mes (en número) que desea cargar: " << endl;
    cin >> mes;
    cout << "Ingrese el año que desea cargar: " << endl;
    cin >> anio;
    diasDelMes = VecDiasDelMes[mes - 1];

    ST_MES mesEntrenamiento[diasDelMes];

    for (int j = 0; j < diasDelMes; j++)
    {
        // Instanciar estructura fecha y cargarla 1 vez para todo el entrenamiento
        ST_FECHA fecha = pedirFecha(mes, anio);

        // Cargar 20 vueltas
        for (int i = 0; i < VUELTAS; i++)
        {
            cargarVueltas(entrenamiento, fecha, kmCircuito);
        }
        ordenXTiempo(entrenamiento);
        mesEntrenamiento[j].vueltaMasLenta = entrenamiento[VUELTAS - 1].numVuelta;
        mesEntrenamiento[j].vueltaMasRapida = entrenamiento[0].numVuelta;
        mesEntrenamiento[j].tiempoMasLenta = entrenamiento[VUELTAS - 1].tiempoVuelta;
        mesEntrenamiento[j].tiempoMasRapida = entrenamiento[0].tiempoVuelta;
        ordenarXNumVuelta(entrenamiento);
        for(int i = 0; i < VUELTAS; i++){
            mesEntrenamiento[j].entrenamiento[i] = entrenamiento[i];
        }
    }

    ordenXFecha(mesEntrenamiento, diasDelMes);

    buscarVueltaMasRapidaMes(mesEntrenamiento, diasDelMes, vueltaMasRapidaMes, tiempoMasRapidaMes, diaVueltaMasRapidaMes);

    buscarVueltaMasLentaMes(mesEntrenamiento, diasDelMes, vueltaMasLentaMes, tiempoMasLentaMes, diaVueltaMasLentaMes);

    cout << "La vuelta mas rápida del mes es la Nº: " << vueltaMasRapidaMes << endl;
    cout << "Del día: " << diaVueltaMasRapidaMes << endl;
    cout << "Tiempo: " << mesEntrenamiento[diaVueltaMasRapidaMes - 1].entrenamiento[vueltaMasRapidaMes - 1].tiempoVuelta << endl;
    cout << "Velocidad media: " << mesEntrenamiento[diaVueltaMasRapidaMes - 1].entrenamiento[vueltaMasRapidaMes - 1].velocidadMedia<< endl;

    cout << "La vuelta mas lenta del mes es la Nº: " << vueltaMasLentaMes << endl;
    cout << "Dia: " << diaVueltaMasLentaMes << endl;
    cout << "Tiempo: " << mesEntrenamiento[diaVueltaMasLentaMes - 1].entrenamiento[vueltaMasLentaMes - 1].tiempoVuelta << endl;
    cout << "Velocidad media: " << mesEntrenamiento[diaVueltaMasLentaMes - 1].entrenamiento[vueltaMasLentaMes - 1].velocidadMedia<< endl;


    // Buscar vueltas
    int nroVuelta;
    int dia;
    cout << "Ingrese el día de vuelta a imprimir (ó 0 para terminar): " << endl;
    cin >> dia;
    while(dia != 0){
        cout << "Ingrese número de vuelta a imprimir: " << endl;
        cin >> nroVuelta;
        imprimirVuelta(mesEntrenamiento, nroVuelta, dia);
        cout << "Ingrese el día de vuelta a imprimir (ó 0 para terminar): " << endl;
        cin >> dia;
    }

    return 0;
}

float pedirDatokm(string mensaje)
{
    float numero;
    cout << mensaje;
    cin >> numero;
    return numero;
}
