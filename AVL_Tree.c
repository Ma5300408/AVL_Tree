#include<stdio.h>
#include<stdlib.h>


struct node{
    int key;
    int bf;
    struct node * left;
    struct node * right;
 

};

struct node * root = NULL;



void AVL_Insert(struct node * r,int value)
{
    if(!r){
       root = (struct node*)malloc(sizeof(struct node));
       root->key = value;
       root->bf = 0;
       root->left = NULL;
       root->right = NULL;
       return;
    }      

   struct node *a, *pa, *p, *pp;
   a = r;
   pa = NULL;
   p = r;
   pp = NULL;
   //p->bf = 1;
   while(p){

   if(p->bf != 0){a = p; pa = pp;}
   if(value < p->key){pp = p; p = p->left;}   
   else if(value > p->key){pp = p; p = p->right;}
        else{ return;}
  }
   
  struct node* y;
   y = (struct node*)malloc(sizeof(struct node));
   y->key = value;
   y->bf = 0;
   y->left = NULL;
   y->right = NULL;

   if(value < pp->key)pp->left = y;
   else pp->right = y;

   //printf("Insert without # finished!\n");
   
   int d;
   struct node *b, *c;

   if(value > a->key){b = p = a->right; d = -1;}
   else{b = p = a->left; d = 1;}
   while(p != y){
      if(value > p->key){
          p->bf = -1; p = p->right;
      }
      else{
         p->bf = 1; p = p->left;
      }

   }


   if(!(a->bf)||!(a->bf+d)){
     a->bf +=d; return;

   }
   
   if(d == 1){
        if(b->bf == 1){
           a->left = b->right;
           b->right = a; a->bf = 0; b->bf = 0;
        }
        else{
            c = b->right;
            b->right = c->left;
            a->left = c->right;
            c->left = b;
            c->right = a;
            switch(c->bf){
                   case 1:
                         a->bf = -1; b->bf = 0;
                      break;
                   case -1:
                        b->bf = 1; a->bf = 0;
                      break;
                   case 0:
                        b->bf = 0; a->bf = 0;
                       break;
              }
            
             c->bf = 0; b = c;
            }

        }
       else{
          if(b->bf == -1){
              a->right = b->left;
              b->left = a;  a->bf = 0; b->bf = 0;
           } 
          else{
             c = b->left;
             b->left = c->right;
             a->right = c->left;
             c->left = a;
             c->right = b;
             switch(c->bf){
                    case 1:
                        b->bf = -1; a->bf = 0;
                      break;
                    case -1:
                        a->bf = 1; b->bf = 0;
                       break;
                    case 0:
                        b->bf = 0; a->bf = 0;
                       break;
             }
             c->bf = 0; b = c;
          }

       }
  
   if(!pa)root = b;
   else if(a == pa->left)pa->left = b;
        else pa->right = b;

   return;
}


void Inorder(struct node * r)
{
    if(r){
       Inorder(r->left);
       printf(" %d ",r->key);
       Inorder(r->right);
    }
  return;
}

void Preorder(struct node * r)
{
    if(r){
     
       printf(" %d ",r->key);
       Preorder(r->left);
       Preorder(r->right);
    }
  return;
}



int main()
{
  int i;
  for(i = 0; i < 12; i++){
    int num;
     num = 0;
     scanf("%d",&num);
    AVL_Insert(root,num);
  }
  printf("%d\n",root->key);
  Preorder(root); 
  printf("\n");
  Inorder(root);
  printf("\n");
  printf("This is commit from the linux\n");

  return 0;
}