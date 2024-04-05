    #pragma once
#include <iostream>
#include <cmath>
#include "Tensor_Calculator.h"
using namespace std;

int* Tensor_Calculator(int N) {
    int i, j, tensor_loop;
    const int base = 2;
    int n = log2(N);

    // Base Matrix i => column, j => row
    cout << "BASE MATRIX" << endl;
    int base_Mat[2][2] = { {1, 0}, {1, 1} };
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            cout << base_Mat[i][j] << " ";
        }
        cout << endl;
    }
    // tensors
    int* prev_tensor_Ptr = NULL;
    int* new_tensor_Ptr = NULL;
    prev_tensor_Ptr = new int[base * base];

    // previous tensor pointer matrix
    for (i = 0; i < 2;i++) {
        for (j = 0; j < 2; j++) {
            *(prev_tensor_Ptr + (base * i) + j) = base_Mat[i][j];
        }
    }

    int count1, count2, count3, count4;
    // new tensor pointer matrices
    for (tensor_loop = 2; tensor_loop < N; tensor_loop *= 2) {
        new_tensor_Ptr = new int[(tensor_loop * 2) * (tensor_loop * 2)];

        count1 = count2 = count3 = count4 = 0;

        for (i = 0; i < tensor_loop * 2; i++) {
            for (j = 0; j < tensor_loop * 2; j++) {

                if (i < tensor_loop) {
                    if (j < tensor_loop) {
                        *(new_tensor_Ptr + ((tensor_loop * 2) * i) + j) = *(prev_tensor_Ptr + count1);
                        count1++;
                    }
                    if (j >= tensor_loop) {
                        *(new_tensor_Ptr + ((tensor_loop * 2) * i) + j) = 0;
                        count2++;
                    }
                }

                else if (i >= tensor_loop) {
                    if (j < tensor_loop) {
                        *(new_tensor_Ptr + ((tensor_loop * 2) * i) + j) = *(prev_tensor_Ptr + count3);
                        count3++;
                    }
                    if (j >= tensor_loop) {
                        *(new_tensor_Ptr + ((tensor_loop * 2) * i) + j) = *(prev_tensor_Ptr + count4);
                        count4++;
                    }
                }
            }
        }

        prev_tensor_Ptr = new_tensor_Ptr;
    }

    return new_tensor_Ptr;
}
