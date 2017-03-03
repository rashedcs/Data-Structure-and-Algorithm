  #include<bits/stdc++.h>
  using namespace std;


  struct point
  {
    double x, y;
  };

  point rotateCCW(point p, double angle)
  {
     double a, b;
     a = p.x*cos(angle)-p.y*sin(angle);
     b = p.x*sin(angle) + p.y*cos(angle);
     p.x = a;
     p.y = b;
     return p;
  }


 int main()
 {

    vector<point>P;
    P.push_back(point{4.0, 3.0});
    printf("B = (%.2lf, %.2lf)\n", P[0].x, P[0].y); // B = (4.0, 3.0)
    point R = rotateCCW(P[0], 180);
    printf("R = (%.2lf, %.2lf)\n", R.x, R.y);
   //We can use object array to .................
   /*
    point B{4.0, 3.0};
    printf("B = (%.2lf, %.2lf)\n", B.x, B.y); // B = (4.0, 3.0)
    point F = rotateCCW(B, 180); // rotate B by 180 degrees COUNTER clockwise, F = (-3.0, 4.0)
    printf("F = (%.2lf, %.2lf)\n", F.x, F.y);
   */
    return 0;
 }
