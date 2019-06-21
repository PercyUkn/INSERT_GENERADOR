#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;


int main() {

    string direccion,nombreTabla,lineaCSV;
    cout<<"Ingrese la direccion del archivo: "<<endl;
    getline(cin,direccion);
    cout<<"Ingrese nombre de la tabla: "<<endl;
    getline(cin,nombreTabla);
    ifstream archivoCSV (direccion.c_str(),ios::in);
    direccion.replace(direccion.begin()+direccion.length()-3,direccion.end(),"txt");
    ofstream archivoGenerado (direccion.c_str(),ios::out);
    int numeroLineas = std::count(std::istreambuf_iterator<char>(archivoCSV),std::istreambuf_iterator<char>(), '\n');
    cout<<"Numero de Lineas: "<<numeroLineas<<endl;
    archivoCSV.clear();
    archivoCSV.seekg(0, ios::beg);
    while (getline(archivoCSV,lineaCSV))
    {

        if (numeroLineas>=1)
            {lineaCSV.pop_back();}

            archivoGenerado<<"INSERT INTO "<<nombreTabla<<" VALUES ("<<lineaCSV<<");"<<endl;
        numeroLineas--;
    };
    archivoGenerado.close();
    return 0;

}