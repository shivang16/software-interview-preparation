// https://www.lintcode.com/problem/600/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
   vector < vector <char> > v;
   int searchRows(int i, int j, int left, int right, bool one){
      while (i < j) {
         int mid = i + (j - i) / 2;
         int k = left;
         while (k < right && v[mid][k] == '0')
            k++;
         if (k < right == one) {
            j = mid;
         }
         else {
            i = mid + 1;
         }
      }
      return i;
   }
   int searchColumn(int i, int j, int top, int bottom, bool one){
      while (i != j) {
         int mid = i + (j - i) / 2;
         int k = top;
         while (k < bottom && v[k][mid] == '0')
            k++;
         if (k < bottom == one) {
            j = mid;
         }
         else {
            i = mid + 1;
         }
      }
      return i;
   }
   int minArea(vector<vector<char>>& image, int x, int y) {
      v = image;
      int ret = 0;
      int n = image.size();
      int m = image[0].size();
      int top = searchRows(0, x, 0, m, true);
      int bottom = searchRows(x + 1, n, 0, m, false);
      int left = searchColumn(0, y, top, bottom, true);
      int right = searchColumn(y + 1, m, top, bottom, false);
      return (right - left) * (bottom - top);
   }
};
main(){
   Solution ob;
   vector<vector<char>> v =
   {{'0','0','1','0'},{'0','1','1','0'},{'0','1','0','0'}};
   cout << (ob.minArea(v, 0, 2));
}