sort_a(size)
{
    if (size <= 3)
        small_sort_a(size);

    pivot = ...

    pb_count = 0;
    ra_count = 0;

    repeat size times
    {
        if (top < pivot)
        {
            pb();
            pb_count++;
        }
        else
        {
            ra();
            ra_count++;
        }
    }

    undo_ra(ra_count);

    sort_a(size - pb_count);
    sort_b(pb_count);

    while (pb_count--)
        pa();
}