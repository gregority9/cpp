#include <bits/stdc++.h>

using namespace std;

constexpr int poziom = 10;
bool tab[1<<poziom][1<<poziom];

void fraktal2(int stopien, int x, int y){ //x=8; y=1
    //cout << stopien << " "<<x << " " << y << endl;
    if(stopien == 0) return;
    for(int i=0; i<(1<<stopien); i++){
        tab[x][y+i] = true;
        //cout << x << " " << y+i << endl;
    }
    for(int i=0; i<1<<stopien; i++){
        tab[x-i][y-1+(1<<stopien)] = true;
        //cout << x- << " " << y+1 << endl;
    }
    for(int i=0; i<(1<<stopien); i++){
        tab[x-i][y+i] = true;
    }
    if(stopien != 1){
        fraktal2(stopien-1, x, y);
        fraktal2(stopien-1, x, y+(1<<(stopien-1)));
        fraktal2(stopien-1, x-(1<<(stopien-1)), y+(1<<(stopien-1)));
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    
    if(n==2){
        fraktal2(k, 1<<k , 1); //stopien, x, y
        for(int i=1; i<=(1<<k); i++){
            for(int j=1; j<=(1<<k); j++){
                if(tab[i][j] == false) cout << " ";
                else cout << "#";
            }
            cout << "\n";
        }
    }


    return 0;
}
