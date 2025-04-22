void replace(const T &x, list<T> &y)
{
    auto itr = begin();
    while (itr != end())
    {
        if (*itr == x)
        {
            for (T &x : y)
            {
                insert(itr, x);
            }

            itr = erase(itr);
        }
        else
        {
            itr++;
        }
    }
}
