
#include <iostream>
#include <cmath>
#include <numbers> // std::numbers
#include <fstream>
#include <cstring>
#include <cctype>
#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>
#include <string>
#include <stdio.h>
#include <set>
#include <map>
#include <vector>

#define _USE_MATH_DEFINES

#include <string>
#include <stdio.h>
#include <set>
#include <map>
#include <vector>

using namespace std;


void dz4_1()
{
    // Задача «Файл»

    string strin;
    cout << "Введите десять цифр через пробел" << endl;
    getline(cin, strin);
    ofstream File("/Users/evgin/vsc/dz/dz/file.txt");
    File << strin;
    File.close();
    ifstream file("/Users/evgin/vsc/dz/dz/file.txt");
    int b;
    int counter = 0;
    int fl = 0;
    do
    {
        if (file >> b)
        {
            counter += b;
            fl++;
        }
        else
        {
            file.clear();
            file.ignore(1, ' ');
        }
    } while (!file.eof());

    cout << counter << endl;
    file.close();
    if (fl == 0) {
        cout << "Цифр нет" << endl;
    }

}

int sign(double i)
{
    if (i > 0)
    {
        return 1;
    }
    if (i == 0)
    {
        return 0;
    }
    return -1;
}



void dz4_2()
{

    // Задача «Знак числа»


    double a;
    cout << "Введите число" << endl;
    cin >> a;
    cout << sign(a) << endl;

}

void rect()
{
    double a, b;
    cout << "Прямоугольник" << endl;
    cout << "Длина:" << endl;
    cin >> a;
    cout << "Ширина:" << endl;
    cin >> b;
    cout << a * b << endl;

}

void triang()
{
    double a, b, c;
    cout << "Треугольник" << endl;
    cout << "Основание 1:" << endl;
    cin >> a;
    cout << "Высота:" << endl;
    cin >> b;
    cout << "Основание 2:" << endl;
    cin >> c;
    double p = (a + b + c) / 2;
    if (a >= b + c || b >= a + c || c >= a + b)
    {
        cout << "Нельзя так!" << endl;
    }
    cout << sqrt(p * (p - a) * (p - b) * (p - c)) << endl;
}

void circl()
{
    double r;
    cout << "Круг" << endl;
    cout << "Радиус:" << endl;
    cin >> r;
    cout << M_PI * r * r << endl;
}



void dz4_3()
{

    // Задача «Геометрические фигуры»


    int a;
    cout << "Введите 1 если хотите найти площадь прямоугольника" << endl;
    cout << "Введите 2 если хотите найти площадь треугольника" << endl;
    cout << "Введите 3 если хотите найти площадь круга" << endl;
    cin >> a;
    if (a == 1)
    {
        rect();
    }
    else
    {
        if (a == 2)
        {
            triang();
        }
        else
        {
            if (a == 3)
            {
                circl();
            }
            else
            {
                cout << "Ошибка" << endl;
            }
        }
    }

}

void dz4_4() {

    // Задача «Былая слава»

    int s = 8;
   int f = 60;
   for (int i = 0; i < 6; i++)
   {
       int c = i % 2;
       for (int j = 0; j < s; j++)
       {
           cout << "* ";
       }
       if (c == 0)
       {
           for (int k = 0; k < f - s * 2; k++)
           {
               cout << '_';
           }
       }
       else
       {
           for (int k = 0; k < f - s * 2; k++)
           {
               cout << ' ';
           }
       }
       cout << endl;
   }
   for (int i = 0; i < 7; i++)
   {
       int c = i % 2;
       if (c == 0)
       {
           for (int k = 0; k < f; k++)
           {
               cout << '_';
           }
       }
       else
       {
           for (int k = 0; k < f; k++)
           {
               cout << ' ';
           }
       }
       cout << endl;
   }

}




void dz4_5() {

    // Задача «Синусоида»

    string plot[29][161] = { "-" };
    int centery = 14;
    int centerx = 80;
    for (int i = 0; i < 29; i++) {
        for (int j = 0; j < 161; j++) {
            plot[i][j] = " ";
        }
    }

    int y = 0;
    int scale = 10;
    int posx = 0, posy = 0;
    for (float x = -8; x < 0; x += 0.1) {
        y = round(sin(x) * (scale + 4));
        posx = centerx + x * scale;
        posy = centery + y;
        plot[posy][posx] = "*";
    }

    for (int i = 0; i < 29; i++) {
        for (int j = 0; j < 161; j++) {
            cout << plot[i][j];
        }
        cout << endl;
    }
}


