#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;


class Discipline
{
public:
    string Title, ControlType;
	int TotalHours;
	
    Discipline() {}

    Discipline(string title, int totalHours, string controlType)
        : Title(title), TotalHours(totalHours), ControlType(controlType) {

    }

    void print() const {
        cout
            << "Название дисциплины - " << Title << "\n"
            << "Кол-во часов - " << TotalHours << "\n"
            << "Форма контроля - " << ControlType << "\n";
    };

};

bool compareAscendig(const Discipline& a, const Discipline& b) {
    return a.Title < b.Title;
}

bool compareDescending(const Discipline& a, const Discipline& b) {
    return a.Title > b.Title;
}

void addDiscipline(Discipline disciplines[], int& disciplinesCount) {
    Discipline discipline;

    cout << "Введите название:";
    cin.ignore();
    getline(cin, discipline.Title);

    cout << "Введитекол-во часов:";
    cin.ignore();
    cin >> discipline.TotalHours;

    cout << "Введите форму контроля:";
    cin.ignore();
    getline(cin, discipline.ControlType);

    disciplines[disciplinesCount++] = discipline;
}

void writeDisciplineToFile(Discipline disciplines[], int disciplinesCount, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        return;
    }

    for (int i = 0; i < disciplinesCount; i++)
    {
        Discipline discipline = disciplines[i];
     
        file << discipline.Title << endl;
        file << discipline.TotalHours << endl;
        file << discipline.ControlType << endl;
    }

    file.close();
}

int main()
{
    setlocale(LC_ALL, "RU");
    system("chcp 1251");

    const int MAX_DISCIPLINES = 20;

    Discipline disciplines[MAX_DISCIPLINES];
    
    int disciplinesCount = 0;
    string filename = "desciplines.txt";

    int choice;
    cout << "1. Добавить дисциплину\n2. Сортировать и сохранить (по возростанию)\n3. Сортировать и сохранить (по убыванию)\n4. Вывести все дисциплины\n5. Выход\n";
    while (true) {
        cout << "Введите номер действия: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addDiscipline(disciplines, disciplinesCount);
            break;
        case 2:
            sort(disciplines, disciplines + disciplinesCount, compareAscendig);
            writeDisciplineToFile(disciplines, disciplinesCount, filename);
            break;
        case 3:
            sort(disciplines, disciplines + disciplinesCount, compareDescending);
            writeDisciplineToFile(disciplines, disciplinesCount, filename);
            break;
        case 4:
            for (int i = 0; i < disciplinesCount; i++)
            {
                disciplines[i].print();
                cout << endl;
            }
            break;
        case 5:
            return 0;
        default:
            cout << "Действие не найдено\n";
            break;
        }
    }

    return 0;
}
