#ifndef _CK_ITERATOR_H
#define _CK_ITERATOR_H
namespace CK_STL
{
	struct input_iterator_tag{};
	struct output_iterator_tag{};
	struct forward_iterator_tag :public input_iterator_tag {};
	struct bidirectional_iterator_tag :public forward_iterator_tag {};
	struct random_access_iterator_tag :public bidirectional_iterator_tag {};
	template <class T, class Distance>
	struct input_iterator
	{
		typedef input_iterator_tag	iterator_category;
		typedef T					value_type;
		typedef Distance			difference_type;
		typedef T*					pointer;
		typedef T&					reference;
	};

	struct output_iterator
	{
		typedef output_iterator_tag iterator_category;
		typedef void                value_type;
		typedef void                difference_type;
		typedef void                pointer;
		typedef void                reference;
	};

	template <class T, class Distance>
	struct forward_iterator
	{
		typedef forward_iterator_tag	iterator_category;
		typedef T						value_type;
		typedef Distance				difference_type;
		typedef T*						pointer;
		typedef T&						reference;
	};

	template <class T, class Distance>
	struct bidirectional_iterator
	{
		typedef bidirectional_iterator_tag	iterator_category;
		typedef T							value_type;
		typedef Distance					difference_type;
		typedef T*							pointer;
		typedef T&							reference;
	};

	template <class T, class Distance>
	struct random_access_iterator
	{
		typedef random_access_iterator_tag	iterator_category;
		typedef T							value_type;
		typedef Distance					difference_type;
		typedef T*							pointer;
		typedef T&							reference;
	};
	//获取迭代器类型
	template<class Iterator>
	inline typename iterator_traits<Iterator>::iterator_category
		iterator_category(const Iterator& It){
		typedef typename iterator_traits<Iterator>::iterator_category category;
		return category();
	}

	//获取迭代器所指对象的类型
	template<class Iterator>
	inline typename iterator_traits<Iterator>::value_type*
		value_type(const Iterator& It){
		return static_cast<typename iterator_traits<Iterator>::value_type*>(0);
	}

	//获取迭代器距离类型
	template<class Iterator>
	inline typename iterator_traits<Iterator>::difference_type*
		difference_type(const Iterator& It){
		return static_cast<typename iterator_traits<Iterator>::difference_type*>(0);
	}

	//计算两迭代器间的距离
	template <class InputIterator>
	inline typename iterator_traits<InputIterator>::difference_type _distance(InputIterator first, InputIterator last, input_iterator_tag)
	{
		iterator_traits<InputIterator>::difference_type n = 0;
		while (first != last)
		{
			++first, ++n;
		}
		return n;
	}

	template <class RandomAccessIterator>
	inline typename iterator_traits<RandomAccessIterator>::difference_type _distance(RandomAccessIterator first, RandomAccessIterator last, random_access_iterator_tag)
	{
		return last - first;
	}

	template <class InputIterator>
	inline typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last)
	{
		typedef typename iterator_traits<InputIterator>::iterator_category category;
		return _distance(first, last, category());
	}

	//使迭代器移动响应的距离
	template <class InputIterator, class Distance>
	inline void _advance(InputIterator& i, Distance n, input_iterator_tag)
	{
		while (n--) ++i;
	}

	template<class BidirectionalIterator, class Distance>
	inline void _advance(BidirectionalIterator& i, Distance n, bidirectional_iterator_tag)
	{
		if (n >= 0)
		{
			while (n--) ++i;
		}
		else
		{
			while (n++) --i;
		}
	}

	template<class RandomAccessIterator, class Distance>
	inline void _advance(RandomAccessIterator& i, Distance n, random_access_iterator_tag)
	{
		i += n;
	}

	template <class InputIterator, class Distance>
	inline void advance(InputIterator& i, Distance n)
	{
		_advance(i, n, iterator_category(i));
	}
}
#endif