void dz4_6() {

    // Задача «Автоматный распознаватель»


    map<char, int> c;
    c['I'] = 1;
    c['V'] = 5;
    c['X'] = 10;
    c['L'] = 50;
    c['C'] = 100;
    c['D'] = 500;
    c['M'] = 1000;
    string s;
    int d = 0;
    int    k = 0;
    while (true) {
        cout << "Введите число: "s << endl;
        cin >> s;
        int i = 0;
        bool flag = false;
        while (i < s.size()) {
            k += c[s[i]];
            if (c[s[i]] == 0)
            {
                cout << "Ошибка ввода данных" << endl;
                flag = true;
                break;
            }
            while (i < s.size() && c[s[i + 1]] == c[s[i]]) {
                k += c[s[i]];
                i++;
            }
            if (i < s.size() && c[s[i + 1]] > c[s[i]]) {
                d -= k;
            }
            else {
                d += k;
            }
            cout << k << endl;
            cout << d << endl;
            i++;
            k = 0;
        }
        if (!flag)
        {
            cout << d << endl;
        }
        d = 0;
    }


}


double nedorand(int m, int b, int c, int rand)
{
    rand = (m * rand + b) % c;
    return rand;

}


void dz4_7() {

    // Задача «Генератор случайных чисел»

    int m, b, c;
    cout << "Введите m" << endl;
    cin >> m;
    cout << "Введите i" << endl;
    cin >> b;
    cout << "Введите c" << endl;
    cin >> c;

    cout << nedorand(m, b, c, 0) << endl;
}

void dz4_8() {

    // Задача «Умножение матриц»

    string check;
    cout << "Хотите использовать готовые матрицы?" << endl;
    cin >> check;

    double A[3][4];
    double B[4][2];
    double C[3][2];


    if (check == "1") {
        cout << "Использую готовые матрицы" << endl;
        cout << "A = " << endl;

        A[0][0] = 5;
        A[0][1] = 2;
        A[0][2] = 0;
        A[0][3] = 10;
        A[1][0] = 3;
        A[1][1] = 5;
        A[1][2] = 2;
        A[1][3] = 5;
        A[2][0] = 20;
        A[2][1] = 0;
        A[2][2] = 0;
        A[2][3] = 0;

        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 4; ++j){
                cout << A[i][j] << "\t";
            }
            cout << endl;
        }

        B[0][0] = 1.20;
        B[0][1] = 0.50;
        B[1][0] = 2.80;
        B[1][1] = 0.40;
        B[2][0] = 5.00;
        B[2][1] = 1.00;
        B[3][0] = 2.00;
        B[3][1] = 1.50;

        cout << endl;

        cout << "B = " << endl;

        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 2; ++j){
                cout << B[i][j] << "\t";
            }
            cout << endl;
        }



    } else {
        cout << "Введите требуемые матрицы" << endl;

        cout << "A = " << endl;

        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 4; ++j){
                cin >> A[i][j];
            }
        }

        cout << "B = " << endl;

        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 2; ++j){
                B[i][j] = 0;
            }
        }


        cout << "A = " << endl;

        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 4; ++j){
                cout << A[i][j] << " ";
            }
            cout << endl;
        }

        cout << "B = " << endl;

        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 2; ++j){
                cout << B[i][j] << " ";
            }
            cout << endl;
        }


    }


    cout << endl;

    cout << "----------------------------------------------------" << endl << endl;

    cout << endl;
    cout << "Ответ" << endl;
    cout << endl;


    cout << "C = A * B" << endl << endl;
    cout << "C = " << endl;



    for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                C[i][j] = A[i][0] * B[0][j] + A[i][1] * B[1][j] + A[i][2] * B[2][j] + A[i][3] * B[3][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << (C[i][j]);
                cout << " ";
            }
            cout << "" << endl;
        }
        cout << " " << endl;
