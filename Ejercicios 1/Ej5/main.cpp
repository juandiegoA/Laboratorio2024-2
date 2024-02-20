#include <iostream>

using namespace std;

int main()
{
    cout<<"Este programa muestra el redondeo de una division"<<endl;
    int resultadoI;
    float A,B,resultadoF,diferencia;
    cout << "Ingrese numero A: ";
    cin>>A;
    cout<<"Ingrese numero B: ";
    cin>>B;
    /*if ((isdigit(A)==false) || (isdigit(B)==false))
    {
        cout<<"Papi eran numeros. ¿Usted no sabe leer o que?"<<endl;
    }*/
    resultadoI = A/B;
    resultadoF = A/B;
    diferencia =resultadoF-resultadoI;
    if (diferencia<=0.5){
    cout<<resultadoI<<endl;
    }else {resultadoI = resultadoI+1;
    cout<<resultadoI<<endl;}
}
