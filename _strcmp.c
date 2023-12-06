/**
 * _strcmp - compares two strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: -15 if  the first not-matching character in s1
 * has a lesser ASCII value than the corresponding character in s2,
 * 15 if  first not-matching character in s1 has a greater ASCII value
 * than the corresponding character in s2,
 * 0 if all of the characters in both strings are the same
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	int n = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		n = (int)(s1[i] - s2[i]);

		if (n != 0)
		break;
		i++;
	}
	return (n);
}
