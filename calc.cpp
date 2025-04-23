#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

void matrices();
void geometria();
void analisis();

//MENU PRINCIPAL

int main() {

    while (true) {
        std::cout << "Seleccionar el bloque para calculos:\n";
        std::cout << "1. Algebra\n";
        std::cout << "2. Geometria\n";
        std::cout << "3. Terminar\n";

        int bloque;

        std::cin >> bloque;
        switch (bloque) {
            case 1: 
                matrices();
                break;
            
            case 2: 
                geometria();
                break;
            
            case 3: 
                std::cout << "Terminando el programa..." << std::endl;
                return 0;

            default:
                std::cout << "Bloque no valido" << std::endl;
        }
    }
}

//BLOQUE DE ALGEBRA

void matrices() {


    //DECLARACIONES

    float determinant2x2(float matrix[2][2]);
    float determinant3x3(float matrix[3][3]);
    void inverse3x3(float matrix[3][3], float det, float inv[3][3]);
    void inverse2x2(float matrix[2][2], float det, float inv[2][2]);
    void sumar2x2(float MatA[2][2], float MatB[2][2], float result[2][2]);
    void sumar3x3(float MatA[3][3], float MatB[3][3], float result[3][3]);
    void restar2x2(float MatA[2][2], float MatB[2][2], float result[2][2]);
    void multiplicar2x2(float MatA[2][2], float MatB[2][2], float result[2][2]);
    void restar3x3(float MatA[3][3], float MatB[3][3], float result[3][3]);
    void multiplicar3x3(float MatA[3][3], float MatB[3][3], float result[3][3]);

    float MatA2x2[2][2] = {0}, MatB2x2[2][2] = {0};
    float MatA3x3[3][3] = {0}, MatB3x3[3][3] = {0};
    int sizeMatA = 0, sizeMatB = 0;
    int matrizSeleccionada; 


    //MENU

    while (true) {

        std::cout << "\nMenu de matrices:\n";
        std::cout << "1. Introducir datos\n";
        std::cout << "2. Realizar calculos\n";
        std::cout << "3. Volver al menu principal\n";
        std::cout << "Seleccione una opcion: ";
        int opcionPrincipal;
        std::cin >> opcionPrincipal;

        switch (opcionPrincipal) {
            case 1: 
                //MatA

                std::cout << "Seleccione el tamano de MatA: \n1. 2x2 \n2. 3x3" << std::endl;
                std::cin >> sizeMatA;

                if (sizeMatA == 1) {
                    std::cout << "Introduce los valores para MatA (2x2):" << std::endl;
                    for (int i = 0; i < 2; i++) {
                        for (int j = 0; j < 2; j++) {
                            std::cout << "MatA[" << i << "][" << j << "] = ";
                            std::cin >> MatA2x2[i][j];
                        }
                    }
                } else if (sizeMatA == 2) {
                    std::cout << "Introduce los valores para MatA (3x3):" << std::endl;
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            std::cout << "MatA[" << i << "][" << j << "] = ";
                            std::cin >> MatA3x3[i][j];
                        }
                    }
                } else {
                    std::cout << "Tamano no valido para MatA.\n";
                    break;
                }

                // MatB

                
                std::cout << "Seleccione el tamano de MatB: \n1. 2x2 \n2. 3x3" << std::endl;
                std::cin >> sizeMatB;

                if (sizeMatB == 1) {
                    std::cout << "Introduce los valores para MatB (2x2):" << std::endl;
                    for (int i = 0; i < 2; i++) {
                        for (int j = 0; j < 2; j++) {
                            std::cout << "MatB[" << i << "][" << j << "] = ";
                            std::cin >> MatB2x2[i][j];
                        }
                    }
                } else if (sizeMatB == 2) {
                    std::cout << "Introduce los valores para MatB (3x3):" << std::endl;
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            std::cout << "MatB[" << i << "][" << j << "] = ";
                            std::cin >> MatB3x3[i][j];
                        }
                    }
                } else {
                    std::cout << "Tamano no valido para MatB.\n";
                }
                break;

            case 2: 
                // Menu 
                while (true) {
                    std::cout << "\nMenu de operaciones:\n";
                    std::cout << "1. Calcular determinante\n";
                    std::cout << "2. Calcular inversa\n";
                    std::cout << "3. Sumar matrices (2x2)\n";
                    std::cout << "4. Sumar matrices (3x3)\n";
                    std::cout << "5. Restar matrices (2x2)\n";
                    std::cout << "6. Restar matrices (3x3)\n";
                    std::cout << "7. Multiplicar matrices (2x2)\n";
                    std::cout << "8. Multiplicar matrices (3x3)\n";
                    std::cout << "9. Volver al menu de matrices\n";
                    std::cout << "Seleccione una opcion: ";
                    int opcion;
                    std::cin >> opcion;

                    switch (opcion) {
                        case 1: 
                            std::cout << "Seleccione la matriz para calcular el determinante:\n1. MatA\n2. MatB\n";
                            std::cin >> matrizSeleccionada;

                            if (matrizSeleccionada == 1) {
                                if (sizeMatA == 1) {
                                    std::cout << "Determinante de MatA (2x2): " << determinant2x2(MatA2x2) << std::endl;
                                } else if (sizeMatA == 2) {
                                    std::cout << "Determinante de MatA (3x3): " << determinant3x3(MatA3x3) << std::endl;
                                }
                            } else if (matrizSeleccionada == 2) {
                                if (sizeMatB == 1) {
                                    std::cout << "Determinante de MatB (2x2): " << determinant2x2(MatB2x2) << std::endl;
                                } else if (sizeMatB == 2) {
                                    std::cout << "Determinante de MatB (3x3): " << determinant3x3(MatB3x3) << std::endl;
                                }
                            } else {
                                std::cout << "Opcion no valida." << std::endl;
                            }
                            break;

                        case 2: 
                            std::cout << "Seleccione la matriz para calcular la inversa:\n1. MatA\n2. MatB\n";
                            std::cin >> matrizSeleccionada;

                            if (matrizSeleccionada == 1) {
                                if (sizeMatA == 1) {
                                    float det = determinant2x2(MatA2x2);
                                    if (det == 0) {
                                        std::cout << "La matriz no tiene inversa (determinante = 0)." << std::endl;
                                    } else {
                                        float inv[2][2];
                                        inverse2x2(MatA2x2, det, inv);
                                        std::cout << "Inversa de MatA (2x2):" << std::endl;
                                        for (int i = 0; i < 2; i++) {
                                            for (int j = 0; j < 2; j++) {
                                                std::cout << inv[i][j] << " ";
                                            }
                                            std::cout << std::endl;
                                        }
                                    }
                                } else if (sizeMatA == 2) {
                                    float det = determinant3x3(MatA3x3);
                                    if (det == 0) {
                                        std::cout << "La matriz no tiene inversa (determinante = 0)." << std::endl;
                                    } else {
                                        float inv[3][3];
                                        inverse3x3(MatA3x3, det, inv);
                                        std::cout << "Inversa de MatA (3x3):" << std::endl;
                                        for (int i = 0; i < 3; i++) {
                                            for (int j = 0; j < 3; j++) {
                                                std::cout << inv[i][j] << " ";
                                            }
                                            std::cout << std::endl;
                                        }
                                    }
                                }
                            } else if (matrizSeleccionada == 2) {
                                if (sizeMatB == 1) {
                                    float det = determinant2x2(MatB2x2);
                                    if (det == 0) {
                                        std::cout << "La matriz no tiene inversa (determinante = 0)." << std::endl;
                                    } else {
                                        float inv[2][2];
                                        inverse2x2(MatB2x2, det, inv);
                                        std::cout << "Inversa de MatB (2x2):" << std::endl;
                                        for (int i = 0; i < 2; i++) {
                                            for (int j = 0; j < 2; j++) {
                                                std::cout << inv[i][j] << " ";
                                            }
                                            std::cout << std::endl;
                                        }
                                    }
                                } else if (sizeMatB == 2) {
                                    float det = determinant3x3(MatB3x3);
                                    if (det == 0) {
                                        std::cout << "La matriz no tiene inversa (determinante = 0)." << std::endl;
                                    } else {
                                        float inv[3][3];
                                        inverse3x3(MatB3x3, det, inv);
                                        std::cout << "Inversa de MatB (3x3):" << std::endl;
                                        for (int i = 0; i < 3; i++) {
                                            for (int j = 0; j < 3; j++) {
                                                std::cout << inv[i][j] << " ";
                                            }
                                            std::cout << std::endl;
                                        }
                                    }
                                }
                            } else {
                                std::cout << "Opcion no valida." << std::endl;
                            }
                            break;

                        case 3: 
                            if (sizeMatA == 1 && sizeMatB == 1) {
                                float result[2][2];
                                sumar2x2(MatA2x2, MatB2x2, result);
                                std::cout << "Resultado de la suma (2x2):" << std::endl;
                                for (int i = 0; i < 2; i++) {
                                    for (int j = 0; j < 2; j++) {
                                        std::cout << result[i][j] << " ";
                                    }
                                    std::cout << std::endl;
                                }
                            } else if (sizeMatA == 2 && sizeMatB == 2) {
                                float result[3][3];
                                sumar3x3(MatA3x3, MatB3x3, result);
                                std::cout << "Resultado de la suma (3x3):" << std::endl;
                                for (int i = 0; i < 3; i++) {
                                    for (int j = 0; j < 3; j++) {
                                        std::cout << result[i][j] << " ";
                                    }
                                    std::cout << std::endl;
                                }
                            } else {
                                std::cout << "Ambas matrices deben ser del mismo tamano para realizar la suma." << std::endl;
                            }
                            break;

                        case 4: 
                            if (sizeMatA == 2 && sizeMatB == 2) {
                                float result[3][3];
                                sumar3x3(MatA3x3, MatB3x3, result);
                                std::cout << "Resultado de la suma (3x3):" << std::endl;
                                for (int i = 0; i < 3; i++) {
                                    for (int j = 0; j < 3; j++) {
                                        std::cout << result[i][j] << " ";
                                    }
                                    std::cout << std::endl;
                                }
                            } else {
                                std::cout << "Ambas matrices deben ser de tamano 3x3 para realizar la suma." << std::endl;
                            }
                            break;

                        case 5: 
                            if (sizeMatA == 1 && sizeMatB == 1) {
                                float result[2][2];
                                restar2x2(MatA2x2, MatB2x2, result);
                                std::cout << "Resultado de la resta (2x2):" << std::endl;
                                for (int i = 0; i < 2; i++) {
                                    for (int j = 0; j < 2; j++) {
                                        std::cout << result[i][j] << " ";
                                    }
                                    std::cout << std::endl;
                                }
                            } else {
                                std::cout << "Ambas matrices deben ser de tamano 2x2 para realizar la resta." << std::endl;
                            }
                            break;

                        case 6: 
                            if (sizeMatA == 2 && sizeMatB == 2) {
                                float result[3][3];
                                restar3x3(MatA3x3, MatB3x3, result);
                                std::cout << "Resultado de la resta (3x3):" << std::endl;
                                for (int i = 0; i < 3; i++) {
                                    for (int j = 0; j < 3; j++) {
                                        std::cout << result[i][j] << " ";
                                    }
                                    std::cout << std::endl;
                                }
                            } else {
                                std::cout << "Ambas matrices deben ser de tamano 3x3 para realizar la resta." << std::endl;
                            }
                            break;

                        case 7: 
                            if (sizeMatA == 1 && sizeMatB == 1) {
                                float result[2][2];
                                multiplicar2x2(MatA2x2, MatB2x2, result);
                                std::cout << "Resultado de la multiplicacion (2x2):" << std::endl;
                                for (int i = 0; i < 2; i++) {
                                    for (int j = 0; j < 2; j++) {
                                        std::cout << result[i][j] << " ";
                                    }
                                    std::cout << std::endl;
                                }
                            } else {
                                std::cout << "Ambas matrices deben ser de tamano 2x2 para realizar la multiplicacion." << std::endl;
                            }
                            break;

                        case 8: 
                            if (sizeMatA == 2 && sizeMatB == 2) {
                                float result[3][3];
                                multiplicar3x3(MatA3x3, MatB3x3, result);
                                std::cout << "Resultado de la multiplicacion (3x3):" << std::endl;
                                for (int i = 0; i < 3; i++) {
                                    for (int j = 0; j < 3; j++) {
                                        std::cout << result[i][j] << " ";
                                    }
                                    std::cout << std::endl;
                                }
                            } else {
                                std::cout << "Ambas matrices deben ser de tamano 3x3 para realizar la multiplicacion." << std::endl;
                            }
                            break;

                        case 9:
                            // Go back to menu de matrices
                            goto back_to_matrices;

                        default:
                            std::cout << "Opcion no valida." << std::endl;
                    }
                }
                back_to_matrices:
                break;

            case 3:
                
                return;

            default:
                std::cout << "Opcion no valida." << std::endl;
        }
    }
}

