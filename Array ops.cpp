/*
 * ============================================================================
 * Project Name : ARRAY OPS
 * Developer     :SAKSHAM PANDEY
 * Submitted to : PROF.AYUSHI NIGAM(HOD-CSE) 
 * Language     : C++
 * Description  : A beginner-friendly, menu-driven program to perform essential
 *                2D array operations: Transpose, 90-Degree Rotation, Spiral
 *                Traversal, Linear Search, Diagonal Sum, Matrix Sorting, and
 *                Matrix Copying using switch-case.
 * ============================================================================
 */

#include <iostream>
using namespace std;

// Maximum allowed rows and columns for fixed-size 2D arrays
const int MAX = 50;

// ============================================================================
// FUNCTION: inputMatrix
// Purpose : Takes row count, column count, and matrix elements from the user.
// ============================================================================
void inputMatrix(int mat[MAX][MAX], int &rows, int &cols) {
    cout << "\nEnter number of rows (1 to " << MAX << "): ";
    cin >> rows;
    cout << "Enter number of columns (1 to " << MAX << "): ";
    cin >> cols;

    // Validate matrix dimensions
    while (rows <= 0 || rows > MAX || cols <= 0 || cols > MAX) {
        cout << "[!] Invalid dimensions. Please enter values between 1 and " << MAX << ":\n";
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;
    }

    cout << "\nEnter the elements of the " << rows << "x" << cols << " matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
    cout << "\n[OK] Matrix entered successfully!\n";
}

// ============================================================================
// FUNCTION: displayMatrix
// Purpose : Displays the 2D array in neat row-by-column tabular format.
// ============================================================================
void displayMatrix(int mat[MAX][MAX], int rows, int cols) {
    cout << "\nCurrent Matrix (" << rows << " x " << cols << "):\n";
    cout << "-----------------------------------------\n";
    for (int i = 0; i < rows; i++) {
        cout << "| ";
        for (int j = 0; j < cols; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << "|\n";
    }
    cout << "-----------------------------------------\n";
}

// ============================================================================
// FUNCTION: transposeMatrix
// Purpose : Computes and displays the transpose of the matrix.
//           Rows become columns and columns become rows: trans[j][i] = mat[i][j].
// ============================================================================
void transposeMatrix(int mat[MAX][MAX], int rows, int cols) {
    int trans[MAX][MAX];

    // Swapping row index 'i' with column index 'j'
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            trans[j][i] = mat[i][j];
        }
    }

    cout << "\n--- TRANSPOSE OF MATRIX ---\n";
    cout << "Dimensions change from " << rows << "x" << cols << " to " << cols << "x" << rows << ":\n";
    displayMatrix(trans, cols, rows);
}

// ============================================================================
// FUNCTION: rotateMatrix90Clockwise
// Purpose : Rotates the matrix 90 degrees clockwise.
//           Formula: The element at (i, j) moves to (j, rows - 1 - i).
// ============================================================================
void rotateMatrix90Clockwise(int mat[MAX][MAX], int rows, int cols) {
    int rotated[MAX][MAX];

    // New dimensions after 90 degree rotation:
    // New rows = old cols, New cols = old rows
    int newRows = cols;
    int newCols = rows;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Row 'i' becomes Column '(rows - 1 - i)'
            rotated[j][rows - 1 - i] = mat[i][j];
        }
    }

    cout << "\n--- MATRIX AFTER 90-DEGREE CLOCKWISE ROTATION ---\n";
    displayMatrix(rotated, newRows, newCols);
}

// ============================================================================
// FUNCTION: spiralTraversal
// Purpose : Prints matrix elements in spiral order using four boundary markers:
//           top, bottom, left, and right.
// ============================================================================
void spiralTraversal(int mat[MAX][MAX], int rows, int cols) {
    cout << "\n--- SPIRAL ORDER TRAVERSAL ---\n";

    // Initialize boundary pointers
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;

    cout << "Spiral Sequence: ";

    while (top <= bottom && left <= right) {
        // Step 1: Traverse from Left to Right along the 'top' row
        for (int j = left; j <= right; j++) {
            cout << mat[top][j] << " ";
        }
        top++; // Move top boundary down

        // Step 2: Traverse from Top to Bottom along the 'right' column
        for (int i = top; i <= bottom; i++) {
            cout << mat[i][right] << " ";
        }
        right--; // Move right boundary left

        // Step 3: Traverse from Right to Left along the 'bottom' row (if valid)
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                cout << mat[bottom][j] << " ";
            }
            bottom--; // Move bottom boundary up
        }

        // Step 4: Traverse from Bottom to Top along the 'left' column (if valid)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << mat[i][left] << " ";
            }
            left++; // Move left boundary right
        }
    }
    cout << "\n";
}

// ============================================================================
// FUNCTION: searchElement
// Purpose : Performs Linear Search to find an element in the 2D array and
//           reports its row and column coordinates.
// ============================================================================
void searchElement(int mat[MAX][MAX], int rows, int cols) {
    int key;
    cout << "\nEnter the element to search: ";
    cin >> key;

    bool found = false;
    cout << "\nSearching for " << key << "...\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == key) {
                cout << "[Found] Element " << key << " exists at:\n";
                cout << "   -> Index (0-based) : Row " << i << ", Column " << j << "\n";
                cout << "   -> Position (1-based): Row " << (i + 1) << ", Column " << (j + 1) << "\n";
                found = true;
            }
        }
    }

    if (!found) {
        cout << "[Not Found] Element " << key << " does not exist in the matrix.\n";
    }
}

