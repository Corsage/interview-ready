vector<vector<int>> groupSort(vector<int> arr) {
    vector<vector<int>> res;
    
    // Sort the array first.
    sort(arr.begin(), arr.end());
    
    // Sliding window.
    int count = 1;
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] == arr[i + 1]) { count++; }
        else {
            res.push_back(vector<int> {arr[i], count});
            count = 1;
        }
    }
    
    // Add the last value.
    res.push_back(vector<int> {arr[arr.size() -  1], count});
    
    // Sort the resultant array by frequency.
    sort(res.begin(), res.end(), [](vector<int> a, vector<int> b) {
        if (a[1] == b[1]) { return a[0] < b[0]; }
        return a[1] >= b[1]; 
    });
    
    return res;
}