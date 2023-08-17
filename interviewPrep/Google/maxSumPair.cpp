class MapSum {
public:

    struct Node
    {
        Node *link[26];
        bool flag = false;
        int val = 0;
    };

    Node *root;
    int summed =  0;

    MapSum() {
        unordered_map<string, int> m;
        root = new Node();
    }
    
    void insert(string key, int value) {
        Node *trav = root;
        for(int i=0; i<key.size(); i++){
            if(trav->link[key[i]-'a'] == NULL){
                trav->flag = true;
                trav->link[key[i]-'a'] = new Node();
            }
            trav = trav->link[key[i]-'a']; 
        }
        trav->val = value;
    }

    void dfs(Node *trav){
        if(trav == NULL) return;
        if(trav->flag == false){
            summed += trav->val;
            return;
        }

        summed += trav->val;

        for(int i=0; i<26; i++){
            if(trav->link[i] != NULL) dfs(trav->link[i]);
        }
    }
    
    int sum(string prefix) {
        Node *trav = root;
        for(int i=0; i<prefix.size(); i++){
            if(trav->link[prefix[i]-'a'] != NULL){
                trav = trav->link[prefix[i]-'a'];
            }
            else{
                return 0;
            }
        }
        summed = 0;
        dfs(trav);
        return summed;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */