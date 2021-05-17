#include <iostream>

using namespace std;

float pedirDatokm(string);

int pedirVueltas(string);

void pedirDatoVector(int vector[], string mensaje, int dimension)
{
    cout << mensaje;
    cin >> vector[dimension];
}

void vueltaMasRapida(int vector[], int dimension, int &tiempo, int &posicion)
{
    tiempo = vector[0];

    for (int i = 1; i < dimension; i++)
    {
        if (vector[i] < tiempo)
        {
            tiempo = vector[i];
            posicion = i;
        }
    }

    return;
}

void vueltaMasLenta(int vector[], int dimension, int &tiempo, int &posicion)
{
    tiempo = vector[0];

    for (int i = 1; i < dimension; i++)
    {
        if (vector[i] > tiempo)
        {
            tiempo = vector[i];
            posicion = i;
        }
    }

    return;
}

float velocidadMedia(float, int, int);

int main()
{

    int numVuelta[20] = {0};
    int tiempoVuelta[20] = {0};
    int cantidadVueltas = 0;
    float kmCircuito = 0;
    int masRapida = 0;
    int tiempoMasRapida = 0;
    int masLenta = 0;
    int tiempoMasLenta = 0;

    kmCircuito = pedirDatokm("Ingrese los kilómetros del circuito: ");

    cantidadVueltas = pedirVueltas("Ingrese la cantidad de vueltas a registrar (<= 20): ");

    for (int i = 0; i < cantidadVueltas; i++)
    {
        pedirDatoVector(numVuelta, "Ingrese el número de vuelta: ", i);
        pedirDatoVector(tiempoVuelta, "Ingrese el tiempo de la vuelta (MMSS): ", i);
    }

    vueltaMasRapida(tiempoVuelta, cantidadVueltas, tiempoMasRapida, masRapida);

    vueltaMasLenta(tiempoVuelta, cantidadVueltas, tiempoMasLenta, masLenta);

    cout << "La vuelta más rápida fue la nº " << numVuelta[masRapida]
         << " y su tiempo es de " << tiempoMasRapida / 100 << ":" << tiempoMasRapida % 100 << " minutos" << endl;

    cout << "La vuelta más lenta fue la nº " << numVuelta[masLenta]
         << " y su tiempo es de " << tiempoMasLenta / 100 << ":" << tiempoMasLenta % 100 << " minutos" << endl;

    cout << "La velocidad media fue de " << velocidadMedia(kmCircuito, tiempoMasRapida, tiempoMasLenta) << " m/s." << endl;

    return 0;
}

float pedirDatokm(string mensaje)
{
    float numero;
    cout << mensaje;
    cin >> numero;
    return numero;
}

int pedirVueltas(string mensaje)
{
    int numero;
    cout << mensaje;
    cin >> numero;
    return numero;
}

float velocidadMedia(float kmCircuito, int tiempoMasRapida, int tiempoMasLenta)
{

    float velocidad = 0;
    float mtsCircuito = kmCircuito * 1000;

    int tiempoMasRapidaSeg = (tiempoMasRapida / 100) * 60 + (tiempoMasRapida % 100);

    int tiempoMasLentaSeg = (tiempoMasLenta / 100) * 60 + (tiempoMasLenta % 100);

    if (tiempoMasLentaSeg - tiempoMasRapidaSeg > 0)
    {
        velocidad = (float)mtsCircuito / (tiempoMasLentaSeg - tiempoMasRapidaSeg);
    }
    else
    {
        velocidad = (float)mtsCircuito / tiempoMasRapidaSeg;
    }

    return velocidad;
}
