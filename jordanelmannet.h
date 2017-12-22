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
    void start();

private:
    vector<double> sequence;    //последовательность
    int k; //размерность обучаемой последовательности
    int p;  //количество рядов в матрице обучения
    int L;  //количество строк в матрице обучения - количество образов
    double e; //максимально допустимая ошибка
    double alfa; //коэффициент альфа
    int N; //количество шагов обучения
    int r; //размер выходной последовательности

    void Create();
    void inputParameters();
    void PrintSequence();
    vector<double> CalcFibonacciSeries(int num);
    vector<double> CalcFactorialFunction(int num);
    vector<double> CalcPeriodicFunction(int num);
    vector<double> CalcPowerFunction(int num);
    vector<double> CalcSequenceOfNaturalNumbers(int num);
};

#endif // JORDANELMANNET_H
