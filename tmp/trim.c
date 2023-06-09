#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

//123 abc 123[]
char	*ft_strtrim(const char *str, const char *set)
{
	const char *head;
	const char *tail;
	char		*dest;

	if (str == NULL || set == NULL)
		return NULL;
	head = str;
	while (*head && strchr(set, *head))
		head++;
	tail = head + strlen(head);
	while (head < tail && strchr(set, *(tail - 1)))
		tail--;
	dest = calloc(tail - head + 1, sizeof(char));
	if (dest == NULL)
		return NULL;
	memcpy(dest, head, tail - head);
	return dest;
}

void	test(const char *str, const char *set)
{
	printf("\nstr[%s] set[%s]\n", str, set);
	printf("[%s]\n", ft_strtrim(str, set));
}

int		main()
{
	test("123abc123", "0123456789");
	test("abcab", "0123456789");
	test("", "0123456789");
	test("abcab", "");
	test("", "");
	test("123abc123abc123", "0123456789");
	test("1234567", "0123456789");
	test("1234567", NULL);
	test(NULL, "0123456789");
	test(NULL, NULL);
}


