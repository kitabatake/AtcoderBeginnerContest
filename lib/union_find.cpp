using namespace std;
#include <vector>

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