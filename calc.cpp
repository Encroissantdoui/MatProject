#include <iostream>
#include <math.h>
#include <string>
#include <vector>




void matrices();
void geometria();
void sistema_lineal();




//MENU PRINCIPAL

int main() {

    while (true) {
        std::cout << "Seleccionar el bloque para calculos:\n";
        std::cout << "1. Algebra\n";
        std::cout << "2. Geometria\n";
        std::cout << "3. Sistemas de ecuaciones lineales\n";
        std::cout << "4. Terminar\n";

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
                sistema_lineal();
                break;

            case 4: 
                std::cout << "Terminando el programa..." << std::endl;
                return 0;

            default:
                std::cout << "Bloque no valido" << std::endl;
        }
    }
}

//BLOQUE DE ALGEBRA




std::vector<std::vector<float>> MatA, MatB, MatC, MatD;
std::vector<int> rows(4, 0), cols(4, 0);

void matrices() {

    float determinant2x2(const std::vector<std::vector<float>>& matrix);
    float determinant3x3(const std::vector<std::vector<float>>& matrix);
    void inverse2x2(const std::vector<std::vector<float>>& matrix, float det, std::vector<std::vector<float>>& inv);
    void inverse3x3(const std::vector<std::vector<float>>& matrix, float det, std::vector<std::vector<float>>& inv);
    void adjointAndInverse3x3(const std::vector<std::vector<float>>& matrix, std::vector<std::vector<float>>& adj, std::vector<std::vector<float>>& inv);
    void IntroducirDatosMatrices();
    void mostrarMatrices();
  

    while (true) {
        std::cout << "\nMenu de matrices:\n";
        std::cout << "1. Introducir datos\n";
        std::cout << "2. Realizar calculos\n";
        std::cout << "3. Volver al menu principal\n";
        std::cout << "4. Mostrar matrices\n";
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
                            std::vector<std::vector<float>> adjoint;
                            if (index == 0) determinant = determinant3x3(MatA);
                            else if (index == 1) determinant = determinant3x3(MatB);
                            else if (index == 2) determinant = determinant3x3(MatC);
                            else if (index == 3) determinant = determinant3x3(MatD);

                            if (determinant != 0) {
                                if (index == 0) adjointAndInverse3x3(MatA, adjoint, inverse);
                                else if (index == 1) adjointAndInverse3x3(MatB, adjoint, inverse);
                                else if (index == 2) adjointAndInverse3x3(MatC, adjoint, inverse);
                                else if (index == 3) adjointAndInverse3x3(MatD, adjoint, inverse);
                            }

                        } else {
                            std::cout << "No existe la inversa" << std::endl;
                            continue;
                        }

                        if (determinant == 0) {
                            std::cout << "La matriz no tiene inversa (determinante = 0)." << std::endl;
                        }
                    }

                    if (opcion == 3) {
                        std::cout << "Seleccione las matrices para sumar:" << std::endl;
                        std::cout << "1. MatA" << std::endl;
                        std::cout << "2. MatB" << std::endl;
                        std::cout << "3. MatC" << std::endl;
                        std::cout << "4. MatD" << std::endl;

                        int matriz1, matriz2;
                        std::cout << "Seleccione la primera matriz: ";
                        std::cin >> matriz1;
                        std::cout << "Seleccione la segunda matriz: ";
                        std::cin >> matriz2;

                        if (matriz1 < 1 || matriz1 > 4 || matriz2 < 1 || matriz2 > 4) {
                            std::cout << "Opcion no valida." << std::endl;
                            continue;
                        }

                        int index1 = matriz1 - 1;
                        int index2 = matriz2 - 1;

                        if (rows[index1] != rows[index2] || cols[index1] != cols[index2]) {
                            std::cout << "Las matrices deben tener el mismo numero de filas y columnas para ser sumadas." << std::endl;
                            continue;
                        }

                        std::vector<std::vector<float>> result(rows[index1], std::vector<float>(cols[index1]));

                        for (int i = 0; i < rows[index1]; ++i) {
                            for (int j = 0; j < cols[index1]; ++j) {
                                if (index1 == 0 && index2 == 1) result[i][j] = MatA[i][j] + MatB[i][j];
                                else if (index1 == 0 && index2 == 2) result[i][j] = MatA[i][j] + MatC[i][j];
                                else if (index1 == 0 && index2 == 3) result[i][j] = MatA[i][j] + MatD[i][j];
                                else if (index1 == 1 && index2 == 2) result[i][j] = MatB[i][j] + MatC[i][j];
                                else if (index1 == 1 && index2 == 3) result[i][j] = MatB[i][j] + MatD[i][j];
                                else if (index1 == 2 && index2 == 3) result[i][j] = MatC[i][j] + MatD[i][j];
                                else if (index1 == 1 && index2 == 0) result[i][j] = MatB[i][j] + MatA[i][j];
                                else if (index1 == 2 && index2 == 0) result[i][j] = MatC[i][j] + MatA[i][j];
                                else if (index1 == 3 && index2 == 0) result[i][j] = MatD[i][j] + MatA[i][j];
                                else if (index1 == 2 && index2 == 1) result[i][j] = MatC[i][j] + MatB[i][j];
                                else if (index1 == 3 && index2 == 1) result[i][j] = MatD[i][j] + MatB[i][j];
                                else if (index1 == 3 && index2 == 2) result[i][j] = MatD[i][j] + MatC[i][j];
                            }
                        }

                        std::cout << "La suma de las matrices es:" << std::endl;
                        for (int i = 0; i < rows[index1]; ++i) {
                            for (int j = 0; j < cols[index1]; ++j) {
                                std::cout << result[i][j] << " ";
                            }
                            std::cout << std::endl;
                        }
                    }

                    if (opcion == 4) {
                        std::cout << "Seleccione las matrices para restar:" << std::endl;
                        std::cout << "1. MatA" << std::endl;
                        std::cout << "2. MatB" << std::endl;
                        std::cout << "3. MatC" << std::endl;
                        std::cout << "4. MatD" << std::endl;

                        int matriz1, matriz2;
                        std::cout << "Seleccione la primera matriz: ";
                        std::cin >> matriz1;
                        std::cout << "Seleccione la segunda matriz: ";
                        std::cin >> matriz2;

                        if (matriz1 < 1 || matriz1 > 4 || matriz2 < 1 || matriz2 > 4) {
                            std::cout << "Opcion no valida." << std::endl;
                            continue;
                        }

                        int index1 = matriz1 - 1;
                        int index2 = matriz2 - 1;

                        if (rows[index1] != rows[index2] || cols[index1] != cols[index2]) {
                            std::cout << "Las matrices deben tener el mismo numero de filas y columnas para ser restadas." << std::endl;
                            continue;
                        }

                        std::vector<std::vector<float>> result(rows[index1], std::vector<float>(cols[index1]));

                        for (int i = 0; i < rows[index1]; ++i) {
                            for (int j = 0; j < cols[index1]; ++j) {
                                if (index1 == 0 && index2 == 1) result[i][j] = MatA[i][j] - MatB[i][j];
                                else if (index1 == 0 && index2 == 2) result[i][j] = MatA[i][j] - MatC[i][j];
                                else if (index1 == 0 && index2 == 3) result[i][j] = MatA[i][j] - MatD[i][j];
                                else if (index1 == 1 && index2 == 2) result[i][j] = MatB[i][j] - MatC[i][j];
                                else if (index1 == 1 && index2 == 3) result[i][j] = MatB[i][j] - MatD[i][j];
                                else if (index1 == 2 && index2 == 3) result[i][j] = MatC[i][j] - MatD[i][j];
                                else if (index1 == 1 && index2 == 0) result[i][j] = MatB[i][j] - MatA[i][j];
                                else if (index1 == 2 && index2 == 0) result[i][j] = MatC[i][j] - MatA[i][j];
                                else if (index1 == 3 && index2 == 0) result[i][j] = MatD[i][j] - MatA[i][j];
                                else if (index1 == 2 && index2 == 1) result[i][j] = MatC[i][j] - MatB[i][j];
                                else if (index1 == 3 && index2 == 1) result[i][j] = MatD[i][j] - MatB[i][j];
                                else if (index1 == 3 && index2 == 2) result[i][j] = MatD[i][j] - MatC[i][j];
                            }
                        }

                        std::cout << "La resta de las matrices es:" << std::endl;
                        for (int i = 0; i < rows[index1]; ++i) {
                            for (int j = 0; j < cols[index1]; ++j) {
                                std::cout << result[i][j] << " ";
                            }
                            std::cout << std::endl;
                        }
                    }

                    if (opcion == 5) {
                        std::cout << "Seleccione las matrices para multiplicar:" << std::endl;
                        std::cout << "1. MatA" << std::endl;
                        std::cout << "2. MatB" << std::endl;
                        std::cout << "3. MatC" << std::endl;
                        std::cout << "4. MatD" << std::endl;

                        int matriz1, matriz2;
                        std::cout << "Seleccione la primera matriz: ";
                        std::cin >> matriz1;
                        std::cout << "Seleccione la segunda matriz: ";
                        std::cin >> matriz2;

                        if (matriz1 < 1 || matriz1 > 4 || matriz2 < 1 || matriz2 > 4) {
                            std::cout << "Opcion no valida." << std::endl;
                            continue;
                        }

                        int index1 = matriz1 - 1;
                        int index2 = matriz2 - 1;

                        if (cols[index1] != rows[index2]) {
                            std::cout << "El numero de columnas de la primera matriz debe ser igual al numero de filas de la segunda matriz." << std::endl;
                            continue;
                        }

                        std::vector<std::vector<float>> result(rows[index1], std::vector<float>(cols[index2], 0));

                        for (int i = 0; i < rows[index1]; ++i) {
                            for (int j = 0; j < cols[index2]; ++j) {
                                for (int k = 0; k < cols[index1]; ++k) {
                                    if (index1 == 0 && index2 == 1) result[i][j] += MatA[i][k] * MatB[k][j];
                                    else if (index1 == 0 && index2 == 2) result[i][j] += MatA[i][k] * MatC[k][j];
                                    else if (index1 == 0 && index2 == 3) result[i][j] += MatA[i][k] * MatD[k][j];
                                    else if (index1 == 1 && index2 == 2) result[i][j] += MatB[i][k] * MatC[k][j];
                                    else if (index1 == 1 && index2 == 3) result[i][j] += MatB[i][k] * MatD[k][j];
                                    else if (index1 == 2 && index2 == 3) result[i][j] += MatC[i][k] * MatD[k][j];
                                    else if (index1 == 1 && index2 == 0) result[i][j] += MatB[i][k] * MatA[k][j];
                                    else if (index1 == 2 && index2 == 0) result[i][j] += MatC[i][k] * MatA[k][j];
                                    else if (index1 == 3 && index2 == 0) result[i][j] += MatD[i][k] * MatA[k][j];
                                    else if (index1 == 2 && index2 == 1) result[i][j] += MatC[i][k] * MatB[k][j];
                                    else if (index1 == 3 && index2 == 1) result[i][j] += MatD[i][k] * MatB[k][j];
                                    else if (index1 == 3 && index2 == 2) result[i][j] += MatD[i][k] * MatC[k][j];
                                }
                            }
                        }

                        std::cout << "El producto de las matrices es:" << std::endl;
                        for (int i = 0; i < rows[index1]; ++i) {
                            for (int j = 0; j < cols[index2]; ++j) {
                                std::cout << result[i][j] << " ";
                            }
                            std::cout << std::endl;
                        }
                    }

                    if (opcion == 6) {
                        break; // Go back to the main menu
                    }
                }
                break;

            case 3:
                return;

            case 4:
                mostrarMatrices();
                break;

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

