#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include "Alice_Encryption-Polar.h"
#include "Tensor_Calculator.h"
using namespace std;

string PC_Alice_Enc_func(int k, int N) {
    int i, j;
    const int base = 2;
    // small n is the underroot so that we know how much time to multiply in tensor product
    int n = log2(N);

    cout << "---------------IN ALICE ENCRYPTION FUNCTION--------------" << endl;

    // Alice Reading the Bits file
    ifstream inFile;
    inFile.open("Alice_data.txt");
    if (inFile.fail()) { cout << "Error Opening File" << endl; }
    char c;
    string sifted_data = "";
    while (inFile.get(c)) {
        sifted_data.push_back(c);
    }
    inFile.close();
    
    // Tensor Matrix
    int* tensor_Matrix_ptr = Tensor_Calculator(N);

    cout << "after kronecker " << endl;
    for (i = 0; i < N;i++) {
        for (j = 0; j < N; j++) {
            cout << *(tensor_Matrix_ptr + (N * i) + j) << " ";
        }
        cout << endl;
    }

    // Reading Relaibility sequence and storing it in array
    int frozen = N - k;

    ifstream inputFile("Relaibility_Sequence.txt"); // Assuming the file is named "numbers.txt"
    vector<int> Relaibility_Seq;
    int num;
    while (inputFile >> num) {
        Relaibility_Seq.push_back(num);
    }
    inputFile.close();

    cout << " Relaibility sequence " << endl;
    for (i = 0; i < Relaibility_Seq.size(); i++) {
        cout << Relaibility_Seq[i] << " " << endl;
    }
   
    // //Calculating U Vectors
    //string data = sifted_data; 
    //int dataSize = data.size();

    //for (int i = 0; i < dataSize / k; ++i) {
    //    string Message_block = "";
    //    string RSblock = "";
    //    for (int j = 0; j < k; ++j) {
    //        Message_block += data[k * i + j];
    //    }
    //    cout << "Block " << i << " :: " << Message_block << endl;
    //}

    return 0;
}
