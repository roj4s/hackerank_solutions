#include <algorithm>
#include <bits/stdc++.h>
#include <deque>
#include <iterator>
// https://www.hackerrank.com/challenges/swap-nodes-algo/problem?h_r=next-challenge&h_v=legacy


using namespace std;

/*
 * Complete the swapNodes function below.
 */

class Tree{

    public:
        Tree *right;
        Tree *left;
        int idx;

        Tree(Tree *right, Tree *left, int idx){
            this->right = right;
            this->left = left;
            this->idx = idx;
        }

};

Tree* construct_tree(vector<vector<int>> idxs, Tree * root){

    std::deque<Tree*> processing_queue;
    processing_queue.push_back(root);
    int i = 0;

    while(!processing_queue.empty()){
        Tree * el = processing_queue.front();
        processing_queue.pop_front();

        vector<int> node_vals = idxs[i];
        bool is_right = true;
        for(int v: node_vals){
            if(v != -1){
                Tree * node = new Tree(nullptr, nullptr, v);
                processing_queue.push_back(node);
                if(is_right){
                    el->right = node;
                }
                else{

                    el->left = node;
                }
            }
            is_right = false;
        }
        i -= -1;
    }

    return root;
}

void inorder(Tree * root, vector<int> * path){

    if(root->left){
        inorder(root->left, path);
    }
    if(root->idx != -1){
        path->push_back(root->idx);
    }
    if(root->right){
        inorder(root->right, path);
    }

}

void swap(Tree* root, int k, int level){
    if(level % k == 0){
        Tree * aux = root->right;
        root->right = root->left;
        root->left = aux;
    }
    if(root->right){
        swap(root->right, k, level+1);
    }
    if(root->left){
        swap(root->left, k, level+1);
    }
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    vector<vector<int>> paths;
    Tree * root = construct_tree(indexes, new Tree(nullptr, nullptr, 1));

    for(int k: queries){
        swap(root, k, 1);
        vector<int> * path = new vector<int>;
        inorder(root, path);
        std::reverse(path->begin(), path->end());
        paths.push_back((*path));

        /*
        for(int v: *path){

            cout << v << ",";

        }
        cout << "\n";
        */

    }

    return paths;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

