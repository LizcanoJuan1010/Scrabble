#ifndef SCRABBLE_H
#define SCRABBLE_H

#include <string>
#include <functional>
#include <vector>
class Scrabble {
	public:
void inicializarFuncion(const std::string& argumento, const std::vector<std::string>& diccionario);
void iniciarInversoFuncion(const std::string& argumento,std::vector<std::string>& palabrasInv);
void puntajeFuncion(const std::string& argumento, const std::vector<std::string>& diccionario);
void exitfuncion(const std::string& argumento);
void iniciararbolFuncion(const std::string& argumento);
void iniciararbolinversoFuncion(const std::string& argumento);
void palabrasporprefijoFuncion(const std::string& argumento, const std::vector<std::string>& diccionario);
void palabrasporsufijoFuncion(const std::string& argumento, const std::vector<std::string>& diccionario);
void grafodepalabrasFuncion(const std::string& argumento);
void posiblespalabrasFuncion(const std::string& argumento);
};
#include "Scrabble.hxx"
#endif 