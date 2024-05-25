#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
   int coeff;
   int exp;
   struct node* next;
};

struct node* createNode(int coeff,int exp){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->coeff=coeff;
    new_node->exp=exp;
    new_node->next=NULL;
    return new_node;
}
void insertTerm(struct node**poly,int coeff,int exp)
{
// allocate memory for a new node



struct node* temp=*poly;
struct node* newNode=createNode(coeff,exp);
//assign the data to thenew node
//new_node->data=new_data;

//set the next of the new node as the current head
//new_node->next=NULL;

if(*poly == NULL)
{
    *poly=newNode;
}
else{
    while(temp->next!=NULL){temp=temp->next;}//false
    temp->next=newNode; 
}
}
struct node* addPolynomials(struct node* poly1, struct node* poly2)
{
    struct node* result=NULL;
    struct node** tail=&result;
    while(poly1 != NULL && poly2 != NULL)
    {
        if (poly1->exp == poly2->exp)
        {
            insertTerm(tail, poly1->coeff+poly2->coeff, poly1->exp);
            poly1=poly1->next;
            poly2=poly2->next;
        }
        else if(poly1->exp > poly2->exp)
        {
            insertTerm(tail, poly1->coeff, poly1->exp);
            poly1=poly1->next;
        }
        else
        {
            insertTerm(tail, poly2->coeff, poly2->exp);
            poly2=poly2->next;
        }
        tail=&((*tail)->next);
    }
    // If any of the polynomials have remaining terms
    while(poly1 != NULL)
    {
        insertTerm(tail, poly1->coeff, poly1->exp);
        poly1=poly1->next;
        tail=&((*tail)->next);
    }
    while(poly2 != NULL)
    {
        insertTerm(tail, poly2->coeff, poly2->exp);
        poly2=poly2->next;
        tail=&((*tail)->next);
    }
    return result;
}



void displaypoly(struct node* poly){
    if(poly==NULL){
        printf("0\n");
        return;
    }
    while(poly!=NULL){
        printf("%dx^%d",poly->coeff,poly->exp);
        if(poly->next!=NULL){
            printf("  +  ");
        }
        poly=poly->next;
    }
    printf("\n");
}

// Function to subtract two polynomials
struct node* subPolynomials(struct node* poly1, struct node* poly2)
{
    struct node* result=NULL;
    struct node** tail=&result;
    while(poly1 != NULL && poly2 != NULL)
    {
        if (poly1->exp == poly2->exp)
        {
            insertTerm(tail, poly1->coeff-poly2->coeff, poly1->exp);
            poly1=poly1->next;
            poly2=poly2->next;
        }
        else if(poly1->exp > poly2->exp)
        {
            insertTerm(tail, poly1->coeff, poly1->exp);
            poly1=poly1->next;
        }
        else
        {
            insertTerm(tail, -(poly2->coeff), poly2->exp);
            poly2=poly2->next;
        }
        tail=&((*tail)->next);
    }
    // If any of the polynomials have remaining terms
    while(poly1 != NULL)
    {
        insertTerm(tail, poly1->coeff, poly1->exp);
        poly1=poly1->next;
        tail=&((*tail)->next);
    }
    while(poly2 != NULL)
    {
        insertTerm(tail, poly2->coeff, poly2->exp);
        poly2=poly2->next;
        tail=&((*tail)->next);
    }
    return result;
}

struct node* multiplyPolynomials(struct node* poly1 , struct node* poly2){
    struct node* result = NULL;
    struct node* tempresult = NULL;
    struct node* tempPoly1 = poly1;
    while(tempPoly1 != NULL){
        struct node* tempPoly2 = poly2;
        while(tempPoly2 != NULL){
            int coeff = tempPoly1->coeff * tempPoly2->coeff;
            int expp = tempPoly1->exp + tempPoly2->exp;
            insertTerm(&tempresult , coeff , expp);
            tempPoly2 = tempPoly2->next;
        }
        result = addPolynomials(result , tempresult);
        tempresult = NULL;
        tempPoly1 = tempPoly1->next;
    }
    return result;
}

int main(){
    struct node* poly1=NULL;
    struct node* poly2=NULL;
    
    insertTerm(&poly1,5,2);
    insertTerm(&poly1,3,4);
    insertTerm(&poly1,2,0);
    insertTerm(&poly2,-3,3);
    insertTerm(&poly2,2,1);
    insertTerm(&poly2,7,0);
    
    printf(" first polynomial::");
    displaypoly(poly1);
    printf("second polynomial::");
    displaypoly(poly2);

    struct node* sum=addPolynomials(poly1,poly2);
    printf("Sum of polynimials is::");
    displaypoly(sum);

    struct node* sub=subPolynomials(poly1,poly2);
    printf("Subtraction of polynimials is::");
    displaypoly(sub);
    
    struct node* mul=multiplyPolynomials(poly1,poly2);
    printf("Multiplication of polynimials is::");
    displaypoly(mul);
}