int C[100],col[100],l1[100],l2[100];
int n,ans;
void dfs(int cur){
	if(cur==n) ans++;
	else{
		for(int i=0;i<n;i++){
			
			if(!col[i]&&!l1[cur+i]&&!l2[cur-i+n]){
				C[cur]=i;
				col[i]=l1[cur+i]=l2[cur-i+n]=1;
				dfs(cur+1);
				col[i]=l1[cur+i]=l2[cur-i+n]=0;
			}
		}
	}

int int main(int argc, char const *argv[])
{
	memset(C,0,sizeof(C));
	memset(col,0,sizeof(col));
	memset(l1,0,sizeof(l1));
	memset(l2,0,sizeof(l2));
	cin>>n;ans=0;
	dfs(0);
	cout<<ans;

	return 0;
}