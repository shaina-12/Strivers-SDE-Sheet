// taken reference from https://www.youtube.com/watch?v=PzszoiY5XMQ&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=62
// taken reference from https://www.naukri.com/code360/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTabValue=DISCUSS
#include<cmath>
int NthRoot(int n, int m) {
  // Write your code here.
  int low = 1;
  int high = m;
  // most of the things analogus to binary search algorithm
  while(low<=high){
    int mid = (low+high)/2;
    if(pow(mid,n)==m){
      return mid;
    }
    else if(pow(mid,n)<m){
      low = mid+1;
    }
    else{
      high=mid-1;
    }
  }
  return -1;
}
