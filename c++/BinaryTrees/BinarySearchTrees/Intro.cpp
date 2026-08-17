#include <iostream>
#include <vector>
#include <queue>


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

class BST{
    public :
    Node* root;
    
    BST(){
        root = nullptr;
    }

    Node* insert(Node* root , int data){
        
        if(root == nullptr){
            Node* newNode = new Node(data);
            return newNode;
        }

        if(data > root->data){
            root->right = insert(root->right , data);
        }else{
            root->left = insert(root->left , data);
        }
    }

    Node* insertIntoBst(Node* root , int item){
        Node* newNode = new Node(item);

        if(root == nullptr){
            return newNode;
        }

        Node* cur = root;
        Node* prev = nullptr ;



        while(cur !=nullptr){
            prev = cur;
            if(item < cur->data){
                cur = cur->left;
            }else{
                cur = cur->right;
            }

        }

        if(prev->data > item ){
            prev->left = newNode;
        }else{
            prev->right = newNode;
        }
        return root;    
    }


    void Inorder(Node* root){
        if(root == nullptr){
            return ;
        }

        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }

    Node* findInorderSucessor(Node* root){
        Node* curr = root;

        while(curr != nullptr && curr->left != nullptr){
            curr = curr->left;
        }   

        return curr;    

    }

    // https://chatgpt.com/c/6a82c23e-6aa4-83ee-8e5b-e2983f02d3a6

    Node* deleteANode(Node *const root , int data){

        if(root == nullptr){
            return nullptr;
        }

        if(data > root->data){
            root->right = deleteANode(root->right , data);
        }else if(data < root->data){
            root->left = deleteANode(root->left , data);
        }else{
            // case 1 : no child 
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }
            // case 2 : one child 
            else if(root->left == nullptr){
                Node* temp = root->right;
                delete root;
                return temp;
            }else if(root->right == nullptr){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // case 3 : two children 
            else{
                Node* temp = findInorderSucessor(root->right);
                root->data = temp->data;
                root->right = deleteANode(root->right , temp->data);
            }
        }
        return root;    
    }

    bool searchInBST(Node* root , int item){
        if(root == nullptr){
            return false;
        }

        Node* curr = root;

        while(curr != nullptr){
            if(item == curr->data){
                return true;
            }else if(item < curr->data){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }

        return false;

    }

    void levelOrderTraversal(Node*root){

        queue<Node*> q;
        q.push(root);
        q.push(nullptr);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            if(curr != nullptr){
                cout << curr->data << " ";

                if(curr->left != nullptr){
                    q.push(curr->left);
                }

                if(curr->right != nullptr){
                    q.push(curr->right);
                }
            }else{
                cout << endl;
                if(!q.empty()){
                    q.push(nullptr);
                }
            }
        }   
    }
};

int main() {
    BST b;
    vector<int> bstnodes = {1 , 4 , 7 , 2 , 12 , 9};
    for(int i = 0 ; i<bstnodes.size() ; i++){
        b.root = b.insertIntoBst(b.root , bstnodes[i]);
    }

    b.Inorder(b.root);

    cout << endl;

    b.levelOrderTraversal(b.root);

    b.deleteANode(b.root , 4);

    cout << endl;
    b.levelOrderTraversal(b.root);

    cout << b.searchInBST(b.root , 12) << endl;
    cout << b.searchInBST(b.root , 121);
}

// https://chatgpt.com/c/6a82f0c2-e340-83ee-9db6-5ce56f24d7a9