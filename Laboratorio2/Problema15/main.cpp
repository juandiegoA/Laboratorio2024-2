
#include <iostream>
using namespace std;

bool checkIntersection(int a[], int b[]) {
    int x1 = a[0], y1 = a[1], w1 = a[2], h1 = a[3];
    int x2 = b[0], y2 = b[1], w2 = b[2], h2 = b[3];
    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) {
        return true; // Son coordenadas negativas
    }
    if (x1 == x2 && y1 == y2 && w1 == w2 && h1 == h2) {
        return true; // Son el mismo
    }

    if ((x1 == x2 + w2 || x1 + w1 == x2) && (y1 == y2 + h2 || y1 + h1 == y2)) {
        return true; // solo se tocan una arista
    }
    if (x1 < x2 + w2 && x1 + w1 > x2 && y1 < y2 + h2 && y1 + h1 > y2) {
        return true; // Intecsectados
    }
    return false; //No se intersectan
}

int main(){
    cout<<"ingrese un cuadrado: ";
    int a[4],b[4];
    for(int i=0;i<4;i++){
        cout<<"\n["<<i<<"]: ";
        cin>>a[i];
    }
    cout<<"ingrese el segundo cuadrado: ";
    for(int i=0;i<4;i++){
        cout<<"\n["<<i<<"]: ";
        cin>>b[i];
    }

    bool intersect = checkIntersection(a, b);
    if (intersect) {
        cout << "Los cuadrados se intersectan." << endl;
        int campo[100][100],d1[2],d2[2];
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                campo[i][j]=0;
            }
        }
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                if(i==a[0] and j==a[1]){
                    d1[0]=i+a[2];
                    d1[1]=j+a[3];
                }
                if(i==b[0] and j==b[1]){//esta es la posicion del segundo
                    campo[i][j]=1;
                    d2[0]=i;
                    d2[1]=j;
                }
            }
        }
        int cont=0;
        if(d1[0]<d2[0]){
            a[0]=d1[0];
            a[1]=d1[1];
            while(d1[0]<d2[0]){
                d1[0]++;
                cont++;
            }
            a[2]=cont;
            cont=0;
            if(d1[1]>d2[1]){
                while(d1[1]>d2[1]){
                    d1[1]--;
                    cont++;
                }
            }else{
                while(d1[1]<d2[1]){
                    d1[1]++;
                    cont++;
                }
            }
            a[3]=cont;
        }else{
            a[0]=d2[0];
            a[1]=d2[1];
            while(d2[0]<d1[0]){
                d2[0]++;
                cont++;
            }
            a[2]=cont;
            cont=0;
            if(d2[1]>d1[1]){
                while(d2[1]>d1[1]){
                    d2[1]--;
                    cont++;
                }
            }else{
                while(d2[1]<d1[1]){
                    d2[1]++;
                    cont++;
                }
            }
            a[3]=cont;
        }cout<<"{";
        for(int i=0;i<4;i++){
            cout<<a[i]<<", ";
        }
        cout<<"}";
    } else {
        cout << "Los cuadrados no se intersectan." << endl;
    }
    return 0;
}
