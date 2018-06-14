/*
We are given a list of (axis-aligned) rectangles.  Each rectangle[i] = [x1, y1, x2, y2] , 
where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates 
of the top-right corner of the ith rectangle.
Find the total area covered by all rectangles in the plane.  Since the answer may be too large, 
return it modulo 10^9 + 7.
 */
Solution1:
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles){
        long long res=0;
        set<int> sx,sy;
        for(auto v:rectangles) 
            sx.insert(v[0]),sy.insert(v[1]),sx.insert(v[2]),sy.insert(v[3]);
        
        vector<int> x(begin(sx),end(sx)),y(begin(sy),end(sy));
        vector<vector<int>> m(x.size(),vector<int>(y.size(),0));

        for (auto v:rectangles){
            for (auto i=lower_bound(begin(x),end(x),v[0]);*i!=v[2];++i)
                for (auto j=lower_bound(begin(y),end(y),v[1]);*j!=v[3];++j)
                    if (m[i-begin(x)][j-begin(y)]++==0) 
                        res=(res +((long long)*next(i)-*i)*(*next(j)-*j))%1000000007;
        }
        return res;
    }
};
Solution2:
class Solution {
public:
    
   static bool cmp(vector<int> a,vector<int> b){
        return a[1] < b[1];
   }
   
    
   int getDeep(vector<vector<int>>& rectangles,int x1,int x2){
       vector<pair<int,int>> deep;
       int length = 0;
       int start;
       int end;
       
       for(int i = 0;i < rectangles.size(); ++i){
           if(x1 >= rectangles[i][0] && x2 <= rectangles[i][2]){
               if(deep.empty()){
                   deep.push_back(make_pair(rectangles[i][1],rectangles[i][3]));
               }else{
                   end = deep[deep.size()-1].second;
                   if(rectangles[i][1] <= end){
                       start = deep[deep.size()-1].first;
                       end = max(end,rectangles[i][3]);
                       deep.pop_back();
                       deep.push_back(make_pair(start,end));
                   }else{
                       deep.push_back(make_pair(rectangles[i][1],rectangles[i][3]));
                   }
               }
           }
       }
       
       for(int i = 0;i < deep.size(); ++i){
           length += deep[i].second - deep[i].first;
       }
     
       return length;
   } 
    
   int rectangleArea(vector<vector<int>>& rectangles) {
        long long mod = 1000000000 + 7;
        long long area = 0;
        vector<long long> X;
       
       for(int i = 0;i < rectangles.size(); ++i){
           X.push_back(rectangles[i][0]);
           X.push_back(rectangles[i][2]);
       }
       
       sort(X.begin(),X.end());
       sort(rectangles.begin(),rectangles.end(),cmp);
       vector<long long>::iterator end_unique = unique(X.begin(), X.end());
       X.erase(end_unique, X.end());
       
       for(int i = 1;i < X.size(); ++i){
           long long height = getDeep(rectangles,X[i-1],X[i]);
           long long width = X[i]-X[i-1];
           area += (width*height)%mod;
           area = area%mod;
       }
       
       return area;
    }
};