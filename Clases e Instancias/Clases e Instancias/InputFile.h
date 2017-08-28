/*
*	Autor: Alonso Issac Morales Gutiérrez
*	Matrícula: A01371668
*	Fecha: 21/Agosto/2017
*/

#pragma once
#include <string>

class InputFile {
public:
	bool Read(std::string filename);
	std::string GetContents();
private:
	std::string _contents;
};