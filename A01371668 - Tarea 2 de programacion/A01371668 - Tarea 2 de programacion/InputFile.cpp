/*
*	Autor: Alonso Issac Morales Gutiérrez
*	Matrícula: A01371668
*	Fecha: 21/Agosto/2017
*/

#include "InputFile.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

std::string InputFile::GetContents() {
	return _contents;
}

bool InputFile::Read(std::string filename) {
	//Abrimos el archivo recibido "filename"
	ifstream archivo;
	archivo.open(filename);

	//Validamos el archivo
	if (!archivo) {
		_contents = "";
		return false; //Como el archivo está vacio regresamos false
	} else {
		//variable registro de tipo stringstream es para almacenar lo que contenga el archivo txt
		string linea;
		stringstream registro;
		while (getline(archivo, linea)) { //Obtenemos cada línea del archivo txt
			registro << linea << "\n";
		}
		_contents = registro.str(); //convertimos lo recibido en variable registro a tipo string
		archivo.close(); //cerramos el archivo
		return true; //Como el archivo si contiene datos regresamos true
	}
}