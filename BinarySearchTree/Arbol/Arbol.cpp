
#include <iostream>
#include<sstream>
#include "NodoArbol.h"
#include "Abb.h"
#include <fstream> //Lee datos de un .txt
#include <string>
#include <algorithm>
//#include <bits/stdc++.h> 
#include <vector>
#include <string.h>

//Concordance function
bool countOccurences(string palabra, string word)
{
    //Método para buscar una palabra en una linea de texto
    //Entrada: palabra-> es la linea de texto en la que voy a comparar una palabra (word)
    //Salida: Si encuentro una palabra en una linea de texto regreso true, caso contrario false
    stringstream s(palabra);

    //Guardo temporalmente cada palabra de un string
    string temp;

    while (s >> temp) {

        //Si la palabra que busco esta en la oracion manda compare() manda 0
        if (temp.compare(word) == 0) { 
            return true;
        }
    }
    return false;
}
int main()
{
    //HOMEWORK 9. OPCION 1 -> DICCIONARIO    OPCION 2-> POSTFIX EXPRESSIONS CON 2 NUMEROS Y UN OPERADOR ( + - / * ~ )
    int opcion = 0;
    cout << "HOMEWORK 9 TECLEA 1 -> Diccionario  TECLEA 2 -> Postfix expressions con 2 numeros y un operador\n ";
    cin >> opcion;

    if (opcion == 1)
    {
        int cont = 0;
        int hojas = 0;
        int internos = 0;
        Abb arbolito;
        string resp;

        vector<string> renglones; //Vector que almacenará linea por linea de un archivo .txt
        vector <int> numLineas; //Contará todas las lineas del archivo txt para devolver la ubicacion de una palabra

        string filename = "dofi.dat";
        fstream newfile; //Creo un objeto de la clase fstream para leer .txt
        fstream file;
        newfile.open(filename, ios::in); //open a file to perform read operation using file object
        string oneWord;

        // opening file 
        file.open(filename.c_str());
        int contLineas = 0;
        // extraigo palabras de un archivo
        while (file >> oneWord)
        {
            if (oneWord.size() >= 3) { //El diccionario permite solo palabras mayor o igual a 3 y las convierte a minuscula
                std::for_each(oneWord.begin(), oneWord.end(), [](char& c) {
                    c = ::tolower(c);
                    });
                //Borro todo caracter pegado a mi palabra que no sea una letra, ejemplo: Casa, => Casa
                oneWord.erase(std::remove_if(oneWord.begin(),
                    oneWord.end(),
                    [](char c)
                    { return c == ',' || c == '.' || c == ':' || c == ';' || c == '!'; }));
                oneWord.end();

                //Cuando la palabra sea mayor a 3, minuscula y sin caracteres que no sean de la palabra, la inserto al arbol (diccionario)
                arbolito.Inserta(oneWord);
            }
        }

        //En este proceso hago lo mismo pero solo para almacenar linea por linea del txt a un vector <string> renglones

        if (newfile.is_open()) {   //checking whether the file is open
            string tp;
            while (getline(newfile, tp)) { //read data from file object and put it into string.
                //arbolito.Inserta(tp);
                std::cout << tp << "\n"; //print the data of the string
                std::for_each(tp.begin(), tp.end(), [](char& c) {
                    c = ::tolower(c);
                    });
                tp.erase(std::remove_if(tp.begin(),
                    tp.end(),
                    [](char c)
                    { return c == ',' || c == '.' || c == ':' || c == ';' || c == '!'; })); //Excluyo cualquier signo diferente al abecedario
                tp.end();
                renglones.push_back(tp); //Guardo linea por linea
            }

            newfile.close(); //close the file object.
        }

        do {
            std::cout << " \n\n Ingrese la palabra para buscarla. \n Ingrese D + palabra para borrarla.\n ingrese I + palabra para Insertarla.\n C para regresar todas las palabras." << endl;
            getline(cin, resp);
            std::string data = resp;
            // convert string to back to lower case
            std::for_each(data.begin(), data.end(), [](char& c) {
                c = ::tolower(c);
                });

            //Comando borrar palabra
            if (data[0] == 'd' && data[1] == ' ') {//delimito los string a una sola letra para los comandos del diccionario
                std::string s = data;
                std::string delimiter = " ";

                size_t pos = 0;
                std::string token;
                while ((pos = s.find(delimiter)) != (std::string::npos)) {
                    token = s.substr(0, pos);
                    s.erase(0, pos + delimiter.length());
                }
                arbolito.borrar(s);
                std::cout << endl;
                system("pause");
            }

            //Comando insertar palabra
            else if (data[0] == 'i' && data.size() == 1) {//delimito los string a una sola letra para los comandos del diccionario
                std::string s = data;
                std::string delimiter = " ";

                size_t pos = 0;
                std::string token;
                while ((pos = s.find(delimiter)) != (std::string::npos)) {
                    token = s.substr(0, pos);
                    s.erase(0, pos + delimiter.length());
                }
                if (s.size() > 3)
                {
                    arbolito.Inserta(s);
                }
                else {
                    std::cout << "Ingrese una palabra mayor de 3 caracteres..." << endl;
                }

                std::cout << endl;
                system("pause");
            }

            //Comando regresar todas las palabras
            else if (data[0] == 'c' && data.size() == 1)
            {
                vector <string> nums;
                std::cout << "\nTotal de palabras: ";
                std::cout << arbolito.contarNodos(arbolito.getRoot(), cont) << endl;
                arbolito.preorden(arbolito.getRoot()); 
                std::cout << endl;
                system("pause");
            }
            //Si escribo sólo la palabra sin comando me indica si encontró la palabra y la linea en la que está
            else {
                if (arbolito.buscar(data)) {
                    numLineas.clear(); 
                    int numLinea = 0;
                    for (int i = 0; i < renglones.size(); i++)
                    {
                        numLinea++;
                        //Al encontrar una palabra en un renglón, guardo en el vector el numero de linea en la que se encuentra
                        if (countOccurences(renglones[i], data)) {
                            numLineas.push_back(numLinea);
                        }
                    }
                    for (int i = 0; i < numLineas.size(); i++)
                    {
                        cout << numLineas[i] << " "; //imprimo las lineas en la que se encontró la palabra
                    }
                }
            }
        } while (resp != "0");

    }
    else  if(opcion == 2) {
        Abb arbolito;
        string primero, segundo, operador;
        vector <string> num;
        int suma = 0;

        do{
            cout << "Para crear una postfix expressions con arboles ingresa 2 numeros distintos entre sí y después el operador.\n" 
                "(teclea s para salir)\n";

            cout << "Ingresa el primer numero\n";
            cin >> primero;
            cout << "Ingresa el segundo numero\n";
            cin >> segundo;
            cout << "Ingresa el operador ( + - * / ~ )\n";
            cin >> operador;

            if(primero == segundo) {
                cout << "No puedes guardar 2 numeros iguales en un arbol\n";
            }
            else if (primero == "s") {
                fflush(stdin);
                return 0;
            }
            else {
                arbolito.Inserta(primero);
                arbolito.Inserta(segundo);
                arbolito.Inserta(operador);

                arbolito.preorden(arbolito.getRoot(), num);

              
                    //Cada if y else if detecta la posición en la que se almacenó cada numero y dependiendo eso, hace la operación adecuada
                    if (num[1] == "+") {
                        try {
                            suma = stoi(num[0]) + stoi(num[2]);
                            cout << "sumo " << stoi(num[0]) << " y " << stoi(num[2]) << endl;
                            cout << "El resultado de " << num[0] << " " << num[1] << " " << num[2] << " es " << suma << endl;
                        }
                        catch (exception) {
                            cout << "Debes ingresar un numero valido\n";
                        }
                    }
                    else  if (num[2] == "+") {
                        try {
                            suma = stoi(num[0]) + stoi(num[1]);
                            cout << "sumo " << stoi(num[0]) << " y " << stoi(num[1]) << endl;
                            cout << "El resultado de " << num[0] << " " << num[2] << " " << num[1] << " es " << suma << endl;
                        }
                        catch (exception) {
                            cout << "Debes ingresar un numero valido\n";
                        }
                    }

                    if (num[1] == "-") {
                        try {
                            suma = stoi(num[0]) - stoi(num[2]);
                            cout << "resto " << stoi(num[0]) << " y " << stoi(num[2]) << endl;
                            cout << "El resultado de " << num[0] << " " << num[1] << " " << num[2] << " es " << suma << endl;
                        }
                        catch (exception) {
                            cout << "Debes ingresar un numero valido\n";
                        }
                    }
                    else if (num[2] == "-") {
                        try {
                            suma = stoi(num[0]) - stoi(num[1]);
                            cout << "resto " << stoi(num[0]) << " y " << stoi(num[1]) << endl;
                            cout << "El resultado de " << num[0] << " " << num[2] << " " << num[1] << " es " << suma << endl;
                        }
                        catch (exception) {
                            cout << "Debes ingresar un numero valido\n";
                        }
                    }
                    if (num[1] == "*") {
                        try {
                            suma = stoi(num[0]) * stoi(num[2]);
                            cout << "multiplico " << stoi(num[0]) << " y " << stoi(num[2]) << endl;
                            cout << "El resultado de " << num[0] << " " << num[1] << " " << num[2] << " es " << suma << endl;
                        }
                        catch (exception) {
                            cout << "Debes ingresar un numero valido\n";
                        }
                    }
                    else if (num[2] == "*") {
                        try {
                            suma = stoi(num[0]) * stoi(num[1]);
                            cout << "multiplico " << stoi(num[0]) << " y " << stoi(num[1]) << endl;
                            cout << "El resultado de " << num[0] << " " << num[2] << " " << num[1] << " es " << suma << endl;
                        }
                        catch (exception) {
                            cout << "Debes ingresar un numero valido\n";
                        }
                    }
                    if (num[1] == "/") {
                        if (num[2] == "0")
                            cout << "No puedes dividir entre 0\n";
                        else {
                            try {
                                suma = stoi(num[0]) / stoi(num[2]);
                                cout << "divido " << stoi(num[0]) << " y " << stoi(num[2]) << endl;
                                cout << "El resultado de " << num[0] << " " << num[1] << " " << num[2] << " es " << suma << endl;
                            }
                            catch (std::overflow_error e) {
                                cout << "Debes ingresar un numero valido\n";
                            }
                        }
                    }
                    else if (num[2] == "/") {
                        if (num[1] == "0")
                            cout << "No puedes dividir entre 0\n";
                        else {
                            try {
                                suma = stoi(num[0]) / stoi(num[1]);
                                cout << "divido " << stoi(num[0]) << " y " << stoi(num[1]) << endl;
                                cout << "El resultado de " << num[0] << " " << num[2] << " " << num[1] << " es " << suma << endl;
                            }
                            catch (exception) {
                                cout << "Debes ingresar un numero valido\n";
                            }
                        }
                    }
                    if (num[2] == "~") {
                        try {
                            int suma2;
                            suma = stoi(num[0]) * -1;
                            suma2=stoi(num[1]) * -1;
                            cout << "aplico +/- a" << stoi(num[0]) << endl;
                            cout << "El resultado de " << num[0] <<" y " << num[1]<<" +/- es " << suma <<" y "<< suma2<< endl;
                        }
                        catch (exception) {
                            cout << "Debes ingresar un numero valido\n";
                        }
                    }
                    else if (num[1] == "~") {

                        try {
                            suma = stoi(num[0]) * -1;
                            cout << "aplico +/- a" << stoi(num[0]) << endl;
                            cout << "El resultado de " << num[0] << "+/- es " << suma << endl;
                        }
                        catch (exception) {
                            cout << "Debes ingresar un numero valido\n";
                        }
                    }

                    //Para poder hacer varias operaciones debo borrar los num almecenados en el arbol
                    arbolito.borrar(operador);
                    arbolito.borrar(segundo);
                    arbolito.borrar(primero);
                    num.clear();

                    system("pause");
               
            }
            //Si presiono cualquier tecla me salgo
        } while (primero !="-0");
    }
}
