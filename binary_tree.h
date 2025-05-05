#pragma once

typedef struct t_node {
  int data;
  struct t_node *left;
  struct t_node *right;
} t_node;

t_node *create_node(int data);
