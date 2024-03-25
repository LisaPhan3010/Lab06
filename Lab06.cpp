#include <iostream>
#include <fstream>

const int MAX_SIZE = 3;

// Read a matrix from a file
void read_matrix(int matrix[MAX_SIZE][MAX_SIZE], const std::string& filename, int startline) {
    std::ifstream file(filename);
    std::string line;
    if (!file) {
        std::cerr << "Error: Cannot open the file " << filename << std::endl;
        exit(1);
    }
    for (int i = 0; i < startline; i++) {
        std::getline(file, line);  // Skip lines
    }
    for (int i = 0; i < MAX_SIZE; ++i) {
        for (int j = 0; j < MAX_SIZE; ++j) {
            file >> matrix[i][j];  // Read matrix elements
        }
    }
    file.close();
}

// Print a matrix
void print_matrix(const int matrix[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Add two matrices
void add_matrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Subtract two matrices
void subtract_matrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

// Multiply two matrices
void multiply_matrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < MAX_SIZE; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

// Find and print the max value of the matrix
void get_max(const int matrix[MAX_SIZE][MAX_SIZE]) {
    int max = matrix[0][0];
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    std::cout << "Max value of the matrix: " << max << std::endl;
}

// Transpose and print the matrix
void transpose_matrix(const int matrix[MAX_SIZE][MAX_SIZE]) {
    int transpose[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    std::cout << "Transposed matrix:" << std::endl;
    print_matrix(transpose);
}

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    // Read matrix A from file
    read_matrix(matrixA, "matrix_input.txt", 1);
    std::cout << "Matrix A:" << std::endl;
    print_matrix(matrixA);

    // Read matrix B from file
    read_matrix(matrixB, "matrix_input.txt", MAX_SIZE + 1);
    std::cout << "Matrix B:" << std::endl;
    print_matrix(matrixB);

    // Add matrix A and B
    add_matrices(matrixA, matrixB, result);
    std::cout << "Matrix A + Matrix B:" << std::endl;
    print_matrix(result);

    // Subtract matrix A and B
    subtract_matrices(matrixA, matrixB, result);
    std::cout << "Matrix A - Matrix B:" << std::endl;
    print_matrix(result);

    // Multiply matrix A and B
    multiply_matrices(matrixA, matrixB, result);
    std::cout << "Matrix A * Matrix B:" << std::endl;
    print_matrix(result);

    // Get max value of the matrix A
    get_max(matrixA);

    // Transpose matrix A
    transpose_matrix(matrixA);

    return 0;
}
