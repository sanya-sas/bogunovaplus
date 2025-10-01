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