// CALCULOS

float determinant2x2(float matrix[2][2]) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

float determinant3x3(float matrix[3][3]) {
    float maind = matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[0][2] * matrix[1][0] * matrix[2][1];
    float secd = matrix[2][0] * matrix[1][1] * matrix[0][2] + matrix[2][1] * matrix[1][2] * matrix[0][0] + matrix[2][2] * matrix[1][0] * matrix[0][1];
    return maind - secd;
}

void inverse2x2(float matrix[2][2], float det, float inv[2][2]) {
    inv[0][0] = matrix[1][1] / det;
    inv[0][1] = -matrix[0][1] / det;
    inv[1][0] = -matrix[1][0] / det;
    inv[1][1] = matrix[0][0] / det;
}

void inverse3x3(float matrix[3][3], float det, float inv[3][3]) {
    inv[0][0] = (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) / det;
    inv[0][1] = (matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2]) / det;
    inv[0][2] = (matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1]) / det;
    inv[1][0] = (matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2]) / det;
    inv[1][1] = (matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0]) / det;
    inv[1][2] = (matrix[0][2] * matrix[1][0] - matrix[0][0] * matrix[1][2]) / det;
    inv[2][0] = (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]) / det;
    inv[2][1] = (matrix[0][1] * matrix[2][0] - matrix[0][0] * matrix[2][1]) / det;
    inv[2][2] = (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) / det;
}

