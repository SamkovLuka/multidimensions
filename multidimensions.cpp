#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void task1() {
    int rows, cols, startValue;
    cout << "������ ������� �����: ";
    cin >> rows;
    cout << "������ ������� ��������: ";
    cin >> cols;
    cout << "������ �������� ��������: ";
    cin >> startValue;

    int arr[rows][cols];
    arr[0][0] = startValue;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 && j == 0) continue;
            if (j == 0)
                arr[i][j] = arr[i - 1][cols - 1] * 2;
            else
                arr[i][j] = arr[i][j - 1] * 2;
        }
    }

    cout << "�����:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void task2() {
    int rows, cols, startValue;
    cout << "������ ������� �����: ";
    cin >> rows;
    cout << "������ ������� ��������: ";
    cin >> cols;
    cout << "������ �������� ��������: ";
    cin >> startValue;

    int arr[rows][cols];
    arr[0][0] = startValue;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 && j == 0) continue;
            if (j == 0)
                arr[i][j] = arr[i - 1][cols - 1] + 1;
            else
                arr[i][j] = arr[i][j - 1] + 1;
        }
    }

    cout << "�����:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void printArray(int arr[][6], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void shiftRight(int arr[][6], int rows, int cols, int shiftCount) {
    for (int k = 0; k < shiftCount; k++) {
        for (int i = 0; i < rows; i++) {
            int last = arr[i][cols - 1];
            for (int j = cols - 1; j > 0; j--) {
                arr[i][j] = arr[i][j - 1];
            }
            arr[i][0] = last;
        }
    }
}

void shiftLeft(int arr[][6], int rows, int cols, int shiftCount) {
    for (int k = 0; k < shiftCount; k++) {
        for (int i = 0; i < rows; i++) {
            int first = arr[i][0];
            for (int j = 0; j < cols - 1; j++) {
                arr[i][j] = arr[i][j + 1];
            }
            arr[i][cols - 1] = first;
        }
    }
}

void shiftUp(int arr[][6], int rows, int cols, int shiftCount) {
    for (int k = 0; k < shiftCount; k++) {
        for (int j = 0; j < cols; j++) {
            int first = arr[0][j];
            for (int i = 0; i < rows - 1; i++) {
                arr[i][j] = arr[i + 1][j];
            }
            arr[rows - 1][j] = first;
        }
    }
}

void shiftDown(int arr[][6], int rows, int cols, int shiftCount) {
    for (int k = 0; k < shiftCount; k++) {
        for (int j = 0; j < cols; j++) {
            int last = arr[rows - 1][j];
            for (int i = rows - 1; i > 0; i--) {
                arr[i][j] = arr[i - 1][j];
            }
            arr[0][j] = last;
        }
    }
}

void task3() {
    srand(time(0));

    const int rows = 2;
    const int cols = 6;
    int arr[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 10;
        }
    }

    cout << "���������� �����: \n";
    printArray(arr, rows, cols);

    int shiftCount;
    char direction;
    cout << "������ ������� �������: ";
    cin >> shiftCount;
    cout << "������ �������� (L - ����, R - ������, U - �����, D - ����): ";
    cin >> direction;

    switch (direction) {
    case 'L':
        shiftLeft(arr, rows, cols, shiftCount);
        break;
    case 'R':
        shiftRight(arr, rows, cols, shiftCount);
        break;
    case 'U':
        shiftUp(arr, rows, cols, shiftCount);
        break;
    case 'D':
        shiftDown(arr, rows, cols, shiftCount);
        break;
    default:
        cout << "������������ ��������" << endl;
        return;
    }

    cout << "����� ���� ��������:\n";
    printArray(arr, rows, cols);
}

int main() {
    int choice;
    while (true) {
        cout << "\n������ ��������:\n";
        cout << "1. ����� � ���������� �� �������� �� 2\n";
        cout << "2. ����� � ���������� �� 1\n";
        cout << "3. ������� �������� ������\n";
        cout << "0. �����\n";
        cin >> choice;

        switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 0: return 0;
        default: cout << "wrong choice, try again\n"; break;
        }
    }
    return 0;
}
