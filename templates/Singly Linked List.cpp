template<class T>
class List
{
private:
	struct Node
	{
		T data;
		Node *next;
		Node(T data = -1, Node *next = NULL) : data(data), next(next) {}
	};
	Node *head, *tail;
	int size;

	Node *_forward(Node *p, int n)
	{
		for (int i = 1; i <= n; i++) p = p->next;
		return p;
	}
	Node *_insert_after(Node *p, T x)
	{
		p->next = new Node(x, p->next);
		size++;
		if (p == tail) tail = p->next;
		return p->next;
	}
	void _del_after(Node *p)
	{
		Node *q = p->next;
		if (q == tail) tail = p;
		p->next = q->next;
		delete q;
		size--;
	}

public:
	List()
	{
		tail = new Node();
		head = new Node(-1, tail);
		tail = head;
		size = 0;
	}

	struct iterator
	{
		Node *p;
		iterator(Node *p = NULL) : p(p) {}

		iterator& operator++()
		{
			p = p->next;
			return *this;
		}
		iterator operator++(int)
		{
			iterator tmp(*this);
			p = p->next;
			return tmp;
		}
		iterator operator+(int n)
		{
			for (int i = 1; i <= n; i++) p = p->next;
			return iterator(p);
		}
		bool operator==(iterator &it)
		{
			return p == it.p;
		}
		bool operator!=(iterator &it)
		{
			return p != it.p;
		}
		T& operator*()
		{
			return p->data;
		}
	};

	//Insert an item
	iterator& insert_after(iterator& it, T x)
	{
		it.p = _insert_after(it.p, x);
		return it;
	}
	T insert(int pos, T x)
	{
		Node *p = _forward(head, pos);
		return _insert_after(p, x)->data;
	}
	int insert(T x)
	{
		return insert(0, x);
	}
	iterator append(T x)
	{
		return iterator(_insert_after(tail, x));
	}

	//Delete an item
	void del_after(iterator& it)
	{
		_del_after(it.p);
	}
	void del(int pos)
	{
		_del_after(_forward(head, pos));
	}

	iterator begin()
	{
		return iterator(head->next);
	}
	iterator end()
	{
		return iterator(tail->next);
	}

	int len()
	{
		return size;
	}
	bool empty()
	{
		return size == 0;
	}

	T& operator[](int i)
	{
		return _forward(head, i + 1)->data;
	}
};