void sumar2x2(float MatA[2][2], float MatB[2][2], float result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = MatA[i][j] + MatB[i][j];
        }
    }
}

void sumar3x3(float MatA[3][3], float MatB[3][3], float result[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = MatA[i][j] + MatB[i][j];
        }
    }
}

void restar2x2(float MatA[2][2], float MatB[2][2], float result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = MatA[i][j] - MatB[i][j];
        }
    }
}

void multiplicar2x2(float MatA[2][2], float MatB[2][2], float result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                result[i][j] += MatA[i][k] * MatB[k][j];
            }
        }
    }
}

void restar3x3(float MatA[3][3], float MatB[3][3], float result[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = MatA[i][j] - MatB[i][j];
        }
    }
}

void multiplicar3x3(float MatA[3][3], float MatB[3][3], float result[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result[i][j] += MatA[i][k] * MatB[k][j];
            }
        }
    }
}



//BLOQUE DE GEOMETRIA



void geometria() {

    //DECLARACIONES
    void IntroducirPuntos();
    void IntroducirVectores();
    void IntroducirRectas();
    void IntroducirPlanos();
    void Geocalcular();
    void MostrarDatos();

    menu_geometria:

    while (true) {
        std::cout << "1. Introducir datos\n";
        std::cout << "2. Realizar calculos\n";
        std::cout << "3. Volver al menu principal\n";
        std::cout << "4. Mostrar datos\n";
        std::cout << "Seleccione una opcion: ";
        int opcion;
        std::cin >> opcion;

        

        switch (opcion) {
            case 1: 
                std::cout << "Menu de datos de geometria" << std::endl;
                std::cout << "1. Introducir datos de puntos" << std::endl;
                std::cout << "2. Introducir datos de vectores" << std::endl;
                std::cout << "3. Introducir datos de rectas (Con los puntos y vectores definidos en los apartados anteriores)" << std::endl;
                std::cout << "4. Introducir datos de planos (Con dos vectores y un punto/vector normal y punto)" << std::endl;
                std::cout << "5. Regresar al menu anterior" << std::endl;
                std::cout << "Seleccione una opcion: ";
                int opcionDatos;
                std::cin >> opcionDatos;

                switch (opcionDatos) {
                    case 1: 
                        IntroducirPuntos();
                        break;
                    
                    case 2: 
                        IntroducirVectores(); 
                        break;
                    
                    case 3: 
                        IntroducirRectas();
                        break;
                    
                    case 4: 
                        IntroducirPlanos();
                        break;
                    
                    case 5:
                        // Go back to menu de geometria
                        goto menu_geometria;

                    default:
                        std::cout << "Opcion no valida." << std::endl;
                }
                
                break;
            

            case 2: 
                std::cout << "Realizar calculos de geometria." << std::endl;
                // Geocalcular(); // Uncomment and implement if needed
                break;
            
            case 3:
                // Go back to main menu
                return;

            case 4:
                MostrarDatos();
                break;

            default:
                std::cout << "Opcion no valida." << std::endl;
        }
    }
}


