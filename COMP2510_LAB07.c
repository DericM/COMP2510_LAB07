

#define NAMESIZE 20

void list_init(record_list *list);
void list_destroy(record_list *list);
int list_insert(record_list *list, const record *rec);





typedef struct name {
	char last[NAMESIZE];
	char first[NAMESIZE];
} name;

 
typedef struct record {
	name name;
	int score;               /* between 0 & 100 inclusive */
} record;


typedef struct node {
	record data;
	node *next;
} node;

typedef node *record_list;

int main()
{
	record_list head;
	record *rec1, *rec2, *rec3;

	rec1 = malloc(sizeof(record));
	rec2 = malloc(sizeof(record));
	rec3 = malloc(sizeof(record));

	if (!rec1 || !rec2 || !rec3)
		return 0;

	strcpy(*rec1->name.first,"jim");
	strcpy(*rec1->name.last = "kimbo");
	strcpy(*rec2->name.first = "tim");
	strcpy(*rec2->name.last = "tree");
	strcpy(*rec3->name.first = "fred");
	strcpy(*rec3->name.last = "fanta");

	rec1->score = 30;
	rec2->score = 40;
	rec3->score = 50;

	list_init(head);
	list_insert(head, rec1);
	list_insert(head, rec2);
	list_insert(head, rec3);
	


}



void list_init(record_list *list) {
	list = malloc(sizeof(record_list));
}



void list_destroy(record_list *list) {
	node *p, *q;
	for (p = list; p != 0; p = q) {
		q = p->next;
		free(p);
	}
}


int list_insert(record_list *list, const record *rec) {
		node *newnode = malloc(sizeof(node));
		node **tracer;
		
		if (!newnode) {
			return 0;
		}


		for (tracer = &list; *tracer != 0; tracer = &(*tracer)->next) {
			if (cmp_N(&(*tracer)->data, rec)) {
				break;
			}
		}

		newnode->next = *tracer;
		*tracer = newnode;

		return 1;
}


int cmp_N(const void *p, const void *q) {
	record *rec1 = *(record * const *)p;
	record *rec2 = *(record * const *)q;

	int i = strcmp(rec2->name.last, rec1->name.last);
	if (i == 0) {
		return strcmp(rec2->name.first, rec1->name.first);
	}
	return i;
}




int list_print(record_list *list) {
	if (list != 0) {
		print_record(list->data);
		print_list(list->next);
	}
}

/*
prints a record
*/
void print_record(const record *prec) {
	printf("%s %s %d\n", prec->name.last, prec->name.first, prec->score);
}