#include <iostream>
#include <queue>
#include <climits>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}

    void insert(int data) {
        if (root == nullptr) {
            root = new Node(data);
            return;
        }

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp->left == nullptr) {
                temp->left = new Node(data);
                break;
            } else {
                q.push(temp->left);
            }

            if (temp->right == nullptr) {
                temp->right = new Node(data);
                break;
            } else {
                q.push(temp->right);
            }
        }
    }

    void printInOrder() {
        printInOrderRec(root);
        std::cout << std::endl;
    }
    int getMaxNodeValue()
    {
        return getMaxValueRec(root);
    }
    int getHeight()
    {
        return getHeightRec(root);
    }
    int getNumberOfNodes()
    {
        int NoOfNodes = 0;
        getNumberOfNodeRec(root,NoOfNodes);
        return NoOfNodes;
    }
    int getNumberOfNodes2() {
        return getNumberOfNodesRec2(root);
    }
    bool isPerfect() {
        int depth = getHeightRec(root);
        return isPerfectRec(root, depth, 0);
    }
    int getNumberOfLeaves() {
        return getNumberOfLeavesRec(root);
    }
private:
    Node* root;

    void printInOrderRec(Node* node) {
        if (node == nullptr) {
            return;
        }

        printInOrderRec(node->left);
        std::cout << node->data << " ";
        printInOrderRec(node->right);
    }
    int getMaxValueRec(Node*root)
    {
        if(root==nullptr) return 0;
        int maxValue = root->data;
        int leftSide = getMaxValueRec(root->left);
        int rightSide = getMaxValueRec(root->right);
        if(leftSide > maxValue) maxValue =leftSide;
        if(rightSide > maxValue) maxValue =rightSide;
        return maxValue;
    }
    int getHeightRec(Node* root)
    {
        if(root == nullptr) return 0;
        int leftSide = getHeightRec(root->left);
        int rightSide = getHeightRec(root->right);
        return 1+std::max(leftSide , rightSide);
    }
    int getNumberOfNodeRec(Node*root , int& NoOfNodes)
    {
        if(root == nullptr) return 0;
        int leftSide = getNumberOfNodeRec(root->left , NoOfNodes);
        NoOfNodes++;
        int rightSide = getNumberOfNodeRec(root->right , NoOfNodes);
        return NoOfNodes;
        
    }
      int getNumberOfNodesRec2(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftCount = getNumberOfNodesRec2(node->left);
        int rightCount = getNumberOfNodesRec2(node->right);

        return 1 + leftCount + rightCount;
    }
    bool isPerfectRec(Node* node, int depth, int level) {
        // Base case: if the node is nullptr, it's perfect up to this point
        if (node == nullptr) {
            return true;
        }

        // If the current node is a leaf node
        if (node->left == nullptr && node->right == nullptr) {
            // If the current level is the last level
            if (level == depth - 1) {
                return true;
            }
            // If the current level is not the last level
            else {
                return false;
            }
        }

        // If the current node has only one child or both children
        if (node->left == nullptr || node->right == nullptr) {
            return false;
        }

        // Recursively check the left and right subtrees
        return isPerfectRec(node->left, depth, level + 1) &&
               isPerfectRec(node->right, depth, level + 1);
    }
    int getNumberOfLeavesRec(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        if (node->left == nullptr && node->right == nullptr) {
            return 1;
        }

        int leftLeaves = getNumberOfLeavesRec(node->left);
        int rightLeaves = getNumberOfLeavesRec(node->right);

        return leftLeaves + rightLeaves;
    }
};
int main() {
    BinaryTree tree;

    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);

    
    
    /*
                                                        1
                                             2                      3
                                      4             5        6              7

    
    
    
    */

    std::cout << "In-order traversal: ";
    tree.printInOrder(); // Output: 4 2 5 1 6 3 7
    std::cout<<tree.getMaxNodeValue()<<std::endl;
    std::cout<<tree.getHeight()<<std::endl;
    std::cout<<tree.getNumberOfNodes()<<std::endl;
    std::cout<<tree.getNumberOfNodes2()<<std::endl;
    std::cout<<tree.isPerfect()<<std::endl;





    return 0;
}
