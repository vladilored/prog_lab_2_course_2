#include "header.h"
#include <iostream>
#include <limits>
#include <random>

using namespace std;

// Отдельная функция валидации вещественного ввода (требование на 10 баллов)
double getValidDouble(const string& prompt, double minVal, double maxVal) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= minVal && value <= maxVal) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "  [Ошибка ввода!] Требуется число от " 
             << minVal << " до " << maxVal << ". Повторите попытку.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Отдельная функция валидации целочисленного ввода
int getValidInt(const string& prompt, int minVal, int maxVal) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= minVal && value <= maxVal) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "  [Ошибка ввода!] Требуется целое число от " 
             << minVal << " до " << maxVal << ". Повторите попытку.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Генерация случайных вещественных значений
double getRandomDouble(double minVal, double maxVal) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_real_distribution<double> dis(minVal, maxVal);
    return dis(gen);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "========================================================\n";
    cout << "       ЛАБОРАТОРНАЯ РАБОТА №2. ВАРИАНТ 3: КЛАСС WINE    \n";
    cout << "========================================================\n\n";

    // 1. Проверка счетчика при входе в main()
    cout << ">>> 1. Проверка счетчика объектов при входе в main(): " 
         << Wine::getCount() << endl << endl;

    // Диалог с пользователем (требование на 5 баллов)
    cout << "--- ДИАЛОГ С ПОЛЬЗОВАТЕЛЕМ: ВЫБОР РЕЖИМА ЗАДАНИЯ ДАННЫХ ---\n";
    cout << "1. Ввести данные вручную (с валидацией ввода)\n";
    cout << "2. Сгенерировать данные случайным образом\n";
    int choice = getValidInt("Выберите режим (1 или 2): ", 1, 2);

    double alc1, dens1, alc2, dens2, alc3, dens3, dynAlc, dynDens, extAlc, extDens;

    if (choice == 1) {
        cout << "\n>>> Ручной ввод параметров для массива из 3-х вин:\n";
        alc1 = getValidDouble("Вино 1 - крепость % [0.0 - 100.0]: ", 0.0, 100.0);
        dens1 = getValidDouble("Вино 1 - плотность г/см³ [0.8 - 1.5]: ", 0.8, 1.5);

        alc2 = getValidDouble("Вино 2 - крепость % [0.0 - 100.0]: ", 0.0, 100.0);
        dens2 = getValidDouble("Вино 2 - плотность г/см³ [0.8 - 1.5]: ", 0.8, 1.5);

        alc3 = getValidDouble("Вино 3 - крепость % [0.0 - 100.0]: ", 0.0, 100.0);
        dens3 = getValidDouble("Вино 3 - плотность г/см³ [0.8 - 1.5]: ", 0.8, 1.5);

        cout << "\n>>> Ручной ввод для динамического объекта:\n";
        dynAlc = getValidDouble("Динамическое вино - крепость % [0.0 - 100.0]: ", 0.0, 100.0);
        dynDens = getValidDouble("Динамическое вино - плотность г/см³ [0.8 - 1.5]: ", 0.8, 1.5);

        cout << "\n>>> Ручной ввод для внешнего объекта:\n";
        extAlc = getValidDouble("Внешнее вино - крепость % [0.0 - 100.0]: ", 0.0, 100.0);
        extDens = getValidDouble("Внешнее вино - плотность г/см³ [0.8 - 1.5]: ", 0.8, 1.5);
    } else {
        cout << "\n>>> Случайная генерация параметров вин:\n";
        alc1 = getRandomDouble(9.0, 15.0);  dens1 = getRandomDouble(0.98, 1.02);
        alc2 = getRandomDouble(9.0, 15.0);  dens2 = getRandomDouble(0.98, 1.02);
        alc3 = getRandomDouble(9.0, 15.0);  dens3 = getRandomDouble(0.98, 1.02);
        dynAlc = getRandomDouble(11.0, 16.0); dynDens = getRandomDouble(0.99, 1.03);
        extAlc = getRandomDouble(10.0, 18.0); extDens = getRandomDouble(0.98, 1.04);
        cout << "  Параметры успешно сгенерированы!\n";
    }

    // 2. Создание массива объектов через статический метод create()
    cout << "\n>>> 2. Создание массива объектов через Wine::create():\n";
    Wine* staticArray[3];
    staticArray[0] = Wine::create(alc1, dens1);
    staticArray[1] = Wine::create(alc2, dens2);
    staticArray[2] = Wine::create(alc3, dens3);
    cout << "Счетчик объектов после создания массива: " << Wine::getCount() << endl;

    // 3. Динамическое создание объекта
    cout << "\n>>> 3. Динамическое создание объекта через Wine::create():\n";
    Wine* dynamicWine = Wine::create(dynAlc, dynDens);
    cout << "Счетчик объектов после динамического создания: " << Wine::getCount() << endl;

    // 4. Демонстрация методов варианта 3 (age, dilute, printInfo)
    cout << "\n>>> 4. Демонстрация методов класса Wine:\n";
    cout << "Объект 0 до выдержки:\n";
    staticArray[0]->printInfo();
    cout << "Вызов age() для объекта 0:\n";
    staticArray[0]->age();

    cout << "\nОбъект 1 до разбавления:\n";
    staticArray[1]->printInfo();
    double diluteRatio = (choice == 1) 1
        ? getValidDouble("Введите коэффициент разбавления для объекта 1 (> 1.0): ", 1.01, 10.0) 
        : 2.0;
    cout << "Вызов dilute(" << diluteRatio << ") для объекта 1:\n";
    staticArray[1]->dilute(diluteRatio);

    // 5. Демонстрация дружественной функции
    cout << "\n>>> 5. Демонстрация дружественной функции inspectWine():\n";
    inspectWine(*staticArray[0]);

    // 6. Демонстрация внешних функций создания и уничтожения
    cout << "\n>>> 6. Демонстрация внешних функций (externalCreate, externalDestroy):\n";
    Wine* externalWine = externalCreate(extAlc, extDens);
    cout << "Счетчик объектов после externalCreate(): " << Wine::getCount() << endl;
    externalWine->printInfo();
    externalDestroy(externalWine);
    cout << "Счетчик объектов после externalDestroy(): " << Wine::getCount() << endl;

    // 7. Удаление динамического объекта
    cout << "\n>>> 7. Удаление динамического объекта через Wine::destroy():\n";
    Wine::destroy(dynamicWine);
    cout << "Счетчик объектов после удаления динамического объекта: " << Wine::getCount() << endl;

    // 8. Удаление массива объектов
    cout << "\n>>> 8. Удаление массива объектов через Wine::destroy():\n";
    for (int i = 0; i < 3; i++) {
        Wine::destroy(staticArray[i]);
    }
    cout << "Счетчик объектов после удаления массива: " << Wine::getCount() << endl;

    cout << "\n>>> Проверка счетчика при завершении: " << Wine::getCount() << endl;
    cout << "\n=== Программа успешно завершена ===\n";

    return 0;
}