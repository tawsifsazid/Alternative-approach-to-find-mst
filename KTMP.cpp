/**
	* Author   : Muhammad Tawsif Sazid
	* Military Institute and Science and Technology
	*
	*
**/

#include <bits/stdc++.h>
#define pii acos(-1)
#define ll long long
#define pare pair<int,int>
#define eps 1e-9
#define max 60006
#define read(type) readInt<type>()


/****** Template of some basic operations *****/

template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

/**********************************************/

using namespace std;



int n,parent[300005],edge_nisi = 0,final_ans = 0,m,cl_kore_dao;

struct node {
    int cost, u, v , id;

    bool operator < (const node& a )const{
        return cost > a.cost;
    }
};

priority_queue< node , vector < node > > Q[400005];
vector<node>temp;


void init(){
    int i,j,k;
    for(i=0;i<=200000;i++){
        parent[i] = i;
    }
    edge_nisi = 0;
    final_ans = 0;

    for(i = 0; i<400000; i++){
        while(!Q[i].empty()){
            Q[i].pop();
        }
    }


    temp.clear();
}

int fnd(int r){
    if(r == parent[r])return r;
    else{
        parent[r] = fnd(parent[r]);
        return parent[r];
    }
}
void print_queue(int index){
    cout<<"Printing Queue"<<endl;
    while(!Q[index].empty()){
        node aa = Q[index].top();
        cout<<aa.u<<" "<<aa.v<<" "<<aa.cost<<endl;
        Q[index].pop();
    }
    cout<<endl<<endl;

}
void check_merge(int num){
    ///print_queue(number);

    int number = fnd(num);
   
    node ext = Q[number].top();

    int fixed1,fixed2,lel;
    fixed1 = ext.u;
    fixed2 = ext.v;
    lel = ext.cost;
    ///cout<<fixed1<<" "<<fixed2<<" "<<lel<<endl;


    while(!Q[number].empty()){
        ext = Q[number].top();
        Q[number].pop();
        if(fixed1 == ext.u && fixed2 == ext.v ){}
        else{
            ///cout<<"thaktese"<<ext.u<<" "<<ext.v<<" "<<ext.cost<<endl;
            temp.push_back(ext);
        }
    }
    int arekjon = fnd(fixed2);
    ///cout<<" 2nd node "<<arekjon<<endl;

    while(!Q[arekjon].empty()){
        ext = Q[arekjon].top();
        ///cout<<"testing "<<ext.u<<" "<<ext.v<<" "<<ext.cost<<endl;
        Q[arekjon].pop();
        if((fixed2 == ext.u && fixed1 == ext.v) || (fixed1 == ext.u && fixed2 == ext.v) ){}
        else{
            ///cout<<"thaktese "<<ext.u<<" "<<ext.v<<" "<<ext.cost<<endl;
            temp.push_back(ext);
        }
    }
    
     if(number != arekjon){
            final_ans = final_ans + lel;
            edge_nisi++;
            parent[arekjon] = number;
     }
    for(int i=0;i<temp.size();i++){
        Q[number].push(temp[i]);
    }
    ///print_queue(number);
    cl_kore_dao = number;
    temp.clear();

}

void KTMP(){
    int i,j,k;
    while(1){
       if(edge_nisi == n-1)break;
       /// cout<<"new turn"<<endl;
        for(i = 0;i<n; i++){
            if(edge_nisi == n-1)break;
                check_merge(i);
        }
 
    }
}

int main(){
    clock_t tStart = clock();
   
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i,j,k,a,b,cst,ch = 0;

    while(cin>>n>>m){
        if(n == 0 && m == 0)break;
        init();
        k = 0;
        ///ch++;
        for(i=0;i<m;i++){
            cin>>a>>b>>cst;
            k = k + cst;
            node lol;
            lol.u = a;
            lol.v = b;
            lol.cost = cst;
            ///E[a].push_back(lol);
            Q[a].push(lol);
            lol.u = b;
            lol.v = a;
            lol.cost = cst;
            Q[b].push(lol);
            ///E[b].push_back(lol);
        }

        KTMP();
        cout<<final_ans<<endl;
       
    }
    ///printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
