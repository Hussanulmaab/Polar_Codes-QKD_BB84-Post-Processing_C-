#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include "Alice_Encryption-Polar.h"
using namespace std;

int main() {
    int k, N;
    cout << "Enter the Value of k :: ";
    cin >> k;
    cout << "Enter the Value of N :: ";
    cin >> N;
        
    PC_Alice_Enc_func(k, N);

    return 0;
}

