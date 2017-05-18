// Agrega_Clase_ListaDE-MO.cpp: archivo de proyecto principal.


#include "stdafx.h"
#include "iostream"

using namespace System;
using namespace std;

int linea, op;

void fijo()
{
	Console::WriteLine(L"===========================================================");
	Console::WriteLine(L"Listas Ordenadas Doblemente Enlasadas: programa interactivo");
	Console::WriteLine(L"===========================================================");
}

void limpiaopciones()
{
	int i;
	linea = 5;
	Console::SetCursorPosition(3, linea);
	for (i = 1; i <= 25; i = i + 1)
	{
		cout << "                                            ";
	}

	linea = 5;
}

void opciones()
{

	linea = 5;
	Console::SetCursorPosition(3, linea);
	Console::WriteLine(L"Opciones");
	Console::WriteLine(L"1. Añadir nodos");
	Console::WriteLine(L"2. Eliminar nodo");
	Console::WriteLine(L"3. Desplegar lista");
	Console::WriteLine(L"4. Salir");
	cout << "\n\n   Digite opcion ";
	cin >> op;
	limpiaopciones();
}

struct nodo
{
	int dato;
	nodo *ant;
	nodo *sig;
};

class Lde
{
private:
	nodo *inicial;
	nodo *buscarLista(int clave);
public:
	Lde();
	~Lde();
	void agregar();
	void eliminar();
	void desplegarLista();
};

Lde::Lde()
{
	inicial = NULL;
}

Lde::~Lde()
{
	nodo *apun = inicial;
	while (apun != NULL)
	{
		inicial = apun->sig;
		delete apun;
		apun = inicial;
	}
}

void Lde::desplegarLista()
{
	linea = 5;
	Console::SetCursorPosition(0, linea);
	linea = linea + 1;
	Console::SetCursorPosition(0, linea);

	if (inicial == NULL)
	{
		cout << "La lista esta vacia" << endl;
	}
	else
	{
		nodo *apunt;
		apunt = inicial;
		while (apunt != NULL)
		{
			cout << apunt->dato << endl;
			apunt = apunt->sig;
		}
	}
	system("pause");
}

nodo *Lde::buscarLista(int clave)
{
	nodo *anterior;
	anterior = NULL;
	if (clave <= inicial->dato) //Si es verdad significa que debe ir de primero
	{
		return anterior;
	}
	else
	{
		anterior = inicial;
		while ((anterior->sig != NULL) && (clave > anterior->sig->dato))
		{
			//Aqui compara el valor de cada dato
			anterior = anterior->sig;
		}
		return anterior;
	}
}

void Lde::eliminar()
{
	char resp;
	int codigo;
	nodo *apun;
	nodo *aux;
	do
	{
		linea = 5;
		Console::SetCursorPosition(3, linea);
		linea = linea + 1;
		Console::SetCursorPosition(3, linea);

		cout << endl;
		cout << "Entre codigo clave (Digite codigo a eliminar)" << endl;
		cin >> codigo;
		apun = buscarLista(codigo);
		aux = inicial;
		if (apun == NULL) //Es por que es el primero el que voy a eliminar
		{
			if (aux->dato == codigo)
			{
				inicial = aux->sig;
				inicial->ant = NULL;
				delete aux;
			}
			else
			{
				cout << "El nodo a eliminar no existe" << endl;
			}
		}
		else
		{
			if (apun->sig != NULL) // Si es verdadero es porque codigo es menor que el maximo codigo entre los nodos
			{                    // Y apun seguira apuntando al nodo que antecede al eliminar
				if (apun->sig->dato == codigo && apun->sig->sig != NULL) //Corrobora q no sea el ultimo
				{
					//aux nodo a eliminar
					aux = apun->sig;
					apun->sig = aux->sig;
					aux->sig->ant = apun;
					delete aux;
				}
				else //Eliminar el ultimo
				{
					aux = apun->sig;
					apun->sig = NULL;
					delete aux;
				}
			}
			else  //De lo contrario es porque codigo es mayor y apun sera igual al ultimo nodo
			{
				cout << "El nodo a eliminar no existe" << endl;
			}
		}
		cout << "Desea eliminar otro nodo (s/n)" << endl;
		cin >> resp;
		resp = tolower(resp);
		limpiaopciones();
	} while (resp == 's');
	limpiaopciones();
}

void Lde::agregar()
{
	nodo *nuevo, *anterior;
	char resp;
	do
	{
		linea = 5;
		Console::SetCursorPosition(3, linea);
		linea = linea + 1;
		Console::SetCursorPosition(3, linea);

		nuevo = new nodo();
		cout << "Entre clave del nodo a agregar" << endl;
		cin >> nuevo->dato;
		if (inicial == NULL)
		{
			//Agregar el primer nodo a la lista
			inicial = nuevo;
			nuevo->ant = NULL;
			nuevo->sig = NULL;
		}
		else
		{
			//Agrega a una lista que contiene al menos un nodo
			anterior = buscarLista(nuevo->dato);
			if (anterior == NULL)
			{
				//Agregar un nodo que queda de primero
				//en unal ista que no estaba vacia
				if (nuevo->dato == inicial->dato) cout << "El nodo a agregar ya existe" << endl;
				else
				{
					nuevo->sig = inicial;
					nuevo->ant = inicial->ant;
					inicial->ant = nuevo;
					inicial = nuevo;
				}
			}
			else
			{
				//
				if (anterior->sig != NULL)
				{
					//Agregs un nodo que queda entre el
					//primero y el ultimo
					if (nuevo->dato == anterior->sig->dato) cout << "El nodo a agregar ya existe" << endl;
					else
					{
						nuevo->sig = anterior->sig;
						nuevo->ant = anterior;
						anterior->sig->ant = nuevo;
						anterior->sig = nuevo;
					}
				}
				else
				{
					//Agregar un nodo que queda de ultimo
					//[...]
					nuevo->sig = anterior->sig;
					nuevo->ant = anterior;
					anterior->sig = nuevo;
				}
			}
		}
		cout << "Desea agregar otro nodo? (s/n)" << endl;
		cin >> resp;
		resp = tolower(resp);
		limpiaopciones();
	} while (resp == 's');
	limpiaopciones();
}

int main()
{
	Lde l;
	fijo();
	do
	{
		opciones();
		switch (op)
		{
		case 1: { l.agregar(); limpiaopciones(); break; }
		case 2: { l.eliminar(); limpiaopciones(); break; }
		case 3: { l.desplegarLista(); limpiaopciones(); break; }

		}
	} while (op != 4);

	Console::WriteLine(L"Termina sistema ");
	system("pause");
}
