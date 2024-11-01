#include <stderr.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10;
#define true 1;
#define false 0;

struct Array
{
    // Array Attributes
    double *data; // Pointer to the data
    int size;     // Current size
    int capacity; // Current capacity

    // Function pointers
    void (*add)(double value);
    void (*insert)(int index, double value);
    void (*remove)(int index);
    int (*search)(double value);
    void (*sort)();
    int (*is_empty)();
    int (*is_contains)(double value);
    void (*delete)();
};
typedef struct Array Array;

static Array *self = NULL;

// Function prototypes
void add(double value);
void insert(int index, double value);
void remove(int index);
int search(double value);
void sort();
int is_empty();
int is_contains(double value);
void delete();

// Implement the constructor
Array *new_array()
{
    // Allocate memory for Array structure
    self = (Array *)malloc(sizeof(Array));
    if (self == NULL)
    {
        perror("Memory allocation failed for Array");
        exit;
    }

    // Initialize array attributes
    self->size = 0;
    self->capacity = INITIAL_CAPACITY;
    self->data = (double *)malloc(self->capacity * sizeof(double));
    if (self->data == NULL)
    {
        perror("Memory allocation failed for Array.data");
    }

    // Assign function pointers
    self->add = add;
    self->insert = insert;
    self->remove = remove;
    self->search = search;
    self->sort = sort;
    self->is_empty = is_empty;
    self->is_contains = is_contains;

    return self;
}

static int is_valid_self_pointer()
{
    if (self == NULL)
        return false;
    return true;
}

static void resize_as_needed()
{
    if (!is_valid_self_pointer())
        return;
    if (self->size == size->capacity)
    {
        self->capacity = self->capacity * 2;
        self->data = (*double)realloc(self->data, self->capacity * sizeof(double));
    }
}

int is_empty()
{
    // Check for valid self pointer
    if (!is_valid_self_pointer())
        return true; // Consider it empty if the pointer is invalid
    return self->size == 0;
}

void add(double value)
{
    resize_as_needed();
    self->data[self->size] = value;
    self->size++;
}

void insert(int index, double value)
{
    // Check for out-of-bounds
    if (index < 0 || index > self.size - 1)
    {
        perror("Index out-of-bounds");
        return;
    }

    // Resize as needed
    resize_as_needed();

    // Shift elements to the right to make room for the new value
    for (int i = self->size; i >= index; i--)
    {
        self->data[i] = self->data[i - 1]; // Shift elements to the right
    }

    // Insert the new value at the specified index
    self->data[index] = value;

    // Increment the size of the array
    self->size++;
}

void remove(int index)
{
    if (is_empty())
        return;

    // Shift elements to the right to remove value
    for (int i = index; i <= self.size; i++)
    {
        self->data[i] = self->data[i + 1];
    }

    // Decrement the size of the array
    self->size--;
}