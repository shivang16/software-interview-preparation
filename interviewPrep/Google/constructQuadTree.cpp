// https://leetcode.com/problems/construct-quad-tree/
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;bottomRight
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* constructQuad(vector <vector <int>> &grid,int r1,int r2,int c1,int c2){
        if(r1>r2 || c1 > c2) return NULL;
        if(r1==r2 && c1==c2){
            return new Node(grid[r1][c1],true,NULL,NULL,NULL,NULL);
        }
        int midr = (r1+r2)/2, midc = (c1+c2)/2;
        Node* topLeft = constructQuad(grid,r1,midr,c1,midc);
        Node* bottomLeft = constructQuad(grid,midr+1,r2,c1,midc);
        Node* topRight = constructQuad(grid,r1,midr,midc+1,c2);
        Node* bottomRight = constructQuad(grid,midr+1,r2,midc+1,c2);
        bool isLeaf = false;
        if(topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf){
            if(topLeft->val==topRight->val && topLeft->val == bottomLeft->val && topLeft->val == bottomRight->val)
                isLeaf = true;
        }
        if(isLeaf){
            return new Node(topLeft->val,isLeaf,NULL,NULL,NULL,NULL);
        }
        return new Node(topLeft->val,isLeaf,topLeft,topRight,bottomLeft,bottomRight);
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return constructQuad(grid,0,n-1,0,n-1);
    }
};