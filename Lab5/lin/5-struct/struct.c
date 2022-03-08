/**
  * SO, 2016
  * Lab #5
  *
  * Task #5, lin
  *
  * Use of malloc, realloc on structures
  */
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

#define NO_FLOWERS 5
#define NAME_LEN 16

struct flower_info {
	char *name;
	int price;
	int class;
};

/*
 * allocate_flowers - allocates space for all the flowers
 * init every flower with random values
 */
static struct flower_info *allocate_flowers(int no)
{
	int i;
	int ret;
	struct flower_info *f_info;

	f_info = malloc(no * sizeof(*f_info));
	DIE(f_info == NULL, "malloc");

	/* initialization */
	for (i = 0; i < no; i++) {
		/*
		 * ne-ai zis si la lab: asprint face malloc + printf si parea
		 * ce trebuie
		 */
		ret = asprintf(&f_info[i].name, "flower__%d__", i);
		DIE(ret < 0, "asprintf");

		f_info[i].price = 1 + i * 2;
		f_info[i].class = 2 + i * 3;
	}

	return f_info;
}

/**
 * TODO: implement free_flowers to deallocate
 * an array of no flower
 */
static void free_flowers(struct flower_info *f_info, int no)
{
	int i;

	/* PC anul 1, nu e prea mult de zis */
	for (i = 0; i != no; ++i)
		free(f_info[i].name);

	free(f_info);
}

static void print_flowers(struct flower_info *f_info, int no)
{
	int i;

	for (i = 0; i < no; i++)
		printf("=%d=:Name: %s, price: %d, class: %d\n",
			i, f_info[i].name, f_info[i].price, f_info[i].class);
}

int main(void)
{
	struct flower_info *flowers;

	flowers  = allocate_flowers(NO_FLOWERS);

	print_flowers(flowers, NO_FLOWERS);

	free_flowers(flowers, NO_FLOWERS);

	return 0;
}
