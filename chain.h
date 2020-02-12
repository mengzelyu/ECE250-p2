class Node{
	public:
	long long pnum;
	Node *next;
	std::string caller;
};

class hash{
	private:
	long long size;
	Node **hashtable;
	
	public:
	hash(long long size);
	~hash();
	long long hashfunc(long long key);
	void insert(long long key, std::string caller);
	long long search(long long key);
	void delete_key(long long key);
	void print(long long i); 
};
