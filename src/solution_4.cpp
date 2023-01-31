#include <iostream>
#include "AverageArray.h"
using namespace std;

void solution_4() {

    cout << "\n********************** Решение №4 *********************\n";

    AverageArray<int> a1({10,2,13,45,5,16,9,18});
    cout << "\nПроверяем массив целых чисел\n";
    a1.print();
    cout << "Среднее арифметическое = " << a1.average() << endl;

    AverageArray<float> a2({10.5,2.1,13.4,45.0,5.4,1.16,2.119,5.181});
    cout << "\nПроверяем массив вещественных чисел float\n";
    a2.print();
    cout << "Среднее арифметическое = " << a2.average() << endl;

    AverageArray<double> a3({100.5,291.1,1213.4,475.0,5.454,0.656,119.2,125.18,34.567});
    cout << "\nПроверяем массив вещественных чисел double\n";
    a3.print();
    cout << "Среднее арифметическое = " << a3.average() << endl;

}