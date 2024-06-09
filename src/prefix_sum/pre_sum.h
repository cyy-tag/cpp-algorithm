#include <vector>
#include <numeric>
#include <limits>

using namespace std;
/*
nums = [1, 2, 2, 3, 4, ...]
一维前缀和 定义pre_sum[i+1] 表示nums[0, i]前缀和
这样不用单独处理第一行/第一列的元素和
pre_sum[0] = 0;
pre_sum[i+1] = pre_sum[i] + nums[i-1] (i >= 1)
sum(nums[l, r]) = pre_sum[r+1] - pre_sum[l]
*/

void LinearPreSum(vector<int> & nums) {
    int n = nums.size();
    vector<int> pre_sum(n+1);
    pre_sum[0] = 0;
    for(int i = 1; i <= n; i++) {
        pre_sum[i] = pre_sum[i-1] + nums[i-1];
    }
}


/*
二维前缀和
matrix[m][n]
定义sum[i+1][j+1]表示左上角为matrix[0][0]
右下角为matrix[i][j]的子矩阵和
sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + matrix[i][j];

类似的定义min_region[i+1][j+1]表示左上角在(0, 0)，右下角在(i, j)的矩阵最小值
min_region[i+1][j+1] = min({min_region[i][j+1], min_region[i+1][j], matrix[i][j]})

类似最大值为
max_region[i+1][j+1] = max({max_region[i][j+1], max_region[i+1][j], matrix[i][j]})

*/
class NumMatrix {
public:
    vector<vector<int>> sum;
    vector<vector<int>> min_region;
    vector<vector<int>> max_region;

    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        //二维前缀和
        sum = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        //二维矩阵最小值
        min_region = vector<vector<int>>(m+1, vector<int>(n+1, numeric_limits<int>::max()));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                min_region[i][j] = min({min_region[i-1][j], min_region[i][j-1], matrix[i-1][j-1]});
            }
        }
        //二维矩阵最大值
        max_region = vector<vector<int>>(m+1, vector<int>(n+1, numeric_limits<int>::min()));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                max_region[i][j] = max({min_region[i-1][j], max_region[i][j-1], matrix[i-1][j-1]});
            }
        }
    }
    //返回指定区间左上角为[row1, col1], 右下角[row2, col2]的区域和
    int SumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row2+1][col1] - sum[row1][col2+1] + sum[row1][col1];
    }
};
