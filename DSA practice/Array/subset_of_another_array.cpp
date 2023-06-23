// approach 1
string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, int> mp;
    for(int i=0; i<m; i++){
        mp[a2[i]]++;
    }
    for(int i=0; i<n; i++){
        if(mp.find(a1[i])!=mp.end()){
            mp[a1[i]]--;
        }
    }
    // for (auto i : mp){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    
    for(auto i:mp){
        if(i.second>0){
            return "No";
        }
    }
    return "Yes";
}

// approach 2
string isSubset(int a1[], int a2[], int n, int m) {
    sort(a1, a1+n);
    sort(a2, a2+m);
    int i=0, j=0;
    while(i<n && j<m){
        if(a1[i]==a2[j]){
            j++;
        }
        i++;
    }
    if(j==m){
        return "Yes";
    }
    return "No";
}