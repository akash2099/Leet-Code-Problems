#define ppi pair<int,int>
static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

// bool sortbysecdesc(const pair<int,int> &a, const pair<int,int> &b){
//     return a.second>b.second;
// }

void sort_vector_pair(vector<ppi>&ar){
    priority_queue <ppi, vector<ppi>, greater<ppi>> minHeap;
    
    for(int i=0;i<ar.size();++i){
        minHeap.push(ar[i]);
    }
    
    for(int i=0;i<ar.size();++i){
        ar[i]=make_pair(minHeap.top().first,-minHeap.top().second);
        minHeap.pop();
    }
}

// void sort_vector_pair_desc(vector<ppi>&ar){
//     priority_queue <ppi> maxHeap;
    
//     for(int i=0;i<ar.size();++i){
//         maxHeap.push(make_pair(ar[i].second,ar[i].first));
//     }
    
//     for(int i=0;i<ar.size();++i){
//         ar[i]=make_pair(maxHeap.top().second,maxHeap.top().first);
//         maxHeap.pop();
//     }
// }


class Solution {

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // O(nlogn)
        int n=people.size();
        
        vector<pair<int,int>>pep;
        for(int i=0;i<n;++i){
            pep.push_back(make_pair(people[i][0],-people[i][1]));
        }
        
	    // sort(pep.begin(), pep.end());
        // sort_vector_pair_desc(pep);

        sort_vector_pair(pep);
        
        // for(int i=0;i<n;++i)
        //     cout<<pep[i].first<<" "<<pep[i].second<<endl;
        // cout<<endl;
                    
        vector<pair<int,ppi>>v(n);
        
        for(int i=0;i<n;++i){
            v[i]=make_pair(i,make_pair(0,0));
        }

        for(int i=0;i<n;++i){
            
            // cout<<pep[i].first<<" "<<pep[i].second<<endl;
            
            vector<int>temp{pep[i].first,pep[i].second}; // create the answer vector
            
            people[v[pep[i].second].first]=temp;// save the answer 
            
            v.erase(v.begin()+pep[i].second); // erase the vector which is already allcoated
            
            // for(int j=0;j<people.size();++j){
            //     for(int k=0;k<people[0].size();++k)
            //         cout<<people[j][k]<<",";
            //     cout<<" ";
            // }
            // cout<<endl;
        }
        
        return people;   
    }
};
