#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node_s {
char data;
struct node_s * right, * left;
} tree_t;
typedef tree_t * btree;

int find_index(char *istr, int start,int end, char data){
    for(int i=start;i<=end;i++){
        if (istr[i]==data)
        {
            return i;
        }
        
    }
    return -1;
}

btree PItree_fun(char *pstr, char *istr,int startIndex,int endIndex,int *index){
    if (startIndex>endIndex) return NULL;
    btree root = (btree)malloc(sizeof(tree_t));
    root->data = pstr[*index];
    root->left = root->right = NULL;
    
    int rootIndex = find_index(istr,startIndex,endIndex,root->data);
    if(rootIndex==-1){
        free(root);
        return NULL;
    }
    
    (*index)++;
    root->left = PItree_fun(pstr,istr,startIndex,rootIndex-1,index);
    root->right = PItree_fun(pstr,istr,rootIndex+1,endIndex,index);
    
    return root;
}

btree OItree_fun(char *pstr, char *ostr,int startIndex,int endIndex,int *index){
    if (startIndex>endIndex) return NULL;
    btree root = (btree)malloc(sizeof(tree_t));
    root->data = pstr[*index];
    root->left = root->right = NULL;
    
    int rootIndex = find_index(ostr,startIndex,endIndex,root->data);
    if(rootIndex==-1){
        free(root);
        return NULL;
    }
    
    (*index)--;
    root->right = OItree_fun(pstr,ostr,rootIndex+1,endIndex,index);
    root->left = OItree_fun(pstr,ostr,startIndex,rootIndex-1,index);

    
    return root;
}

void print_root(btree root,int now,int level){
    if (now>level || root==NULL) return;
    if(now==level) printf("%c",root->data);

    
    print_root(root->left,now+1,level);
    print_root(root->right,now+1,level);
}

int main(){
    char type1,type2;
    char data1[22],data2[22];
    scanf("%c",&type1);
    scanf("%s",data1);
    scanf(" %c",&type2);
    scanf("%s",data2);
    btree tree = NULL;
    int n = strlen(data1);
    if (type1=='P'&&type2=='I'){
        int pre_index = 0;
        tree = PItree_fun(data1,data2,0,n-1,&pre_index);
    }else if (type1=='I'&&type2=='P'){
        int pre_index = 0;
        tree = PItree_fun(data2,data1,0,n-1,&pre_index);
    }else if (type1=='O'&&type2=='I')
    {
        int pre_index = n-1;
        tree = OItree_fun(data1,data2,0,n-1,&pre_index);
    }else if (type1=='I'&&type2=='O')
    {
        int pre_index = n-1;
        tree = OItree_fun(data2,data1,0,n-1,&pre_index);
    }
    for(int i=0;i<30;i++){
        print_root(tree,0,i);
    }
    
    printf("\n");
    free(tree);
    return 0;
}