#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
using namespace std;
void imprimir(int array[],int size);
void heap_sort(int array[],int size);
void heapify(int array[],int n,int i);
void LeerArchivo(int* numeros,int rango);
int main(){
    const int rango=100;
	int array[rango];
	LeerArchivo(array,rango);
	cout<<"Array Original: ";
	imprimir(array,rango);
    auto startTime = chrono::high_resolution_clock::now();
    heap_sort(array,rango);
    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::duration<double>>(endTime - startTime).count();
    cout<<endl;
    cout<<"Duración: "<<duration<<" segundos."<<endl;
    cout<<"\nArreglo ordenado: ";
    imprimir(array, rango);
	return 0;
}
void heap_sort(int array[],int size){
    int n=size;
    for(int i=n/2-1;i>=0;i--) {
            heapify(array,n,i);
        }

    for (int i=n-1;i>0;i--) {
        int aux=array[0];
        array[0]=array[i];
        array[i]=aux;
        heapify(array, i, 0);
    }
}
void heapify(int array[],int n,int i){
    int indice_mayor= i;
    int hijo_izquierdo=2*i+1;
    int hijo_derecho=2*i+2;

    if (hijo_izquierdo<n && array[hijo_izquierdo]>array[indice_mayor]) {
        indice_mayor=hijo_izquierdo;
    }
    if (hijo_derecho<n && array[hijo_derecho] > array[indice_mayor]) {
        indice_mayor=hijo_derecho;
    }

    if (indice_mayor!=i) {
        int aux=array[i];
        array[i]=array[indice_mayor];
        array[indice_mayor]=aux;
        heapify(array, n, indice_mayor);
    }
}
void imprimir(int array[],int size){
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