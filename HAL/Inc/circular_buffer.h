/*
 * circular_buffer.h
 *
 *  Created on: Apr 28, 2020
 *      Author: t. pailevanian
 */

#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

class CircularBuffer {
public:
	CircularBuffer(size_t size);
	~CircularBuffer();

	void PutOverwrite(uint8_t data);

	bool Put(uint8_t data);

	bool Get(uint8_t * data);

	void Reset();

	bool IsEmpty();

	bool IsFull();

	size_t Capacity();

	size_t Available();

protected:
	uint8_t * buffer_;

	size_t head_ = 0;
	size_t tail_ = 0;
	size_t max_size_;

	bool full_ = false;

	void RetreatPointer();

private:

	void AdvancePointer();


};


#endif /* CIRCULAR_BUFFER_H_ */
