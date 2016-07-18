#include "dynamic_array.h"

void daInit(DynamicArray *array) {
    array->values = (Object **) malloc(sizeof(Object *) * DYNAMIC_ARRAY_CHUNK_SIZE);
    if (!array->values) {
        natrix_error = ALLOC_ERR;
    } else {
        array->size = DYNAMIC_ARRAY_CHUNK_SIZE;
        array->len = 0;
    }
}

void daCheckExtend(DynamicArray *array) {
    if (array->size == array->len) {
        void *res = realloc(
                array->values,
                sizeof(Object *) * (
                        array->size + DYNAMIC_ARRAY_CHUNK_SIZE
                )
        );
        if (!res) {
            natrix_error = ALLOC_ERR;
        } else {
            array->values = (Object **) res;
        }
    }
}

void daPush(DynamicArray *array, Object *obj) {
    daCheckExtend(array);
    if (!check_err) {
        array->values[array->len++] = obj;
    }
}

Object *daPop(DynamicArray *array) {
    Object *object = NULL;
    if (0 == array->len) {
        natrix_error = NO_VALUE_ERR;
    } else {
        object = array->values[--array->len];
    }
    return object;
}

void clear(DynamicArray *array) {
    array->len = 0;
}

Object *daGet(DynamicArray *array, int32_t n) {
    Object *object = NULL;
    if (n < 0) n += array->len;
    if ((n < 0) || (n > array->len)) {
        natrix_error = INDEX_ERR;
    } else {
        object = array->values[n];
    }
    return object;
}