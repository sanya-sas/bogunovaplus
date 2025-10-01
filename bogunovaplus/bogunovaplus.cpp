#include <iostream>
#include <string>
#include <limits> // проверка границы чисел
#include <fstream> // работа с файлами

using namespace std;

struct Pipe { // структура для трубы
    string name;
    double length = 0;
    double diameter = 0;
    bool isUnderRepair = false;
};

struct Cs { // структура для компрессорной станции 
    string name;
    int totalWorkshops = 0;
    int workingWorkshops = 0;
    double efficiency = 0;
};

template <typename T> // Проверка входных данных
T getValidInput(const string& prompt) {
    T value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаю буфер до конца строки 
            cout << "Error: Enter a valid number.\n";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

void createPipe(Pipe& pipe) { // Ссылка на оригинальный объект 
    cout << "\n+++ Add New Pipe +++" << endl;
    cout << "Enter pipe name: ";
    getline(cin, pipe.name); // Читаю всю строку

    pipe.length = getValidInput<double>("Enter pipe length (km): "); // Проверка для длины
    while (pipe.length <= 0) {
        cout << "Length must be positive. Try again.\n";
        pipe.length = getValidInput<double>("Enter pipe length (km): ");
    }

    pipe.diameter = getValidInput<double>("Enter pipe diameter (mm): "); // Проверка для диаметра
    while (pipe.diameter <= 0) {
        cout << "Diameter must be positive. Try again.\n";
        pipe.diameter = getValidInput<double>("Enter pipe diameter (mm): ");
    }

    pipe.isUnderRepair = false;
    cout << "Pipe '" << pipe.name << "' added successfully!\n" << endl; // Как f строки в питоне
}

void createCs(Cs& cs) { // Ссылка на оригинальный объект Cs
    cout << "\n+++ Add New Compressor Station +++" << endl;
    cout << "Enter station name: ";
    getline(cin, cs.name);

    cs.totalWorkshops = getValidInput<int>("Enter total workshops: ");
    while (cs.totalWorkshops <= 0) { // Проверка количества цехов
        cout << "Number must be positive. Try again.\n";
        cs.totalWorkshops = getValidInput<int>("Enter total workshops: ");
    }

    cs.workingWorkshops = getValidInput<int>("Enter working workshops: "); // Проверка количества цехов в работе 
    while (cs.workingWorkshops < 0 || cs.workingWorkshops > cs.totalWorkshops) {
        cout << "Working workshops cannot be negative or exceed total. Try again.\n";
        cs.workingWorkshops = getValidInput<int>("Enter working workshops: ");
    }

    cs.efficiency = getValidInput<double>("Enter efficiency (%): "); // Проверка значения эффективности
    while (cs.efficiency < 0 || cs.efficiency > 100) {
        cout << "Efficiency must be between 0 and 100%. Try again.\n";
        cs.efficiency = getValidInput<double>("Enter efficiency (%): ");
    }
    cout << "Station '" << cs.name << "' added successfully!\n" << endl; // Успех
}