void mostrarMatrices() {
    std::cout << "Matrices introducidas:\n";

    std::vector<std::vector<std::vector<float>>> matrices = {MatA, MatB, MatC, MatD};
    std::string nombres[] = {"MatA", "MatB", "MatC", "MatD"};

    for (int i = 0; i < 4; i++) {
        std::cout << nombres[i] << ":\n";
        if (matrices[i].empty()) {
            std::cout << "No definida\n";
        } else {
            for (int j = 0; j < matrices[i].size(); j++) {
                for (int k = 0; k < matrices[i][j].size(); k++) {
                    std::cout << matrices[i][j][k] << " ";
                }
                std::cout << "\n";
            }
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

/*

void inverse3x3(const std::vector<std::vector<float>>& matrix, float det, std::vector<std::vector<float>>& inv) {
    inv.resize(3, std::vector<float>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int sign;
            if ((i + j) % 2 == 0) {
                sign = 1;
            } else {
                sign = -1;
            }
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

*/
void adjointAndInverse3x3(const std::vector<std::vector<float>>& matrix, std::vector<std::vector<float>>& adj, std::vector<std::vector<float>>& inv) {
    float det = determinant3x3(matrix);

    if (det == 0) {
        std::cout << "No existe inversa (determinante = 0)\n";
        return;
    }

    adj.resize(3, std::vector<float>(3));
    adj[0][0] =  matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1];
    adj[1][0] = -(matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]);
    adj[2][0] =  matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0];

    adj[0][1] = -(matrix[0][1] * matrix[2][2] - matrix[0][2] * matrix[2][1]);
    adj[1][1] =  matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0];
    adj[2][1] = -(matrix[0][0] * matrix[2][1] - matrix[0][1] * matrix[2][0]);

    adj[0][2] =  matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1];
    adj[1][2] = -(matrix[0][0] * matrix[1][2] - matrix[0][2] * matrix[1][0]);
    adj[2][2] =  matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    inv.resize(3, std::vector<float>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            inv[i][j] = adj[i][j] / det;
        }
    }

    std::cout << "La inversa de la matriz es:\n";
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
    void posicion_relativa();
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
                std::cout << "3. Posicion relativa" << std::endl;
                std::cout << "4. Volumen y area" << std::endl;
                std::cout << "5. Salir" << std::endl;


                int opcionCalculo;
                std::cin >> opcionCalculo;

                switch (opcionCalculo) {
                    case 1: 
                        distancia();
                        break;

                    case 2: 
                        angulo();
                        break;

                    case 3: 
                        posicion_relativa();
                        break;

                    case 4: 
                        volumen_area();
                        break;


                    case 5:
                       
                        break;


                    default:
                        std::cout << "Opcion no valida." << std::endl;
                }


                break;
            
            case 3:

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





