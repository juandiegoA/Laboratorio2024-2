#include <iostream>
#include<fstream>
#include<math.h>
#include<cstdlib>
#include <direct.h> // Necesario para chdir()

using namespace std;

void escrituraArchivo(string data, string name){
    ofstream outfile;
    cout<<name;
    string filePath = "C:/Users/Est01/Documents/Lab3/Data/Sudo.txt";
    outfile.open(filePath);

    if (!outfile.is_open())
    {
        cout << "Error abriendo el archivo" << endl;
        exit(1);
    }
//file:///C:/Users/Est01/Documents/Lab3/Data/Sudo.txt
    outfile << data+"_" << endl;
    outfile.close();
}

string lecturaArchivo(string name){
    string data;
    string dataSalida="";
    ifstream infile;
    string filePath = "C:/Users/Est01/Documents/Lab3/Data/" + name + ".txt";
    infile.open(filePath);
    if (!infile.is_open())
    {
        cout << "Error abriendo el archivo" << endl;
        exit(1);
    }

    while (!infile.eof()){
        infile >> data;
    }

    for (int i=0;i<data.length();i++){
        if(data.at(i)!='_'){
            dataSalida+=data.at(i);
        }else{
            break;
        }
    }
    //cout<<dataSalida<<endl;
    infile.close();
    return dataSalida;
}
