#include <stdio.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>
#include <iostream>
#define N 4
#define alpha 0.05

using namespace std;

double X[N] = {150, 180, 165, 165};
double Y[N] = {150, 150, 175.98, 158.67};
double Z[N] = {150, 150, 150, 174.495};
int buf[N] = {0, 1, 2, 3};

void selectSort(){
  size_t size = N;
  long i, j, k;
  double x, y, z;
  int bf;
  for(int i=0; i < size; i++) {   	// i - номер текущего шага
    k=i;
    x=Z[i]; y = Y[i]; z = X[i]; bf = buf[i];

    for(j=i+1; j < size; j++)	// цикл выбора наименьшего элемента
      if (Z[j] < x ){
        k=j;
        x=Z[j];
        y=Y[j];
        z=Z[j];
        bf=buf[j] ;        // k - индекс наименьшего элемента
      }
    Z[k] = Z[i];
    Y[k] = Y[i];
    X[k] = X[i];
    buf[k] = buf[i];
    Z[i] = x;
    Y[i] = y;
    X[i] = z;
    buf[i] = bf;
     	            // меняем местами наименьший с a[i]
  }
}

void draw_face(int a, int b, int c){
    line(X[a], Y[a], X[b], Y[b]);
    line(X[b], Y[b], X[c], Y[c]);
    line(X[c], Y[c], X[a], Y[a]);
}

void print(){
    draw_face(buf[0], buf[1], buf[2]);
    draw_face(buf[0], buf[3], buf[1]);
    draw_face(buf[1], buf[2], buf[3]);
}


/*template<typename T>
void selectSort(T a[], T b[], T c[], int buf[], long size) {
  long i, j, k;
  T x, y, z;
  int bf;
  for( i=0; i < size; i++) {   	// i - номер текущего шага
    k=i;
    x=a[i]; y = b[i]; z = c[i]; bf = buf[i];

    for(j=i+1; j < size; j++)	// цикл выбора наименьшего элемента
      if (a[j] < x ){
        k=j;
        x=a[j];
        bf=buf[j] ;        // k - индекс наименьшего элемента
      }
    a[k] = a[i];
    b[k] = b[i];
    c[k] = c[i];
    buf[k] = buf[i];
    a[i] = x;
    b[i] = y;
    c[i] = z;
    buf[i] = bf;
     	            // меняем местами наименьший с a[i]
  }
}*/

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
            selectSort();
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
            for(i = 0; i<4; i++)
                cout << buf[i]<< "\t";
            cout << endl;

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
            }
            cleardevice();
    }
	closegraph();
	getchar();
	return 0;
}

