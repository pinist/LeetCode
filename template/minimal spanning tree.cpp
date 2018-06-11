//kruskal
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MV=1e5+5;
const int ME=1e5+5;
struct Ed
{
	int fr,to,w;
	Ed(int fr=0,int to=0,int w=0):fr(fr),to(to),w(w){}
	bool operator<(const Ed & T) const
	{
		return w<T.w;
	}
}ed[ME];

int ne,nv;
int uf[MV],mst[MV];

int find(int x){
	return x==uf[x]?x:uf[x]=find(uf[x]);
}

void init(int nv){
	for(int i=1;i<=nv;i++) uf[i]=i;
}

bool kruskal{
	sort(ed,ed+ne);
	int cnt=0,mst=0;
	for(int i=0;i<ne;i++){
		int fa=find(ed[i].fr),fb=(ed[i].to);
		if(fa!=fb){
			uf[fa]=fb;
			mst[cnt++]=i;
			mst+=ed[i].w;
		}
	}
	if(cnt==nv) return true;
}

int main(int argc, char const *argv[])
{	
	return 0;
}

