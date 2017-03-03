http://www.codingalpha.com/calculate-distance-between-two-points-c-program/

#include<bits/stdc++.h>
 using namespace std;



 double dist(pair<int,int> &p,pair<int,int> &q)
 {
    return hypot(p.first-q.first, p.second - q.second);
    //hypot (dx, dy) returns sqrt(dx*dx, dy*dy)
 }


 int main()
 {
	vector<pair<int,int> >V;
	V.push_back(make_pair(4,3));
	V.push_back(make_pair(2,2));

        cout<<dist(V[0], V[1])<<endl;

	return 0;
 }



  #include<bits/stdc++.h>
  using namespace std;


  struct point
  {
    double x, y;
  };

  double dist(point p1, point p2)
  {    // Euclidean distance  hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
  }

 int main()
 {
    vector<point> P;
    P.push_back(point{5, 1});
    P.push_back(point{3, 2});

    double d = dist(P[0], P[1]);
    cout<<d<<endl;

   /*
    printf("\nEnter The Coordinates of Point A:\n");
    printf("\nX - Axis Coordinate: \t");
    scanf("%f", &m.x);
    printf("\nY - Axis Coordinate: \t");
    scanf("%f", &m.y);
    printf("\nEnter The Coordinates of Point B:\n");
    printf("\nY - Axis Coordinate:\t");
    scanf("%f", &n.x);
    printf("\nY - Axis Coordinate: \t");
    scanf("%f", &n.y);
    printf("\nDistance between Points A and B: %f\n", distance_calculator(m, n));
    */
    return 0;
 }
