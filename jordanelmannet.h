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
    int p;  //количество столбцов в матрице обучения - размер окна
    int m;  //количество образов или количество нейронов скрытого слоя
    double e; //максимально допустимая ошибка
    double alfa; //коэффициент альфа
    int N; //максимальное количество шагов обучения
    int r; //количество предсказываемых элементов

    vec input;   //входной вектор (p)
    vec hidden;   //выходной вектор из скрытого слоя (m)
    double output;  //выходной вектор из выходного слоя (1)
    vec context_hidden;   //контекстный слой для скрытого слоя (m)
    double context_output;          //контекстный слой для выходного слоя (1)
    mat X;  //матрица обучения m x p
    mat W;  //матрица весов W на скрытом слое p x m
    mat Wch_h;  //матрица весов между контекстным с предыдущими значениями скрытого и скрытым слоем m x m
    mat W_; //матрица весов W_ на выходном слое m x 1
    mat Wco_h; //матрица весов между контекстным с предыдущим значением выходного и скрытым слоем 1 x m
    vec T;
    double T_;

    vector<double> expValues;   //значения, которые необходимо получить при обучении для каждого входного вектора
    void EnterInputParameters();
    void ShowInputParameters();
    bool CheckInputParameters();
    void PrintSequence();
    void CreateMatrixes();
    double GetRandom();
    double ActFunc(double x);
    double DerOfActFunc(double x);
    void DirectErrorProp();
    void BackErrorProp(double val);
    vector<double> CalcFibonacciSeries(int num);
    vector<double> CalcFactorialFunction(int num);
    vector<double> CalcPeriodicFunction(int num);
    vector<double> CalcPowerFunction(int num);
    vector<double> CalcSequenceOfNaturalNumbers(int num);
};

#endif // JORDANELMANNET_H
