
#include <iostream>
#include <cmath>
#include <numbers> // std::numbers
#include <fstream>
#include <cstring>
#include <cctype>



using namespace std;


void dz2_1()
{
    // Задача «Конус»


    double R, r, l, h, V, S;
    cout << "Введи h \n";
    cin >> h;
    cout << "Введи R \n";
    cin >> R;
    cout << "Введи r \n";
    cin >> r;

    if (h<= 0 || r <= 0 || R <= 0) {
        cout << "Нет решений \n";
        return;
    }
    l = sqrt(h*h + (R-r)*(R-r));

    V = (1/3.)* std::numbers::pi *h*(R*R+R*r+r*r);
    S = std::numbers::pi *(R*R+(R+r)*l+r*r);

    cout << "L = " << l << "\n";
    cout << "V = " << V << "\n";
    cout << "S = " << S << "\n";


}


void dz2_2()
{

    // Задача «Разветвление»


    double x, a, rez;
    cout << "Введи x \n";
    cin >> x;
    cout << "Введи a \n";
    cin >> a;


    if (abs(x) < 1 && x != 0){
        rez = a * log(abs(x));
        cout << "Ответ: " << rez << "\n";
    }
    else if (abs(x) >= 1 && a - x*x >= 0) {
        rez = sqrt(a - x*x);
        cout << "Ответ: " << rez << "\n";
    }
    else
        cout << "Нет корней";



}


void dz2_3()
{

    // Задача «Функция»


    double x, y, b, n1, n2;

    cout << "Введи x \n";
    cin >> x;
    cout << "Введи y \n";
    cin >> y;
    cout << "Введи b \n";
    cin >> b;

    n1 = b - y;
    n2 = b - x;

    if ((n1 > 0) && (n2 >= 0)) {
        cout << "z = " << log(n1) * sqrt(n2) << '\n';
    } else {
        cout << "Нет решений\n";
    }


}


void dz2_4()
{

    // Задача «Порядок»

    long long n;

    cout << "Введите N: ";
    cin >> n;

    for (int i = 1; i <= 10; i++) {
        cout << i << " - " << n++ << '\n';
    }

}

void dz2_5()
{

    // Задача «Табуляция»

    cout << "x \t y \n";

    for (float x = -4; x <= 4; x = x + 0.5) {
        cout << x << "\t";
        if (x == 1)
          cout << "Нет решений" << '\n';
        else
          cout << (x * x - 2 * x + 2) / (x - 1) << '\n';
    }

}





void dz3_1()
{
    // Задача «Заем»
    
    float m, S, p, n, r;
    
    cout << "Введите S \n";
    cin >> S;
    cout << "Введите p \n";
    cin >> p;
    cout << "Введите n \n";
    cin >> n;
    r = p/100;
    m = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
    cout << "Ответ: " << m << "\n";

    
    
}

void dz3_2()
{
    // Задача «Ссуда»
    
    float m, S, n;
    
    float rez=-1;
    
    cout << "Введите m \n";
    cin >> m;
    cout << "Введите S \n";
    cin >> S;
    cout << "Введите n \n";
    cin >> n;
    
    float left = 0, right = 100, flag;
    bool f = true;
    
    do {
        
        flag = (left+right)/2.;
        float r = flag/100;
        float k = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
        float raz = abs(k-m);
        
        if (raz < 0.001){
            rez = flag;
            f = false;
            break;
        } else if (k < m){
            left = flag+1;
        } else {
            right = flag-1;
        }
        
        
    } while (f);
    
    if (rez != -1) {
        cout << "Ответ: " << rez << "\n";
    } else {
        cout << "Нет такого" << "\n";
    }
    
}


void dz3_3()
{
    // Задача «Копирование файла»
    ifstream file("/Users/evgin/vsc/dz/dz/cppstudio.txt");
    for(string line; getline( file, line ); )
    {
        cout << line << endl;
    }
    file.close();

}

void dz3_4() {
    setlocale(LC_ALL, "Russian");
    ifstream file("/Users/evgin/vsc/dz/dz/cppstudio.txt");
    int b;
    int fl = 0;
    do
    {
        if (file >> b)
        {
            cout << b << " ";
            fl++;
        }
        else
        {
            file.clear();
            file.ignore(1, ' ');
        }
    } while (!file.eof());
    file.close();
    if (fl == 0) {
        cout << "В файле не было цифр" << endl;
    }
}

void dz3_5()
{
    
    string word = "hbshjkbdkhjvbsjkhdbbsdjbkjsbjksbBDKBdbakb";
    
    transform(word.begin(),word.end(),word.begin(),::tolower);

    sort(word.begin(), word.end());
 
    cout << word << endl;
 

}





int main()
{
    
    dz3_2();

    return 0;
}









