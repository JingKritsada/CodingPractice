void shift(int k)
{
	int pos;
	if (k < 0)
	{
		k *= -1;
		pos = k % mSize;
	}
	else
	{
		pos = mSize - (k % mSize);
	}

	mHeader->prev->next = mHeader->next;
	mHeader->next->prev = mHeader->prev;

	node *itr = mHeader->prev;
	while (pos--)
	{
		itr = itr->prev;
	}

	mHeader->next = itr->next;
	mHeader->next->prev = mHeader;

	mHeader->prev = itr;
	mHeader->prev->next = mHeader;
}