std::vector<std::vector<std::vector<float>>> rectas(4, std::vector<std::vector<float>>(2, std::vector<float>(3)));

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


    rectas[rectaSeleccionada - 1][0] = punto;
    rectas[rectaSeleccionada - 1][1] = vector;

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
        planoecuacion[planoSeleccionado - 1] = std::to_string(A) + "x + " + std::to_string(B) + "y + " + std::to_string(C) + "z + " + std::to_string(D) + " = 0";

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


        planoecuacion[planoSeleccionado - 1] = std::to_string(A) + "x + " + std::to_string(B) + "y + " + std::to_string(C) + "z + " + std::to_string(D) + " = 0";

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
        if (rectas[i][0].empty() || rectas[i][1].empty()) {
            std::cout << "R" << i + 1 << ": No definida\n";
        } else {
            std::cout << "R" << i + 1 << ": Punto (" << rectas[i][0][0] << ", " << rectas[i][0][1] << ", " << rectas[i][0][2] << ")";
            std::cout << ", Vector (" << rectas[i][1][0] << ", " << rectas[i][1][1] << ", " << rectas[i][1][2] << ")\n";
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

void distancia() {


    while (true) {
        std::cout << "\nMenu de distancia:\n";
        std::cout << "1. Distancia entre puntos\n";
        std::cout << "2. Distancia entre punto y recta\n";
        std::cout << "3. Distancia entre punto y plano\n";
        std::cout << "4. Regresar al menu anterior\n";
        std::cout << "Seleccione una opcion: ";

        int opcion;
        std::cin >> opcion;

        switch (opcion) {
            case 1:
            {
            std::cout << "Seleccione dos puntos de los introducidos:\n";
            std::cout << "1. PA\n";
            std::cout << "2. PB\n";
            std::cout << "3. PC\n";
            std::cout << "4. PD\n";

            int idx1 = 0, idx2 = 0;
            std::cout << "Introduce el numero del primer punto: ";
            std::cin >> idx1;
            std::cout << "Introduce el numero del segundo punto: ";
            std::cin >> idx2;

            if (idx1 < 1 || idx1 > 4 || idx2 < 1 || idx2 > 4) {
                std::cout << "Seleccion invalida.\n";
                break;
            }

     
            std::vector<float> p1, p2;
            if (idx1 == 1) p1 = PA;
            else if (idx1 == 2) p1 = PB;
            else if (idx1 == 3) p1 = PC;
            else if (idx1 == 4) p1 = PD;

            if (idx2 == 1) p2 = PA;
            else if (idx2 == 2) p2 = PB;
            else if (idx2 == 3) p2 = PC;
            else if (idx2 == 4) p2 = PD;


            float distancia = sqrt(pow(p2[0] - p1[0], 2) + pow(p2[1] - p1[1], 2) + pow(p2[2] - p1[2], 2));

            std::cout << "La distancia entre los puntos seleccionados es: " << distancia << "\n";
            }
            break;

            case 2:
            {
                std::cout << "Seleccione un punto de los introducidos:\n";
                std::cout << "1. PA\n";
                std::cout << "2. PB\n";
                std::cout << "3. PC\n";
                std::cout << "4. PD\n";

                int idx = 0;
                std::cout << "Ingrese el numero del punto: ";
                std::cin >> idx;

                if (idx < 1 || idx > 4) {
                    std::cout << "Seleccion invalida. Intente de nuevo.\n";
                    break;
                }

                std::vector<float> p;
                if (idx == 1) p = PA;
                else if (idx == 2) p = PB;
                else if (idx == 3) p = PC;
                else if (idx == 4) p = PD;

                std::cout << "Seleccione la recta:\n";
                std::cout << "1. R1\n";
                std::cout << "2. R2\n";
                std::cout << "3. R3\n";
                std::cout << "4. R4\n";

                int rectaIdx = 0;
                std::cout << "Ingrese el numero de la recta: ";
                std::cin >> rectaIdx;

                if (rectaIdx < 1 || rectaIdx > 4 || rectas[rectaIdx - 1][0].empty() || rectas[rectaIdx - 1][1].empty()) {
                    std::cout << "Seleccion invalida o recta no definida.\n";
                    break;
                }

                std::vector<float> linePoint = rectas[rectaIdx - 1][0];
                std::vector<float> lineVector = rectas[rectaIdx - 1][1];

                // Calculate the vector from the line point to the selected point
                std::vector<float> lineToPoint(3);
                for (int i = 0; i < 3; ++i) {
                    lineToPoint[i] = p[i] - linePoint[i];
                }

                // Calculate the cross product of lineVector and lineToPoint
                std::vector<float> crossProduct(3);
                crossProduct[0] = lineVector[1] * lineToPoint[2] - lineVector[2] * lineToPoint[1];
                crossProduct[1] = lineVector[2] * lineToPoint[0] - lineVector[0] * lineToPoint[2];
                crossProduct[2] = lineVector[0] * lineToPoint[1] - lineVector[1] * lineToPoint[0];

                // Calculate the magnitude of the cross product
                float crossMagnitude = sqrt(pow(crossProduct[0], 2) + pow(crossProduct[1], 2) + pow(crossProduct[2], 2));

                // Calculate the magnitude of the line vector
                float lineMagnitude = sqrt(pow(lineVector[0], 2) + pow(lineVector[1], 2) + pow(lineVector[2], 2));

                // Calculate the distance
                float distance = crossMagnitude / lineMagnitude;

                std::cout << "La distancia entre el punto y la recta es: " << distance << "\n";
            }
            break;

            case 3:
            {
                std::cout << "Seleccione un punto de los introducidos:\n";
                std::cout << "1. PA\n";
                std::cout << "2. PB\n";
                std::cout << "3. PC\n";
                std::cout << "4. PD\n";

                int idx = 0;
                std::cout << "Ingrese el numero del punto: ";
                std::cin >> idx;

                if (idx < 1 || idx > 4) {
                    std::cout << "Seleccion invalida. Intente de nuevo.\n";
                    break;
                }

                std::vector<float> p;
                if (idx == 1) p = PA;
                else if (idx == 2) p = PB;
                else if (idx == 3) p = PC;
                else if (idx == 4) p = PD;

                std::cout << "Seleccione el plano:\n";
                std::cout << "1. Pla1\n";
                std::cout << "2. Pla2\n";
                std::cout << "3. Pla3\n";
                std::cout << "4. Pla4\n";

                int planoIdx = 0;
                std::cout << "Ingrese el numero del plano: ";
                std::cin >> planoIdx;

                if (planoIdx < 1 || planoIdx > 4 || planoecuacion[planoIdx - 1].empty()) {
                    std::cout << "Seleccion invalida o plano no definido.\n";
                    break;
                }

                // Calculate the distance using the plane's normal and equation
                float A = planeNormals[planoIdx - 1][0];
                float B = planeNormals[planoIdx - 1][1];
                float C = planeNormals[planoIdx - 1][2];
                float D = -(A * PA[0] + B * PA[1] + C * PA[2]); // Assuming D is calculated from PA

                // Calculate the numerator: |Ax + By + Cz + D|
                float numerator = fabs(A * p[0] + B * p[1] + C * p[2] + D);

                // Calculate the denominator: sqrt(A^2 + B^2 + C^2)
                float denominator = sqrt(A * A + B * B + C * C);

                if (denominator == 0) {
                    std::cout << "El plano tiene una normal invalida, no se puede calcular la distancia.\n";
                    break;
                }

                
                float distance = numerator / denominator;

                std::cout << "La distancia entre el punto y el plano es: " << distance << "\n";
            }
            break;

            case 4:
                return; 

            default:
                std::cout << "Opcion no valida. Intente de nuevo.\n";
        }
    }
}




void angulo() {

    while (true) {
        std::cout << "\nMenu de angulo:\n";
        std::cout << "1. Angulo entre vectores\n";
        std::cout << "2. Angulo entre plano y recta\n";
        std::cout << "3. Regresar al menu anterior\n";
        std::cout << "Seleccione una opcion: ";

        int opcion;
        std::cin >> opcion;

        switch (opcion) {
            case 1:
            {
                std::cout << "Seleccione el primer vector:\n";
                std::cout << "1. VA\n";
                std::cout << "2. VB\n";
                std::cout << "3. VC\n";
                std::cout << "4. VD\n";
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
                        break;
                }

                std::cout << "Seleccione el segundo vector:\n";
                std::cout << "1. VA\n";
                std::cout << "2. VB\n";
                std::cout << "3. VC\n";
                std::cout << "4. VD\n";
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
                        break;
                }

                // Calculate dot product
                float dotProduct = 0;
                for (int i = 0; i < 3; ++i) {
                    dotProduct += vector1[i] * vector2[i];
                }

                // Calculate magnitudes
                float magnitude1 = 0, magnitude2 = 0;
                for (int i = 0; i < 3; ++i) {
                    magnitude1 += vector1[i] * vector1[i];
                    magnitude2 += vector2[i] * vector2[i];
                }
                magnitude1 = std::sqrt(magnitude1);
                magnitude2 = std::sqrt(magnitude2);

                // Calculate angle
                if (magnitude1 == 0 || magnitude2 == 0) {
                    std::cout << "Uno de los vectores tiene magnitud cero, no se puede calcular el angulo.\n";
                    break;
                }

                float angle = acos(dotProduct / (magnitude1 * magnitude2));

                std::cout << "El angulo entre los dos vectores es: " << angle * (180/M_PI) << " grados.\n";
                break;
            }
            case 2:
            {
                std::cout << "Seleccione el vector:\n";
                std::cout << "1. VA\n";
                std::cout << "2. VB\n";
                std::cout << "3. VC\n";
                std::cout << "4. VD\n";
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
                        break;
                }

                std::cout << "Seleccione el plano:\n";
                std::cout << "1. Pla1\n";
                std::cout << "2. Pla2\n";
                std::cout << "3. Pla3\n";
                std::cout << "4. Pla4\n";
                int planoSeleccionado;
                std::cin >> planoSeleccionado;

                std::vector<float> planeNormal;
                switch (planoSeleccionado) {
                    case 1: planeNormal = planeNormals[0]; break;
                    case 2: planeNormal = planeNormals[1]; break;
                    case 3: planeNormal = planeNormals[2]; break;
                    case 4: planeNormal = planeNormals[3]; break;
                    default:
                        std::cout << "Opcion no valida para el plano." << std::endl;
                        break;
                }

                // Calculate dot product
                float dotProduct = 0;
                for (int i = 0; i < 3; ++i) {
                    dotProduct += vector[i] * planeNormal[i];
                }

                // Calculate magnitudes
                float magnitudeVector = 0, magnitudePlaneNormal = 0;
                for (int i = 0; i < 3; ++i) {
                    magnitudeVector += vector[i] * vector[i];
                    magnitudePlaneNormal += planeNormal[i] * planeNormal[i];
                }
                magnitudeVector = std::sqrt(magnitudeVector);
                magnitudePlaneNormal = std::sqrt(magnitudePlaneNormal);

                // Calculate angle using arcsin
                if (magnitudeVector == 0 || magnitudePlaneNormal == 0) {
                    std::cout << "El vector o el plano tiene magnitud cero, no se puede calcular el angulo.\n";
                    break;
                }

                float angle = asin(dotProduct / (magnitudeVector * magnitudePlaneNormal));

                std::cout << "El angulo entre el vector y el plano es: " << angle * (180/M_PI) << " grados.\n";
                break;
            }
            case 3:
                return;
            default:
                std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    }
}


