https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118800/offering/1381354?leftPanelTab=0

Approach-1
  
//recursio + memoisatioN
  
  
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<string> helper(string &s, int idx, unordered_set<string> &set, unordered_map<int, vector<string>> &dp,  int size){
    //base case
    if(idx==size){
        return {""};
    }
    
    string word="";
    
    
       // Already has a solution for the current sentence, simply return the solution.
    if (dp.find(idx) != dp.end())
    {
        return dp[idx];
    }
    
    
    vector<string> subpart, completepart;
    for(int j=idx; j<size; j++){
        word.push_back(s[j]);
        if(set.count(word)==0){
            continue;
        }
        
        subpart = helper(s, j+1, set, dp, size);
        for(int i=0; i<subpart.size(); i++){
            if(subpart[i].size()!=0){
                string temp = word;
                temp.append(" ");
                temp.append(subpart[i]);
                subpart[i] = temp;
            }
            else{
                subpart[i] = word;
            }
        }
        
        for(int i=0; i<subpart.size(); i++){
            completepart.push_back(subpart[i]);
        }
    }
    dp[idx] = completepart;

    return dp[idx];
    
}


vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    unordered_map<int, vector<string>> dp;
    
   unordered_set<string>set;
   for(int i=0; i<dictionary.size(); i++){
       set.insert(dictionary[i]);
   }
   
   return helper(s, 0, set,dp, s.size());

}





Approach-2
//using trie



class trieNode
{
    public:
    trieNode*children[26];
    bool isterminal;
    
    trieNode(){
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        this->isterminal = false;
    }
};

void insert(trieNode*root, string word){
    trieNode*curr = root;
    for(int i=0; i<word.size(); i++){
        if(curr->children[word[i]-'a']==NULL){
            curr->children[word[i]-'a'] = new trieNode();
        }
        curr = curr->children[word[i]-'a'];
    }
    curr->isterminal = true;
    
}


void search(trieNode*root, string &s, vector<string>&res, string temp, int pos){
    trieNode*curr = root;
    for(int i=pos; i<s.size(); i++){
        if(curr->children[s[i]-'a']==NULL){
            return;
        }
        if(curr->children[s[i]-'a']->isterminal == true){
            string lastword = temp;
            lastword.append(s.substr(pos,i-pos+1));
            
            if(i==s.size()-1){
                res.push_back(lastword);
            }
            else{
                search(root,s,res, lastword+" ", i+1);
            }
        }
        curr = curr->children[s[i]-'a'];
    }
    return;
}

vector<string> wordBreak(string&s, vector<string>&dictionary){
    trieNode*root = new trieNode();
    
    for(int i=0; i<dictionary.size(); i++){
        insert(root, dictionary[i]);
    }
    
    vector<string>res;
    search(root, s, res, "", 0);
    return res;
}
























