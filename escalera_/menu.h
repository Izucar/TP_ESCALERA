#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include <cstdlib>  // Para system("cls")
#include <vector>
#include <cstdlib>  // Para system("cls")
#include <ctime>    // Para srand y time
#include <algorithm>

using namespace std;

const int puntajemaximo = 100 ;
const int numerodedados = 6;
const int rondas = 3;


struct Jugador {
    string nombre;
    int puntaje;
    int puntajeTotal;
};

int lanzarDado() {
     return  rand() % 10 + 1;

}


int evaluarDados(const vector<int>& dados) {
    int suma = 0;
    for (int dado : dados) {
        suma += dado;
    }
    return suma;
}

bool verificarEscalera(const vector<int>& dados) {
    vector<int> valores = dados;
    sort(valores.begin(), valores.end());

    // Verificar si los valores forman una escalera
    for (int i = 0; i < numerodedados - 1; ++i) {
        if (valores[i] != valores[i + 1] - 1) {
            return false;
        }
    }
    return true;
}

// Función para verificar si hay sexteto de 6 en los dados
bool verificarSextetoSeis(const vector<int>& dados) {
    int cuentaSeis = 0;
    for (int dado : dados) {
        if (dado == 6) {
            cuentaSeis++;
        }
    }
    return cuentaSeis == numerodedados;
}

// Función para jugar el juego para un solo jugador
void jugar1(Jugador& jugador) {

    int numeroRonda = 1;
    int puntajeTotal = 0;
    bool juegoGanado = false;

    while (!juegoGanado) {
        system("cls");
        cout << "Turno de " << jugador.nombre << " | Ronda N° " << numeroRonda << " | Puntaje Total: " << puntajeTotal << " puntos" << endl;
        cout << "-------------------------------------------------------" << endl;
        system("pause");
        int puntajeMaximoRonda = 0;

        for (int i = 0; i < rondas; ++i) {
            cout << "LANZAMIENTO N° " << i + 1 << endl;

            // Simular lanzamiento de dados
            vector<int> dados(numerodedados);
            for (int j = 0; j < numerodedados; ++j) {
                dados[j] = lanzarDado();
                cout << dados[j] << " ";
            }
            cout << endl;

            // Calcular puntaje del lanzamiento
            int puntajeLanzamiento = evaluarDados(dados);
            cout << "Puntaje de ronda: " << puntajeLanzamiento << " puntos" << endl;

            // Evaluar si hay escalera o sexteto de 6
            if (verificarEscalera(dados)) {
                cout << "¡Escalera! ¡Has ganado la partida en esta ronda!" << endl;
                juegoGanado = true;
                break;
            }
            if (verificarSextetoSeis(dados)) {
                puntajeTotal = 0;
                cout << "¡Sexteto6! Puntaje total reseteado a 0." << endl;
                break;
            }

            // Actualizar máximo puntaje de la ronda
            if (puntajeLanzamiento > puntajeMaximoRonda) {
                puntajeMaximoRonda = puntajeLanzamiento;
            }
        }

        // Sumar máximo puntaje de la ronda al puntaje total
        puntajeTotal += puntajeMaximoRonda;

        // Verificar si se alcanzó o superó el puntaje objetivo
        if (puntajeTotal >= puntajemaximo && !juegoGanado) {



            cout << "¡Felicidades! Has alcanzado " << puntajemaximo << " ¡Ganaste!" << endl;
            juegoGanado = true;
        }

system("pause");
        ++numeroRonda;
    }

    // Asignar puntaje total al jugador
    jugador.puntaje = puntajeTotal;
}

