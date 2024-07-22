#include <iostream>
#include "menu.h"

using namespace std;

int main()
{
    srand(time(0));
    // Mostramos el mensaje de bienvenida

    cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& BIENVENIDO JUGADOR &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
    cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&  ESTAS JUGANDO A    &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
    cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&    ESCALERA        &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "                                        PRESIONE ENTER PARA CONTINUAR" << endl;

    // El usuario tiene que presionar ENTER PARA CONTINUAR


    system ("pause");    // Esperar a que el usuario presione Ente

Jugador jugador1, jugador2;
int opcion;// para declarar el valor de "opcion"


do {

    system("cls"); // para limpiar la consola y que no quede todo feo

    cout <<"-------------------------MENU PRINCIPAL-------------------------" << endl;
    cout <<"----------------------------------------------------------------" << endl;
    cout << endl;
    cout << "1) REGLAS" << endl;
    cout << "2) MODO 1 JUGADOR" << endl;
    cout << "3) MODO 2 JUGADORES" << endl;
    cout << "4) MAYOR PUNTAJE DE LA SESION" << endl;
    cout << endl;
    cout << "0) PARA SALIR DEL MENU" << endl;
    cout << endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<" Escriba la opcion seleccionada y luego presione <ENTER>:  ";
    cin  >> opcion;


    switch (opcion){

        case 0:
                    return 0;
        break;

        case 5:

            cout << "Ingrese el nombre del jugador para el modo simulado: ";
        cin >> jugador1.nombre;
                jugador1.puntaje >= 0;
                modosimulado ();
                cout << "¡Partida finalizada! " << jugador1.nombre << " ha obtenido " << jugador1.puntaje << " puntos." << endl;


            system("pause");

               break;

        case 1:

            system("cls");

                //colocamos la situacion 1 (REGLAS)
            reglas ();

            system("pause");

        break;

        case 2:
            system("cls");
            cout << "------------------------------------------------------" << endl;
            cout << "                      MODO 1 JUGADOR                  " << endl;
            cout << "------------------------------------------------------" << endl;
            cout << "INGRESE SUS DATOS JUGADOR " << endl;
            cout << "INGRESE SU NOMBRE: ";
                cin >> jugador1.nombre;
                jugador1.puntaje >= 0;
                jugar1(jugador1);
                cout<<endl;
                cout<<"---------------------------------------------------------------"<<endl;
                cout << "¡Partida finalizada! " << jugador1.nombre << " ha obtenido " << jugador1.puntaje << " puntos." << endl;
                cout<<"---------------------------------------------------------------"<<endl;
                cout<<endl;

            system("pause");

        break;
        case 3:
            system("cls");
            cout << "------------------------------------------------------" << endl;
            cout << "                    MODO 2 JUGADORES                  " << endl;
            cout << "------------------------------------------------------" << endl;
            cout << "INGRESE SUS DATOS JUGADOR 1 " << endl;
            cout << "INGRESE SU NOMBRE: ";
            cin>> jugador1.nombre;
            jugador1.puntaje >= 0;

            cout <<endl;

            cout << "INGRESE SUS DATOS JUGADOR 2 " << endl;
            cout << "INGRESE SU NOMBRE: ";
             cin>> jugador2.nombre;
             jugador2.puntaje >= 0;

            cout <<endl;
            jugadorPara2( jugador1.nombre, jugador2.nombre);

            system("pause");

            break;
        case 4:
            system("cls");

            mayorPuntaje();

            system("pause");
            break;




                    }
    }while(true);// para repetir el codigo desde el menu


    return 0;
}
