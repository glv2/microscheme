/* ======================= Microscheme =======================
 * Microscheme-C FFI demo
 * (C) 2014-2021 Ryan Suchocki, et al.
 * http://github.com/ryansuchocki/microscheme
 */

#include "microscheme_types.c"

#include <math.h>

ms_value mathpow(ms_value x, ms_value y)
{
    return round(pow(x, y));
}

ms_value vectsum(ms_value v)
{
    vector *vect = asVector(v);

    int i, total = 0;
    for (i = 0; i < vect->length; i++)
    {
        total += vect->data[i];
    }

    return total;
}

ms_value listsum(ms_value v)
{
    if (isNull(v)) return 0;

    pair *lst = asPair(v);

    return lst->car + listsum(lst->cdr);
}