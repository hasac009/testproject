
#include <iostream>
#include<math.h>
#include <io.h>
#include <fcntl.h>
#include <stdexcept>
#include <string>
#include <windows.h>
#include <algorithm>

using namespace std;

class Menu;
class Num;
class Text;

int getNumber(std::string text);

class Menu 
{
private:
    int Nmenu;
public:
    Menu() 
    {
        Nmenu = 0;
    }
    void showmenu() 
    {
        cout << "1." << "Ввести текст" << endl;
        cout << "2." <<"Узнать длину текста" << endl;
        cout << "3." << "Посчитать количество предложений(по количеству точек)" << endl;
        cout << "4." << "Проеверить и изменить написаны ли все первые буквы большими" << endl;
        cout << "5." << "Сделать весь текст капсом" << endl;
        cout << "6." << "Сделать весь текст прописными" << endl;
        cout << "7." << "Узнать сколько раз встречается введенное слово." << endl;
        cout << "8." << "Заменить выбранный символ на случайные." << endl;
        cout << "9." << "Вывести случайную фигуру из случайных символов " << endl;
        cout << "10." << "Узнать встречаются ли в тексте даты. " << endl;
        cout << "11." << "Повернуть в обратном порядке. " << endl;
        cout << "12." << "Узнать встречаются ли в тексте специальные символы." << endl;
        cout << "13." << "Заменить группу символов на такие ж символы только большие." << endl;
        cout << "14." << "Сохранить текст в файл " << endl;
        cout << "15." << "Открыть текст из файла "<< endl;

    }
    int value() 
    {
        

        this->showmenu();
        Nmenu = getNumber("Ваш ответ:");



        return Nmenu;
    }



};

class Text 
{
private:
    string text{};
public:
    Text() 
    {
        text = "";
    }
    Text(string t)
    {
        text = t;
    }
    void showText() 
    {
        cout << text;
        Sleep(2000);
    }
    void setText(string te) 
    {
        text = te;
    }

    friend void lenthStr(Text& text);
    friend void countOffer(Text& text1);
    friend void editedText(Text& text1);
    friend void Upper(Text& text1);
    friend void Lower(Text& text1);
    friend void checkWord(Text& T, string word);
};


int getNumber(std::string text)
{
    int input;
    while (true)
    {
        std::cout << text;
        std::cin >> input;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            system("cls");
        }
        else
            system("cls");
        break;

    }


    return input;


}

void lenthStr(Text& text1) 
{
    int lenth = text1.text.length();
    cout << "Количество символов - "<< lenth;
    Sleep(2000);

}

void countOffer(Text& text1)
{
    int lenth = text1.text.length();
    string s = text1.text;
    short count{};
    for(int i = 0; i < lenth;i++) 
    {
        if (s[i] == '.')
        {
            count++;
        }

    }
    (count > 4 || count == 0) ? cout << count <<" Предложений " : cout << count << " Предложения ";
    Sleep(2000);
}

void editedText(Text& text1)
{
    int lenth = text1.text.length();
    string s = text1.text;
    if (!isupper(s[0])) 
    {
        s[0] = toupper(s[0]);
    }
    for (int i = 0; i < lenth - 1; i++)
    {
        if (s[i] == '.')
        {
            if (!isupper(s[i + 1]));
            {
                s[i + 1] = toupper(s[i + 1]);
            }
        }

    }

    text1.setText(s);
}

void Upper(Text& text1) 
{
    string s = text1.text;

    transform(s.begin(), s.end(), s.begin(), ::toupper);
    text1.setText(s);
    text1.showText();
    Sleep(2000);
}

void Lower(Text& text1)
{
    
    for (int i = 0; i < text1.text.length(); i++) 
    {
        text1.text[i] = tolower(text1.text[i]);
    }
    text1.showText();
    Sleep(2000);
}

void checkWord(Text& T, string word)
{
    int j{};
    int count{};
    for (int i{}; i < T.text.length(); i++)
    {
        if (T.text[i] == word[j])
        {
            if (j == word.length() - 1)
            {
                count++;
                j = 0;
            }
            else
                j++;
        }
        else
        {
            j = 0;
        }
    }

    cout << "Слова \"" << word << "\" в тексте найдено: " << count;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Menu meny;
    Text text1;
    string str{};

    while (true) 
    {
        int numberUser{};
        numberUser = meny.value();
        switch (numberUser)
        {
        case 1:
            cout << "Введите текст: ";
            cin.ignore();
            getline(cin, str);
            text1.setText(str);
            system("cls");
            break;
        case 2:
            lenthStr(text1);
            system("cls");
            break;
        case 3:
            countOffer(text1);
            system("cls");
            break;
        case 4:
            editedText(text1);
            text1.showText();
            system("cls");
            break;
        case 5:
            Upper(text1);
            system("cls");
            break;
        case 6:
            Lower(text1);
            system("cls");
            break;
        default:
            break;
        }



    }
    

    return 0;
}