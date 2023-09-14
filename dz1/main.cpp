
#include <iostream>
#include <cmath>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;


void dz1_1()
{
    // Задание «Имя»

    cout<<"Evgeniy";

}


void dz1_2()
{
    
    // Задание «Арифметика»

    double a, b;
    cout<<"Введите число \n";
    cin >> a;
    cout<<"Введите число \n";
    cin >> b;
    cout << "Сумма: " << a+b << "\n";
    cout << "Разность: " << a-b << "\n";
    cout << "Произведение: " << a*b << "\n";
    if (b != 0) { cout << "Частное от деления: " << a/b << "\n";} else { cout << "На 0 делить нельзя :(";}
//    abs(a)/abs(b)*(a/a)*(b/b)

}

void dz1_3()
{
    
    // Задание «Уравнение»

    double b, c;
    cout<<"Введите число \n";
    cin >> b;
    cout<<"Введите число \n";
    cin >> c;
    if (b == 0 && c == 0) {cout << "x = Любое";} else if (b == 0 && c != 0) {cout << "x = Нет решений";} else if (b != 0 && c == 0) {cout << "x = 0";} else {cout << "x = " << -1*(c/b);}


}

void dz1_4()
{
    
    // Задание «Еще уравнение»


    double a,b,c,d,x1,x2;
 
    cout << "Введите a\n";
    cin >> a;
    cout << "Введите b\n";
    cin >> b;
    cout << "Введите c\n";
    cin >> c;
     
    d = b * b - 4 * a * c;
    if (a != 0) {
        if (d > 0)
        {
            x1 = ((-b) + sqrt(d)) / (2 * a);
            x2 = ((-b) - sqrt(d)) / (2 * a);
            cout << "x1 = " << x1 << "\n";
            cout << "x2 = " << x2 << "\n";
        }
        if (d == 0)
        {
            x1 = -(b / (2 * a));
            cout << "x1 = x2 = " << x1 << "\n";
        }
        if (d < 0)
            cout << "D < 0, Нет корней";
    }
      if (a == 0) {
          if (b == 0 && c == 0)
          {
              cout << "x = Любое";
              
          } else if (b == 0 && c != 0)
          
          {
              cout << "x = Нет решений";
              
          } else if (b != 0 && c == 0)
          
          {
              cout << "x = 0";
              
          } else {
              cout << "x = " << -1*(c/b);
              
          }
      }
    cout << '\n';

}
void dz1_5()
{
    // Задание «Лампа со шторой»

    string ans;
    bool morning, shtor, lamp;

    cout << "y - если да \n";
    cout << "n - если нет \n";
    cout << "------------------- \n";


    cout << "На улице день? \n";
    cin >> ans;
    if (ans == "y") {
        morning = true;
    } else {
        morning = false;
    }
    cout << "Шторы раздвинуты? \n";
    cin >> ans;
    if (ans == "y") {
        shtor = true;
    } else {
        shtor = false;
    }
    cout << "Лампа включена? \n";
    cin >> ans;
    if (ans == "y") {
        lamp = true;
    } else {
        lamp = false;
    }
    cout << ((lamp || (morning && shtor)) ? "Cветло \n" : "Темно\n");

    
    
}

int main()
{
    
    dz1_1();

    return 0;
}









