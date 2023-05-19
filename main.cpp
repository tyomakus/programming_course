#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
 
std::string towords(int numb);
 
int main()
{
    std::ifstream file("file.txt");
    getline(file, str);
    int numb = std::stoi(str);
    file.close();
    //int numb=150;
    std::string str=towords(numb);
    std::cout<<numb<<" = "<<str;
    
    getch();
    return EXIT_SUCCESS;
}

std::string towords(int numb){
    //массив, для определения разряда, в котором находимся(сотни,десятки,еденицы...)
    int osn[11]={0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
 
    //массив оснований
    std::string basis[11][10]={
        {"","","","","","","","","",""},
        {"","один","два","три","четыре","пять","шесть","семь","восемь","девять"},
        {"","десять","двадцать","тридцать","сорок","пятьдесят","шестьдесят","семьдесят","восемьдесят","девяносто"},
        {"","сто","двести","триста","четыреста","пятьсот","шестьсот","семьсот","восемьсот","девятьсот"},
        {"","одна","две","три","четыре","пять","шесть","семь","восемь","девять"},
        {"","десять","двадцать","тридцать","сорок","пятьдесят","шестьдесят","семьдесят","восемьдесят","девяносто"},
        {"","сто","двести","триста","четыреста","пятьсот","шестьсот","семьсот","восемьсот","девятьсот"},
        {"","один","два","три","четыре","пять","шесть","семь","восемь","девять"},
        {"","десять","двадцать","тридцать","сорок","пятьдесят","шестьдесят","семьдесят","восемьдесят","девяносто"},
        {"","сто","двести","триста","четыреста","пятьсот","шестьсот","семьсот","восемьсот","девятьсот"},
        {"","один","два","три ","четыре","пять","шесть","семь","восемь","девять"}};
 
    //массив окончаний
    std::string termination[10][10]={
        {"","","","тысяч","","","миллионов","","","миллиардов"},
        {"","","","тысяча","","","миллион","","","миллиард"},
        {"","","","тысячи","","","миллиона","","","миллиарда"},
        {"","","","тысячи","","","миллиона","","","миллиарда"},
        {"","","","тысячи","","","миллиона","","","миллиарда"},
        {"","","","тысяч","","","миллионов","","","миллиардов"},
        {"","","","тысяч","","","миллионов","","","миллиардов"},
        {"","","","тысяч","","","миллионов","","","миллиардов"},
        {"","","","тысяч","","","миллионов","","","миллиардов"},
        {"","","","тысяч","","","миллионов","","","миллиардов"}};
 
    std::string dec[10]={"десять","одиннадцать","двенадцать","тринадцать","четырнадцать","пятнадцать","шестнадцать","семнадцать","восемнадцать","девятнадцать"};
    std::string result;
 
    if (!numb){
        result="ноль";
        return result;
    }
    int n1=numb;
    int cnt=0;
 
    //подсчет количесива цифр в числе
    while (numb){
        numb/=10;
        ++cnt;
    }
    int celoe=0;
 
    //перевод
    while (n1){
        if (!((cnt+1) % 3)){
            if ((n1/osn[cnt])==1){
                    n1%=osn[cnt];
                    --cnt;
                    celoe=n1/osn[cnt];
                    n1%=osn[cnt];
                    result+=dec[celoe];
                --cnt;
                if (!(cnt % 3))
                    result+=" "+termination[0][cnt]+" ";
            }
            if (!cnt) break;
        }
        celoe=n1/osn[cnt];
        n1%=osn[cnt];
        result+=basis[cnt][celoe]+" ";
        --cnt;
        if (!(cnt % 3))
            result+=termination[celoe][cnt]+" ";
    }
 
    return result;
}