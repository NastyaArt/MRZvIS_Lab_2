#include "jordanelmannet.h"

JordanElmanNet::JordanElmanNet()
{
    Create();
}

void JordanElmanNet::Create()
{
    //выбор ряда
    int key;

    cout << "Choose sequence: \n"
            << "1. Fibonacci series: \n0,1,1,2,3,5,8,13,21,34,55,89,144,...\n"
            << "2. Factorial function: \n1,2,6,24,120,720,5040,40320,...\n"
            << "3. Periodic function: \n1,0,-1,0,1,0,-1,...\n"
            << "4. Power function(x^2): \n1,4,9,16,25,36,49,64,81,...\n"
            << "5. Sequence of natural numbers: \n1,2,3,4,5,6,7,8,...\n"
            << "6. Enter sequence\n";

    cin >> key;
    switch (key) {
        case 1:{
            int num;
            cout << "Input number of elements: (2<=n<=15)\n";
            cin >> num;
            if (num < 2 || num >15){
                cout << "Invalid parameters!";
                        return;
            }
            sequence = CalcFibonacciSeries(num);
            PrintSequence();
            break;
        }
        case 2:{
            int num;
            cout << "Input number of elements: (2<=n<=15)\n";
            cin >> num;
            if (num < 2 || num >15){
                cout << "Invalid parameters!";
                        return;
            }
            sequence = CalcFactorialFunction(num);
            PrintSequence();
            break;
        }
        case 3:{
            int num;
            cout << "Input number of elements: (2<=n<=15)\n";
            cin >> num;
            if (num < 2 || num >15){
                cout << "Invalid parameters!";
                        return;
            }
            sequence = CalcPeriodicFunction(num);
            PrintSequence();
            break;
        }
        case 4:{
            int num;
            cout << "Input number of elements: (2<=n<=15)\n";
            cin >> num;
            if (num < 2 || num >15){
                cout << "Invalid parameters!";
                        return;
            }
            sequence = CalcPowerFunction(num);
            PrintSequence();
            break;
        }
        case 5:{
            int num;
            cout << "Input number of elements: (2<=n<=15)\n";
            cin >> num;
            if (num < 2 || num >15){
                cout << "Invalid parameters!";
                        return;
            }
            sequence = CalcSequenceOfNaturalNumbers(num);
            PrintSequence();
            break;
        }
        case 6:{
            int num;
            cout << "Input number of elements: (2<=n<=15)\n";
            cin >> num;
            if (num < 2 || num >15){
                cout << "Invalid parameters!";
                        return;
            }
            sequence.clear();
            double x;
            cout << "Input elements: \n";
            for (int i = 0; i < num; i++)
            {
                cin >> x;
                sequence.push_back(x);
            }
            PrintSequence();
            break;
        }
        default:{
            printf("Error\n");
            return;
        }
    }
    //ввод параметров
    //создание сети исходя из вышеперечисленного

}

void JordanElmanNet::inputParameters()
{

}

void JordanElmanNet::PrintSequence()
{
    cout << "Learning sequence: \n";
    for (int i = 0; i < num; i++)
    {
        cout << sequence[i];
        if (i < num-1)
            cout << ", ";
    }
}

vector<double> JordanElmanNet::CalcFibonacciSeries(int num)
{
    vector<double> seq;

    seq.push_back(0);
    seq.push_back(1);
    for (int i = 1; i < num; i++)
    {
        seq.push_back(seq[i] + seq[i - 1]);
    }

    return seq;
}

vector<double> JordanElmanNet::CalcFactorialFunction(int num)
{
    vector<double> seq;
    double x = 1;

    for (int i = 1; i <= num; i++){
        for (int j = 1; j <= i; j++)
            x *= j;
        seq.push_back(x);
        x = 1;
    }

    return seq;
}

vector<double> JordanElmanNet::CalcPeriodicFunction(int num)
{
    vector<double> seq;

    for (int i = 0; i < num; i++)
    {
        switch (i % 4){
            case 0: {
                seq.push_back(1);
                break;
            }
            case 1: {
                seq.push_back(0);
                break;
            }
            case 2: {
                seq.push_back(-1);
                break;
            }
            case 3: {
                seq.push_back(0);
                break;
            }
        }
    }

    return seq;
}

vector<double> JordanElmanNet::CalcPowerFunction(int num)
{
    vector<double> seq;

    for (int i = 1; i <= num; i++)
    {
        seq.push_back(pow(i, 2));
    }

    return seq;
}

vector<double> JordanElmanNet::CalcSequenceOfNaturalNumbers(int num)
{
    vector<double> seq;

    for (int i = 1; i <= num; i++)
    {
        seq.push_back(i);
    }

    return seq;
}

void JordanElmanNet::start()
{

}
