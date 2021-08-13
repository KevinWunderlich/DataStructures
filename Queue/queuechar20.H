const int maxqueuechar = 28;
class queuechar_type		    // declaration of class//
{
public:
		void clear_queuechar();	//member functions//
		bool empty_queuechar(); //    of class queue_type//
		bool full_queuechar();
		void insert_queuechar(char ch);
		void delete_queuechar(char& ch);
		char queuechar[29];
		int frontch,rearch;
};

void queuechar_type::clear_queuechar()
{
	frontch = maxqueuechar;
	rearch = maxqueuechar;
}
//----------------------------------------------------------------------
bool queuechar_type::empty_queuechar()
{
	if (rearch == frontch)
		return true;
	else
		return false;
}
//----------------------------------------------------------------------
bool queuechar_type::full_queuechar()
{
	int querear;
	if (rearch == maxqueuechar) 
		querear = 0;
	else
		querear = rearch + 1;
	if (querear == frontch)
		return true;
	else
		return false;
}
//----------------------------------------------------------------------
void queuechar_type::insert_queuechar(char ch)
{
	if (rearch == maxqueuechar)
		rearch = 0;
	else 
		rearch = rearch + 1;
    queuechar[rearch] = ch;
}
//----------------------------------------------------------------------
void queuechar_type::delete_queuechar(char& ch)
{
	if (frontch == maxqueuechar)
		frontch = 0;
	else 
		frontch = frontch + 1;
	ch = queuechar[frontch];
	
}
