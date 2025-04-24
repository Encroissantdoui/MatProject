#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

// Forward declarations


void matrices();
void geometria();




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




std::vector<std::vector<float>> MatA, MatB, MatC, MatD;
std::vector<int> rows(4, 0), cols(4, 0); // Number of rows and columns for each matrix

void matrices() {

    float determinant2x2(const std::vector<std::vector<float>>& matrix);
    float determinant3x3(const std::vector<std::vector<float>>& matrix);
    void inverse2x2(const std::vector<std::vector<float>>& matrix, float det, std::vector<std::vector<float>>& inv);
    void inverse3x3(const std::vector<std::vector<float>>& matrix, float det, std::vector<std::vector<float>>& inv);
    void IntroducirDatosMatrices();
  

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
                IntroducirDatosMatrices();
                break;

            case 2: 
                while (true) {
                    std::cout << "\nMenu de operaciones:\n";
                    std::cout << "1. Calcular determinante\n";
                    std::cout << "2. Calcular inversa\n";
                    std::cout << "3. Sumar matrices\n";
                    std::cout << "4. Restar matrices\n";
                    std::cout << "5. Multiplicar matrices\n";
                    std::cout << "6. Volver al menu de matrices\n";
                    std::cout << "Seleccione una opcion: ";
                    int opcion;
                    std::cin >> opcion;

                    if (opcion == 1) {
                        std::cout << "Seleccione la matriz para calcular el determinante:" << std::endl;
                        std::cout << "1. MatA" << std::endl;
                        std::cout << "2. MatB" << std::endl;
                        std::cout << "3. MatC" << std::endl;
                        std::cout << "4. MatD" << std::endl;
                        int matrizSeleccionada;
                        std::cin >> matrizSeleccionada;

                        if (matrizSeleccionada < 1 || matrizSeleccionada > 4) {
                            std::cout << "Opcion no valida." << std::endl;
                            continue;
                        }

                        int index = matrizSeleccionada - 1;
                        float determinant = 0;

                        if (rows[index] == 2 && cols[index] == 2) {
                            if (index == 0) determinant = determinant2x2(MatA);
                            else if (index == 1) determinant = determinant2x2(MatB);
                            else if (index == 2) determinant = determinant2x2(MatC);
                            else if (index == 3) determinant = determinant2x2(MatD);
                        } else if (rows[index] == 3 && cols[index] == 3) {
                            if (index == 0) determinant = determinant3x3(MatA);
                            else if (index == 1) determinant = determinant3x3(MatB);
                            else if (index == 2) determinant = determinant3x3(MatC);
                            else if (index == 3) determinant = determinant3x3(MatD);
                        } else {
                            std::cout << "No existe determinante para esa matriz" << std::endl;
                            continue;
                        }

                        std::cout << "El determinante de la matriz es: " << determinant << std::endl;
                    }

                    if (opcion == 2) {
                        std::cout << "Seleccione la matriz para calcular la inversa:" << std::endl;
                        std::cout << "1. MatA" << std::endl;
                        std::cout << "2. MatB" << std::endl;
                        std::cout << "3. MatC" << std::endl;
                        std::cout << "4. MatD" << std::endl;
                        int matrizSeleccionada;
                        std::cin >> matrizSeleccionada;

                        if (matrizSeleccionada < 1 || matrizSeleccionada > 4) {
                            std::cout << "Opcion no valida." << std::endl;
                            continue;
                        }

                        int index = matrizSeleccionada - 1;
                        float determinant = 0;
                        std::vector<std::vector<float>> inverse;

                        if (rows[index] == 2 && cols[index] == 2) {
                            if (index == 0) determinant = determinant2x2(MatA);
                            else if (index == 1) determinant = determinant2x2(MatB);
                            else if (index == 2) determinant = determinant2x2(MatC);
                            else if (index == 3) determinant = determinant2x2(MatD);

                            if (determinant != 0) {
                                if (index == 0) inverse2x2(MatA, determinant, inverse);
                                else if (index == 1) inverse2x2(MatB, determinant, inverse);
                                else if (index == 2) inverse2x2(MatC, determinant, inverse);
                                else if (index == 3) inverse2x2(MatD, determinant, inverse);
                            }
                        } else if (rows[index] == 3 && cols[index] == 3) {
                            if (index == 0) determinant = determinant3x3(MatA);
                            else if (index == 1) determinant = determinant3x3(MatB);
                            else if (index == 2) determinant = determinant3x3(MatC);
                            else if (index == 3) determinant = determinant3x3(MatD);

                            if (determinant != 0) {
                                if (index == 0) inverse3x3(MatA, determinant, inverse);
                                else if (index == 1) inverse3x3(MatB, determinant, inverse);
                                else if (index == 2) inverse3x3(MatC, determinant, inverse);
                                else if (index == 3) inverse3x3(MatD, determinant, inverse);
                            }
                        } else {
                            std::cout << "No existe la inversa" << std::endl;
                            continue;
                        }

                        if (determinant == 0) {
                            std::cout << "La matriz no tiene inversa (determinante = 0)." << std::endl;
                        }
                    }

                    if (opcion == 6) {
                        break; // Go back to the main menu
                    }
                }
                break;

            case 3:
                return;

            default:
                std::cout << "Opcion no valida." << std::endl;
        }
    }
}

