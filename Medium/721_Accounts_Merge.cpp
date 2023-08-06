class Solution {
   public:
    unordered_set<string> visited;
    unordered_map<string, vector<string>> AL;

    void DFS(vector<string>& merged_account, string& email) {
        visited.insert(email);
        merged_account.push_back(email);

        for (auto& v : AL[email]) {
            if (visited.find(v) == visited.end()) {
                DFS(merged_account, v);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for (vector<string>& account : accounts) {
            string email_1 = account[1];
            for (int i = 2; i < account.size(); i++) {
                string email = account[i];
                AL[email_1].push_back(email);
                AL[email].push_back(email_1);
            }
        }

        vector<vector<string>> merged_accounts;
        for (vector<string>& account : accounts) {
            string account_name = account[0];
            string email_1 = account[1];

            if (visited.find(email_1) == visited.end()) {
                vector<string> merged_account;
                merged_account.push_back(account_name);
                DFS(merged_account, email_1);
                sort(merged_account.begin() + 1, merged_account.end());
                merged_accounts.push_back(merged_account);
            }
        }

        return merged_accounts;
    }
};