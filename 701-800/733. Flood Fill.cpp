/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.
 */
class Solution {
public:
    queue<pair<int,int> > qu;
    int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
    vector<vector<int> >vis;
    vector<vector<int> > floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m=image.size(),n; if(m) n=image[0].size();
        if(!n) return image;
        //cout<<m<<' '<<n<<endl;
        int pcolor=image[sr][sc];
        image[sr][sc]=newColor;
        qu.push(make_pair(sr,sc));
        vector<int > tt;tt.assign(n,0);
        for(int i=0;i<m;i++) vis.push_back(tt);
        //cout<<qu.front().first<<' '<<qu.front().second<<endl;
        while(!qu.empty()){
            int x=qu.front().first, y=qu.front().second;
            //cout<<x<<' '<<y<<endl;
            qu.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(0<=nx&&nx<m&&0<=ny&&ny<n&&(image[nx][ny]==pcolor)&&vis[nx][ny]==0){
                    image[nx][ny]=newColor;
                    vis[nx][ny]=1;
                    qu.push(make_pair(nx,ny));
                }
            }
        }
        return image;
    }
};