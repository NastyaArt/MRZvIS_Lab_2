/**
 *    Автор: Анастасия Артемчук
 */

#ifndef JORDANELMANNET_H
#define JORDANELMANNET_H
#include <iostream>
#include <armadillo>
/**
 *    Armadillo - библиотека линейной алгебры
 *    Авторы: Dr Ryan Curtin
 *            Dr Conrad Sanderson
 */
using namespace std;
using namespace arma;

class JordanElmanNet
{
public:
    JordanElmanNet();
    void StartLearning();

private:
    vector<double> sequence;    //последовательность
    int k; //размерность обучаемой последовательности
    int p;  //количество рядов в матрице обучения - размер окна
    int l;  //количество строк в матрице обучения - количество образов
    double e; //максимально допустимая ошибка
    double alfa; //коэффициент альфа
    int N; //количество шагов обучения
    int r; //размер выходной последовательности

    mat X;  //матрица обучения p x l
    mat W;  //матрица весов W на первом слое k x l
    mat Y;  //выходные значения на первом слое
    mat W_; //матрица весов W_ на втором слое l x 1
    mat Y_; //выходные значения на втором слое 1 х 1

    void inputParameters();
    void outputParameters();
    void PrintSequence();
    void CreateMatrixes();
    vector<double> CalcFibonacciSeries(int num);
    vector<double> CalcFactorialFunction(int num);
    vector<double> CalcPeriodicFunction(int num);
    vector<double> CalcPowerFunction(int num);
    vector<double> CalcSequenceOfNaturalNumbers(int num);
};

#endif // JORDANELMANNET_H
