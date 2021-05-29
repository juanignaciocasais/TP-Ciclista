#include <iostream>

using namespace std;

float pedirDatokm(string);

int pedirDato(string);

float velocidadMedia(float, int, int);

int main()
{
    int numVuelta = 0;
    int tiempoVuelta = 0;
    int cantidadVueltas = 0;
    float kmCircuito = 0;
    int masRapida = 0;
    int tiempoMasRapida = 0;
    int masLenta = 0;
    int tiempoMasLenta = 0;

    kmCircuito = pedirDatokm("Ingrese los kilómetros del circuito: ");

    cantidadVueltas = pedirDato("Ingrese la cantidad de vueltas a registrar (<= 20): ");

    for (int i = 0; i < cantidadVueltas; i++)
    {
        numVuelta = pedirDato("Ingrese el número de vuelta: ");

        tiempoVuelta = pedirDato("Ingrese el tiempo de la vuelta (MMSS): ");

        if (tiempoMasRapida > tiempoVuelta || masRapida == 0)
        {
            tiempoMasRapida = tiempoVuelta;
            masRapida = numVuelta;
        }

        if (tiempoMasLenta < tiempoVuelta || masLenta == 0)
        {
            tiempoMasLenta = tiempoVuelta;
            masLenta = numVuelta;
        }
    }

    cout << "La vuelta más rápida fue la nº " << masRapida
         << " y su tiempo es de " << tiempoMasRapida / 100 << ":" << tiempoMasRapida % 100 << " minutos" << endl;

    cout << "La vuelta más lenta fue la nº " << masLenta
         << " y su tiempo es de " << tiempoMasLenta / 100 << ":" << tiempoMasLenta % 100 << " minutos" << endl;

    cout << "Porcentaje de reducción de tiempo: " << velocidadMedia(kmCircuito, tiempoMasRapida, tiempoMasLenta) << endl;

    return 0;
}

float pedirDatokm(string mensaje)
{
    float numero;
    cout << mensaje;
    cin >> numero;
    return numero;
}

int pedirDato(string mensaje)
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

    velocidad = (float)tiempoMasLentaSeg / tiempoMasRapidaSeg - 1;

    return velocidad;
}
