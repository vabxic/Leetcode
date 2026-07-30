class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size(),X,Y,g,m,c,d,ans = 0,total,XMid,YMid;

        map<pair<int,int>,map<int,int>> Lines;
        map<pair<int,int>,int> Mid;
        map<tuple<int,int,int,int,int>,int> LineMid;

        for(int i = 0;i < n ;i++){
            for(int j = i+1 ; j < n ;j++){
                X = points[i][0] - points[j][0];
                Y = points[i][1] - points[j][1];
                XMid = points[i][0] + points[j][0];
                YMid = points[i][1] + points[j][1];

                Mid[make_pair(XMid,YMid)]++;
                if(X<0||X==0&&Y<0){
                    X*=-1;
                    Y*=-1;
                }
                g = gcd(abs(X),abs(Y));
                X /= g;
                Y /= g;
                c = Y * points[i][0] - X * points[i][1]; 
                Lines[make_pair(X,Y)][c]++;
                
                LineMid[{X,Y,c,XMid,YMid}]++;
            }                                                                               
        }
        for(auto &x:Lines){
            total = 0;
            for(auto &y:x.second){
                total += y.second;
            }
            for(auto &y:x.second){
                total -= y.second;
                ans += y.second*total;
            }
        }
        for(auto &x:Mid){
            ans -= ((x.second)*(x.second-1))/2;   
        }
        for(auto &x:LineMid){
            ans += ((x.second)*(x.second-1))/2;
        }
        return max(ans,0);
    }
};