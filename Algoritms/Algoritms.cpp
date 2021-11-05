#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>


using namespace std;

struct list {
    list* next;
    char* word;
    int key;
};
static list* Last;

list* Initial() {
    list* s;
    Last = s = new list;
    s->next = NULL;
    return s;
}
list* AddElement(list* s, int key, char* word) {
    list* q,*p;
    p = s;
    q = s->next;
    Last->key = key;
    while ((q!= NULL) && (q->key < key)) {
        p = q;
        q = q->next;
    }
    if (q == NULL || (p->key > key)) {
        q = new list;
        q->key = key;
        q->word = word;
        q->next = s;
        s = q;
    }
    else {
        if ((key == p->key) || (q != Last && q->key == key)) {
            throw exception("Invalid value number");
        }
        list* k = new list;
        k->key = key;
        k->word = word;
        k->next = q;
        p->next = k;
    }
    return s;
}
void PrintElement(list* s) {
    list* p = s;
    while (p != Last) {
        cout << p->key << ' ' << p->word << endl;
        p = p->next;
    }
}


int main()
{
    FILE* f;
    char buf[1000];
    char* word;
    int num;
    list* s = Initial();
    f = fopen("wordlist.txt", "r");
    if (f == NULL) {
        cout << "do not read file!! " << endl;
        return 0;
    }

    while (true) {
        if (fscanf(f, "%s", &buf) == -1)break;
        if(fscanf(f, "%d", &num) == -1)break;
        word = new char[strlen(buf)];
        strcpy(word, buf);
        try
        {
            s = AddElement(s, num, word);
        }
        catch (exception& a)
        {
            cout << a.what() << endl;
            return 0;
        }
    }
    PrintElement(s);
   


   
    return 0;
    

    // вставка элемента между т

    
}

