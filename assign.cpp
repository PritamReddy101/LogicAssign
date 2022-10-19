#include  <iostream>
#include <string>
using namespace std;

struct tree
{
    char data;
    tree *left;
    tree *right;
};

tree *root;

bool isOperator(char c)
{
    if (c == '~' || c == '+' || c == '*' || c == '>')
        return true;

    return false;
}

bool isOperand(char c)
{
    if (c >= 'a' && c <= 'z')
        return true;
    if (c >= 'A' && c <= 'Z')
        return true;
    return false;
}

bool CheckParantheses(char c)
{
    if (c == ']' || c == '[' || c == '}' || c == '{' || c == ')' || c == '(')
        return true;
    else
        return false;
}

bool isNegation(char c)
{
    if (c == '~')
        return true;
    return false;
}

int i = 1;

char* addToTree(tree** roothead,char* input){

    //base condition for recursion to end
    if (*input == '\0')
        return "\0";

    while (1) {
        char* q = "null";
        if (*roothead == NULL) {
            tree* temp = new tree();
            temp->data = *input;
            temp->left = NULL;
            temp->right = NULL;
            *roothead = temp;
        }
        else {
 
            // If the character is an operand
            if (isOperand(*input)) {
                return input;
            }

            // if(isNegation(*input)){
            //     q = addToTree(&(*roothead)->right, q + 1);
            // }
 
            // Build the left sub-tree
            if(!isNegation((*roothead)->data)){
                q = addToTree(&(*roothead)->left, input + 1);
                // Build the right sub-tree
            q = addToTree(&(*roothead)->right, q + 1);
            }
            else{
                // Build the right sub-tree
            q = addToTree(&(*roothead)->right, input + 1);
            }
            
 
            
 
            return q;
        }
    }

}

void inr(tree* p) // recursion
{
    if (p == NULL) {
        return;
    }
    else {
        inr(p->left);
        printf("%c ", p->data);
        inr(p->right);
    }
}
int computeHeight(tree* p){
    int lv,rv;
    if (p == NULL) {
        return 0;
    }

        lv = computeHeight(p->left);
        rv = computeHeight(p->right);
        if(lv>=rv){
            return lv+1;
        }else{
            return rv+1;
        }
}

int main()
{   

    tree* s = NULL;
    char a[] = ">p*q*ab";
    addToTree(&s, a);
    printf("The Infix expression is:\n ");
    inr(s);
    std::cout<< "\nThe height of the parse tree is "<< computeHeight(s);
}