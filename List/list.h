#define POISON_POINTER_DELTA 0
#define LIST_POISON1  ((void *) 0x00100100 + POISON_POINTER_DELTA)
#define LIST_POISON2  ((void *) 0x00200200 + POISON_POINTER_DELTA)


/** the struct of node **/
struct list_head
{
	struct list_head *next, *prev;
};

/** List Declare**/
/** Get Address in order to point back to itself **/
#define LIST_HEAD_INIT(name)\
	 { &(name), &(name)}

/** List Init **/
#define LIST_HEAD(name)\
	struct list_head name = LIST_HEAD_INIT(name)

/** List Init **/
static inline void INIT_LIST_HEAD(struct list_head * list)
{
	list->next = list;
	list->prev = list;
	/** point back **/
}

					/** should add const **/
static inline int list_empty(const struct list_head * head)
{
	return head->next == head;
}

#ifndef CONFIG_DEBUG_LIST
static inline void __list_add(struct list_head * new, struct list_head *prev, struct list_head *next)
{
	next -> prev = new;	
	new -> next = next;
	new -> prev = prev;
	prev -> next = new;
}

#else
extern void __list_add(struct list_head * new, struct list_head * prev, struct list_head * next);
#endif

/** insert behind head **/
static inline void list_add(struct list_head *new, struct list_head * head)
{
	__list_add(new, head, head->next);
}

/** insert before head **/
static inline void list_add_tail(struct list_head *new, struct list_head * head)
{
	__list_add(new, head->prev, head);
}

/** delete node between head and next **/
static inline void __list_del(struct list_head * prev, struct list_head * next)
{
	next -> prev = prev;	
	prev -> next = next;
}

#ifndef  CONFIG_DEBUG_LIST
static inline void list_del(struct list_head *entry)
{
	__list_del(entry -> prev, entry -> next);
	/** after __list_del executed entry still points somewhere **/
	entry -> next = LIST_POISON1;
	entry -> prev = LIST_POISON2;
}
#else
extern void list_del(struct list_head * entry);
#endif


#define container_of(ptr, type, member) ({                      \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - offsetof(type,member) );})




