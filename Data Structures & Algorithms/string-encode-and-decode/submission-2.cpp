class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        string indexs ="";
        int curridx =0;
        for (const string& s : strs) {
            encoded += s;
            indexs +=to_string(curridx)+"#";
            curridx = encoded.size();
        }
        string ans = indexs+","+encoded;
        cout<<ans<<" "<<endl;
        return ans;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        stringstream ss(s);
        string index;
        getline(ss,index,',');
        int indexsize = index.size();
        string rest = s.substr(indexsize+1);
        stringstream ss2(index);
        vector<int>indexs;
        string temp;
         while(getline(ss2,temp,'#')) {
            indexs.push_back(stoi(temp));
         }
        for(int i=0;i<indexs.size();i++) {
            int curridx = indexs[i];
            if(i==indexs.size()-1) {
                ans.push_back(rest.substr(curridx));
            } else {
                int ni = indexs[i+1];
                ans.push_back(rest.substr(curridx,ni-curridx));
            }
        }
       
        return ans;
    }
};
