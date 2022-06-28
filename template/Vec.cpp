#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



struct Node
{
	int a,b;
	Node(){}
	Node(int _a,int _b):a(_a),b(_b){}
};


static bool cmp(const pair<int,string>&a, const pair<int,string>&b){
    return a.first>=b.first;
}

int main()
{
    vector<Node> vec2;
    vector<int> vec = {3, 5, 4, 17, 2};
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(4);
	vec.push_back(17);
	vec.push_back(2);
	vec.reserve(100);
	cout<<vec.size()<<" "<<vec.capacity()<<endl<<endl;

   
	
	cout<<vec.size()<<endl;
	
	for(int i=0;i<vec.size();i++)
		cout<<vec[i]<<" ";
	cout<<endl;
	
	sort(vec.begin(),vec.end());

	for(int i:vec)
		cout<<i<<" ";
	cout<<endl;

	vec2.emplace(vec2.end(),1,3);
	vec2.emplace_back(4,2);

	for(auto i:vec2)
		cout<<i.a<<" "<<i.b<<endl;

	vec.clear();
	vec.assign(10,26);
	for(int i:vec)
		cout<<i<<" ";
	cout<<endl;

	vec.clear();
	for(int i=0;i<10;i++)
		vec.push_back(i);
	for(int i:vec)
		cout<<i<<" ";
	cout<<endl;
	vec.erase(vec.begin()+2,vec.end()-3);
	for(int i:vec)
		cout<<i<<" ";
	cout<<endl;

    vector<pair<int,string>> list ={{1,"2"},{3,"2"},{6,"2"}};
    
    sort(list.begin(),list.end(),cmp);
    
    for(auto [m,n]:list) cout<<m<<" "<<n<<endl;
    
	return 0;
}