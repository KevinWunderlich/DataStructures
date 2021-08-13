const int maxqueue = 4;
class queue_type		    // declaration of class//
{
public:
		void clear_queue();	//member functions//
		bool empty_queue(); //    of class queue_type//
		bool full_queue();
		void insert_queue(int numb);
		void delete_queue(int& numb);
		int queue[5];
		int front,rear;
};

void queue_type::clear_queue()
{
	front = maxqueue;
	rear = maxqueue;
}
//----------------------------------------------------------------------
bool queue_type::empty_queue()
{
	if (rear == front)
		return true;
	else
		return false;
}
//----------------------------------------------------------------------
bool queue_type::full_queue()
{
	int querear;
	if (rear == maxqueue) 
		querear = 0;
	else
		querear = rear + 1;
	if (querear == front)
		return true;
	else
		return false;
}
//----------------------------------------------------------------------
void queue_type::insert_queue(int numb)
{
	if (rear == maxqueue)
		rear = 0;
	else 
		rear = rear + 1;
    queue[rear] = numb;
}
//----------------------------------------------------------------------
void queue_type::delete_queue(int& numb)
{
	if (front == maxqueue)
		front = 0;
	else 
		front = front + 1;
	numb = queue[front];
	
}
