#include <QCoreApplication>

#include <iostream>

#include "jordanelmannet.h"

using namespace std;

void main(){

    JordanElmanNet net;
    net.StartLearning();
    net.GeneratePredictedSequence();
    return;
}
