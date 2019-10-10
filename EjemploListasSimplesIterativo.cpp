#include <iostream>
#include<cstdlib>
using namespace std;
int contador=0;

struct nodo{
	int dato;
	struct nodo *sig;
};

void menu();
nodo *crearNodo();
void insertarNodoFinal(nodo *&nuevo, nodo *&ini, nodo *&actual);
void insertarNodoInicio(nodo *&nuevo, nodo *&ini);
void mostrarLista(nodo *inicio);


int main(){
	system("color 4f");
	//este puntero se va a quedar siempre en el primer nodo de la lista
	nodo *inicio=NULL;
	//Este puntero siempre estara en el ultimo nodo que sea ingresado
	nodo *nodoActual=NULL;
	int opcion;
	nodo *aux=NULL;
	
	do{
		menu();
		cout << "ingrese opcion: ";
		cin >> opcion;
		switch(opcion){
			case 0:		cout << "saliendo del programa... :D" << endl;
						break;
			case 1:		aux=crearNodo();
			 			insertarNodoFinal(aux,inicio,nodoActual);
						aux=NULL;
						break;
			case 2:		aux=crearNodo();
			 			insertarNodoInicio(aux,inicio);
						aux=NULL;
						break;
			case 3:		mostrarLista(inicio);
						cout<<"NULL"<<endl;
						break;
			
			default:	cout << "opcion invalida...."  << endl;
						break;
		}
	}while(opcion != 0);
	
	
	return 0;
}

void menu(){
	cout << "*************** MENU ***************" << endl;
	cout << "\t0 - salir" << endl;
	cout << "\t1 - insertar nodo a la lista (al final)" << endl;
	cout << "\t2 - insertar nodo a la lista (al inicio)" << endl;
	cout << "\t3 - mostrar lista" << endl;
	cout << "*************** MENU ***************" << endl;
}

nodo *crearNodo(){
	nodo *nuevo_nodo = new nodo();
	cout<<"Ingrese el dato: ";
	cin>>nuevo_nodo->dato;
	nuevo_nodo->sig=NULL;
	return nuevo_nodo;
}
//Al nosotros poner *inicio pasamos unacopia de lo que tiene el puntero
//si pusieramos *&inicio mandariamos el contenido original
void mostrarLista(nodo *inicio){
	while(inicio!=NULL){
		cout<<inicio->dato;
		cout<<"->";
		inicio=inicio->sig;
	}

}

void insertarNodoFinal(nodo *&nuevo, nodo *&ini, nodo *&actual){	
	if(ini==NULL){//si es el primer nodo que ingresamos
		//apuntamos al primero
		ini = nuevo;
		//al ser el primero el unico nodo, actual tambien es el primero
		actual=nuevo;
	}else{
		//Ahora que ya hay mas de un nodo
		actual->sig = nuevo;
		actual = actual->sig;
	}
}

void insertarNodoInicio(nodo *&nuevo, nodo *&ini){	
	//El puntero siguiente del nuevo nodo apuntara a donde apunta el nodo inicial
	nuevo->sig = ini;
	//Ahora que ya enlazamos el puntero siguiente del nuevo nodo falta decir que el nuevo nodo inicial sera el que acabamos de ingresar
	ini = nuevo;	
}
