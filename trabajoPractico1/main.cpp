#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>

using namespace std;

int** generarMatrizVacia(int n, int m){
    //Asignación de memoria dinamica para las filas
    int** matriz = new int*[n];
    //Asignación de memoria dinamica para las columnas
    for (int i = 0; i<n; i++){
        matriz[i] = new int[m];
    }

    return matriz;
}

// 1)
int** matrizRandom(int n, int m, int max = 100){
    //Creacion de la matriz vacía
    int** matriz = generarMatrizVacia(n, m);
    //Inicialización en un valor entero (aleatorio)
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            matriz[i][j] = rand() % (max + 1);
        }
    }

    return matriz;
}

// 2)
int** sumarMatrizes(int** matrizA, int**matrizB, int n, int m){
    //Creación de la matriz vaciía
    int** nuevaMatriz = generarMatrizVacia(n, m);
    //Suma de las matrizes A y B y asignación de los valores en la nueva matriz
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            nuevaMatriz[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }

    return nuevaMatriz;
}

// 3)
void llenarMatriz(int num, int n, int m, int** &matriz){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            matriz[i][j] = num;
        }
    }
}

// 4)
//(En este caso al usar la función se elimina la matriz original)
int** rotarMatriz(int** &matriz, int n, int m){
    int** matrizRotada = generarMatrizVacia(m, n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            matrizRotada[j][i] = matriz[i][j]; //intercambio de filas por columnas
        }
    }
    delete[] matriz;
    return matrizRotada;
}

// 5)
void llenarMatriz(int num1, int num2, int n, int m, int** &matriz){
    int numero;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            //elección "aleatoria" del número a asignar
            if((rand() % 2) == 0) {
                numero = num1;
            } else {
                numero = num2;
            }
            //asignación del número
            matriz[i][j] = numero;
        }
    }
}

// 6)
void informesMatriz(int** matriz, int n, int m){
    int suma = 0;
    int sumaPar = 0;
    int sumaImpar = 0;
    int* sumaFilas = new int[n];
    memset(sumaFilas, 0, sizeof(int) * n); //inicialización del vector dinamico de las filas en 0
    int* sumaColumnas = new int[m];
    memset(sumaColumnas, 0, sizeof(int) * m); //inicialización del vector dinamico de las columnas en 0
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(matriz[i][j] > 100) {
                cout<<"La matriz contiene números mayores al 100";
                return;
            }
            //a)
            suma += matriz[i][j];
            //b)
            if((matriz[i][j] % 2) == 0){
                sumaPar += matriz[i][j];
            }
            //c)
            else {
                sumaImpar += matriz[i][j];
            }
            //d)
            sumaColumnas[j] += matriz[i][j];
            //e)
            sumaFilas[i] += matriz[i][j];
        }
    }
    //informes:
    cout<<"Suma de todos los números almacenados en la Matriz: "<<suma<<endl;
    cout<<"Suma de los números pares: "<<sumaPar<<endl;
    cout<<"Suma de los números impares: "<<sumaImpar<<endl;
    cout<<"Suma de todos los valores de cada columna: "<<endl;
    for(int i = 0; i<m; i++){
        cout<<"Columna "<<i<<": "<<sumaColumnas[i]<<endl;
    }
    cout<<"Suma de todos los valores de cada fila: "<<endl;
    for(int i = 0; i<n; i++){
        cout<<"Fila "<<i<<": "<<sumaFilas[i]<<endl;
    }

    delete[] sumaFilas;
    delete[]  sumaColumnas;
}

// 7)
void modificarSubyacentes(int** &matriz, int n, int m, int valor, int nuevoValor, int fila, int columna){
    //En el caso de que sea el valor determinado, se reemplaza por el nuevo valor
    if(matriz[fila][columna] == valor){
        matriz[fila][columna] = nuevoValor;
    }
    //Cambio de valores adyacentes
    if(fila > 0){
        matriz[fila - 1][columna] = nuevoValor;
    }
    if(fila < (n - 1)){
        matriz[fila + 1][columna] = nuevoValor;
    }
    if(columna > 0){
        matriz[fila][columna - 1] = nuevoValor;
    }
    if(columna < (m - 1)){
        matriz[fila][columna + 1] = nuevoValor;
    }
}

