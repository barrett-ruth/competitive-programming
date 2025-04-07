#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  node *left, *right;
  node(int val) : data(val), left(nullptr), right(nullptr) {}
};

node *generateTree(int depth) {
  if (depth <= 0)
    return nullptr;

  node *root = new node(rand() % 1000);
  root->left = generateTree(depth - 1);
  root->right = generateTree(depth - 1);
  return root;
}

void inorderTraversal(node *root) {
  if (!root)
    return;
  inorderTraversal(root->left);
  std::cout << root->data << " ";
  inorderTraversal(root->right);
}

void deleteTree(node *root) {
  if (!root)
    return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

vector<unordered_map<int, int>> up(1000);
unordered_map<int, int> par;

void dfs(node* tree, node* parent=nullptr) {
  if (tree == nullptr) return;
  par[tree->data] = parent->data;
  dfs(tree->left, tree);
  dfs(tree->right, tree);
}

void binary_lift(node* tree) {
  if (tree == nullptr) return;
  int d = depth[tree->data];

  int i = 1;
  int u = tree->data;
  while (pow(2, i) <= d) {
    up[u][i] = up[up[u][i - 1]][i - 1];
    ++i;
  }

  par[tree->left] = tree;
  binary_lift(tree->left);
  binary_lift(tree->right);
}

int lca(int u, int v) {
  int ud = depth[u], vd = depth[v];
  if (ud > vd) {
    swap(u, v);
    swap(ud, vd);
  }

  int delta = vd - ud;
  while (v != u) {
    int promote = powl(2, floor(log2(delta)));
    v = up[v][promote];
    delta -= promote;
  }

  delta = ud;
  int l = 0, r = ud;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (up[u][m] == up[v][m]) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  return l;
}

int main() {
  int depth = 20;
  node *tree = generateTree(depth);
  binary_lift(tree);
  cout << lca(tree->left->data, tree->right->data)
       << "<- was lca(root.left, root.right), when should be: " << tree->data
       << '\n';

  return 0;
}