void IntroducirDatosMatrices() {
    while (true) {
        std::cout << "Seleccione la matriz para introducir datos:" << std::endl;
        std::cout << "1. MatA" << std::endl;
        std::cout << "2. MatB" << std::endl;
        std::cout << "3. MatC" << std::endl;
        std::cout << "4. MatD" << std::endl;
        std::cout << "5. Regresar al menu anterior" << std::endl;
        int matrizSeleccionada;
        std::cin >> matrizSeleccionada;

        if (matrizSeleccionada < 1 || matrizSeleccionada > 5) {
            std::cout << "Opcion no valida." << std::endl;
            continue;
        }

        if (matrizSeleccionada == 5) {
 
            return;
        }


        int index = matrizSeleccionada - 1;

        std::cout << "Defina el numero de filas (maximo 3): ";
        std::cin >> rows[index];
        std::cout << "Defina el numero de columnas (maximo 3): ";
        std::cin >> cols[index];

        if (rows[index] <= 0 || cols[index] <= 0 || rows[index] > 3 || cols[index] > 3) {
            std::cout << "Numero de filas y columnas debe estar entre 1 y 3." << std::endl;
            continue;
        }

        // Resize the selected matrix
        if (index == 0) MatA.resize(rows[index], std::vector<float>(cols[index]));
        else if (index == 1) MatB.resize(rows[index], std::vector<float>(cols[index]));
        else if (index == 2) MatC.resize(rows[index], std::vector<float>(cols[index]));
        else if (index == 3) MatD.resize(rows[index], std::vector<float>(cols[index]));

        std::cout << "Introduzca los valores para la matriz (" << rows[index] << "x" << cols[index] << "):" << std::endl;
        for (int i = 0; i < rows[index]; ++i) {
            for (int j = 0; j < cols[index]; ++j) {
                std::cout << "Elemento [" << i << "][" << j << "] = ";
                if (index == 0) std::cin >> MatA[i][j];
                else if (index == 1) std::cin >> MatB[i][j];
                else if (index == 2) std::cin >> MatC[i][j];
                else if (index == 3) std::cin >> MatD[i][j];
            }
        }

        std::cout << "Matriz definida como:" << std::endl;
        for (int i = 0; i < rows[index]; ++i) {
            for (int j = 0; j < cols[index]; ++j) {
                if (index == 0) std::cout << MatA[i][j] << " ";
                else if (index == 1) std::cout << MatB[i][j] << " ";
                else if (index == 2) std::cout << MatC[i][j] << " ";
                else if (index == 3) std::cout << MatD[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}

float determinant2x2(const std::vector<std::vector<float>>& matrix) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

float determinant3x3(const std::vector<std::vector<float>>& matrix) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
           matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
           matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

void inverse2x2(const std::vector<std::vector<float>>& matrix, float det, std::vector<std::vector<float>>& inv) {
    inv.resize(2, std::vector<float>(2));
    inv[0][0] =  matrix[1][1] / det;
    inv[0][1] = -matrix[0][1] / det;
    inv[1][0] = -matrix[1][0] / det;
    inv[1][1] =  matrix[0][0] / det;

    std::cout << "La inversa de la matriz es:" << std::endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << inv[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void inverse3x3(const std::vector<std::vector<float>>& matrix, float det, std::vector<std::vector<float>>& inv) {
    inv.resize(3, std::vector<float>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int sign = ((i + j) % 2 == 0) ? 1 : -1;
            std::vector<std::vector<float>> minor(2, std::vector<float>(2));
            int row = 0;
            for (int r = 0; r < 3; ++r) {
                if (r == i) continue;
                int col = 0;
                for (int c = 0; c < 3; ++c) {
                    if (c == j) continue;
                    minor[row][col] = matrix[r][c];
                    ++col;
                }
                ++row;
            }
            inv[j][i] = sign * determinant2x2(minor) / det;
        }
    }

    std::cout << "La inversa de la matriz es:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << inv[i][j] << " ";
        }
        std::cout << std::endl;
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
    void distancia();
    void angulo();
    void simetria();
    void proyeccion_ortogonal();
    void rango();
    void interseccion();
    void volumen_area();

  

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
                menu_geometria:
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
                        break;

                    default:
                        std::cout << "Opcion no valida." << std::endl;
                }
                if (opcionDatos != 5) {
                    goto menu_geometria;
                }
                break;
                
            

            case 2: 
                menu_geometria2:
                std::cout << "Seleccione opcion:" << std::endl;
                std::cout << "1. Distancia" << std::endl;
                std::cout << "2. Angulo" << std::endl;
                std::cout << "3. Simetria" << std::endl;
                std::cout << "4. Proyeccion ortogonal" << std::endl;
                std::cout << "5. Rango" << std::endl;
                std::cout << "6. Interseccion" << std::endl;
                std::cout << "7. Volumen y Area" << std::endl;
                std::cout << "8. Regresar al menu anterior" << std::endl;

                int opcionCalculo;
                std::cin >> opcionCalculo;

                switch (opcionCalculo) {
                    case 1: 
                        //distancia();
                        break;

                    case 2: 
                        //angulo();
                        break;

                    case 3: 
                        //simetria();
                        break;

                    case 4: 
                        //proyeccion_ortogonal();
                        break;

                    case 5: 
                        //rango();
                        break;

                    case 6: 
                        //interseccion();
                        break;

                    case 7: 
                        //volumen_area();
                        break;

                    case 8:
                        break;


                    default:
                        std::cout << "Opcion no valida." << std::endl;
                }
                if (opcionCalculo != 8) {
                    goto menu_geometria2;
                }

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


