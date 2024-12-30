#include <stdio.h>
#include <time.h>
#include <string.h>

struct User {
    char *name;
    char *email;
    int age;
};

clock_t getTime(void);  // function prototype
void createArrayAndLoop(int8_t); // function prototype
void times2(int*, int); // function prototype
void times3(int*, int); // function prototype
void times4(int*, int); // function prototype
void double_array(int*, int); // function prototype
size_t get_string_length(char*); // function prototype
void set_name(struct User*, char*); // function prototype
void read_file_by_char(char*); //function prototype
void read_file_by_chunks(char*, int); // function prototype

// Get size of an int (4-bytes)
void sizeOfInt(void) {
    printf("Size of int: %zu bytes\n", sizeof(int));
}

// Get size fo a float (4-bytes)
void sizeOfFloat(void) {
    printf("Size of float: %zu bytes\n", sizeof(float));
}

// Get size of a char (1-byte)
void sizeOfChar(void) {
    printf("Size of char: %zu bytes\n", sizeof(char));
}
 
// Get size of string (8-bytes)
void sizeOfString(char *string) {
    printf("Size of String: %zu bytes\n", sizeof(&string));
}

void addressInMemory(void) {
    int i = 10;
    printf("The value of i is %d\n", i);
    printf("The address of i is %p\n", (void *)&i);
}

void increment(int *p) { // accepts a pointer to an int
    *p = *p + 1; // note the address-of; turns in into a pointer to i
}

void setupIncrement(void) {
    int i = 10;
    int *j = &i;

    printf("i is %d\n", i); // prints "10"
    printf("i is also %d\n", *j); // prints "10"
    increment(j); // j is an int*-- to i
    printf("i is %d\n", i); // prints "11"
}

// You can define this as print_2D_array(int a[][3])
// becuase the compiler only needs the second dimension
// so it can figure out how far in memory to skip
// for each increment of the first dimension
void print_2D_array(int a[2][3]) {
    printf("Print 2D-Array:\n");
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%d ", a[row][col]);
        }
        printf("\n");
    }
}

void display_array(int *arr, int len) {
    printf("Display array:\n");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    clock_t start, end;
    double cpu_time_used;

    start = getTime();

    sizeOfInt();
    sizeOfFloat();
    sizeOfChar();
    sizeOfString("H");
    addressInMemory();
    setupIncrement();
    createArrayAndLoop(10);
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    int arr2d[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    times2(arr, 10);
    times3(arr, 10);
    times4(arr, 10);
    double_array(arr, 10);
    print_2D_array(arr2d);
    // Mutable string array -- stores memory near program memory
    char str[13] = "Hello, World!";
    // Immutable string
    // char *str = "Hello, World!"; -- stores memory far away from program memory (faster and safer)
    printf("This string, %s, is %zu bytes long.\n", str, get_string_length(str));
    // Create copy of string
    char str_copy[strlen(str)];
    strcpy(str_copy, str);
    str_copy[0] = 'J';
    printf("This string, %s, has been copied and is %zu bytes long.\n", str_copy, get_string_length(str_copy));
    // New 'User' type object
    struct User user = {.name="Robert Burns", .email="r.burns@email.com", .age=28};
    set_name(&user, "Rob Burns");
    printf("User's name: %s\n", user.name);
    read_file_by_char("text.txt");
    read_file_by_chunks("multiline_text.txt", 1024);

    end = getTime();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTime took to execute: %f seconds\n", cpu_time_used);
    return 0;
}

clock_t getTime(void) {
    return clock();
}

void createArrayAndLoop(int8_t arraySize) {
    int8_t arr[arraySize];
    for (int i = 0; i < arraySize; i++) {
        arr[i] = i;
        printf("Element: %d\n", arr[i]);
    }
    /**
     * To get the size of an array you must take the sizeof the array, 
     * and then divide that by the size of each element to get the length. 
     * For example, if an int is 4 bytes, and the array is 32 bytes long, 
     * there must be room for 32/4 or 8 int's
     * 
     * Since char's are 1 byte, the length of the array is the number
     * of elements in the array; array[5] = size of 5
     * 
     * This does not work if you pass the array as a function parameter
     */
    printf("Final array size: %lu\n", sizeof arr / sizeof(int8_t));
    printf("Final array size (alternative): %lu\n", sizeof(int8_t [arraySize]));
}

// Passing as a pointer to the first element
void times2(int *a, int len) {
    for (int i = 0; i < len; i++) {
        printf("x2 - %d\n", a[i] * 2);
    }
}

// Same as times2, but using array notation
void times3(int *a, int len) {
    for (int i = 0; i < len; i++) {
        printf("x3 - %d\n", a[i] * 3);
    }
}

// Same as times2, but using array notation with size
void times4(int a[5], int len) {
    for (int i = 0; i < len; i++) {
        printf("x4 - %d\n", a[i] * 4);
    }
}

void double_array(int *a, int len) {
    // Multiply each element by 2
    // This doubles the values in x in main() since x and a point
    // the the same array in memory
    for (int i = 0; i < len; i++) {
        a[i] *= 2;
    }
    // Notice: We don't need to return a new array
    // The values are updated in place and visible
    // to the caller
    display_array(a, len);
}

size_t get_string_length(char *str) {
    size_t count = 0;
    while (str[count] != '\0') { // Single quotes for single char
        count++;
    }
    return count;
}

/**
 * variable c to de-pointer it to get to the struct itself.
 * Dereferencing a struct car* results in the struct car that
 * the pointer points to, which we should be able to use the
 * dot operator on
 */
void set_name(struct User *user, char *name) {
    user->name = name;
}

void read_file_by_char(char *filename) {
    FILE *fp;
    int c;

    fp = fopen(filename, "r");
    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }
    fclose(fp);
}

void read_file_by_chunks(char *filename, int chunk) {
    FILE *fp;
    char output[chunk];
    int lineCount = 0;

    // Create a file pointer to READ file contents
    fp = fopen(filename, "r");

    while (fgets(output, sizeof output, fp) != NULL) {
        printf("%d: %s", ++lineCount, output);
    }
    fclose(fp);
}
