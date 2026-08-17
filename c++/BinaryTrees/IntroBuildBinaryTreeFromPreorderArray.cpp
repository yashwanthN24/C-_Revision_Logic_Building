#include <iostream>
#include <vector>
#include <queue>
#include <map>


using namespace std;


class Node{

    public:
    int data;
    Node* left;
    Node* right;

     Node(int data){
        this->data = data;
        left = right = nullptr;
    }

};

class BinaryTree{

    int idx ;
    
    public :
    
    Node* root;
    BinaryTree(){
        root = nullptr;
        idx = -1;;
    }

    ~BinaryTree(){
        destroy(root);
    }

    void destroy(Node* root) {
    if (root == nullptr)
        return;

    destroy(root->left);
    destroy(root->right);
    delete root;
   }

    Node* buildTree(vector<int> preorderArray){
        idx++;
        if(idx >= preorderArray.size() || preorderArray[idx] == -1){
            return nullptr;
        }
        
        Node* newNode = new Node(preorderArray[idx]);
        newNode->left = buildTree(preorderArray );
        newNode->right = buildTree(preorderArray);   

        return newNode;

        
    }

    void preOrder(Node* root){
        if(root == nullptr){
            return ;
        }

        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }   

    void InOrder(Node* root){
        if(root == nullptr){
            return ;
        }

        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }

    void PostOrder(Node* root){
        if(root == nullptr){
            return ;
        }

        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << " ";
    }

