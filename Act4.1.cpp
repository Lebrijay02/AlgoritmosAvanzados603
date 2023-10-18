//Juan Lebrija A01721659
#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x, y;
};

//O(1)
int crossProduct(Point p1, Point p2, Point p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

//O(1)
bool intersect(Point p1, Point p2, Point p3, Point p4) {
  int cp1, cp2, cp3, cp4;
  cp1 = crossProduct(p1, p2, p3);
  cp2 = crossProduct(p1, p2, p4);
  cp3 = crossProduct(p3, p4, p1);
  cp4 = crossProduct(p3, p4, p2);

  return ((cp1 > 0 && cp2 < 0) || (cp1 < 0 && cp2 > 0)) && ((cp3 > 0 && cp4 < 0) || (cp3 < 0 && cp4 > 0));
}

//O(N)
int main() {
  int N;
  cout <<"N: ";
  cin >> N;
  vector<bool> ans(N);
  
  for(int i=0; i<N; i++){
    Point p1, p2, p3, p4;
    cout<<"Input: ";
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
    ans[i] = intersect(p1, p2, p3, p4);
  }
  
  for(int i=0; i<N; i++){
    if(ans[i]){
      cout<<"True"<<endl;
    }else{
      cout<<"False"<<endl;
    }
  }
  return 0;
}

/*
1 5 7 1 1 4 10 9
10 2 1 12 3 3 0 15
-6 -6 3 4 2 2 1 1
True
False
False
*/