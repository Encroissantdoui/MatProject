#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

void matrices();
void geometria();
void analisis();

int main() {
    std::cout << "Seleccionar el bloque para calculos: \n1. Algebra \n2. Geometria \n3. Analisis" << std::endl;
    int bloque;
    std::cin >> bloque;
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
        default:
            std::cout << "Bloque no valido" << std::endl;
    }

    return 0;
}

void matrices() {
    float determinant2x2(float matrix[2][2]);
    float determinant3x3(float matrix[3][3]);
    void inverse(float matrix[3][3], float det, float inv[3][3]);
    void inverse2x2(float matrix[2][2], float det, float inv[2][2]);

    float MatA2x2[2][2] = {0}, MatB2x2[2][2] = {0};
    float MatA3x3[3][3] = {0}, MatB3x3[3][3] = {0};
    int sizeMatA = 0, sizeMatB = 0;

    // Input for MatA
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
        return;
    }

    // Input for MatB
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
        return;
    }

    // Menu for calculations
    while (true) {
        std::cout << "\nMenu de operaciones:\n";
        std::cout << "1. Calcular determinante\n";
        std::cout << "2. Calcular inversa\n";
        std::cout << "3. Salir\n";
        std::cout << "Seleccione una opcion: ";
        int opcion;
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::cout << "Seleccione la matriz para calcular el determinante:\n1. MatA\n2. MatB\n";
                int matrizSeleccionada;
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
            }
            case 2: {
                std::cout << "Seleccione la matriz para calcular la inversa:\n1. MatA\n2. MatB\n";
                int matrizSeleccionada;
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
                            inverse(MatA3x3, det, inv);
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
                            inverse(MatB3x3, det, inv);
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
            }
            case 3:
                return;
            default:
                std::cout << "Opcion no valida." << std::endl;
        }
    }
}

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

void inverse(float matrix[3][3], float det, float inv[3][3]) {
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

void geometria() {
    std::cout << "Bloque de geometria inicializado." << std::endl;
    // Aqui se implementaran las funciones de geometria.
}

void analisis() {
    std::cout << "Bloque de analisis inicializado." << std::endl;
    // Aqui se implementaran las funciones de analisis.
}

// void prob() {
// }