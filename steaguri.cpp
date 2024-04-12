#include <iostream>
#include <string.h>
using namespace std;

char culori[11][11];
int st[4], n, k, contor;

void Init(){
    st[k] = 0;
}

int Succesor(){
    if(st[k] < n)
    {
        st[k]++;
        return 1;
    }
    else return 0;
}

int Valid(){
    for(int i = 1; i < k; i++)
        if(st[i] == st[k])
          return 0;
    return 1;
}

int Solutie(){
    return k == 3;
}

void Tipar(){
    for(int i = 1; i <= 3; i++)
        cout << culori[st[i]] << " ";
    cout << endl;
}

void bck(){
    int es;
    k = 1;
    Init();
    while(k > 0){
        do{}while((es = Succesor()) && !Valid());
        if(es){
            if(Solutie()){
                Tipar();
                contor++;
            }
            else{
                k++;
                Init();
            }
        }
        else k--;
    }
}

int main()
{
    cout << "cate culori? "; cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin.get();
        cin.get(culori[i], 11);
    }
    bck();
    cout << endl << "au fost generate " << contor << " solutii";
    return 0;
}