void volumen_area() {

    while (true) {
        std::cout << "\nMenu de volumen y area:\n";
        std::cout << "1. Area de paralelogramo\n";
        std::cout << "2. Area de triangulo\n";
        std::cout << "3. Volumen de tetraedro\n";
        std::cout << "4. Volumen de paralelepipedo\n";
        std::cout << "5. Regresar al menu anterior\n";
        std::cout << "Seleccione una opcion: ";

        int opcion;
        std::cin >> opcion;

        switch (opcion) {
            case 1:
            {
                std::cout << "Seleccione el primer vector:\n";
                std::cout << "1. VA\n";
                std::cout << "2. VB\n";
                std::cout << "3. VC\n";
                std::cout << "4. VD\n";
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
                        break;
                }

                std::cout << "Seleccione el segundo vector:\n";
                std::cout << "1. VA\n";
                std::cout << "2. VB\n";
                std::cout << "3. VC\n";
                std::cout << "4. VD\n";
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
                        break;
                }

                // Calculate cross product
                std::vector<float> crossProduct(3);
                crossProduct[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
                crossProduct[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2];
                crossProduct[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];

                // Calculate magnitude of the cross product (area)
                float area = std::sqrt(crossProduct[0] * crossProduct[0] + crossProduct[1] * crossProduct[1] + crossProduct[2] * crossProduct[2]);

                std::cout << "El area del paralelogramo definido por los dos vectores es: " << area << "\n";
                break;
            }
            case 2:
            {

                std::cout << "Seleccione el primer vector:\n";
                std::cout << "1. VA\n";
                std::cout << "2. VB\n";
                std::cout << "3. VC\n";
                std::cout << "4. VD\n";
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
                        break;
                }

                std::cout << "Seleccione el segundo vector:\n";
                std::cout << "1. VA\n";
                std::cout << "2. VB\n";
                std::cout << "3. VC\n";
                std::cout << "4. VD\n";
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
                        break;
                }

                // Calculate cross product
                std::vector<float> crossProduct(3);
                crossProduct[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
                crossProduct[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2];
                crossProduct[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];

                // Calculate magnitude of the cross product (area)
                float area = std::sqrt(crossProduct[0] * crossProduct[0] + crossProduct[1] * crossProduct[1] + crossProduct[2] * crossProduct[2]);

                std::cout << "El area del triangulo definido por los dos vectores es: " << (area/2) << "\n";




                break;
            }
            case 3:
            {
                std::cout << "Seleccione el primer vector:\n";
                std::cout << "1. VA\n";
                std::cout << "2. VB\n";
                std::cout << "3. VC\n";
                std::cout << "4. VD\n";
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
                        break;
                }

                std::cout << "Seleccione el segundo vector:\n";
                std::cout << "1. VA\n";
                std::cout << "2. VB\n";
                std::cout << "3. VC\n";
                std::cout << "4. VD\n";
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
                        break;
                }

                std::cout << "Seleccione el tercer vector:\n";
                std::cout << "1. VA\n";
                std::cout << "2. VB\n";
                std::cout << "3. VC\n";
                std::cout << "4. VD\n";
                int vector3Seleccionado;
                std::cin >> vector3Seleccionado;

                std::vector<float> vector3;
                switch (vector3Seleccionado) {
                    case 1: vector3 = VA; break;
                    case 2: vector3 = VB; break;
                    case 3: vector3 = VC; break;
                    case 4: vector3 = VD; break;
                    default:
                        std::cout << "Opcion no valida para el tercer vector." << std::endl;
                        break;
                }

                
                std::vector<std::vector<float>> matrix = {
                    {vector1[0], vector1[1], vector1[2]},
                    {vector2[0], vector2[1], vector2[2]},
                    {vector3[0], vector3[1], vector3[2]}
                };

                
                float determinant = determinant3x3(matrix);

                
                float volume = std::abs(determinant) / 6.0;

                std::cout << "El volumen del tetraedro definido por los tres vectores es: " << volume << "\n";
                break;
            }
            case 4:
            {
                std::cout << "Seleccione el primer vector:\n";
                std::cout << "1. VA\n";
                std::cout << "2. VB\n";
                std::cout << "3. VC\n";
                std::cout << "4. VD\n";
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
                        break;
                }

                std::cout << "Seleccione el segundo vector:\n";
                std::cout << "1. VA\n";
                std::cout << "2. VB\n";
                std::cout << "3. VC\n";
                std::cout << "4. VD\n";
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
                        break;
                }

                std::cout << "Seleccione el tercer vector:\n";
                std::cout << "1. VA\n";
                std::cout << "2. VB\n";
                std::cout << "3. VC\n";
                std::cout << "4. VD\n";
                int vector3Seleccionado;
                std::cin >> vector3Seleccionado;

                std::vector<float> vector3;
                switch (vector3Seleccionado) {
                    case 1: vector3 = VA; break;
                    case 2: vector3 = VB; break;
                    case 3: vector3 = VC; break;
                    case 4: vector3 = VD; break;
                    default:
                        std::cout << "Opcion no valida para el tercer vector." << std::endl;
                        break;
                }

                
                std::vector<std::vector<float>> matrix = {
                    {vector1[0], vector1[1], vector1[2]},
                    {vector2[0], vector2[1], vector2[2]},
                    {vector3[0], vector3[1], vector3[2]}
                };

                
                float determinant = determinant3x3(matrix);

                
                float volume = std::abs(determinant);

                std::cout << "El volumen del paralelepipedo definido por los tres vectores es: " << volume << "\n";
                break;
            }
                
                break;

            case 5:
                
                return; 

            default:
                std::cout << "Opcion no valida. Intente de nuevo.\n";
        }
    }


}


