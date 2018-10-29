#include <stdio.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>
#include <iostream>
#define N 4
#define alpha 0.05
#define BN 100000

using namespace std;

double X[N] = {150, 180, 165, 165};
double Y[N] = {150, 150, 175.98, 158.67};
double Z[N] = {150, 150, 150, 174.495};
double Zm[3];

int draw_face(int a, int b, int c, int z){
    int flag = 0;
    if(Zm[z] == BN)
        return 0;

    for(int i=0; i<3;){
        if(Zm[z]==Zm[i])
            i++;
        else if(Zm[z]<Zm[i]){
            flag = 1;
            i++;
        }
        else
            i++;
    }

    if(flag==1){
        line(X[a], Y[a], X[b], Y[b]);
        line(X[b], Y[b], X[c], Y[c]);
        line(X[c], Y[c], X[a], Y[a]);
        Zm[z] = BN;
        return 1;
    }
    return 0;


}

void print(){
    int counter = 0;
    while(1){
        counter += draw_face(0, 1, 2, 0);
        counter += draw_face(0, 3, 1, 1);
        counter += draw_face(1, 2, 3, 2);
        if(counter == 3)
            break;
    }
}

void print_coor(){
    int i;
    cout << endl;
    for(i = 0; i<4; i++)
        cout << X[i] << "\t";
    cout << endl;
    for(i = 0; i<4; i++)
        cout << Y[i]<< "\t";
    cout << endl;
    for(i = 0; i<4; i++)
        cout << Z[i]<< "\t";
    cout << endl << endl;
    for(i = 0; i<3; i++)
        cout << Zm[i]<< "\t";
    cout << endl << endl;
}

int main(){
    double x, y, z;
    double midx = 0, midy = 0, midz = 0;
    int step = 3;
    double k = 1.00;
    int i;
    int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "");
	setlocale(LC_ALL, "Russian");
	double size_f = sizeof(Z)/sizeof(Z[0]);

    while(1){
            Zm[0]=((Z[0]+Z[1]+Z[2])/3);
            Zm[1]=((Z[0]+Z[3]+Z[1])/3);
            Zm[2]=((Z[1]+Z[2]+Z[3])/3);
            print_coor();
            print();
            midx=0;
            midy=0;
            midz=0;
            float x1, y1, z1;
            for(int i = 0; i < 4; i++){
                midx += X[i];
                midy += Y[i];
                midz += Z[i];
            }
            midx/=N;
            midy/=N;
            midz/=N;

            char c = getche();
            switch(c){
            case 'w':
                for(int i = 0; i < 4; i++)
                    Y[i]-=step;
                break;
            case 's':
                for(int i = 0; i < 4; i++)
                    Y[i]+=step;
                break;
            case 'a':
                for(int i = 0; i < 4; i++)
                    X[i]-=step;
                break;
            case 'd':
                for(int i = 0; i < 4; i++)
                    X[i]+=step;
                break;
            case 'z':
                for(int i = 0; i < 4; i++){
                    x1 = X[i];
                    y1 = Y[i];
                    X[i] = midx + (x1-midx)*cos(alpha)-(y1-midy)*sin(alpha);
                    Y[i] = midy + (x1-midx)*sin(alpha)+(y1-midy)*cos(alpha);
                }
                break;
            case 'y':
                for(int i = 0; i < 4; i++){
                    x1 = X[i];
                    z1 = Z[i];
                    X[i] = midx + (x1-midx)*cos(alpha)-(z1-midz)*sin(alpha);
                    Z[i] = midz + (x1-midx)*sin(alpha)+(z1-midz)*cos(alpha);
                }
                break;
            case 'x':
                for(int i = 0; i < 4; i++){
                    y1 = Y[i];
                    z1 = Z[i];
                    Y[i] = midy + (y1-midy)*cos(alpha)-(z1-midz)*sin(alpha);
                    Z[i] = midz + (y1-midy)*sin(alpha)+(z1-midz)*cos(alpha);
                }
                break;
            case '+':
                k = 1.15;
                for(int i = 0; i < 4; i++){
                    x1=X[i];
                    y1=Y[i];
                    z1=Z[i];
                    X[i]=midx-k*(midx-X[i]);
                    Y[i]=midy-k*(midy-Y[i]);
                    Z[i]=midz-k*(midz-Z[i]);

                }
                break;
            case '-':
                k = 0.85;
                for(int i = 0; i < 4; i++){
                    x1=X[i];
                    y1=Y[i];
                    z1=Z[i];
                    X[i]=midx-k*(midx-X[i]);
                    Y[i]=midy-k*(midy-Y[i]);
                    Z[i]=midz-k*(midz-Z[i]);
                }
                break;
            case '0':
                return 0;
            }
            cleardevice();
    }
	closegraph();
	getchar();
	return 0;
}
