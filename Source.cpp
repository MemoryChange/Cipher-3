#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

string encryptMessage(const string& message, int key1, int key2, int key3)
{
    string encryptedMessage = message;
    int key1Counter = key1;
    int key2Counter = key2;
    int key3Counter = key3;

    string alphabet = "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß ,.!?";
    int alphabetSize = alphabet.length();

    for (size_t i = 0; i < encryptedMessage.length(); i++)
    {
        char currentChar = encryptedMessage[i];
        size_t charIndex = alphabet.find(currentChar);

        if (charIndex != string::npos)
        {
            if (key1Counter > 0)
            {
                charIndex = (charIndex + key1) % alphabetSize;
                key1Counter--;
            }
            else if (key2Counter > 0)
            {
                charIndex = (charIndex + key2) % alphabetSize;
                key2Counter--;
            }
            else if (key3Counter > 0)
            {
                charIndex = (charIndex + key3) % alphabetSize;
                key3Counter--;
            }
            else
            {
                key1Counter = key1;
                key2Counter = key2;
                key3Counter = key3;

                charIndex = (charIndex + key1) % alphabetSize;
                key1Counter--;
            }

            encryptedMessage[i] = alphabet[charIndex];
        }
    }

    return encryptedMessage;
}

string decryptMessage(const string& encryptedMessage, int key1, int key2, int key3)
{
    string decryptedMessage = encryptedMessage;
    int key1Counter = key1;
    int key2Counter = key2;
    int key3Counter = key3;

    string alphabet = "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß ,.!?";
    int alphabetSize = alphabet.length();

    for (size_t i = 0; i < decryptedMessage.length(); i++)
    {
        char currentChar = decryptedMessage[i];
        size_t charIndex = alphabet.find(currentChar);

        if (charIndex != string::npos)
        {
            if (key1Counter > 0)
            {
                charIndex = (charIndex - key1 + alphabetSize) % alphabetSize;
                key1Counter--;
            }
            else if (key2Counter > 0)
            {
                charIndex = (charIndex - key2 + alphabetSize) % alphabetSize;
                key2Counter--;
            }
            else if (key3Counter > 0)
            {
                charIndex = (charIndex - key3 + alphabetSize) % alphabetSize;
                key3Counter--;
            }
            else
            {
                key1Counter = key1;
                key2Counter = key2;
                key3Counter = key3;

                charIndex = (charIndex - key1 + alphabetSize) % alphabetSize;
                key1Counter--;
            }

            decryptedMessage[i] = alphabet[charIndex];
        }
    }

    return decryptedMessage;
}

string inputMessage()
{
    string message;
    cout << "Ââåäèòå ñîîáùåíèå: ";
    getline(cin, message);
    return message;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string message = inputMessage();
    int key1 = 5;
    int key2 = 7;
    int key3 = 3;

    cout << "Âûáåğèòå ğåæèì: " << endl;
    cout << "1. Çàøèôğîâàòü ñîîáùåíèå" << endl;
    cout << "2. Ğàñøèôğîâàòü ñîîáùåíèå" << endl;
    cout << "Êëş÷ 1 = " << key1 << endl;
    cout << "Êëş÷ 2 = " << key2 << endl;
    cout << "Êëş÷ 3 = " << key3 << endl;
    cout << "Âàø âûáîğ: ";

    int choice;
    cin >> choice;
    cin.ignore(); 

    if (choice == 1)
    {
        string encryptedMessage = encryptMessage(message, key1, key2, key3);
        cout << "Çàøèôğîâàííîå ñîîáùåíèå: " << encryptedMessage << endl;
    }
    else if (choice == 2)
    {
        string decryptedMessage = decryptMessage(message, key1, key2, key3);
        cout << "Ğàñøèôğîâàííîå ñîîáùåíèå: " << decryptedMessage << endl;
    }
    else
    {
        cout << "Íåâåğíûé âûáîğ." << endl;
        return 1;
    }

    return 0;
}