void posicion_relativa() {

    std::cout << "Menu de posicion relativa:\n";
    std::cout << "1. Recta y recta\n";
    std::cout << "2. Recta y plano\n";
    std::cout << "3. Plano y plano\n";
    std::cout << "4. 3 planos\n";
    std::cout << "5. Salir\n";
    std::cout << "Seleccione una opcion: ";

    int opcion;
    std::cin >> opcion;

    switch (opcion) {
        case 1:
        {
            std::cout << "Recta y recta\n";
            // Implementar la lógica para recta y recta
            break;
        }
        case 2:
            std::cout << "Recta y plano\n";
            // Implementar la lógica para recta y plano
            break;
        case 3:
            std::cout << "Plano y plano\n";
            // Implementar la lógica para plano y plano
            break;
        case 4:
            std::cout << "3 planos\n";
            // Implementar la lógica para 3 planos
            break;
        case 5:
            return; 
        default:
            std::cout << "Opcion no valida. Intente de nuevo.\n";
    }


}










// SISTEMA LINEAL

std::vector<std::vector<int>> matrix3x3(3, std::vector<int>(3));
std::vector<std::vector<int>> matrix3x4(3, std::vector<int>(4));



void sistema_lineal() {

    void rouche_frobenius();
    int calculateRango(std::vector<std::vector<int>>& matrix, int rows, int cols);
    void solucionar_sistema();

    menu_sistema:

    std::cout << "Sistema Lineal\n";
    std::cout << "1. Introducir ecuacion\n";
    std::cout << "2. Realizar calculos\n";
    std::cout << "3. Regresar al menu anterior\n";
    std::cout << "Seleccione una opcion: ";

    int opcion;
    std::cin >> opcion;

    switch (opcion) {
        case 1:
        {
            int A1, B1, C1, D1, A2, B2, C2, D2, A3, B3, C3, D3;

            std::cout << "Introducir ecuacion:\n";
            std::cout << "A1x + B1y + C1z = D1\n";
            std::cout << "A2x + B2y + C2z = D2\n";
            std::cout << "A3x + B3y + C3z = D3\n";
            std::cout << "Introducir A1: ";
            std::cin >> A1;
            std::cout << "Introducir B1: ";
            std::cin >> B1;
            std::cout << "Introducir C1: ";
            std::cin >> C1;
            std::cout << "Introducir D1: ";
            std::cin >> D1;
            std::cout << "Introducir A2: ";
            std::cin >> A2;
            std::cout << "Introducir B2: ";
            std::cin >> B2;
            std::cout << "Introducir C2: ";
            std::cin >> C2;
            std::cout << "Introducir D2: ";
            std::cin >> D2;
            std::cout << "Introducir A3: ";
            std::cin >> A3;
            std::cout << "Introducir B3: ";
            std::cin >> B3;
            std::cout << "Introducir C3: ";
            std::cin >> C3;
            std::cout << "Introducir D3: ";
            std::cin >> D3;

            
            matrix3x3 = {
                {A1, B1, C1},
                {A2, B2, C2},
                {A3, B3, C3}
            };

            
            matrix3x4 = {
                {A1, B1, C1, D1},
                {A2, B2, C2, D2},
                {A3, B3, C3, D3}
            };

            std::cout<<matrix3x3[0][0]<<" "<<matrix3x3[0][1]<<" "<<matrix3x3[0][2]<<" "<<std::endl;
            std::cout<<matrix3x3[1][0]<<" "<<matrix3x3[1][1]<<" "<<matrix3x3[1][2]<<" "<<std::endl;
            std::cout<<matrix3x3[2][0]<<" "<<matrix3x3[2][1]<<" "<<matrix3x3[2][2]<<" "<<std::endl;
            
            std::cout<<matrix3x4[0][0]<<" "<<matrix3x4[0][1]<<" "<<matrix3x4[0][2]<<" "<<matrix3x4[0][3]<<std::endl;
            std::cout<<matrix3x4[1][0]<<" "<<matrix3x4[1][1]<<" "<<matrix3x4[1][2]<<" "<<matrix3x4[1][3]<<std::endl;
            std::cout<<matrix3x4[2][0]<<" "<<matrix3x4[2][1]<<" "<<matrix3x4[2][2]<<" "<<matrix3x4[2][3]<<std::endl;



            goto menu_sistema;
            break;
        }
        case 2:
        {
            std::cout << "Menu de calculos:\n";
            std::cout << "1. Tipo de sistema\n";
            std::cout << "2. Solucion del sistema\n";
            std::cout << "3. Salir\n";
            int calculoOpcion;
            std::cin >> calculoOpcion;
            switch (calculoOpcion) {
                case 1:
                    rouche_frobenius();
                    goto menu_sistema;
                    break;
                case 2:
                    solucionar_sistema();
                    goto menu_sistema;
                    break;
                case 3:
                    goto menu_sistema;
                default:
                    std::cout << "Opcion no valida. Intente de nuevo.\n";
            }


            break;
        }
        case 3:
            break; 
        default:
            std::cout << "Opcion no valida. Intente de nuevo.\n";
    }
}

