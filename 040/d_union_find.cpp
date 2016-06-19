#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

template<typename T>
class UnionFind {

  public:

    UnionFind (int node_num)
    {
      nodes = vector<Node>(node_num);
      for (int i = 0; i < node_num; i++) nodes[i] = {i, 1, -1};
    }

    void connect (int a_i, int b_i)
    {
      Node &a_head = nodes[head_index(a_i)];
      Node &b_head = nodes[head_index(b_i)];

      if (a_head == b_head) return;

      if (a_head.connected > b_head.connected) {
        a_head.connected += b_head.connected;
        b_head.forward_i = a_head.index;
      }
      else {
        b_head.connected += a_head.connected;
        a_head.forward_i = b_head.index;
      }
    }

    T find (int i)
    {
      Node node = nodes[i];
      while (node.forward_i != -1){
        node = nodes[node.forward_i];
      }
      return node.connected;
    }

  private:
    
    struct Node {
      int index;
      T connected;
      int forward_i;
      bool operator== (const Node &a)
      {
        return index == a.index;
      }
    };

    vector<Node> nodes;

    int head_index (int n_i)
    {
      Node node = nodes[n_i];
      while (node.forward_i != -1) {
        node = nodes[node.forward_i];
      }
      return node.index;
    }
};



struct Query {
  enum Type {Connect, Find};
  Type type;
  int year;
  pair<int,int> connect;
  int find_id;
  int ans_i;
};

ostream &operator << (ostream &os, Query const &q) {
  return os << q.year << ", " << q.type << endl;
}

bool operator> (const Query &a, const Query &b) {
  if (a.year == b.year) {
   return a.type < b.type; // make run Connect process before Find process
  }
  return a.year > b.year;
}



int main() {

  int N, M, Q;
  cin >> N >> M;

  vector<Query> queries;

  int a, b, y;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> y;
    queries.push_back ({
      Query::Connect, 
      y,
      make_pair(a, b)
    });
  }

  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int v, w;
    cin >> v >> w;
    queries.push_back ({
      Query::Find,
      w + 1,
      make_pair(0, 0),
      v,
      i
    });
  }

  sort(queries.begin(), queries.end(), greater<Query>());

  vector<int> ans(Q);
  UnionFind<int> uf {N + 1};
  for (Query q: queries) {
    if (q.type == Query::Connect) {
      uf.connect(q.connect.first, q.connect.second);
    }
    else {
      ans[q.ans_i] = uf.find(q.find_id);
    }
  }

  for (int a:ans) cout << a << endl;
}