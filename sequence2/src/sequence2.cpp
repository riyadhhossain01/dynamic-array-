#include <cstdlib>
#include <cassert>
#include <iostream>
#include <algorithm>

#include "sequence2.h"


using namespace main_savitch_4;
// For some reason  #include<algorithm> doesn't declare the copy function,
//so I created my own way to deaclare copy.
template<class InputIterator, class OutputIterator>
  OutputIterator copy (InputIterator first, InputIterator last, OutputIterator result)
{
  while (first!=last) {
    *result = *first;
    ++result; ++first;
  }
  return result;
}

    //Constructor to initialize dynamic array
   sequence::sequence(size_type initial_capacity)
    {
        data = new value_type[initial_capacity];
        current_index = 0;
        capacity = initial_capacity;
        used = 0;
    }
    // Copy Constructor
    sequence::sequence(const sequence& source)
    {
        capacity = source.capacity;
		data = new value_type[capacity];
		used = source.used;
		current_index = source.current_index;
		copy(source.data,source.data+used,data);
    }
    //Destructor

        sequence::~sequence( )
        {
            delete [] data;
        }

    void sequence::start( )
    {
        current_index = 0;

    }
    void sequence::advance()
    {
        if(is_item())
		current_index++;
    }

    void sequence::insert(const value_type& entry)
    {
        if(used == capacity)
	   {
		   capacity = (capacity*1.1) + 1 ;
		   resize(capacity);
	   }
	   if (!is_item() )
		{
		    current_index = 0;
        }
	   for (int i = used; i > current_index; i--)
	   {
	       data[i] = data[i-1];
       }
	   data[current_index] = entry;
	   used++;
    }
    void sequence::attach(const value_type& entry)
    {
	   if(used == capacity)
	   {
		   capacity = (capacity*1.1) + 1 ;
		   resize(capacity);
		   data[current_index+1] = entry;
	   }

	   if(!is_item())
	   {   data[current_index]=entry; }
	   else
	   {
		   for (int i = used; i > current_index+1; i--)
		   {	data[i] = data[i-1];	}
		   data[current_index+1] = entry;
		   current_index++;
	   }
	   ++used;
   }

    void sequence::remove_current( )
    {
       if(is_item())
	   {
	   		for (int i = current_index; i < used; i++)
			{
			    data[i] = data[i+1];
            }
			used--;
	   }
    }

    void sequence::resize(size_type new_capacity)
        {
            if(new_capacity > used)
		{
			value_type *new_size;
			capacity = new_capacity;
			new_size= new value_type[capacity];
			copy(data,data+used,new_size);
			delete [] data;
			data = new_size;
		}
        }

  void sequence::operator = (const sequence& source)
{
	    value_type *new_data;
		capacity = source.capacity;
		current_index = source.current_index;
		used = source.used;
		new_data = new value_type [capacity];
		copy(data,data+used,new_data);
		delete [ ] data;
		data = new_data;
		copy(source.data,source.data+used,data);
}

    sequence::size_type sequence:: size() const
    {
       return used;
    }


    bool sequence :: is_item() const
    {
          return current_index < used;
    }

      sequence::value_type sequence:: current() const
    {
             return data[current_index];
    }





