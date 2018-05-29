#include <QCoreApplication>
#include <iostream>
#include <new>         // for placement new
#include <cstring> // for strcpy()


struct chaff
{
    char dross[20];
    int slag;
};

// our buffer
// sizeof(char) = 1, sizeof(char dross[20]) = 1 * 20 = 20, sizeof(int) = 4
// ==> sizeof(chaff) = 20 + 4 = 24
// Создаем с кол-вом элементов(байт) = 24 * 2 = 48
char buffer[sizeof(chaff) * 2];

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    using std::cout;
    using std::cin;
    using std::endl;
    using std::strcpy;
    using std::strlen;

    std::cout << "Go\n";

    chaff * pstr = new (buffer) chaff[2]; // помещаем массив chaff в область buffer


    int i = 0;
    cout << "Enter the dross name for element " << i + 1 << ": ";
    char dross[20];
    cin.get(dross, 20);
    strcpy(pstr[i].dross, dross);
    cout << "Enter slag value for element " << i + 1 << ": ";
    cin >> pstr[i].slag;

    cout << "Dross: " << pstr[i].dross << endl;
    cout << "Slag:  " << pstr[i].slag << endl;

    cin.clear();
    cin.get();
    //********
    i = 1;
    cout << "Enter the dross name for element " << i + 1 << ": ";
    cin.get(dross, 20);
    strcpy(pstr[i].dross, dross);
    cout << "Enter slag value for element " << i + 1 << ": ";
    cin >> pstr[i].slag;

    cout << "Dross: " << pstr[i].dross << endl;
    cout << "Slag:  " << pstr[i].slag << endl;

    std::cout << "Bye\n";
    return a.exec();
}