//FUNCIONES Y CALCULOS



std::vector<float> PA(3), PB(3), PC(3), PD(3);

void IntroducirPuntos() {



    std::cout << "Seleccione punto." << std::endl;
    std::cout << "1. PA" << std::endl;
    std::cout << "2. PB" << std::endl;
    std::cout << "3. PC" << std::endl;
    std::cout << "4. PD" << std::endl;
    int puntoSeleccionado;
    std::cin >> puntoSeleccionado;

    switch (puntoSeleccionado) {
        case 1: 
            std::cout << "Introducir coordenadas de PA:" << std::endl;
            for (int i = 0; i < 3; ++i) {
                if (i == 0) {
                    std::cout << "X: ";
                } else if (i == 1) {
                    std::cout << "Y: ";
                } else if (i == 2) {
                    std::cout << "Z: ";
                }
                std::cin >> PA[i];
            }
            std::cout << "Coordenadas de PA: (" << PA[0] << ", " << PA[1] << ", " << PA[2] << ")" << std::endl;
            break;

        case 2: 
            std::cout << "Introducir coordenadas de PB:" << std::endl;
            for (int i = 0; i < 3; ++i) {
                if (i == 0) {
                    std::cout << "X: ";
                } else if (i == 1) {
                    std::cout << "Y: ";
                } else if (i == 2) {
                    std::cout << "Z: ";
                }
                std::cin >> PB[i];
            }
            std::cout << "Coordenadas de PB: (" << PB[0] << ", " << PB[1] << ", " << PB[2] << ")" << std::endl;
            break;

        case 3: 
            std::cout << "Introducir coordenadas de PC:" << std::endl;
            for (int i = 0; i < 3; ++i) {
                if (i == 0) {
                    std::cout << "X: ";
                } else if (i == 1) {
                    std::cout << "Y: ";
                } else if (i == 2) {
                    std::cout << "Z: ";
                }
                std::cin >> PC[i];
            }
            std::cout << "Coordenadas de PC: (" << PC[0] << ", " << PC[1] << ", " << PC[2] << ")" << std::endl;
            break;

        case 4: 
            std::cout << "Introducir coordenadas de PD:" << std::endl;
            for (int i = 0; i < 3; ++i) {
                if (i == 0) {
                    std::cout << "X: ";
                } else if (i == 1) {
                    std::cout << "Y: ";
                } else if (i == 2) {
                    std::cout << "Z: ";
                }
                std::cin >> PD[i];
            }
            std::cout << "Coordenadas de PD: (" << PD[0] << ", " << PD[1] << ", " << PD[2] << ")" << std::endl;
            break;

        default:
            std::cout << "Opcion no valida." << std::endl;
    }
}





