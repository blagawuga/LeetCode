class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> result;
        // create an empty vector of pairs
        vector<pair<string, string>> vec;
        
        if (logs.size() == 0)  
            return logs;
        
        map<string, string> map;
        vector<string> digitList;
        
        for (auto log: logs) {
            if (isdigit(log[log.size()-1]))
                digitList.push_back(log);
            else 
                vec.push_back(pair<string, string> (log.substr(0, log.find(" ")), log.substr(log.find(" ")+1)));
        }

        // sort the vector by increasing order of its pair's second value
        // if second value are equal, order by the pair's first value
        sort(vec.begin(), vec.end(),
                [](const pair<string,string>& l, const pair<string,string>& r) {
                    if (l.second != r.second)
                        return l.second < r.second;

                    return l.first < r.first;
                });
        
        // print the vector
        for (auto const &pair: vec) {
            string el = pair.first + " " + pair.second;
            result.push_back(el);
        }
        
        for (auto log: digitList) 
            result.push_back(log);
            
        return result;
    }
};