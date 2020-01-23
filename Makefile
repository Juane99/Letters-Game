SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: clean $(BIN)/cantidad_letras $(BIN)/testlista_palabras $(BIN)/letras documentacion
# ** Generación de documentación **
documentacion:
	doxygen doc/doxys/Doxyfile

#EJECUTABLES

$(BIN)/cantidad_letras: $(OBJ)/cantidad_letras.o  $(OBJ)/ConjuntoLetras.o $(OBJ)/lista_palabras.o $(OBJ)/Letra.o 
	g++ -std=c++11 -o $(BIN)/cantidad_letras $(OBJ)/cantidad_letras.o $(OBJ)/ConjuntoLetras.o $(OBJ)/lista_palabras.o $(OBJ)/Letra.o 

$(BIN)/testlista_palabras: $(OBJ)/testlista_palabras.o  $(OBJ)/ConjuntoLetras.o $(OBJ)/bolsa_letras.o $(OBJ)/lista_palabras.o $(OBJ)/Letra.o 
	g++ -std=c++11 -o $(BIN)/testlista_palabras $(OBJ)/testlista_palabras.o $(OBJ)/ConjuntoLetras.o $(OBJ)/bolsa_letras.o $(OBJ)/lista_palabras.o $(OBJ)/Letra.o 

$(BIN)/letras: $(OBJ)/letras.o  $(OBJ)/ConjuntoLetras.o $(OBJ)/bolsa_letras.o $(OBJ)/lista_palabras.o $(OBJ)/Letra.o 
	g++ -std=c++11 -o $(BIN)/letras $(OBJ)/letras.o $(OBJ)/ConjuntoLetras.o $(OBJ)/bolsa_letras.o $(OBJ)/lista_palabras.o $(OBJ)/Letra.o 

#OBJETOS


$(OBJ)/testlista_palabras.o: $(SRC)/testlista_palabras.cpp $(OBJ)/ConjuntoLetras.o $(OBJ)/Letra.o
	g++ -std=c++11 -o $(OBJ)/testlista_palabras.o -c $(SRC)/testlista_palabras.cpp -I./$(INC) 

$(OBJ)/letras.o: $(SRC)/letras.cpp $(OBJ)/ConjuntoLetras.o $(OBJ)/Letra.o
	g++ -std=c++11 -o $(OBJ)/letras.o -c $(SRC)/letras.cpp -I./$(INC) 

$(OBJ)/cantidad_letras.o: $(SRC)/cantidad_letras.cpp $(OBJ)/ConjuntoLetras.o $(OBJ)/Letra.o
	g++ -std=c++11 -o $(OBJ)/cantidad_letras.o -c $(SRC)/cantidad_letras.cpp -I./$(INC) 

$(OBJ)/ConjuntoLetras.o: $(SRC)/ConjuntoLetras.cpp $(INC)/ConjuntoLetras.hpp $(OBJ)/Letra.o

	g++ -std=c++11 -o $(OBJ)/ConjuntoLetras.o -c $(SRC)/ConjuntoLetras.cpp -I./$(INC) 

$(OBJ)/Letra.o: $(SRC)/Letra.cpp $(INC)/Letra.hpp 

	g++ -std=c++11 -o $(OBJ)/Letra.o -c $(SRC)/Letra.cpp -I./$(INC) 

$(OBJ)/bolsa_letras.o: $(SRC)/bolsa_letras.cpp $(INC)/bolsa_letras.hpp $(OBJ)/ConjuntoLetras.o

	g++ -std=c++11 -o $(OBJ)/bolsa_letras.o -c $(SRC)/bolsa_letras.cpp -I./$(INC)

$(OBJ)/lista_palabras.o: $(SRC)/lista_palabras.cpp $(INC)/lista_palabras.hpp 

	g++ -std=c++11 -o $(OBJ)/lista_palabras.o -c $(SRC)/lista_palabras.cpp -I./$(INC)

# ** Limpieza **
clean :
	@-rm $(OBJ)/* $(BIN)/*
mrproper : clean
	@-rm $(BIN)/* doc/html/*
