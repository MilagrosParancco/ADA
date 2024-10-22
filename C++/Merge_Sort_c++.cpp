#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
using namespace std;
void merge_sort(int array[], int size);
void imprimir(int array[], int size);
void merge(int array[], int left[], int leftSize, int right[], int rightSize);
void LeerArchivo(int* numeros,int rango);
int main(){
    const int rango=100;
	int array[rango];
	LeerArchivo(array,rango);
	cout<<"Array Original: ";
	imprimir(array,rango);
    auto startTime = chrono::high_resolution_clock::now();
    merge_sort(array,rango);
    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::duration<double>>(endTime - startTime).count();
    cout<<endl;
    cout<<"Duración: "<<duration<<" segundos."<<endl;
    cout<<"\nArreglo ordenado: ";
    imprimir(array, rango);
	return 0;
}
void merge_sort(int array[], int size){
    if (size< 2) {
        return;
    }
    int mid=size/2;
    int* left=new int[mid];
    int* right=new int[size-mid];

    for (int i=0;i<mid;i++) {
        left[i]=array[i];
    }

    for (int i=mid;i<size;i++) {
        right[i-mid]=array[i];
    }

    merge_sort(left,mid);
    merge_sort(right,size-mid);

    merge(array,left,mid,right,size-mid);
    delete[] left;
    delete[] right;
}
void merge(int array[], int left[], int leftSize, int right[], int rightSize) {
    int i=0,j=0,k=0;

    while(i<leftSize && j<rightSize){
        if(left[i]<=right[j]) {
            array[k++]=left[i++];
        }else{
            array[k++]=right[j++];
        }
    }
    while (i<leftSize) {
        array[k++]=left[i++];
    }

    while (j<rightSize) {
        array[k++]=right[j++];
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