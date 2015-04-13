/*
Copyright (c) 2013, Christoph Vogel, ETH Zurich

The code may be used free of charge for non-commercial and
educational purposes, the only requirement is that this text is
preserved within the derivative work. For any other purpose you
must contact the authors for permission. This code may not be
redistributed without written permission from the authors.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES 
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF 
MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE 
FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY 
DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, 
WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, 
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

/*
* quickSelect.cpp
*
* from numerical recipies
*
*/

#ifndef __quickSelect__
#define __quickSelect__

typedef double elem_type;

/*
* This Quickselect routine is based on the algorithm described in
* "Numerical recipes in C", Second Edition,
* Cambridge University Press, 1992, Section 8.5, ISBN 0-521-43108-5
* This code by Nicolas Devillard - 1998. Public domain.
*/
#define ELEM_SWAP(a,b) { register elem_type t=(a);(a)=(b);(b)=t; }

//elem_type quick_select(elem_type arr[], int n)
elem_type quick_select(elem_type* arr, int n)
{
  int low, high ;
  int median;
  int middle, ll, hh;
  low = 0 ; high = n-1 ; median = (low + high) / 2;
  for (;;) {
    if (high <= low) /* One element only */
      return arr[median] ;
    if (high == low + 1) { /* Two elements only */
      if (arr[low] > arr[high])
        ELEM_SWAP(arr[low], arr[high]) ;
      return arr[median] ;
    }
    /* Find median of low, middle and high items; swap into position low */
    middle = (low + high) / 2;
    if (arr[middle] > arr[high]) ELEM_SWAP(arr[middle], arr[high]) ;
    if (arr[low] > arr[high]) ELEM_SWAP(arr[low], arr[high]) ;
    if (arr[middle] > arr[low]) ELEM_SWAP(arr[middle], arr[low]) ;
    /* Swap low item (now in position middle) into position (low+1) */
    ELEM_SWAP(arr[middle], arr[low+1]) ;
    /* Nibble from each end towards middle, swapping items when stuck */
    ll = low + 1;
    hh = high;
    for (;;) {
      do ll++; while (arr[low] > arr[ll]) ;
      do hh--; while (arr[hh] > arr[low]) ;
      if (hh < ll)
        break;
      ELEM_SWAP(arr[ll], arr[hh]) ;
    }
    /* Swap middle item (in position low) back into correct position */
    ELEM_SWAP(arr[low], arr[hh]) ;
    /* Re-set active partition */
    if (hh <= median)
      low = ll;
    if (hh >= median)
      high = hh - 1;
  }
}

elem_type quick_select_pick(elem_type* arr, int n, int pick)
{
  int low, high ;
  int median;
  int middle, ll, hh;
  low = 0 ; high = n-1 ; median = pick;//(low + high) / 2;
  for (;;) {
    if (high <= low) /* One element only */
      return arr[median] ;
    if (high == low + 1) { /* Two elements only */
      if (arr[low] > arr[high])
        ELEM_SWAP(arr[low], arr[high]) ;
      return arr[median] ;
    }
    /* Find median of low, middle and high items; swap into position low */
    middle = (low + high) / 2;
    if (arr[middle] > arr[high]) ELEM_SWAP(arr[middle], arr[high]) ;
    if (arr[low] > arr[high]) ELEM_SWAP(arr[low], arr[high]) ;
    if (arr[middle] > arr[low]) ELEM_SWAP(arr[middle], arr[low]) ;
    /* Swap low item (now in position middle) into position (low+1) */
    ELEM_SWAP(arr[middle], arr[low+1]) ;
    /* Nibble from each end towards middle, swapping items when stuck */
    ll = low + 1;
    hh = high;
    for (;;) {
      do ll++; while (arr[low] > arr[ll]) ;
      do hh--; while (arr[hh] > arr[low]) ;
      if (hh < ll)
        break;
      ELEM_SWAP(arr[ll], arr[hh]) ;
    }
    /* Swap middle item (in position low) back into correct position */
    ELEM_SWAP(arr[low], arr[hh]) ;
    /* Re-set active partition */
    if (hh <= median)
      low = ll;
    if (hh >= median)
      high = hh - 1;
  }
}

#undef ELEM_SWAP

#endif