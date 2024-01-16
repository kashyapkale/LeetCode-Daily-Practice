class Solution {
private:
    unordered_map<string, vector<string>> createMap(unordered_set<string> &wordSet){
        unordered_map<string, vector<string>> adj;
        for (const auto& word : wordSet) {
            int len = word.length();
            for(int i = 0; i < len; i++){
                for(char ch = 'a'; ch <= 'z'; ch++){
                    string temp = word;
                    temp[i] = ch;
                    if(temp != word && (wordSet.find(temp) != wordSet.end())){
                        adj[word].push_back(temp);
                    }
                }
            }
        }
        return adj;
    }

    int bfs(unordered_map<string, vector<string>> adj, 
        unordered_set<string> &wordSet, 
        unordered_map<string, bool> &visited,
        string beginWord,
        string endWord){


        queue<pair<string, int>> bfsQ;
        bfsQ.push(make_pair(beginWord, 1));

        while(!bfsQ.empty()){
            string top_word = bfsQ.front().first;
            int level = bfsQ.front().second;
            bfsQ.pop();
            visited[top_word] = true;
            if(top_word == endWord){
                return level;
            }

            for(string s : adj[top_word]){
                if(!visited[s]){
                    bfsQ.push(make_pair(s, level + 1));
                }
            }

        }


        return 0;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord){
            return 0;
        }

        unordered_map<string, bool> visited;
        unordered_set<string> wordSet;
        for(string s : wordList){
            visited[s] = false;
            wordSet.insert(s);
        }

        wordSet.insert(beginWord);
        visited[beginWord] = false;
        if(wordSet.find(endWord) == wordSet.end()){
            return 0;
        }

        return bfs(createMap(wordSet), wordSet, visited, beginWord, endWord);

    }
};