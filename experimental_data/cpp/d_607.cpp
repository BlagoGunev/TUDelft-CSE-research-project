#include <cstdio>
#include <vector>

#define MOD 1000000007

typedef long long int64;

int mult(int a, int b) {
  return (int64)a * (int64)b % MOD;
}

int add(int a, int b) {
  int c = a + b;
  return c >= MOD ? c - MOD : c;
}

int sub(int a, int b) {
  int c = a - b;
  return c < 0 ? c + MOD : c;
}

using namespace std;

struct Tournament {
  struct Element {
    int factor = 0;
    int value = 0;
    int power = 0;
  };
  Tournament(int n) {
    offset = 1;
    while (offset < n) offset *= 2;
    tree.resize(2 * offset);
  }

  void IncreaseFactor(int i) {
    i = offset + i;
    tree[i].factor += 1;
    tree[i].power = add(tree[i].power, tree[i].value);
    UpdateParents(i);
  }

  void SetValue(int i, int v) {
    i = offset + i;
    tree[i].value = v;
  }

  void AddValue(int i, int v) {
    i = offset + i;
    tree[i].value = add(tree[i].value, v);
    tree[i].power = add(tree[i].power, mult(tree[i].factor, v));
    UpdateParents(i);
  }

  void UpdateParents(int i) {
    for (i /= 2; i >= 1; i /= 2) {
      tree[i].factor = mult(tree[2 * i].factor, tree[2 * i + 1].factor);
      tree[i].value = add(tree[2 * i].value, tree[2 * i + 1].value);
      tree[i].power = add(tree[2 * i].power,
                          mult(tree[2 * i].factor, tree[2 * i + 1].power));
    }
  }

  int Query(int i) {
    i = offset + i;
    Element ret = tree[i];
    int c = i;
    for (i /= 2; i >= 1; c = i, i /= 2) {
      if (c == 2 * i) {
        Element tmp;
        tmp.factor = mult(ret.factor, tree[2 * i + 1].factor);
        tmp.value = add(ret.value, tree[2 * i + 1].value);
        tmp.power = add(ret.power, mult(ret.factor, tree[2 * i + 1].power));
        ret = tmp;
      }
    }
    return ret.power;
  }

  int offset;
  vector<Element> tree;
};

struct Node;

struct Chain {
  Node* parent;
  Tournament* tournament;
  int propagated_power = 0;
} chains[200000];
Chain* next_chain = chains;

struct Node {
  int value;
  int size;
  vector<Node*> children;
  Node* heavy_link;

  Chain* chain;
  int chain_index;
} tree[200000];
Node* next_node = tree;

struct Command {
  int type;
  Node* parent_node;
  Node* node;
};

void FindHeavyLinks(Node* node) {
  node->size = 1;
  node->heavy_link = nullptr;
  for (Node* child : node->children) {
    FindHeavyLinks(child);
    node->size += child->size;
    if (node->heavy_link == nullptr || child->size > node->heavy_link->size) {
      node->heavy_link = child;
    }
  }
}

void BuildChains(Node* node, Node* parent) {
  Chain* chain = next_chain++;
  chain->parent = parent;
  int i = 0;
  for (; node; node = node->heavy_link) {
    node->chain = chain;
    node->chain_index = i++;
    for (Node* child : node->children) {
      if (child != node->heavy_link) {
        BuildChains(child, node);
      }
    }
  }
  chain->tournament = new Tournament(i);
}

void Propagate(Chain* c) {
  int current_power = c->tournament->tree[1].power;
  int delta = sub(current_power, c->propagated_power);
  c->propagated_power = current_power;
  if (c->parent == nullptr) return;
  c->parent->chain->tournament->AddValue(c->parent->chain_index, delta);
  Propagate(c->parent->chain);
}

int main() {
  int Q;
  Node* root = next_node++;
  scanf("%d%d", &root->value, &Q);
  vector<Command> C;
  for (int i = 0; i < Q; ++i) {
    Command c;
    scanf("%d", &c.type);
    int node_index;
    if (c.type == 1) {
      c.node = next_node++;
      scanf("%d%d", &node_index, &c.node->value);
      c.parent_node = &tree[node_index - 1];
      c.parent_node->children.push_back(c.node);
    } else {
      scanf("%d", &node_index);
      c.node = &tree[node_index - 1];
    }
    C.push_back(c);
  }

  FindHeavyLinks(root);
  BuildChains(root, nullptr);

  root->chain->tournament->SetValue(root->chain_index, root->value);
  root->chain->tournament->IncreaseFactor(root->chain_index);
  for (Command const& c : C) {
    if (c.type == 1) {
      Tournament* t;
      c.node->chain->tournament->SetValue(c.node->chain_index, c.node->value);
      c.node->chain->tournament->IncreaseFactor(c.node->chain_index);
      c.parent_node->chain->tournament->IncreaseFactor(
          c.parent_node->chain_index);
      Propagate(c.node->chain);
    } else {
      printf("%d\n", c.node->chain->tournament->Query(c.node->chain_index));
    }
  }

  return 0;
}