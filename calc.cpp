#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

void matrices();
void geometria();
void analisis();
void prob();


int main() {
    std::cout<<"Seleccionar el bloque para calculos: \n1. Algebra \n2. Geometria \n3. Analisis \n4. Proabilidades"<<std::endl;
    int bloque;
    std::cin>>bloque;
    switch (bloque) {
        case 1: {
            matrices();
            break;
        }
        case 2: {
            geometria();
            break;
        }
        case 3: {
            analisis();
            break;
        }
        case 4: {
            prob();
            break;
        }
        default:
            std::cout<<"Bloque no valido"<<std::endl;
    }

    return 0;
}

/*

void matrices() {

float determinant(float matrix[3][3]);
void adjg(float matrix[3][3], float adj[3][3]);
void inverse(float adj[3][3], float det, float inv[3][3]);

int main()
{
    float matrix[3][3];
    float adj[3][3];
    float inv[3][3];
    
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            std::cout<<"Enter matrix, row" << i <<" column"<<j<<"\n";
            std::cin>>matrix[i][j];
        }
    }
    float res = determinant(matrix);
    adjg(matrix, adj);
    
    std::cout<<"\nDeterminante: "<<res<<"\n";
    std::cout<<"Adjunto: \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << adj[i][j] << " ";
        }
        std::cout << "\n";
    }

    inverse(adj, res, inv);
    
    if (res == 0){
        return 0;
           
    }
    
    std::cout << "\nInverse matrix:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << inv[i][j] << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}

float determinant(float matrix[3][3])
{
    float maind = matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[0][2] * matrix[1][0] * matrix[2][1];
    
    float secd = matrix[2][0] * matrix[1][1] * matrix[0][2] + matrix[2][1] * matrix[1][2] * matrix[0][0] + matrix[2][2] * matrix[1][0] * matrix[0][1];
    
    float det = maind - secd;
    
    return det;
}

void adjg(float matrix[3][3], float adj[3][3])
{
    adj[0][0] =  matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1];
    adj[1][0] = -(matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]);
    adj[2][0] =  matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0];

    adj[0][1] = -(matrix[0][1] * matrix[2][2] - matrix[0][2] * matrix[2][1]);
    adj[1][1] =  matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0];
    adj[2][1] = -(matrix[0][0] * matrix[2][1] - matrix[0][1] * matrix[2][0]);

    adj[0][2] =  matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1];
    adj[1][2] = -(matrix[0][0] * matrix[1][2] - matrix[0][2] * matrix[1][0]);
    adj[2][2] =  matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    
}

void inverse(float adj[3][3], float det, float inv[3][3])
{
    if (det == 0) {
        std::cout << "No existe inversa \n";
        return;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            inv[i][j] = adj[i][j] / det;
        }
    }
}


}

void geometria() {



}

void analisis() {


}

void prob() {


}

