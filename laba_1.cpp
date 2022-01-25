#include <iostream>
//#include <conio.h>
#include <cmath>
#include <iomanip>
//#include <windows.h>

//const long double pi = acos(-1);
const long double pi = M_PI;

using namespace std;


template <typename T>
T machin_zero(T Ek){
    while (Ek / 2 > 0){
        Ek = Ek / 2;
    }
    return Ek;
}

template <typename T>
T machin_eps(T Ek){
    while (1 + Ek > 1){
        Ek = Ek / 2;
    }
    return Ek;
}

long double exp_in_ryad(int x){
    bool poz = x > 0;
    x = poz ? x : -x;
    long k = 1;
    long double temp = 1, answer = 1;
    while (temp > 0){
        temp = temp / k * x;
        answer += temp;
        k++;
    }
    return poz ? answer : 1 / answer;
}


long double coss(long double x){
    long double temp = 1;
    long double answer = 1;
    int k = 1;
    while (abs(temp) > 0){
        temp *= (-1)*x*x / (2*k*(2*k-1));
        answer += temp;
        k+=1;
    }
    return answer;
}

long double sinn(long double x){
    long double temp = x;
    long double answer = x;
    int k = 1;
    while (abs(temp) > 0){
        temp *= (-1)*x/(2*k)*x / (2*k+1);
        answer += temp;
        k+=1;
    }
    return answer;
}

long double to_interval(long double x) {
    while (x - 2 * M_PI > 0) x -= 2*M_PI;
    while (x < 0) x += 2*M_PI;
    return x;
}

long long fact(int x){
    if(x == 1) return 1;
    return x*fact(x-1);
}

long double integral(int k, long double eps) {
    if (k == 0) return exp(-1) + eps;
    return 1 - k * integral(k - 1, eps);
}

long double integral_2(int k, long double km) {
    if (k == 10000) return km;
    return (1 - integral(k + 1, km))/ (long double)k;
}

long double da = 1e-7;
void La(int i) {
  long double proizved = 1;
  long double proizved2 = 1;
  for(int j = 1; j <= 20; j++){
      if(j != i){
          proizved *= (i - j);
      }
      proizved2 *= i;
  }
  cout << "i = " << i << ", ";
  cout << "Li = " << proizved2/proizved << ", ";
  cout << "dxi = " << proizved2/proizved * da << ", ";
  cout << "i + dxi = " << i + proizved2/proizved * da << endl;
  cout << "_____" << endl;
}

int main() {
    int n; // кол-во элементов массива X
    //setlocale(LC_ALL, "Russian");
    //SetConsoleOutputCP(CP_UTF8);
    //SetConsoleCP(CP_UTF8);
    cout << "Задание 1.1" << endl;
    cout << "Машинный ноль(float): " << machin_zero((float)1) << endl;
    cout << "Машинный ноль(double): " << machin_zero((double)1) << endl;
    cout << "Машинный ноль(long double): " << machin_zero((long double)1) << endl;
    cout << endl;
    cout << "Задание 1.2" << endl;
    cout << "Машинный эпсилон(float): " << machin_eps((float)1) << endl;
    cout << "Машинный эпсилон(double): " << machin_eps((double)1) << endl;
    cout << "Машинный эпсилон(long double): " << machin_eps((long double)1) << endl;
    cout << endl;
    cout << "Задание 2.1" << endl;
    for(int i = 0; i <= 50; i += 10){
        cout << "Мой exp(" << i << "): " << exp_in_ryad(i) << endl;
        cout << "Стандартный exp(" << i << "): " << exp(i) << endl;
        cout << "Погрешность = " << abs(exp(i) - exp_in_ryad(i)) << endl;
        cout << "_______" << endl;
    }
    cout << endl;
    cout << "Задание 2.2" << endl;
    for(int i = 0; i <= 50; i += 10){
        cout << "Мой exp(-" << i << "): " << exp_in_ryad(-i) << endl;
        cout << "Стандартный exp(-" << i << "): " << exp(-i) << endl;
        cout << "Погрешность = " << abs(exp(-i) - exp_in_ryad(-i)) << endl;
        cout << "_______" << endl;
    }
    cout << endl;
    cout << "Задание 2.3" << endl;
    for(int i = 0; i <= 50; i += 5){
        cout << "Мой sin(" << i << "): " << sinn(i) << endl;
        cout << "Мой sin(" << i << ") interval: " << sinn(to_interval(i)) << endl;
        cout << "Стандартный sin(" << i << "): " << sin(i) << endl;
        cout << "Погрешность = " << abs(sin(i) - sinn(i)) << endl;
        cout << "Погрешность в интервале = " << abs(sin(i) - sinn(to_interval(i))) << endl;
        cout << endl;
        cout << "Мой cos(" << i << "): " << coss(i) << endl;
        cout << "Мой cos(" << i << ") interval: " << coss(to_interval(i)) << endl;
        cout << "Стандартный cos(" << i << "): " << cos(i) << endl;
        cout << "Погрешность = " << abs(cos(i) - coss(i)) << endl;
        cout << "Погрешность в интервале = " << abs(cos(i) - coss(to_interval(i))) << endl;
        cout << "_______" << endl;
    }
    cout << endl;
    cout << "Задание 2.3" << endl;
    for(int i = 1; i <= 20; i ++){
        cout << "Интеграл " << i << "(eps = 0): " << integral(i, 0) << endl;
        cout << "Интеграл " << i << "(eps = 1e-7): " << integral(i, 1e-7) << endl;
        cout << "Интеграл " << i << "(eps = 1e-6): " << integral(i, 1e-6) << endl;
        cout << "Интеграл " << i << "(eps = 1e-5): " << integral(i, 1e-5) << endl;
        cout << "_______" << endl;
    }
    cout << endl;
    for(int i = 20; i >= 1; i --){
        cout << "Интеграл " << i << "(eps = 0): " << integral_2(i, 0) << endl;
        cout << "Интеграл(старый) " << i << "(eps = 0): " << integral(i, 0) << endl;
        cout << "Интеграл " << i << "(eps = 1e-2): " << integral_2(i, 1e-2) << endl;
        cout << "Интеграл " << i << "(eps = 1e-1): " << integral_2(i, 1e-1) << endl;
        cout << "Интеграл " << i << "(eps = 1-5): " << integral_2(i, 1) << endl;
        cout << "_______" << endl;
    }

    cout << "Задание 4" << endl;
    for(int i = 1; i <= 20; i++){
      La(i);
    }

    return 0;
}