// ============================================================================
// FUNCTION: diagonalSum
// Purpose : Calculates Primary Diagonal and Secondary Diagonal sums.
//           Note: Diagonals are defined only for square matrices (rows == cols).
// ============================================================================
void diagonalSum(int mat[MAX][MAX], int rows, int cols) {
    cout << "\n--- DIAGONAL SUM ---\n";

    // Check if matrix is square
    if (rows != cols) {
        cout << "[!] Diagonal sum is only defined for square matrices (Rows must equal Columns).\n";
        cout << "    Current dimensions: " << rows << " x " << cols << " (Not square).\n";
        return;
    }

    int primarySum = 0;
    int secondarySum = 0;

    for (int i = 0; i < rows; i++) {
        // Primary diagonal: elements where row index equals column index (i == j)
        primarySum += mat[i][i];

        // Secondary diagonal: elements where row + col == rows - 1
        secondarySum += mat[i][rows - 1 - i];
    }

    cout << "Primary Diagonal Sum   (Top-Left to Bottom-Right) : " << primarySum << "\n";
    cout << "Secondary Diagonal Sum (Top-Right to Bottom-Left) : " << secondarySum << "\n";
    cout << "Total Sum of Both Diagonals                       : " << (primarySum + secondarySum) << "\n";
}

// ============================================================================
// FUNCTION: sortMatrix
// Purpose : Sorts all elements of the matrix in ascending order.
//           Method:
//           1. Transfer 2D elements into a 1D temporary array.
//           2. Sort the 1D array using standard Bubble Sort.
//           3. Place sorted elements back into the 2D matrix.
// ============================================================================
void sortMatrix(int mat[MAX][MAX], int rows, int cols) {
    int totalElements = rows * cols;
    int temp[MAX * MAX];
    int index = 0;

    // Step 1: Flatten 2D array into 1D array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp[index] = mat[i][j];
            index++;
        }
    }

    // Step 2: Bubble Sort on 1D array
    for (int i = 0; i < totalElements - 1; i++) {
        for (int j = 0; j < totalElements - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                // Swap adjacent elements
                int swapVar = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swapVar;
            }
        }
    }

    // Step 3: Refill sorted elements back into the 2D matrix
    index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = temp[index];
            index++;
        }
    }

    cout << "\n--- MATRIX AFTER SORTING (ASCENDING ORDER) ---\n";
    displayMatrix(mat, rows, cols);
}

// ============================================================================
// FUNCTION: copyMatrix
// Purpose : Copies the current matrix into another empty matrix and displays both.
// ============================================================================
void copyMatrix(int mat[MAX][MAX], int rows, int cols) {
    // Second (empty) matrix to hold copied elements
    int copiedMat[MAX][MAX];

    // Element-by-element copying
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            copiedMat[i][j] = mat[i][j];
        }
    }

    cout << "\n--- COPYING MATRIX INTO ANOTHER MATRIX ---\n";
    cout << "[Original Matrix]:\n";
    displayMatrix(mat, rows, cols);

    cout << "\n[New (Copied) Matrix]:\n";
    displayMatrix(copiedMat, rows, cols);

    cout << "[OK] Successfully copied all elements into the new matrix!\n";
}

// ============================================================================
// MAIN FUNCTION
// Flow:
// 1. Asks user to enter the initial matrix.
// 2. Runs a menu loop using 'do-while'.
// 3. Executes the user's selected operation using 'switch-case'.
// 4. Continues until the user selects the Exit option.
// ============================================================================
int main() {
    int mat[MAX][MAX];
    int rows = 0, cols = 0;
    int choice;

    cout << "=====================================================\n";
    cout << "  WELCOME TO 2D ARRAY OPERATIONS PROGRAM BY SAKSHAM        \n";
    cout << "=====================================================\n";

    // Step 1: Initial matrix input
    inputMatrix(mat, rows, cols);

    // Step 2: Menu loop
    do {
        cout << "\n==================== MAIN MENU ======================\n";
        cout << " 1. Display Current Matrix\n";
        cout << " 2. Transpose of Matrix\n";
        cout << " 3. Rotate Matrix (90 Degrees Clockwise)\n";
        cout << " 4. Spiral Matrix Traversal\n";
        cout << " 5. Search an Element\n";
        cout << " 6. Diagonal Sum (Square Matrix)\n";
        cout << " 7. Sort Matrix Elements\n";
        cout << " 8. Copy Matrix into Another Empty Matrix\n";
        cout << " 9. Enter a New Matrix (Reset)\n";
        cout << " 0. Exit Program\n";
        cout << "=====================================================\n";
        cout << "Enter your choice (0-9): ";
        cin >> choice;

        // Flow control based on user choice
        switch (choice) {
            case 1:
                displayMatrix(mat, rows, cols);
                break;

            case 2:
                transposeMatrix(mat, rows, cols);
                break;

            case 3:
                rotateMatrix90Clockwise(mat, rows, cols);
                break;

            case 4:
                spiralTraversal(mat, rows, cols);
                break;

            case 5:
                searchElement(mat, rows, cols);
                break;

            case 6:
                diagonalSum(mat, rows, cols);
                break;

            case 7:
                sortMatrix(mat, rows, cols);
                break;

            case 8:
                copyMatrix(mat, rows, cols);
                break;

            case 9:
                cout << "\n--- ENTERING NEW MATRIX ---\n";
                inputMatrix(mat, rows, cols);
                break;

            case 0:
                cout << "\nThank you for using this Program from Saksham! Goodbye.\n";
                break;

            default:
                cout << "\n[!] Invalid choice! Please enter a number between 0 and 9.\n";
                break;
        }

    } while (choice != 0);

    return 0;
}