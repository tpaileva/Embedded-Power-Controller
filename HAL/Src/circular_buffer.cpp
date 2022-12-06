/*
 * circular_buffer.cpp
 *
 *  Created on: Apr 28, 2020
 *      Author: t. pailevanian
 */

#include "circular_buffer.h"

CircularBuffer::CircularBuffer(size_t size)
{
	// Create the buffer to store data
	buffer_ = (uint8_t *)malloc(sizeof(uint8_t) * size);

	// Store the buffer maximum size
	max_size_ = size;

	// Reset the head and tail pointer
	Reset();
}

CircularBuffer::~CircularBuffer()
{
	if(buffer_ != NULL){
		free(buffer_);
	}
}

void CircularBuffer::PutOverwrite(uint8_t data)
{
    buffer_[head_] = data;

    AdvancePointer();
}

bool CircularBuffer::Put(uint8_t data)
{
	bool successful = false;

	if(!IsFull())
	{
		buffer_[head_] = data;
		AdvancePointer();
		successful = true;
	}

	return successful;
}

bool CircularBuffer::Get(uint8_t *data)
{
	bool successful = false;

    if(!IsEmpty())
    {
        *data = buffer_[tail_];
        RetreatPointer();

        successful = true;
    }

    return successful;
}

void CircularBuffer::Reset()
{
    head_ = 0;
    tail_ = 0;
    full_ = false;
}

bool CircularBuffer::IsEmpty()
{
	return !full_ && (head_ == tail_);
}

bool CircularBuffer::IsFull()
{
	return full_;
}

size_t CircularBuffer::Capacity()
{
	return max_size_;
}

size_t CircularBuffer::Available()
{
	size_t size = max_size_;

	if(!full_)
	{
		if(head_ >= tail_)
		{
			size = (head_ - tail_);
		}
		else
		{
			size = (max_size_ + head_ - tail_);
		}
	}

	return size;
}

void CircularBuffer::AdvancePointer()
{
	if(full_)
    {
        tail_ = (tail_ + 1) % max_size_;
    }

	head_ = (head_ + 1) % max_size_;

	// We mark full because we will advance tail on the next time around
	full_ = (head_ == tail_);
}

void CircularBuffer::RetreatPointer()
{
	full_ = false;
	tail_ = (tail_ + 1) % max_size_;
}
