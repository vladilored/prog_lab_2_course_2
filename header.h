#ifndef HEADER_H
#define HEADER_H

class Wine {
private:
    double alcContent; // Крепость алкоголя в %
    double density;    // Плотность в г/см³
    static int count;  // Статический счетчик созданных объектов

    // Закрытый конструктор и деструктор
    Wine(double alc = 0.0, double dens = 0.0);
    ~Wine();

    // Закрытый вспомогательный метод (сокрытие части методов)
    void normalizeData();

public:
    // Статические методы для создания и уничтожения объектов
    static Wine* create(double alc = 0.0, double dens = 0.0);
    static void destroy(Wine* obj);

    // Обязательные методы варианта 3 (Wine)
    void age();                  // выдержать вино
    void dilute(double ratio);   // разбавить вино

    // Метод вывода информации о текущем состоянии
    void printInfo() const;

    // Статический метод доступа к счетчику объектов
    static int getCount();

    // Внешние дружественные функции для создания и уничтожения
    friend Wine* externalCreate(double alc, double dens);
    friend void externalDestroy(Wine* obj);

    // Дружественная функция
    friend void inspectWine(const Wine& wine);
};

// Прототипы внешних функций
Wine* externalCreate(double alc, double dens);
void externalDestroy(Wine* obj);
void inspectWine(const Wine& wine);

#endif