std::vector<float> VA(3), VB(3), VC(3), VD(3);


void IntroducirVectores() {


    std::cout << "Seleccione vector." << std::endl;
    std::cout << "1. VA" << std::endl;
    std::cout << "2. VB" << std::endl;
    std::cout << "3. VC" << std::endl;
    std::cout << "4. VD" << std::endl;
    int vectorSeleccionado;
    std::cin >> vectorSeleccionado;

    switch (vectorSeleccionado) {
        case 1: 
            std::cout << "Introducir coordenadas de VA:" << std::endl;
            for (int i = 0; i < 3; ++i) {
                if (i == 0) {
                    std::cout << "X: ";
                } else if (i == 1) {
                    std::cout << "Y: ";
                } else if (i == 2) {
                    std::cout << "Z: ";
                }
                std::cin >> VA[i];
            }
            std::cout << "Coordenadas de VA: (" << VA[0] << ", " << VA[1] << ", " << VA[2] << ")" << std::endl;
            break;

        case 2: 
            std::cout << "Introducir coordenadas de VB:" << std::endl;
            for (int i = 0; i < 3; ++i) {
                if (i == 0) {
                    std::cout << "X: ";
                } else if (i == 1) {
                    std::cout << "Y: ";
                } else if (i == 2) {
                    std::cout << "Z: ";
                }
                std::cin >> VB[i];
            }
            std::cout << "Coordenadas de VB: (" << VB[0] << ", " << VB[1] << ", " << VB[2] << ")" << std::endl;
            break;

        case 3: 
            std::cout << "Introducir coordenadas de VC:" << std::endl;
            for (int i = 0; i < 3; ++i) {
                if (i == 0) {
                    std::cout << "X: ";
                }
                else if (i == 1) {
                    std::cout << "Y: ";
                } else if (i == 2) {
                    std::cout << "Z: ";
                }
                std::cin >> VC[i];
            }
            std::cout << "Coordenadas de VC: (" << VC[0] << ", " << VC[1] << ", " << VC[2] << ")" << std::endl;

            break;
        case 4: 
            std::cout << "Introducir coordenadas de VD:" << std::endl;
            for (int i = 0; i < 3; ++i) {
                if (i == 0) {
                    std::cout << "X: ";
                } else if (i == 1) {
                    std::cout << "Y: ";
                } else if (i == 2) {
                    std::cout << "Z: ";
                }
                std::cin >> VD[i];
            }
            std::cout << "Coordenadas de VD: (" << VD[0] << ", " << VD[1] << ", " << VD[2] << ")" << std::endl;
            break;

        default:
            std::cout << "Opcion no valida." << std::endl;
    }

}





