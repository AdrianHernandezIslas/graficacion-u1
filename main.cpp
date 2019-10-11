#include <iostream>
#include <vector>
#include <queue>
#include "acciones.h"


vector<vector<char>> matriz;
queue<vector<int>> cola;

int main(){
    rellenarMatriz(matriz,10);
    cola = linea(2,7,10,1);
    dibujar(cola,matriz);
    cin.get();
    return 0;
}