    void levelOrder(Node* root){
        if(root == NULL){
            return ;
        }

        // create a queue 
        queue<Node*> q;

        q.push(root);
        q.push(nullptr);    

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            if(curr != nullptr){
                cout << curr->data << " ";

                if(curr->left != nullptr)
                    q.push(curr->left);
                if(curr->right != nullptr)
                    q.push(curr->right);

                
            }else{
                cout << endl;

                if(!q.empty()){
                    q.push(nullptr);
                }
                // because fpr ;ast level after removing null we will have empty queue meaning we processsed all levels so we dont need to push null again as we will exit the loop after this iteration as queue is empty

            }
            

            
        }
    }

    int heightOfTree(Node* root){
        if(root == nullptr){
            return 0;
        }

        int leftHeight = heightOfTree(root->left);
        int rightHeight = heightOfTree(root->right);
 
        return max(leftHeight , rightHeight) + 1;
    }

    int heightOfTreeViaLevelOrder(Node* root){
        if(root == nullptr){
            return 0;
        }

        queue<Node*> q;
        q.push(root);
        q.push(nullptr);

        int height = 0;

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            if(curr != nullptr){
                if(curr->left != nullptr)
                    q.push(curr->left);
                if(curr->right != nullptr)
                    q.push(curr->right);
            }else{
                height++;

                if(!q.empty()){
                    q.push(nullptr);
                }
            }
        }

        return height;
    }   

    int countOfNodes(Node* root){
        if(root == nullptr){
            return 0;
        }

        int leftCount = countOfNodes(root->left);
        int rightCount = countOfNodes(root->right);

        return leftCount + rightCount + 1;
    }   

    int sumOfNodes(Node* root){
        if(root == nullptr){
            return 0;
        }

        int leftSum = sumOfNodes(root->left);
        int rightSum = sumOfNodes(root->right);

        return leftSum + rightSum + root->data;
    }

    int diameterOfTree(Node* root){
        if(root == nullptr){
            return 0;
        }

        // when diamter includes root calculate height passing through root
        int curDiameter = heightOfTree(root->left) + heightOfTree(root->right) + 1;
        
        // find diameter in left and right subtrees 
        // o(n^2) time complexity as heightOfTree is called for each node and it takes O(n) time to calculate height of tree
        int leftDiameter = diameterOfTree(root->left);
        int rightDiameter = diameterOfTree(root->right);

        return max(curDiameter, max(leftDiameter, rightDiameter));
    }

    pair<int , int> diameterOfTreeOptimized(Node* root){
        if(root == nullptr){
            // return {0, 0}; // height , diameter

            // or 
            return make_pair(0, 0); // height , diameter
        }

        // (LH , LD ) , (RH , RD) 
        pair<int , int> leftInfo = diameterOfTreeOptimized(root->left);
        pair<int , int> rightInfo = diameterOfTreeOptimized(root->right);


        int curHeight = max(leftInfo.first, rightInfo.first) + 1;
        int curDiameter = leftInfo.first + rightInfo.first + 1;
        int overallDiameter = max(curDiameter, max(leftInfo.second, rightInfo.second));

        // here we are doing height calcuation in the same recursive calls for claculkating leftdiametr and rightdiamert this way we get both infor and henc in n calls both info we get so O(n) time complexity as we are not calling heightOfTree for each node which takes O(n) time for each node so overall O(n^2) time complexity

        // return {curHeight, overallDiameter}; 

        // or 

        return make_pair(curHeight, overallDiameter);
    }

    bool isIdentical(Node* node , Node* subRoot){
        if(node == nullptr && subRoot == nullptr){
            return true;
        }else if(node == nullptr || subRoot == nullptr || node->data != subRoot->data){
            return false;
        }



        return isIdentical(node->left, subRoot->left) && isIdentical(node->right, subRoot->right);
    }

    bool isSubtree(Node* root, Node* subRoot){
        if(root == nullptr){
            return false;
        }
        
        if(root->data == subRoot->data && isIdentical(root, subRoot)){
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    void topViewOfABinaryTree(Node* root){
        if(root == nullptr){
            return ;
        }

        // create a queue to do level order traversal
        queue<pair<Node*, int>> q; // pair of node and its horizontal distance from root
        q.push({root, 0});

        // create a map to store the first node at each horizontal distance
        map<int, int> m; // map of horizontal distance and node data

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            Node* curr = p.first;
            int hd = p.second;

            // if this is the first node at this horizontal distance, add it to the map
            if(m.find(hd) == m.end()){
                m[hd] = curr->data;
            }

            // push left and right children with updated horizontal distances
            if(curr->left != nullptr){
                q.push({curr->left, hd - 1});
            }
            if(curr->right != nullptr){
                q.push({curr->right, hd + 1});
            }
        }

        // print the top view from the map
        for(auto it : m){
            cout << it.second << " ";
        }
        cout << endl;

        //  works because map sorts the keys in ascending order by default so we get the top view from left to right 
        //  so unlike java  no need to track min and max horizontal distanc to start printing from min to max horizontal distance as map sorts the keys in ascending order by default so we get the top view from left to right
    }   
    void bottomViewOfABinaryTree(Node* root){
        if(root == nullptr){
            return ;
        }

        // create a queue to do level order traversal
        queue<pair<Node*, int>> q; // pair of node and its horizontal distance from root
        q.push({root, 0});

        // create a map to store the first node at each horizontal distance
        map<int, int> m; // map of horizontal distance and node data

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            Node* curr = p.first;
            int hd = p.second;

            // if this is the first node at this horizontal distance, add it to the map
           
                m[hd] = curr->data;
            

            // push left and right children with updated horizontal distances
            if(curr->left != nullptr){
                q.push({curr->left, hd - 1});
            }
            if(curr->right != nullptr){
                q.push({curr->right, hd + 1});
            }
        }

        // print the top view from the map
        for(auto it : m){
            cout << it.second << " ";
        }
        cout << endl;

        //  works because map sorts the keys in ascending order by default so we get the top view from left to right 
        //  so unlike java  no need to track min and max horizontal distanc to start printing from min to max horizontal distance as map sorts the keys in ascending order by default so we get the top view from left to right
    }   

    // https://chatgpt.com/c/6a814da0-4c10-83ee-92b5-aba0c827fc39

    void KthLevelHelper(Node* root , int k , int level){
        if(root == nullptr){
            return ;
        }

        if(level == k){
            cout << root->data << " ";
            return ;
        }

        KthLevelHelper(root->left , k , level + 1);
        KthLevelHelper(root->right , k , level + 1);
    }

    void KthLevelofaTree(Node* root , int k ){
        KthLevelHelper(root , k , 1);
        cout << endl;
    }

    void KthLevel(Node* root , int k){

        // create a queue 
        queue<Node*> q; 

        q.push(root);
        q.push(nullptr);
        int level = 1;

        while(!q.empty()){
            Node *curr = q.front();
            q.pop();

            if(curr != nullptr){
                if(level == k){
                    cout << curr->data << " ";
                }
                if(curr->left != nullptr)
                    q.push(curr->left);
                if(curr->right != nullptr)
                    q.push(curr->right);
            }else{
                level++;
                if(!q.empty()){
                    q.push(nullptr);
                }
            }
        }
    }

    Node* InvertBinaryTree(Node* root){
        if(root == nullptr){
            return nullptr;
        }

        // Swap the left and right children
        Node* left = InvertBinaryTree(root->left);
        Node* right = InvertBinaryTree(root->right);

        root->left = right;
        root->right = left;
        return root;
    }

    int transformSumTree(Node*root){
        if (root == nullptr) {
            return 0;
        }

        int leftchild = transformSumTree(root->left);
        int rightchild = transformSumTree(root->right);

        int data = root->data;
        int newLeft = (root->left != 0 ? root->left->data : 0);
        int newRight = (root->right !=0? root->right->data : 0);

        root->data = newLeft + newRight + leftchild + rightchild;
        return data;

    }

    void PrintLevelWiseSumOfTree(Node* root){
        if(root == nullptr){
            return ;
        }

        queue<Node*> q;
        q.push(root);
        q.push(nullptr);

        int sum = 0;

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            if(curr != nullptr){
                sum += curr->data;

                if(curr->left != nullptr)
                    q.push(curr->left);
                if(curr->right != nullptr)
                    q.push(curr->right);
            }else{
                cout << sum << endl;
                sum = 0;

                if(!q.empty()){
                    q.push(nullptr);
                }
            }
        }
    }   

};