int calculateRango(std::vector<std::vector<int>>& matrix, int rows, int cols) {
    int rango = std::min(rows, cols); // Ensure rango does not exceed the smaller dimension
    for (int row = 0; row < rango; ++row) {
        if (matrix[row][row] != 0) {
            for (int col = 0; col < rows; ++col) {
                if (col != row) {
                    float multiplier = static_cast<float>(matrix[col][row]) / matrix[row][row];
                    for (int i = 0; i < cols; ++i) {
                        matrix[col][i] -= static_cast<int>(multiplier * matrix[row][i]);
                    }
                }
            }
        } else {
            bool reducir = true;
            for (int i = row + 1; i < rows; ++i) {
                if (matrix[i][row] != 0) {
                    std::swap(matrix[row], matrix[i]);
                    reducir = false;
                    break;
                }
            }
            if (reducir) {
                --rango;
                for (int i = 0; i < rows; ++i) {
                    matrix[i][row] = matrix[i][rango];
                }
            }
            --row;
        }
    }
    return rango;
}

void rouche_frobenius() {
    // Create copies of the matrices to avoid modifying the originals
    std::vector<std::vector<int>> matrixA = matrix3x3;
    std::vector<std::vector<int>> matrixA_prime = matrix3x4;

    // Calculate ranks
    int rankA = calculateRango(matrixA, 3, 3);
    int rankA_prime = calculateRango(matrixA_prime, 3, 4);

    // Determine compatibility
    std::cout << "Rango of A: " << rankA << "\n";
    std::cout << "Rango of A': " << rankA_prime << "\n";

    if (rankA == rankA_prime) {
        if (rankA == 3) {
            std::cout << "Sistema compatible determinado.\n";
        } else {
            std::cout << "Sistema compatible indeterminado.\n";
        }
    } else {
        std::cout << "Sistema incompatible.\n";
    }
}

