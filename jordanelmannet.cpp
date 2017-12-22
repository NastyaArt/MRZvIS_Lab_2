#include "jordanelmannet.h"

JordanElmanNet::JordanElmanNet()
{
    int key;
    cout << "Choose sequence: \n"
            << "1. Fibonacci series: \n0,1,1,2,3,5,8,13,21,34,55,89,144,...\n"
            << "2. Factorial function: \n1,2,6,24,120,720,5040,40320,...\n"
            << "3. Periodic function: \n1,0,-1,0,1,0,-1,...\n"
            << "4. Power function(x^2): \n1,4,9,16,25,36,49,64,81,...\n"
            << "5. Sequence of natural numbers: \n1,2,3,4,5,6,7,8,...\n"
            << "6. Enter your own sequence\nChoose:";

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
            k = num;
            sequence = CalcFibonacciSeries(num);
            PrintSequence();
            int key;
            cout << "\nUse standart params(1) or enter your own(2)?: \n";
            cin >> key;
            if (key == 1){
                p = 2;
                alfa = 0.001;
                e = 0.1;
                N = 1000000;
                outputParameters();
            }
            else if (key == 2){
                inputParameters();
            }
            else
            {
                cout << "Invalid parameters!";
                return;
            }
            break;
        }
        case 2:{
            int num;
            cout << "Input number of elements: (2<=n<=8)\n";
            cin >> num;
            if (num < 2 || num >8){
                cout << "Invalid parameters!";
                        return;
            }
            k = num;
            sequence = CalcFactorialFunction(num);
            PrintSequence();
            int key;
            cout << "\nUse standart params(1) or enter your own(2)?: \n";
            cin >> key;
            if (key == 1){
                p = 6;
                alfa = 0.001;
                e = 0.1;
                N = 1000000;
                outputParameters();
            }
            else if (key == 2){
                inputParameters();
            }
            else
            {
                cout << "Invalid parameters!";
                return;
            }
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
            k = num;
            sequence = CalcPeriodicFunction(num);
            PrintSequence();
            int key;
            cout << "\nUse standart params(1) or enter your own(2)?: \n";
            cin >> key;
            if (key == 1){
                p = 4;
                alfa = 0.001;
                e = 0.1;
                N = 1000000;
                outputParameters();
            }
            else if (key == 2){
                inputParameters();
            }
            else
            {
                cout << "Invalid parameters!";
                return;
            }
            break;
        }
        case 4:{
            int num;
            cout << "Input number of elements: (2<=n<=8)\n";
            cin >> num;
            if (num < 2 || num >8){
                cout << "Invalid parameters!";
                        return;
            }
            k = num;
            sequence = CalcPowerFunction(num);
            PrintSequence();
            int key;
            cout << "\nUse standart params(1) or enter your own(2)?: \n";
            cin >> key;
            if (key == 1){
                p = 2;
                alfa = 0.001;
                e = 0.1;
                N = 1000000;
                outputParameters();
            }
            else if (key == 2){
                inputParameters();
            }
            else
            {
                cout << "Invalid parameters!";
                return;
            }
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
            k = num;
            sequence = CalcSequenceOfNaturalNumbers(num);
            PrintSequence();
            int key;
            cout << "\nUse standart params(1) or enter your own(2)?: \n";
            cin >> key;
            if (key == 1){
                p = 2;
                alfa = 0.001;
                e = 0.1;
                N = 1000000;
                outputParameters();
            }
            else if (key == 2){
                inputParameters();
            }
            else
            {
                cout << "Invalid parameters!";
                return;
            }
            break;
        }
        case 6:{
            int num;
            cout << "Input number of elements: (2<=n<=10)\n";
            cin >> num;
            if (num < 2 || num >10){
                cout << "Invalid parameters!";
                        return;
            }
            k = num;
            sequence.clear();
            double x;
            cout << "Input elements: \n";
            for (int i = 0; i < num; i++)
            {
                cin >> x;
                sequence.push_back(x);
            }
            PrintSequence();
            inputParameters();
            break;
        }
        default:{
            printf("Error\n");
            return;
        }
    }
    CreateMatrixes();
}

void JordanElmanNet::inputParameters()
{
    cout << "Enter window size(p) (p>=1 & p<k)\n";
    cin >> p;
    cout << "Enter max error(e) (0<е<=0.1)\n";
    cin >> e;
    cout << "Enter step learning(alfa) (0<alfa<=0.1 & alfa<=е)\n";
    cin >> alfa;
    cout << "Enter max number of learning steps(N)(1<=N<=1000000)\n";
    cin >> N;
}

void JordanElmanNet::outputParameters()
{
    cout << "Window size p = " << p << "\n";
    cout << "Max error e = " << e << "\n";
    cout << "Step learning alfa = " << alfa << "\n";
    cout << "Max number of learning steps N = " << N << "\n";
}

void JordanElmanNet::PrintSequence()
{
    cout << "Learning sequence: \n";
    for (int i = 0; i < k; i++)
    {
        cout << sequence[i];
        if (i < k - 1)
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

void JordanElmanNet::CreateMatrixes()
{


}

void JordanElmanNet::StartLearning()
{

}

void JordanElmanNet::GeneratePredictedSequence()
{
    int num;
    cout << "Input number of elements for predicting: (0<num<10)\n";
    cin >> num;
    if (num < 0 || num >10){
        cout << "Invalid parameters!";
                return;
    }
   // r=k+num;
    resSequence = sequence;

    //формирование элементов и добавление в resSequence

    cout << "Result sequence: \n";
    for (int i = 0; i < r; i++)
    {
        cout << resSequence[i];
        if (i < k - 1)
            cout << ", ";
    }
}