std::vector<std::pair<std::vector<float>, std::vector<float>>> rectas(4);

void IntroducirRectas() {
 

    std::cout << "Seleccione recta." << std::endl;
    std::cout << "1. R1" << std::endl;
    std::cout << "2. R2" << std::endl;
    std::cout << "3. R3" << std::endl;
    std::cout << "4. R4" << std::endl;
    int rectaSeleccionada;
    std::cin >> rectaSeleccionada;

    if (rectaSeleccionada < 1 || rectaSeleccionada > 4) {
        std::cout << "Opcion no valida." << std::endl;
        return;
    }

    std::cout << "Seleccione el punto para definir la recta:" << std::endl;
    std::cout << "1. PA" << std::endl;
    std::cout << "2. PB" << std::endl;
    std::cout << "3. PC" << std::endl;
    std::cout << "4. PD" << std::endl;
    int puntoSeleccionado;
    std::cin >> puntoSeleccionado;

    std::vector<float> punto;
    switch (puntoSeleccionado) {
        case 1: punto = PA; break;
        case 2: punto = PB; break;
        case 3: punto = PC; break;
        case 4: punto = PD; break;
        default:
            std::cout << "Opcion no valida para el punto." << std::endl;
            return;
    }

    std::cout << "Seleccione el vector para definir la recta:" << std::endl;
    std::cout << "1. VA" << std::endl;
    std::cout << "2. VB" << std::endl;
    std::cout << "3. VC" << std::endl;
    std::cout << "4. VD" << std::endl;
    int vectorSeleccionado;
    std::cin >> vectorSeleccionado;

    std::vector<float> vector;
    switch (vectorSeleccionado) {
        case 1: vector = VA; break;
        case 2: vector = VB; break;
        case 3: vector = VC; break;
        case 4: vector = VD; break;
        default:
            std::cout << "Opcion no valida para el vector." << std::endl;
            return;
    }


    rectas[rectaSeleccionada - 1] = {punto, vector};

    std::cout << "Recta R" << rectaSeleccionada << " definida por:" << std::endl;
    std::cout << "Punto: (" << punto[0] << ", " << punto[1] << ", " << punto[2] << ")" << std::endl;
    std::cout << "Vector: (" << vector[0] << ", " << vector[1] << ", " << vector[2] << ")" << std::endl;
}





std::vector<std::string> planoecuacion(4);
std::vector<std::vector<float>> planeNormals(4, std::vector<float>(3)); 

