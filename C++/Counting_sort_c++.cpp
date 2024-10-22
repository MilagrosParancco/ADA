#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
using namespace std;

void Counting_sort(int array[],int size);
void imprimir(int array[],int size);
void LeerArchivo(int* numeros,int rango);

int main(){
    const int rango=100;
	int array[rango];
	LeerArchivo(array,rango);
	cout<<"Array Original: ";
	imprimir(array,rango);
    auto startTime = chrono::high_resolution_clock::now();
    Counting_sort(array,rango);
    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::duration<double>>(endTime - startTime).count();
    cout<<endl;
    cout<<"Duración: "<<duration<<" segundos."<<endl;
    cout<<"\nArreglo ordenado: ";
    imprimir(array, rango);
	return 0;
}

void Counting_sort(int array[], int size){
    int max=array[0],min=array[0],range;
    for(int i=0;i<size;i++){
        if(array[i]>max){
            max=array[i];
        }
        if(array[i]<min){
            min=array[i];
        }
    }
    range=max-min+1;
    int conteo[range]={0};
    int salida[size];

    for(int i=0;i<size;i++){
        conteo[array[i]-min]++;
    }
    for(int i=1;i<range;i++){
        conteo[i]+=conteo[i-1];
    }
    for(int i=size-1;i>=0;i--){
        salida[conteo[array[i]-min]-1]=array[i];
        conteo[array[i]-min]--;
    }
    for(int i=0;i<size;i++){
        array[i]=salida[i];
    }
    imprimir(array,size);
    
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