int main(){
    BinaryTree bt;

    // vector<int> preorderArray = {1, 2, 4, -1 , -1 , 5, -1 , -1  ,  6 , 7 , -1 , -1 , 8 , -1 , -1};
    vector<int> preorderArray = {1, 2, 4, -1 , -1 , 5, -1 , 6 , -1 , 7 , -1 , -1 , 3 , -1 , -1};
    int size = sizeof(preorderArray)/sizeof(preorderArray[0]);
    cout << sizeof(preorderArray) << endl;
    cout << sizeof(preorderArray[0]) << endl;
    cout << preorderArray.size() << endl;
    cout << preorderArray.capacity() << endl;
    cout << "Size of preorderArray: " << size << endl;
    bt.root = bt.buildTree(preorderArray);

    cout << bt.root->data << endl;
    cout << bt.root->left->data << endl;
    cout << bt.root->right->data << endl;
    bt.preOrder(bt.root);
    cout << endl;
    bt.InOrder(bt.root);

    cout << endl;

    bt.PostOrder(bt.root);

    cout << endl;
    bt.levelOrder(bt.root);
    cout << "Height of the tree: " << bt.heightOfTree(bt.root) << endl;

    cout << "Level wise sum of the tree: " << endl;
    bt.PrintLevelWiseSumOfTree(bt.root);

    cout << endl;

    cout << "Height of the tree via level order: " << bt.heightOfTreeViaLevelOrder(bt.root) << endl;

    cout << "Count of nodes in the tree: " << bt.countOfNodes(bt.root) << endl; 

    Node* root2 = new Node(5);
    root2->left = new Node(3);
    root2->right = new Node(7);

    cout << "Count of nodes in root2: " << bt.countOfNodes(root2) << endl;

    cout << "Height of root2: " << bt.heightOfTree(root2) << endl;

    bt.levelOrder(root2);

    cout << "Sum of nodes in root2: " << bt.sumOfNodes(root2) << endl;

    Node* root3 = new Node(1);
    root3->left = new Node(2);
    root3->right = new Node(3);
    root3->left->left = new Node(4);
    root3->right->right = nullptr;
    root3->right->left = nullptr;
    root3->left->right = new Node(5);
    root3->left->right->left = nullptr;
    root3->left->right->right = new Node(6);;
    root3->left->right->left = nullptr;;
    root3->left->right->right->right = new Node(7);
    root3->left->right->right->left = nullptr;
    root3->left->right->right->right->left = nullptr;
    root3->left->right->right->right->right = nullptr;

    cout << bt.diameterOfTreeOptimized(root3).first << endl;

    bt.topViewOfABinaryTree(root3);

    bt.bottomViewOfABinaryTree(root3);

    bt.KthLevelofaTree(root3 , 3);

    bt.KthLevel(root3 , 3);
    cout << endl;

    // Node* newRoot = bt.InvertBinaryTree(bt.root);

    // bt.levelOrder(newRoot);

    bt.transformSumTree(bt.root );

    cout << endl ;
    cout << endl ;
    bt.levelOrder(bt.root);


}