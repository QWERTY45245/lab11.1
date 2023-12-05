#include <iostream>
#include <fstream>
#include <cmath>
#include<Windows.h>
using namespace std;

bool is_sqrt_value(double x) {
    // Функція, яка перевіряє, чи може число бути значенням функції кореня квадратного.
    return x <= 0;
}

void process_data(const string& tt, const string& ee) {
    try {
        ifstream input_file(tt);
        ofstream output_file(ee);

        if (!input_file.is_open() || !output_file.is_open()) {
            throw runtime_error("Не вдалося відкрити файл.");
        }

        double num;
        while (input_file >> num) {
            if (is_sqrt_value(num)) {
                output_file << num << endl;
            }
        }

        input_file.close();
        output_file.close();
    }
    catch (const exception& e) {
        cerr << "Помилка: " << e.what() << endl;
    }
}

void print_file_content(const string& tt) {
    // Функція для виведення вмісту файлу на екран.
    try {
        ifstream file(tt);

        if (!file.is_open()) {
            throw runtime_error("Не вдалося відкрити файл.");
        }

        cout << "Вміст файлу " << tt << ":\n";
        cout << file.rdbuf() << endl;

        file.close();
    }
    catch (const exception& e) {
        cerr << "Помилка: " << e.what() << endl;
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    
    // Отримуємо ім'я вхідного файлу від користувача
    string input_filename;
    cout << "Введіть ім'я вхідного файлу: ";
    cin >> input_filename;

    // Обробка даних та запис результатів у вихідний файл
    string output_filename = "ee.txt";
    process_data(input_filename, output_filename);

    // Виведення вмісту результатуючого файлу на екран
    print_file_content(output_filename);

    return 0;
}

    