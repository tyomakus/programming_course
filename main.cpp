#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string convertToWords(int number);

int main()
{
    setlocale(LC_ALL, "Russian");
    ifstream input("numbers.txt");
    int number;

    while (input >> number)
    {
        string words = convertToWords(number);
        cout << words << endl;
    }

    input.close();

    return 0;
}

string convertToWords(int number)
{
    // массив словесных представлений чисел от 0 до 19
    string units[] = {"ноль", "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять",
                      "десять", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать", "пятнадцать", "шестнадцать",
                      "семнадцать", "восемнадцать", "девятнадцать"};

    // массив словесных представлений десятков от 20 до 90
    string tens[] = {"", "", "двадцать", "тридцать", "сорок", "пятьдесят", "шестьдесят", "семьдесят", "восемьдесят", "девяносто"};

    // массив словесных представлений сотен от 100 до 900
    string hundreds[] = {"", "сто", "двести", "триста", "четыреста", "пятьсот", "шестьсот", "семьсот", "восемьсот", "девятьсот"};

    string words;

    if (number < 20)
    {
        words = units[number];
    }
    else if (number < 100)
    {
        words = tens[number / 10] + " " + units[number % 10];
    }
    else if (number < 1000)
    {
        words = hundreds[number / 100] + " " + convertToWords(number % 100);
    }
    else if (number < 1000000)
    {
        words = convertToWords(number / 1000) + " тысяч " + convertToWords(number % 1000);
    }
    else if (number < 1000000000)
    {
        words = convertToWords(number / 1000000) + " миллионов " + convertToWords(number % 1000000);
    }

    return words;
}