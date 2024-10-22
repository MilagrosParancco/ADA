#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
using namespace std;

void quickSort(int array[], int low, int high);
int partition(int array[], int low, int high);
void imprimir(int array[], int size);
void LeerArchivo(int* numeros,int rango);
int main(){
    const int rango=100;
	int array[rango];
	LeerArchivo(array,rango);
	cout<<"Array Original: ";
	imprimir(array,rango);
    auto startTime = chrono::high_resolution_clock::now();
    quickSort(array, 0, rango-1);
    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::duration<double>>(endTime - startTime).count();
    cout<<endl;
    cout<<"Duración: "<<duration<<" segundos."<<endl;
    cout<<"\nArreglo ordenado: ";
    imprimir(array, rango);
	return 0;
}

void quickSort(int array[],int low,int high){
    if(low<high){
        int partitionIndex=partition(array,low,high);
        quickSort(array,low, partitionIndex-1);
        quickSort(array,partitionIndex+1, high);
    }
}

int partition(int array[], int low, int high){
    int pivot=array[high];
    int i=low-1;

    for (int j=low;j<high;j++){
        if(array[j]<=pivot) {
            i++;
            swap(array[i],array[j]);
        }
    }

    swap(array[i+1],array[high]);
    return i+1;
}

void imprimir(int array[], int size){
    for (int i=0;i<size;i++) {
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
