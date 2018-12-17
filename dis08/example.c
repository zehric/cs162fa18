#include <stdio.h>

/* Total physical memory size = 4 pages 
   Total virtual memory size = 100 pages
   Assume we have page 0 at virtual address 10
                  page 1 at virtual address 70
                  page 2 is not mapped
                  page 3 at virtual address 32 */

#define VIRT_MEM_SIZE 100
#define PHYS_MEM_SIZE 4

/* Lookup takes in a virtual address and returns the corresponding
 * physical address */
int page_table_lookup(int *page_table, int virtual_page_num) {
	int physical_page_num = page_table[virtual_page_num];
	if (physical_page_num == -1) {
		printf("PAGE FAULT: no mapping for %d\n", virtual_page_num);
		return -1;
	}
	return physical_page_num;
}

/* Since the physical address in the inverted page table is just the index,
 * we just iterate through the inverted page table and return the index whose
 * value matches the virtual address */
int inv_page_table_lookup(int *inv_page_table, int virtual_page_num) {
	int physical_page_num;
	for (int physical_page_num = 0; physical_page_num < PHYS_MEM_SIZE; physical_page_num++) {
		int page_table_entry = inv_page_table[physical_page_num];
		if (page_table_entry == virtual_page_num) {
			return physical_page_num;
		}
	}
	printf("PAGE FAULT (inverted): no mapping for %d\n",virtual_page_num);
	return -1;
}

int main()
{
	/* Page table */
	int page_table[VIRT_MEM_SIZE];
	for (int i = 0; i < VIRT_MEM_SIZE; i++) // Fill with -1 (empty)
		page_table[i] = -1;
	page_table[10] = 0; // Virtual address 10 -> Physical address 0
	page_table[70] = 1; // Virtual address 70 -> Physical address 1
	page_table[32] = 3; // Virtual address 32 -> Physical address 3


	/* Inverted page table */
	int inv_page_table[PHYS_MEM_SIZE];
	for (int i = 0; i < PHYS_MEM_SIZE; i++) // Fill with -1 (empty)
		page_table[i] = -1;
	inv_page_table[0] = 10;
	inv_page_table[1] = 70;
	inv_page_table[3] = 32;
	/* Notice the inverted page table is literally an inverted version of
	 * the page table */


	printf("Looking up virtual page %d in page table:\n", 32);
        printf("%d\n", page_table_lookup(page_table, 32));
	printf("Looking up virtual page %d in inverted page table:\n", 32);
	printf("%d\n", inv_page_table_lookup(inv_page_table, 32));
	
	printf("\n");

	/* virtual address 50 isn't mapped */
	printf("Looking up virtual page %d in page table:\n", 50);
        printf("%d\n", page_table_lookup(page_table, 50));
	printf("Looking up virtual page %d in inverted page table:\n", 50);
	printf("%d\n", inv_page_table_lookup(inv_page_table, 50));
}