void solucionar_sistema() {
   
    std::vector<std::vector<float>> matrix3x3_float(3, std::vector<float>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix3x3_float[i][j] = static_cast<float>(matrix3x3[i][j]);
        }
    }
    float detA = determinant3x3(matrix3x3_float);
    if (detA == 0) {
        std::cout << "El sistema no tiene una solucion unica (determinante = 0).\n";
        return;
    }

    
    std::vector<std::vector<float>> Ax(3, std::vector<float>(3));
    std::vector<std::vector<float>> Ay(3, std::vector<float>(3));
    std::vector<std::vector<float>> Az(3, std::vector<float>(3));

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            Ax[i][j] = static_cast<float>(matrix3x3[i][j]);
            Ay[i][j] = static_cast<float>(matrix3x3[i][j]);
            Az[i][j] = static_cast<float>(matrix3x3[i][j]);
        }
    }

 
    for (int i = 0; i < 3; ++i) {
        Ax[i][0] = matrix3x4[i][3];
        Ay[i][1] = matrix3x4[i][3];
        Az[i][2] = matrix3x4[i][3];
    }


    float detAx = determinant3x3(Ax);
    float detAy = determinant3x3(Ay);
    float detAz = determinant3x3(Az);


    float x = detAx / detA;
    float y = detAy / detA;
    float z = detAz / detA;


    std::cout << "La solucion del sistema es:\n";
    std::cout << "x = " << x << "\n";
    std::cout << "y = " << y << "\n";
    std::cout << "z = " << z << "\n";
}