#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
using namespace std;

void selectionSort(int array[], int size);
void imprimir(int array[], int size);
void LeerArchivo(int* numeros,int rango);

int main(){
    const int rango=100;
	int array[rango];
	LeerArchivo(array,rango);
	cout<<"Array Original: ";
	imprimir(array,rango);
    auto startTime = chrono::high_resolution_clock::now();
    selectionSort(array, rango);
    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::duration<double>>(endTime - startTime).count();
    cout<<endl;
    cout<<"Duración: "<<duration<<" segundos."<<endl;
    cout<<"\nArreglo ordenado: ";
    imprimir(array, rango);
	return 0;
}

void selectionSort(int array[], int size){
    for(int i=0;i<size-1;i++){
        int minIndex=i;
        for(int j=i+1;j<size;j++){
            if(array[j]<array[minIndex]){
                minIndex=j;
            }
        }
        swap(array[i],array[minIndex]);
    }
}

void imprimir(int array[], int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
void LeerArchivo(int* numeros, int rango) {
	string ruta="D:/gersael/java/Crear_numeros/"+to_string(rango) + ".txt";
    ifstream archivo(ruta);
    if (!archivo.is_open()){
        cerr<<"Error al abrir el archivo: "<<ruta<<endl;
        return;
    }
	string linea;
    int i=0;
    while(getline(archivo, linea) && i<rango) {
        istringstream iss(linea);
        int numero;
        while (iss>>numero && i<rango){
            numeros[i]=numero;
            i++;
        }
    }

    archivo.close(); // Cerrar el archivo
}