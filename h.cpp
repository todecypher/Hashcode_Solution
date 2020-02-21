#include"bits/stdc++.h"
using namespace std;
#define in freopen("f_libraries_of_the_world.txt","r",stdin);
#define out freopen("f_libraries_of_the_world_out.txt","w",stdout);
#define io in out 
using ll = long long;
//a_example
//b_read_on
//c_incunabula
//d_tough_choices
//e_so_many_books
//f_libraries_of_the_world


ll n_library , n_books, n_days;
vector<ll> books_score;


class library{
	public : 
		ll lib_id;
		ll signup_time ; //time it takes to signup
		ll rate ; // shipping rate
		ll n_book ; //no of books in library;
		vector<ll> books;


		// ans  cordinates 
		vector<ll> processed;


	void arrange(){
		sort(books.begin() , books.end() , [&](ll a , ll b)
			{ return books_score[a] > books_score[b] ;});
	}
};
ll maxi(vector<ll>& v){
	ll m1 = 0 ;
	for(int i = 0;  i< v.size();i++) m1+= books_score[v[i]];

	return m1;

}
bool comp(library& a , library& b){
	if(a.signup_time == b.signup_time){
		if(a.rate == b.rate) {
			if(maxi(a.books) == maxi(b.books)) {
					return 1;
				}
			else
				return maxi(a.books) < maxi(b.books);
			
		}
		else{
			return a.rate > b.rate;
		}

	}
	else return a.signup_time<b.signup_time;
}

int main(){
	#ifndef ONLINE_JUDGE
	io
	#endif

	
	cin>>n_books>>n_library>>n_days;

	ll x;
	for(int i = 0;i<n_books;i++) cin>>x , books_score.push_back(x);

	library L[n_library];	
	for(int i =0; i<n_library;i++) {
		cin>>L[i].n_book>>L[i].signup_time>>L[i].rate;
		L[i].lib_id = i;
			for(int j=0 ;j<L[i].n_book;j++) cin>>x , L[i].books.push_back(x);
	}	
	
	sort(L, L+n_library , comp);

	for (int i = 0; i < n_library; ++i)
	{
		L[i].arrange();
	}

	ll ct =0 ;
	for(int i =0 ; i<n_library ;i++){
		// cout<<"ID: " << L[i].lib_id<<endl; 
		// cout<<"SIGNUP TIEM : "<<L[i].signup_time<<endl;
		// cout<<"RATE : "<<L[i].rate<<endl;
		// cout<<"BOOKS : ";
		// 	for(auto j: L[i].books) {
		// 		cout<<j<<" "<<books_score[j]<<endl;
		// 	}
		// 	cout<<endl;
		if(n_days >= L[i].signup_time){
			n_days -= L[i].signup_time;
			ll x = n_days * L[i].rate ; 
			x = min(x , L[i].n_book);
			for(int j =0;j<x;j++){
				L[i].processed.push_back(L[i].books[j]);
			}
			ct++;
			
		}
		else{
			break;
		}
	}

	cout<<ct<<endl;
	for(int i= 0 ;i<ct;i++){
		cout<<L[i].lib_id<<" "<<L[i].processed.size()<<endl;
		for(auto j : L[i].processed){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	
}	