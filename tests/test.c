#include <assert.h>
#include <libpds.h>

void test();

// TODO: Look into the testing framework Unity
int main(void)
{
    test();
    return 0;
}

void test()
{
    assert(tree_create_node(5)->id == 5);
    printf("All tests have passed!\n");
}