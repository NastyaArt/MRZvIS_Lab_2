#include <QCoreApplication>

#include <iostream>

#include "jordanelmannet.h"

using namespace std;

void main(){

    JordanElmanNet net;
    net.StartLearning();
    net.GeneratePredictedSequence();

//    int p = 2;
//    int m = 6;

//    vec input(p);

//    mat X(m, p);
//    for (int i = 0; i < m; i++)
//    {
//        for (int j = 0; j < p; j++)
//        {
//            X(i, j) = i + j + 1;
//            cout << X(i, j) << " ";
//        }
//        cout << endl;
//    }


//    input = conv_to<vec>::from(X.row(0));

//    cout << input;

    return;
}
