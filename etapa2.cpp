#include <iostream>
using namespace std;

#define VUELTAS 10

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

float pedirDatokm(string);

ST_FECHA pedirFecha()
{
  ST_FECHA fecha;
  cout << "Ingrese día de entrenamiento: " << endl;
  cin >> fecha.dia;
  cout << "Ingrese mes de entrenamiento: " << endl;
  cin >> fecha.mes;
  cout << "Ingrese año de entrenamiento: " << endl;
  cin >> fecha.anio;

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

void imprimirVuelta(ST_ENTRENAMIENTO entrenamiento[VUELTAS], int nroVuelta)
{
  cout << "Vuelta nro: " << nroVuelta << endl;
  cout << "Tiempo: " << entrenamiento[nroVuelta - 1].tiempoVuelta << endl;
  cout << "Fecha de entrenamiento: " << entrenamiento[nroVuelta - 1].fecha.dia 
    << "/" << entrenamiento[nroVuelta - 1].fecha.mes 
    << "/" << entrenamiento[nroVuelta - 1].fecha.anio << endl;
  cout << "Velocidad media de la vuelta: " << entrenamiento[nroVuelta - 1].velocidadMedia << endl;
}

/*
3.5 01 01 2021 5 0320 6 0400 4 0312 3 0315 2 0322 1 0400 7 0340 8 0329 9 0349 10 0310   
*/

int main()
{
  // Ingresar kilometros del circuito
  float kmCircuito = 0;
  kmCircuito = pedirDatokm("Ingrese los kilómetros del circuito: ");

  // Instanciar estructura de entrenamiento
  ST_ENTRENAMIENTO entrenamiento[VUELTAS];

  // Instanciar estructura fecha y cargarla 1 vez para todo el entrenamiento
  ST_FECHA fecha = pedirFecha();

  // Cargar 20 vueltas
  for (int i = 0; i < VUELTAS; i++)
  {
    cargarVueltas(entrenamiento, fecha, kmCircuito);
  }

  // Buscar vueltas
  int nroVuelta;
  cout << "Ingrese número de vuelta a imprimir: " << endl;
  cin >> nroVuelta;
  imprimirVuelta(entrenamiento, nroVuelta);

  return 0;
}

float pedirDatokm(string mensaje)
{
  float numero;
  cout << mensaje;
  cin >> numero;
  return numero;
}
