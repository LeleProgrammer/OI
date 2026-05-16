#include<map>
#include<set>
#include<iostream>
std::map<std::set<int>,bool>mp;
int main(){
	std::ios::sync_with_stdio(0);
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++){
		std::set<int>s;
		for(int j=1;j<=6;j++){
			int x;std::cin>>x;
			s.insert(x);
		}
		if(mp[s]){
			std::cout<<"Twin snowflakes found.";
			return 0;
		}else{
			mp[s]=true;
		}
	}
	std::cout<<"No two snowflakes are alike.";
} 