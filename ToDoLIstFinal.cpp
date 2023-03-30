// ToDoLIstFinal.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include<string>
#include <cstdlib>

using namespace std;

void interface() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t*                       Список дел                                    * " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;
}
int ID;

struct todo {
    int id;
    string task;
};

//Ввод
void addtodo() {
    interface();
    todo todo;
    cout << "\nВведите содержание дела: ";
    cin.get();
    getline(cin, todo.task);
    ID++;
    ofstream write;
    write.open("todo.txt", ios::app);
    write << "\n" << ID;
    write << "\n" << todo.task;
    write.close();

    write.open("id.txt");
    write << ID;
    write.close();

    char ch;
    cout << "{Хотите добавить ещё дело? y/n" << endl;
    cin >> ch;

    if (ch == 'y') {
        addtodo();
    }
    else {
        cout << "\n\tДанные сохранены";
        return;
    }
}

void print(todo s) {
    cout << "\n\tID is : " << s.id;
    cout << "\n\tTask is : " << s.task;
}

//Просмотр
void readData() {
    interface;
    todo todo;
    ifstream read;
    read.open("todo.txt");
    cout << "\n\t------------------Ваш список дел--------------------";

    while (!read.eof()) {
        read >> todo.id;
        read.ignore();
        getline(read, todo.task);
        print(todo);
    }
    read.close();
}

//Поиск
int searchData() {
    interface();
    int id;
    cout << "\n\tВведите номер дела: ";
    cin >> id;
    todo todo;
    ifstream read;
    read.open("todo.txt");

    while (!read.eof()) {
        read >> todo.id;
        read.ignore();
        getline(read, todo.task);
        if (todo.id == id) {
            print(todo);
            return id;
        }
    }
}

// Удалить
void deleteData() {
    interface();
    int id = searchData();
    cout << "\n\tВы действительно хотите удалить дело (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        todo todo;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("todo.txt");

        while (!read.eof()) {
            read >> todo.id;
            read.ignore();
            getline(read, todo.task);
            if (todo.id != id) {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << todo.task;
            }
        }
        read.close();
        tempFile.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\tДело успешно удалено";
    }
    else {
        cout << "\n\tЗапись не удалена";
    }
}
//Изменить
void updateData() {
    interface();
    int id = searchData();
    cout << "\n\tВы действительно хотите выполнить действие (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        todo newData;
        cout << "\n\tВведите содержание дела : ";
        cin.get();
        getline(cin, newData.task);
        todo todo;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("todo.txt");

        while (!read.eof()) {
            read >> todo.id;
            read.ignore();
            getline(read, todo.task);
            if (todo.id != id) {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << todo.task;
            }
            else {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << newData.task;
            }
        }
        read.close();
        tempFile.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\tДело успешно обновленно";
    }
    else {
        cout << "\n\tЗапись не обновлена";
    }
}
int main()
{
    setlocale(LC_ALL, "ru");
    system("cls");
    system("Color E0");
    system("title todoapp @copyassignment");
    interface();
    ifstream read;
    read.open("id.txt");
    if (!read.fail()) {
        read >> ID;
    }
    else {
        ID = 0;
    }
    read.close();

    while (true) {
        cout << endl << endl;
        cout << "\n\t1.Добавить дело";
        cout << "\n\t2.Просмотр дел";
        cout << "\n\t3.Поиск дела";
        cout << "\n\t4.Удаление дела";
        cout << "\n\t5.Изменение данных";

        int choice;
        cout << "\n\tВыберите действие : ";
        cin >> choice;
        switch (choice) {
        case 1:
            addtodo();
            break;
        case 2:
            readData();
            break;
        case 3:
            searchData();
            break;
        case 4:
            deleteData();
            break;
        case 5:
            updateData();
            break;
        }
    }

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
