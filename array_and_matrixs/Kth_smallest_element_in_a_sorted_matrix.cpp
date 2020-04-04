// 378 kth smallest element in a sorted matrix
// Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

// Note that it is the kth smallest element in the sorted order, not the kth distinct element.

// Example:

// matrix = [
//    [ 1,  5,  9],
//    [10, 11, 13],
//    [12, 13, 15]
// ],
// k = 8,

// return 13.
// Note:
// You may assume k is always valid, 1 ≤ k ≤ n2.

#include<vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0];
        int right = matrix[matrix.size()-1][matrix.size()-1];
        while(left < right){
            int mid = (left + right) / 2;
            int count = searchMatrix(matrix, mid);
            if(count < k){
               left = mid+1;
            }
            else{right = mid;}
        }
        return left;

    }

    int searchMatrix(vector<vector<int>>& matrix, int midvalue){
        int r = matrix.size()-1;
        int c = 0;
        int count = 0;
        while(r >= 0 && c < matrix[0].size()){
            if(matrix[r][c] <= midvalue){
                c++;
                count += r + 1;
            }
            else{r--;}
        }
        return count;
    }
};

