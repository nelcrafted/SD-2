#include <iostream>
#include <string>

using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

    // TODO : Menambahkan karakter ke stack
    void push(char value) {
        top++;
        stack[top] = value;
    }

    // TODO : Mengambil karakter paling atas
    char pop() {
        char value = stack[top];
        top--;
        return value;
    }

int main() {
    system("cls");

    string kata;

    cout << "Masukkan sebuah kata : ";
    cin >> kata;

    // TODO : Memasukkan setiap karakter ke stack
    for (int i = 0; i < kata.length(); i++) {
        push(kata[i]);
    }

    // TODO Mengeluarkan karakter dari stack
    while (top != -1) {
        cout << pop();
    }

    cout << endl;

    return 0;
}