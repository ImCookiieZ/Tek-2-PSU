#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main()
{
//    char *test = malloc(10000);
//    char *mal = strdup("<3");
//    char *mal2 = strdup("niceone");
//    char *mal3 = strdup("notfree");
//    printf("mal\t%s\t%p\n", mal, mal);
//    printf("mal2\t%s\t%p\n", mal3, mal3);
//    fflush(stdout);
////    mal = realloc(mal, 7);
////    mal[3] = 'l';
////    mal[4] = 'o';
////    mal[5] = 'l';
////    mal[6] = '\0';
//    printf("mal\t%s\t%p\n", mal, mal);
//    fflush(stdout);
//    free(mal);
//    free(mal2);
//    mal = strdup("lol2");
//    mal2 = strdup("split");
//    char *mal4 = strdup("jo");
//    printf("mal\t%s\t%p\n", mal, mal);
//    printf("mal2\t%s\t%p\n", mal2, mal2);
//    printf("mal4\t%s\t%p\n\n", mal4, mal4);
//    fflush(stdout);
////    write(1, mal, strlen(mal));
////    write(1, mal2, strlen(mal2));
//    mal = realloc(mal2, 13);
//    memset(mal, 'O', 12);
//    mal[12] = 0;
//    printf("mal\t%s\t%p\n", mal, mal);
//    free(mal);
//    free(mal2);
//    free(mal3);
//    free(mal4);
//    free(mal2);
//    mal = malloc(4);
//    write(1, mal, strlen(mal));
    char *mal = strdup("nice");
    char *mal2 = strdup("lol");
    free(mal);
    mal = malloc(3);
    mal[0] = 'n';
    printf("%p", mal);
    free(mal);
    free(mal2);
    printf("%p", mal);
    return 0;
}