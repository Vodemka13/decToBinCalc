#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;


void printVector(vector <char> v1){
    for (int i = 0; i < 8; i++){
        cout << v1[i];
    }
}


vector <char> decToBin(vector <char> v1, int num){
    string bin = "";
    bool flag = false;

    if (num < 0){ // check if the number is negative
        num = num - num - num;
        flag = true;
    }

    if (num == 0 || num == -0){
        vector <char> res(8);
        for (int i = 0; i < 8; i++){ // kostyli
            res[i] = '0';
        }
        return res;
    }

    while (num > 1){ // converting decimal to binary STRING
        if (num % 2 == 0) bin = "0" + bin;
        else bin = "1" + bin;
        num /= 2;
    }

    bin = "1" + bin; // yeah

    int ivector = 7;

    for (int i = 0; i < 8; i++){ // filling vector with '0's
        v1[i] = '0';
    }

    for (int i = bin.length() - 1; i >= 0; i--){ // filling vector with string from end
        v1[ivector] = bin[i];
        ivector -= 1;
    }

    cout << endl;
    if (!flag) v1[0] = '0'; // sign symbol
    if (flag) v1[0] = '1';
    return v1;
}

vector <char> printBackwards(vector <char> v1){ // backward bin
    vector <char> newv(8);
    newv[0] = v1[0];
    for (int i = 1; i < 8; i++){
        if (v1[i] == '0') newv[i] = '1';
        else newv[i] = '0';
    }
    return newv;
}


vector <char> printExtra(vector <char> v1) { // extracode
    int carry = 1;
    vector <char> newv(8);
    newv[0] = v1[0];
    for (int i = 7; i > 0; i--){
        if (v1[i] == '1'){
            if (carry + 1 > 1){
                newv[i] = '0';
                carry = 1;
            }
            else{
                newv[i] = '1';
                carry = 0;
            }
        }
        else{
            if (carry == 1){
                newv[i] = '1';
                carry = 0;
            }
            else {
                newv[i] = '0';
            }
        }
    }
    return newv;
}


int main() {
    system("color F9");
    SetConsoleTitle(("Calculator"));
    setlocale(LC_ALL, "Russian");
    while (true){
        cout << endl << "Введите десятичное число:" << endl << endl;
        int num;
        cin >> num;
        if (num < -128 || num > 127) cout << endl << endl << "ЧИСЛО ВЫХОДИТ ЗА ГРАНИЦЫ ОДНОБАЙТОВОГО ПРЕДСТАВЛЕНИЯ [-128; 127]" << endl << endl;
        else {
            cout << endl << endl << "Выберите операцию:" << endl << "1 - Прямой код" << endl << "2 - Обратный код" << endl << "3 - Дополнительный код" << endl << endl;
            int operation;
            vector <char> straightBin(8);
            cin >> operation;

            if (operation == 1){
                straightBin = decToBin(straightBin, num);
                printVector(straightBin);
            }
            if (operation == 2) {
                straightBin = decToBin(straightBin, num);
                printVector(printBackwards(straightBin));
            }
            if (operation == 3) {
                straightBin = decToBin(straightBin, num);
                printVector(printExtra(printBackwards(straightBin)));
            }
        }
        bool flag = true;
        cout << endl << endl << "Для продолжения нажмите пробел";
        while (flag){
            if (GetAsyncKeyState(VK_SPACE)){
                flag = false;
                system("cls");
            }
        }
    }
    return 0;
}
