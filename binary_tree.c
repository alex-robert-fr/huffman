#include "binary_tree.h"
#include <stdlib.h>

t_node *create_node(int data) {
  t_node *node = (t_node *)malloc(sizeof(t_node));
  if (node == NULL) {
    return NULL; // Memory allocation failed
  }
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}
