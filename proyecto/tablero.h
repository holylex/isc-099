#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>
#include <vector>
#include <GestorConfiguracion.h>
using namespace std;
using std::vector;

class Tablero{
private:
    int N, M, X;
    vector<vector<char> > tablero;

    void get_values(){
        //Trae los valores de configuracion del juego
        //N filas
        //M columnas
        //X máximo número de bolas contiguas para determinar a un ganador
        GestorConfiguracion gc;
        gc.Cargar("conf.properties");
        istringstream bufferN(gc.valorDe("N"));
        bufferN >> N;
        istringstream bufferM(gc.valorDe("M"));
        bufferM >> M;
        istringstream bufferX(gc.valorDe("X"));
        bufferX >> X;
    }

    void init_tablero(){
        tablero.resize(N);
        for (int i=0; i<N; i++){
            tablero[i].resize(M);
            for (int j=0; j<M; j++){
                tablero[i][j] = '.';
            }
        }
    }

    int gameover(char ficha){
        //revisa si el juego termino
        //0 = no termino
        //1 = empate
        //2 = ganador



        //revisa linea horizontal
        for (int i=0; i<N; i++){
            int count = 0;
            for (int j=0; j<M; j++){
                if (tablero[i][j] == ficha){
                    count++;
                    if (count >= X){
                        return 2;
                    }
                } else {
                    count = 0;
                }
            }
        }

        //revisa linea vertical
        for (int i=0; i<M; i++){
            int count = 0;
            for (int j=0; j<N; j++){
                if (tablero[j][i] == ficha){
                    count++;
                    if (count >= X){
                        return 2;
                    }
                } else {
                    count = 0;
                }
            }
        }

        //revisa linea diagonal derecha
        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                int count = 0;
                for (int k=0; (k<X && i+k < N && j+k < M); k++){
                        //cout << k << endl;
                    if (tablero[i+k][j+k] == ficha){
                        count++;

                        if (count >= X){
                            return 2;
                        }
                    }else {
                        count = 0;
                    }
                }
            }
        }

        //revisa linea diagonal izquierda
        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                int count = 0;
                for (int k=0; (k<X && i-k > -1 && j+k < M); k++){
                        //cout << k << endl;
                    if (tablero[i-k][j+k] == ficha){
                        count++;

                        if (count >= X){
                            return 2;
                        }
                    }else {
                        count = 0;
                    }
                }
            }
        }

        //revisa tablero lleno
        bool espacios_vacios = false;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(tablero[i][j] == '.'){
                    espacios_vacios = true;
                }
            }
        }
        if (!espacios_vacios){
            return 1;
        }

        return 0;
    }
public:

Tablero(){
    get_values();
    init_tablero();
}

int getN(){
    return N;
 }

void draw(){
    cout << "tablero: " << endl;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cout << tablero[i][j] << ' ';
        }
        cout << endl;
    }
}

int jugada(char ficha, int columna){
    //0 = jugada invalida
    //1 = jugada aceptada
    //2 = juego terminado
    if (columna < 1 || columna > M){
        //invalid move
        cout << "jugada invalida" << endl;
        return 0;
    }
    columna--; //ajuste para empezar a contar en 1
    for (int i=tablero.size()-1; i>-1; i--){
        if(tablero[i][columna] == '.'){
            tablero[i][columna] = ficha;
            draw();
            switch (gameover(ficha)){
            //0 = no termino
            //1 = empate
            //2 = ganador
            case 0:
                return 1;
                break;
            case 1:
                cout << "El juego ha empatado" << endl;
                return 2;
                break;
            case 2:
                cout << "El jugado " << ficha << " ha ganado!!!" << endl;
                return 2;
                break;
            default:
                return 1;
            }
        }
    }
    //invalid play
    //Si llega aqui la ficha no cabe en la columna
    draw();
    return 0;

}
};

#endif // TABLERO_H
