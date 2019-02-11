
#include "list.h"
//#include "llist.c"
#include <stdio.h>
#include <stdlib.h>

void qSort(LIST *lst){

    if(lst_is_empty(lst) || lst_length(lst) == 1)
        return;
    
    LIST *pivot = lst_create();
    lst_push_back(pivot, lst->front->val);

        lst->front = lst->front->next;

    LIST *lst2;
    
    lst2 = lst_filter_leq(lst, pivot->front->val);
    
    
        qSort(lst);
        qSort(lst2);
    
    
    lst_concat(lst,pivot);
    lst_concat(lst,lst2);
    
    
}

int main(){
    LIST *lst1 = lst_create();
    int userInput;
    
    int val = scanf("%d", &userInput);
    
    while(val != EOF && val != 0){
        lst_push_back(lst1, userInput);
        val = scanf("%d", &userInput);
    }
    
    lst_print(lst1);
    
        printf("Quick-Sort:\n");
    qSort(lst1);
    lst_print(lst1);
}