//        cout << C[1][1] << endl;
//        cout << C[1][0] << endl;

        cout << "Больше всего денег получил продавец ";
        if (C[0][0] > C[1][0] && C[0][0] > C[2][0])
        {
            cout << 1 << endl;
        }
        else
        {
            if (C[1][0] > C[0][0] && C[1][0] > C[2][0])
            {
                cout << 2 << endl;
            }
            else
            {
                cout << 3 << endl;
            }
        }


        cout << "Меньше всего денег получил продавец ";
        if (C[0][0] < C[1][0] && C[0][0] < C[2][0])
        {
            cout << 1 << endl;
        }
        else
        {
            if (C[1][0] < C[0][0] && C[1][0] < C[2][0])
            {
                cout << 2 << endl;
            }
            else
            {
                cout << 3 << endl;
            }
        }

        cout << "Больше всего комиссионных получил продавец ";
        if (C[0][1] > C[1][1] && C[0][1] > C[2][1])
        {
            cout << 1 << endl;
        }
        else
        {
            if (C[1][1] > C[0][1] && C[1][1] > C[2][1])
            {
                cout << 2 << endl;
            }
            else
            {
                cout << 3 << endl;
            }
        }


        cout << "Меньше всего комиссионных получил продавец ";
        if (C[1][0] < C[1][1] && C[1][0] < C[1][2])
        {
            cout << 1 << endl;
        }
        else
        {
            if (C[1][1] < C[0][1] && C[1][1] < C[2][1])
            {
                cout << 2 << endl;
            }
            else
            {
                cout << 3 << endl;
            }
        }

        cout << "общая сумма денег, вырученных за проданные товары равна ";
        cout << C[0][0] + C[1][0] + C[2][0] << endl;

        cout << "всего продавцы получили комиссионных ";
        cout << C[0][1] + C[1][1] + C[2][1] << endl;

        cout << "общая сумма денег, прошедших через руки продавцов ";
        cout << C[0][0] + C[1][0] + C[2][0] + C[0][1] + C[1][1] + C[2][1] << endl;


}

int r(char rs)
{
    switch (rs)
    {
        case 'I': return 1;
            break;
        case 'V': return 5;
            break;
        case 'X': return 10;
            break;
        case 'L': return 50;
            break;
        case 'C': return 100;
            break;
        case 'D': return 500;
            break;
        case 'M': return 1000;
            break;
        default: return 0;
            break;
    }
}


int rim()
{
    string x = "";
    cout << "Введите число: " << endl;
    cin >> x;

    for (int i = 0; i < x.size(); i++)
        if (r(x[i]) == 0) {
            cout << "error" << endl;
            return 1;
        }

    int num = 0;
    int last = r(x[0]);
    int counter = 1;

    for (int i = 1; i < x.size(); i++) {
        if (counter > 2) {
            cout << "error" << endl;
            return 2;
        }

        int line = r(x[i]);

        if (last == line)
            counter++;

        if (last < line)
            num -= (last * counter);

        if (last > line)
            num += (last * counter);

        if (last != line)
            counter = 1;

        last = line;
    }

    if (last == r(x[x.size() - 1])) {
        num += r(x[x.size() - 1]) * counter;
    }

    cout << num << endl;
    return 0;
}

void toRim(int digital_number) {
    char rom[]   = { 'I','V','X','L', 'C', 'D', 'M' };
    int  value[] = {  1,  5,  10,  50,  100, 500, 1000 };

    int array_size = sizeof(rom)/sizeof(rom[0]);
    string rom_number;

    for ( int i = array_size; i >= 0 ; --i)
        while ( digital_number >= value )
        {
            if ( (digital_number >= value*4) && (i!= array_size) )
            {
                digital_number -= value*4;
                rom_number += rom;
                rom_number += rom[i+1];
            }
            else
            {
                digital_number -= value;
                rom_number += rom;
            }
        };
    return rom_number;
}

int digit(char x) { // римские числа в арабские
  switch (x) {
  case 'I': return 1;
  case 'V': return 5;
  case 'X': return 10;
  case 'L': return 50;
  case 'C': return 100;
  case 'D': return 500;
  case 'M': return 1000;
  }
  return -1;
}

