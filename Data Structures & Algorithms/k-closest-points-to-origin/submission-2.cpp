class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int L = 0;
        int R = points.size()-1;
        int pivot = points.size();

        while(pivot!=k) {
            pivot = partition(points,L,R);
            if(pivot<k) {
                L = pivot+1;
            } else {
                R = pivot -1;
            }
        }
        return vector<std::vector<int>>(points.begin(),points.begin()+k);
    }
private:
    int partition(vector<vector<int>>& points,int L,int R) {
        int pivotIdx = R;
        int pivotDistance = euclidean(points[pivotIdx]);
        int i = L;
        for (int j=L;j<R;j++) {
            if(euclidean(points[j])<=pivotDistance) {
                swap(points[i],points[j]);
                i++;
            }
        }
        swap(points[i],points[R]);
        return i;
    }
    
    int euclidean(vector<int>&point) {
        return point[0]*point[0]+point[1]*point[1];
    }
};
