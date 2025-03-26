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
