#include <iostream>
#include <cstdio>
using namespace std;

struct node{
	char data;
	node* prev;
	node* next;
} a[1010000];

char str[1010000];
int getstrlen(char * str){
	int i;
	for(i=0;str[i]!='\0';i++) ;
	return i;
}

int idx;
node* alloc(){
	return &a[idx++];
}

void insertnode(node ** curr, char data){
	node* newnode = alloc();
	newnode->data = data;
	newnode->prev = *curr;

	newnode->next = (*curr)->next;
	(*curr)->next->prev = newnode;

	(*curr)->next = newnode;
	*curr = (*curr)->next;
}

void deletenode(node ** curr){
	(*curr)->prev->next = (*curr)->next;
	(*curr)->next->prev = (*curr)->prev;
	(*curr) = (*curr)->prev;
}
void printnode(node * head, node * tail){
	for(node * iter = head; iter!=tail; iter = iter->next)
		cout << iter->data;
	cout << "\n";
}
int main(){
	FILE * fp;
    fp = fopen("input.txt","r");
	int num;
	//cin >> num;
    fscanf(fp, "%d", &num);
	int len;
	for(int i=0;i<num;i++){
		idx=0;

		node * head = alloc();
		node * tail = alloc();
		node * curr = head;

		head->next = tail;
		tail->prev = head;
		
		//cin >> str;
        fscanf(fp, "%s", str);
		len = getstrlen(str);
		for(int j=0;j<len;j++){
			switch(str[j]){
				case '<' :
					if(curr!=head) curr = curr->prev;
					break;
				case '>' :
					if(curr!=tail->prev) curr = curr->next;
					break;
				case '-' :
					if(curr!=head) deletenode(&curr);
					break;
				default :
					insertnode(&curr, str[j]);
					break;
			}
		}
		printnode(head->next, tail);
	}

	return 0;
}