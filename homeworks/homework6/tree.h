typedef struct treenode {
  char *user;
  char *pass;
  
  unsigned int depth;
  struct treenode* lC;
  struct treenode* rC;
} node;

void erase(node* pos);
node* insert(char *u, char *p, node *pos, int d);
void show(node* position, char prefix);
void alpha(node* position);

