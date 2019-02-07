#include<stdio.h>
void rev(int val) {
	int k = val;
	int l = val;
	int res = k & 0x00FF;
	res = res << 8;
	int res1 = l & 0xFF00;
	res1 = res1 >> 8;
	printf("\nrev val : %x", res1 | res);
	getchar();
}
void rotate(int val) {
	int k = val;
	int l = k & 0x000F;
	l = l << 12;
	//printf("\n%x l val", l);
	int h = val;
	h = h >> 4;
	int j = h & 0x0FFF;
	int res = l | j;
	printf("\nrotate val: %x", res);
	getchar();
}
int main() {
	int val = 0xCAFE;
	int c = 0;
	if (val & 1) {
		c++;
	}
	for (int i = 0; i < 4; i++) {
		if ((val >> 1) & 1) {
			c++;
		}
	}
	if (c >= 3) {
		printf("case1: yes\n");
		getchar();
	}
	rev(val);
	rotate(val);
	return 0;
}
