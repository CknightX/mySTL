#ifndef _CK_QUEUE_H
#define _CK_QUEUE_H
#include "ck_deque.h"
namespace CK_STL
{
	template<class T,class Sequence=deque<T> >
	class queue
	{
		friend bool operator==(const queue& x,const queue& y){return x.c==y.c;}
		friend bool operator<(const queue& x,const queue& y){return x.c<y.c;}

		public:
		typedef typename Sequence::value_type value_type;
		typedef typename Sequence::size_type size_type;
		typedef typename Sequence::reference reference;
		typedef typename Sequence::const_reference const_reference;
		protected:
		Sequence c;
		public:
		bool empty() const {return c.empty();}
		size_type size() const {return c.size();}
		reference front(){return c.front();}
		const_reference front()const{return c.front();}
		reference back(){return c.back();}
		const_reference back()const{return c.back();}
		void push(const value_type& x){c.push_back(x);}
		void pop(){c.pop_front();}
	};
}
#endif
