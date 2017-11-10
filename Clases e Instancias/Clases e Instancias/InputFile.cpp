/*
*	Autor1: Francisco Geada	Rodriguez	A01168958
*	Autor2: Alonso Morales Gutiérrez	A01371668
*	Gráficas Computacionales
*	Prof. Oriam De Gyves
*/

#include "InputFile.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

std::string InputFile::GetContents() {
	return InputFile::_contents;
}

bool InputFile::Read(std::string _fileName) {
	bool open = false;
	std::ifstream inputFile;
	inputFile.open(_fileName);
	std::string _line;
	InputFile::_contents = "";

	if (inputFile.is_open()) {
		open = true;

		while (getline(inputFile, _line)) {
			InputFile::_contents = _contents + _line;
			InputFile::_contents = _contents + "\n";
		}
		inputFile.close();
	}
	return open;
}