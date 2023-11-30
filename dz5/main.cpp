
#include <iostream>
#include <cmath>
#include <numbers> // std::numbers
#include <fstream>
#include <cstring>
#include <cctype>
#define _USE_MATH_DEFINES
#include <sstream>

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


void dz5_1_1()
{
    // Задача «Алгоритм Евклида»

    int a, b;
    cin >> a;
    cin >> b;
    while (a != b) {
        if (a>b) {
          a = a-b;
        }
        else {
          b = b-a;
        }
    }
    cout << a;
    
    
}

void dz5_1_2() {
    int a, b;
    cin >> a;
    cin >> b;
    while (a != 0 && b != 0) {
        if (a > b) {
          a = a%b;
        }
        else {
          b = b%a;
        }
    }
    cout << a+b << endl;
    
}


void dz5_0() {
    
    // Задача «Решето Эратосфена»
    
    double n=0;
    int m=2;
    cout << "Введите n" << endl;
    cin >> n;
    int *arr = new int[n];
    
    for (int i=0; i < n; i++) {
        arr[i] = i;
    }
    
    arr[0] = 0;
    
    while (m<n) {
        if (arr[m]!=0) {
            int j = m*2;
            while (j<n) {
                arr[j]=0;
                j=j+m;
            }
        }
        m+=1;
        
    }
    
    int write = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[write++] = arr[i];
        }
    }
    
    

    n = write;
    
    for(int i = n; i > 0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = 0;
    n++;

    
    for (int i=0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;

}

void dz3_1() {
    
    // Задача №8
    
    string text;
    cout << "Enter text: ";
    cin >> text;

    for(char c : text) {
        cout << (int)c << " ";
    }
    cout << endl;

}


void dz3_2() {
    
    // Задача №16
    
    ifstream inFile("/Users/evgin/vsc/dz/dz/input.txt");
    string line;
    string word1 = "Hello";
    string word2 = "world";

    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            if(line.find(word1) != string::npos && line.find(word2) != string::npos) {
            cout << "Found in line: " << line << endl;
            }
        }
        inFile.close();
    }
    else {
    cout << "Проблема с файлом" << endl;
    }

}


void dz4_1() {
    
    // Задача №8

    
    double n;
    cout << "Введите n" << endl;
    cin >> n;
    double a;
    cout << "Введите a" << endl;
    cin >> a;
    
    cout << endl;

    double r=1;

    
    double n1 = 0;
    double n2 = 1;
    
    for (int i=0; i<n; i++){
        n1 = i+1;
        n2 *= (a+i);
        
        r *= (n1/n2);
        
    }
    
    cout << "Результат:" << endl;
    cout << r << endl;
    
    
}


void dz4_2() {
    
    // Задача №16

    double e;
    cout << "Введите E" << endl;
    cin >> e;
    double r=0;

    for (int n=1; n>0; n++){
        if (e<(1/pow(3,n))) {
            r+=(1/pow(3,n))*(pow(cos(pow(3, n-1)), 3));
        } else {
            break;
        }
    }
    
    cout << "Результат:" << endl;
    cout << r << endl;

    
}

void dz5_1() {
    
    // Задача №8

    cout << "Введите порядок матрицы:" << endl;
    int n;
    cin >> n;
    //Матрица A
    cout << "Введите матрицу A:" << endl;
    float** A = new float* [n];
    for (int i = 0; i < n; i++)
      A[i] = new float[n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> A[i][j];
      }
    }
    //Матрица B
    cout << "Введите матрицу B:" << endl;
    float** B = new float* [n];
    for (int i = 0; i < n; i++)
      B[i] = new float[n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> B[i][j];
      }
    }
    //Матрица E
    float** E = new float* [n];
    for (int i = 0; i < n; i++)
      E[i] = new float[n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) {
          E[i][j] = 1;
        }
        else {
          E[i][j] = 0;
        }
      }
    }
    //Матрица C
    float** C = new float* [n];
    for (int i = 0; i < n; i++)
      C[i] = new float[n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int q = i + 1, p = j + 1;
        C[i][j] = 1 / (q + p);
      }
    }
    //Побочная матрица
    float** H = new float* [n];
    for (int i = 0; i < n; i++)
      H[i] = new float[n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        H[i][j] = 0;
      }
    }
    //Вычисления
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        B[i][j] -= E[i][j];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          H[i][j] = A[i][k] * B[k][j];
        }
        
        
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        H[i][j] += C[i][j];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << H[i][j]<<' ';
      }
      cout << endl;
    }

}


string hexToAny(int num, int base) {
    stringstream ss;
    string result;

    do {
        int rem = num % base;
        ss << rem;
        result = ss.str() + result;
        ss.str("");
        num /= base;
    } while (num != 0);

    return result;
}

void dz5_2() {
    
    // Задача №16

    ifstream in("/Users/evgin/vsc/dz/dz/16CC.txt");
    ofstream out("/Users/evgin/vsc/dz/dz/output.txt");


    int base;
    cout << "Введите основание системы счисления (2-9): ";
    cin >> base;
    
    string hex;
    while (in >> hex) {
        int dec_num = stoi(hex, 0, 16);
        string converted = hexToAny(dec_num, base);
        out << converted << endl;
        cout << hex << " -> " << converted << endl;
    }
    
    in.close();
    out.close();
    
}




int main()
{
    setlocale (LC_ALL, "Rus");
    dz5_2();

    return 0;
}



