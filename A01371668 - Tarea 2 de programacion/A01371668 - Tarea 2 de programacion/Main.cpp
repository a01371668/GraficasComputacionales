/*
*	Autor: Alonso Issac Morales Guti�rrez
*	Matr�cula: A01371668
*	Fecha: 21/Agosto/2017
*/

#include <iostream>
#include <string>
#include "InputFile.h"

int main(int argc, char* argv[])
{
	std::string filename = "Prueba.txt";
	InputFile myFile;
	myFile.Read(filename);
	std::string contents = myFile.GetContents();
	std::cout << "Contents: " << contents << std::endl;

	std::cin.get();
	return 0;
}