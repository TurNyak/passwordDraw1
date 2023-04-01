#include <iostream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;
int help_bool=0;//zmiena pomocnicza ktoramomoga zprawdzic czy uzyl uzytkownik ostatnia funkcje
int len;
string name,surname;
string password[20]={};
bool pass_numbers = true;
bool pass_letters = true;
bool pass_big_letters = true;
bool pass_marks = true;

// Funkcja ktora pobiera od uzytkownika dlugosc hasla
// i sprawdza dlugosc znakow
int get_pass_length(){
    string length;
    vector<int> vec={8,9,10,11,12,13,14,15,16,17,18,19,20};
    cout<<"Write how long your password will be from 8 to 20 characters :";
    //pobiera inforamcje od uzytkownika
    getline(cin,length);
    //string dlugosc na int dlugosc
    int a = atoi(length.c_str());
    //sprawdzamy czy pobrana informaja jest w zakresie
    if (find(vec.begin(), vec.end(), a) != vec.end() ){
            len=a;
    }//sprzwdza czy podane liczbe sa 1=liczbe,2=liczbe w zakresie od 8 do 20 jesli nie 1,2 to zwraca na poczatek
    else{return get_pass_length();}
}
// Funkcja ktora pobiera od uzytkownika czy bede mial liczby
// i jak bede mial to wpisuje ich w haslo
void get_pass_numbers(){
    string numbers[] = {"1","2","3","4","5","6","7","8","9","0"};
    string get;
    vector<int> vec={1,2};
    cout<<"Do you want to have numbers in your password if yes then write 1 if no then write 2 :";
    getline(cin,get);//pobiera inforamcje od uzytkownika
    int a = atoi(get.c_str());//string informacje na int informacje
    if (find(vec.begin(), vec.end(), a) != vec.end() ){
        if(a==2){
            pass_numbers=false;
        }else{
            help_bool++;
            for(int i=0;i<len;i++){
            int random = rand()%10;
            password[i]=numbers[random];
            }
        }//jesli uzytkownik wybral 1  to on ma w haslie liczby
    }else{return get_pass_numbers();}//sprzwdza czy podane liczbe sa 1=liczbe,2=liczbe 1,2
}
// Funkcja ktora pobiera od uzytkownika czy bede mial literki
// i jak bede mial to wpisuje ich w haslo
void get_pass_letters(){
    string letters[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    string get;
    vector<int> vec={1,2};
    cout<<"Do you want to have letters in your password if yes then write 1 if no then write 2 :";
    getline(cin,get);//pobiera inforamcje od uzytkownika
    int a = atoi(get.c_str());//string informacje na int informacje
    if (find(vec.begin(), vec.end(), a) != vec.end() ){
        if(a==2){
            pass_letters=false;
        }else{
            if(help_bool!=0){
                for(int i=0;i<len/2;i++){
                    int random_len = rand()%len;
                    int random = rand()%25;
                    password[random_len]=letters[random];
                }
            }else{
                help_bool++;
                for(int i = 0;i<len;i++){
                    int random = rand()%25;
                    password[i]=letters[random];
                }
            }
        }//jesli uzytkownik wybral 1  to on ma w haslie literki
    }else{return get_pass_letters();}//sprzwdza czy podane liczbe sa 1=liczbe,2=liczbe 1,2
}
// Funkcja ktora pobiera od uzytkownika czy bede mial duze literki
// i jak bede mial to wpisuje ich w haslo
void get_pass_big_letters(){
    string big_letters[] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    string get;
    vector<int> vec={1,2};
    cout<<"Do you want to have big letters in your password if yes then write 1 if no then write 2 :";
    getline(cin,get);//pobiera inforamcje od uzytkownika
    int a = atoi(get.c_str());//string informacje na int informacje
    if (find(vec.begin(), vec.end(), a) != vec.end() ){
        if(a==2){
                pass_big_letters=false;
        }else{
            if(help_bool!=0){
                for(int i = 0;i<len/3;i++){
                    int random_len = rand()%len;
                    int random = rand()%25;
                    password[random_len]=big_letters[random];
                }
            }else{
                help_bool++;
                for(int i = 0;i<len;i++){
                    int random = rand()%25;
                    password[i]=big_letters[random];
                }
            }
        }//jesli uzytkownik wybral 1  to on ma w haslie wielkie literki
    }else{return get_pass_big_letters();}//sprzwdza czy podane liczbe sa 1=liczbe,2=liczbe 1,2
}
// Funkcja ktora pobiera od uzytkownika czy bede mial duze specyalne znaki
// i jak bede mial to wpisuje ich w haslo
void get_pass_marks(){//funkcja pobiera od uzytkownika czy chce on miec specyalne znaki jesli tak to dodaje ich odrazu
    string marks [] = {"!","@","#","$","%","^","&","*","(",")","_","+","-","="};
    string get;
    vector<int> vec={1,2};
    cout<<"Do you want to have marks in your password if yes then write 1 if no then write 2 :";
    getline(cin,get);//pobiera inforamcje od uzytkownika
    int a = atoi(get.c_str());//string informacje na int informacje
    if (find(vec.begin(), vec.end(), a) != vec.end() ){
        if(a==2){
            pass_marks=false;
        }else{
            if(help_bool!=0){
                for(int i = 0;i<len/4;i++){
                    int random_len = rand()%len;//randomowe miejsce w haslie
                    int random = rand()%13;//randomowy znak
                    password[random_len]=marks[random];
                }
            }else{
                help_bool++;
                for(int i = 0;i<len;i++){
                    int random = rand()%13;
                    password[i]=marks[random];
                }
            }
        }//jesli uzytkownik wybral 1  to on ma w haslie specyalne znaki
    }else{return get_pass_marks();}//sprzwdza czy podane liczbe sa 1=liczbe,2=liczbe 1,2
}
// Funkcja odwolywa sie do pytajacych funkcyjach
// Sprawdza czy uzytkownik wybral
// i wypisuje haslo oraz imie i nazwisko
void create_password(){
    get_pass_length();
    get_pass_numbers();
    get_pass_letters();
    get_pass_big_letters();
    get_pass_marks();
    int chosen = pass_big_letters+pass_letters+pass_marks+pass_numbers;
    if (chosen != 0){
        cout<<surname<<" "<<name<<" your password :";
        for(int i = 0;i<len;i++){
            cout<<password[i];
        }
        cout<<endl;
    }else{
        cout<<"YOU SHOULD HAVE CHOSEN SOMETHING"<<endl;
        pass_numbers = true;
        pass_letters = true;
        pass_big_letters = true;
        pass_marks = true;
        return create_password();
    }
}
// Funkcjadla realizacji uzytkownika
// Pobieanie dabych imie i nazwiska
void create_user(){
    cout<<"Please enter your Name"<<endl;
    getline(cin,name);
    cout<<"Please enter your Surname"<<endl;
    getline(cin,surname);
    create_password();
}
int main(){
    srand (time(NULL));
    create_user();
    system("pause");
    return 0;
}



/* EXAMPLE OF COMMENTING YOUR CODE :3
// Funkcja pomocniczna wypisująca na std::cout wyśrodkowany tytuł
// Przyjmuje tytuł oraz szerokość terminala
// Zwraca czy napis mieści się w szerokości terminala
bool draw_title(string title, int term_width) {
    int left_space = term_width-title.length();
    // Jeśli będzie więcej napisu niż miejsca, nie da się umieścić
    if (left_space < 0) return false;

    // Wyświetl napis
    cout << string(left_space/2, '-') << title << string(left_space/2, '-') << endl;

    return true;
}
*/
