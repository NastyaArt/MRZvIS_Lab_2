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
            if (num < 2 || num > 15){
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
                m = k - p;
                alfa = 0.001;
                e = 0.1;
                N = 1000000;
                ShowInputParameters();
            }
            else if (key == 2){
                EnterInputParameters();
            }
            else
            {
                cout << "Invalid parameters!";
                return;
            }
            cout << "Input number of elements to predict: (1<=n<=10)\n";
            cin >> num;
            if (num < 1 || num > 10){
                cout << "Invalid parameters!";
                        return;
            }
            r = num;
            break;
        }
        case 2:{
            int num;
            cout << "Input number of elements: (2<=n<=8)\n";
            cin >> num;
            if (num < 2 || num > 8){
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
                m = k - p;
                alfa = 0.001;
                e = 0.1;
                N = 1000000;
                ShowInputParameters();
            }
            else if (key == 2){
                EnterInputParameters();
            }
            else
            {
                cout << "Invalid parameters!";
                return;
            }
            cout << "Input number of elements to predict: (1<=n<=10)\n";
            cin >> num;
            if (num < 1 || num > 10){
                cout << "Invalid parameters!";
                        return;
            }
            r = num;
            break;
        }
        case 3:{
            int num;
            cout << "Input number of elements: (2<=n<=15)\n";
            cin >> num;
            if (num < 2 || num > 15){
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
                m = k - p;
                alfa = 0.001;
                e = 0.1;
                N = 1000000;
                ShowInputParameters();
            }
            else if (key == 2){
                EnterInputParameters();
            }
            else
            {
                cout << "Invalid parameters!";
                return;
            }
            cout << "Input number of elements to predict: (1<=n<=10)\n";
            cin >> num;
            if (num < 1 || num > 10){
                cout << "Invalid parameters!";
                        return;
            }
            r = num;
            break;
        }
        case 4:{
            int num;
            cout << "Input number of elements: (2<=n<=8)\n";
            cin >> num;
            if (num < 2 || num > 8){
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
                m = k - p;
                alfa = 0.001;
                e = 0.1;
                N = 1000000;
                ShowInputParameters();
            }
            else if (key == 2){
                EnterInputParameters();
            }
            else
            {
                cout << "Invalid parameters!";
                return;
            }
            cout << "Input number of elements to predict: (1<=n<=10)\n";
            cin >> num;
            if (num < 1 || num > 10){
                cout << "Invalid parameters!";
                        return;
            }
            r = num;
            break;
        }
        case 5:{
            int num;
            cout << "Input number of elements: (2<=n<=15)\n";
            cin >> num;
            if (num < 2 || num > 15){
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
                m = k - p;
                alfa = 0.001;
                e = 0.1;
                N = 1000000;
                ShowInputParameters();
            }
            else if (key == 2){
                EnterInputParameters();
            }
            else
            {
                cout << "Invalid parameters!";
                return;
            }
            cout << "Input number of elements to predict: (1<=n<=10)\n";
            cin >> num;
            if (num < 1 || num > 10){
                cout << "Invalid parameters!";
                        return;
            }
            r = num;
            break;
        }
        case 6:{
            int num;
            cout << "Input number of elements: (2<=n<=10)\n";
            cin >> num;
            if (num < 2 || num > 10){
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
            EnterInputParameters();
            cout << "Input number of elements to predict: (1<=n<=10)\n";
            cin >> num;
            if (num < 1 || num > 10){
                cout << "Invalid parameters!";
                        return;
            }
            r = num;
            break;
        }
        default:{
            printf("Error\n");
            return;
        }
    }
    if (!CheckInputParameters())
        return;
    CreateMatrixes();
}

void JordanElmanNet::EnterInputParameters()
{
    cout << "Enter window size(p) (p>=1 & p<k)\n";
    cin >> p;
    m = k - p;
    cout << "Enter max error(e) (0<e<=0.1)\n";
    cin >> e;
    cout << "Enter step learning(alfa) (0<alfa<=0.1 & alfa<=e)\n";
    cin >> alfa;
    cout << "Enter max number of learning steps(N)(1<=N<=1000000)\n";
    cin >> N;
}

void JordanElmanNet::ShowInputParameters()
{
    cout << "Window size p = " << p << "\n";
    cout << "Number of images in the training sample m = " << m << "\n";
    cout << "Max error e = " << e << "\n";
    cout << "Step learning alfa = " << alfa << "\n";
    cout << "Max number of learning steps N = " << N << "\n";
}

