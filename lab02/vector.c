/* Include the system headers we need */
#include <stdlib.h>
#include <stdio.h>

/* Include our header */
#include "vector.h"

/* Define what our struct is */
struct vector_t {
    size_t size;
    int *data;
};

/* Utility function to handle allocation failures. In this
   case we print a message and exit. */
static void allocation_failed() {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
}

/* Create a new vector with a size (length) of 1 and set its single component to zero... the
   right way */
vector_t *vector_new() {
    /* Declare what this function will return */
    vector_t *retval;

    /* First, we need to allocate memory on the heap for the struct */
    retval = malloc(sizeof(vector_t));

    /* Check our return value to make sure we got memory */
    if (retval == NULL) {
        allocation_failed();
    }

    /* Now we need to initialize our data.
       Since retval->data should be able to dynamically grow,
       what do you need to do? */
    retval->size = 1;
    retval->data = malloc(sizeof(int));

    /* Check the data attribute of our vector to make sure we got memory */
    if (retval->data == NULL) {
        free(retval);
        allocation_failed();
    }

    /* Complete the initialization by setting the single component to zero */
    retval->data[0] = 0;

    /* and return... */
    return retval;
}

/* Return the value at the specified location/component "loc" of the vector */
int vector_get(vector_t *v, size_t loc) {
    /* If we are passed a NULL pointer for our vector, complain about it and exit. */
    if (v == NULL) {
        fprintf(stderr, "vector_get: passed a NULL vector.\n");
        abort();
    }

    /* If the requested location is higher than we have allocated, return 0.
     * Otherwise, return what is in the passed location.
     */
    if (loc >= v->size) {
        return 0;
    }

    return v->data[loc];
}

/* Free up the memory allocated for the passed vector.
   Remember, you need to free up ALL the memory that was allocated. */
void vector_delete(vector_t *v) {
    if (v != NULL) {
        free(v->data);
        free(v);
    }
}

/* Set a value in the vector. If the extra memory allocation fails, call
   allocation_failed(). */
void vector_set(vector_t *v, size_t loc, int value) {
    /* What do you need to do if the location is greater than the size we have
     * allocated?  Remember that unset locations should contain a value of 0.
     */

    /* If we are passed a NULL pointer for our vector, complain about it and exit. */
    if (v == NULL) {
        fprintf(stderr, "vector_set: passed a NULL vector.\n");
        abort();
    }

    /* If the requested location is higher than we have allocated, we need to resize our data array */
    if (loc >= v->size) {
        size_t new_size = loc + 1;
        int *new_data = realloc(v->data, new_size * sizeof(int));

        if (new_data == NULL) {
            allocation_failed();
        }

        /* Set the new elements to 0 */
        for (size_t i = v->size; i < new_size; i++) {
            new_data[i] = 0;
        }

        v->data = new_data;
        v->size = new_size;
    }

    v->data[loc] = value;
}
