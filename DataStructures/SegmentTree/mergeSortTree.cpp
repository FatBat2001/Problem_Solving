#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;
void generateTree(int treeIndex, int leftIndex, int rightIndex, vector<pair<int, int> > &a, vector<int> tree[]){
   if (leftIndex == rightIndex){
      tree[treeIndex].push_back(a[leftIndex].second);
      return;
   }
   int midValue = (leftIndex + rightIndex) / 2;
   generateTree(2 * treeIndex, leftIndex, midValue, a, tree);
   generateTree(2 * treeIndex + 1, midValue + 1, rightIndex, a, tree);
   merge(tree[2 * treeIndex].begin(), tree[2 * treeIndex].end(), tree[2 * treeIndex + 1].begin(),
   tree[2 * treeIndex + 1].end(), back_inserter(tree[treeIndex]));
}
int calculateKSmallest(int startIndex, int endIndex, int queryStart, int queryEnd, int treeIndex, int key, vector<int> tree[]){
      if (startIndex == endIndex){
         return tree[treeIndex][0];
      }
      int mid = (startIndex + endIndex) / 2;
      int last_in_query_range = (upper_bound(tree[2 * treeIndex].begin(), tree[2 * treeIndex].end(), queryEnd) - tree[2 * treeIndex].begin());
      int first_in_query_range = (lower_bound(tree[2 * treeIndex].begin(), tree[2 * treeIndex].end(),queryStart) - tree[2 * treeIndex].begin());
      int M = last_in_query_range - first_in_query_range;
      if (M >= key){
         return calculateKSmallest(startIndex, mid, queryStart, queryEnd, 2 * treeIndex, key, tree);
      }
      else {
         return calculateKSmallest(mid + 1, endIndex, queryStart,queryEnd, 2 * treeIndex + 1, key - M, tree);
      }
}
int queryWrapper(int queryStart, int queryEnd, int key, int n,
   vector<pair<int, int> > &a, vector<int> tree[]){
      return calculateKSmallest(0, n - 1, queryStart - 1, queryEnd - 1, 1, key, tree);
}
int main(){
   int input[] = { 7, 8 , 1, 4 , 6 , 8 , 10 };
   int size = sizeof(input)/sizeof(input[0]);
   vector<pair<int, int> > vec;
   for (int i = 0; i < size; i++) {
      vec.push_back(make_pair(input[i], i));
   }
   sort(vec.begin(), vec.end());
   vector<int> tree[MAX];
   generateTree(1, 0, size - 1, vec, tree);

   cout<<"Count of number which are smaller than or equal to key value in the given range are:"<<endl;

   int getSmallestIndex = queryWrapper(2, 4, 2, size, vec, tree);
   cout << input[getSmallestIndex] << endl;
   getSmallestIndex = queryWrapper(1, 6, 3, size, vec, tree);
   cout << input[getSmallestIndex] << endl;
   return 0;
}