bool JordanElmanNet::CheckInputParameters()
{
    if (p <= 0 || p >= k || e <= 0 || e > 0.1 || alfa <= 0 || alfa > 0.1 || N < 1 || N > 1000000){
        cout << "Invalid parameters!";
        return false;
    }
    return true;

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

double JordanElmanNet::ActFunc(double x)
{
    return (exp(x) - exp(-x)) / (exp(x) + exp(-x));
}

double JordanElmanNet::DerOfActFunc(double x)
{
//    return 4.0/pow((exp(x)+exp(-x)),2);
    return 1.0 - pow(x, 2);
}

void JordanElmanNet::CreateMatrixes()
{
    printf("CreateMatrixes\n");
    vec input(p);
    input.fill(0);
    this->input = input;
    vec hidden(m);
    hidden.fill(0);
    this->hidden = hidden;
    output = 0;
    vec context_hidden(p);
    context_hidden.fill(0);
    this->context_hidden = context_hidden;
    context_output = 0;

    vec T(m);
    T.fill(0);
    this->T = T;
    T_ = 0;

    mat X(m, p);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            X(i, j) = sequence[i + j];
//            cout << X(i, j) << " ";
        }
        expValues.push_back(sequence[i + p]);
//        cout << "| " << expValues[i];
//        cout << endl;
    }
    this->X = X;

/**
 * randu( n_elem )
 * Generate a vector, matrix or cube with the elements set to random floating point values
 * randu() uses a uniform distribution in the [0,1] interval
*/
    W = randu<mat>(p, m); //заполнение псевдо-случайными числами в интервале [0,1]
    W = (W * 2.0 - 1.0);  //преобразование чисел под интервал [-1,1]

    Wch_h = randu<mat>(m, m); //заполнение псевдо-случайными числами в интервале [0,1]
    Wch_h = (Wch_h * 2.0 - 1.0);  //преобразование чисел под интервал [-1,1]

    W_ = randu<mat>(m, 1); //заполнение псевдо-случайными числами в интервале [0,1]
    W_ = (W_ * 2.0 - 1.0);  //преобразование чисел под интервал [-1,1]

    Wco_h = randu<mat>(1, m); //заполнение псевдо-случайными числами в интервале [0,1]
    Wco_h = (Wco_h * 2.0 - 1.0);  //преобразование чисел под интервал [-1,1]

}

double JordanElmanNet::GetRandom()
{
    return 2.0 * ( (double)rand() / (double)RAND_MAX ) - 1.0;
}

void JordanElmanNet::StartLearning()
{
    double E;
    int iteration = 0;

    do {
        iteration++;
        E = 0.0;
        for (int i = 0; i < m; i++) {

            input = conv_to<vec>::from(X.row(i));

            DirectErrorProp();

            E += pow(output - expValues[i], 2) / 2;

            BackErrorProp(expValues[i]);

        }
        if (iteration <= 10 || iteration % 1000 == 0 )
            cout << "Iteration: " << iteration << " Error: " << E << endl;

    } while (E > e);

    cout << "Finish learning" << endl;
    cout << "Iterations = " << iteration << " \nError = " << E << endl;
    cout << "Output = " << output << endl;
}

void JordanElmanNet::DirectErrorProp()
{
    double S;

    for (int j = 0; j < m; j++) {
        S = 0.0;

        for (int i = 0; i < p; i++) {
            S += W(i, j) * input[i];
        }

        for (int i = 0; i < m; i++) {
            S += Wch_h(i, j) * context_hidden[i];
        }

        S += Wco_h(0, j) * context_output;

        // Substruct input bias	// пороговое значение ???
        S -= T(j);

        hidden[j] = ActFunc(S);
    }

    S = 0.0;

    for (int i = 0; i < m; i++) {
        S += W_(i, 0) * hidden[i];
    }

    // Substruct hidden bias	// пороговое значение ???
    S -= T_;

    output = ActFunc(S);

    // Copy hidden to context
    for (int i = 0; i < m; i++) {
        context_hidden[i] = hidden[i];
    }

    // Copy output to context
    context_output = output;

}

void JordanElmanNet::BackErrorProp(double val)
{
//    double a = 0.0001; //adaptiveStep();
    double diff = alfa * (output - val);
//    cout << output << endl;
//    cout << val << endl;
//    cout << diff << endl;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            W(j, i) -= diff * W_(i, 0) * DerOfActFunc(hidden[i]) * input[j];
        }

        for (int j = 0; j < m; j++) {
            Wch_h(j, i) -= diff * W_(i, 0) * DerOfActFunc(hidden[i]) * context_hidden[j];
        }

        W_(i, 0) -= diff * hidden[i];
        Wco_h(0, i) -= diff * W_(i, 0) * DerOfActFunc(hidden[i]) * context_output;
        T(i) = diff * W_(i, 0) * DerOfActFunc(hidden[i]);
    }

    T_ = diff;

    //normalizeWeights();
//    cout << W << endl;
//    cout << W_ << endl;
//    cout << Wch_h << endl;
//    cout << Wco_h << endl;
}

void JordanElmanNet::GeneratePredictedSequence()
{
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

