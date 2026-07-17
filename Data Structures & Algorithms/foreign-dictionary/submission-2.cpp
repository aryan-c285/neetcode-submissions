class Solution {
   private:
    vector<int> toposort(vector<unordered_set<int>> &adj, vector<bool> &present) {
        int n = adj.size();
        vector<int> indegree(n);
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) indegree[it]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (present[i] && indegree[i] == 0) q.push(i);
        }

        vector<int> top;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            top.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (present[it] && indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return top;
    }

   public:
    string foreignDictionary(vector<string>& words) {
        string ans = "";
        vector<unordered_set<int>> adj(26);
        vector<bool> present(26, false);
        for (auto& it : words) {
            for (char c : it) {
                present[c - 'a'] = true;
            }
        }
        for (int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.size(), s2.size());
            bool found = false;


            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].insert(s2[j] - 'a');
                    found = true;
                    break;
                }
            }
            if (!found && s1.size() > s2.size()) return ans;
        }

        vector<int> topo = toposort(adj, present);
            int c = 0;
            for (bool x: present){
                if(x) c++;
            }
            if (c!= topo.size()) return ans;
            for (auto it : topo) {
            if (present[it]) ans += char(it + 'a');
        }
        return ans;
    }
};