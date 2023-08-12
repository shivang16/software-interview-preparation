class Solution {
public:
    // Cookable maps if the recipe is achievable by either cooking or supplies
unordered_map<string,bool> cookable;
// adj is the adjancy matrix for the recipies->ingredients
unordered_map<string, vector<string>> adj;
// visited map for checking if we have already visited that ingredient/recipe
unordered_map<string,bool> visited;

// DFS function
bool dfs(string node)
{
    // if we have aready processed a recipe/ingredient return its cookable
    if(visited[node]) return cookable[node];
    
    visited[node]= true;
    
    // if the recipe/ingredient can be prepared/ in supplies return its cookable
    if(cookable.find(node)!=cookable.end())
        return cookable[node];
    
    // if the recipe/ingredient cant be prepared and if it isn't dependant on any other
    // recipe/ingredient, we cant prepare that dish.
    if(adj[node].size()==0) 
        return cookable[node]=false; 
    
    //traverse all the ingredients for that dish
    for(auto i: adj[node])
        
        // if any ingredient cant be prepared we cant cook the dish
        if(!dfs(i))
             return cookable[node]=false;
    
    //if none of the above condition satisfied we can cook the dish
    return cookable[node]=true;
}
vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
   
    int n=recipes.size();
    
    for(int i=0;i<n;i++)
        for(auto j: ingredients[i])
            adj[recipes[i]].push_back(j);
    
    // mark the supplies as cookable
    for(auto i:supplies) 
        cookable[i]=true;
    
    vector<string> ans;
    for(int i=0;i<n;i++)
    // if any recipe is cookable we insert it into our ans vector
        if(dfs(recipes[i])) 
            ans.push_back(recipes[i]);
    return ans;
}
};