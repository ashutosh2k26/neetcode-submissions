
struct Comp {
    bool operator()(vector<int> a, vector <int> b ) {
        if( (a[0]*a[0] + a[1]*a[1] ) > (b[0]*b[0] + b[1]*b[1]))
            return false;
        return true; 
    }
};
class Solution {
public:
   
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>, Comp> pq;
        for(int i = 0 ; i < k ; i++) {
            pq.push(points[i]);
        }

        for(int i = k ; i < points.size(); i++) {
            int dist = pq.top()[0]* pq.top()[0] + pq.top()[1]*pq.top()[1];
            int ndist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            std::cout<<"dist::"<<dist<<" ndist"<<ndist<<"\n";
            std::cout<<"top "<<pq.top()[0]<<" - "<<pq.top()[1]<<"\n";
            std::cout<<"vec "<<points[i][0]<<" - "<<points[i][1]<<"\n"; 

            if(ndist < dist) {
                pq.pop();
                pq.push(points[i]);
            }
        }

        vector<vector<int>> ret;
        while(!pq.empty()) {
            ret.push_back(pq.top());
            pq.pop();
        }
        return ret;
        
    }
};
