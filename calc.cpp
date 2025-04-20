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

    float MATA2x2[2][2] = {0}, MATB2x2[2][2] = {0};
    float MATA3x3[3][3] = {0}, MATB3x3[3][3] = {0};
    int sizeMATA = 0, sizeMATB = 0;

    // Input for MATA
    std::cout << "Seleccione el tamano de MATA: \n1. 2x2 \n2. 3x3" << std::endl;
    std::cin >> sizeMATA;

    if (sizeMATA == 1) {
        std::cout << "Introduce los valores para MATA (2x2):" << std::endl;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                std::cout << "MATA[" << i << "][" << j << "] = ";
                std::cin >> MATA2x2[i][j];
            }
        }
    } else if (sizeMATA == 2) {
        std::cout << "Introduce los valores para MATA (3x3):" << std::endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << "MATA[" << i << "][" << j << "] = ";
                std::cin >> MATA3x3[i][j];
            }
        }
    } else {
        std::cout << "Tamano no valido para MATA.\n";
        return;
    }

    // Input for MATB
    std::cout << "Seleccione el tamano de MATB: \n1. 2x2 \n2. 3x3" << std::endl;
    std::cin >> sizeMATB;

    if (sizeMATB == 1) {
        std::cout << "Introduce los valores para MATB (2x2):" << std::endl;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                std::cout << "MATB[" << i << "][" << j << "] = ";
                std::cin >> MATB2x2[i][j];
            }
        }
    } else if (sizeMATB == 2) {
        std::cout << "Introduce los valores para MATB (3x3):" << std::endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << "MATB[" << i << "][" << j << "] = ";
                std::cin >> MATB3x3[i][j];
            }
        }
    } else {
        std::cout << "Tamano no valido para MATB.\n";
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
                std::cout << "Seleccione la matriz para calcular el determinante:\n1. MATA\n2. MATB\n";
                int matrizSeleccionada;
                std::cin >> matrizSeleccionada;

                if (matrizSeleccionada == 1) {
                    if (sizeMATA == 1) {
                        std::cout << "Determinante de MATA (2x2): " << determinant2x2(MATA2x2) << std::endl;
                    } else if (sizeMATA == 2) {
                        std::cout << "Determinante de MATA (3x3): " << determinant3x3(MATA3x3) << std::endl;
                    }
                } else if (matrizSeleccionada == 2) {
                    if (sizeMATB == 1) {
                        std::cout << "Determinante de MATB (2x2): " << determinant2x2(MATB2x2) << std::endl;
                    } else if (sizeMATB == 2) {
                        std::cout << "Determinante de MATB (3x3): " << determinant3x3(MATB3x3) << std::endl;
                    }
                } else {
                    std::cout << "Opcion no valida." << std::endl;
                }
                break;
            }
            case 2: {
                std::cout << "Seleccione la matriz para calcular la inversa:\n1. MATA\n2. MATB\n";
                int matrizSeleccionada;
                std::cin >> matrizSeleccionada;

                if (matrizSeleccionada == 1) {
                    if (sizeMATA == 1) {
                        float det = determinant2x2(MATA2x2);
                        if (det == 0) {
                            std::cout << "La matriz no tiene inversa (determinante = 0)." << std::endl;
                        } else {
                            float inv[2][2];
                            inverse2x2(MATA2x2, det, inv);
                            std::cout << "Inversa de MATA (2x2):" << std::endl;
                            for (int i = 0; i < 2; i++) {
                                for (int j = 0; j < 2; j++) {
                                    std::cout << inv[i][j] << " ";
                                }
                                std::cout << std::endl;
                            }
                        }
                    } else if (sizeMATA == 2) {
                        float det = determinant3x3(MATA3x3);
                        if (det == 0) {
                            std::cout << "La matriz no tiene inversa (determinante = 0)." << std::endl;
                        } else {
                            float inv[3][3];
                            inverse(MATA3x3, det, inv);
                            std::cout << "Inversa de MATA (3x3):" << std::endl;
                            for (int i = 0; i < 3; i++) {
                                for (int j = 0; j < 3; j++) {
                                    std::cout << inv[i][j] << " ";
                                }
                                std::cout << std::endl;
                            }
                        }
                    }
                } else if (matrizSeleccionada == 2) {
                    if (sizeMATB == 1) {
                        float det = determinant2x2(MATB2x2);
                        if (det == 0) {
                            std::cout << "La matriz no tiene inversa (determinante = 0)." << std::endl;
                        } else {
                            float inv[2][2];
                            inverse2x2(MATB2x2, det, inv);
                            std::cout << "Inversa de MATB (2x2):" << std::endl;
                            for (int i = 0; i < 2; i++) {
                                for (int j = 0; j < 2; j++) {
                                    std::cout << inv[i][j] << " ";
                                }
                                std::cout << std::endl;
                            }
                        }
                    } else if (sizeMATB == 2) {
                        float det = determinant3x3(MATB3x3);
                        if (det == 0) {
                            std::cout << "La matriz no tiene inversa (determinante = 0)." << std::endl;
                        } else {
                            float inv[3][3];
                            inverse(MATB3x3, det, inv);
                            std::cout << "Inversa de MATB (3x3):" << std::endl;
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