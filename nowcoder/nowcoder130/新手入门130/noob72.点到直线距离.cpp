/**
 * @nc app=nowcoder id=1bcdd78060e54812a9c47ebe40c6af65 topic=383 question=11211973 lang=C++
 * 2026-01-21 11:01:05
 * https://www.nowcoder.com/practice/1bcdd78060e54812a9c47ebe40c6af65?tpId=383&tqId=11211973
 * [noob72] 点到直线距离
 */

/** @nc code=start */

#include <bits/stdc++.h>
using namespace std;

struct point{
    double x,y;
    point(double A,double B){
        x=A,y=B;
    }
    point() = default;
};

struct line{
    point point_A,point_B;
    line(point A,point B){
        point_A = A,point_B = B;
    }
    line() = default;
};

double getDistance(point P, line L){
    // TODO: 计算点P到直线L的距离
    

}















































































































int main(){
    int a, b, sx, sy, tx, ty;
    cin >> a >> b >> sx >> sy >> tx >> ty;
    point A(sx, sy), B(tx, ty), C(a, b);
    line L(A, B);
    printf("%.2lf", getDistance(C, L));
    return 0;
}

/** @nc code=end */
