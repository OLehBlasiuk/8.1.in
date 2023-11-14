#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int CountCommaDashGroups(char* str)
{
    if (strlen(str) < 2)
        return 0;

    int k = 0;
    for (int i = 0; str[i + 1] != 0; i++)
    {
        if (str[i] == ',' && str[i + 1] == '-')
            k++;
    }
    return k;
}
char* ReplaceCommaDashGroups(char* str)
{
    size_t len = strlen(str);
    if (len < 2)
        return str;

    char* tmp = new char[len * 2 + 1];
    char* t = tmp;
    tmp[0] = '\0';
    size_t i = 0;

    while (i < len && str[i + 1] != 0)
    {
        if (str[i] == ',' && str[i + 1] == '-')//У,ЦФ
        {
            strcat(t, "*");//У*Ф.
            t += 1;
            i += 2;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }
    *t++ = str[i++];
    *t = '\0';
    // «м≥нюЇмо присвоЇнн€ результату , щоб уникнути витоку пам'€т≥
    strcpy(str, tmp);
    return tmp;
}
int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    
    cout << "String contained " << CountCommaDashGroups(str) << " groups of ', -'" << endl;

    char* dest = new char[151];
    dest = ReplaceCommaDashGroups(str);

    cout << "Modified string: " << dest << endl;

    cout << "Original string: " << str << endl;

    return 0;
}