int convert(string x) {
  int i;
  int j = 0;
  int result = 0;
  int lenX = x.length() - 1;

  for (i = lenX; i >= 0; i--) {
    if (digit(x[i]) >= j)
      result += digit(x[i]);
    else
      result -= digit(x[i]);
    j = digit(x[i]);
  }
  return result;
}

void dz4_6()
{
  string x;
  cout << "Number = ";
  cin >> x;
  cout << convert(x) << endl;
}



void dz4_6() {


    string num;
    int n;
    string new_num;
    int decode = 0;

    cout << "Введите римское число" << endl;
    cin >> num;
    if (num.substr(0, 2) == "IX" && num.size() == 2){
        decode += 9;
    } else if (num.substr(0, 2) == "IX" && num.size() != 2) {
        cout << "Wrong!" << endl;
    }
        else if (num.substr(0, 2) == "IV" && num.size() == 2){
        decode += 4;
    }   else if (num.substr(0, 2) == "IV" && num.size() != 2){
        cout << "Wrong!" << endl;
    }
    else {
        int pred_num = 1001;
        for (int i = 0; i != num.size(); ++i) {
            switch (num[i])
            {
                case 'I':
                    n = 1;
                    break;
                case 'V':
                    n = 5;
                    break;
                case 'X':
                    n = 10;
                    break;
                case 'L':
                    n = 50;
                    break;
                case 'C':
                    n = 100;
                    break;
                case 'D':
                    n = 500;
                    break;
                case 'M':
                    n = 1000;
                    break;
                    
                default:
                    break;
            }
            if (n > pred_num){
                cout << "wrong" << endl;
            } else {
                decode += n;
                pred_num = n;
            }
            
        }
    }
    cout << decode << endl;

}






int str_to_int(char s)
{
    switch (s)
    {
    case '0': return 0;
        break;
    case '1': return 1;
        break;
    case '2': return 2;
        break;
    case '3': return 3;
        break;
    case '4': return 4;
        break;
    case '5': return 5;
        break;
    case '6': return 6;
        break;
    case '7': return 7;
        break;
    case '8': return 8;
        break;
    case '9': return 9;
        break;
    case 'A': return 10;
        break;
    case 'B': return 11;
        break;
    case 'C': return 12;
        break;
    case 'D': return 13;
        break;
    case 'E': return 14;
        break;
    case 'F': return 15;
        break;
        default: return 0;
            break;
    }
}
string perevod_int_to_string(char n)
{
    switch (n)
    {
    case 0: return "0";
        break;
    case 1: return "1";
        break;
    case 2: return "2";
        break;
    case 3: return "3";
        break;
    case 4: return "4";
        break;
    case 5: return "5";
        break;
    case 6: return "6";
        break;
    case 7: return "7";
        break;
    case 8: return "8";
        break;
    case 9: return "9";
        break;
    case 10: return "A";
        break;
    case 11: return "B";
        break;
    case 12: return "C";
        break;
    case 13: return "D";
        break;
    case 14: return "E";
        break;
    case 15: return "F";
        break;
        default: return 0;
            break;
    }
}
int perevod_n_to_10(string n, int osn)
{
    int sm = 0;
    reverse(n.begin(), n.end());
    for (int i = 0; i != n.length(); i++)
    {
        sm += str_to_int(n[i]) * pow(osn,i);
    }
    return sm;
}
string perevod_10_to_n(int sm, int osn)
{
    string s = "";
    string s1;
    string strsm = to_string(sm);
    while (sm > 0)
    {
        s += perevod_int_to_string(sm % osn);
        sm = sm / osn;

    }
    reverse(s.begin(), s.end());
    return s;
    
}
void dz4_9() {

    setlocale (LC_ALL, "Rus");
    int num;
    cout << "Введите число" << endl;
    string n;
    cin >> n;
    cout << "Введите СС" << endl;
    int osn;
    cin >> osn;
    num = perevod_n_to_10(n, osn);
    cout << "Ваше число в десятичной сс" << endl;
    cout << num << endl << endl;

    cout << "Введите систему в которую мы его переводим" << endl;
    int osn2;
    cin >> osn2;
    string res = perevod_10_to_n(num, osn2);
    cout << res << endl;
}


int main()
{
    setlocale (LC_ALL, "Rus");
    dz4_6();

    return 0;
}



