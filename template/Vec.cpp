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
vector<Node> vec2;

int main()
{
	vec.reserve(100);
	cout<<vec.size()<<" "<<vec.capacity()<<endl<<endl;

    vector<int> vec = {3, 5, 4, 17, 2};
	
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

	return 0;
}