void IntroducirPlanos() {
    std::cout << "Seleccione plano." << std::endl;
    std::cout << "1. Pla1" << std::endl;
    std::cout << "2. Pla2" << std::endl;
    std::cout << "3. Pla3" << std::endl;
    std::cout << "4. Pla4" << std::endl;
    int planoSeleccionado;
    std::cin >> planoSeleccionado;

    if (planoSeleccionado < 1 || planoSeleccionado > 4) {
        std::cout << "Opcion no valida." << std::endl;
        return;
    }

    std::cout << "Seleccione la forma de definir el plano:" << std::endl;
    std::cout << "1. Vector normal y un punto" << std::endl;
    std::cout << "2. Dos vectores y un punto" << std::endl;
    int formaSeleccionada;
    std::cin >> formaSeleccionada;

    if (formaSeleccionada == 1) {
        std::cout << "Seleccione el vector normal para definir el plano:" << std::endl;
        std::cout << "1. VA" << std::endl;
        std::cout << "2. VB" << std::endl;
        std::cout << "3. VC" << std::endl;
        std::cout << "4. VD" << std::endl;
        int vectorSeleccionado;
        std::cin >> vectorSeleccionado;

        std::vector<float> vectorNormal;
        switch (vectorSeleccionado) {
            case 1: vectorNormal = VA; break;
            case 2: vectorNormal = VB; break;
            case 3: vectorNormal = VC; break;
            case 4: vectorNormal = VD; break;
            default:
                std::cout << "Opcion no valida para el vector normal." << std::endl;
                return;
        }

        std::cout << "Seleccione el punto para definir el plano:" << std::endl;
        std::cout << "1. PA" << std::endl;
        std::cout << "2. PB" << std::endl;
        std::cout << "3. PC" << std::endl;
        std::cout << "4. PD" << std::endl;
        int puntoSeleccionado;
        std::cin >> puntoSeleccionado;

        std::vector<float> punto;
        switch (puntoSeleccionado) {
            case 1: punto = PA; break;
            case 2: punto = PB; break;
            case 3: punto = PC; break;
            case 4: punto = PD; break;
            default:
                std::cout << "Opcion no valida para el punto." << std::endl;
                return;
        }

        // Calculate the general equation of the plane
        float A = vectorNormal[0];
        float B = vectorNormal[1];
        float C = vectorNormal[2];
        float D = -(A * punto[0] + B * punto[1] + C * punto[2]);

        planeNormals[planoSeleccionado - 1] = vectorNormal;

        // Store the equation as a string in the global variable
        planoecuacion[planoSeleccionado - 1] = std::to_string(A) + "x + " +
                                                std::to_string(B) + "y + " +
                                                std::to_string(C) + "z + " +
                                                std::to_string(D) + " = 0";

        // Output the equation
        std::cout << "Plano Pla" << planoSeleccionado << " definido por:" << std::endl;
        std::cout << "Vector normal: (" << vectorNormal[0] << ", " << vectorNormal[1] << ", " << vectorNormal[2] << ")" << std::endl;
        std::cout << "Punto: (" << punto[0] << ", " << punto[1] << ", " << punto[2] << ")" << std::endl;
        std::cout << "La ecuacion general del plano es: " << planoecuacion[planoSeleccionado - 1] << std::endl;

    } else if (formaSeleccionada == 2) {
        std::cout << "Seleccione el primer vector para definir el plano:" << std::endl;
        std::cout << "1. VA" << std::endl;
        std::cout << "2. VB" << std::endl;
        std::cout << "3. VC" << std::endl;
        std::cout << "4. VD" << std::endl;
        int vector1Seleccionado;
        std::cin >> vector1Seleccionado;

        std::vector<float> vector1;
        switch (vector1Seleccionado) {
            case 1: vector1 = VA; break;
            case 2: vector1 = VB; break;
            case 3: vector1 = VC; break;
            case 4: vector1 = VD; break;
            default:
            std::cout << "Opcion no valida para el primer vector." << std::endl;
            return;
        }

        std::cout << "Seleccione el segundo vector para definir el plano:" << std::endl;
        std::cout << "1. VA" << std::endl;
        std::cout << "2. VB" << std::endl;
        std::cout << "3. VC" << std::endl;
        std::cout << "4. VD" << std::endl;
        int vector2Seleccionado;
        std::cin >> vector2Seleccionado;

        std::vector<float> vector2;
        switch (vector2Seleccionado) {
            case 1: vector2 = VA; break;
            case 2: vector2 = VB; break;
            case 3: vector2 = VC; break;
            case 4: vector2 = VD; break;
            default:
            std::cout << "Opcion no valida para el segundo vector." << std::endl;
            return;
        }

        std::cout << "Seleccione el punto para definir el plano:" << std::endl;
        std::cout << "1. PA" << std::endl;
        std::cout << "2. PB" << std::endl;
        std::cout << "3. PC" << std::endl;
        std::cout << "4. PD" << std::endl;
        int puntoSeleccionado;
        std::cin >> puntoSeleccionado;

        std::vector<float> punto;
        switch (puntoSeleccionado) {
            case 1: punto = PA; break;
            case 2: punto = PB; break;
            case 3: punto = PC; break;
            case 4: punto = PD; break;
            default:
            std::cout << "Opcion no valida para el punto." << std::endl;
            return;
        }

        // Calculate the cross product of the two vectors to get the normal vector
        std::vector<float> vectorNormal(3);
        vectorNormal[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
        vectorNormal[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2];
        vectorNormal[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];

        // Calculate the general equation of the plane
        float A = vectorNormal[0];
        float B = vectorNormal[1];
        float C = vectorNormal[2];
        float D = -(A * punto[0] + B * punto[1] + C * punto[2]);

        planeNormals[planoSeleccionado - 1] = vectorNormal;

        // Store the equation as a string in the global variable
        planoecuacion[planoSeleccionado - 1] = std::to_string(A) + "x + " +
                            std::to_string(B) + "y + " +
                            std::to_string(C) + "z + " +
                            std::to_string(D) + " = 0";

        // Output the equation
        std::cout << "Plano Pla" << planoSeleccionado << " definido por:" << std::endl;
        std::cout << "Vector normal: (" << vectorNormal[0] << ", " << vectorNormal[1] << ", " << vectorNormal[2] << ")" << std::endl;
        std::cout << "Punto: (" << punto[0] << ", " << punto[1] << ", " << punto[2] << ")" << std::endl;
        std::cout << "La ecuacion general del plano es: " << planoecuacion[planoSeleccionado - 1] << std::endl;


    } else {

        std::cout << "Opcion no valida para la forma de definir el plano." << std::endl;

    }
}

void MostrarDatos() {
    std::cout << "Datos actuales:\n";

    // Mostrar puntos
    std::cout << "Puntos:\n";
    std::cout << "PA: (" << PA[0] << ", " << PA[1] << ", " << PA[2] << ")\n";
    std::cout << "PB: (" << PB[0] << ", " << PB[1] << ", " << PB[2] << ")\n";
    std::cout << "PC: (" << PC[0] << ", " << PC[1] << ", " << PC[2] << ")\n";
    std::cout << "PD: (" << PD[0] << ", " << PD[1] << ", " << PD[2] << ")\n";

    // Mostrar vectores
    std::cout << "Vectores:\n";
    std::cout << "VA: (" << VA[0] << ", " << VA[1] << ", " << VA[2] << ")\n";
    std::cout << "VB: (" << VB[0] << ", " << VB[1] << ", " << VB[2] << ")\n";
    std::cout << "VC: (" << VC[0] << ", " << VC[1] << ", " << VC[2] << ")\n";
    std::cout << "VD: (" << VD[0] << ", " << VD[1] << ", " << VD[2] << ")\n";

    // Mostrar rectas
    std::cout << "Rectas:\n";
    for (int i = 0; i < 4; ++i) {
        if (rectas[i].first.empty() || rectas[i].second.empty()) {
            std::cout << "R" << i + 1 << ": No definida\n";
        } else {
            std::cout << "R" << i + 1 << ": Punto (" << rectas[i].first[0] << ", " << rectas[i].first[1] << ", " << rectas[i].first[2] << ")";
            std::cout << ", Vector (" << rectas[i].second[0] << ", " << rectas[i].second[1] << ", " << rectas[i].second[2] << ")\n";
        }
    }

    // Mostrar planos
    std::cout << "Planos:\n";
    for (int i = 0; i < 4; ++i) {
        if (planoecuacion[i].empty()) {
            std::cout << "Pla" << i + 1 << ": No definido\n";
        } else {
            std::cout << "Pla" << i + 1 << ": " << planoecuacion[i] << "\n";
        }
    }
}