void jugadorPara2(string nombreJugador1, string nombreJugador2) {

    string nombre;

    Jugador jugador1 = {nombreJugador1, 0};
    Jugador jugador2 = {nombreJugador2, 0};
    int numeroRonda = 1;
    bool juegoGanado = false;

    while (!juegoGanado) {
        // Turno del jugador 1
        system("cls");
        cout << "Turno de " << jugador1.nombre << " | Ronda N° " << numeroRonda << " | Puntaje Total: " << jugador1.puntajeTotal << " puntos" << endl;
        cout << "-------------------------------------------------------" << endl;
        system("pause");
        int puntajeMaximoRonda = 0;

        for (int i = 0; i < rondas; ++i) {
            cout << "LANZAMIENTO N° " << i + 1 << endl;

            // Simular lanzamiento de dados
            vector <int> dados(numerodedados);
            for (int j = 0; j < numerodedados; ++j) {
                dados[j] = lanzarDado();
                cout << dados[j] << " ";
            }
            cout << endl;

            // Calcular puntaje del lanzamiento
            int puntajeLanzamiento = evaluarDados(dados);
            cout << "Puntaje de ronda: " << puntajeLanzamiento << " puntos" << endl;

            // Evaluar si hay escalera o sexteto de 6
            if (verificarEscalera(dados)) {
                cout << "¡Escalera! ¡Has ganado la partida en esta ronda!" << endl;
                juegoGanado = true;
                break;
            }
            if (verificarSextetoSeis(dados)) {
                jugador1.puntajeTotal = 0;
                cout << "¡Sexteto6! Puntaje total reseteado a 0." << endl;
                break;
            }

            // Actualizar máximo puntaje de la ronda
            if (puntajeLanzamiento > puntajeMaximoRonda) {
                puntajeMaximoRonda = puntajeLanzamiento;
            }
        }

        // Sumar máximo puntaje de la ronda al puntaje total
        jugador1.puntajeTotal += puntajeMaximoRonda;

        // Verificar si se alcanzó o superó el puntaje objetivo
        if (jugador1.puntajeTotal >= puntajemaximo && !juegoGanado) {
            cout<<"--------------------------------------------------------------------"<<endl;
            cout << "¡Felicidades! " << jugador1.nombre << " has alcanzado " << puntajemaximo << " ¡Ganaste!" << endl;
            cout<<"--------------------------------------------------------------------"<<endl;
            juegoGanado = true;
            break;
        }

        system("pause");
        if (juegoGanado) break;

        // Turno del jugador 2
        system("cls");
        cout << "Turno de " << jugador2.nombre << " | Ronda N° " << numeroRonda << " | Puntaje Total: " << jugador2.puntajeTotal << " puntos" << endl;
        cout << "-------------------------------------------------------" << endl;
        system("pause");
        puntajeMaximoRonda = 0;

        for (int i = 0; i < rondas; ++i) {
            cout << "LANZAMIENTO N° " << i + 1 << endl;

            // Simular lanzamiento de dados
            vector<int> dados(numerodedados);
            for (int j = 0; j < numerodedados; ++j) {
                dados[j] = lanzarDado();
                cout << dados[j] << " ";
            }
            cout << endl;

            // Calcular puntaje del lanzamiento
            int puntajeLanzamiento = evaluarDados(dados);
            cout << "Puntaje de ronda: " << puntajeLanzamiento << " puntos" << endl;

            // Evaluar si hay escalera o sexteto de 6
            if (verificarEscalera(dados)) {
                cout << "¡Escalera! ¡Has ganado la partida en esta ronda!" << endl;
                juegoGanado = true;
                break;
            }
            if (verificarSextetoSeis(dados)) {
                jugador2.puntajeTotal = 0;
                cout << "¡Sexteto6! Puntaje total reseteado a 0." << endl;
                break;
            }

            // Actualizar máximo puntaje de la ronda
            if (puntajeLanzamiento > puntajeMaximoRonda) {
                puntajeMaximoRonda = puntajeLanzamiento;
            }
        }

        // Sumar máximo puntaje de la ronda al puntaje total
        jugador2.puntajeTotal += puntajeMaximoRonda;

        // Verificar si se alcanzó o superó el puntaje objetivo
        if (jugador2.puntajeTotal >= puntajemaximo && !juegoGanado) {
            cout<<"--------------------------------------------------------------------"<<endl;
            cout << "¡Felicidades! " << jugador2.nombre << " has alcanzado " << puntajemaximo << " ¡Ganaste!" << endl;
            cout<<"--------------------------------------------------------------------"<<endl;
            juegoGanado = true;
            break;
        }

        system("pause");
        ++numeroRonda;
    }

}




void mayorPuntaje(){
cout << endl;
cout << "------------------------------------------------------" << endl;
cout << "La puntuacion mas alta obtenida hasta ahora es: " <<endl;
cout << "------------------------------------------------------" << endl;
cout << endl;
}

void modosimulado () {











    }

void reglas () {
                cout <<" ---------------------------------------------------------------------" << endl;
                cout<< "                              REGLAS DEL JUEGO                        " << endl;
                cout <<" ----------------------------------------------------------------------" << endl;
                cout << endl;
                cout << "El objetivo del juego es obtener al menos 100 puntos en la menor cantidad posible de rondas,"<< endl;
                cout << "o sacar una escalera en un lanzamiento." << endl;
            cout << endl;
                cout << "RONDAS:"<< endl;
                cout << "Una ronda está compuesta por 3 lanzamientos. Un lanzamiento consiste en tirar seis dados y evaluar sus valores para determinar el puntaje." << endl;
            cout << endl;

                cout << "PUNTAJE:"<< endl;
                cout << "El puntaje de un lanzamiento esta determinado por una serie de reglas que figuran en la sección Combinaciones con puntos." << endl;
            cout << endl;
                cout << "LANZAMIENTO:"<< endl;
                cout << "El puntaje final de la ronda será el valor maximo de los puntos obtenidos en los 3 lanzamientos (no la suma de los tres, sino el más alto), con las siguientes excepciones:" ;
                cout << "Si en un lanzamiento se obtiene escalera el jugador GANA EL PARTIDO en ese momento" << endl;
                cout << "Si en un lanzamiento se obtiene una combinación de 6 dados con valor 6, el puntaje total de la persona se resetea a 0" << endl;
            cout << endl;
                cout << "REGLAS PARA 2 JUGADORES:"<< endl;
                cout << "Para el caso de la opcion para 2 jugadores, cada jugador debe completar una ronda(3 lanzamientos) alternativamente." << endl;
            cout << endl;
                cout << "COMBINACION DE PUNTOS:" << endl;
                cout << "|Suma de dados:| Suma de los valores de todos los dados ( A exepcion de los 6 iguales ) por ejemplo: 1+1+2+2+3+5= 14" << endl;
                cout << "|Sexteto X (X es el número del dado)|: 6 dados iguales (menos para el número 6) ejemplo 5(x)*10 puntos= 50 puntos" << endl;
                cout << "|Escalera|: Gana la partida en esa ronda por la combinacion de los 6 numeros diferentes" << endl;
                cout << "|Sexteto6|: Resetea el puntaje total a 0" << endl;
            cout << endl;
                }












#endif // MENU_H_INCLUDED