// 8)
bool cargarEnPosRandom(int** &matriz, int n, int m, int valor, int nuevoValor){
    int fila = rand() % n;
    int columna = rand() % m;
    int ady = 0;
    if(matriz[fila][columna] == valor){
        //Contando adyacentes
        //arriba
        if(fila > 0){
            if(matriz[fila - 1][columna] == valor) ady++;
        }
        //abajo
        if(fila < (n - 1)){
            if(matriz[fila + 1][columna] == valor) ady++;
        }
        //izquierda
        if(columna > 0){
            if(matriz[fila][columna - 1] == valor) ady++;
        }
        //derecha
        if(columna < (m - 1)){
            if(matriz[fila][columna + 1] == valor) ady++;
        }
    }
    if(ady >= 2){
        matriz[fila][columna] = nuevoValor;
        return true;
    } else return false;
}

//La siguiente funcion tiene el proposito de hacer más "sencillo" el informe de los resultados de cada actividad
void recorrerMatriz(int** matriz, int n, int m){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<setw(5)<<matriz[i][j];
        }
        cout<<endl;
    }
}

int main()
{
    //Inicializacion de la seed de numeros aleatorios
    //srand(time(NULL));

    //Informe/Prueba de todas las actividades:
    cout<<"Trabajo Práctico de POO"<<endl
       <<"Alumno: Ledesma Alejo Tomás"<<endl;
    //Actividad 1)
    int** matrizA = matrizRandom(3, 3);
    cout<<endl<<"Actividad 1)"<<endl
       <<"Matriz resultante: "<<endl;
    recorrerMatriz(matrizA, 3, 3);
    //Actividad 2)
    int** matrizB = matrizRandom(3, 3, 200);
    int** matrizSumada = sumarMatrizes(matrizA, matrizB, 3, 3);
    cout<<endl<<"Actividad 2)"<<endl
       <<"Matriz resultante de la suma:"<<endl;
    recorrerMatriz(matrizSumada, 3, 3);
    //Actividad 3)
    llenarMatriz(9, 3, 3, matrizA);
    cout<<endl<<"Actividad 3)"<<endl
       <<"Matriz resultante:"<<endl;
    recorrerMatriz(matrizA, 3, 3);
    //Actividad 4)
    cout<<endl<<"Actividad 4)"<<endl
       <<"Matriz Original:"<<endl;
    recorrerMatriz(matrizB, 3, 3);
    int** matrizRotada = rotarMatriz(matrizB, 3, 3);
    cout<<endl<<"Matriz Rotada:"<<endl;
    recorrerMatriz(matrizRotada, 3, 3);
    //Actividad 5)
    llenarMatriz(1, 0, 3, 3, matrizA);
    cout<<endl<<"Actividad 5)"<<endl
       <<"Matriz resultante:"<<endl;
    recorrerMatriz(matrizA, 3, 3);
    //Actividad 6)
    int** matrizC = matrizRandom(3, 3);
    cout<<endl<<"Actividad 6)"<<endl
       <<"Informes de la matriz:"<<endl;
    informesMatriz(matrizC, 3, 3);
    //Actividad 7)
    cout<<endl<<"Actividad 7)"<<endl
       <<"Matriz original:"<<endl;
    recorrerMatriz(matrizA, 3, 3);
    modificarSubyacentes(matrizA, 3, 3, 1, 0, 2, 0);
    cout<<endl<<"Matriz modificada:"<<endl;
    recorrerMatriz(matrizA, 3, 3);
    //Actividad 8)
    cout<<endl<<"Actividad 8)"<<endl;
    if(cargarEnPosRandom(matrizA, 3, 3, 1, 0)){
        cout<<"Matriz resultante (usando la matriz anterior):"<<endl;
        recorrerMatriz(matrizA, 3, 3);
    } else cout<<"La posición generada aleatoriamente no cumple con los requisitos, vuelve a intentar.."<<endl;
    return 0;
}
