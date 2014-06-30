#include <iostream>
#include <tablero.h>
#include <stdlib.h>



    //0 = jugada invalida
    //1 = jugada aceptada
    //2 = juego terminado
 int preguntar_columna(char ficha){
    int columna;
    cout << "Donde desea jugar " << ficha << ": ";
    cin >> columna;
    return columna;
 }

int preguntar_maquina(char ficha, Tablero table){

    return rand() % table.getN() + 1;
 }

void connectX(char ficha1, char ficha2, Tablero table){
    int jugada1 = 0;
    int jugada2 = 0;

    while (true){

        //jugador 1
        while(jugada1 == 0){
            jugada1 = table.jugada(ficha1, preguntar_columna(ficha1));
        }
        if (jugada1 == 2){
            break;
        }else{
            jugada1 = 0;
        }

        //si ficha2 == 0 entonces juega la maquina
        if (ficha2 == 'M'){
            while(jugada2 == 0){
                jugada2 = table.jugada(ficha2, preguntar_maquina(ficha2, table));
            }
            if (jugada2 == 2){
                break;
            }else{
                jugada2 = 0;
            }
        } else {
            while(jugada2 == 0){
                jugada2 = table.jugada(ficha2, preguntar_columna(ficha2));
            }
            if (jugada2 == 2){
            break;
            }else{
                jugada2 = 0;
            }
        }
    }

}

using namespace std;
int main()
{
    Tablero table;


    char ficha1 = ' ';
    char ficha2 = ' ';
    char again;


    cout << "Saludos Jugador 1: Ingrese su caracter de juego: ";
    cin >> ficha1;

    cout << "Saludos Jugador 2: Ingrese su caracter de juego (use M pa jugar contra la maquina): ";
    cin >> ficha2;



    do {
        connectX(ficha1, ficha2, table);
        cout << "Le gustaria jugar de nuevo? y/n: " ;
        cin >> again;
    } while (again == 'y');










    return 0;
}
