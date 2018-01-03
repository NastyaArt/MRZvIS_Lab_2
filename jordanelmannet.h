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
    void GeneratePredictedSequence();

private:

    vector<double> sequence;    //исходная последовательность
    vector<double> resSequence;    //выходная последовательность
    int k;  //размерность обучаемой последовательности
    int p;  //количество рядов в матрице обучения - размер окна
    int m;  //количество образо или количество нейронов скрытого слоя
    double e; //максимально допустимая ошибка
    double alfa; //коэффициент альфа
    int N; //максимальное количество шагов обучения
    int r; //количество предсказываемых элементов

    vector<double> hiden;   //скрытый слой
    double output;          //выходной слой
    vector<double> context_hiden;   //контекстный слой для скрытого слоя
    double context_output;          //контекстный слой для выходного слоя
    mat X;  //матрица обучения p x L
    mat W;  //матрица весов W на скрытом слое k x L
    mat Wch_h;  //матрица весов между контекстным с предыдущими значениями скрытого и скрытым слоем
    mat W_; //матрица весов W_ на выходном слое L x 1
    mat Wco_h; //матрица весов между контекстным с предыдущим значением выходного и скрытым слоем

    void EnterInputParameters();
    void ShowInputParameters();
    bool CheckInputParameters();
    void PrintSequence();
    void CreateMatrixes();
    double ActFunc(double x);
    double DerOfActFunc(double x);
    vector<double> CalcFibonacciSeries(int num);
    vector<double> CalcFactorialFunction(int num);
    vector<double> CalcPeriodicFunction(int num);
    vector<double> CalcPowerFunction(int num);
    vector<double> CalcSequenceOfNaturalNumbers(int num);
};

#endif // JORDANELMANNET_H
