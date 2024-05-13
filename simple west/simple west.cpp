#include <iostream>
using namespace std;

string here;
int x = 0;
int y = 0;
struct path {
    int fx;
    int fy;
    int tx;
    int ty;
};
path hall{ -2,2,0,0 };

bool isbet(int question, int small, int large) {
    if ((question<=large && question>=small)|| (question>=large && question<=small)) {
        return true;
    }
    else {
        return false;
    }
}

bool rectbet(int x, int y, path rect) {
    int slope;
    int intercept;
    if (rect.fy < rect.ty) {
         slope = 1;
    }
    else {
        slope = -1;
    }
    intercept = rect.fy - (slope * rect.fx);
    if (isbet(x, rect.fx, rect.tx) && isbet(y, rect.fy, rect.ty)) {
        if (rect.fy == slope * rect.fx + intercept) {
            return true;
        }
    }
    else {
        return false;
    }
}

int main()
{

    while (true) {
        cin >> here;
        if (here == "nw"&&rectbet(x,y,hall)&&hall.fx<x){
            x = x - 2;
            y = y + 2;
        }
        cout << x << "," << y << endl;
    }
}
